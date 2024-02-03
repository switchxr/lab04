/** @brief Gh control constants, structures, function prototypes
 * @file ghcontrol.h
 */
#ifndef GHCONTROL_H
#define GHCONTROL_H

// Includes
#include "led2472g.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define GHUPDATE 2000
#define SENSORS 3
#define TEMPERATURE 0
#define HUMIDITY 1
#define PRESSURE 2
#define SIMULATE 1
#define USTEMP 50
#define LSTEMP -10
#define USHUMID 100
#define LSHUMID 0
#define USPRESS 1016
#define LSPRESS 975
#define STEMP 25.0
#define SHUMID 55.0


// Function Prototypes

void GhDisplayHeader(const char * sname);

void GhDelay(int milliseconds);

int GhGetRandom(int range);

void GhControllerInit(void);
void GhDisplayControls(int *heater, int *humidifier);
void GhDisplayReadings(time_t rtime, float creadings[SENSORS]);
void GhDisplayTargets(void);
void GhSetControls(int *heater, int *humidifier, float readings[SENSORS]);
void GhSetTargets(void);

float GhGetHumidity(void);
float GhGetPressure(void);
float GhGetTemperature(void);
void GhGetReadings(float readings[SENSORS]);







#endif
