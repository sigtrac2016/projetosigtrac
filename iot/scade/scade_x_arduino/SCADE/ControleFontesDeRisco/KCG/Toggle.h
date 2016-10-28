/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/KCG/config.txt
** Generation date: 2016-10-27T14:59:00
*************************************************************$ */
#ifndef _Toggle_H_
#define _Toggle_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Toggle::Output1 */ Output1;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Toggle;

/* ===========  node initialization and cycle functions  =========== */
/* Toggle */
extern void Toggle(/* Toggle::Input1 */ kcg_bool Input1, outC_Toggle *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Toggle_reset(outC_Toggle *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Toggle_init(outC_Toggle *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Toggle_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** Toggle.h
** Generation date: 2016-10-27T14:59:00
*************************************************************$ */

