#include "main.h"
extern "C" void SystemClock_Config(void); // сгенерирован Cube

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    GPIO_InitTypeDef led{GPIO_PIN_13, GPIO_MODE_OUTPUT_PP,
                         GPIO_SPEED_FREQ_LOW, 0};
    HAL_GPIO_Init(GPIOC, &led);

    while (true)
    {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        HAL_Delay(500);
    }
}