//
// Created by luca on 8/20/21.
//

#include "Gpio.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "GPIO"
const gpio_num_t pin_power_button = (gpio_num_t)CONFIG_GPIO_PIN_SOFTLATCH_BUTTON;
const gpio_num_t pin_power_bootstrap = (gpio_num_t)CONFIG_GPIO_PIN_SOFTLATCH_POWER;
PushButton_t powerButton = Gpio::GpioInput(pin_power_button, true);
GpioOutput_t powerBootstrap = Gpio::GpioOutput(pin_power_bootstrap);
namespace Gpio {
    [[nodiscard]] esp_err_t GpioBase::init(void) {
        esp_err_t status{ESP_OK};
        status |= gpio_config(&_cfg);
        return status;
    } // GpioBase::init

    [[nodiscard]] esp_err_t GpioInput::init(void) {
        esp_err_t status{GpioBase::init()};
        return status;
    } // GpioInput::init

    bool GpioInput::state(void) {
        int level = gpio_get_level(_pin);
        ESP_LOGI(LOG_TAG, "Reading GPIO Input at level: %d", level);
        bool readState = static_cast<bool>(level);
        return _inverted_logic == !readState;
    }//GpioInput::State

    [[nodiscard]] esp_err_t GpioOutput::init(void) {
        esp_err_t status{GpioBase::init()};
        if (ESP_OK == status) {
            status |= set(_inverted_logic);
        }
        return status;
    }// GpioOutput::init

    esp_err_t GpioOutput::set(const bool state) {
        _state = state;
        return gpio_set_level(_pin, _inverted_logic ? !_state : _state);
    } // GpioOutput::Set

    esp_err_t GpioOutput::toggle(void) {
        return this->set(!_state);
    }// GpioOutput::toggle

    /**
     * @brief uses either gpio_pad_hold or gpio_pad_unhold to maintain the pad's value.
     * @param hold if the pad should hold or unhold it's state.
     * @return if held/unhold with success.
     */
    esp_err_t GpioOutput::holdPin(bool hold) {
        esp_err_t status{ESP_OK};
        if(hold) {
            gpio_pad_hold(_pin);
            ESP_LOGD(LOG_TAG, "Holding GPIO pad %d", _pin);
        } else {
            ESP_LOGD(LOG_TAG, "Unholding GPIO pad %d", _pin);
            gpio_pad_unhold(_pin);
        }
        return status;
    } // GpioOutput::holdPin
} //namespace Gpio