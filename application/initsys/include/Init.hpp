//
// Created by luca on 8/22/21.
//

#ifndef POWERESP_INIT_HPP
#define POWERESP_INIT_HPP
#ifndef CPP_FREERTOS_NO_EXCEPTIONS
#define CPP_FREERTOS_NO_EXCEPTIONS
#endif
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "thread.hpp"
#include "ticks.hpp"
#include "workqueue.hpp"
#ifndef pdSECOND
#define pdSECOND pdMS_TO_TICKS(1000)
#endif
#include <stdio.h>
using namespace cpp_freertos;
using namespace std;
namespace initsys {
    /**
     * FreeRTOS system init thread/task.
     */
    class Init : public Thread {
    public:
        Init()
        : Thread("RootInitTask", 2014, 3, APP_CPU)
        {
        };
        esp_err_t init(void);
        esp_err_t loop(void);
        esp_err_t shutdown(uint8_t secondsDelay =5);
    protected:
        void Run() override;
    };
}
using Init_t = initsys::Init;
extern Init_t rootTask;


#endif //POWERESP_INIT_HPP
