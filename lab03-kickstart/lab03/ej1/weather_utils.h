#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "weather_table.h"

int menor_temp_min(WeatherTable a);

void max_temp_maxima(WeatherTable a);

void max_presi_men(WeatherTable a, int output[YEARS]);

#endif //_WEATHER_UTILS_H