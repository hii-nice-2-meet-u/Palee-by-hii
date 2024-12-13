#include <Palee.h>

void setup(void)
{
}

void loop(void)
{
	OK();
	Motor(100, 100, 1000);
	Motor(-100, -100, 1000);
	x;

	OK();

	Motor_MA(150);
	OK();
	x;

	Motor_MB(150);
	OK();
	x;

	Motor(-125, -125);
	OK();
	x;
}

//------------------------------------------------
/* ? StopMotor

- Motor();
- MotorStop();
- x;
- X;

*/
//------------------------------------------------