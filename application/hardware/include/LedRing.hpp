//
// Created by luca on 8/25/21.
//

#ifndef POWERESP_LEDRING_HPP
#define POWERESP_LEDRING_HPP
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "thread.hpp"
#include "ticks.hpp"
#include "workqueue.hpp"
#include "PCA9632.h"
namespace Hardware {
    class LedRing;
}
typedef enum {
    RED,
    GREEN,
    BLUE
} LedColor_t;
using LedRing_t = Hardware::LedRing;
//meant for the RGB ledring around the power button.
extern LedRing_t buttonLedRing;
using namespace cpp_freertos;
#define LED_FULLY_ON 255
#define LED_FULLY_OFF 0
namespace Hardware {
    class LedRing {
    public:
        constexpr LedRing(const PwmControl::PCA9632 &controller = pwmLedRingController) : _controller{controller} {

        };
        esp_err_t init(void);
        esp_err_t allOff(void);
        esp_err_t color(LedColor_t color, uint16_t brightness=LED_FULLY_ON);
        esp_err_t red(uint8_t brightness=255) { return color(RED, brightness);};
        esp_err_t green(uint8_t brightness=255) { return color(GREEN, brightness);};
        esp_err_t blue(uint8_t brightness=255) { return color(BLUE, brightness);};
        esp_err_t _driver_sleep(void);
        esp_err_t _driver_wakeup(void);

    protected:
        PwmControl::PCA9632 _controller;
        bool _deviceInSleepMode = false;
        uint8_t resolveColorChannel(LedColor_t color);
    };
}
#endif //POWERESP_LEDRING_HPP
