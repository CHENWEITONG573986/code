/******************************************************************/
//	Copyright (C), 2011-2012, �������� 
//  Author   	  	: ����Ԫ  
//  Reviser				: �����
//  Update Date   : 2012/08/01
//  Version   	  : 1.3          
//  Description   : Transplant to v3.5 function library
/******************************************************************/ 

#ifndef SERVO_L
#define SERVO_L

//Ӳ����ʼ��
extern void  UP_IOout_Init(void);																		//�����س�ʼ��
extern void  UP_IOout_SetIO(u8 Channel, u8 Value);									//����ģ�����˿�IO�����ƽ��ͨ��0~7��ֵ0��1
extern void  UP_IOout_SetALLIO(u8 Value);														//ͬʱ����8·ģ�����˿�IO�����ƽ��ֵ0x00~0xFF

#endif
