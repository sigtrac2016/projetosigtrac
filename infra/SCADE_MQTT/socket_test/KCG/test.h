/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/socket_test/KCG/config.txt
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */
#ifndef _test_H_
#define _test_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_int /* test::Output1 */ Output1;
  kcg_bool /* test::Emit */ Emit;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int /* test::_L2 */ _L2;
  kcg_bool /* test::_L4 */ _L4;
} outC_test;

/* ===========  node initialization and cycle functions  =========== */
/* test */
extern void test(outC_test *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void test_reset(outC_test *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void test_init(outC_test *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _test_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** test.h
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */

