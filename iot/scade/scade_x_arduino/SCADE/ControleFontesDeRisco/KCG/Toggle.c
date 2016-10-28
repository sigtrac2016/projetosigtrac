/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/KCG/config.txt
** Generation date: 2016-10-27T14:59:00
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Toggle.h"

#ifndef KCG_USER_DEFINED_INIT
void Toggle_init(outC_Toggle *outC)
{
  outC->init = kcg_true;
  outC->Output1 = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Toggle_reset(outC_Toggle *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Toggle */
void Toggle(/* Toggle::Input1 */ kcg_bool Input1, outC_Toggle *outC)
{
  /* Toggle::_L4 */ kcg_bool _L4;
  
  /* fby_1_init_1 */ if (outC->init) {
    _L4 = kcg_false;
  }
  else {
    _L4 = outC->Output1;
  }
  /* 1 */ if (Input1) {
    outC->Output1 = !_L4;
  }
  else {
    outC->Output1 = _L4;
  }
  outC->init = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Toggle.c
** Generation date: 2016-10-27T14:59:00
*************************************************************$ */

