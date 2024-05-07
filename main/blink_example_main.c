
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "esp_http_client.h"
#include "esp_log.h"

static const char *TAG = "BLINK";

extern const uint8_t server_cert_pem_start[] asm("_binary_ca_cert_pem_start");
extern const uint8_t server_cert_pem_end[] asm("_binary_ca_cert_pem_end");
#define led_pin 13

void app_main(void)
{
    gpio_reset_pin(led_pin);
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);
    gpio_set_pull_mode(led_pin, GPIO_PULLDOWN_ONLY);


    while (1)
    {
        printf("led-----------------\n");
        gpio_set_level(led_pin, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(led_pin, 0);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
