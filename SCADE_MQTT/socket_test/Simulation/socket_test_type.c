#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include "kcg_types.h"
#include "SmuTypes.h"
#include "SmuPredefConv.h"
#include "SmuVTable.h"
#include "socket_test_type.h"

char strDefaultRealFormat[] = "%.5g"; /* (from .etp) */

#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

/****************************************************************
 ** array_char_150 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimarray_char_150VTable_defined
    extern struct SimTypeVTable *pSimarray_char_150VTable;
  #else 
    struct SimTypeVTable *pSimarray_char_150VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimarray_char_150VTable;
#endif

int array_char_150_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimarray_char_150VTable != NULL
        && pSimarray_char_150VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_char_150VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    if (pConverter->m_bDisplayStrings)
        return pConverter->m_pfnCharArrayToString(pValue, kcg_char_to_string, 150, sizeof(kcg_char), pfnStrAppend, pStrObj, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
    else
        return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 150, sizeof(kcg_char), pfnStrAppend, pStrObj);
}

int check_array_char_150_string(const char *str, char **endptr)
{
    static array_char_150 rTemp;
    return string_to_array_char_150(str, &rTemp, endptr);
}

int string_to_array_char_150(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimarray_char_150VTable != NULL) {
        nRet = string_to_VTable(str, pSimarray_char_150VTable, pValue, endptr);
    }
    if (nRet == 0) {
        if (*str == '"')
            nRet = pConverter->m_pfnStringToCharArray(str, pValue, &_Type_kcg_char_Utils, 150, sizeof(kcg_char), endptr, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
        else
            nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_char_Utils, 150, sizeof(kcg_char), endptr);
    }
    return nRet;
}

int is_array_char_150_double_conversion_allowed()
{
    if (pSimarray_char_150VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimarray_char_150VTable);
    }
    return 0;
}

int array_char_150_to_double(const void *pValue, double *nValue)
{
    if (pSimarray_char_150VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_char_150VTable, nValue);
    }
    return 0;
}

int is_array_char_150_long_conversion_allowed()
{
    if (pSimarray_char_150VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimarray_char_150VTable);
    }
    return 0;
}

int array_char_150_to_long(const void *pValue, long *nValue)
{
    if (pSimarray_char_150VTable != NULL) {
        return VTable_to_long(pValue, pSimarray_char_150VTable, nValue);
    }
    return 0;
}

void compare_array_char_150(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimarray_char_150VTable != NULL
        && pSimarray_char_150VTable->m_version >= Scv612
        && pSimarray_char_150VTable->m_pfnCompare != NULL) {
        if (pSimarray_char_150VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimarray_char_150VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimarray_char_150VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_char, 150, sizeof(kcg_char), pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_array_char_150_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetArraySignature(get_kcg_char_signature, 150, pfnStrAppend, pStrObj); 
}

int set_array_char_150_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 150; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

SimTypeUtils _Type_array_char_150_Utils = {
    array_char_150_to_string,
    check_array_char_150_string,
    string_to_array_char_150,
    is_array_char_150_double_conversion_allowed,
    array_char_150_to_double,
    is_array_char_150_long_conversion_allowed,
    array_char_150_to_long,
    compare_array_char_150,
    get_array_char_150_signature,
    set_array_char_150_default_value,
    sizeof(array_char_150)
};

/****************************************************************
 ** array_char_16 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimarray_char_16VTable_defined
    extern struct SimTypeVTable *pSimarray_char_16VTable;
  #else 
    struct SimTypeVTable *pSimarray_char_16VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimarray_char_16VTable;
#endif

int array_char_16_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimarray_char_16VTable != NULL
        && pSimarray_char_16VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_char_16VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    if (pConverter->m_bDisplayStrings)
        return pConverter->m_pfnCharArrayToString(pValue, kcg_char_to_string, 16, sizeof(kcg_char), pfnStrAppend, pStrObj, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
    else
        return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 16, sizeof(kcg_char), pfnStrAppend, pStrObj);
}

int check_array_char_16_string(const char *str, char **endptr)
{
    static array_char_16 rTemp;
    return string_to_array_char_16(str, &rTemp, endptr);
}

int string_to_array_char_16(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimarray_char_16VTable != NULL) {
        nRet = string_to_VTable(str, pSimarray_char_16VTable, pValue, endptr);
    }
    if (nRet == 0) {
        if (*str == '"')
            nRet = pConverter->m_pfnStringToCharArray(str, pValue, &_Type_kcg_char_Utils, 16, sizeof(kcg_char), endptr, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
        else
            nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_char_Utils, 16, sizeof(kcg_char), endptr);
    }
    return nRet;
}

int is_array_char_16_double_conversion_allowed()
{
    if (pSimarray_char_16VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimarray_char_16VTable);
    }
    return 0;
}

int array_char_16_to_double(const void *pValue, double *nValue)
{
    if (pSimarray_char_16VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_char_16VTable, nValue);
    }
    return 0;
}

int is_array_char_16_long_conversion_allowed()
{
    if (pSimarray_char_16VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimarray_char_16VTable);
    }
    return 0;
}

int array_char_16_to_long(const void *pValue, long *nValue)
{
    if (pSimarray_char_16VTable != NULL) {
        return VTable_to_long(pValue, pSimarray_char_16VTable, nValue);
    }
    return 0;
}

void compare_array_char_16(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimarray_char_16VTable != NULL
        && pSimarray_char_16VTable->m_version >= Scv612
        && pSimarray_char_16VTable->m_pfnCompare != NULL) {
        if (pSimarray_char_16VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimarray_char_16VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimarray_char_16VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_char, 16, sizeof(kcg_char), pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_array_char_16_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetArraySignature(get_kcg_char_signature, 16, pfnStrAppend, pStrObj); 
}

int set_array_char_16_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 16; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

SimTypeUtils _Type_array_char_16_Utils = {
    array_char_16_to_string,
    check_array_char_16_string,
    string_to_array_char_16,
    is_array_char_16_double_conversion_allowed,
    array_char_16_to_double,
    is_array_char_16_long_conversion_allowed,
    array_char_16_to_long,
    compare_array_char_16,
    get_array_char_16_signature,
    set_array_char_16_default_value,
    sizeof(array_char_16)
};

/****************************************************************
 ** array_char_50 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimarray_char_50VTable_defined
    extern struct SimTypeVTable *pSimarray_char_50VTable;
  #else 
    struct SimTypeVTable *pSimarray_char_50VTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimarray_char_50VTable;
#endif

int array_char_50_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimarray_char_50VTable != NULL
        && pSimarray_char_50VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimarray_char_50VTable->m_pfnToType(SptString, pValue), pStrObj);
    }
    if (pConverter->m_bDisplayStrings)
        return pConverter->m_pfnCharArrayToString(pValue, kcg_char_to_string, 50, sizeof(kcg_char), pfnStrAppend, pStrObj, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
    else
        return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 50, sizeof(kcg_char), pfnStrAppend, pStrObj);
}

int check_array_char_50_string(const char *str, char **endptr)
{
    static array_char_50 rTemp;
    return string_to_array_char_50(str, &rTemp, endptr);
}

int string_to_array_char_50(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    skip_whitespace(str);
    if (pSimarray_char_50VTable != NULL) {
        nRet = string_to_VTable(str, pSimarray_char_50VTable, pValue, endptr);
    }
    if (nRet == 0) {
        if (*str == '"')
            nRet = pConverter->m_pfnStringToCharArray(str, pValue, &_Type_kcg_char_Utils, 50, sizeof(kcg_char), endptr, pConverter->m_bStringsPadding, pConverter->m_cStringsPaddingChar);
        else
            nRet = pConverter->m_pfnStringToArray(str, pValue, &_Type_kcg_char_Utils, 50, sizeof(kcg_char), endptr);
    }
    return nRet;
}

int is_array_char_50_double_conversion_allowed()
{
    if (pSimarray_char_50VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimarray_char_50VTable);
    }
    return 0;
}

int array_char_50_to_double(const void *pValue, double *nValue)
{
    if (pSimarray_char_50VTable != NULL) {
        return VTable_to_double(pValue, pSimarray_char_50VTable, nValue);
    }
    return 0;
}

int is_array_char_50_long_conversion_allowed()
{
    if (pSimarray_char_50VTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimarray_char_50VTable);
    }
    return 0;
}

int array_char_50_to_long(const void *pValue, long *nValue)
{
    if (pSimarray_char_50VTable != NULL) {
        return VTable_to_long(pValue, pSimarray_char_50VTable, nValue);
    }
    return 0;
}

void compare_array_char_50(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimarray_char_50VTable != NULL
        && pSimarray_char_50VTable->m_version >= Scv612
        && pSimarray_char_50VTable->m_pfnCompare != NULL) {
        if (pSimarray_char_50VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult |= SIM_CMP_RES_LT/...): */
            unitResult = pSimarray_char_50VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult = -1/1/0): */
            pSimarray_char_50VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnArrayComparison(pResult, pValue1, pValue2, 
                compare_kcg_char, 50, sizeof(kcg_char), pTol, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_array_char_50_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pConverter->m_pfnGetArraySignature(get_kcg_char_signature, 50, pfnStrAppend, pStrObj); 
}

