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

int newHeartRate(){
  int i;
  for (i = 0; i < 1000; i++);
  
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
