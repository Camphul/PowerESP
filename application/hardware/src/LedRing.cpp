//
// Created by luca on 8/25/21.
//
#include "LedRing.hpp"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "LedRing"
#include "I2Cbus.hpp"
#include "freertos/FreeRTOS.h"
namespace Hardware {
    uint8_t LedRing::resolveColorChannel(LedColor_t color) {
        switch (color) {
            case RED:
                return CONFIG_LEDRING_R;
            case GREEN:
                return CONFIG_LEDRING_G;
            case BLUE:
                return CONFIG_LEDRING_B;
        }
        return 0;//default
    }
    esp_err_t LedRing::init() {
        esp_err_t status{ESP_OK};
        status |= _controller.init_device();
        if(ESP_OK != status) {
            ESP_LOGE(LOG_TAG, "Something went wrong setting up the LedRing device.");
        } else {
            ESP_LOGI(LOG_TAG, "Initialized LedRing hardware device with success.");
        }
        return status;
    }
    esp_err_t LedRing::allOff() {
        esp_err_t status{ESP_OK};
        status |= _controller.setBrightness(CONFIG_LEDRING_R, LED_FULLY_OFF);
        status |= _controller.setBrightness(CONFIG_LEDRING_G, LED_FULLY_OFF);
        status |= _controller.setBrightness(CONFIG_LEDRING_B, LED_FULLY_OFF);
        return status;
    }
    esp_err_t LedRing::color(LedColor_t color, uint16_t brightness) {
        return _controller.setBrightness(resolveColorChannel(color), brightness);
    }
    esp_err_t LedRing::_driver_sleep() {
        if(_deviceInSleepMode) {
            //device already asleep
            ESP_LOGI(LOG_TAG, "Cant put device to sleep. Already in sleep mode.");
            return ESP_OK;
        }
        _deviceInSleepMode = true;
        return _controller.sleep();
    }
    esp_err_t LedRing::_driver_wakeup() {
        if(!_deviceInSleepMode) {
            //device already asleep
            ESP_LOGI(LOG_TAG, "Cant wake device up. Already awake");
            return ESP_OK;
        }
        return _controller.wakeup();
    }
}
LedRing_t buttonLedRing = Hardware::LedRing(i2c0);