int set_array_char_50_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 50; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

SimTypeUtils _Type_array_char_50_Utils = {
    array_char_50_to_string,
    check_array_char_50_string,
    string_to_array_char_50,
    is_array_char_50_double_conversion_allowed,
    array_char_50_to_double,
    is_array_char_50_long_conversion_allowed,
    array_char_50_to_long,
    compare_array_char_50,
    get_array_char_50_signature,
    set_array_char_50_default_value,
    sizeof(array_char_50)
};

/****************************************************************
 ** kcg_bool 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimBoolVTable_defined
    extern struct SimTypeVTable *pSimBoolVTable;
  #else 
    struct SimTypeVTable *pSimBoolVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimBoolVTable;
#endif

int kcg_bool_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_bool_to_string(*((kcg_bool*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_bool_string(const char *str, char **endptr)
{
    static kcg_bool rTemp;
    return string_to_kcg_bool(str, &rTemp, endptr);
}

int string_to_kcg_bool(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static SimBool rTemp;
    skip_whitespace(str);
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimBoolVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimBoolVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_bool*)pValue = (rTemp == SbTrue)? kcg_true : kcg_false;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_bool(str, (kcg_bool*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_bool_double_conversion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimBoolVTable);
    }
    return 1;
}

int kcg_bool_to_double(const void *pValue, double *nValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimBoolVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_double(&value, pSimBoolVTable, nValue);
        }
    }
    *nValue = *((kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
    return 1;
}

int is_kcg_bool_long_conversion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimBoolVTable);
    }
    return 1;
}

int kcg_bool_to_long(const void *pValue, long *nValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimBoolVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_long(&value, pSimBoolVTable, nValue);
        }
    }
    *nValue = *((kcg_bool*)pValue) == kcg_true ? 1 : 0;
    return 1;
}

void compare_kcg_bool(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_version >= Scv612
        && pSimBoolVTable->m_pfnCompare != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimBoolVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value1 = (*((const kcg_bool*)pValue1) == kcg_true)? SbTrue : SbFalse;
            SimBool value2 = (*((const kcg_bool*)pValue2) == kcg_true)? SbTrue : SbFalse;
            pSimBoolVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_bool(pResult, *((kcg_bool*)pValue1), *((kcg_bool*)pValue2));
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_bool_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("B", pStrObj);
}

int set_kcg_bool_default_value(void *pValue)
{
    *(kcg_bool*)pValue = kcg_false;
    return 1;
}

SimTypeUtils _Type_kcg_bool_Utils = {
    kcg_bool_to_string,
    check_kcg_bool_string,
    string_to_kcg_bool,
    is_kcg_bool_double_conversion_allowed,
    kcg_bool_to_double,
    is_kcg_bool_long_conversion_allowed,
    kcg_bool_to_long,
    compare_kcg_bool,
    get_kcg_bool_signature,
    set_kcg_bool_default_value,
    sizeof(kcg_bool)
};

/****************************************************************
 ** kcg_char 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimCharVTable_defined
    extern struct SimTypeVTable *pSimCharVTable;
  #else 
    struct SimTypeVTable *pSimCharVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimCharVTable;
#endif

int kcg_char_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_char_to_string(*((kcg_char*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_char_string(const char *str, char **endptr)
{
    static kcg_char rTemp;
    return string_to_kcg_char(str, &rTemp, endptr);
}

int string_to_kcg_char(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static char rTemp;
    skip_whitespace(str);
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimCharVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimCharVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_char*)pValue = (kcg_char)rTemp;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_char(str, (kcg_char*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_char_double_conversion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimCharVTable);
    }
    return 1;
}

int kcg_char_to_double(const void *pValue, double *nValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimCharVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_double(&value, pSimCharVTable, nValue);
        }
    }
    *nValue = (double)*((kcg_char*)pValue);
    return 1;
}

int is_kcg_char_long_conversion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimCharVTable);
    }
    return 1;
}

int kcg_char_to_long(const void *pValue, long *nValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimCharVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_long(&value, pSimCharVTable, nValue);
        }
    }
    *nValue = (long)*((kcg_char*)pValue);
    return 1;
}

void compare_kcg_char(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_version >= Scv612
        && pSimCharVTable->m_pfnCompare != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimCharVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value1 = (char)(*(const kcg_char*)pValue1);
            char value2 = (char)(*(const kcg_char*)pValue2);
            pSimCharVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_char(pResult, *((kcg_char*)pValue1), *((kcg_char*)pValue2));
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_char_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("C", pStrObj);
}

int set_kcg_char_default_value(void *pValue)
{
    *(kcg_char*)pValue = 0;
    return 1;
}

SimTypeUtils _Type_kcg_char_Utils = {
    kcg_char_to_string,
    check_kcg_char_string,
    string_to_kcg_char,
    is_kcg_char_double_conversion_allowed,
    kcg_char_to_double,
    is_kcg_char_long_conversion_allowed,
    kcg_char_to_long,
    compare_kcg_char,
    get_kcg_char_signature,
    set_kcg_char_default_value,
    sizeof(kcg_char)
};

/****************************************************************
 ** kcg_int 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimLongVTable_defined
    extern struct SimTypeVTable *pSimLongVTable;
  #else 
    struct SimTypeVTable *pSimLongVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimLongVTable;
#endif

int kcg_int_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_int_to_string(*((kcg_int*)pValue), pfnStrAppend, pStrObj);
}

int check_kcg_int_string(const char *str, char **endptr)
{
    static kcg_int rTemp;
    return string_to_kcg_int(str, &rTemp, endptr);
}

int string_to_kcg_int(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static long rTemp;
    skip_whitespace(str);
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimLongVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimLongVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_int*)pValue = (kcg_int)rTemp;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_int(str, (kcg_int*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int_double_conversion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimLongVTable);
    }
    return 1;
}

int kcg_int_to_double(const void *pValue, double *nValue)
{
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimLongVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return VTable_to_double(&value, pSimLongVTable, nValue);
        }
    }
    *nValue = (double)*((kcg_int*)pValue);
    return 1;
}

int is_kcg_int_long_conversion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimLongVTable);
    }
    return 1;
}

int kcg_int_to_long(const void *pValue, long *nValue)
{
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimLongVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return VTable_to_long(&value, pSimLongVTable, nValue);
        }
    }
    *nValue = (long)*((kcg_int*)pValue);
    return 1;
}

void compare_kcg_int(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    /* Customized comparison */
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_version >= Scv612
        && pSimLongVTable->m_pfnCompare != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimLongVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value1 = (long)(*(const kcg_int*)pValue1);
            long value2 = (long)(*(const kcg_int*)pValue2);
            pSimLongVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int(pResult, *((kcg_int*)pValue1), *((kcg_int*)pValue2));
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_int_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("I", pStrObj);
}

