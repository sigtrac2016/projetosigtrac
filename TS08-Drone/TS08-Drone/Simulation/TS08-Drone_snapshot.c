#include "TS08-Drone_snapshot.h"
#include "TS08-Drone_type.h"
#include "SmuLib.h"
#include "SmuVTable.h"
#include "stdio.h"

#ifdef _MSC_VER
  #define snprintf _snprintf
#endif

const char* szKcgTraceCheckSum = "1aaab6f3729bb06e9557636761ff214d";

/*********************************************
 * Snapshot Save functions
 *********************************************/
int save_var(const char *cpath, const void *pValue, const void *pBaseAddr, PFN_TYPE_TO_STRING pfnTypeToString, FILE *snsFile) {
    int bOK = 1;
    SimString strValue;
    SimStringAlloc(&strValue);
    bOK &= (pfnTypeToString(pValue, SimStringAppend, &strValue) != 0);
    bOK &= (fprintf(snsFile, "%s\t[offset=%u]\t%s\n", SimStringGet(&strValue), (size_t)pValue-(size_t)pBaseAddr, cpath) >= 0);
    SimStringFree(&strValue);
    return bOK;
}

int save_field(const char *cpath, const char *proj, const void *pValue, const void *pBaseAddr, PFN_TYPE_TO_STRING pfnTypeToString, FILE *snsFile) {
    int bOK = 1;
    SimString strCPath;
    SimStringAlloc(&strCPath);
    SimStringAppend(cpath, &strCPath);
    SimStringAppend(proj, &strCPath);
    bOK = save_var(SimStringGet(&strCPath), pValue, pBaseAddr, pfnTypeToString, snsFile);
    SimStringFree(&strCPath);
    return bOK;
}

typedef int(*PFN_SAVE_CONTEXT)(const char *cpath, const void *pValue, const void *pBaseAddr, FILE *snsFile);

int save_context(const char *cpath, const char *proj, const void *pValue, const void *pBaseAddr, PFN_SAVE_CONTEXT pfnSaveContext, FILE *snsFile) {
    int bOK = 1;
    SimString strCPath;
    SimStringAlloc(&strCPath);
    SimStringAppend(cpath, &strCPath);
    SimStringAppend(proj, &strCPath);
    bOK = pfnSaveContext(SimStringGet(&strCPath), pValue, pBaseAddr, snsFile);
    SimStringFree(&strCPath);
    return bOK;
}

