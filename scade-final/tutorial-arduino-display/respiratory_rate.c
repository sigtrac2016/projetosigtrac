#ifndef _KCG_IMPORTED_FUNCTIONS_H_
#define _KCG_IMPORTED_FUNCTIONS_H_

#include "kcg_types.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <time.h>


int currentRespiratoryRate = 18;
int minRespiratoryRate = 12;
int maxRespiratoryRate = 50;

int newRespiratoryRate(){
  int i;
  for (i = 0; i < 1000; i++);
  
  int delta = (rand() % 5) - 2; // [-2, 2]
  currentRespiratoryRate += delta;
  
  if (currentRespiratoryRate > maxRespiratoryRate) {
    currentRespiratoryRate = maxRespiratoryRate;
  } else if (currentRespiratoryRate < minRespiratoryRate) {
    currentRespiratoryRate = minRespiratoryRate;
  }
  
  printf("respiratory rate = %d\n", currentRespiratoryRate);
  return currentRespiratoryRate;
}

kcg_int RespiratoryRateValueOp(void){
    return newRespiratoryRate();
}

#endif /* _KCG_IMPORTED_FUNCTIONS_H_ */