int set_kcg_int_default_value(void *pValue)
{
    *(kcg_int*)pValue = 0;
    return 1;
}

SimTypeUtils _Type_kcg_int_Utils = {
    kcg_int_to_string,
    check_kcg_int_string,
    string_to_kcg_int,
    is_kcg_int_double_conversion_allowed,
    kcg_int_to_double,
    is_kcg_int_long_conversion_allowed,
    kcg_int_to_long,
    compare_kcg_int,
    get_kcg_int_signature,
    set_kcg_int_default_value,
    sizeof(kcg_int)
};

/****************************************************************
 ** kcg_real 
 ****************************************************************/

#ifdef __cplusplus
  #ifdef pSimDoubleVTable_defined
    extern struct SimTypeVTable *pSimDoubleVTable;
  #else 
    struct SimTypeVTable *pSimDoubleVTable = NULL;
  #endif
#else
  struct SimTypeVTable *pSimDoubleVTable;
#endif

int kcg_real_to_string(const void *pValue, PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, pValue), pStrObj);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, &value), pStrObj);
        }
    }
    return predef_kcg_real_to_string(*((kcg_real*)pValue), pConverter->m_RealFormat, pfnStrAppend, pStrObj);
}

int check_kcg_real_string(const char *str, char **endptr)
{
    static kcg_real rTemp;
    return string_to_kcg_real(str, &rTemp, endptr);
}

