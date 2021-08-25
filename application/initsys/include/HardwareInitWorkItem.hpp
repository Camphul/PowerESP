//
// Sets up the rest of the hardware.
// Created by luca on 8/23/21.
//

#ifndef POWERESP_HARDWAREINITWORKITEM_HPP
#define POWERESP_HARDWAREINITWORKITEM_HPP
#include "InitWorkItem.hpp"
class HardwareInitWorkItem : public InitWorkItem {
public:
    HardwareInitWorkItem(bool freeAfterComplete = false )
    : InitWorkItem("HardwareInit", freeAfterComplete) {
    };
    void Initialize(void) override;
};

#endif //POWERESP_HARDWAREINITWORKITEM_HPP
