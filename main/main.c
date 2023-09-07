#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include <stdio.h>

#define LED_GPIO_PIN 5

void led_init()
{
    esp_rom_gpio_pad_select_gpio(LED_GPIO_PIN);
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);
}

void led_blink_task(void *ignore)
{
    int led_state = 1u;

    while(true)
    {
        led_state = !led_state;
        gpio_set_level(LED_GPIO_PIN, led_state);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    // LED init.
    led_init();
    xTaskCreate(&led_blink_task, "led_blink_task",  1024, NULL, 6, NULL);
}
