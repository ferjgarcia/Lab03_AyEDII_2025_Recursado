#include "weather_utils.h"
#include <stdio.h>
#include <stdlib.h>

void array_dump(int a[], unsigned int length) {
    int year = FST_YEAR;
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "Mayor temperatura maxima de %d: %i\n", year, a[i]);
        year++;
    }
}

int menor_temp_min(WeatherTable a) {
    int min = a[0][0][0]._min_temp;

    for (unsigned int years = 0; years < YEARS; years++) {
        for (month_t months = 0; months < MONTHS; months++) {
            for (unsigned int days = 0; days < DAYS-1; days++) {
                if (min > a[years][months][days+1]._min_temp){
                    min = a[years][months][days+1]._min_temp;
                }  
            } 
        }   
    }
    
    return min;
}

void max_temp_maxima(WeatherTable a) {
    int output[YEARS];
    int max = a[0][0][0]._max_temp;

    for (unsigned int years = 0; years < YEARS; years++) {
        for (month_t months = 0; months < MONTHS; months++) {
            for (unsigned int days = 0; days < DAYS-1; days++) {
                if (max < a[years][months][days+1]._max_temp){
                    max = a[years][months][days+1]._max_temp;
                }  
            } 
        }   
        output[years] = max;
        max = 0;
    }  

    array_dump(output,YEARS);
}

unsigned int sum_month_rainfall(WeatherTable a, unsigned int years, unsigned int months) {
    int res = 0;

    for (unsigned int days = 0; days < DAYS; days++) {
        res += a[years][months][days]._rainfall;
    }
    
    return res;
}

void max_presi_men(WeatherTable a, int output[YEARS]) {
    month_t myMonth;
    unsigned int maxRainfallMonth = 0;

    for (unsigned int years = 0; years < YEARS; years++) {
        for (month_t months = 0; months < MONTHS; months++) {
            if(maxRainfallMonth < sum_month_rainfall(a, years, months)) {
                maxRainfallMonth = sum_month_rainfall(a, years, months);
                myMonth = months+1;
            }
        }   
        output[years] = myMonth;
        maxRainfallMonth = 0;
    }  
}