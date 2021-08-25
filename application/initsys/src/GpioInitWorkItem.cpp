//
// Created by luca on 8/23/21.
//
#include "GpioInitWorkItem.hpp"
#include "esp_err.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "GPIO_INIT"
void GpioInitWorkItem::Initialize() {
    ESP_LOGI(LOG_TAG, "Finished work shuttong myself down.");

}

