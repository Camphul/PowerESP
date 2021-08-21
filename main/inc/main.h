//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_MAIN_H
#define POWERESP_MAIN_H
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Gpio.h"
#include "I2Cbus.hpp"
#include "PCA9632.h"
#define pdSECOND pdMS_TO_TICKS(1000)
#define I2C_SDA_PIN GPIO_NUM_21
#define I2C_SCL_PIN GPIO_NUM_22
#define I2C_CLK_FREQ 400000
class Main final {
public:
    esp_err_t setup(void);
    void run(void);
    Gpio::GpioOutput led{GPIO_NUM_17};
};

#endif //POWERESP_MAIN_H
