//
// Created by luca on 8/20/21.
//
#include "main.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main pe_main;

extern "C" void app_main(void)
{
    ESP_ERROR_CHECK(pe_main.setup());
    while(true)
    {
        pe_main.run();
    }
}

esp_err_t Main::setup(void) {
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "Main setup invocation");
    led.init();
    return status;
}

void Main::run(void) {
    ESP_LOGI(LOG_TAG, "LED on");
    led.set(true);
    vTaskDelay(pdSECOND);
    ESP_LOGI(LOG_TAG, "LED off");
    led.set(false);
    vTaskDelay(pdSECOND);
}