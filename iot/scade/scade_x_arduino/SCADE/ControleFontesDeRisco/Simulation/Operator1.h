/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/config.txt
** Generation date: 2016-10-27T19:29:59
*************************************************************$ */
#ifndef _Operator1_H_
#define _Operator1_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* Operator1::SignalFromButton */ SignalFromButton;
} inC_Operator1;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Operator1::ReqLayerVisible */ ReqLayerVisible;
  kcg_bool /* Operator1::ReqLayerActive */ ReqLayerActive;
  kcg_int /* Operator1::SignalToLed */ SignalToLed;
  kcg_bool /* Operator1::EmitToCDS */ EmitToCDS;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Toggle::_L2 */ _L2_1;
  kcg_bool /* Operator1::_L2 */ _L2;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* Toggle::Output1 */ Output1_1;
  kcg_bool /* Toggle::Input1 */ Input1_1;
  kcg_bool /* Toggle::_L4 */ _L4_1;
  kcg_bool /* Toggle::_L3 */ _L3_1;
  kcg_bool /* Toggle::_L1 */ _L1_1;
  kcg_bool /* Operator1::_L1 */ _L1;
  kcg_bool /* Operator1::_L3 */ _L3;
  kcg_bool /* Operator1::_L5 */ _L5;
  kcg_int /* Operator1::_L6 */ _L6;
  kcg_bool /* Operator1::_L9 */ _L9;
  kcg_int /* Operator1::_L11 */ _L11;
  kcg_int /* Operator1::_L12 */ _L12;
  kcg_int /* Operator1::_L13 */ _L13;
} outC_Operator1;

/* ===========  node initialization and cycle functions  =========== */
/* Operator1 */
extern void Operator1(inC_Operator1 *inC, outC_Operator1 *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Operator1_reset(outC_Operator1 *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Operator1_init(outC_Operator1 *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Operator1_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** Operator1.h
** Generation date: 2016-10-27T19:29:59
*************************************************************$ */