int string_to_kcg_real(const char *str, void *pValue, char **endptr)
{
    int nRet = 0;
    static double rTemp;
    skip_whitespace(str);
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet = string_to_VTable(str, pSimDoubleVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet = string_to_VTable(str, pSimDoubleVTable, &rTemp, endptr);
            if (nRet != 0) {
                *(kcg_real*)pValue = (kcg_real)rTemp;
            }
        }
    }
    if (nRet == 0) {
        nRet = predef_string_to_kcg_real(str, (kcg_real*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_real_double_conversion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimDoubleVTable);
    }
    return 1;
}

int kcg_real_to_double(const void *pValue, double *nValue)
{
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimDoubleVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return VTable_to_double(&value, pSimDoubleVTable, nValue);
        }
    }
    *nValue = (double)*((kcg_real*)pValue);
    return 1;
}

int is_kcg_real_long_conversion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_long_conversion_allowed(pSimDoubleVTable);
    }
    return 1;
}

int kcg_real_to_long(const void *pValue, long *nValue)
{
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimDoubleVTable, nValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return VTable_to_long(&value, pSimDoubleVTable, nValue);
        }
    }
    *nValue = (long)*((kcg_real*)pValue);
    return 1;
}

void compare_kcg_real(int *pResult, const void *pValue1, const void *pValue2, SimTolerance *pTol, const char *pszPath, PFN_STR_LIST_APPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult = 0;
    SimTolerance defaultTol = {(sizeof(kcg_real) == 8 ? DBL_MIN : FLT_MIN), 0};
    if (!pTol)
        pTol = &defaultTol;
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_version >= Scv65
        && pSimDoubleVTable->m_pfnCompareWithTol != NULL ) {
        /* Customized comparison with tolerance (R15 and higher): */
        unitResult = pSimDoubleVTable->m_pfnCompareWithTol(pResult, pValue1, pValue2, pTol);
    } else if (pSimDoubleVTable != NULL && pTol == &defaultTol
               && pSimDoubleVTable->m_version >= Scv612
               && pSimDoubleVTable->m_pfnCompare != NULL) {
        /* Customized comparison without tolerance: */
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimDoubleVTable->m_pfnCompare(pResult, pValue1, pValue2);
         } else {
             /* Before R15: VTable function returns a standard C typed *variable: */
             double value1 = (double)(*(const kcg_real*)pValue1);
             double value2 = (double)(*(const kcg_real*)pValue2);
             pSimDoubleVTable->m_pfnCompare(&unitResult, &value1, &value2);
             updateCompareResult(unitResult, pResult);
         }
    } else {
        /* Predefined comparison (with/without tolerance): */
        unitResult = predef_compare_kcg_real(pResult, *((kcg_real*)pValue1), *((kcg_real*)pValue2), pTol);
    }
    if (unitResult != 0 && pfnStrListAppend != NULL && pszPath != NULL && *pszPath != 0 && pListErrPaths != NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int get_kcg_real_signature(PFN_STR_APPEND pfnStrAppend, void *pStrObj)
{
    return pfnStrAppend("R", pStrObj);
}

int set_kcg_real_default_value(void *pValue)
{
    *(kcg_real*)pValue = 0.0;
    return 1;
}

SimTypeUtils _Type_kcg_real_Utils = {
    kcg_real_to_string,
    check_kcg_real_string,
    string_to_kcg_real,
    is_kcg_real_double_conversion_allowed,
    kcg_real_to_double,
    is_kcg_real_long_conversion_allowed,
    kcg_real_to_long,
    compare_kcg_real,
    get_kcg_real_signature,
    set_kcg_real_default_value,
    sizeof(kcg_real)
};

