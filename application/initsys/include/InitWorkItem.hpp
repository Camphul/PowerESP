//
// Created by luca on 8/23/21.
//

#ifndef POWERESP_INITWORKITEM_HPP
#define POWERESP_INITWORKITEM_HPP
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "thread.hpp"
#include "ticks.hpp"
#include "workqueue.hpp"
#include <stdio.h>
using namespace std;
using namespace cpp_freertos;
    class InitWorkItem : public WorkItem {
    public:
        InitWorkItem(string name, bool freeAfterComplete = false)
        : WorkItem(freeAfterComplete),
        _name(name) {
            WorkItemCount++;
        };
        ~InitWorkItem() {
            WorkItemCount--;
        };
        virtual void Initialize(void) {

        }
        void Run() override {
            Initialize();
        }
    private:
        const string _name;
        static volatile int WorkItemCount;
    };
#endif //POWERESP_INITWORKITEM_HPP