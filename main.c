#include "STD_TYPES.h"
#include "MACROS.h"
#include "util/delay.h"
#include "MDIO_interface.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "HLED_interface.h"

void DisplayHours();
void DisplayMinutes();
void DisplaySeconds();
void StopWatchStart();

u8 hr=0,min=0,sec=0;

int main()
{
	u8 flag=0,cursor=0,key ;
	led_pin_t LED={LED_PIN_SOURCE,LED_PORTA,LED_PIN5};
	Port_voidInit();
	HLCD_voidInit();

	HLCD_voidSendString("00:00:00");

	while(1)
	{
		key=HKPD_u8GetPressedKey();
		if(key!=NOT_PRESSED)
		{
			if(key == '+' || key == '-')
			{
				if( cursor==0 )
				{
					switch(key)
					{
					case'+' : hr++ ; DisplayHours(); break ;
					case'-' : hr-- ; DisplayHours(); break ;
					default:break ;
					}
				}

				else if ( cursor==3 )
				{

					switch(key)
					{
					case'+' : min++ ; DisplayMinutes(); break ;
					case'-' : min-- ; DisplayMinutes(); break ;
					default:break ;
					}
				}
				else
				{
					switch(key)
					{
					case'+' : sec++ ; DisplaySeconds(); break ;
					case'-' : sec-- ; DisplaySeconds(); break ;
					default:break ;
					}
				}

			}
			else if (key==0)
			{
				if(cursor==6)
				{
					cursor=0 ;
				}
				else
				{
					cursor+=3 ;
				}
			}
			else if(key=='#')
			{
				if(cursor==0)
				{
					cursor=6 ;
				}
				else
				{
					cursor-=3 ;
				}
			}
			else if (key=='=')
			{
				StopWatchStart();
				flag=1 ;
			}
			else if (key=='/')
			{
				HLCD_voidSendString("00:00:00");
				sec=0 ;
				min=0 ;
				hr=0 ;
				cursor=0 ;
			}

		}
		else
		{
			if(flag==1)
			{
				HLCD_voidClearLcd();
				HLCD_voidSendString("It's Time !") ;
				HLED_voidLedPinState(LED,LED_PIN_ON);
				_delay_ms(400);
				HLCD_voidClearLcd();
				HLED_voidLedPinState(LED,LED_PIN_OFF);
				_delay_ms(400);
			}
		}
	}
}


void DisplayHours()
{
	if(hr==60)
	{
		hr=0 ;
		HLCD_voidSendGoTo(0,0);
		HLCD_voidSendDigit(0);
		HLCD_voidSendDigit(0);
	}
	else if(hr>60)
	{
		hr=59 ;
		HLCD_voidSendInt(hr,0,0);

	}
	if (hr < 10)
	{
		HLCD_voidSendGoTo(0,0);
		HLCD_voidSendDigit(0);
		HLCD_voidSendGoTo(0,1);
		HLCD_voidSendDigit(hr);
	}
	else
	{
		HLCD_voidSendInt(hr,0,0);
	}
}
void DisplayMinutes()
{
	if(min==60)
	{
		min=0 ;
		HLCD_voidSendGoTo(0,3);
		HLCD_voidSendDigit(0);
		HLCD_voidSendDigit(0);
	}
	else if(min>60)
	{
		min=59 ;
		HLCD_voidSendInt(min,0,3);

	}
	if (min < 10)
	{
		HLCD_voidSendGoTo(0,3);
		HLCD_voidSendDigit(0);
		HLCD_voidSendGoTo(0,4);
		HLCD_voidSendDigit(min);
	}
	else
	{
		HLCD_voidSendInt(min,0,3);
	}
}
void DisplaySeconds()
{
	if(sec==60)
	{
		sec=0 ;
		HLCD_voidSendGoTo(0,6);
		HLCD_voidSendDigit(0);
		HLCD_voidSendDigit(0);
	}
	else if(sec>60)
	{
		sec=59 ;
		HLCD_voidSendInt(sec,0,6);

	}
	if (sec < 10)
	{
		HLCD_voidSendGoTo(0,6);
		HLCD_voidSendDigit(0);
		HLCD_voidSendGoTo(0,7);
		HLCD_voidSendDigit(sec);
	}
	else
	{
		HLCD_voidSendInt(sec,0,6);
	}
}
void StopWatchStart()
{
	while (sec !=0 || min !=0 || hr!=0)
	{
		if(sec!=0)
		{
			sec-- ;
			DisplaySeconds();
			_delay_ms(1000);
		}
		else
		{
			sec=59 ;
			DisplaySeconds();
			if(min!=0)
			{

				min-- ;
				DisplayMinutes();
				_delay_ms(1000);
			}
			else
			{
				min=59 ;
				DisplayMinutes();
				hr-- ;
				DisplayHours();
				_delay_ms(1000);
			}
		}
	}

}
