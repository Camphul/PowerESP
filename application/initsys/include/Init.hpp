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
#define ROOT_TASK_STACK_DEPTH 8192
#define ROOT_TASK_PRIORITY 3
#include <stdio.h>
namespace initsys {
    class Init;
}
using Init_t = initsys::Init;
extern Init_t rootTask;
using namespace cpp_freertos;
using namespace std;
namespace initsys {
    /**
     * FreeRTOS system init thread/task.
     */
    class Init : public Thread {
    public:
        Init()
        : Thread("RootInitTask", ROOT_TASK_STACK_DEPTH, ROOT_TASK_PRIORITY, APP_CPU)
        {
        };
        esp_err_t init(void);
        esp_err_t loop(void);
        esp_err_t shutdown(uint8_t secondsDelay =5);
    protected:
        void Run() override;
    };


}


#endif //POWERESP_INIT_HPP
