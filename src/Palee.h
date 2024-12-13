
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File	:	HanumanLT.h
 *
 *	Created on	:	Sat 30 Oct 2024
 *		Author	:	hii-nice-2-meet-u
 *
 */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef __PALEE_H__
#define __PALEE_H__

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "Arduino.h"
#include "PaleeMacro.h"

#include <avr/io.h>
#include <util/delay.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` Switch OK!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` ================================================================ #ffffff
//* --------------------------------

void wait_swOK(void)
{
	while (!digitalRead(Pin_swOK))
		;
}

void wait_swOK_unPress(void)
{
	while (!digitalRead(Pin_swOK))
		;
}

#define wait_OK wait_swOK
#define wait_OK_unPress wait_swOK_unPress

//* --------------------------------
//` ================================================================ #ffffff
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` Motor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` ================================================================ #ffffff
//* --------------------------------

//$ Function initialize Motor
void _init_Motor(void)
{
	pinMode(MA_IN1, OUTPUT); //- Motor [ A ]→[ 1 ]
	pinMode(MA_IN2, OUTPUT); /// Motor [ A ]→[ 2 ]
	pinMode(MB_IN1, OUTPUT); //- Motor [ B ]→[ 1 ]
	pinMode(MB_IN2, OUTPUT); /// Motor [ B ]→[ 2 ]
}

//+ Control Motor A
void Motor_MA(short Speed)
{
	if (Speed > 255)
	{
		Speed = 255;
	}
	if (Speed < 0)
	{
		analogWrite(MA_IN1, -Speed);
		analogWrite(MA_IN2, 0);
	}
	else
	{
		analogWrite(MA_IN1, 0);
		analogWrite(MA_IN2, Speed);
	}
}

//+ Control Motor B
void Motor_MB(short Speed)
{
	if (Speed > 255)
	{
		Speed = 255;
	}
	if (Speed < 0)
	{
		analogWrite(MB_IN1, -Speed);
		analogWrite(MB_IN2, 0);
	}
	else
	{
		analogWrite(MB_IN1, 0);
		analogWrite(MB_IN2, Speed);
	}
}

//$ Control Motor
void Motor(short LSp, short RSp)
// void Motor(short RSp, short LSp)
{
	Motor_MA(LSp);
	Motor_MB(RSp);
}

//+ Control Motor in Time duration
void Motor(short LSp, short RSp, short duration)
// void Motor(short RSp, short LSp)
{
	Motor(LSp, RSp);
	delay(duration);
}

//+ Stop PWM Signal
void Motor(void)
{
	analogWrite(MA_IN1, 0);
	analogWrite(MA_IN2, 0);
	analogWrite(MB_IN1, 0);
	analogWrite(MB_IN2, 0);
}

#define MotorStop(void) Motor(void)

//* --------------------------------
//` ================================================================ #ffffff
//' ================================================================ #0150fe
//" --------------------------------

void initVariant(void)
{
	pinMode(Pin_swOK, INPUT);
	_init_Motor();
}

//" --------------------------------
//' ================================================================ #0150fe
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~