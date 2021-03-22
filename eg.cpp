#include<iostream>
using namespace std;
#include "LogitechSteeringWheelLib.h"

void main() {
	//the parameter determines whether you’ll use X-input or not 
	if (LogiSteeringInitialize(true))
	{
	
		cout << "G29init secuss" << endl;
		//this is  main loop 
		while (LogiUpdate())
		{
			cout<<LogiPlaySpringForce(0, 0, 30, 100);

			DIJOYSTATE2 * wheel = LogiGetState(0);
			
			//输出角度，油门，刹车信息
			cout << "X:" << wheel->lX << "  Y:" << wheel->lY << "  Z:" << wheel->lRz << endl;
			
			/*if (wheel->rgbButtons!= NULL)
			{
				cout << wheel->rgbButtons << endl;
			}
			else
			{
				cout <<"rgbkong"<< endl;
			}*/

			for (int i = 0; i < 10; i++)
			{
				if (LogiButtonIsPressed(0, i))
				{
					cout << i << endl;
				}
			}

			Sleep(100);
		}
	}

}