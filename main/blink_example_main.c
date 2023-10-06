
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

// #define BLINK_GPIO CONFIG_BLINK_GPIO // 5
#define led_pin 2



void app_main(void)
{
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(led_pin, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(led_pin, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}


// void app_main(void)
// {
//     gpio_set_direction(button_pin, GPIO_MODE_INPUT);

//     while (1)
//     {
//         uint8_t s_led_state = gpio_get_level(button_pin);
//         if (s_led_state)
//         {
//             printf("led on----------------------------------->");
//         }
//         else
//         {
//             printf("led offff----------------------------------->");
//         }
//     }
// }

// void app_main(void)
// {
//     esp_http_client_config_t config = {
//         .url = "https://parseapi.back4app.com/classes/B4aVehicle/jadkSa4E7W",
//         .method = HTTP_METHOD_PUT,
//         .headers = {
//             "X-Parse-Application-Id" : "xc6ma9Ot8MP7HfVJ0QiojPExB8paEcIqBT5abnCB",
//             "X-Parse-REST-API-Key" : "z2jm18Wsdiv3B0jJMSmgk5OD6XN0icMsNJghy4nO",
//             "Content-Type" : "application/json",
//         },
//         .buffer_size = 1024,
//     };

//     esp_http_client_config_t config = {
//         .url = "https://parseapi.back4app.com/classes/B4aVehicle/jadkSa4E7W",
//     };

//     esp_http_client_handle_t client = esp_http_client_init(&config);
//      esp_http_client_set_header(client, "xc6ma9Ot8MP7HfVJ0QiojPExB8paEcIqBT5abnCB", "z2jm18Wsdiv3B0jJMSmgk5OD6XN0icMsNJghy4nO");

//     esp_http_client_set_method(client, HTTP_METHOD_PUT);

//     char post_data[100];
//     //    = "{\"state\": \"on\"}";
//     sprintf(post_data, "{\"state\": \"%d\"}", s_led_state);
//     // esp_http_client_handle_t client = esp_http_client_init(&config);
//     esp_http_client_set_post_field(client, post_data, strlen(post_data));
//     esp_err_t err = esp_http_client_perform(client);
//     esp_http_client_cleanup(client);

//     if (err == ESP_OK)
//     {
//         printf("Data sent successfully to Back4App\n");
//     }
//     else
//     {
//         printf("Failed to send data to Back4App. Error code: %d\n", err);
//     }
// }