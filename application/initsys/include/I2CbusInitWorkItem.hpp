//
// Created by luca on 8/23/21.
//

#ifndef POWERESP_I2CBUSINITWORKITEM_HPP
#define POWERESP_I2CBUSINITWORKITEM_HPP
#include "InitWorkItem.hpp"
class I2CbusInitWorkItem : public InitWorkItem {
public:
    I2CbusInitWorkItem(bool freeAfterComplete = false )
    : InitWorkItem("I2CbusInit", freeAfterComplete) {
    };
    void Initialize(void) override;
};

#endif //POWERESP_I2CBUSINITWORKITEM_HPP
