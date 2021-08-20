//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_GPIO_H
#define POWERESP_GPIO_H

#include "driver/gpio.h"

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
            virtual esp_err_t set(const bool state) =0;
            [[nodiscard]] esp_err_t init(void);
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
                    .pull_down_en = GPIO_PULLDOWN_ENABLE,
                    .intr_type = GPIO_INTR_DISABLE,
                },
                invert
            }
            {
            }
            esp_err_t init(void);
            esp_err_t set(const bool state);
            esp_err_t toggle(void);
            bool state(void) { return _state; }
        }; // class GpioOutput

        class GpioInput {
            const gpio_num_t _pin;
            const bool _inverted_logic;
            public:
            constexpr GpioInput(const gpio_num_t pin,const bool invert = false) : _pin{pin}, _inverted_logic{invert} {

            }
            bool state(void);
        }; //class GpioInput
} // namespace Gpio


#endif //POWERESP_GPIO_H
