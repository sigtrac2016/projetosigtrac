/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/KCG/config.txt
** Generation date: 2016-10-27T16:38:08
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Operator1.h"

#ifndef KCG_USER_DEFINED_INIT
void Operator1_init(outC_Operator1 *outC)
{
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
  /* Toggle::Output1 */ kcg_bool Output1_1;
  /* Toggle::Input1 */ kcg_bool Input1_1;
  /* Toggle::_L4 */ kcg_bool _L4_1;
  /* Toggle::_L3 */ kcg_bool _L3_1;
  /* Toggle::_L1 */ kcg_bool _L1_1;
  /* Operator1::_L1 */ kcg_bool _L1;
  /* Operator1::_L3 */ kcg_bool _L3;
  /* Operator1::_L5 */ kcg_bool _L5;
  /* Operator1::_L6 */ kcg_int _L6;
  /* Operator1::_L9 */ kcg_bool _L9;
  /* Operator1::_L11 */ kcg_int _L11;
  /* Operator1::_L12 */ kcg_int _L12;
  /* Operator1::_L13 */ kcg_int _L13;
  
  /* fby_1_init_1 */ if (outC->init) {
    _L1 = kcg_true;
  }
  else {
    _L1 = outC->_L2;
  }
  outC->_L2 = kcg_false;
  outC->ReqLayerVisible = _L1;
  outC->ReqLayerActive = _L1;
  _L3 = inC->SignalFromButton;
  /* 1_fby_1_init_1 */ if (outC->init) {
    _L4_1 = kcg_false;
  }
  else {
    _L4_1 = outC->_L2_1;
  }
  Input1_1 = _L3;
  _L1_1 = Input1_1;
  _L3_1 = !_L4_1;
  /* 1 */ if (_L1_1) {
    outC->_L2_1 = _L3_1;
  }
  else {
    outC->_L2_1 = _L4_1;
  }
  Output1_1 = outC->_L2_1;
  _L5 = Output1_1;
  _L11 = GREEN;
  _L12 = RED;
  /* 1 */ if (_L5) {
    _L6 = _L11;
  }
  else {
    _L6 = _L12;
  }
  _L9 = kcg_true;
  outC->EmitToCDS = _L9;
  _L13 = /* 1 */ SerialWrite(_L6);
  outC->SignalToLed = _L13;
  outC->init = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Operator1.c
** Generation date: 2016-10-27T16:38:08
*************************************************************$ */

