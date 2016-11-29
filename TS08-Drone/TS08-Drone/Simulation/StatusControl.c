/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/config.txt
** Generation date: 2016-10-25T13:10:57
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StatusControl.h"

#ifndef KCG_USER_DEFINED_INIT
void StatusControl_init(outC_StatusControl *outC)
{
  kcg_int i;
  
  outC->_L1_1 = kcg_true;
  outC->init = kcg_true;
  outC->StatusButtonColor = 0;
  for (i = 0; i < 10; i++) {
    outC->ButtonText[i] = ' ';
    outC->StatusButtonText[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void StatusControl_reset(outC_StatusControl *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* StatusControl */
void StatusControl(inC_StatusControl *inC, outC_StatusControl *outC)
{
  /* 1_fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    outC->_L26 = kcg_false;
  }
  else {
    outC->_L26 = outC->_L1_1;
  }
  /* 1 */ if (outC->_L26) {
    kcg_copy_T_String(&outC->StatusButtonText, (T_String *) &ON_TEXT);
    outC->StatusButtonColor = GREEN;
    kcg_copy_T_String(&outC->ButtonText, (T_String *) &TURN_OFF);
  }
  else {
    kcg_copy_T_String(&outC->StatusButtonText, (T_String *) &OFF_TEXT);
    outC->StatusButtonColor = RED;
    kcg_copy_T_String(&outC->ButtonText, (T_String *) &TURN_ON);
  }
  /* 1 */ if (inC->OnButton) {
    outC->_L1_1 = !outC->_L26;
  }
  else {
    outC->_L1_1 = outC->_L26;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** StatusControl.c
** Generation date: 2016-10-25T13:10:57
*************************************************************$ */

