//
// Created by luca on 8/9/21.
//

#ifndef POWERESP_IIC_H
#define POWERESP_IIC_H
#include "esp_err.h"
#define I2C_MASTER_SCL_IO           22      /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           21      /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0                          /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          400000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000
#define PE_OLED_ADDR1 0x3C /* 60, 0x3C */
#define PE_OLED_ADDR2 0x3C*2 /* 60*2=120, 0x3C*2 = 0x78 */
#define PE_PCA_ADDR1 0x62 /* 98, 0x62 */
#define PE_PCA_ADDR2 0x70 /* 112, 0x70 */
esp_err_t pe_beginI2C(void);
esp_err_t pe_generic_write_i2c_register_two_words(uint8_t regaddr, uint16_t valueA, uint16_t valueB);
esp_err_t pe_generic_write_i2c_register_word(uint8_t regaddr, uint16_t value);
esp_err_t pe_generic_write_i2c_register(uint8_t regaddr, uint8_t value);
esp_err_t pe_generic_read_two_i2c_register(uint8_t regaddr, uint8_t* valueA, uint8_t* valueB);
esp_err_t pe_generic_read_i2c_register_word(uint8_t regaddr, uint16_t* value);
#endif //POWERESP_IIC_H
