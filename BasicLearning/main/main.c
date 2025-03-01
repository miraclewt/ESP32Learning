#include <stdio.h>
#include "Port.h"
#include <inttypes.h>
#include <stdbool.h>
#include <freertos/FreeRTOS.h>

static void port_task(void *arg)
{
    bool red_active = true;

    while (true)
    {
        // 切换颜色
        if (red_active)
        {
            gpio_set_level(LED_R, true);
            gpio_set_level(LED_G, false);
            gpio_set_level(LED_B, false);
        }
        else
        {
            gpio_set_level(LED_R, false);
            gpio_set_level(LED_G, false);
            gpio_set_level(LED_B, true);
        }

        // 延时
        vTaskDelay(pdMS_TO_TICKS(1000));

        // 切换状态
        red_active = !red_active;
    }
}

void app_main(void)
{
    Port_Init();
    xTaskCreate(port_task, "rgb_task", 1024, NULL, tskIDLE_PRIORITY + 1, NULL);
    // vTaskStartScheduler();
    /* 有关app_main的调度机制需要进一步研究 */
}