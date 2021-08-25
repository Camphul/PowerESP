//
// Created by luca on 8/23/21.
//

#ifndef POWERESP_GPIOINITWORKITEM_HPP
#define POWERESP_GPIOINITWORKITEM_HPP
#include "InitWorkItem.hpp"
class GpioInitWorkItem : public InitWorkItem {
    public:
        GpioInitWorkItem(bool freeAfterComplete = false )
        : InitWorkItem("GpioInit", freeAfterComplete) {
        };
        void Initialize(void) override;
};

#endif //POWERESP_GPIOINITWORKITEM_HPP
