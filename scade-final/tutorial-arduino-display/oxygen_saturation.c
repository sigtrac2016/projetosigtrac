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

int newOxygenSaturation(){
  int i;
  for (i = 0; i < 4000; i++);
  
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
