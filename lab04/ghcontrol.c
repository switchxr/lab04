/** @brief Gh control functions
 *  @file ghcontrol.c
 */
#include "ghcontrol.h"


void GhDisplayHeader(const char * sname)
{
	fprintf(stdout,"%s's CENG153 Greenhouse Controller\n",sname);
}

void GhDelay(int milliseconds)
{
	long wait;
	clock_t now,start;

	wait =  milliseconds*(CLOCKS_PER_SEC/1000);
	start = clock();
	now = start;
	while ( (now-start) < wait)
	{
		now = clock();
	}
}

int GhGetRandom(int range)
{
	return rand() % range;
}

void GhControllerInit(void)
{
	srand((unsigned) time(NULL));
	GhSetTargets();
	GhDisplayHeader("Shayan");
}

void GhDisplayControls(int *heater, int *humidifier)
{
	//fprintf(stderr,"\n%s not implemented.\n",__FUNCTION__);
	fprintf(stdout, "heater:%d\t humidifier:%d\t", *heater, *humidifier);
}

void GhDisplayReadings(time_t rtime, float creadings[SENSORS])
{
	fprintf(stdout,"\nUnit:%LX %s Readings\tT:%5.1fC\tH: %5.1f%\tP: %6.1fmb\n",ShGetSerial(),ctime(&rtime),creadings[TEMPERATURE],creadings[HUMIDITY],creadings[PRESSURE]);
	fprintf(stdout," target data:\tSTEMP: %5.1f\t SHUMID: %5.1f",STEMP,SHUMID);
}

void GhDisplayTargets(void)
{
	
}

void GhSetControls(int *heater, int *humidifier, float creadings[SENSORS])
{
	const int ON=1;
	const int OFF=0;
	if(readings[TEMPERATURE] < STEMP)
	{
		*heater= ON;
	}
	else
	{
		*heater= OFF;
	}
	if(readings[HUMIDITY] < SHUMID)
	{
		*heater =ON;
	}
	else
	{
		*heater =OFF;
	}

}

void GhSetTargets(void)
{

}


float GhGetHumidity(void)
{

	return GhGetRandom(USHUMID - LSHUMID +1) +LSHUMID;
}

float GhGetPressure(void)
{

	return GhGetRandom(USPRESS - LSPRESS +1)+LSPRESS;
}

float GhGetTemperature(void)
{

	return GhGetRandom(USTEMP - LSTEMP+1)+LSTEMP;
}

void GhGetReadings(float readings[SENSORS])
{
	readings[HUMIDITY] = GhGetHumidity();
	readings[PRESSURE] = GhGetPressure();
	readings[TEMPERATURE] = GhGetTemperature();
}


