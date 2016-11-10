/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/config.txt
** Generation date: 2016-10-27T19:29:59
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Operator1.h"

#ifndef KCG_USER_DEFINED_INIT
void Operator1_init(outC_Operator1 *outC)
{
  outC->_L13 = 0;
  outC->_L12 = 0;
  outC->_L11 = 0;
  outC->_L9 = kcg_true;
  outC->_L6 = 0;
  outC->_L5 = kcg_true;
  outC->_L3 = kcg_true;
  outC->_L1 = kcg_true;
  outC->_L1_1 = kcg_true;
  outC->_L3_1 = kcg_true;
  outC->_L4_1 = kcg_true;
  outC->Input1_1 = kcg_true;
  outC->Output1_1 = kcg_true;
  outC->init = kcg_true;
  outC->_L2 = kcg_true;
  outC->_L2_1 = kcg_true;
  outC->EmitToCDS = kcg_true;
  outC->SignalToLed = 0;
  outC->ReqLayerActive = kcg_true;
  outC->ReqLayerVisible = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Operator1_reset(outC_Operator1 *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Operator1 */
void Operator1(inC_Operator1 *inC, outC_Operator1 *outC)
{
  /* fby_1_init_1 */ if (outC->init) {
    outC->_L1 = kcg_true;
  }
  else {
    outC->_L1 = outC->_L2;
  }
  outC->_L2 = kcg_false;
  outC->ReqLayerVisible = outC->_L1;
  outC->ReqLayerActive = outC->_L1;
  outC->_L3 = inC->SignalFromButton;
  /* 1_fby_1_init_1 */ if (outC->init) {
    outC->_L4_1 = kcg_false;
  }
  else {
    outC->_L4_1 = outC->_L2_1;
  }
  outC->Input1_1 = outC->_L3;
  outC->_L1_1 = outC->Input1_1;
  outC->_L3_1 = !outC->_L4_1;
  /* 1 */ if (outC->_L1_1) {
    outC->_L2_1 = outC->_L3_1;
  }
  else {
    outC->_L2_1 = outC->_L4_1;
  }
  outC->Output1_1 = outC->_L2_1;
  outC->_L5 = outC->Output1_1;
  outC->_L11 = GREEN;
  outC->_L12 = RED;
  /* 1 */ if (outC->_L5) {
    outC->_L6 = outC->_L11;
  }
  else {
    outC->_L6 = outC->_L12;
  }
  outC->_L9 = kcg_true;
  outC->EmitToCDS = outC->_L9;
  outC->_L13 = /* 1 */ SerialWrite(outC->_L6);
  outC->SignalToLed = outC->_L13;
  outC->init = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Operator1.c
** Generation date: 2016-10-27T19:29:59
*************************************************************$ */

