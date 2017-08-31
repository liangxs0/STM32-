#include <stm32f10x.h>
#include "USART1.h"
#include "KEY.h"
#include "Relay.h"
#include "Delay.h"
#include "Beep.h"
#include "LED.h"

int main(void)
{
	
	LED_Init();
	delay_init(72);
while (1)
	{
					Blink();
//		Set_Led(LED_B);
//					delay_ms_(100);
//		Reset_Led(LED_B);
//					delay_ms_(100);
					
	}
	
}


