/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/config.txt
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Main.h"

#ifndef KCG_USER_DEFINED_INIT
void Main_init(outC_Main *outC)
{
  kcg_int i;
  
  outC->Emit = kcg_true;
  outC->LayerVisible = kcg_true;
  outC->LayerActive = kcg_true;
  outC->_L1_2_2 = kcg_true;
  outC->_L49_1 = kcg_true;
  outC->_L32_1 = kcg_true;
  outC->_L1_1_1 = kcg_true;
  outC->init = kcg_true;
  outC->Longitude = 0.0;
  outC->Latitude = 0.0;
  outC->YawOut = 0.0;
  outC->AltitudeOut = 0.0;
  outC->CompassDir = 0.0;
  outC->DirOutput = 0.0;
  outC->HorSpeedOutput = 0.0;
  outC->VertSpeedOutput = 0.0;
  outC->Str_size = 0;
  outC->StatusButtonColor = 0;
  for (i = 0; i < 10; i++) {
    outC->TkoffText[i] = ' ';
    outC->ButtonText[i] = ' ';
    outC->StatusButtonText[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Main_reset(outC_Main *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Main */
void Main(inC_Main *inC, outC_Main *outC)
{
  /* Main */ kcg_real tmp5;
  /* Main */ kcg_real tmp4;
  /* Main */ kcg_real tmp3;
  /* Main */ kcg_real tmp2;
  /* Main */ kcg_bool tmp1;
  /* Main */ kcg_bool tmp;
  
  outC->Emit = kcg_true;
  outC->LayerVisible = kcg_true;
  /* 1_fby_1_init_3 */ if (outC->init) {
    outC->output_2_2 = kcg_false;
    tmp2 = 0.0;
    tmp5 = 0.0;
    outC->output_1_1 = kcg_false;
    tmp3 = 0.0;
  }
  else {
    outC->output_2_2 = outC->_L1_2_2;
    tmp2 = outC->Longitude;
    tmp5 = outC->Latitude;
    outC->output_1_1 = outC->_L1_1_1;
    tmp3 = outC->AltitudeOut;
  }
  outC->On = !outC->output_2_2;
  /* 1 */ if (outC->On) {
    outC->DirOutput = 0.0;
    outC->HorSpeedOutput = 0.0;
    outC->VertSpeedOutput = 0.0;
  }
  else {
    outC->DirOutput = inC->DirInput;
    outC->HorSpeedOutput = inC->HorSpeedInput;
    outC->VertSpeedOutput = inC->VertSpeedInput;
  }
  outC->YawOut = outC->DirOutput;
  outC->CompassDir = outC->DirOutput;
  outC->LayerActive = outC->LayerVisible;
  outC->Str_size = BTN_TEXT_SIZE;
  outC->_L21_1 = .1427581 * 0.707107;
  outC->_L8_1 = inC->HorSpeedInput > 0.0;
  outC->_L10_1 = inC->DirInput > 0.0;
  /* 3 */ if (outC->_L8_1 & outC->_L10_1) {
    tmp4 = outC->_L21_1;
  }
  else {
    tmp4 = 0.0;
  }
  outC->Longitude = tmp2 + tmp4;
  /* 1 */ if (outC->_L8_1) {
    /* 2 */ if (outC->_L10_1) {
      tmp4 = .1427581;
    }
    else {
      tmp4 = outC->_L21_1;
    }
  }
  else {
    tmp4 = 0.0;
  }
  outC->Latitude = tmp5 + tmp4;
  /* 1 */ if (inC->TkoffButton) {
    outC->_L1_1_1 = !outC->output_1_1;
  }
  else {
    outC->_L1_1_1 = outC->output_1_1;
  }
  /* 3 */ if (outC->output_1_1) {
    /* 1_fby_1_init_5 */ if (outC->init) {
      tmp1 = kcg_true;
    }
    else {
      tmp1 = outC->_L32_1;
    }
    /* 10 */ if (tmp1) {
      tmp2 = 0.5;
    }
    else {
      tmp2 = 0.0;
    }
    kcg_copy_T_String(&outC->TkoffText, (T_String *) &LAND);
  }
  else {
    /* 1_fby_1_init_6 */ if (outC->init) {
      tmp = kcg_true;
    }
    else {
      tmp = outC->_L49_1;
    }
    /* 11 */ if (tmp) {
      tmp2 = - 0.5;
    }
    else {
      tmp2 = 0.0;
    }
    kcg_copy_T_String(&outC->TkoffText, (T_String *) &TAKEOFF);
  }
  outC->init = kcg_false;
  outC->_L26_1 = tmp3 + tmp2;
  outC->_L32_1 = outC->_L26_1 <= 3.0;
  /* 7 */ if (outC->_L32_1) {
    outC->_L34_1 = outC->_L26_1;
  }
  else {
    outC->_L34_1 = 3.0;
  }
  outC->_L49_1 = outC->_L34_1 >= 0.0;
  /* 9 */ if (outC->_L49_1) {
    outC->AltitudeOut = outC->_L34_1;
  }
  else {
    outC->AltitudeOut = 0.0;
  }
  /* 1 */ if (inC->OnButton) {
    outC->_L1_2_2 = outC->On;
  }
  else {
    outC->_L1_2_2 = outC->output_2_2;
  }
  /* 3 */ if (outC->output_2_2) {
    kcg_copy_T_String(&outC->ButtonText, (T_String *) &TURN_OFF);
    outC->StatusButtonColor = GREEN;
    kcg_copy_T_String(&outC->StatusButtonText, (T_String *) &ON_TEXT);
  }
  else {
    kcg_copy_T_String(&outC->ButtonText, (T_String *) &TURN_ON);
    outC->StatusButtonColor = RED;
    kcg_copy_T_String(&outC->StatusButtonText, (T_String *) &OFF_TEXT);
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Main.c
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */

