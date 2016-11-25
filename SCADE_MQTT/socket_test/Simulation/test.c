/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/config.txt
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "test.h"

#ifndef KCG_USER_DEFINED_INIT
void test_init(outC_test *outC)
{
  kcg_int i14;
  kcg_int i13;
  kcg_int i12;
  kcg_int i11;
  kcg_int i10;
  kcg_int i9;
  kcg_int i8;
  kcg_int i7;
  kcg_int i6;
  kcg_int i5;
  kcg_int i4;
  kcg_int i3;
  kcg_int i2;
  kcg_int i1;
  kcg_int i;
  
  outC->_L82 = kcg_true;
  for (i = 0; i < 16; i++) {
    outC->_L81[i] = ' ';
  }
  for (i1 = 0; i1 < 50; i1++) {
    outC->_L80[i1] = ' ';
  }
  outC->_L78 = 0;
  outC->_L77 = 0;
  outC->_L76 = 0;
  outC->_L74 = 0;
  outC->_L73 = 0;
  outC->_L72 = 0;
  outC->_L71 = 0;
  for (i2 = 0; i2 < 16; i2++) {
    outC->_L69[i2] = ' ';
  }
  for (i3 = 0; i3 < 16; i3++) {
    outC->_L68[i3] = ' ';
  }
  for (i4 = 0; i4 < 16; i4++) {
    outC->_L67[i4] = ' ';
  }
  for (i5 = 0; i5 < 16; i5++) {
    outC->_L66[i5] = ' ';
  }
  for (i6 = 0; i6 < 16; i6++) {
    outC->_L65[i6] = ' ';
  }
  outC->_L64 = 0;
  for (i7 = 0; i7 < 16; i7++) {
    outC->_L63[i7] = ' ';
  }
  for (i8 = 0; i8 < 50; i8++) {
    outC->_L62[i8] = ' ';
  }
  for (i9 = 0; i9 < 50; i9++) {
    outC->_L59[i9] = ' ';
  }
  for (i10 = 0; i10 < 50; i10++) {
    outC->_L58[i10] = ' ';
  }
  for (i11 = 0; i11 < 50; i11++) {
    outC->_L57[i11] = ' ';
  }
  for (i12 = 0; i12 < 50; i12++) {
    outC->_L56[i12] = ' ';
  }
  outC->_L55 = 0;
  outC->_L53 = 0.0;
  outC->_L52 = 0.0;
  outC->_L50 = ' ';
  outC->_L44 = kcg_true;
  outC->_L46 = kcg_true;
  outC->_L47 = kcg_true;
  outC->_L48 = kcg_true;
  outC->_L15 = 0;
  for (i13 = 0; i13 < 150; i13++) {
    outC->_L9[i13] = ' ';
  }
  outC->_L4 = kcg_true;
  for (i14 = 0; i14 < 50; i14++) {
    outC->aqui[i14] = ' ';
  }
  outC->EmitToOcurrenceType = kcg_true;
  outC->SelectedOcurrenceType = 0;
  outC->LEDReportDispatched = 0;
  outC->LEDReportRegisted = 0;
  outC->Emit = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void test_reset(outC_test *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* test */
void test(inC_test *inC, outC_test *outC)
{
  outC->_L4 = kcg_true;
  outC->Emit = outC->_L4;
  outC->_L47 = inC->SignalFromButton;
  outC->_L46 = kcg_true;
  outC->_L48 = kcg_false;
  /* 5 */ if (outC->_L47) {
    outC->_L44 = outC->_L46;
  }
  else {
    outC->_L44 = outC->_L48;
  }
  outC->_L55 = inC->Title;
  kcg_copy_array_char_50(&outC->_L57, (array_char_50 *) &TITLE_THEFT);
  kcg_copy_array_char_50(&outC->_L58, (array_char_50 *) &TITLE_THEFT_ATTEMPT);
  kcg_copy_array_char_50(&outC->_L59, (array_char_50 *) &TITLE_ROBBERY);
  kcg_copy_array_char_50(&outC->_L62, (array_char_50 *) &TITLE_ROBBERY_ATTEMPT);
  kcg_copy_array_char_50(&outC->_L80, (array_char_50 *) &TITLE_DEFAULT);
  switch (outC->_L55) {
    case 1 :
      kcg_copy_array_char_50(&outC->_L56, &outC->_L57);
      break;
    case 2 :
      kcg_copy_array_char_50(&outC->_L56, &outC->_L58);
      break;
    case 3 :
      kcg_copy_array_char_50(&outC->_L56, &outC->_L59);
      break;
    case 4 :
      kcg_copy_array_char_50(&outC->_L56, &outC->_L62);
      break;
    
    default :
      kcg_copy_array_char_50(&outC->_L56, &outC->_L80);
  }
  outC->_L50 = DEPARTMENT;
  kcg_copy_array_char_150(&outC->_L9, &inC->Description);
  outC->_L52 = LATITUDE;
  outC->_L53 = LONGITUDE;
  outC->_L64 = inC->Status;
  kcg_copy_array_char_16(&outC->_L65, (array_char_16 *) &STATUS_NAO_INICIADO);
  kcg_copy_array_char_16(&outC->_L66, (array_char_16 *) &STATUS_INICIADO);
  kcg_copy_array_char_16(&outC->_L67, (array_char_16 *) &STATUS_CANCELADO);
  kcg_copy_array_char_16(&outC->_L69, (array_char_16 *) &STATUS_FINALIZADO);
  kcg_copy_array_char_16(&outC->_L68, (array_char_16 *) &STATUS_REFORCOS);
  kcg_copy_array_char_16(&outC->_L81, (array_char_16 *) &STATUS_DEFAULT);
  switch (outC->_L64) {
    case 1 :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L65);
      break;
    case 2 :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L66);
      break;
    case 3 :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L67);
      break;
    case 4 :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L69);
      break;
    case 5 :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L68);
      break;
    
    default :
      kcg_copy_array_char_16(&outC->_L63, &outC->_L81);
  }
  outC->_L15 = /* 1 */
    PublishMQTT(
      outC->_L44,
      &outC->_L56,
      outC->_L50,
      &outC->_L9,
      outC->_L52,
      outC->_L53,
      &outC->_L63);
  outC->_L73 = RED;
  outC->_L72 = GREEN;
  outC->_L74 = RED;
  switch (outC->_L15) {
    case -1 :
      outC->_L71 = outC->_L73;
      break;
    case 0 :
      outC->_L71 = outC->_L72;
      break;
    
    default :
      outC->_L71 = outC->_L74;
  }
  outC->LEDReportRegisted = outC->_L71;
  outC->_L78 = GREEN;
  outC->_L77 = RED;
  /* 7 */ if (outC->_L47) {
    outC->_L76 = outC->_L78;
  }
  else {
    outC->_L76 = outC->_L77;
  }
  outC->LEDReportDispatched = outC->_L76;
  outC->_L82 = inC->NotifyFromOcurrenceType;
  outC->EmitToOcurrenceType = outC->_L82;
  outC->SelectedOcurrenceType = outC->_L55;
  kcg_copy_array_char_50(&outC->aqui, &outC->_L56);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** test.c
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

