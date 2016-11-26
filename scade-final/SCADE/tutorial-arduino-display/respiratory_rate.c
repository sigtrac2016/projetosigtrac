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
int respiratory_rate_sleep_time = 3; // s
time_t  respiratory_rate_tic;

int newRespiratoryRate(){
  time_t  tac;
  time(&tac);
  int current_sleep_time = (int) (tac - respiratory_rate_tic);
  if (current_sleep_time < respiratory_rate_sleep_time) {
    return currentRespiratoryRate;
  }
  time(&respiratory_rate_tic);
  
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
