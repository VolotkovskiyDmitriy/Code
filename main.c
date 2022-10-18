#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"


int main(void){
GPIO_InitTypeDef gpioConf;


RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
gpioConf.GPIO_Pin = GPIO_Pin_0;
gpioConf.GPIO_Mode = GPIO_Mode_IN;
GPIO_Init(GPIOA, &gpioConf);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


gpioConf.GPIO_Pin = GPIO_Pin_12;
gpioConf.GPIO_Mode = GPIO_Mode_OUT;
gpioConf.GPIO_Speed = GPIO_Speed_100MHz;
gpioConf.GPIO_OType = GPIO_OType_PP;
gpioConf.GPIO_PuPd = GPIO_PuPd_NOPULL;

GPIO_Init(GPIOD, &gpioConf);

while(1) {

	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0) {
		if (GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_12)) {
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);
			GPIO_ResetBits(GPIOD, GPIO_Pin_13);
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
		}
		else {
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
		}
		while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==0);



	}
}

}
