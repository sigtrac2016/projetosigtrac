#ifndef TS08_DRONE_TYPES_CONVERSION
#define TS08_DRONE_TYPES_CONVERSION

#include "SmuTypes.h"

/****************************************************************
 ** _1_float 
 ****************************************************************/
extern int _1_float_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check__1_float_string(const char *str, char **endptr);
extern int string_to__1_float(const char *str, void *pValue, char **endptr);
extern int is__1_float_double_conversion_allowed();
extern int _1_float_to_double(const void *pValue, double *nValue);
extern int is__1_float_long_conversion_allowed();
extern int _1_float_to_long(const void *pValue, long *nValue);
extern void compare__1_float(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get__1_float_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set__1_float_default_value(void *pValue);
extern SimTypeUtils _Type__1_float_Utils;

/****************************************************************
 ** kcg_bool 
 ****************************************************************/
extern int kcg_bool_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_kcg_bool_string(const char *str, char **endptr);
extern int string_to_kcg_bool(const char *str, void *pValue, char **endptr);
extern int is_kcg_bool_double_conversion_allowed();
extern int kcg_bool_to_double(const void *pValue, double *nValue);
extern int is_kcg_bool_long_conversion_allowed();
extern int kcg_bool_to_long(const void *pValue, long *nValue);
extern void compare_kcg_bool(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_kcg_bool_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_kcg_bool_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_bool_Utils;

/****************************************************************
 ** kcg_char 
 ****************************************************************/
extern int kcg_char_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_kcg_char_string(const char *str, char **endptr);
extern int string_to_kcg_char(const char *str, void *pValue, char **endptr);
extern int is_kcg_char_double_conversion_allowed();
extern int kcg_char_to_double(const void *pValue, double *nValue);
extern int is_kcg_char_long_conversion_allowed();
extern int kcg_char_to_long(const void *pValue, long *nValue);
extern void compare_kcg_char(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_kcg_char_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_kcg_char_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_char_Utils;

/****************************************************************
 ** kcg_int 
 ****************************************************************/
extern int kcg_int_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_kcg_int_string(const char *str, char **endptr);
extern int string_to_kcg_int(const char *str, void *pValue, char **endptr);
extern int is_kcg_int_double_conversion_allowed();
extern int kcg_int_to_double(const void *pValue, double *nValue);
extern int is_kcg_int_long_conversion_allowed();
extern int kcg_int_to_long(const void *pValue, long *nValue);
extern void compare_kcg_int(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_kcg_int_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_kcg_int_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_int_Utils;

/****************************************************************
 ** kcg_real 
 ****************************************************************/
extern int kcg_real_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_kcg_real_string(const char *str, char **endptr);
extern int string_to_kcg_real(const char *str, void *pValue, char **endptr);
extern int is_kcg_real_double_conversion_allowed();
extern int kcg_real_to_double(const void *pValue, double *nValue);
extern int is_kcg_real_long_conversion_allowed();
extern int kcg_real_to_long(const void *pValue, long *nValue);
extern void compare_kcg_real(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_kcg_real_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_kcg_real_default_value(void *pValue);
extern SimTypeUtils _Type_kcg_real_Utils;

/****************************************************************
 ** T_String 
 ****************************************************************/
extern int T_String_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_T_String_string(const char *str, char **endptr);
extern int string_to_T_String(const char *str, void *pValue, char **endptr);
extern int is_T_String_double_conversion_allowed();
extern int T_String_to_double(const void *pValue, double *nValue);
extern int is_T_String_long_conversion_allowed();
extern int T_String_to_long(const void *pValue, long *nValue);
extern void compare_T_String(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_T_String_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_T_String_default_value(void *pValue);
extern SimTypeUtils _Type_T_String_Utils;


#endif /*TS08_DRONE_TYPES_CONVERSION */
