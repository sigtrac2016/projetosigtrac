#ifndef TS08_DRONE_SNAPSHOT_API
#define TS08_DRONE_SNAPSHOT_API

#include "Main.h"
#include "stdio.h"

/*********************************************
 * Main Snapshot Save/Load functions
 *********************************************/
extern int save_snapshot(const char *szFilePath, size_t nCycle,
                      inC_Main *inC,
                      outC_Main *outC);
extern int load_snapshot(const char *szFilePath, size_t *nCycle,
                      inC_Main *inC,
                      outC_Main *outC);

/**********************************************
 * Operators context Save/Load sub-functions
 *********************************************/
extern int save_inC_Main(const char *cpath, const inC_Main *pValue, const void *pBaseAddr, FILE *snsFile);
extern int load_inC_Main(inC_Main *pValue, FILE *snsFile);
extern int save_outC_Main(const char *cpath, const outC_Main *pValue, const void *pBaseAddr, FILE *snsFile);
extern int load_outC_Main(outC_Main *pValue, FILE *snsFile);
#endif /*TS08_DRONE_SNAPSHOT_API*/
