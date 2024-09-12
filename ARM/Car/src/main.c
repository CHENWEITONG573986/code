#include "include\\UP_System.h"
u8 robot_state = 0;
u8 robot_old_state = 0;
bool forward_flag = 1;

void GetState();
bool IsStateChanged();
void GoForward();								  //(250,364,273,219)(200,455,341,272)(400,228,171,136)
void TurnLeft(int delay, int speed1, int speed2); //(300,303,228,182)
void TurnRight(int delay, int speed1, int speed2);
void BackForward(); //(250,364,273)(200,455,341)
void Squat();
void Standup();
void BackSquat();
void WaveHead(u8 cycle);
void ShakeHead(u8 cycle);
void Nod(u8 cycle);
void Dance();
void Play();
int main(void)
{
	bool bFirst = 0;
	int j = 0;

	UP_System_Init();

	UP_CDS_SetMode(1, CDS_SEVMODE);
	UP_CDS_SetMode(2, CDS_SEVMODE);
	UP_CDS_SetMode(3, CDS_SEVMODE);
	UP_CDS_SetMode(4, CDS_SEVMODE);
	UP_CDS_SetMode(5, CDS_SEVMODE);
	UP_CDS_SetMode(6, CDS_SEVMODE);
	UP_CDS_SetMode(7, CDS_SEVMODE);
	UP_CDS_SetMode(8, CDS_SEVMODE);
	UP_CDS_SetMode(9, CDS_SEVMODE);
	UP_CDS_SetMode(10, CDS_SEVMODE);
	UP_CDS_SetMode(11, CDS_SEVMODE);
	UP_CDS_SetMode(12, CDS_SEVMODE);
	UP_CDS_SetMode(13, CDS_SEVMODE);
	UP_CDS_SetMode(14, CDS_SEVMODE);
	UP_CDS_SetMode(15, CDS_SEVMODE);
	UP_CDS_SetMode(16, CDS_SEVMODE);
	UP_CDS_SetMode(17, CDS_SEVMODE);
	UP_CDS_SetMode(18, CDS_SEVMODE);
	UP_CDS_SetMode(19, CDS_SEVMODE);
	UP_CDS_SetMode(20, CDS_SEVMODE);

	UP_delay_ms(1000);

	while (1)
	{
		GetState();
		switch (robot_state)
		{
		case 1: // ���ϰ�
			if (forward_flag == 1)
			{
				GoForward();
			}
			else
			{
				if (!IsStateChanged())
				{
					j++;
					j %= 15;
					if (j > 13)
						forward_flag = 1;
				}
				Standup();
			}
			break;

		case 2: // ����ϰ�
			if (IsStateChanged())
			{
				BackForward();
			}
			TurnRight(250, 364, 273);
			break;

		case 3: // �Ҳ��ϰ�
			if (IsStateChanged())
			{
				BackForward();
			}
			TurnLeft(250, 364, 273);
			break;

		case 4: // ǰ���ϰ�
			BackForward();
			break;

		case 5: // ad��⵽�ϰ�����ioû�м�⵽�ϰ�
		{
			WaveHead(1);
			BackForward();
			Squat();
			Standup();
		}
		break;
		case 6: // ad��⵽�ϰ��ܽ�����ioû�м�⵽
		{
			BackForward();
			if (bFirst)
			{
				Nod(1);
				Dance();
			}
			else
			{
				Standup();
				Play();
			}
			bFirst = !bFirst;
		}
		break;

		default:
			break;
		}
	}
}

