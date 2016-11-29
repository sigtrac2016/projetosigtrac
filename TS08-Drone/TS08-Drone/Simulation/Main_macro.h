#ifndef _MAIN_MACRO_H_
#define _MAIN_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file Main_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "Main.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_Main inputs_ctx;
    outC_Main outputs_ctx;
} WU_Main;
#define WU_CTX_TYPE_Main WU_Main
#define WU_CTX_TYPE_Main_SIZE sizeof(WU_Main)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_Main() 

#define DECLARE_EXT_SENSORS_Main(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_Main_OnButton(context) context.inputs_ctx.OnButton  /* Main/OnButton */
#define VAR_Main_OnButton VARC_Main_OnButton(CTX_Main)

#define VARC_Main_VertSpeedInput(context) context.inputs_ctx.VertSpeedInput  /* Main/VertSpeedInput */
#define VAR_Main_VertSpeedInput VARC_Main_VertSpeedInput(CTX_Main)

#define VARC_Main_HorSpeedInput(context) context.inputs_ctx.HorSpeedInput  /* Main/HorSpeedInput */
#define VAR_Main_HorSpeedInput VARC_Main_HorSpeedInput(CTX_Main)

#define VARC_Main_DirInput(context) context.inputs_ctx.DirInput  /* Main/DirInput */
#define VAR_Main_DirInput VARC_Main_DirInput(CTX_Main)

#define VARC_Main_TkoffButton(context) context.inputs_ctx.TkoffButton  /* Main/TkoffButton */
#define VAR_Main_TkoffButton VARC_Main_TkoffButton(CTX_Main)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_Main_StatusButtonText(context) context.outputs_ctx.StatusButtonText  /* Main/StatusButtonText */
#define VAR_Main_StatusButtonText VARC_Main_StatusButtonText(CTX_Main)

#define VARC_Main_StatusButtonColor(context) context.outputs_ctx.StatusButtonColor  /* Main/StatusButtonColor */
#define VAR_Main_StatusButtonColor VARC_Main_StatusButtonColor(CTX_Main)

#define VARC_Main_Emit(context) context.outputs_ctx.Emit  /* Main/Emit */
#define VAR_Main_Emit VARC_Main_Emit(CTX_Main)

#define VARC_Main_Str_size(context) context.outputs_ctx.Str_size  /* Main/Str_size */
#define VAR_Main_Str_size VARC_Main_Str_size(CTX_Main)

#define VARC_Main_LayerVisible(context) context.outputs_ctx.LayerVisible  /* Main/LayerVisible */
#define VAR_Main_LayerVisible VARC_Main_LayerVisible(CTX_Main)

#define VARC_Main_LayerActive(context) context.outputs_ctx.LayerActive  /* Main/LayerActive */
#define VAR_Main_LayerActive VARC_Main_LayerActive(CTX_Main)

#define VARC_Main_ButtonText(context) context.outputs_ctx.ButtonText  /* Main/ButtonText */
#define VAR_Main_ButtonText VARC_Main_ButtonText(CTX_Main)

#define VARC_Main_VertSpeedOutput(context) context.outputs_ctx.VertSpeedOutput  /* Main/VertSpeedOutput */
#define VAR_Main_VertSpeedOutput VARC_Main_VertSpeedOutput(CTX_Main)

#define VARC_Main_HorSpeedOutput(context) context.outputs_ctx.HorSpeedOutput  /* Main/HorSpeedOutput */
#define VAR_Main_HorSpeedOutput VARC_Main_HorSpeedOutput(CTX_Main)

#define VARC_Main_DirOutput(context) context.outputs_ctx.DirOutput  /* Main/DirOutput */
#define VAR_Main_DirOutput VARC_Main_DirOutput(CTX_Main)

#define VARC_Main_CompassDir(context) context.outputs_ctx.CompassDir  /* Main/CompassDir */
#define VAR_Main_CompassDir VARC_Main_CompassDir(CTX_Main)

#define VARC_Main_TkoffText(context) context.outputs_ctx.TkoffText  /* Main/TkoffText */
#define VAR_Main_TkoffText VARC_Main_TkoffText(CTX_Main)

