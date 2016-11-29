/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/config.txt
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */
#ifndef _Main_H_
#define _Main_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* Main::OnButton */ OnButton;
  _1_float /* Main::VertSpeedInput */ VertSpeedInput;
  _1_float /* Main::HorSpeedInput */ HorSpeedInput;
  _1_float /* Main::DirInput */ DirInput;
  kcg_bool /* Main::TkoffButton */ TkoffButton;
} inC_Main;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  T_String /* Main::StatusButtonText */ StatusButtonText;
  kcg_int /* Main::StatusButtonColor */ StatusButtonColor;
  kcg_bool /* Main::Emit */ Emit;
  kcg_int /* Main::Str_size */ Str_size;
  kcg_bool /* Main::LayerVisible */ LayerVisible;
  kcg_bool /* Main::LayerActive */ LayerActive;
  T_String /* Main::ButtonText */ ButtonText;
  _1_float /* Main::VertSpeedOutput */ VertSpeedOutput;
  _1_float /* Main::HorSpeedOutput */ HorSpeedOutput;
  _1_float /* Main::DirOutput */ DirOutput;
  kcg_real /* Main::CompassDir */ CompassDir;
  T_String /* Main::TkoffText */ TkoffText;
  kcg_real /* Main::AltitudeOut */ AltitudeOut;
  kcg_real /* Main::YawOut */ YawOut;
  kcg_real /* Main::Latitude */ Latitude;
  kcg_real /* Main::Longitude */ Longitude;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Switch::_L1 */ _L1_2_2;
  kcg_bool /* Takeoff::_L49 */ _L49_1;
  kcg_bool /* Takeoff::_L32 */ _L32_1;
  kcg_bool /* Switch::_L1 */ _L1_1_1;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* Switch::output */ output_2_2;
  kcg_real /* Takeoff::_L34 */ _L34_1;
  kcg_real /* Takeoff::_L26 */ _L26_1;
  kcg_bool /* Switch::output */ output_1_1;
  kcg_real /* HorPosControl::_L21 */ _L21_1;
  kcg_bool /* HorPosControl::_L10 */ _L10_1;
  kcg_bool /* HorPosControl::_L8 */ _L8_1;
  kcg_bool /* Main::On */ On;
} outC_Main;

/* ===========  node initialization and cycle functions  =========== */
/* Main */
extern void Main(inC_Main *inC, outC_Main *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Main_reset(outC_Main *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Main_init(outC_Main *outC);
#endif /* KCG_USER_DEFINED_INIT */

#endif /* _Main_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** Main.h
** Generation date: 2016-11-22T21:53:38
*************************************************************$ */

