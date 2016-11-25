/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/config.txt
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */
#ifndef _test_H_
#define _test_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"

/* ========================  input structure  ====================== */
typedef struct {
  array_char_150 /* test::Description */ Description;
  kcg_bool /* test::Notification */ Notification;
  kcg_bool /* test::SignalFromButton */ SignalFromButton;
  kcg_int /* test::Title */ Title;
  kcg_real /* test::Latitude */ Latitude;
  kcg_real /* test::Longitude */ Longitude;
  kcg_int /* test::Status */ Status;
  kcg_bool /* test::NotifyFromOcurrenceType */ NotifyFromOcurrenceType;
} inC_test;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* test::Emit */ Emit;
  kcg_int /* test::LEDReportRegisted */ LEDReportRegisted;
  kcg_int /* test::LEDReportDispatched */ LEDReportDispatched;
  kcg_int /* test::SelectedOcurrenceType */ SelectedOcurrenceType;
  kcg_bool /* test::EmitToOcurrenceType */ EmitToOcurrenceType;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  array_char_50 /* test::aqui */ aqui;
  kcg_bool /* test::_L4 */ _L4;
  array_char_150 /* test::_L9 */ _L9;
  kcg_int /* test::_L15 */ _L15;
  kcg_bool /* test::_L48 */ _L48;
  kcg_bool /* test::_L47 */ _L47;
  kcg_bool /* test::_L46 */ _L46;
  kcg_bool /* test::_L44 */ _L44;
  kcg_char /* test::_L50 */ _L50;
  kcg_real /* test::_L52 */ _L52;
  kcg_real /* test::_L53 */ _L53;
  kcg_int /* test::_L55 */ _L55;
  array_char_50 /* test::_L56 */ _L56;
  array_char_50 /* test::_L57 */ _L57;
  array_char_50 /* test::_L58 */ _L58;
  array_char_50 /* test::_L59 */ _L59;
  array_char_50 /* test::_L62 */ _L62;
  array_char_16 /* test::_L63 */ _L63;
  kcg_int /* test::_L64 */ _L64;
  array_char_16 /* test::_L65 */ _L65;
  array_char_16 /* test::_L66 */ _L66;
  array_char_16 /* test::_L67 */ _L67;
  array_char_16 /* test::_L68 */ _L68;
  array_char_16 /* test::_L69 */ _L69;
  kcg_int /* test::_L71 */ _L71;
  kcg_int /* test::_L72 */ _L72;
  kcg_int /* test::_L73 */ _L73;
  kcg_int /* test::_L74 */ _L74;
  kcg_int /* test::_L76 */ _L76;
  kcg_int /* test::_L77 */ _L77;
  kcg_int /* test::_L78 */ _L78;
  array_char_50 /* test::_L80 */ _L80;
  array_char_16 /* test::_L81 */ _L81;
  kcg_bool /* test::_L82 */ _L82;
} outC_test;

/* ===========  node initialization and cycle functions  =========== */
/* test */
extern void test(inC_test *inC, outC_test *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void test_reset(outC_test *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void test_init(outC_test *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _test_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** test.h
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

