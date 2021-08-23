//
// Created by luca on 8/22/21.
//

#include "Init.hpp"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "INITSYS"

Init_t rootTask = initsys::Init();

using namespace initsys;
void Init::Run() {
    ESP_LOGI(LOG_TAG, "Initializing system");
    esp_err_t initStatus = init();
    if(ESP_OK != initStatus) {
        ESP_LOGI(LOG_TAG, "Failed system initialization!");
        ESP_ERROR_CHECK(initStatus);
    }
    while(1) {
        esp_err_t loopStatus = loop();
        if(ESP_OK != loopStatus) {
            ESP_LOGI(LOG_TAG, "Main program loop returned non-ok status: %d. Exiting program loop.", loopStatus);
            ESP_ERROR_CHECK(shutdown(0));
            continue;
        }
    }
    ESP_LOGI(LOG_TAG, "Exiting root task's Run()");
}
/**
 * @brief initialize system.
 * @return if the system initialized correctly.
 */
esp_err_t Init::init() {
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "Init invoked");
    return status;
}

/**
 * @brief system loop
 * @return if loop ran successfully
 */
esp_err_t Init::loop() {
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "Loop invoked");
    Delay(pdSECOND);
    return status;
}

esp_err_t Init::shutdown(uint8_t msDelay) {
    esp_err_t status{ESP_OK};
    TickType_t ticks = pdMS_TO_TICKS(msDelay);
    ESP_LOGI(LOG_TAG, "Shutdown invoked, will shutdown in %d milliseconds(%d ticks)", msDelay, ticks);
    return status;
}