//
// Created by luca on 8/23/21.
//
#include "GpioInitWorkItem.hpp"
#include "esp_err.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "GPIO_INIT"
#include "Gpio.h"
void GpioInitWorkItem::Initialize() {
    ESP_LOGD(LOG_TAG, "Configuring GPIO.");
    ESP_ERROR_CHECK(powerBootstrap.set(true)); //most important line, maintains power after user stops pressing the button.
    ESP_ERROR_CHECK(powerBootstrap.holdPin(true)); // second most important, doesnt cause shutdown by random glitches.
    ESP_LOGI(LOG_TAG, "Bootstrapped cmos power mechanism through GPIO. Power should be stable now.");

}

