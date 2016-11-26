/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/Bruna/Desktop/sp3/almost/SCADE/tutorial-arduino-display/KCG/config.txt
** Generation date: 2016-11-26T11:08:47
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "DisplayOp.h"

#ifndef KCG_USER_DEFINED_INIT
void DisplayOp_init(outC_DisplayOp *outC)
{
  outC->heart_rate = 0.0;
  outC->oxygen_saturation = 0.0;
  outC->respiratory_rate = 0.0;
  outC->temperature = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void DisplayOp_reset(outC_DisplayOp *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* DisplayOp */
void DisplayOp(outC_DisplayOp *outC)
{
  /* DisplayOp */ kcg_int tmp;
  
  tmp = /* 1 */ TemperatureValueOp();
  outC->temperature = (kcg_real) tmp;
  tmp = /* 1 */ RespiratoryRateValueOp();
  outC->respiratory_rate = (kcg_real) tmp;
  tmp = /* 2 */ OxygenSaturationValueOp();
  outC->oxygen_saturation = (kcg_real) tmp;
  tmp = /* 1 */ HeartRateValueOp();
  outC->heart_rate = (kcg_real) tmp;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** DisplayOp.c
** Generation date: 2016-11-26T11:08:47
*************************************************************$ */

