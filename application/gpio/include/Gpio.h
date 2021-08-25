//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_GPIO_H
#define POWERESP_GPIO_H

#include "driver/gpio.h"
namespace Gpio {
    class GpioBase;
    class GpioOutput;
    class GpioInput;
}

using GpioInput_t = Gpio::GpioInput;
using GpioOutput_t = Gpio::GpioOutput;
using PushButton_t = GpioInput_t;
/**
 * Physical button on the hardware used to power the device on/off/do other programmed actions
 */
extern PushButton_t powerButton;
/**
 * powerBootstrap is meant to be an output which can only be set inverse once since
 * it will power off the device.
 */
extern GpioOutput_t powerBootstrap;
namespace Gpio{
        class GpioBase {
            protected:
                const gpio_num_t _pin;
                const gpio_config_t _cfg;
                const bool _inverted_logic = false;
            public:
            constexpr GpioBase(const gpio_num_t pin, const gpio_config_t& config, const bool invert = false) :
            _pin{pin},
            _cfg{config},
            _inverted_logic{invert}
            {
            }
            virtual bool state(void) =0;

            // virtual esp_err_t set(const bool state) =0;
            virtual esp_err_t init(void);
        }; // class GpioBase

        class GpioOutput : public GpioBase{
            bool _state = false;
            public:
            constexpr GpioOutput(const gpio_num_t pin, const bool invert = false) : GpioBase{
                pin,
                        gpio_config_t{
                    .pin_bit_mask = static_cast<uint64_t>(1) << pin,
                    .mode = GPIO_MODE_OUTPUT,
                    .pull_up_en = GPIO_PULLUP_DISABLE,
                    .pull_down_en = GPIO_PULLDOWN_DISABLE,
                    .intr_type = GPIO_INTR_DISABLE,
                },
                invert
            }
            {
                gpio_config(&_cfg);
            }
            [[nodiscard]]esp_err_t init(void);
            [[nodiscard]]esp_err_t set(const bool state);
            [[nodiscard]]esp_err_t toggle(void);
            bool state(void) override { return _state; }
            [[nodiscard]]esp_err_t holdPin(bool hold);
        }; // class GpioOutput

        class GpioInput : public GpioBase {
            bool _state = false;
            public:
            constexpr GpioInput(const gpio_num_t pin, const bool invert = false) : GpioBase{
                pin,
                gpio_config_t{
                    .pin_bit_mask = static_cast<uint64_t>(1) << pin,
                    .mode = GPIO_MODE_INPUT,
                    .pull_up_en = GPIO_PULLUP_DISABLE,
                    .pull_down_en = GPIO_PULLDOWN_ENABLE,
                    .intr_type = GPIO_INTR_DISABLE,
                    },
                    invert
            }
            {
                gpio_config(&_cfg);
            }
            esp_err_t init(void) override;
            bool state(void);
        }; //class GpioInput
} // namespace Gpio


#endif //POWERESP_GPIO_H
