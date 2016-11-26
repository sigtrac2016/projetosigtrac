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

int newTemperature(){
  int i;
  for (i = 0; i < 1000; i++);
  
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
