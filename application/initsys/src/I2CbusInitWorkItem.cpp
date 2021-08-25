//
// Created by luca on 8/23/21.
//
#include "I2CbusInitWorkItem.hpp"
#include "esp_err.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "I2Cbus_INIT"
#include "I2Cbus.hpp"
const gpio_num_t I2C_SDA_PIN = (gpio_num_t)CONFIG_I2C_SDA_PIN;
const gpio_num_t I2C_SCL_PIN = (gpio_num_t)CONFIG_I2C_SCL_PIN;
const uint32_t I2C_CLK_FREQ = CONFIG_I2C_CLK_FREQ;
void I2CbusInitWorkItem::Initialize() {
    ESP_LOGD(LOG_TAG, "Configuring thread-safe I2C bus...");
    I2C_t& i2cMaster = i2c0;
    ESP_ERROR_CHECK(i2cMaster.begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_CLK_FREQ));
    ESP_LOGI(LOG_TAG, "Initialized I2Cbus at a frequency of %dHz. SDA at GPIO%d. SCL at GPIO%d.", I2C_CLK_FREQ, I2C_SDA_PIN, I2C_SCL_PIN);
    i2cMaster.setTimeout(10);

}

