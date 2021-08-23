//
// Created by luca on 8/20/21.
//
#include "main.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Init.hpp"
/**
 * Entrypoint to our application.
 */
extern "C" void app_main(void)
{
    ESP_LOGV(LOG_TAG, "Creating Root Init Task/Thread");
    rootTask.Start();
    vTaskDelete(nullptr);
    ESP_LOGV(LOG_TAG, "Reached end of app_main");
}
