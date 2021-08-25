//
// Created by luca on 8/23/21.
//
#include "HardwareInitWorkItem.hpp"
#include "esp_err.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "Hardware_INIT"
#include "LedRing.hpp"
using namespace Hardware;
void HardwareInitWorkItem::Initialize() {
    ESP_LOGD(LOG_TAG, "Configuring remaining hardware devices...");
    ESP_ERROR_CHECK(buttonLedRing.init());
    //LedRingFlashNotification_t &redPattern;
    //redPattern  = new PowerButton::LedRingFlashNotification(buttonLedRing, RED, pdMS_TO_TICKS(500));
    //buttonLedRing.displayNotification(redPattern);
    ESP_ERROR_CHECK(buttonLedRing.allOff());
    //LedRingFlashNotification_t greenPattern(buttonLedRing, GREEN, pdMS_TO_TICKS(1000));
    // buttonLedRing.displayNotification(greenPattern);
    ESP_LOGI(LOG_TAG, "Configured connected hardware.");

}

