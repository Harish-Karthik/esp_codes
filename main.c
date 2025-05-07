#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>

#define LED_1 GPIO_NUM_2
#define LED_2 GPIO_NUM_4

void BLINK_LED_1(void *pvParameter)
{
    gpio_set_level(LED_1, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    gpio_set_level(LED_1, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}

void BLINK_LED_2(void *pvParameter)
{
    gpio_set_level(LED_2, 1);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    gpio_set_level(LED_2, 0);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

void app_main(void)
{
   // gpio_pad_select_gpio(LED_1);
   // gpio_pad_select_gpio(LED_2);

    gpio_set_direction(LED_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_2, GPIO_MODE_OUTPUT);

    xTaskCreate(BLINK_LED_1, "LED_1_BLINK", 2048,"led is blinking", 1, NULL);
    xTaskCreate(BLINK_LED_1, "LED_2_BLINK", 2048,"led is blinking", 1, NULL);

}