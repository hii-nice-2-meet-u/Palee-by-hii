
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
 *
 *	File	:	Palee.h
 *	Release		:	v1.0.1
 *
 *	Created on	:	Fri 13 Dec 2024
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
	while (digitalRead(Pin_swOK))
		;
}

#define wait_OK(void) wait_swOK(void)
#define wait_OK_unPress(void) wait_swOK_unPress(void)

#define OK(void) \
	wait_swOK(); \
	wait_swOK_unPress();

//* --------------------------------
//` ================================================================ #ffffff
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` LED Ctrl
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//` ================================================================ #ffffff
//* --------------------------------

//$ Function initialize LED
void _init_LED(void)
{
	pinMode(Pin_LED_RED, OUTPUT);
	pinMode(Pin_LED_GREEN, OUTPUT);
}

//* --------------------------------

#define __LED_RED_ON digitalWrite(Pin_LED_RED, HIGH)
#define __LED_RED_OFF digitalWrite(Pin_LED_RED, LOW)

#define __LED_GREEN_ON digitalWrite(Pin_LED_GREEN, HIGH)
#define __LED_GREEN_OFF digitalWrite(Pin_LED_GREEN, LOW)

//* --------------------------------

void blink_RED(int duration = 100)
{
	__LED_RED_ON;
	delay(duration);
	__LED_RED_OFF;
}

void blink_GREEN(int duration = 100)
{
	__LED_GREEN_ON;
	delay(duration);
	__LED_GREEN_OFF;
}

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
		analogWrite(MA_IN1, 0);
		analogWrite(MA_IN2, -Speed);
	}
	else
	{
		analogWrite(MA_IN1, Speed);
		analogWrite(MA_IN2, 0);
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
		analogWrite(MB_IN1, 0);
		analogWrite(MB_IN2, -Speed);
	}
	else
	{
		analogWrite(MB_IN1, Speed);
		analogWrite(MB_IN2, 0);
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
#define x Motor()
#define X Motor()

//* --------------------------------
//` ================================================================ #ffffff
//' ================================================================ #0150fe
//" --------------------------------

void initVariant(void)
{
	pinMode(Pin_swOK, INPUT);
	_init_LED();
	_init_Motor();
}

//" --------------------------------
//' ================================================================ #0150fe
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~