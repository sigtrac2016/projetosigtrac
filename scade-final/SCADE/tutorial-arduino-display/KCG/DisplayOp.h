/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/Bruna/Desktop/sp3/almost/SCADE/tutorial-arduino-display/KCG/config.txt
** Generation date: 2016-11-26T11:08:47
*************************************************************$ */
#ifndef _DisplayOp_H_
#define _DisplayOp_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* DisplayOp::temperature */ temperature;
  kcg_real /* DisplayOp::respiratory_rate */ respiratory_rate;
  kcg_real /* DisplayOp::oxygen_saturation */ oxygen_saturation;
  kcg_real /* DisplayOp::heart_rate */ heart_rate;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_DisplayOp;

/* ===========  node initialization and cycle functions  =========== */
/* DisplayOp */
extern void DisplayOp(outC_DisplayOp *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void DisplayOp_reset(outC_DisplayOp *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void DisplayOp_init(outC_DisplayOp *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _DisplayOp_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** DisplayOp.h
** Generation date: 2016-11-26T11:08:47
*************************************************************$ */