void GetState()
{
	int ad = 0;
	int io1 = 0;
	int io2 = 0;
	static u8 cyc = 0;
	io1 = UP_ADC_GetIO(0);
	io2 = UP_ADC_GetIO(1);
	ad = UP_ADC_GetValue(7);
	if (ad < 180)
	{ // adû�м�⵽�ϰ�����������ֹ
		if ((io1 == 1) && (io2 == 1))
		{ // ���ϰ�
			robot_state = 1;
		}
		else if ((io1 == 0) && (io2 == 1))
		{
			// ����ϰ�
			robot_state = 2;
		}
		else if ((io1 == 1) && (io2 == 0))
		{
			// �Ҳ��ϰ�
			robot_state = 3;
		}
		else
		{
			// ����
			robot_state = 4;
		}
	}
	else if (ad < 500)
	{ // ad��⵽�ϰ������������Ƚϴ�Ķ���
		if ((io1 == 1) && (io2 == 1))
		{ // ���ϰ�
			robot_state = 5;
		}
		else if ((io1 == 0) && (io2 == 1))
		{
			// ����ϰ�
			robot_state = 2;
		}
		else if ((io1 == 1) && (io2 == 0))
		{
			// �Ҳ��ϰ�
			robot_state = 3;
		}
		else
		{
			// ����
			robot_state = 4;
		}
	}
	else
	{ // io��⵽�ϰ������������Ƚ�С�Ķ���
		if ((io1 == 1) && (io2 == 1))
		{ // ���ϰ�
			robot_state = 6;
		}
		else if ((io1 == 0) && (io2 == 1))
		{
			// ����ϰ�
			robot_state = 2;
		}
		else if ((io1 == 1) && (io2 == 0))
		{
			// �Ҳ��ϰ�
			robot_state = 3;
		}
		else
		{
			// ����
			robot_state = 4;
		}
	}
	if (robot_state != 1)
	{
		cyc++;
	}
	if (cyc > 20)
	{
		cyc = 0;
		forward_flag = 1;
	}
}
bool IsStateChanged()
{
	robot_old_state = robot_state;
	GetState();
	if (robot_old_state == robot_state)
	{
		return 0;
	}
	else
	{
		robot_old_state = robot_state;
		return 1;
	}
}

void GoForward()
{
	static u8 time = 0;
	time++;
	if (time > 5)
	{
		UP_CDS_SetAngle(19, 512, 512);
		UP_CDS_SetAngle(20, 562, 512);

		UP_delay_ms(500);
		BackSquat();
		ShakeHead(2);
		time = 0;
		forward_flag = 0;
		Standup();
		return;
	}
	UP_CDS_SetAngle(1, 435, 300);
	UP_CDS_SetAngle(2, 619, 300);
	UP_CDS_SetAngle(3, 324, 300);

	UP_CDS_SetAngle(4, 475, 300);
	UP_CDS_SetAngle(5, 517, 300);
	UP_CDS_SetAngle(6, 222, 300);

	UP_CDS_SetAngle(7, 695, 300);
	UP_CDS_SetAngle(8, 612, 300);
	UP_CDS_SetAngle(9, 358, 300);

	UP_CDS_SetAngle(10, 780, 300);
	UP_CDS_SetAngle(11, 520, 300);
	UP_CDS_SetAngle(12, 230, 300);

	UP_CDS_SetAngle(13, 420, 300);
	UP_CDS_SetAngle(14, 657, 300);
	UP_CDS_SetAngle(15, 303, 300);

	UP_CDS_SetAngle(16, 430, 300);
	UP_CDS_SetAngle(17, 532, 300);
	UP_CDS_SetAngle(18, 241, 300);

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(3, 0);
	UP_delay_ms(450);

	UP_CDS_SetAngle(5, 657, 512);
	UP_CDS_SetAngle(6, 312, 512);

	UP_CDS_SetAngle(11, 640, 512);
	UP_CDS_SetAngle(12, 320, 512);

	UP_CDS_SetAngle(17, 627, 512);
	UP_CDS_SetAngle(18, 341, 512);

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(4, 0);
	UP_delay_ms(390);

	UP_CDS_SetAngle(1, 315, 300);
	UP_CDS_SetAngle(2, 499, 300);
	UP_CDS_SetAngle(3, 234, 300);

	UP_CDS_SetAngle(4, 615, 300);

	UP_CDS_SetAngle(7, 575, 300);
	UP_CDS_SetAngle(8, 517, 300);
	UP_CDS_SetAngle(9, 220, 300);

	UP_CDS_SetAngle(10, 660, 300);

	UP_CDS_SetAngle(13, 560, 300);
	UP_CDS_SetAngle(14, 547, 300);
	UP_CDS_SetAngle(15, 213, 300);

	UP_CDS_SetAngle(16, 310, 300);

	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(5, 0);

	UP_delay_ms(450);
	UP_CDS_SetAngle(2, 619, 512);
	UP_CDS_SetAngle(3, 324, 512);

	UP_CDS_SetAngle(8, 612, 512);
	UP_CDS_SetAngle(9, 358, 512);

	UP_CDS_SetAngle(14, 657, 512);
	UP_CDS_SetAngle(15, 303, 512);

	UP_delay_ms(390);
}

