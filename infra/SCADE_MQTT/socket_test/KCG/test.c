/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/socket_test/KCG/config.txt
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "test.h"

#ifndef KCG_USER_DEFINED_INIT
void test_init(outC_test *outC)
{
  outC->_L4 = kcg_true;
  outC->_L2 = 0;
  outC->Emit = kcg_true;
  outC->Output1 = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void test_reset(outC_test *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* test */
void test(outC_test *outC)
{
  outC->_L2 = /* 2 */ Operator2();
  outC->Output1 = outC->_L2;
  outC->_L4 = kcg_true;
  outC->Emit = outC->_L4;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** test.c
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */

