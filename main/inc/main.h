//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_MAIN_H
#define POWERESP_MAIN_H
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define pdSECOND pdMS_TO_TICKS(1000)

class Main final {
public:
    esp_err_t setup(void);
    void run(void);
};

#endif //POWERESP_MAIN_H
