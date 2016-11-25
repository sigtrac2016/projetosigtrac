#ifndef SOCKET_TEST_SNAPSHOT_API
#define SOCKET_TEST_SNAPSHOT_API

#include "test.h"
#include "stdio.h"

/*********************************************
 * Main Snapshot Save/Load functions
 *********************************************/
extern int save_snapshot(const char *szFilePath, size_t nCycle,
                      inC_test *inC,
                      outC_test *outC);
extern int load_snapshot(const char *szFilePath, size_t *nCycle,
                      inC_test *inC,
                      outC_test *outC);

/**********************************************
 * Operators context Save/Load sub-functions
 *********************************************/
extern int save_inC_test(const char *cpath, const inC_test *pValue, const void *pBaseAddr, FILE *snsFile);
extern int load_inC_test(inC_test *pValue, FILE *snsFile);
extern int save_outC_test(const char *cpath, const outC_test *pValue, const void *pBaseAddr, FILE *snsFile);
extern int load_outC_test(outC_test *pValue, FILE *snsFile);
#endif /*SOCKET_TEST_SNAPSHOT_API*/
