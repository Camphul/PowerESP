//
// Created by luca on 8/22/21.
//

#include "Init.hpp"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "INITSYS"
#define INIT_WORK_ITEM_QUEUE_STACK_DEPTH 2048
#define INIT_WORK_ITEM_QUEUE_PRIORITY 5
#include "Gpio.h"
#include "PCA9632.h"
#include "GpioInitWorkItem.hpp"
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
    Gpio::GpioOutput powerOutput(GPIO_NUM_33);
    ESP_ERROR_CHECK(powerOutput.init());
    ESP_ERROR_CHECK(powerOutput.set(1));
    ESP_ERROR_CHECK(powerOutput.holdPin(true));
    I2C_t& i2cMaster = i2c0;
    ESP_ERROR_CHECK(i2cMaster.begin(GPIO_NUM_21, GPIO_NUM_22,
                                    400000));
    i2cMaster.setTimeout(10);
    ESP_ERROR_CHECK(ledRing.init_device());
    ESP_ERROR_CHECK(ledRing.configureOutputs(false, PwmControl::STOP_COMMAND, PwmControl::OPEN_DRAIN, PwmControl::ZERO));
    ESP_ERROR_CHECK(ledRing.setBrightness(CONFIG_LEDRING_R, 255));
    int channel = 0;
    for(int x =15; x > 0; x--) {
        if(channel >= 3) {
            channel = 0;
        }
        ledRing.setBrightness(CONFIG_LEDRING_R, 0);
        ledRing.setBrightness(CONFIG_LEDRING_G, 0);
        ledRing.setBrightness(CONFIG_LEDRING_B, 0);
        ledRing.setBrightness(channel, 255);
        channel += 1;
        DelayMS(1000);
    }
    powerOutput.holdPin(false);
    powerOutput.set(false);
    ESP_LOGI(LOG_TAG, "Finished work shuttong myself down.");
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
    initWorkQueue.QueueWork(new GpioInitWorkItem(true));
    ESP_LOGI(LOG_TAG, "Done with init");
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