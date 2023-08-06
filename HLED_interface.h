/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : HAL            ****************/
/************* Module : LED            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 6/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

#define LED_PIN_SINK         1
#define LED_PIN_SOURCE       2

#define LED_PORT_SOURCE      3
#define LED_PORT_SINK        4


#define LED_PIN_ON           1
#define LED_PIN_OFF          2

#define LED_PORT_ON         0xff
#define LED_PORT_OFF        0x00


#define LED_PORTA       DIO_PORTA
#define LED_PORTB       DIO_PORTB
#define LED_PORTC       DIO_PORTC
#define LED_PORTD       DIO_PORTD

#define LED_PIN0        DIO_PIN0
#define LED_PIN1        DIO_PIN1
#define LED_PIN2        DIO_PIN2
#define LED_PIN3        DIO_PIN3
#define LED_PIN4        DIO_PIN4
#define LED_PIN5        DIO_PIN5
#define LED_PIN6        DIO_PIN6
#define LED_PIN7        DIO_PIN7



typedef struct{
	u8 LedConnection ;
	u8 LedPort ;
	u8 LedPin ;
}led_pin_t;

typedef struct{
	u8 LedConnection ;
	u8 LedPort ;
}led_port_t;

void HLED_voidLedPinState(led_pin_t Copy_u8LedStruct,u8 Copy_u8LedPinState);
void HLED_voidLedPortState(led_port_t Copy_u8LedStruct,u8 Copy_u8LedState);


#endif /* HLED_INTERFACE_H_ */
