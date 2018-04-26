/*
 * encoder.c
 *
 *  Created on: Apr 26, 2018
 */

#include "encoder.h"

// disable 1MS timer interrupt
void noInterrupt1Ms()
{
	timer_disable_intr(TIMERGROUP1MS, msTimer);
}

// enable 1MS timer interrupt
void interrupt1Ms()
{
	timer_enable_intr(TIMERGROUP1MS, msTimer);
}

void encoderLoop()
{
	Button newButton ;
	static int16_t oldValue = 0;
	/*
	event_lcd_t evt;

// Encoder loop
		newValue = - getValue();
		newButton = getButton();
		if (newValue != 0)
		{
		//    Serial.print("Encoder: ");Serial.println(newValue);
			// reset our accelerator
			if ((newValue >0)&&(oldValue<0)) oldValue = 0;
			if ((newValue <0)&&(oldValue>0)) oldValue = 0;
			wakeLcd();
		}
		else
		{
			// lower accelerator
			if (oldValue <0) oldValue++;
			if (oldValue >0) oldValue--;
		}

		if (newButton != Open)
		{
			wakeLcd();
			ESP_LOGD(TAG,"Button: %d",newButton);
			if (newButton == Clicked) {startStop();}
			if (newButton == DoubleClicked) { toggletime();}

//			if (getPinState() == getpinsActive())
			if ((newButton == Held)&&(getPinState() == getpinsActive()))
			{
				currentValue = newValue;
				changeStation(newValue);
			}

		}	else
		{
			if ((stateScreen  != sstation)&&(newValue != 0))
			{
				ESP_LOGD(TAG,"Enc value: %d, oldValue: %d,  incr volume: %d",newValue, oldValue,newValue+(oldValue*3));
				evt.lcmd = evol;
				evt.lline = (char*)((uint32_t)newValue+(oldValue*3));
				xQueueSend(event_lcd,&evt, 0);
			}
			if ((stateScreen  == sstation)&&(newValue != 0))
			{
				currentValue += newValue;
				evt.lcmd = estation;
				evt.lline = (char*)((uint32_t)newValue);
				xQueueSend(event_lcd,&evt, 0);
			}
		}
		oldValue += newValue;
// end Encoder loop
*/
}

void task_encoder(void *pvParams)
{
	printf("task_encoder!\n");

	ClickEncoderInit(PIN_ENCODER_A, PIN_ENCODER_B, PIN_ENCODER_BTN);

	while (1)
	{
		encoderLoop();
	}
	vTaskDelete( NULL );
}