int save_inC_Main(const char *cpath, const inC_Main *pValue, const void *pBaseAddr, FILE *snsFile) {
    int bOK = 1;
    bOK &= save_field(cpath, ".OnButton", (const void *)(&pValue->OnButton), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".VertSpeedInput", (const void *)(&pValue->VertSpeedInput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".HorSpeedInput", (const void *)(&pValue->HorSpeedInput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".DirInput", (const void *)(&pValue->DirInput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".TkoffButton", (const void *)(&pValue->TkoffButton), pBaseAddr, kcg_bool_to_string, snsFile); 
    return bOK;
}

int save_outC_Main(const char *cpath, const outC_Main *pValue, const void *pBaseAddr, FILE *snsFile) {
    int bOK = 1;
    bOK &= save_field(cpath, ".StatusButtonText", (const void *)(&pValue->StatusButtonText), pBaseAddr, T_String_to_string, snsFile); 
    bOK &= save_field(cpath, ".StatusButtonColor", (const void *)(&pValue->StatusButtonColor), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".Emit", (const void *)(&pValue->Emit), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".Str_size", (const void *)(&pValue->Str_size), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".LayerVisible", (const void *)(&pValue->LayerVisible), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".LayerActive", (const void *)(&pValue->LayerActive), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".ButtonText", (const void *)(&pValue->ButtonText), pBaseAddr, T_String_to_string, snsFile); 
    bOK &= save_field(cpath, ".VertSpeedOutput", (const void *)(&pValue->VertSpeedOutput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".HorSpeedOutput", (const void *)(&pValue->HorSpeedOutput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".DirOutput", (const void *)(&pValue->DirOutput), pBaseAddr, _1_float_to_string, snsFile); 
    bOK &= save_field(cpath, ".CompassDir", (const void *)(&pValue->CompassDir), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".TkoffText", (const void *)(&pValue->TkoffText), pBaseAddr, T_String_to_string, snsFile); 
    bOK &= save_field(cpath, ".AltitudeOut", (const void *)(&pValue->AltitudeOut), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".YawOut", (const void *)(&pValue->YawOut), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".Latitude", (const void *)(&pValue->Latitude), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".Longitude", (const void *)(&pValue->Longitude), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".init", (const void *)(&pValue->init), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".On", (const void *)(&pValue->On), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".output_2_2", (const void *)(&pValue->output_2_2), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L1_2_2", (const void *)(&pValue->_L1_2_2), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L32_1", (const void *)(&pValue->_L32_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L49_1", (const void *)(&pValue->_L49_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".output_1_1", (const void *)(&pValue->output_1_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L1_1_1", (const void *)(&pValue->_L1_1_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L26_1", (const void *)(&pValue->_L26_1), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, "._L34_1", (const void *)(&pValue->_L34_1), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, "._L8_1", (const void *)(&pValue->_L8_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L10_1", (const void *)(&pValue->_L10_1), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L21_1", (const void *)(&pValue->_L21_1), pBaseAddr, kcg_real_to_string, snsFile); 
    return bOK;
}

int save_snapshot(const char *szFilePath, size_t nCycle,
                      inC_Main *inC,
                      outC_Main *outC) {
    int bOK = 1;
    char savRealFormat[MAX_REAL_FORMAT_LEN];
    FILE *snsFile = fopen(szFilePath, "w");
    if ( !snsFile )
        return 0;

    /* Force real number format to 17 significant digits */
    strcpy(savRealFormat, pConverter->m_RealFormat);
    strcpy(pConverter->m_RealFormat, "%.17g");

    /* Write mapping file checksum */
    bOK &= (fprintf(snsFile, "%s\n", szKcgTraceCheckSum) >= 0);

    /* Write cycle counter */
    bOK &= (fprintf(snsFile, "%u\n", nCycle) >= 0);

    /* Write all context variables */
    bOK &= save_inC_Main("inC", inC, (const void*)inC, snsFile);
    bOK &= save_outC_Main("outC", outC, (const void*)outC, snsFile);

    /* Restore real number format */
    strcpy(pConverter->m_RealFormat, savRealFormat);
    fclose(snsFile);
    return bOK;
}
/*********************************************
 * Snapshot Load functions
 *********************************************/
int read_line(FILE *snsFile, SimString *pstrLine) {
    char buf[1024];
    size_t bufLen;
    SimStringReset(pstrLine);
    if (feof(snsFile))
        return 0;
    /* Read entire line */
    while (fgets(buf, 100, snsFile) != NULL) {
        SimStringAppend(buf, pstrLine);
        if (buf[strlen(buf) - 1] == '\n')
            break;
    }
    /* Remove end of line characters */
    while (pstrLine->m_nLength >=0 && pstrLine->m_pszBase[pstrLine->m_nLength-1] == '\n' || pstrLine->m_pszBase[pstrLine->m_nLength-1] == '\r') {
        pstrLine->m_pszBase[pstrLine->m_nLength-1] = '\0';
        pstrLine->m_nLength--;
    }
    return 1;
}

int load_var(void *pValue, PFN_STRING_TO_TYPE pfnStringToType, FILE *snsFile) {
    int bOK = 1;
    char *endptr;
    SimString strLine;
    SimStringAlloc(&strLine);
    bOK = read_line(snsFile, &strLine);
    if (bOK)
        bOK = (pfnStringToType(SimStringGet(&strLine), pValue, &endptr) != 0
            && (*endptr=='\t' || *endptr=='\0' || *endptr==' '));
    SimStringFree(&strLine);
    return bOK;
}

int load_inC_Main(inC_Main *pValue, FILE *snsFile) {
    int bOK = 1;
    bOK &= load_var((void *)(&pValue->OnButton), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->VertSpeedInput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->HorSpeedInput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->DirInput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->TkoffButton), string_to_kcg_bool, snsFile); 
    return bOK;
}

int load_outC_Main(outC_Main *pValue, FILE *snsFile) {
    int bOK = 1;
    bOK &= load_var((void *)(&pValue->StatusButtonText), string_to_T_String, snsFile); 
    bOK &= load_var((void *)(&pValue->StatusButtonColor), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->Emit), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->Str_size), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->LayerVisible), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->LayerActive), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->ButtonText), string_to_T_String, snsFile); 
    bOK &= load_var((void *)(&pValue->VertSpeedOutput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->HorSpeedOutput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->DirOutput), string_to__1_float, snsFile); 
    bOK &= load_var((void *)(&pValue->CompassDir), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->TkoffText), string_to_T_String, snsFile); 
    bOK &= load_var((void *)(&pValue->AltitudeOut), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->YawOut), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->Latitude), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->Longitude), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->init), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->On), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->output_2_2), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L1_2_2), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L32_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L49_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->output_1_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L1_1_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L26_1), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->_L34_1), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->_L8_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L10_1), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L21_1), string_to_kcg_real, snsFile); 
    return bOK;
}

int load_snapshot(const char *szFilePath, size_t *nCycle,
                      inC_Main *inC,
                      outC_Main *outC) {
    int bOK = 1;
    FILE *snsFile = fopen(szFilePath, "r");
    SimString strLine;
    SimStringAlloc(&strLine);
    if ( !snsFile )
        return 0;

    /* Read and verify mapping file checksum */
    bOK = read_line(snsFile, &strLine);
    if (bOK)
        bOK = strcmp(SimStringGet(&strLine), szKcgTraceCheckSum)==0;

    /* Read cycle counter */
    if (bOK)
        bOK = (fscanf(snsFile, "%u\n", nCycle) == 1);

    /* Read all context variables */
    if (bOK) {
        bOK &= load_inC_Main(inC, snsFile);
        bOK &= load_outC_Main(outC, snsFile);
    }

    fclose(snsFile);
    SimStringFree(&strLine);
    return bOK;
}