void TurnLeft(int delay, int speed1, int speed2)
{
	UP_CDS_SetAngle(1, 480, speed1);
	UP_CDS_SetAngle(2, 619, 100);
	UP_CDS_SetAngle(3, 334, 100);

	UP_CDS_SetAngle(4, 437, speed1);
	UP_CDS_SetAngle(5, 538, speed1);
	UP_CDS_SetAngle(6, 365, speed2);

	UP_CDS_SetAngle(7, 712, speed1);
	UP_CDS_SetAngle(8, 635, 100);
	UP_CDS_SetAngle(9, 330, 100);

	UP_CDS_SetAngle(10, 574, speed1);
	UP_CDS_SetAngle(11, 551, speed1);
	UP_CDS_SetAngle(12, 395, speed2);

	UP_CDS_SetAngle(13, 590, speed1);
	UP_CDS_SetAngle(14, 610, 100);
	UP_CDS_SetAngle(15, 278, 100);

	UP_CDS_SetAngle(16, 311, speed1);
	UP_CDS_SetAngle(17, 489, speed1);
	UP_CDS_SetAngle(18, 392, speed2);

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);

	UP_delay_ms(delay);

	UP_CDS_SetAngle(5, 638, speed1);
	UP_CDS_SetAngle(6, 290, speed2);

	UP_CDS_SetAngle(11, 611, speed1);
	UP_CDS_SetAngle(12, 320, speed2);

	UP_CDS_SetAngle(17, 589, speed1);
	UP_CDS_SetAngle(18, 317, speed2);

	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_delay_ms(delay + 50);

	UP_CDS_SetAngle(1, 280, speed1);
	UP_CDS_SetAngle(2, 519, speed1);
	UP_CDS_SetAngle(3, 409, speed2);

	UP_CDS_SetAngle(4, 637, speed1);

	UP_CDS_SetAngle(7, 512, speed1);
	UP_CDS_SetAngle(8, 535, speed1);
	UP_CDS_SetAngle(9, 405, speed2);

	UP_CDS_SetAngle(10, 774, speed1);

	UP_CDS_SetAngle(13, 390, speed1);
	UP_CDS_SetAngle(14, 510, speed1);
	UP_CDS_SetAngle(15, 353, speed2);

	UP_CDS_SetAngle(16, 511, speed1);

	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);

	UP_delay_ms(delay);

	UP_CDS_SetAngle(2, 619, speed1);
	UP_CDS_SetAngle(3, 334, speed2);

	UP_CDS_SetAngle(8, 635, speed1);
	UP_CDS_SetAngle(9, 330, speed2);

	UP_CDS_SetAngle(14, 610, speed1);
	UP_CDS_SetAngle(15, 278, speed2);
	//

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);

	UP_delay_ms(delay + 50);
}
void TurnRight(int delay, int speed1, int speed2)
{
	UP_CDS_SetAngle(1, 280, speed1);
	UP_CDS_SetAngle(2, 619, 100);
	UP_CDS_SetAngle(3, 334, 100);

	UP_CDS_SetAngle(4, 637, speed1);
	UP_CDS_SetAngle(5, 538, speed1);
	UP_CDS_SetAngle(6, 365, speed2);

	UP_CDS_SetAngle(7, 512, speed1);
	UP_CDS_SetAngle(8, 635, 100);
	UP_CDS_SetAngle(9, 330, 100);

	UP_CDS_SetAngle(10, 774, speed1);
	UP_CDS_SetAngle(11, 551, speed1);
	UP_CDS_SetAngle(12, 395, speed2);

	UP_CDS_SetAngle(13, 394, speed1);
	UP_CDS_SetAngle(14, 610, 100);
	UP_CDS_SetAngle(15, 278, 100);

	UP_CDS_SetAngle(16, 511, speed1);
	UP_CDS_SetAngle(17, 489, speed1);
	UP_CDS_SetAngle(18, 392, speed2);
	//

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);

	UP_delay_ms(delay);

	UP_CDS_SetAngle(5, 638, speed1);
	UP_CDS_SetAngle(6, 290, speed2);

	UP_CDS_SetAngle(11, 611, speed1);
	UP_CDS_SetAngle(12, 320, speed2);

	UP_CDS_SetAngle(17, 589, speed1);
	UP_CDS_SetAngle(18, 317, speed2);

	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);

	UP_delay_ms(delay + 50);

	UP_CDS_SetAngle(1, 480, speed1);
	UP_CDS_SetAngle(2, 519, speed1);
	UP_CDS_SetAngle(3, 409, speed2);

	UP_CDS_SetAngle(4, 437, speed1);

	UP_CDS_SetAngle(7, 712, speed1);
	UP_CDS_SetAngle(8, 535, speed1);
	UP_CDS_SetAngle(9, 405, speed2);

	UP_CDS_SetAngle(10, 574, speed1);

	UP_CDS_SetAngle(13, 594, speed1);
	UP_CDS_SetAngle(14, 510, speed1);
	UP_CDS_SetAngle(15, 353, speed2);

	UP_CDS_SetAngle(16, 311, speed1);
	//

	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);

	UP_delay_ms(delay);

	UP_CDS_SetAngle(2, 619, speed1);
	UP_CDS_SetAngle(3, 334, speed2);

	UP_CDS_SetAngle(8, 635, speed1);
	UP_CDS_SetAngle(9, 330, speed2);

	UP_CDS_SetAngle(14, 610, speed1);
	UP_CDS_SetAngle(15, 278, speed2);
	//

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);

	UP_delay_ms(delay + 50);
}
void BackForward()
{
	UP_CDS_SetAngle(1, 278, 364);
	UP_CDS_SetAngle(2, 510, 100);
	UP_CDS_SetAngle(3, 229, 100);

	UP_CDS_SetAngle(4, 615, 364);
	UP_CDS_SetAngle(5, 437, 364);
	UP_CDS_SetAngle(6, 295, 328);

	UP_CDS_SetAngle(7, 512, 364);
	UP_CDS_SetAngle(8, 545, 100);
	UP_CDS_SetAngle(9, 253, 100);

	UP_CDS_SetAngle(10, 580, 364);
	UP_CDS_SetAngle(11, 431, 364);
	UP_CDS_SetAngle(12, 327, 328);

	UP_CDS_SetAngle(13, 560, 364);
	UP_CDS_SetAngle(14, 556, 100);
	UP_CDS_SetAngle(15, 214, 100);

	UP_CDS_SetAngle(16, 305, 364);
	UP_CDS_SetAngle(17, 443, 364);
	UP_CDS_SetAngle(18, 349, 328);
	//

	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(5, 0);

	UP_delay_ms(260);

	UP_CDS_SetAngle(5, 537, 364);
	UP_CDS_SetAngle(6, 205, 328);

	UP_CDS_SetAngle(11, 531, 364);
	UP_CDS_SetAngle(12, 237, 328);

	UP_CDS_SetAngle(17, 543, 364);
	UP_CDS_SetAngle(18, 259, 328);

	//
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(5, 1);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(4, 0);

	UP_delay_ms(300);

	UP_CDS_SetAngle(1, 478, 364);
	UP_CDS_SetAngle(2, 410, 364);
	UP_CDS_SetAngle(3, 319, 328);

	UP_CDS_SetAngle(4, 475, 364);

	UP_CDS_SetAngle(7, 712, 364);
	UP_CDS_SetAngle(8, 445, 364);
	UP_CDS_SetAngle(9, 343, 328);

	UP_CDS_SetAngle(10, 780, 364);

	UP_CDS_SetAngle(13, 420, 364);
	UP_CDS_SetAngle(14, 456, 364);
	UP_CDS_SetAngle(15, 304, 328);

	UP_CDS_SetAngle(16, 505, 364);
	//

	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(3, 0);

	UP_delay_ms(260);

	UP_CDS_SetAngle(2, 510, 364);
	UP_CDS_SetAngle(3, 229, 328);

	UP_CDS_SetAngle(8, 545, 364);
	UP_CDS_SetAngle(9, 253, 328);

	UP_CDS_SetAngle(14, 556, 364);
	UP_CDS_SetAngle(15, 214, 328);
	//

	UP_delay_ms(300);
}
void Squat()
{
	UP_CDS_SetAngle(1, 472, 512);
	UP_CDS_SetAngle(2, 430, 512);
	UP_CDS_SetAngle(3, 119, 512);
	UP_CDS_SetAngle(4, 530, 512);
	UP_CDS_SetAngle(5, 488, 512);
	UP_CDS_SetAngle(6, 140, 512);
	UP_CDS_SetAngle(7, 593, 512);
	UP_CDS_SetAngle(8, 446, 512);
	UP_CDS_SetAngle(9, 185, 512);
	UP_CDS_SetAngle(10, 627, 512);
	UP_CDS_SetAngle(11, 414, 512);
	UP_CDS_SetAngle(12, 122, 512);
	UP_CDS_SetAngle(13, 490, 512);
	UP_CDS_SetAngle(14, 426, 512);
	UP_CDS_SetAngle(15, 95, 512);
	UP_CDS_SetAngle(16, 429, 512);
	UP_CDS_SetAngle(17, 429, 512);
	UP_CDS_SetAngle(18, 131, 512);
	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 1);
	if (IsStateChanged())
	{
		UP_delay_ms(400);
		return;
	}
	UP_delay_ms(1000);
}
void Standup()
{
	UP_CDS_SetAngle(1, 472, 512);
	UP_CDS_SetAngle(2, 639, 512);
	UP_CDS_SetAngle(3, 346, 512);
	UP_CDS_SetAngle(4, 530, 512);
	UP_CDS_SetAngle(5, 640, 512);
	UP_CDS_SetAngle(6, 312, 512);
	UP_CDS_SetAngle(7, 593, 512);
	UP_CDS_SetAngle(8, 601, 512);
	UP_CDS_SetAngle(9, 335, 512);
	UP_CDS_SetAngle(10, 627, 512);
	UP_CDS_SetAngle(11, 695, 512);
	UP_CDS_SetAngle(12, 401, 512);
	UP_CDS_SetAngle(13, 490, 512);
	UP_CDS_SetAngle(14, 703, 512);
	UP_CDS_SetAngle(15, 330, 512);
	UP_CDS_SetAngle(16, 429, 512);
	UP_CDS_SetAngle(17, 654, 512);
	UP_CDS_SetAngle(18, 358, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	if (IsStateChanged())
	{
		UP_delay_ms(400);
		return;
	}
	UP_delay_ms(1000);
}
void BackSquat()
{
	UP_CDS_SetAngle(1, 390, 512);
	UP_CDS_SetAngle(2, 539, 512);
	UP_CDS_SetAngle(3, 320, 512);
	UP_CDS_SetAngle(4, 450, 512);
	UP_CDS_SetAngle(5, 627, 512);
	UP_CDS_SetAngle(6, 278, 512);
	UP_CDS_SetAngle(7, 592, 512);
	UP_CDS_SetAngle(8, 668, 512);
	UP_CDS_SetAngle(9, 402, 512);
	UP_CDS_SetAngle(10, 715, 512);
	UP_CDS_SetAngle(11, 551, 512);
	UP_CDS_SetAngle(12, 324, 512);
	UP_CDS_SetAngle(13, 585, 512);
	UP_CDS_SetAngle(14, 602, 512);
	UP_CDS_SetAngle(15, 282, 512);
	UP_CDS_SetAngle(16, 429, 512);
	UP_CDS_SetAngle(17, 678, 512);
	UP_CDS_SetAngle(18, 356, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 0);
	if (IsStateChanged())
	{
		UP_delay_ms(400);
		return;
	}
	UP_delay_ms(1000);
}
void WaveHead(u8 cycle)
{
	u8 cyc = 0;
	UP_CDS_SetAngle(19, 512, 512);
	UP_CDS_SetAngle(20, 512, 512);
	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	if (IsStateChanged())
	{
		UP_delay_ms(100);
		return;
	}
	UP_delay_ms(300);

	for (cyc = 0; cyc < cycle; cyc++)
	{
		UP_CDS_SetAngle(19, 462, 512);
		UP_CDS_SetAngle(20, 562, 512);
		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 1);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 1);
		UP_delay_ms(200);

		UP_CDS_SetAngle(19, 512, 512);
		UP_CDS_SetAngle(20, 512, 512);
		//
		UP_IOout_SetIO(0, 1);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 1);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 0);
		UP_delay_ms(200);

		UP_CDS_SetAngle(19, 562, 512);
		UP_CDS_SetAngle(20, 562, 512);
		//

		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 1);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 1);
		UP_delay_ms(200);

		UP_CDS_SetAngle(19, 512, 512);
		UP_CDS_SetAngle(20, 512, 512);
		//
		UP_IOout_SetIO(0, 1);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 1);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 0);

		UP_delay_ms(200);
		if (IsStateChanged())
		{
			return;
		}
	}
}
void ShakeHead(u8 cycle)
{
	u8 cyc = 0;
	UP_CDS_SetAngle(19, 512, 512);
	UP_CDS_SetAngle(20, 580, 512);
	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	if (IsStateChanged())
	{
		return;
	}
	UP_delay_ms(400);
	for (cyc = 0; cyc < cycle; cyc++)
	{
		UP_CDS_SetAngle(19, 432, 200);
		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 0);

		UP_delay_ms(1000);
		if (IsStateChanged())
		{
			break;
		}
		UP_CDS_SetAngle(19, 592, 200);
		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 0);

		UP_delay_ms(1000);
		if (IsStateChanged())
		{
			break;
		}
	}
	UP_CDS_SetAngle(19, 512, 200);
	UP_CDS_SetAngle(20, 512, 512);
	//
}
void Nod(u8 cycle)
{
	u8 cyc = 0;
	UP_CDS_SetAngle(19, 512, 512);
	UP_CDS_SetAngle(20, 512, 512);
	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	if (IsStateChanged())
	{
		return;
	}
	UP_delay_ms(300);

	for (cyc = 0; cyc < cycle; cyc++)
	{
		UP_CDS_SetAngle(19, 462, 512);
		UP_CDS_SetAngle(20, 562, 512);
		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 0);

		UP_delay_ms(300);

		UP_CDS_SetAngle(19, 512, 512);
		UP_CDS_SetAngle(20, 462, 512);
		//
		UP_IOout_SetIO(0, 1);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 1);
		UP_IOout_SetIO(3, 1);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 1);

		UP_delay_ms(300);

		UP_CDS_SetAngle(19, 562, 512);
		UP_CDS_SetAngle(20, 562, 512);
		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 0);

		UP_delay_ms(300);

		UP_CDS_SetAngle(19, 512, 512);
		UP_CDS_SetAngle(20, 462, 512);
		//
		UP_IOout_SetIO(0, 1);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 1);
		UP_IOout_SetIO(3, 1);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 1);
		UP_delay_ms(300);
		if (IsStateChanged())
		{
			break;
		}
	}
	UP_CDS_SetAngle(20, 512, 512);
	//
	UP_delay_ms(300);
}
void Dance()
{
	UP_CDS_SetAngle(1, 441, 512);
	UP_CDS_SetAngle(2, 647, 512);
	UP_CDS_SetAngle(3, 358, 512);

	UP_CDS_SetAngle(4, 553, 512);
	UP_CDS_SetAngle(5, 447, 512);
	UP_CDS_SetAngle(6, 651, 512);

	UP_CDS_SetAngle(7, 574, 512);
	UP_CDS_SetAngle(8, 666, 512);
	UP_CDS_SetAngle(9, 327, 512);

	UP_CDS_SetAngle(10, 616, 512);
	UP_CDS_SetAngle(11, 435, 512);
	UP_CDS_SetAngle(12, 642, 512);

	UP_CDS_SetAngle(13, 501, 512);
	UP_CDS_SetAngle(14, 658, 512);
	UP_CDS_SetAngle(15, 289, 512);

	UP_CDS_SetAngle(16, 488, 512);
	UP_CDS_SetAngle(17, 463, 512);
	UP_CDS_SetAngle(18, 637, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(500);
	// 1,3,5���£�2��4��6̧��
	UP_CDS_SetAngle(2, 493, 512);
	UP_CDS_SetAngle(3, 224, 512);

	UP_CDS_SetAngle(8, 531, 512);
	UP_CDS_SetAngle(9, 209, 512);

	UP_CDS_SetAngle(14, 550, 512);
	UP_CDS_SetAngle(15, 176, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(300);
	// 1,3,5�ŵأ�2��4��6̧��
	UP_CDS_SetAngle(2, 647, 512);
	UP_CDS_SetAngle(3, 358, 512);

	UP_CDS_SetAngle(8, 666, 512);
	UP_CDS_SetAngle(9, 327, 512);

	UP_CDS_SetAngle(14, 658, 512);
	UP_CDS_SetAngle(15, 289, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(350);
	// ����
	UP_CDS_SetAngle(3, 303, 512);

	UP_CDS_SetAngle(5, 656, 512);
	UP_CDS_SetAngle(6, 278, 512);

	UP_CDS_SetAngle(9, 349, 512);

	UP_CDS_SetAngle(11, 647, 512);
	UP_CDS_SetAngle(12, 295, 512);

	UP_CDS_SetAngle(15, 269, 512);

	UP_CDS_SetAngle(17, 653, 512);
	UP_CDS_SetAngle(18, 333, 512);
	//
	if (IsStateChanged())
	{
		UP_delay_ms(400);
		return;
	}
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(600);
	// 1,3,5̧��2��4��6�ŵ�
	UP_CDS_SetAngle(2, 435, 512);
	UP_CDS_SetAngle(3, 647, 512);

	UP_CDS_SetAngle(8, 461, 512);
	UP_CDS_SetAngle(9, 667, 512);

	UP_CDS_SetAngle(14, 465, 512);
	UP_CDS_SetAngle(15, 586, 512);

	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(700);
	// 1,3,5̧��2��4��6����
	UP_CDS_SetAngle(5, 525, 512);
	UP_CDS_SetAngle(6, 194, 512);

	UP_CDS_SetAngle(11, 519, 512);
	UP_CDS_SetAngle(12, 229, 512);

	UP_CDS_SetAngle(17, 509, 512);
	UP_CDS_SetAngle(18, 197, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(350);
	// 1,3,5̧��2��4��6�ŵ�
	UP_CDS_SetAngle(5, 654, 512);
	UP_CDS_SetAngle(6, 296, 512);

	UP_CDS_SetAngle(11, 647, 512);
	UP_CDS_SetAngle(12, 345, 512);

	UP_CDS_SetAngle(17, 651, 512);
	UP_CDS_SetAngle(18, 330, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 1);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(350);
	// ����
	UP_CDS_SetAngle(2, 648, 512);
	UP_CDS_SetAngle(3, 303, 512);

	UP_CDS_SetAngle(6, 278, 512);

	UP_CDS_SetAngle(8, 667, 512);
	UP_CDS_SetAngle(9, 349, 512);

	UP_CDS_SetAngle(12, 295, 512);

	UP_CDS_SetAngle(14, 640, 512);
	UP_CDS_SetAngle(15, 269, 512);

	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 1);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	if (IsStateChanged())
	{
		UP_delay_ms(400);
		return;
	}
	UP_delay_ms(700);
}
void Play()
{
	u8 cyc = 0;
	UP_CDS_SetAngle(1, 345, 512);
	UP_CDS_SetAngle(2, 648, 512);
	UP_CDS_SetAngle(3, 358, 512);

	UP_CDS_SetAngle(4, 434, 512);
	UP_CDS_SetAngle(5, 707, 512);
	UP_CDS_SetAngle(6, 358, 512);

	UP_CDS_SetAngle(7, 574, 512);
	UP_CDS_SetAngle(8, 672, 512);
	UP_CDS_SetAngle(9, 421, 512);

	UP_CDS_SetAngle(10, 750, 512);
	UP_CDS_SetAngle(11, 647, 512);
	UP_CDS_SetAngle(12, 354, 512);

	UP_CDS_SetAngle(13, 620, 512);
	UP_CDS_SetAngle(14, 664, 512);
	UP_CDS_SetAngle(15, 295, 512);

	UP_CDS_SetAngle(16, 489, 512);
	UP_CDS_SetAngle(17, 646, 512);
	UP_CDS_SetAngle(18, 366, 512);
	//

	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	UP_delay_ms(700);
	// �������ŵأ�ǰ����̧��
	UP_CDS_SetAngle(2, 448, 512);
	UP_CDS_SetAngle(3, 664, 512);

	UP_CDS_SetAngle(6, 375, 512);

	UP_CDS_SetAngle(7, 598, 512);
	UP_CDS_SetAngle(8, 581, 512);
	UP_CDS_SetAngle(9, 274, 512);

	UP_CDS_SetAngle(11, 480, 512);
	UP_CDS_SetAngle(12, 694, 512);

	UP_CDS_SetAngle(14, 690, 512);
	UP_CDS_SetAngle(15, 354, 512);

	UP_CDS_SetAngle(16, 429, 512);
	UP_CDS_SetAngle(17, 550, 512);
	UP_CDS_SetAngle(18, 244, 512);
	//
	UP_IOout_SetIO(0, 1);
	UP_IOout_SetIO(1, 1);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 0);
	UP_IOout_SetIO(5, 0);
	UP_delay_ms(400);

	for (cyc = 0; cyc < 4; cyc++)
	{
		// ǰ�������£�ǰ����̧��
		UP_CDS_SetAngle(2, 401, 800);
		UP_CDS_SetAngle(3, 784, 800);

		UP_CDS_SetAngle(11, 613, 800);
		UP_CDS_SetAngle(12, 531, 800);

		//
		UP_IOout_SetIO(0, 0);
		UP_IOout_SetIO(1, 0);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 1);
		UP_IOout_SetIO(5, 1);
		UP_delay_ms(280);
		// ǰ�������£�ǰ����̧��
		UP_CDS_SetAngle(2, 611, 800);
		UP_CDS_SetAngle(3, 556, 800);

		UP_CDS_SetAngle(11, 409, 800);
		UP_CDS_SetAngle(12, 769, 800);
		//
		UP_delay_ms(280);
		UP_IOout_SetIO(0, 1);
		UP_IOout_SetIO(1, 1);
		UP_IOout_SetIO(2, 0);
		UP_IOout_SetIO(3, 0);
		UP_IOout_SetIO(4, 0);
		UP_IOout_SetIO(5, 0);
		if (IsStateChanged())
		{
			break;
		}
	}
	// �������ŵأ�ǰ����ǰ��
	UP_CDS_SetAngle(2, 648, 512);
	UP_CDS_SetAngle(3, 358, 512);

	UP_CDS_SetAngle(8, 672, 512);
	UP_CDS_SetAngle(9, 421, 512);

	UP_CDS_SetAngle(11, 647, 512);
	UP_CDS_SetAngle(12, 354, 512);

	UP_CDS_SetAngle(17, 646, 512);
	UP_CDS_SetAngle(18, 366, 512);
	//
	UP_IOout_SetIO(0, 0);
	UP_IOout_SetIO(1, 0);
	UP_IOout_SetIO(2, 0);
	UP_IOout_SetIO(3, 0);
	UP_IOout_SetIO(4, 1);
	UP_IOout_SetIO(5, 1);
	if (IsStateChanged())
	{
		UP_delay_ms(200);
		return;
	}
	UP_delay_ms(400);
}
