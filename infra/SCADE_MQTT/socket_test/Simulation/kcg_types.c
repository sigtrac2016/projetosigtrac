/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/config.txt
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_array_char_150
kcg_bool kcg_comp_array_char_150(array_char_150 *kcg_c1, array_char_150 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 150; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_char_150 */

#ifdef kcg_use_array_char_50
kcg_bool kcg_comp_array_char_50(array_char_50 *kcg_c1, array_char_50 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 50; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_char_50 */

#ifdef kcg_use_array_char_16
kcg_bool kcg_comp_array_char_16(array_char_16 *kcg_c1, array_char_16 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 16; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_char_16 */

/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_types.c
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

