/** @brief Defines the entry point for the console application.
 *  @file lab04.c
 */
#include "ghcontrol.h"

int main (void)
{
	GhControllerInit();
	time_t now;
	float creadings[SENSORS] = {0.0,0.0,0.0};
	float readings[SENSORS];	

	
	while(1)
	{	
		now = time(NULL);
		GhGetReadings(creadings);	
		GhSetControls(&heater, &humidifier, readings[SENSORS]);
		GhDisplayReadings(now, creadings);
		GhDisplayTargets();
		//GhDisplayControls();
		GhDelay(GHUPDATE);
	}
	//fprintf(stdout, "Press ENTER to continue...");
	fgetc(stdin);

	return EXIT_FAILURE;
}


