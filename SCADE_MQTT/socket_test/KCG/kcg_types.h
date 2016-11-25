/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/socket_test/KCG/config.txt
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#define KCG_MAPW_CPY

#include "./user_macros.h"

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif /* kcg_real */

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* truthtables::TruthTableValues */
typedef enum kcg_tag_TruthTableValues_truthtables {
  T_truthtables,
  F_truthtables,
  X_truthtables
} TruthTableValues_truthtables;
/* lut::LutIndex */
typedef struct kcg_tag_LutIndex_lut { kcg_int k; kcg_real f; } LutIndex_lut;

#ifndef kcg_copy_LutIndex_lut
#define kcg_copy_LutIndex_lut(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (LutIndex_lut)))
#endif /* kcg_copy_LutIndex_lut */

#ifdef kcg_use_LutIndex_lut
#ifndef kcg_comp_LutIndex_lut
extern kcg_bool kcg_comp_LutIndex_lut(
  LutIndex_lut *kcg_c1,
  LutIndex_lut *kcg_c2);
#endif /* kcg_comp_LutIndex_lut */
#endif /* kcg_use_LutIndex_lut */

#endif /* _KCG_TYPES_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_types.h
** Generation date: 2016-11-21T18:54:56
*************************************************************$ */

