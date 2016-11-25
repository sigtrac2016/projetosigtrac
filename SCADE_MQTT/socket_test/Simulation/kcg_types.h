/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/config.txt
** Generation date: 2016-11-24T23:28:50
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

typedef kcg_char array_char_150[150];

typedef kcg_char array_char_50[50];

typedef kcg_char array_char_16[16];

#ifndef kcg_copy_array_char_150
#define kcg_copy_array_char_150(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_150)))
#endif /* kcg_copy_array_char_150 */

#ifndef kcg_copy_array_char_50
#define kcg_copy_array_char_50(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_50)))
#endif /* kcg_copy_array_char_50 */

#ifndef kcg_copy_array_char_16
#define kcg_copy_array_char_16(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_16)))
#endif /* kcg_copy_array_char_16 */

#ifdef kcg_use_array_char_150
#ifndef kcg_comp_array_char_150
extern kcg_bool kcg_comp_array_char_150(
  array_char_150 *kcg_c1,
  array_char_150 *kcg_c2);
#endif /* kcg_comp_array_char_150 */
#endif /* kcg_use_array_char_150 */

#ifdef kcg_use_array_char_50
#ifndef kcg_comp_array_char_50
extern kcg_bool kcg_comp_array_char_50(
  array_char_50 *kcg_c1,
  array_char_50 *kcg_c2);
#endif /* kcg_comp_array_char_50 */
#endif /* kcg_use_array_char_50 */

#ifdef kcg_use_array_char_16
#ifndef kcg_comp_array_char_16
extern kcg_bool kcg_comp_array_char_16(
  array_char_16 *kcg_c1,
  array_char_16 *kcg_c2);
#endif /* kcg_comp_array_char_16 */
#endif /* kcg_use_array_char_16 */

#endif /* _KCG_TYPES_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_types.h
** Generation date: 2016-11-24T23:28:50
*************************************************************$ */

