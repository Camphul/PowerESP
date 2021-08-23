//
// Created by luca on 8/20/21.
//

#include "PCA9632.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "PCA9632"
#include "freertos/task.h"
#define DEFAULT_I2C_TIMEOUT 10
namespace PwmControl {
    [[nodiscard]] esp_err_t PCA9632::init_device(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGI(LOG_TAG, "Initializing device");
        ESP_ERROR_CHECK(this->reset());
        ESP_ERROR_CHECK(this->wakeup());
        ESP_ERROR_CHECK(this->configureOutputs(false, STOP_COMMAND, OPEN_DRAIN, ZERO));
        ESP_LOGI(LOG_TAG, "Initialized device");
        return status;
    }
    /*!
     * @brief Triggers a software reset of the chip.
     * All the registers will be set to their power-up default value
     * @return True if there is an error, false otherwise
     */
    [[nodiscard]] esp_err_t PCA9632::reset(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGD(LOG_TAG, "Resetting device");
        ESP_ERROR_CHECK(_master.writeByte(PCA9632_SWRST_I2C_SLAVE_ADDRESS,0xA5, 0x5A));
        return status;
    }
    /*!
     * @brief Puts the chip in sleep mode.
     * Don't call any other method while sleeping.
     */
    [[nodiscard]] esp_err_t PCA9632::sleep(void) {
        esp_err_t status{ESP_OK};
        uint8_t oldMode1;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE1, &oldMode1));
        uint8_t newMode1 = oldMode1 | PCA9632_MODE1_MASK_SLEEP;
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE1, newMode1));
        ESP_LOGD(LOG_TAG, "Putting device to sleep");
        return status;
    }
    /*!
     * @brief Wakes up the chip.
     * There is a 500us delay that guarantees that all the functions and registers are available before the method returns.
     */
    [[nodiscard]] esp_err_t PCA9632::wakeup(void) {
        esp_err_t status{ESP_OK};
        uint8_t oldMode1;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE1, &oldMode1));
        uint8_t newMode1 = oldMode1 & ~PCA9632_MODE1_MASK_SLEEP;
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE1, newMode1));
        //Required to sleep according to datasheet.
        vTaskDelay(pdMS_TO_TICKS(500));
        ESP_LOGD(LOG_TAG, "Waking up device");
        return status;
    }

    /*!
     * @brief Sets the first I2C subaddress and activates it.
     * @param addr The address
     */
    [[nodiscard]] esp_err_t PCA9632::setSubaddress1Active(const uint8_t addr) {
        return this->setAddressActive(0, addr, true);
    }

    /*!
     * @brief Sets the second I2C subaddress and activates it.
     * @param addr The address
     */
    [[nodiscard]] esp_err_t PCA9632::setSubaddress2Active(const uint8_t addr) {
        return this->setAddressActive(1, addr, true);
    }

    /*!
     * @brief Sets the third I2C subaddress and activates it.
     * @param addr The address
     */
    [[nodiscard]] esp_err_t PCA9632::setSubaddress3Active(const uint8_t addr) {
        return this->setAddressActive(2, addr, true);
    }

    /*!
     * @brief Sets the "all call" I2C subaddress (active by default)
     * @param addr The address
     */
    [[nodiscard]] esp_err_t PCA9632::setAllCallAddressActive(const uint8_t addr) {
        return this->setAddressActive(3, addr, true);
    }

    /*!
     * @brief Disables the "all call" I2C address (active by default)
     */
    [[nodiscard]] esp_err_t PCA9632::setAllCallAddressInactive(void) {
        return this->setAddressActive(3, 0, false);
    }

    /*!
     * @brief Configures the behavior of the output drivers
     * @param inverted Iif true, the outputs will be inverted (w.r.t the common anode config)
     * @param trigger When the outputs must change.  Change of the outputs at the STOP command allows synchronizing outputs of more than one PCA9634.
     * @param structure The output driver final transistors configuration. Some newer LEDs include integrated Zener diodes to limit voltage transients, reduce EMI and protect the LEDs, and these must be driven only in the open-drain mode to prevent overheating the IC.
     * @param output The desired output when ~OE=1
     */
    [[nodiscard]] esp_err_t PCA9632::configureOutputs(const bool inverted, const OutputChangeTrigger trigger, const OutputDriverStructure structure, const OutputWhenNotEnabled output) {
        esp_err_t status{ESP_OK};
        uint8_t oldMode2;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE2, &oldMode2));
        uint8_t newMode2 = (oldMode2 & PCA9632_MODE2_MASK_DMBLNK) | (inverted << 4) | (trigger << 3) | (structure << 2) | output;
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE2, newMode2));
        return status;
    }

    /*!
     * @brief Sets the parameters for the global dimming effect.
     * This will disable the global blinking.
     * The effect must be applied to the single outputs with setEffectEnabled().
     * A 190 Hz fixed frequency signal is superimposed with the 97 kHz individual brightness control signal.
     * @param ratio The dimming ratio. A value of 0.5 will half the output Vrms.
     */
    [[nodiscard]] esp_err_t PCA9632::configureDimmingEffect(const float ratio) {
        esp_err_t status{ESP_OK};
        uint8_t oldMode2;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE2, &oldMode2));
        uint8_t newMode2 = oldMode2 & ~PCA9632_MODE2_MASK_DMBLNK;
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE2, newMode2));
        ESP_ERROR_CHECK(setGroupPwm(ratio));
        return status;
    }

    /*!
     * @brief Sets the parameters for the global blinking effect.
     * This will disable the global dimming
     * The effect must be applied to the single outputs with setEffectEnabled().
     * @param period The period, in seconds of the blinking effect. The value is clamped between 0.041 and 10.73.
     * @param dutyCycle The blinking duty cycle. A value of 0.1 will keep the output on for 10% of the time.
     *
     */
    [[nodiscard]] esp_err_t PCA9632::configureBlinkingEffect(const float period, const float dutyCycle) {
        esp_err_t status{ESP_OK};
        uint8_t oldMode2;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE2, &oldMode2));
        uint8_t newMode2 = oldMode2 | PCA9632_MODE2_MASK_DMBLNK;
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE2, newMode2));
        ESP_ERROR_CHECK(setGroupPwm(dutyCycle));
        ESP_ERROR_CHECK(writeRegister(  PCA9632_GRPFREQ, (int)clamp(24.0 * period - 1.0, 0.0, 255.0)));
        return status;
    }

    /*!
     * @brief Enables or disables the dimming/blinking effects for a channel.
     * @param channel The channel (0 - 3) whose flag must be set.
     * @param enabled Whether or not the effects must be enabled.
     */
    [[nodiscard]] esp_err_t PCA9632::setEffectEnabled(const uint8_t channel, const bool enabled) {
        esp_err_t status{ESP_OK};
        if(channel >= channels) {
            return ESP_ERR_CHANNEL_OUT_OF_BOUNDS;
        }
        uint8_t ledoutRegisterAddress = PCA9632_LEDOUT + channel / 4;
        uint8_t ledoutBitShift = (channel & 0x03) << 1;
        uint8_t ledoutRegisterValue;
        ESP_ERROR_CHECK(readRegister(ledoutRegisterAddress, &ledoutRegisterValue));
        OutputDriverEffect oldLedoutValue = static_cast<OutputDriverEffect>((ledoutRegisterValue >> ledoutBitShift) & 0x03);
        if(enabled) {
            if(oldLedoutValue == FULLY_ON) {
                writeRegister(PCA9632_PWM0 + channel, 0xFF);
            }
            if(oldLedoutValue != BRIGHTNESS_DIMMING_BLINKING_CONTROL) {
                writeRegister(ledoutRegisterAddress, ((ledoutRegisterValue & ~(0x03 << ledoutBitShift)) | (BRIGHTNESS_DIMMING_BLINKING_CONTROL << ledoutBitShift)));
            }
        } else if(oldLedoutValue == BRIGHTNESS_DIMMING_BLINKING_CONTROL) {
            writeRegister(ledoutRegisterAddress, ((ledoutRegisterValue & ~(0x03 << ledoutBitShift)) | (BRIGHTNESS_CONTROL << ledoutBitShift)));
        }
        return status;
    }

    /*!
     * @brief Sets the brightness of a channel.
     * @param channel The channel (0 - 3) whose brighness must be set.
     * @param value The brightness intensity. The PWM duty cycle will be set to value / 256. If the effects are disabled for this channel, the maximum value is 256, 255 otherwise. The minimum value is 0.
     */
    [[nodiscard]] esp_err_t PCA9632::setBrightness(const uint8_t channel, const uint16_t value) {
        esp_err_t status{ESP_OK};
        if(channel > channels) {
            return ESP_ERR_CHANNEL_OUT_OF_BOUNDS;
        }
        uint8_t ledoutRegisterAddress = PCA9632_LEDOUT + channel / 4;
        uint8_t ledoutBitShift = (channel & 0x03) << 1;
        uint8_t ledoutRegisterValue;
        ESP_ERROR_CHECK(readRegister(ledoutRegisterAddress, &ledoutRegisterValue));
        OutputDriverEffect oldLedoutValue = static_cast<OutputDriverEffect>((ledoutRegisterValue >> ledoutBitShift) & 0x03);
        uint16_t maxValue = oldLedoutValue == BRIGHTNESS_DIMMING_BLINKING_CONTROL ? 0XFF : 0X100;
        uint16_t clampedValue = value > maxValue ? maxValue : value;
        OutputDriverEffect newLedoutValue;
        if(clampedValue == 0x100) {
            newLedoutValue = FULLY_ON;
        } else if(oldLedoutValue == BRIGHTNESS_DIMMING_BLINKING_CONTROL) {
            newLedoutValue = BRIGHTNESS_DIMMING_BLINKING_CONTROL;
        } else {
            newLedoutValue = BRIGHTNESS_CONTROL;
        }
        if(newLedoutValue != oldLedoutValue) {
            ESP_ERROR_CHECK(writeRegister(ledoutRegisterAddress, ((ledoutRegisterValue & ~(0x03 << ledoutBitShift)) | (newLedoutValue << ledoutBitShift))));
        }
        if(newLedoutValue != FULLY_ON) {
            ESP_ERROR_CHECK(writeRegister(PCA9632_PWM0 + channel, clampedValue));
        }
        return status;
    }

    [[nodiscard]] esp_err_t PCA9632::setAddressActive(const uint8_t index, const uint8_t addr, bool enabled) {
        esp_err_t status{ESP_OK};
        if(enabled) {
            ESP_ERROR_CHECK(writeRegister(PCA9632_SUBADR1 + index, (addr << 1) & 0xFF));
        }
        uint8_t oldMode1;
        ESP_ERROR_CHECK(readRegister(PCA9632_MODE1, &oldMode1));
        uint8_t enableBit = 0x08 >> index;
        uint8_t newMode1;
        if(enabled) {
            newMode1 = oldMode1 | enableBit;
        } else {
            newMode1 = oldMode1 & ~enableBit;
        }
        ESP_ERROR_CHECK(writeRegister(PCA9632_MODE1, newMode1));
        return status;
    }

    [[nodiscard]] esp_err_t PCA9632::setGroupPwm(const float ratio) {
        esp_err_t status{ESP_OK};
        ESP_ERROR_CHECK(writeRegister(PCA9632_GRPPWM, (int)clamp(ratio * 256.0, 0.0, 255.0)));
        return status;
    }

    float PCA9632::clamp(float value, float min, float max) {
        if(value > max) {
            return max;
        } else if(value < min) {
            return min;
        } else {
            return value;
        }
    }
    esp_err_t PCA9632::writeRegister(const uint8_t regAddr, const uint8_t value) {
        esp_err_t status{ESP_OK};
        status |= _master.writeByte(PCA9632_ALL_CALL_I2C_SLAVE_ADDRESS, regAddr & 0x1F, value, DEFAULT_I2C_TIMEOUT);
        return status;
    }

    esp_err_t PCA9632::readRegister(const uint8_t regAddr, uint8_t* value) {
        esp_err_t status{ESP_OK};
        status |= _master.readByte(PCA9632_ALL_CALL_I2C_SLAVE_ADDRESS, regAddr & 0x1F, value, DEFAULT_I2C_TIMEOUT);
        return status;
    }

}
