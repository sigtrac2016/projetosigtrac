/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/config.txt
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_T_String
kcg_bool kcg_comp_T_String(T_String *kcg_c1, T_String *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 10; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_T_String */

/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_types.c
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */

