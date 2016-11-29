#include "TS08-Drone_interface.h"
#include "TS08-Drone_snapshot.h"
#include "SmuVTable.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "262ae51fe584ed39b134af886b6cec4f";
const char* _SCSIM_SmuTypesCheckSum = "3093108411c6570b9c21d7b04ee1db2c";

/*******************************
 * Validity
 *******************************/
int valid(void * pHandle) {
    return 1;
}
int notvalid(void * pHandle) {
    return 0;
}

/*******************************
 * Simulation context
 *******************************/
inC_Main inputs_ctx;
static inC_Main inputs_ctx_restore;
static inC_Main inputs_ctx_execute;
outC_Main outputs_ctx;

/* separate_io: inputs instanciation */

/* separate_io: outputs instanciation */

static void _SCSIM_RestoreInterface(void) {
    inputs_ctx.OnButton = inputs_ctx_restore.OnButton;
    inputs_ctx.VertSpeedInput = inputs_ctx_restore.VertSpeedInput;
    inputs_ctx.HorSpeedInput = inputs_ctx_restore.HorSpeedInput;
    inputs_ctx.DirInput = inputs_ctx_restore.DirInput;
    inputs_ctx.TkoffButton = inputs_ctx_restore.TkoffButton;
    memset((void*)&outputs_ctx, 0,  sizeof(outputs_ctx));

    /* separate_io: outputs restore */
}

static void _SCSIM_ExecuteInterface(void) {
    pSimulator->m_pfnAcquireValueMutex(pSimulator);
    inputs_ctx_execute.OnButton = inputs_ctx.OnButton;
    inputs_ctx_execute.VertSpeedInput = inputs_ctx.VertSpeedInput;
    inputs_ctx_execute.HorSpeedInput = inputs_ctx.HorSpeedInput;
    inputs_ctx_execute.DirInput = inputs_ctx.DirInput;
    inputs_ctx_execute.TkoffButton = inputs_ctx.TkoffButton;
    pSimulator->m_pfnReleaseValueMutex(pSimulator);
}

/*******************************
 * Init/Reset function encapsulation
 *******************************/
int SimInit(void) {
    int nRet=0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif /* EXTENDED_SIM */
#ifndef KCG_USER_DEFINED_INIT
    Main_init(&outputs_ctx);
    nRet=1;
#else /* KCG_USER_DEFINED_INIT */
    nRet=0;
#endif /* KCG_USER_DEFINED_INIT */
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif /* EXTENDED_SIM */
    return nRet;
}

int SimReset(void) {
    int nRet=0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif /* EXTENDED_SIM */
#ifndef KCG_NO_EXTERN_CALL_TO_RESET
    Main_reset(&outputs_ctx);
    nRet=1;
#else /* KCG_NO_EXTERN_CALL_TO_RESET */
    nRet=0;
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif /* EXTENDED_SIM */
    return nRet;
}

#ifdef __cplusplus
  #ifdef pSimoutC_MainCIVTable_defined
    extern struct SimCustomInitVTable *pSimoutC_MainCIVTable;
  #else 
    struct SimCustomInitVTable *pSimoutC_MainCIVTable = NULL;
  #endif
#else
  struct SimCustomInitVTable *pSimoutC_MainCIVTable;
#endif

int SimCustomInit(void) {
    int nRet = 0;
    if (pSimoutC_MainCIVTable != NULL
        && pSimoutC_MainCIVTable->m_pfnCustomInit != NULL) {
        /* VTable function provided => call it */
        nRet = pSimoutC_MainCIVTable->m_pfnCustomInit ((void*)&outputs_ctx);
    } else {
        /* VTable misssing => error */
        nRet = 0;
    }
    return nRet;
}

#ifdef EXTENDED_SIM
int GraphicalInputsConnected = 1;
#endif /* EXTENDED_SIM */
/*******************************
 * Cyclic function encapsulation
 *******************************/
int SimStep(void) {
#ifdef EXTENDED_SIM
    if (GraphicalInputsConnected)
        BeforeSimStep();
#endif /* EXTENDED_SIM */
    _SCSIM_ExecuteInterface();
    Main(&inputs_ctx_execute, &outputs_ctx);
#ifdef EXTENDED_SIM
    AfterSimStep();
#endif /* EXTENDED_SIM */
    return 1;
}

int SimStop(void) {
#ifdef EXTENDED_SIM
    ExtendedSimStop();
#endif /* EXTENDED_SIM */
    return 1;
}

int SsmGetDumpSize(void) {
    int nSize = 0;
    nSize += sizeof(inC_Main);

/* separate_io: add (not in ctx) inputs size */

/* separate_io: add (not in ctx) outputs size */
    nSize += sizeof(outC_Main);
#ifdef EXTENDED_SIM
    nSize += ExtendedGetDumpSize();
#endif /* EXTENDED_SIM */
    return nSize;
}

void SsmGatherDumpData(char * pData) {
    char* pCurrent = pData;
    memcpy(pCurrent, &inputs_ctx, sizeof(inC_Main));
    pCurrent += sizeof(inC_Main);

    /* separate_io: dump (not in ctx) inputs */

    /* separate_io: dump (not in ctx) outputs */
    memcpy(pCurrent, &outputs_ctx, sizeof(outC_Main));
    pCurrent += sizeof(outC_Main);
#ifdef EXTENDED_SIM
    ExtendedGatherDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

void SsmRestoreDumpData(const char * pData) {
    const char* pCurrent = pData;
    memcpy(&inputs_ctx, pCurrent, sizeof(inC_Main));
    pCurrent += sizeof(inC_Main);

    /* separate_io: restore (not in ctx) inputs */

    /* separate_io: restore (not in ctx) outputs */
    memcpy(&outputs_ctx, pCurrent, sizeof(outC_Main));
    pCurrent += sizeof(outC_Main);
#ifdef EXTENDED_SIM
    ExtendedRestoreDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

int SsmSaveSnapshot(const char * szFilePath, size_t nCycle) {
    return save_snapshot(szFilePath, nCycle,
        &inputs_ctx,
        &outputs_ctx);
}

int SsmLoadSnapshot(const char * szFilePath, size_t *nCycle) {
    return load_snapshot(szFilePath, nCycle,
        &inputs_ctx,
        &outputs_ctx);
}

const char * SsmGetCheckSum() {
    return _SCSIM_CheckSum;
}

const char * SsmGetSmuTypesCheckSum() {
    return _SCSIM_SmuTypesCheckSum;
}

void SsmUpdateValues(void) {
#ifdef EXTENDED_SIM
    UpdateValues();
#endif /* EXTENDED_SIM */
}

void SsmConnectExternalInputs(int bConnect) {
#ifdef EXTENDED_SIM
    GraphicalInputsConnected = bConnect;
#endif /* EXTENDED_SIM */
}

#ifdef __cplusplus
} /* "C" */
#endif
