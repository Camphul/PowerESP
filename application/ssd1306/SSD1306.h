//
// Driver for 128x32 monochrome display driven through the i2c bus powered by a SSD1306 driver.
// Created by luca on 8/21/21.
//

#ifndef POWERESP_SSD1306_H
#define POWERESP_SSD1306_H
#include "I2Cbus.hpp"
/* I2C address of the SSD1306 chip which is hardcoded in the ic. (0x3C*2)=0x78 */
#define SSD1306_ADDR_READ 0b01111001
#define SSD1306_ADDR_WRITE 0b01111000

#define SSD1306_MEMORYMODE 0x20          ///< See datasheet
#define SSD1306_COLUMNADDR 0x21          ///< See datasheet
#define SSD1306_PAGEADDR 0x22            ///< See datasheet
#define SSD1306_SETCONTRAST 0x81         ///< See datasheet
#define SSD1306_CHARGEPUMP 0x8D          ///< See datasheet
#define SSD1306_SEGREMAP 0xA0            ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON 0xA5        ///< Not currently used
#define SSD1306_NORMALDISPLAY 0xA6       ///< See datasheet
#define SSD1306_INVERTDISPLAY 0xA7       ///< See datasheet
#define SSD1306_SETMULTIPLEX 0xA8        ///< See datasheet
#define SSD1306_DISPLAYOFF 0xAE          ///< See datasheet
#define SSD1306_DISPLAYON 0xAF           ///< See datasheet
#define SSD1306_COMSCANINC 0xC0          ///< Not currently used
#define SSD1306_COMSCANDEC 0xC8          ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET 0xD3    ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5  ///< See datasheet
#define SSD1306_SETPRECHARGE 0xD9        ///< See datasheet
#define SSD1306_SETCOMPINS 0xDA          ///< See datasheet
#define SSD1306_SETVCOMDETECT 0xDB       ///< See datasheet

#define SSD1306_SETLOWCOLUMN 0x00  ///< Not currently used
#define SSD1306_SETHIGHCOLUMN 0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE 0x40  ///< See datasheet

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range
#define SSD1306_LCDWIDTH 128
#define SSD1306_LCDHEIGHT 32
namespace ssd1306 {
    class SSD1306 {
    public:
        [[nodiscard]] esp_err_t init_device(void);
        [[nodiscard]] esp_err_t sleep(void);
        [[nodiscard]] esp_err_t wakeup(void);
        [[nodiscard]] esp_err_t reset(void);
        [[nodiscard]] esp_err_t clearBuffer(void);
        [[nodiscard]] esp_err_t sendBuffer(void);
        [[nodiscard]] esp_err_t drawBuffer(void);
        uint8_t *buffer(void) { return *_fb; }
    private:
        uint8_t *_fb[(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT)/8];
        [[nodiscard]] esp_err_t writeRegister(uint8_t regAddr, uint8_t value);
        [[nodiscard]] esp_err_t readRegister(uint8_t regAddr, uint8_t* value);
        [[nodiscard]] esp_err_t ssd1306_command(uint8_t command);
    };
}

#endif //POWERESP_SSD1306_H
