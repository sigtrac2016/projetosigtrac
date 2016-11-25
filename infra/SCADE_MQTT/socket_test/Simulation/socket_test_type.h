#ifndef SOCKET_TEST_TYPES_CONVERSION
#define SOCKET_TEST_TYPES_CONVERSION

#include "SmuTypes.h"

/****************************************************************
 ** array_char_150 
 ****************************************************************/
extern int array_char_150_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_array_char_150_string(const char *str, char **endptr);
extern int string_to_array_char_150(const char *str, void *pValue, char **endptr);
extern int is_array_char_150_double_conversion_allowed();
extern int array_char_150_to_double(const void *pValue, double *nValue);
extern int is_array_char_150_long_conversion_allowed();
extern int array_char_150_to_long(const void *pValue, long *nValue);
extern void compare_array_char_150(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_array_char_150_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_array_char_150_default_value(void *pValue);
extern SimTypeUtils _Type_array_char_150_Utils;

/****************************************************************
 ** array_char_16 
 ****************************************************************/
extern int array_char_16_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_array_char_16_string(const char *str, char **endptr);
extern int string_to_array_char_16(const char *str, void *pValue, char **endptr);
extern int is_array_char_16_double_conversion_allowed();
extern int array_char_16_to_double(const void *pValue, double *nValue);
extern int is_array_char_16_long_conversion_allowed();
extern int array_char_16_to_long(const void *pValue, long *nValue);
extern void compare_array_char_16(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_array_char_16_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_array_char_16_default_value(void *pValue);
extern SimTypeUtils _Type_array_char_16_Utils;

/****************************************************************
 ** array_char_50 
 ****************************************************************/
extern int array_char_50_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int check_array_char_50_string(const char *str, char **endptr);
extern int string_to_array_char_50(const char *str, void *pValue, char **endptr);
extern int is_array_char_50_double_conversion_allowed();
extern int array_char_50_to_double(const void *pValue, double *nValue);
extern int is_array_char_50_long_conversion_allowed();
extern int array_char_50_to_long(const void *pValue, long *nValue);
extern void compare_array_char_50(int *nStatus, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths);
extern int get_array_char_50_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj);
extern int set_array_char_50_default_value(void *pValue);
extern SimTypeUtils _Type_array_char_50_Utils;

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


#endif /*SOCKET_TEST_TYPES_CONVERSION */
