#ifndef _KCG_IMPORTED_FUNCTIONS_H_
#define _KCG_IMPORTED_FUNCTIONS_H_

#include "kcg_types.h"

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <time.h>


int currentHeartRate = 70;
int minHeartRate = 0;
int maxHeartRate = 200;
int heart_rate_sleep_time = 1; // s
time_t  heart_rate_tic;

int newHeartRate(){
  time_t  tac;
  time(&tac);
  int current_sleep_time = (int) (tac - heart_rate_tic);
  if (current_sleep_time < heart_rate_sleep_time) {
    return currentHeartRate;
  }
  time(&heart_rate_tic);
  
  int delta = (rand() % 5) - 2; // [-2, 2]
  currentHeartRate += delta;
  
  if (currentHeartRate > maxHeartRate) {
    currentHeartRate = maxHeartRate;
  } else if (currentHeartRate < minHeartRate) {
    currentHeartRate = minHeartRate;
  }
  
  printf("heart rate = %d\n", currentHeartRate);
  return currentHeartRate;
}

kcg_int HeartRateValueOp(void){
    return newHeartRate();
}

#endif /* _KCG_IMPORTED_FUNCTIONS_H_ */
