//
// Created by luca on 8/20/21.
//
#include "main.h"
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main pe_main;

extern "C" void app_main(void)
{
    ESP_ERROR_CHECK(pe_main.setup());
    while(true)
    {
        pe_main.run();
    }
}

static PwmControl::PCA9632 pwmController;
esp_err_t Main::setup(void) {
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "Main setup invocation");
    // start gpio setup
    status |= led.init();
    ESP_ERROR_CHECK(status);
    // end gpio setup
    // start i2c setup
    I2C_t& i2cMaster = i2c0;
    ESP_ERROR_CHECK(i2cMaster.begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_CLK_FREQ));
    i2cMaster.setTimeout(10);
    // i2cMaster.scanner();
    // end i2c setup
    // start PCA9632 setup
    ESP_ERROR_CHECK(pwmController.init_device());
    // end PCA9632 setup
    ESP_LOGI(LOG_TAG, "Main setup completed");
    return status;
}

void Main::run(void) {
    ESP_LOGI(LOG_TAG, "Rerunning loop");
    ESP_ERROR_CHECK(led.toggle());
    vTaskDelay(pdSECOND);
    bool isButtonPressed = button.state();
    ESP_LOGI(LOG_TAG, "Button pressed state is: %s", isButtonPressed ? "yes" : "no");
    /*
    for(uint8_t ledIndex = 0; ledIndex <3; ledIndex++) {
        for(uint16_t brightness = 0; brightness < 256; brightness++) {
            ESP_ERROR_CHECK(pwmController.setBrightness(ledIndex, brightness));
            vTaskDelay(pdMS_TO_TICKS(1));
        }
        for(uint16_t brightness = 256; brightness > 0; brightness--) {
            ESP_ERROR_CHECK(pwmController.setBrightness(ledIndex, brightness));
            vTaskDelay(pdMS_TO_TICKS(1));
        }
        ESP_ERROR_CHECK(pwmController.setBrightness(0, 0));
        ESP_ERROR_CHECK(pwmController.setBrightness(1, 0));
        ESP_ERROR_CHECK(pwmController.setBrightness(2, 0));
        ESP_ERROR_CHECK(led.set(ledIndex % 2 == 0));
    }*/

}