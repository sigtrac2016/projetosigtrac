/*==============================================================================================
 *
 *  SDY1_specification.h 
 *  -------------------
 *
 *  Copyright (C) 2008-2014 by Esterel Technologies.
 *  All Rights Reserved.
 *
 *  UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
 *============================================================================================*/

#ifndef _SDY1_specification_H
#define _SDY1_specification_H

#include "sdy_events.h"

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API extern
#endif

DLL_API int SDY1_specification__lockio();
DLL_API int SDY1_specification__unlockio();
DLL_API int SDY1_specification__init();
DLL_API int SDY1_specification__draw();
DLL_API int SDY1_specification__cancelled();
DLL_API int SDY1_specification__refreshCallback(T_COSIM_REFRESH_CALLBACK f);

#include "SDY1_specification_symbology_layer.h"
DLL_API SDY1_specification_typ_symbology_layer * SDY1_specification_L_symbology_layer(void);


#endif

