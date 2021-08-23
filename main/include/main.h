//
// Created by luca on 8/20/21.
//

#ifndef POWERESP_MAIN_H
#define POWERESP_MAIN_H
#ifndef CPP_FREERTOS_NO_EXCEPTIONS
#define CPP_FREERTOS_NO_EXCEPTIONS
#endif
#define I2C_CLK_FREQ 400000
/* START PIN CONFIGURATION - MAKE GPIO PIN DEFINITIONS CONFIGURABLE THROUGH ESP-IDF MENUCONFIG! */
#define I2C_SDA_PIN GPIO_NUM_21
#define I2C_SCL_PIN GPIO_NUM_22
// V defines the pin which is connected to a nmos to keep power on
#define GPIO_PIN_SOFTLATCH_POWER GPIO_NUM_33
// V detects activity on the other mosfet which is connected to a button.
#define GPIO_PIN_SOFTLATCH_BUTTON GPIO_NUM_32
/* END PIN CONFIGURATION */
/* START LEDRING CHANNEL DEFINITIONS */
#define LEDRING_R 0
#define LEDRING_G 1
#define LEDRING_B 2
/* END LEDRING CHANNEL DEFINTIONS */
#endif //POWERESP_MAIN_H
