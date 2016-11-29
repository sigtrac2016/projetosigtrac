/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/config.txt
** Generation date: 2016-10-25T13:10:57
*************************************************************$ */
#ifndef _StatusControl_H_
#define _StatusControl_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* StatusControl::OnButton */ OnButton;
} inC_StatusControl;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  T_String /* StatusControl::StatusButtonText */ StatusButtonText;
  kcg_int /* StatusControl::StatusButtonColor */ StatusButtonColor;
  T_String /* StatusControl::ButtonText */ ButtonText;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Switch::_L1 */ _L1_1;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* StatusControl::_L26 */ _L26;
} outC_StatusControl;

/* ===========  node initialization and cycle functions  =========== */
/* StatusControl */
extern void StatusControl(inC_StatusControl *inC, outC_StatusControl *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void StatusControl_reset(outC_StatusControl *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void StatusControl_init(outC_StatusControl *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _StatusControl_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** StatusControl.h
** Generation date: 2016-10-25T13:10:57
*************************************************************$ */

