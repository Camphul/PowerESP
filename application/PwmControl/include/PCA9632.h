//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_PCA9632_H
#define POWERESP_PCA9632_H
#include "I2Cbus.hpp"
#define PCA9632_MODE1 0x00
#define PCA9632_MODE2 0x01
#define PCA9632_PWM0 0x02
#define PCA9632_PWM1 0x03
#define PCA9632_PWM2 0x04
#define PCA9632_PWM3 0x05
#define PCA9632_GRPPWM 0x06
#define PCA9632_GRPFREQ 0x07
#define PCA9632_LEDOUT 0x08
#define PCA9632_SUBADR1 0x09
#define PCA9632_SUBADR2 0x0A
#define PCA9632_SUBADR3 0x0B
#define PCA9632_ALLCALLADR 0x0C
#define PCA9632_NO_AUTOINC  0x00
#define PCA9632_AUTO_ALL    0x80
#define PCA9632_AUTO_IND    0xA0
#define PCA9632_AUTOGLO     0xC0
#define PCA9632_AUTOGI      0xE0

#define PCA9632_ALL_CALL_I2C_SLAVE_ADDRESS 0x70
#define PCA9632_SWRST_I2C_SLAVE_ADDRESS 0x03
#define PCA9632_MODE1_MASK_SLEEP 0x10
#define PCA9632_MODE2_MASK_DMBLNK 0x20
#define ESP_ERR_CHANNEL_OUT_OF_BOUNDS 1337
namespace PwmControl {
    typedef enum {
        STOP_COMMAND,
        ACK
    } OutputChangeTrigger;
    typedef enum {
        OFF,
        FULLY_ON,
        BRIGHTNESS_CONTROL,
        BRIGHTNESS_DIMMING_BLINKING_CONTROL
    } OutputDriverEffect;
    typedef enum {
        OPEN_DRAIN,
        TOTEM_POLE
    } OutputDriverStructure;

    typedef enum {
        ZERO,
        ONE_OR_WEAK_HIGH,
        HIGH_Z
    } OutputWhenNotEnabled;
    class PCA9632 {
    public:
        constexpr PCA9632(I2C_t& i2c_master = i2c0) : _master{i2c_master} {
        }
        [[nodiscard]] esp_err_t init_device(void);
        [[nodiscard]] esp_err_t reset(void);
        [[nodiscard]] esp_err_t sleep(void);
        [[nodiscard]] esp_err_t wakeup(void);
        [[nodiscard]] esp_err_t setSubaddress1Active(uint8_t addr);
        [[nodiscard]] esp_err_t setSubaddress2Active(uint8_t addr);
        [[nodiscard]] esp_err_t setSubaddress3Active(uint8_t addr);
        [[nodiscard]] esp_err_t setAllCallAddressActive(uint8_t addr);
        [[nodiscard]] esp_err_t setAllCallAddressInactive(void);
        [[nodiscard]] esp_err_t configureOutputs(bool inverted, OutputChangeTrigger trigger, OutputDriverStructure structure, OutputWhenNotEnabled output);
        [[nodiscard]] esp_err_t configureDimmingEffect(float ratio);
        [[nodiscard]] esp_err_t configureBlinkingEffect(float period, float dutyCycle);
        [[nodiscard]] esp_err_t setEffectEnabled(uint8_t channel, bool enabled);

        [[nodiscard]] esp_err_t setBrightness(uint8_t channel, uint16_t value);
    protected:
        I2C_t& _master;
        const uint8_t channels = 4;
        [[nodiscard]] esp_err_t setAddressActive(uint8_t index, uint8_t addr, bool enabled);
        [[nodiscard]] esp_err_t setGroupPwm(float ratio);
        float clamp(float value, float min, float max);
        esp_err_t writeRegister(uint8_t regAddr, uint8_t value);
        esp_err_t readRegister(uint8_t regAddr, uint8_t* value);
    };
}
using PwmController_t = PwmControl::PCA9632;
extern PwmController_t ledRing;

#endif //POWERESP_PCA9632_H
