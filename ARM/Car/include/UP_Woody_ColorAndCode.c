#include "STM32Lib\\stm32f10x.h"
#include"UP_System.h"
#include "UP_USR232.h" 
#include "UP_UART.h"
#include "UP_Globle.h"
#include "UP_Woody_ColorAndCode.h"

/****************************************************
��ͣ����
*****************************************************/

/**************************************
��������;UP_Woody_StartUp
��������:����woody����Ӧ����
�����������õĺ���:UP_USR232_Putc?UP_UART5_Putc
���ñ������ĺ�������
�������˵��:u32 command:��Χ0-255(ʵ�ʷ�Χ0-35,��鿴��ͣ���������)
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_StartUp(u32 command){
	u32 sum=0x55+0xaa+0x06+0x02;
	UP_UART5_Putc(0x55);
	UP_UART5_Putc(0xaa);
	UP_UART5_Putc(0x06);
	UP_UART5_Putc(0x02);
	UP_UART5_Putc(command);
	sum+=command;
	UP_UART5_Putc(sum);
}
/******************************************************************
��ɫʶ��ģ�� 
******************************************************************/

/**************************************
�������ƣ�UP_Woody_ColorRecLetIssue
�������ܣ���ɫʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_ColorRecLetIssue(){
	char str[5]={0x55,0xAA,0x05,0x40,0x44};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_ColorRecLetIssue
�������ܣ���ɫʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_ColorRecForbidIssue(){
	char str[5]={0x55,0xAA,0x05,0x41,0x45};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_ColorRec_ID_Judge
�������ܣ���ɫʶ�𷵻ص�ID
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ��ID��ʮ������ֵ��ʽ����Χ0~255
����˵������
**************************************/
u16 UP_Woody_ColorRec_ID_Judge(void)
{
	ID=(UP_Woody_ReturnData[4]&0X0F)+((UP_Woody_ReturnData[4]&0XF0)>>4)*16;
	return ID;
}
/*************************************************
�������ƣ�UP_Woody_ColorRec_ID_Judge
�������ܣ���ʾ��ɫʶ�𷵻ص�ID
�����������õĺ�������
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
*************************************************/
 void UP_Woody_Display_ColorID(void)
  {
	 printf("(Pixel)%lud\n",UP_Woody_ColorRec_ID_Judge());
	 UP_delay_ms(3000);
	 UP_LCD_ClearScreen();
	}
/******************************************************************
����ʶ��ģ�� 
******************************************************************/

/**************************************
�������ƣ�UP_Woody_BarCodeRecLetIssue
�������ܣ�����ʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_BarCodeRecLetIssue(){
	char str[5]={0x55,0xAA,0x05,0x50,0x54};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_BarCodeRecForbidIssue
�������ܣ�����ʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_BarCodeRecForbidIssue(){
	char str[5]={0x55,0xAA,0x05,0x51,0x55};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_CodeRec_ID_Judge
�������ܣ�����ʶ�𷵻ص�ID
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ��ID��ʮ������ֵ��ʽ����Χ0~255
����˵������
**************************************/
u16 UP_Woody_BarCodeRec_ID_Judge(void)
{
	ID=(UP_Woody_ReturnData[4]&0X0F)+((UP_Woody_ReturnData[4]&0XF0)>>4)*16;
	return ID;
}
/*************************************************
�������ƣ�UP_Woody_Display_BarCodeID
�������ܣ���ʾ����ʶ�𷵻ص�ID
�����������õĺ�������
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
*************************************************/
 void UP_Woody_Display_BarCodeID(void)
  {
	 printf("(Pixel)%lud\n",UP_Woody_BarCodeRec_ID_Judge());
	 UP_delay_ms(3000);
	 UP_LCD_ClearScreen();
	}

/******************************************************************
��ά��ʶ��ģ�� 
******************************************************************/

/**************************************
�������ƣ�UP_Woody_QrCodeRecLetIssue
�������ܣ�����ʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_QrCodeRecLetIssue(){
	char str[5]={0x55,0xAA,0x05,0x60,0x64};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_QrCodeRecForbidIssue
�������ܣ�����ʶ�������·�
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
**************************************/
void UP_Woody_QrCodeRecForbidIssue(){
	char str[5]={0x55,0xAA,0x05,0x61,0x65};
	for(lab=0;lab<5;lab++){
		UP_UART5_Putc(str[lab]);
	}
	UP_delay_ms(DELAY_TIMES);
}
/**************************************
�������ƣ�UP_Woody_QrCodeRec_ID_Judge
�������ܣ�����ʶ�𷵻ص�ID
�����������õĺ�����UP_USR232_Putc��UP_UART5_Putc
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ��ID��ʮ������ֵ��ʽ����Χ0~255
����˵������
**************************************/
u16 UP_Woody_QrCodeRec_ID_Judge(void)
{
	ID=(UP_Woody_ReturnData[4]&0X0F)+((UP_Woody_ReturnData[4]&0XF0)>>4)*16;
	return ID;
}
/**************************************
�������ƣ�UP_Woody_Display_QrCodeID
�������ܣ���ʾ��ά��ʶ�𷵻ص�ID
�����������õĺ�������
���ñ������ĺ�������
�������˵������
�������˵������
��������ֵ����
����˵������
*************************************************/
 void UP_Woody_Display_QrCodeID(void)
  {
	 printf("(Pixel)%lud\n",UP_Woody_BarCodeRec_ID_Judge());
	 UP_delay_ms(3000);
	 UP_LCD_ClearScreen();
	}
