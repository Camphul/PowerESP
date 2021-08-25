//
// Created by luca on 8/22/21.
//

#include "Init.hpp"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "INITSYS"
#define INIT_WORK_ITEM_QUEUE_STACK_DEPTH 2048*4
#define INIT_WORK_ITEM_QUEUE_PRIORITY 5
#include "Gpio.h"
#include "PCA9632.h"
#include "GpioInitWorkItem.hpp"
#include "I2CbusInitWorkItem.hpp"
#include "HardwareInitWorkItem.hpp"
#include "LedRing.hpp"
Init_t rootTask = initsys::Init();
volatile int InitWorkItem::WorkItemCount = 0;
using namespace initsys;
void Init::Run() {
    ESP_LOGI(LOG_TAG, "Initializing system");
    esp_err_t initStatus = init();
    if(ESP_OK != initStatus) {
        ESP_LOGI(LOG_TAG, "Failed system initialization!");
        ESP_ERROR_CHECK(initStatus);
    }
    ESP_LOGI(LOG_TAG, "Starting main application loop.");
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
    WorkQueue initWorkQueue("init_work_queue", INIT_WORK_ITEM_QUEUE_STACK_DEPTH, INIT_WORK_ITEM_QUEUE_PRIORITY);
    initWorkQueue.QueueWork(new GpioInitWorkItem(true));//Gpio is most important due to power bootstrapping
    initWorkQueue.QueueWork(new I2CbusInitWorkItem(true));//Next follows I2C bus.
    initWorkQueue.QueueWork(new HardwareInitWorkItem(true));//Configure rest of hardware.
    ESP_LOGI(LOG_TAG, "Done with init");
    return status;
}

/**
 * @brief system loop
 * @return if loop ran successfully
 */
esp_err_t Init::loop() {
    esp_err_t status{ESP_OK};
    if(_loopCounter >= UINT32_MAX) {
        ESP_LOGI(LOG_TAG, "Init loop counter reached max. It has been reset to zero.");
        _loopCounter = 0;
    }
    if(_loopCounter %3 == 0) {
        //do stuff
        buttonLedRing.color(RED);
    } else if (_loopCounter %5 == 0) {
        //do stuff
        buttonLedRing.color(GREEN);
    } else if (_loopCounter %6 == 0) {
        //do stuff
        buttonLedRing.color(BLUE);
    } else {
        buttonLedRing.allOff();
    }
    ESP_LOGI(LOG_TAG, "Loop invoked");
    Delay(pdSECOND);
    _loopCounter++;
    return status;
}

esp_err_t Init::shutdown(uint8_t msDelay) {
    esp_err_t status{ESP_OK};
    TickType_t ticks = pdMS_TO_TICKS(msDelay);
    ESP_LOGI(LOG_TAG, "Shutdown invoked, will shutdown in %d milliseconds(%d ticks)", msDelay, ticks);
    return status;
}