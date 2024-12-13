#include <Palee.h>

void setup(void)
{
}

void loop(void)
{
	OK();
  blink_RED(100); 

	OK();
  blink_GREEN(100); 

	OK();
  __LED_RED_ON;
	
  OK();
  __LED_RED_OFF;
	
  OK();
  __LED_GREEN_ON;
  
  OK();
  __LED_GREEN_OFF;
  
	OK();
  __LED_RED_ON;
  __LED_GREEN_ON;
  
  OK();
  __LED_RED_OFF;
  __LED_GREEN_OFF;
}
