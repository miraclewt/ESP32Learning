#include <stdio.h>
#include "Port.h"

void Port_Init(void)
{
    gpio_config_t portConfig={};
    portConfig.intr_type=GPIO_INTR_DISABLE;
    portConfig.mode=GPIO_MODE_OUTPUT;
    portConfig.pin_bit_mask=RGB;
    portConfig.pull_up_en=false;
    portConfig.pull_down_en=false;
    gpio_config(&portConfig);
}