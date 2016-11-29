/* TS08-Drone_mapping.c */

#include <stddef.h>

#include "SmuTypes.h"
#include "SmuMapping.h"
#include "TS08-Drone_type.h"
#include "TS08-Drone_mapping.h"

/* iterators */
extern const MappingIterator iter_array_10;
const MappingIterator iter_array_10 = { "array", 10, 10, NULL};

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) extern const MappingEntry ident##_entries[nb]; extern const MappingScope ident
MAP_DECL(scope_10, 1);
MAP_DECL(scope_9, 11);
MAP_DECL(scope_8, 5);
MAP_DECL(scope_7, 16);
MAP_DECL(scope_6, 3);
MAP_DECL(scope_5, 3);
MAP_DECL(scope_4, 3);
MAP_DECL(scope_3, 6);
MAP_DECL(scope_2, 10);
MAP_DECL(scope_1, 45);
MAP_DECL(scope_0, 1);

/* T_String */
const MappingEntry scope_10_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_array_10, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_10 = {
  "T_String",
  scope_10_entries, 1,
};

/* Main/ MainHorPosControl 1/ */
const MappingEntry scope_9_entries[11] = {
  /* 0 */ { MAP_LOCAL, "@kcg11", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 2},
  /* 1 */ { MAP_LOCAL, "@kcg12", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 3},
  /* 2 */ { MAP_LOCAL, "@kcg13", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 4},
  /* 3 */ { MAP_LOCAL, "@kcg14", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 5},
  /* 4 */ { MAP_OUTPUT, "Latitude", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 0},
  /* 5 */ { MAP_OUTPUT, "Longitude", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 1},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L10_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 9},
  /* 7 */ { MAP_LOCAL, "_L16@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 7},
  /* 8 */ { MAP_LOCAL, "_L21", NULL, sizeof(kcg_real), (size_t)&outputs_ctx._L21_1, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 10},
  /* 9 */ { MAP_LOCAL, "_L3@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 6},
  /* 10 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L8_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 8}
};
const MappingScope scope_9 = {
  "Main/ MainHorPosControl 1/",
  scope_9_entries, 11,
};

/* Main/ MainTakeoff 1/Switch 1/ */
const MappingEntry scope_8_entries[5] = {
  /* 0 */ { MAP_LOCAL, "@kcg10", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L1_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 2},
  /* 1 */ { MAP_LOCAL, "@kcg9", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 1},
  /* 2 */ { MAP_LOCAL, "_L1@mem", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L1_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 3},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 4},
  /* 4 */ { MAP_OUTPUT, "output", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_8 = {
  "Main/ MainTakeoff 1/Switch 1/",
  scope_8_entries, 5,
};

/* Main/ MainTakeoff 1/ */
const MappingEntry scope_7_entries[16] = {
  /* 0 */ { MAP_LOCAL, "@kcg3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 2},
  /* 1 */ { MAP_LOCAL, "@kcg4", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.AltitudeOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 3},
  /* 2 */ { MAP_LOCAL, "@kcg5", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 4},
  /* 3 */ { MAP_LOCAL, "@kcg6", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L32_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 5},
  /* 4 */ { MAP_LOCAL, "@kcg7", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 6},
  /* 5 */ { MAP_LOCAL, "@kcg8", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L49_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 7},
  /* 6 */ { MAP_OUTPUT, "Altitude", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.AltitudeOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 1},
  /* 7 */ { MAP_EXPANDED, "Switch 1", NULL, 0, 0, NULL, NULL, NULL, &scope_8, 1, 11},
  /* 8 */ { MAP_OUTPUT, "TakeoffBtnText", NULL, sizeof(T_String), (size_t)&outputs_ctx.TkoffText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 0},
  /* 9 */ { MAP_LOCAL, "_L1", NULL, sizeof(T_String), (size_t)&outputs_ctx.TkoffText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 13},
  /* 10 */ { MAP_LOCAL, "_L26", NULL, sizeof(kcg_real), (size_t)&outputs_ctx._L26_1, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 14},
  /* 11 */ { MAP_LOCAL, "_L32@mem", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L32_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 8},
  /* 12 */ { MAP_LOCAL, "_L34", NULL, sizeof(kcg_real), (size_t)&outputs_ctx._L34_1, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 15},
  /* 13 */ { MAP_LOCAL, "_L41@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.AltitudeOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 9},
  /* 14 */ { MAP_LOCAL, "_L49@mem", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L49_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 10},
  /* 15 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 12}
};
const MappingScope scope_7 = {
  "Main/ MainTakeoff 1/",
  scope_7_entries, 16,
};

/* Main/ MainVariableControl 4/ */
const MappingEntry scope_6_entries[3] = {
  /* 0 */ { MAP_OUTPUT, "VarOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.DirOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 0},
  /* 1 */ { MAP_LOCAL, "_L2", NULL, sizeof(_1_float), (size_t)&outputs_ctx.DirOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 1},
  /* 2 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 2}
};
const MappingScope scope_6 = {
  "Main/ MainVariableControl 4/",
  scope_6_entries, 3,
};

/* Main/ MainVariableControl 3/ */
const MappingEntry scope_5_entries[3] = {
  /* 0 */ { MAP_OUTPUT, "VarOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.HorSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 0},
  /* 1 */ { MAP_LOCAL, "_L2", NULL, sizeof(_1_float), (size_t)&outputs_ctx.HorSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 1},
  /* 2 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 2}
};
const MappingScope scope_5 = {
  "Main/ MainVariableControl 3/",
  scope_5_entries, 3,
};

/* Main/ MainVariableControl 1/ */
const MappingEntry scope_4_entries[3] = {
  /* 0 */ { MAP_OUTPUT, "VarOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.VertSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 0},
  /* 1 */ { MAP_LOCAL, "_L2", NULL, sizeof(_1_float), (size_t)&outputs_ctx.VertSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 1},
  /* 2 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 2}
};
const MappingScope scope_4 = {
  "Main/ MainVariableControl 1/",
  scope_4_entries, 3,
};

/* Main/ MainStatusControl 2/Switch 2/ */
const MappingEntry scope_3_entries[6] = {
  /* 0 */ { MAP_LOCAL, "@kcg1", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 1},
  /* 1 */ { MAP_LOCAL, "@kcg2", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L1_2_2, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 2},
  /* 2 */ { MAP_LOCAL, "_L1@mem", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L1_2_2, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 3},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_2_2, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 4},
  /* 4 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 5},
  /* 5 */ { MAP_OUTPUT, "output", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_2_2, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_3 = {
  "Main/ MainStatusControl 2/Switch 2/",
  scope_3_entries, 6,
};

/* Main/ MainStatusControl 2/ */
const MappingEntry scope_2_entries[10] = {
  /* 0 */ { MAP_OUTPUT, "ButtonText", NULL, sizeof(T_String), (size_t)&outputs_ctx.ButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 2},
  /* 1 */ { MAP_OUTPUT, "On", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 3},
  /* 2 */ { MAP_OUTPUT, "StatusButtonColor", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.StatusButtonColor, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 1},
  /* 3 */ { MAP_OUTPUT, "StatusButtonText", NULL, sizeof(T_String), (size_t)&outputs_ctx.StatusButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 0},
  /* 4 */ { MAP_EXPANDED, "Switch 2", NULL, 0, 0, NULL, NULL, NULL, &scope_3, 1, 4},
  /* 5 */ { MAP_LOCAL, "_L2", NULL, sizeof(T_String), (size_t)&outputs_ctx.ButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 7},
  /* 6 */ { MAP_LOCAL, "_L23", NULL, sizeof(T_String), (size_t)&outputs_ctx.StatusButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 5},
  /* 7 */ { MAP_LOCAL, "_L27", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 8},
  /* 8 */ { MAP_LOCAL, "_L28", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.output_2_2, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 9},
  /* 9 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.StatusButtonColor, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 6}
};
const MappingScope scope_2 = {
  "Main/ MainStatusControl 2/",
  scope_2_entries, 10,
};

/* Main/ Main */
const MappingEntry scope_1_entries[45] = {
  /* 0 */ { MAP_LOCAL, "@kcg0", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 0, 3},
  /* 1 */ { MAP_OUTPUT, "AltitudeOut", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.AltitudeOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 36},
  /* 2 */ { MAP_OUTPUT, "ButtonText", NULL, sizeof(T_String), (size_t)&outputs_ctx.ButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 30},
  /* 3 */ { MAP_OUTPUT, "CompassDir", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.CompassDir, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 34},
  /* 4 */ { MAP_INPUT, "DirInput", NULL, sizeof(_1_float), (size_t)&inputs_ctx.DirInput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 43},
  /* 5 */ { MAP_OUTPUT, "DirOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.DirOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 33},
  /* 6 */ { MAP_OUTPUT, "Emit", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.Emit, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 26},
  /* 7 */ { MAP_EXPANDED, "HorPosControl 1", NULL, 0, 0, NULL, NULL, NULL, &scope_9, 1, 9},
  /* 8 */ { MAP_INPUT, "HorSpeedInput", NULL, sizeof(_1_float), (size_t)&inputs_ctx.HorSpeedInput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 42},
  /* 9 */ { MAP_OUTPUT, "HorSpeedOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.HorSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 32},
  /* 10 */ { MAP_OUTPUT, "Latitude", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 38},
  /* 11 */ { MAP_OUTPUT, "LayerActive", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.LayerActive, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 29},
  /* 12 */ { MAP_OUTPUT, "LayerVisible", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.LayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 28},
  /* 13 */ { MAP_OUTPUT, "Longitude", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 39},
  /* 14 */ { MAP_LOCAL, "On", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 10},
  /* 15 */ { MAP_INPUT, "OnButton", NULL, sizeof(kcg_bool), (size_t)&inputs_ctx.OnButton, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 40},
  /* 16 */ { MAP_OUTPUT, "StatusButtonColor", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.StatusButtonColor, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 25},
  /* 17 */ { MAP_OUTPUT, "StatusButtonText", NULL, sizeof(T_String), (size_t)&outputs_ctx.StatusButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 24},
  /* 18 */ { MAP_EXPANDED, "StatusControl 2", NULL, 0, 0, NULL, NULL, NULL, &scope_2, 1, 4},
  /* 19 */ { MAP_OUTPUT, "Str_size", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.Str_size, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 27},
  /* 20 */ { MAP_EXPANDED, "Takeoff 1", NULL, 0, 0, NULL, NULL, NULL, &scope_7, 1, 8},
  /* 21 */ { MAP_INPUT, "TkoffButton", NULL, sizeof(kcg_bool), (size_t)&inputs_ctx.TkoffButton, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 44},
  /* 22 */ { MAP_OUTPUT, "TkoffText", NULL, sizeof(T_String), (size_t)&outputs_ctx.TkoffText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 35},
  /* 23 */ { MAP_EXPANDED, "VariableControl 1", NULL, 0, 0, NULL, NULL, NULL, &scope_4, 1, 5},
  /* 24 */ { MAP_EXPANDED, "VariableControl 3", NULL, 0, 0, NULL, NULL, NULL, &scope_5, 1, 6},
  /* 25 */ { MAP_EXPANDED, "VariableControl 4", NULL, 0, 0, NULL, NULL, NULL, &scope_6, 1, 7},
  /* 26 */ { MAP_INPUT, "VertSpeedInput", NULL, sizeof(_1_float), (size_t)&inputs_ctx.VertSpeedInput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 41},
  /* 27 */ { MAP_OUTPUT, "VertSpeedOutput", NULL, sizeof(_1_float), (size_t)&outputs_ctx.VertSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 31},
  /* 28 */ { MAP_OUTPUT, "YawOut", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.YawOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 37},
  /* 29 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.Emit, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 11},
  /* 30 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.LayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 12},
  /* 31 */ { MAP_LOCAL, "_L45", NULL, sizeof(T_String), (size_t)&outputs_ctx.StatusButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 15},
  /* 32 */ { MAP_LOCAL, "_L46", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.StatusButtonColor, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 14},
  /* 33 */ { MAP_LOCAL, "_L51", NULL, sizeof(T_String), (size_t)&outputs_ctx.ButtonText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 13},
  /* 34 */ { MAP_LOCAL, "_L54", NULL, sizeof(_1_float), (size_t)&outputs_ctx.VertSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 16},
  /* 35 */ { MAP_LOCAL, "_L56", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 17},
  /* 36 */ { MAP_LOCAL, "_L57", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 18},
  /* 37 */ { MAP_LOCAL, "_L62", NULL, sizeof(_1_float), (size_t)&outputs_ctx.HorSpeedOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 20},
  /* 38 */ { MAP_LOCAL, "_L63", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 19},
  /* 39 */ { MAP_LOCAL, "_L65", NULL, sizeof(_1_float), (size_t)&outputs_ctx.DirOutput, &_Type__1_float_Utils, NULL, NULL, NULL, 1, 22},
  /* 40 */ { MAP_LOCAL, "_L66", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.On, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 21},
  /* 41 */ { MAP_LOCAL, "_L69", NULL, sizeof(T_String), (size_t)&outputs_ctx.TkoffText, &_Type_T_String_Utils, NULL, NULL, &scope_10, 1, 23},
  /* 42 */ { MAP_LOCAL, "_L73@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.AltitudeOut, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 0},
  /* 43 */ { MAP_LOCAL, "_L74@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 2},
  /* 44 */ { MAP_LOCAL, "_L75@mem", NULL, sizeof(kcg_real), (size_t)&outputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 0, 1}
};
const MappingScope scope_1 = {
  "Main/ Main",
  scope_1_entries, 45,
};

/*  */
const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "Main", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0}
};
const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

