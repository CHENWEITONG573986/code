#include"UP_System.h"
#include "UP_USR232.h" 
#include "UP_UART.h"
#include "UP_Globle.h"
#include "UP_Woody_VoicePlaying.h"
 /*************************************
 *��������
 **************************************/
 
 u32 w[2]={0x00,0x00};
 u32 data1;
/*************************************************
	��������: UP_Woody_PlayingMusic
  ��������: ����woody��������
  �����������õĺ���: void UP_USR232_Putc(unsigned char c);
  ���ñ������ĺ���: ��    
  �������˵��: u32 data1����Χ0-255�����Ŷ�Ӧ����id 0x00~0x31
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��: ��  
*************************************************/
void UP_Woody_PlayingMusic(u32 data1)
{	 
	u32 sum=0x55+0xaa+0x07+0x20;
	w[0]=0x00;
	w[1]=data1;
	
	
	UP_UART5_Putc(0x55);
	UP_UART5_Putc(0xaa);
	UP_UART5_Putc(0x07);
	UP_UART5_Putc(0x20);
	UP_UART5_Putc(w[0]);
	UP_UART5_Putc(w[1]);
	sum+=data1;
	UP_UART5_Putc(sum);
	UP_delay_ms(DELAY_TIMES);
}


