#ifndef _KCG_IMPORTED_FUNCTIONS_H_
#define _KCG_IMPORTED_FUNCTIONS_H_

#include "kcg_types.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <time.h>


int currentTemperature = 36;
int minTemperature = 35;
int maxTemperature = 44;
int temperature_sleep_time = 10; // s
time_t  temperature_tic;

int newTemperature() {
  time_t  tac;
  time(&tac);
  int current_sleep_time = (int) (tac - temperature_tic);
  if (current_sleep_time < temperature_sleep_time) {
    return currentTemperature;
  }
  time(&temperature_tic);
  
  int delta = (rand() % 3) - 1;  // [-1, 1]
  currentTemperature += delta;
  
  if (currentTemperature > maxTemperature) {
    currentTemperature = maxTemperature;
  } else if (currentTemperature < minTemperature) {
    currentTemperature = minTemperature;
  }
  
  printf("temperature = %d\n", currentTemperature);
  return currentTemperature;
}

kcg_int TemperatureValueOp(void){
    return newTemperature();
}

#endif /* _KCG_IMPORTED_FUNCTIONS_H_ */
