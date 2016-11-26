#ifndef _KCG_IMPORTED_FUNCTIONS_H_
#define _KCG_IMPORTED_FUNCTIONS_H_

#include "kcg_types.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <time.h>


int currentOxygenSaturation = 98;
int minOxygenSaturation = 80;
int maxOxygenSaturation = 100;
int oxygen_saturation_sleep_time = 4; // s
time_t  oxygen_saturation_tic;

int newOxygenSaturation(){
  time_t  tac;
  time(&tac);
  int current_sleep_time = (int) (tac - oxygen_saturation_tic);
  if (current_sleep_time < oxygen_saturation_sleep_time) {
    return currentOxygenSaturation;
  }
  time(&oxygen_saturation_tic);
  
  int delta = (rand() % 3) - 1; // [-1, 1]
  currentOxygenSaturation += delta;
  
  if (currentOxygenSaturation > maxOxygenSaturation) {
    currentOxygenSaturation = maxOxygenSaturation;
  } else if (currentOxygenSaturation < minOxygenSaturation) {
    currentOxygenSaturation = minOxygenSaturation;
  }
  
  printf("oxygen saturation = %d\n", currentOxygenSaturation);
  return currentOxygenSaturation;
}

kcg_int OxygenSaturationValueOp(void){
    return newOxygenSaturation();
}

#endif /* _KCG_IMPORTED_FUNCTIONS_H_ */
