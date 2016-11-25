#include "socket_test_snapshot.h"
#include "socket_test_type.h"
#include "SmuLib.h"
#include "SmuVTable.h"
#include "stdio.h"

#ifdef _MSC_VER
  #define snprintf _snprintf
#endif

const char* szKcgTraceCheckSum = "5a13174db08f1e72441e06aa4ed1e970";

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

int save_inC_test(const char *cpath, const inC_test *pValue, const void *pBaseAddr, FILE *snsFile) {
    int bOK = 1;
    bOK &= save_field(cpath, ".Description", (const void *)(&pValue->Description), pBaseAddr, array_char_150_to_string, snsFile); 
    bOK &= save_field(cpath, ".Notification", (const void *)(&pValue->Notification), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".SignalFromButton", (const void *)(&pValue->SignalFromButton), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".Title", (const void *)(&pValue->Title), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".Latitude", (const void *)(&pValue->Latitude), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".Longitude", (const void *)(&pValue->Longitude), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, ".Status", (const void *)(&pValue->Status), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".NotifyFromOcurrenceType", (const void *)(&pValue->NotifyFromOcurrenceType), pBaseAddr, kcg_bool_to_string, snsFile); 
    return bOK;
}

int save_outC_test(const char *cpath, const outC_test *pValue, const void *pBaseAddr, FILE *snsFile) {
    int bOK = 1;
    bOK &= save_field(cpath, ".Emit", (const void *)(&pValue->Emit), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".LEDReportRegisted", (const void *)(&pValue->LEDReportRegisted), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".LEDReportDispatched", (const void *)(&pValue->LEDReportDispatched), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".SelectedOcurrenceType", (const void *)(&pValue->SelectedOcurrenceType), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, ".EmitToOcurrenceType", (const void *)(&pValue->EmitToOcurrenceType), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, ".aqui", (const void *)(&pValue->aqui), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L4", (const void *)(&pValue->_L4), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L9", (const void *)(&pValue->_L9), pBaseAddr, array_char_150_to_string, snsFile); 
    bOK &= save_field(cpath, "._L15", (const void *)(&pValue->_L15), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L48", (const void *)(&pValue->_L48), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L47", (const void *)(&pValue->_L47), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L46", (const void *)(&pValue->_L46), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L44", (const void *)(&pValue->_L44), pBaseAddr, kcg_bool_to_string, snsFile); 
    bOK &= save_field(cpath, "._L50", (const void *)(&pValue->_L50), pBaseAddr, kcg_char_to_string, snsFile); 
    bOK &= save_field(cpath, "._L52", (const void *)(&pValue->_L52), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, "._L53", (const void *)(&pValue->_L53), pBaseAddr, kcg_real_to_string, snsFile); 
    bOK &= save_field(cpath, "._L55", (const void *)(&pValue->_L55), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L56", (const void *)(&pValue->_L56), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L57", (const void *)(&pValue->_L57), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L58", (const void *)(&pValue->_L58), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L59", (const void *)(&pValue->_L59), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L62", (const void *)(&pValue->_L62), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L63", (const void *)(&pValue->_L63), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L64", (const void *)(&pValue->_L64), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L65", (const void *)(&pValue->_L65), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L66", (const void *)(&pValue->_L66), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L67", (const void *)(&pValue->_L67), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L68", (const void *)(&pValue->_L68), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L69", (const void *)(&pValue->_L69), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L71", (const void *)(&pValue->_L71), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L72", (const void *)(&pValue->_L72), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L73", (const void *)(&pValue->_L73), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L74", (const void *)(&pValue->_L74), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L76", (const void *)(&pValue->_L76), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L77", (const void *)(&pValue->_L77), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L78", (const void *)(&pValue->_L78), pBaseAddr, kcg_int_to_string, snsFile); 
    bOK &= save_field(cpath, "._L80", (const void *)(&pValue->_L80), pBaseAddr, array_char_50_to_string, snsFile); 
    bOK &= save_field(cpath, "._L81", (const void *)(&pValue->_L81), pBaseAddr, array_char_16_to_string, snsFile); 
    bOK &= save_field(cpath, "._L82", (const void *)(&pValue->_L82), pBaseAddr, kcg_bool_to_string, snsFile); 
    return bOK;
}

int save_snapshot(const char *szFilePath, size_t nCycle,
                      inC_test *inC,
                      outC_test *outC) {
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
    bOK &= save_inC_test("inC", inC, (const void*)inC, snsFile);
    bOK &= save_outC_test("outC", outC, (const void*)outC, snsFile);

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

int load_inC_test(inC_test *pValue, FILE *snsFile) {
    int bOK = 1;
    bOK &= load_var((void *)(&pValue->Description), string_to_array_char_150, snsFile); 
    bOK &= load_var((void *)(&pValue->Notification), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->SignalFromButton), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->Title), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->Latitude), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->Longitude), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->Status), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->NotifyFromOcurrenceType), string_to_kcg_bool, snsFile); 
    return bOK;
}

int load_outC_test(outC_test *pValue, FILE *snsFile) {
    int bOK = 1;
    bOK &= load_var((void *)(&pValue->Emit), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->LEDReportRegisted), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->LEDReportDispatched), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->SelectedOcurrenceType), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->EmitToOcurrenceType), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->aqui), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L4), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L9), string_to_array_char_150, snsFile); 
    bOK &= load_var((void *)(&pValue->_L15), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L48), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L47), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L46), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L44), string_to_kcg_bool, snsFile); 
    bOK &= load_var((void *)(&pValue->_L50), string_to_kcg_char, snsFile); 
    bOK &= load_var((void *)(&pValue->_L52), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->_L53), string_to_kcg_real, snsFile); 
    bOK &= load_var((void *)(&pValue->_L55), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L56), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L57), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L58), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L59), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L62), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L63), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L64), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L65), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L66), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L67), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L68), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L69), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L71), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L72), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L73), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L74), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L76), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L77), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L78), string_to_kcg_int, snsFile); 
    bOK &= load_var((void *)(&pValue->_L80), string_to_array_char_50, snsFile); 
    bOK &= load_var((void *)(&pValue->_L81), string_to_array_char_16, snsFile); 
    bOK &= load_var((void *)(&pValue->_L82), string_to_kcg_bool, snsFile); 
    return bOK;
}

int load_snapshot(const char *szFilePath, size_t *nCycle,
                      inC_test *inC,
                      outC_test *outC) {
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
        bOK &= load_inC_test(inC, snsFile);
        bOK &= load_outC_test(outC, snsFile);
    }

    fclose(snsFile);
    SimStringFree(&strLine);
    return bOK;
}
