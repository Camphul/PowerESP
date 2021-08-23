//
// Created by luca on 8/23/21.
//

#ifndef POWERESP_GPIOINITWORKITEM_HPP
#define POWERESP_GPIOINITWORKITEM_HPP
#include "InitWorkItem.hpp"
class GpioInitWorkItem : public InitWorkItem {
    public:
        GpioInitWorkItem(string name, bool freeAfterComplete = false )
        : InitWorkItem(name, freeAfterComplete) {
        };
        void Initialize(void) override;
};

#endif //POWERESP_GPIOINITWORKITEM_HPP
