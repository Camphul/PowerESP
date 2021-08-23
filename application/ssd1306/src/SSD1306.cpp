//
// Created by luca on 8/21/21.
//

#include "SSD1306.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "SSD1306"
#define SSD1306_INIT_DELAY_MS 500
namespace ssd1306 {
    [[nodiscard]] esp_err_t SSD1306::init_device(void) {
        esp_err_t status{ESP_OK};
        vTaskDelay(pdMS_TO_TICKS(SSD1306_INIT_DELAY_MS));
        status |= ssd1306_command(SSD1306_DISPLAYON); //send 0xAF as defined in power on sequence
        ESP_LOGV(LOG_TAG, "Initializing SSD1306 device.");
        return status;
    }
    [[nodiscard]] esp_err_t SSD1306::sleep(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Putting device to sleep.");
        return status;
    }
    [[nodiscard]] esp_err_t SSD1306::wakeup(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Waking up device.");
        return status;
    }
    [[nodiscard]] esp_err_t SSD1306::reset(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Resetting device.");
        return status;
    }
    /**
     * @brief empties the display buffer. Dont forget to send the buffer afterwards to clear the display.
     * @return standard esp-idf error/success response format.
     */
    [[nodiscard]] esp_err_t SSD1306::clearBuffer(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Clearing buffer/display.");
        return status;
    }
    /**
     * @brief method which is called to send the display buffer to the actual display.
     * @return standard esp-idf error/success response format.
     */
    [[nodiscard]] esp_err_t SSD1306::sendBuffer(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Sending display buffer to device.");
        return status;
    }
    /**
     * @brief method which is called to populate the display buffer with content.
     * @return standard esp-idf error/success response format.
     */
    [[nodiscard]] esp_err_t SSD1306::drawBuffer(void) {
        esp_err_t status{ESP_OK};
        ESP_LOGV(LOG_TAG, "Drawing contents of the buffer.");
        return status;
    }
    /**
     * @brief write byte to register on ssd1306 slave device.
     * @param regAddr register address on slave device.
     * @param value value to set the register on the slave device to.
     * @return default esp success/fail response format.
     */
    [[nodiscard]] esp_err_t SSD1306::writeRegister(uint8_t regAddr, uint8_t value) {
        esp_err_t status{ESP_OK};
        // i2c0 is a thread safe wrapper around the standard esp-idf i2c driver component(we use i2c port 0 for everything).
        status |= i2c0.writeByte(SSD1306_ADDR_WRITE, regAddr, value);
        return status;
    }

    /**
     * @brief send command to device in accordance to the datasheet's specified command decoder/command format.
     * @param command the command to send to the ic.
     * @return default esp success/fail response format.
     */
    [[nodiscard]] esp_err_t SSD1306::ssd1306_command(uint8_t command) {
        esp_err_t status{ESP_OK};
        // i2c0 is a thread safe wrapper around the standard esp-idf i2c driver component(we use i2c port 0 for everything).
        return status;
    }
    /**
     * @brief read byte from register on ssd1306 slave device to a passed pointer.
     * @param regAddr register address on slave device.
     * @param value pointer referencing a memory location to write the content of the given register to once read.
     * @return default esp success/fail response format.
     */
    [[nodiscard]] esp_err_t SSD1306::readRegister(uint8_t regAddr, uint8_t *value) {
        esp_err_t status{ESP_OK};
        // i2c0 is a thread safe wrapper around the standard esp-idf i2c driver component(we use i2c port 0 for everything).
        status |= i2c0.readByte(SSD1306_ADDR_READ/* or the address with an 1*/, regAddr, value);
        return status;
    }
}
