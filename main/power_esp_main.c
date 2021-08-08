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
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "hal/gpio_types.h"
#define PE_SOFTLATCH_OUTPUT_PIN GPIO_NUM_32
#define PE_SOFTLATCH_BTN_PIN GPIO_NUM_27
#define PE_GPIO_HIGH 1
#define PE_GPIO_LOW 0

void app_main(void)
{
    gpio_set_direction(PE_SOFTLATCH_OUTPUT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(PE_SOFTLATCH_OUTPUT_PIN, PE_GPIO_HIGH);
   // gpio_hold_en(PE_SOFTLATCH_OUTPUT_PIN);
    printf("PowerESP Booting up!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
            CONFIG_IDF_TARGET,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

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
}
