/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : HAL            ****************/
/************* Module : KPD            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 5/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/
#ifndef HKPD_CONFIG_H_
#define HKPD_CONFIG_H_



#define COL_SIZE           4
#define ROW_SIZE           4


#define KPD_COL_PORT       DIO_PORTD
#define KPD_ROW_PORT       DIO_PORTD

#define KPD_R0             0
#define KPD_R1		  	   1
#define KPD_R2		  	   2
#define KPD_R3		  	   3


#define KPD_C0		  	   4
#define KPD_C1		  	   5
#define KPD_C2		  	   6
#define KPD_C3		  	   7

#define KPD_Arr {{7,8,9,'/'},\
				 {4,5,6,'*'},\
				 {1,2,3,'-'},\
				 {'#',0,'=','+'}}

#endif /* HKPD_CONFIG_H_ */
