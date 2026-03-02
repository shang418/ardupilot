//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MatlabController.h
//
// Code generated for Simulink model 'ArduCopter_INDIController'.
//
// Model version                  : 15.3
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Mon Mar  2 12:06:25 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef MatlabController_h_
#define MatlabController_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_cmdBus_
#define DEFINED_TYPEDEF_FOR_cmdBus_

struct cmdBus
{
  real32_T roll;
  real32_T pitch;
  real32_T yaw;
  real32_T thr;
  real32_T s_Kg_init[3];
  real32_T yaw_init;
  uint16_T mission_change;
  real32_T waypoints[40];
  uint16_T num_waypoints;
  real32_T RC_pwm[16];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_measureBus_
#define DEFINED_TYPEDEF_FOR_measureBus_

struct measureBus
{
  real32_T omega_Kb[3];
  real32_T EulerAngles[3];
  real32_T q_bg[4];
  real32_T a_Kg[3];
  real32_T a_Kb[3];
  real32_T V_Kg[3];
  real32_T s_Kg[3];
  real32_T s_Kg_origin[3];
  real32_T lla[3];
  real32_T rangefinder[6];
  real32_T V_bat;
  real32_T omega_mot[4];
  real32_T airspeed;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_lindiStateLogicBus_
#define DEFINED_TYPEDEF_FOR_lindiStateLogicBus_

struct lindiStateLogicBus
{
  boolean_T isPscEnabled;
  boolean_T isPosRmEnabled;
  boolean_T isVertPscEnabled;
  boolean_T isGdnceEnabled;
  boolean_T isAttiCmdEnabled;
  boolean_T isManThrEnabled;
  boolean_T isAutoTuneEnabled;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_logConfigBus_
#define DEFINED_TYPEDEF_FOR_logConfigBus_

struct logConfigBus
{
  uint8_T num_signals;
  uint8_T signal_names[42];
  uint8_T batch_name[4];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qtOPi81Z0PeNKhK6m8BK6D_
#define DEFINED_TYPEDEF_FOR_struct_qtOPi81Z0PeNKhK6m8BK6D_

struct struct_qtOPi81Z0PeNKhK6m8BK6D
{
  real_T leanmax;
  real_T yawratemax;
  real_T yawratetc;
  real_T leanfreq;
  real_T leandamp;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aqAVJiCn7Q7l60Rjbt8PeF_
#define DEFINED_TYPEDEF_FOR_struct_aqAVJiCn7Q7l60Rjbt8PeF_

struct struct_aqAVJiCn7Q7l60Rjbt8PeF
{
  real_T u_min;
  real_T u_max;
  real_T u_d;
  real_T W_v[4];
  real_T W_u[4];
  real_T gamma;
  real_T i_max;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ugs9mWbx3yzxr9Hlai4vbC_
#define DEFINED_TYPEDEF_FOR_struct_ugs9mWbx3yzxr9Hlai4vbC_

struct struct_ugs9mWbx3yzxr9Hlai4vbC
{
  real_T min;
  real_T max;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZYhwVd3qjzjnzfxvh0rFF_
#define DEFINED_TYPEDEF_FOR_struct_ZYhwVd3qjzjnzfxvh0rFF_

struct struct_ZYhwVd3qjzjnzfxvh0rFF
{
  real_T k;
  real_T d;
  real_T x[4];
  real_T y[4];
  real_T z[4];
  real_T a[4];
  real_T nx[4];
  real_T ny[4];
  real_T ip;
  real_T kt;
  real_T vb;
  real_T ri;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4zrY8g3d3iqmdlD7egy8yF_
#define DEFINED_TYPEDEF_FOR_struct_4zrY8g3d3iqmdlD7egy8yF_

struct struct_4zrY8g3d3iqmdlD7egy8yF
{
  real_T accumax;
  real_T accdmax;
  real_T veldmax;
  real_T velumax;
  real_T accxymax;
  real_T velxymax;
  real_T veltc;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_t1muYkFBpCsvhMydPIEJxF_
#define DEFINED_TYPEDEF_FOR_struct_t1muYkFBpCsvhMydPIEJxF_

struct struct_t1muYkFBpCsvhMydPIEJxF
{
  real_T pos;
  real_T vel;
  real_T acc;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qICGedPFFAoBhnvBLpv45E_
#define DEFINED_TYPEDEF_FOR_struct_qICGedPFFAoBhnvBLpv45E_

struct struct_qICGedPFFAoBhnvBLpv45E
{
  struct_4zrY8g3d3iqmdlD7egy8yF rm;
  struct_t1muYkFBpCsvhMydPIEJxF k;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_NtPcxvfiabFPvztJKEAsCF_
#define DEFINED_TYPEDEF_FOR_struct_NtPcxvfiabFPvztJKEAsCF_

struct struct_NtPcxvfiabFPvztJKEAsCF
{
  real32_T Delta_nu_expect[4];
  real32_T Delta_nu_expect_1[4];
  real32_T Delta_nu_expect_2[4];
  real32_T Delta_u[4];
  real32_T Delta_u_dt[4];
  real32_T Delta_nu_measure[4];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_FQDHLgBAtRDOWQ2hGYaDb_
#define DEFINED_TYPEDEF_FOR_struct_FQDHLgBAtRDOWQ2hGYaDb_

struct struct_FQDHLgBAtRDOWQ2hGYaDb
{
  real32_T nu_a_T;
  real32_T Delta_nu_a_T;
  real32_T a_T;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tcsVoxHWWcG8JHpG9tGLV_
#define DEFINED_TYPEDEF_FOR_struct_tcsVoxHWWcG8JHpG9tGLV_

struct struct_tcsVoxHWWcG8JHpG9tGLV
{
  real32_T s_g_ref[3];
  real32_T s_g_ref_dt[3];
  real32_T s_g_ref_dt2[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_V8pMP31kiVzbgIz4RGGIpE_
#define DEFINED_TYPEDEF_FOR_struct_V8pMP31kiVzbgIz4RGGIpE_

struct struct_V8pMP31kiVzbgIz4RGGIpE
{
  real32_T s_g[3];
  real32_T s_g_dt[3];
  real32_T s_g_dt2[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_5MoEvP1wEitNEzCSmvsOHE_
#define DEFINED_TYPEDEF_FOR_struct_5MoEvP1wEitNEzCSmvsOHE_

struct struct_5MoEvP1wEitNEzCSmvsOHE
{
  real32_T e_s_g[3];
  real32_T e_s_g_dt[3];
  real32_T e_s_g_dt2[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_QZzCBH5Wz9Uhv0ZDwWvM4_
#define DEFINED_TYPEDEF_FOR_struct_QZzCBH5Wz9Uhv0ZDwWvM4_

struct struct_QZzCBH5Wz9Uhv0ZDwWvM4
{
  real32_T nu[3];
  real32_T nu_ref[3];
  real32_T nu_cntrl[3];
  real32_T nu_measure[3];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DfhVuCanEgyDLemR8wMTB_
#define DEFINED_TYPEDEF_FOR_struct_DfhVuCanEgyDLemR8wMTB_

struct struct_DfhVuCanEgyDLemR8wMTB
{
  struct_tcsVoxHWWcG8JHpG9tGLV reference;
  struct_V8pMP31kiVzbgIz4RGGIpE measure;
  struct_5MoEvP1wEitNEzCSmvsOHE error;
  struct_QZzCBH5Wz9Uhv0ZDwWvM4 pseudo_control;
};

#endif

// Block signals and states (default storage) for system '<Root>'
struct DW {
  real_T NextOutput[4];                // '<S33>/White Noise'
  real32_T s_g_ref[3];                 // '<S4>/Merge3'
  real32_T s_g_ref_dt[3];              // '<S4>/Merge3'
  real32_T s_g_ref_dt2[3];             // '<S4>/Merge3'
  real32_T n_g_des[3];                 // '<S4>/Merge'
  real32_T Add[9];                     // '<S104>/Add'
  real32_T nu[3];                      // '<S13>/Add1'
  real32_T Gain[3];                    // '<S23>/Gain'
  real32_T Delta_factors_G1[4];        // '<S22>/apply learn rate'
  real32_T DiscreteTimeIntegratory_DSTATE[3];// '<S61>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTAT_e[3];// '<S60>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTAT_b[3];// '<S58>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTA_br[9];// '<S59>/Discrete-Time Integrator y' 
  real32_T Delay_DSTATE_a[4];          // '<S25>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE[4];// '<S49>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegratory_dt_DSTA[3];// '<S62>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_DSTA_eg[4];// '<S43>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_j[4];// '<S43>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_DSTAT_f[3];// '<S62>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_DSTA_by[3];// '<S92>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_o[3];// '<S92>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_DSTAT_k[3];// '<S94>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_n[3];// '<S94>/Discrete-Time Integrator y_dt' 
  real32_T UnitDelay1_DSTATE_m[4];     // '<S41>/Unit Delay1'
  real32_T DiscreteTimeIntegratory_dt_D_jl[9];// '<S59>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_DS_l[3];// '<S58>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_DS_g[3];// '<S60>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_D_oh[3];// '<S61>/Discrete-Time Integrator y_dt' 
  real32_T UnitDelay6_DSTATE[3];       // '<S18>/Unit Delay6'
  real32_T DiscreteTimeIntegratory_dt_D_jv[3];
                                      // '<S129>/Discrete-Time Integrator y_dt'
  real32_T DiscreteTimeIntegratory_dt_DS_b[3];
                                      // '<S130>/Discrete-Time Integrator y_dt'
  real32_T DiscreteTimeIntegratory_DSTAT_l[9];// '<S105>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_p[9];
                                      // '<S105>/Discrete-Time Integrator y_dt'
  real32_T DiscreteTimeIntegrator1_DSTATE[3];// '<S12>/Discrete-Time Integrator1' 
  real32_T DiscreteTimeIntegrator_DSTATE_c[2];// '<S96>/Discrete-Time Integrator' 
  real32_T DiscreteTimeIntegratory_DSTA_ez[3];// '<S55>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_DS_h[3];// '<S55>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_D_ln[4];// '<S39>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_dt_DS_d[4];// '<S38>/Discrete-Time Integrator y_dt' 
  real32_T DiscreteTimeIntegratory_DSTA_gd[4];// '<S34>/Discrete-Time Integrator y' 
  real32_T DiscreteTimeIntegratory_dt_D_lq[4];// '<S34>/Discrete-Time Integrator y_dt' 
  real32_T Merge1;                     // '<S4>/Merge1'
  real32_T cmd_lean_angle_01;          // '<S4>/Merge'
  real32_T lean_dir_angle_des;         // '<S4>/Merge'
  real32_T Delta_nu_a_T;           // '<S9>/incremental thrust atti correction'
  real32_T a_T_meas;             // '<S9>/desired and measured specific thrust'
  real32_T Gain1;                      // '<S23>/Gain1'
  real32_T Delta_factors_G2;           // '<S22>/apply learn rate2'
  real32_T UnitDelay1_DSTATE;          // '<S15>/Unit Delay1'
  real32_T DiscreteTimeIntegrator2_DSTATE;// '<S72>/Discrete-Time Integrator2'
  real32_T Delay_DSTATE;               // '<S16>/Delay'
  real32_T Delay1_DSTATE;              // '<S26>/Delay1'
  real32_T DiscreteTimeIntegrator_DSTATE_l;// '<S91>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_k;// '<S97>/Discrete-Time Integrator'
  int32_T UnitDelay_DSTATE_h;          // '<S18>/Unit Delay'
  int32_T UnitDelay1_DSTATE_b;         // '<S18>/Unit Delay1'
  int32_T UnitDelay2_DSTATE;           // '<S18>/Unit Delay2'
  uint32_T RandSeed[4];                // '<S33>/White Noise'
  int8_T DiscreteTimeIntegratory_PrevR_o;// '<S105>/Discrete-Time Integrator y'
  int8_T DiscreteTimeIntegratory_dt_Pr_j;
                                      // '<S105>/Discrete-Time Integrator y_dt'
  int8_T DiscreteTimeIntegrator1_PrevRes;// '<S12>/Discrete-Time Integrator1'
  int8_T DiscreteTimeIntegrator_PrevRe_k;// '<S96>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_m;// '<S97>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegratory_IC_LOAD;// '<S61>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_b;// '<S60>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_L_b1;// '<S59>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegrator2_IC_LOAD;// '<S72>/Discrete-Time Integrator2'
  uint8_T DiscreteTimeIntegratory_IC_LO_m;// '<S62>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_d;// '<S92>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_L_bz;// '<S94>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_L_bc;// '<S129>/Discrete-Time Integrator y' 
  uint8_T DiscreteTimeIntegratory_IC_LO_o;// '<S130>/Discrete-Time Integrator y' 
  uint8_T DiscreteTimeIntegratory_IC_LO_p;// '<S105>/Discrete-Time Integrator y' 
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;// '<S12>/Discrete-Time Integrator1'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S96>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_IC_LOA_h;// '<S97>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegratory_IC_LO_e;// '<S55>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_n;// '<S39>/Discrete-Time Integrator y'
  uint8_T DiscreteTimeIntegratory_IC_LO_f;// '<S38>/Discrete-Time Integrator y'
  boolean_T icLoad;                    // '<S16>/Delay'
  boolean_T WaypointNavigation_MODE;   // '<S4>/Waypoint Navigation'
  boolean_T FlightPathSmoothing_MODE;  // '<S119>/Flight Path Smoothing'
  boolean_T NDIpositioncontrollerforcopters;
             // '<S4>/NDI position controller for copters with reference input'
  boolean_T NDIpositioncontrollerforcopte_i;
                  // '<S4>/NDI position controller for copters reference model'
  boolean_T CopterRandomExcitation_MODE;// '<S21>/Copter Random Excitation'
  boolean_T AdaptiveINDIG1andG2correction_M;
                                  // '<S21>/Adaptive INDI G1 and G2 correction'
};

// Constant parameters (default storage)
struct ConstP {
  // Computed Parameter: MATLABFunction_G10
  //  Referenced by: '<S44>/MATLAB Function'

  real32_T MATLABFunction_G10[16];

  // Computed Parameter: MATLABFunction_G20
  //  Referenced by: '<S44>/MATLAB Function'

  real32_T MATLABFunction_G20[16];
};

// External inputs (root inport signals with default storage)
struct ExtU {
  cmdBus cmd;                          // '<Root>/cmd'
  measureBus measure;                  // '<Root>/measure'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real32_T u[8];                       // '<Root>/u'
  real32_T logs[15];                   // '<Root>/logs'
};

// Constant parameters (default storage)
extern const ConstP rtConstP;

// Exported data declaration

// Const memory section
// Declaration for custom storage class: Const
extern const logConfigBus log_config[5];
                // Referenced by: '<S3>/Const Simulink.Parameter of log config'

// Class declaration for model ArduCopter_INDIController
class MatlabControllerClass
{
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  MatlabControllerClass();

  // Destructor
  ~MatlabControllerClass();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<S9>/DCM 2 Lean Vector'
  static void DCM2LeanVector(const real32_T rtu_M_bg[9], real32_T rty_n_g[3]);

  // private member function(s) for subsystem '<S52>/n ref norm'
  static void nrefnorm(const real32_T rtu_y[3], const real32_T rtu_y_dt[3],
                       const real32_T rtu_y_dt2[3], real32_T rty_n[3], real32_T
                       rty_n_dt[3], real32_T rty_n_dt2[3]);

  // private member function(s) for subsystem '<S63>/DCM to quaternions'
  static void DCMtoquaternions(const real32_T rtu_M_bg[9], real32_T rty_q_bg[4]);

  // private member function(s) for subsystem '<S63>/Quaternion Reduced'
  void QuaternionReduced(const real32_T rtu_q_bg[4], real32_T rty_q_red[4],
    real32_T *rty_yaw);
  real32_T norm(const real32_T x[4]);

  // private member function(s) for subsystem '<S67>/wrap angle'
  static void wrapangle(real32_T rtu_angle, real32_T *rty_angle_0_2pi);

  // private member function(s) for subsystem '<S72>/Lean Vector Derivative Trafo'
  static void LeanVectorDerivativeTrafo(const real32_T rtu_n_g[3], const
    real32_T rtu_n_g_dt[3], const real32_T rtu_n_g_dt2[3], const real32_T
    rtu_M_bg[9], const real32_T rtu_omega_Kb[3], const real32_T rtu_omega_Kb_dt
    [3], real32_T rty_n_b[3], real32_T rty_n_b_dt[3], real32_T rty_n_b_dt2[3]);

  // private member function(s) for subsystem '<Root>'
  real32_T xnrm2(int32_T n, const real32_T x_data[], int32_T ix0);
  void mldivide(const real32_T A_data[], const int32_T A_size[2], const real32_T
                B_0[8], real32_T Y_data[], int32_T *Y_size);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S35>/Add' : Unused code path elimination
//  Block '<S35>/Add1' : Unused code path elimination
//  Block '<S35>/Add2' : Unused code path elimination
//  Block '<S35>/Matrix Multiply' : Unused code path elimination
//  Block '<S35>/Matrix Multiply1' : Unused code path elimination
//  Block '<S35>/Scope' : Unused code path elimination
//  Block '<S35>/Scope1' : Unused code path elimination
//  Block '<S35>/Scope2' : Unused code path elimination
//  Block '<S35>/Unit Delay' : Unused code path elimination
//  Block '<S37>/Constant' : Unused code path elimination
//  Block '<S37>/Scope' : Unused code path elimination
//  Block '<S4>/Constant' : Unused code path elimination
//  Block '<S8>/Gain' : Unused code path elimination
//  Block '<S13>/Gain' : Unused code path elimination
//  Block '<S13>/Gain1' : Unused code path elimination
//  Block '<S106>/Data Type Duplicate' : Unused code path elimination
//  Block '<S106>/Data Type Propagation' : Unused code path elimination
//  Block '<S107>/Data Type Duplicate' : Unused code path elimination
//  Block '<S107>/Data Type Propagation' : Unused code path elimination
//  Block '<S18>/Data Type Conversion8' : Unused code path elimination
//  Block '<S18>/Data Type Conversion9' : Unused code path elimination
//  Block '<S128>/Discrete-Time Integrator y' : Unused code path elimination
//  Block '<S128>/Discrete-Time Integrator y_dt' : Unused code path elimination
//  Block '<S128>/Divide' : Unused code path elimination
//  Block '<S128>/Gain' : Unused code path elimination
//  Block '<S128>/Product1' : Unused code path elimination
//  Block '<S128>/Product2' : Unused code path elimination
//  Block '<S128>/Saturation' : Unused code path elimination
//  Block '<S128>/Sum2' : Unused code path elimination
//  Block '<S128>/Sum3' : Unused code path elimination
//  Block '<S128>/omega^2' : Unused code path elimination
//  Block '<S128>/y_dt_0' : Unused code path elimination
//  Block '<S126>/Scope' : Unused code path elimination
//  Block '<S126>/Scope1' : Unused code path elimination
//  Block '<S126>/Scope2' : Unused code path elimination
//  Block '<S126>/Scope3' : Unused code path elimination
//  Block '<S18>/Scope1' : Unused code path elimination
//  Block '<S22>/Reshape3' : Reshape block reduction
//  Block '<S34>/Saturation' : Eliminated Saturate block
//  Block '<S38>/Saturation' : Eliminated Saturate block
//  Block '<S39>/Saturation' : Eliminated Saturate block
//  Block '<S49>/Saturation' : Eliminated Saturate block
//  Block '<S43>/Saturation' : Eliminated Saturate block
//  Block '<S55>/Saturation' : Eliminated Saturate block
//  Block '<S58>/Saturation' : Eliminated Saturate block
//  Block '<S59>/Saturation' : Eliminated Saturate block
//  Block '<S60>/Saturation' : Eliminated Saturate block
//  Block '<S61>/Saturation' : Eliminated Saturate block
//  Block '<S62>/Saturation' : Eliminated Saturate block
//  Block '<S11>/Reshape1' : Reshape block reduction
//  Block '<S11>/Reshape2' : Reshape block reduction
//  Block '<S72>/Gain1' : Eliminated nontunable gain of 1
//  Block '<S72>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S91>/Saturation' : Eliminated Saturate block
//  Block '<S92>/Saturation' : Eliminated Saturate block
//  Block '<S94>/Saturation' : Eliminated Saturate block
//  Block '<S72>/Reshape' : Reshape block reduction
//  Block '<S105>/Saturation' : Eliminated Saturate block
//  Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S18>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S18>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S18>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S129>/Saturation' : Eliminated Saturate block
//  Block '<S130>/Saturation' : Eliminated Saturate block
//  Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S8>/Constant' : Unused code path elimination
//  Block '<S123>/Constant' : Unused code path elimination
//  Block '<S123>/Constant1' : Unused code path elimination
//  Block '<S123>/Divide' : Unused code path elimination
//  Block '<S123>/Max' : Unused code path elimination
//  Block '<S123>/Square' : Unused code path elimination
//  Block '<S123>/wp_rad_min' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ArduCopter_INDIController'
//  '<S1>'   : 'ArduCopter_INDIController/Actuator muxer'
//  '<S2>'   : 'ArduCopter_INDIController/INDI Controller'
//  '<S3>'   : 'ArduCopter_INDIController/log muxer'
//  '<S4>'   : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot'
//  '<S5>'   : 'ArduCopter_INDIController/INDI Controller/pick feedback variables'
//  '<S6>'   : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Accelerations to Reduced Attitude and Thrust'
//  '<S7>'   : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune'
//  '<S8>'   : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation'
//  '<S9>'   : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust'
//  '<S10>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering'
//  '<S11>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller'
//  '<S12>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model'
//  '<S13>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input'
//  '<S14>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Pilot Reduced Attitude Commands'
//  '<S15>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/State Logic Bus'
//  '<S16>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Stick Command Bus'
//  '<S17>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Vertical Acc to Specific Thrust'
//  '<S18>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation'
//  '<S19>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Accelerations to Reduced Attitude and Thrust/INDI Copter Acc 2 Lean Vector'
//  '<S20>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Accelerations to Reduced Attitude and Thrust/MATLAB Function4'
//  '<S21>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune'
//  '<S22>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction'
//  '<S23>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Copter Random Excitation'
//  '<S24>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check'
//  '<S25>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/accumulate G1 correction factors'
//  '<S26>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/accumulate G2 correction factor'
//  '<S27>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/create diag'
//  '<S28>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction/G1 learn rate'
//  '<S29>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction/G2 learn rate'
//  '<S30>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction/Gradient of Delta_nu w.r.t. G1 correction factors'
//  '<S31>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction/Gradient of Delta_nu w.r.t. G2 correction factor'
//  '<S32>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Adaptive INDI G1 and G2 correction/Inversion error'
//  '<S33>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Copter Random Excitation/Band-Limited White Noise'
//  '<S34>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/Copter Random Excitation/PT2 discrete with saturation'
//  '<S35>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check/Inversion forward'
//  '<S36>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check/filtered Delta nu'
//  '<S37>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check/filtered Delta u'
//  '<S38>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check/filtered Delta nu/PT2 discrete with saturation1'
//  '<S39>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Autotune/Copter INDI Autotune/INDI Inversion Check/filtered Delta u/PT2 discrete with saturation'
//  '<S40>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/Control Allocation Vertical Acc Weighting'
//  '<S41>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/INDI high level wls control allocation'
//  '<S42>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/Motor dynamics model'
//  '<S43>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/Sensor filter model'
//  '<S44>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/control effectiveness'
//  '<S45>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/INDI high level wls control allocation/INDI control allocation'
//  '<S46>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/INDI high level wls control allocation/Set Desired Motor Command'
//  '<S47>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/INDI high level wls control allocation/Set Vertical Acc Weight To Zero'
//  '<S48>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/INDI high level wls control allocation/INDI control allocation/caIndiWls'
//  '<S49>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/Motor dynamics model/PT1 discrete with saturations'
//  '<S50>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Copter Inner Loop INDI and Control Allocation/control effectiveness/MATLAB Function'
//  '<S51>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/DCM 2 Lean Vector'
//  '<S52>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/PT2 Lean Vector'
//  '<S53>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/desired and measured specific thrust'
//  '<S54>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/incremental thrust atti correction'
//  '<S55>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/PT2 Lean Vector/PT2 discrete with saturation'
//  '<S56>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Incremental specific thrust/PT2 Lean Vector/n ref norm'
//  '<S57>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/MATLAB Function'
//  '<S58>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/PT2 discrete with saturation'
//  '<S59>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/PT2 discrete with saturation1'
//  '<S60>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/PT2 discrete with saturation2'
//  '<S61>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/PT2 discrete with saturation3'
//  '<S62>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/PT2 discrete with saturation4'
//  '<S63>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/measured yaw'
//  '<S64>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/measured yaw/DCM to quaternions'
//  '<S65>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Measurement Filtering/measured yaw/Quaternion Reduced'
//  '<S66>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/Reduced Attitude Scheduler'
//  '<S67>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/error computation'
//  '<S68>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/measure'
//  '<S69>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/ny control'
//  '<S70>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/ny from reference'
//  '<S71>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/ny measured'
//  '<S72>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model'
//  '<S73>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/Reduced Attitude Scheduler/Reduced Attitude Weighting Factors'
//  '<S74>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/error computation/angle error'
//  '<S75>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/error computation/wrap angle'
//  '<S76>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/error computation/wrap angle1'
//  '<S77>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/measure/DCM to quaternions'
//  '<S78>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/measure/Quaternion Reduced'
//  '<S79>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Desired Roll Pitch'
//  '<S80>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Lean Angle Limiter'
//  '<S81>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Lean Vector Derivative Trafo'
//  '<S82>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Lean Vector Derivative Trafo Delay'
//  '<S83>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Lean Vector Derivative to Omega'
//  '<S84>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/MATLAB Function'
//  '<S85>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT1 discrete reference model2'
//  '<S86>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector'
//  '<S87>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector1'
//  '<S88>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Pseudo-Control Roll Pitch'
//  '<S89>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/Simulink Trickster'
//  '<S90>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/lean angles 2 lean vector'
//  '<S91>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT1 discrete reference model2/PT1 discrete with saturations'
//  '<S92>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector/PT2 discrete with saturation'
//  '<S93>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector/n ref norm'
//  '<S94>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector1/PT2 discrete with saturation'
//  '<S95>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Multicopter (Reduced) Attitude INDI Controller/reference model/PT2 Lean Vector1/n ref norm'
//  '<S96>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/PT1 discrete with saturation horizontal'
//  '<S97>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/PT1 discrete with saturation vertical'
//  '<S98>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/Stick RollPitch to limited RollPitch'
//  '<S99>'  : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/cmd_throttle to vertical_velocity'
//  '<S100>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/Stick RollPitch to limited RollPitch/Stick RollPitch to Lean Command'
//  '<S101>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/Stick RollPitch to limited RollPitch/Stick RollPitch to Lean Command/stickRP2LeanCmd'
//  '<S102>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters reference model/cmd_throttle to vertical_velocity/MATLAB Function'
//  '<S103>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/measures'
//  '<S104>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller'
//  '<S105>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller/PT2 discrete with saturation1'
//  '<S106>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller/Saturation Dynamic'
//  '<S107>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller/Saturation Dynamic1'
//  '<S108>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller/acccntrlmax'
//  '<S109>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/NDI position controller for copters with reference input/position controller/eposmax'
//  '<S110>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Pilot Reduced Attitude Commands/MATLAB Function'
//  '<S111>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Pilot Reduced Attitude Commands/MATLAB Function1'
//  '<S112>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/State Logic Bus/Compare To Zero'
//  '<S113>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/State Logic Bus/LindiCopter State Logic'
//  '<S114>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Stick Command Bus/MATLAB Function'
//  '<S115>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Stick Command Bus/MATLAB Function1'
//  '<S116>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Stick Command Bus/throttle_-1_1 to throttle_0_1'
//  '<S117>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Vertical Acc to Specific Thrust/MATLAB Function'
//  '<S118>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Avoid zero speed'
//  '<S119>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing'
//  '<S120>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Look Ahead'
//  '<S121>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Look Ahead1'
//  '<S122>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Split waypoints and velocity'
//  '<S123>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Waypoint radius'
//  '<S124>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/WpNav Matching'
//  '<S125>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Compare To Constant'
//  '<S126>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Flight Path Smoothing'
//  '<S127>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Pass-through'
//  '<S128>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Flight Path Smoothing/PT2 discrete with saturation3'
//  '<S129>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Flight Path Smoothing/PT2 discrete with saturation4'
//  '<S130>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Flight Path Smoothing/Flight Path Smoothing/PT2 discrete with saturation5'
//  '<S131>' : 'ArduCopter_INDIController/INDI Controller/LindiCopter Autopilot/Waypoint Navigation/Waypoint radius/MATLAB Function'
//  '<S132>' : 'ArduCopter_INDIController/INDI Controller/pick feedback variables/Euler Angles to Rotation Matrix'
//  '<S133>' : 'ArduCopter_INDIController/INDI Controller/pick feedback variables/accelerometer'
//  '<S134>' : 'ArduCopter_INDIController/log muxer/Auxiliary function to define log_config in generated C++ code'

#endif                                 // MatlabController_h_

//
// File trailer for generated code.
//
// [EOF]
//
