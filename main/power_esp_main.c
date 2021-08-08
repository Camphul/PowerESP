/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <driver/gpio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "PEChipInfo.h"
#include "hal/gpio_types.h"
#include "iic.h"
#define PE_SOFTLATCH_OUTPUT_PIN GPIO_NUM_32
#define PE_SOFTLATCH_BTN_PIN GPIO_NUM_27
#define PE_GPIO_HIGH 1
#define PE_GPIO_LOW 0
#define PE_DEBUG_AUTOREBOOT 1
void app_main(void)
{
    gpio_set_direction(PE_SOFTLATCH_OUTPUT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(PE_SOFTLATCH_OUTPUT_PIN, PE_GPIO_HIGH);
   // gpio_hold_en(PE_SOFTLATCH_OUTPUT_PIN);
    pe_beginI2C();
    printf("PowerESP Booting up!\n");
    ESP_ERROR_CHECK(pePrintChipInfo());

#if PE_DEBUG_AUTOREBOOT
    for (int i = 120; i >= 0; i--) {
        if( i % 5 != 0) {
            gpio_set_level(PE_SOFTLATCH_OUTPUT_PIN, PE_GPIO_LOW);
           // gpio_hold_dis(PE_SOFTLATCH_OUTPUT_PIN);
        } else {
            gpio_set_level(PE_SOFTLATCH_OUTPUT_PIN, PE_GPIO_HIGH);
            //gpio_hold_en(PE_SOFTLATCH_OUTPUT_PIN);
        }
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
#endif
}
