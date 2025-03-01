#include <driver/gpio.h>

#define LED_R GPIO_NUM_0
#define LED_G GPIO_NUM_1
#define LED_B GPIO_NUM_8
#define RGB ((1<<LED_R)|(1>>LED_G)|(1<<LED_B))

void Port_Init(void);