#define VARC_Main_AltitudeOut(context) context.outputs_ctx.AltitudeOut  /* Main/AltitudeOut */
#define VAR_Main_AltitudeOut VARC_Main_AltitudeOut(CTX_Main)

#define VARC_Main_YawOut(context) context.outputs_ctx.YawOut  /* Main/YawOut */
#define VAR_Main_YawOut VARC_Main_YawOut(CTX_Main)

#define VARC_Main_Latitude(context) context.outputs_ctx.Latitude  /* Main/Latitude */
#define VAR_Main_Latitude VARC_Main_Latitude(CTX_Main)

#define VARC_Main_Longitude(context) context.outputs_ctx.Longitude  /* Main/Longitude */
#define VAR_Main_Longitude VARC_Main_Longitude(CTX_Main)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_OnButton kcg_bool
#define CPY_OnButton(DST, SRC) DST = SRC
#define T_VertSpeedInput _1_float
#define CPY_VertSpeedInput(DST, SRC) DST = SRC
#define T_HorSpeedInput _1_float
#define CPY_HorSpeedInput(DST, SRC) DST = SRC
#define T_DirInput _1_float
#define CPY_DirInput(DST, SRC) DST = SRC
#define T_TkoffButton kcg_bool
#define CPY_TkoffButton(DST, SRC) DST = SRC
#define T_StatusButtonText T_String
#define CPY_StatusButtonText(DST, SRC) kcg_copy_T_String(DST, SRC)
#define T_StatusButtonColor kcg_int
#define CPY_StatusButtonColor(DST, SRC) DST = SRC
#define T_Emit kcg_bool
#define CPY_Emit(DST, SRC) DST = SRC
#define T_Str_size kcg_int
#define CPY_Str_size(DST, SRC) DST = SRC
#define T_LayerVisible kcg_bool
#define CPY_LayerVisible(DST, SRC) DST = SRC
#define T_LayerActive kcg_bool
#define CPY_LayerActive(DST, SRC) DST = SRC
#define T_ButtonText T_String
#define CPY_ButtonText(DST, SRC) kcg_copy_T_String(DST, SRC)
#define T_VertSpeedOutput _1_float
#define CPY_VertSpeedOutput(DST, SRC) DST = SRC
#define T_HorSpeedOutput _1_float
#define CPY_HorSpeedOutput(DST, SRC) DST = SRC
#define T_DirOutput _1_float
#define CPY_DirOutput(DST, SRC) DST = SRC
#define T_CompassDir kcg_real
#define CPY_CompassDir(DST, SRC) DST = SRC
#define T_TkoffText T_String
#define CPY_TkoffText(DST, SRC) kcg_copy_T_String(DST, SRC)
#define T_AltitudeOut kcg_real
#define CPY_AltitudeOut(DST, SRC) DST = SRC
#define T_YawOut kcg_real
#define CPY_YawOut(DST, SRC) DST = SRC
#define T_Latitude kcg_real
#define CPY_Latitude(DST, SRC) DST = SRC
#define T_Longitude kcg_real
#define CPY_Longitude(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_Main(context)  WU_Main context;

#define DECLARE_CTXT_Main() DECLAREC_CTXT_Main(CTX_Main)

#define DECLAREC_EXT_CTXT_Main(MODE , context) MODE WU_Main context;

#define DECLARE_EXT_CTXT_Main(MODE) DECLAREC_EXT_CTXT_Main(MODE , CTX_Main)

#define INITC_Main(context)     #ifndef KCG_USER_DEFINED_INIT\
        Main_init(&context.outputs_ctx);\
    #else\
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET\
            Main_reset(&context.outputs_ctx);\
        #endif\
    #endif
#define INIT_Main() INITC_Main(CTX_Main)

#define PERFORMC_Main(context)     Main( \
        &context.inputs_ctx /* input context */,\
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_Main() PERFORMC_Main(CTX_Main)

/*$************** SCADE Macro wrapper *********************
** End of file Main_macro.h
***********************************************************$*/

#endif /* _MAIN_MACRO_H_ */
