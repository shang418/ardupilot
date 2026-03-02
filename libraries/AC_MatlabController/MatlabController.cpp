//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MatlabController.cpp
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
#include "MatlabController.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>

// Exported data definition

// Const memory section
// Definition for custom storage class: Const
const logConfigBus log_config[5] = { {
    14U,

    { 115U, 49U, 1U, 115U, 50U, 1U, 115U, 51U, 1U, 115U, 52U, 1U, 115U, 53U, 1U,
      115U, 54U, 1U, 115U, 55U, 1U, 115U, 56U, 1U, 115U, 57U, 1U, 115U, 49U, 48U,
      115U, 49U, 49U, 115U, 49U, 50U, 115U, 49U, 51U, 115U, 49U, 52U },

    { 77U, 76U, 49U, 0U }
  }, { 1U,
    { 115U, 49U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U },

    { 77U, 76U, 50U, 0U }
  }, { 0U,
    { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U },

    { 77U, 76U, 51U, 0U }
  }, { 0U,
    { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U },

    { 77U, 76U, 52U, 0U }
  }, { 0U,
    { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U },

    { 77U, 76U, 53U, 0U }
  } } ;         // Referenced by: '<S3>/Const Simulink.Parameter of log config'

extern real32_T rt_hypotf(real32_T u0, real32_T u1);
extern real32_T rt_roundf(real32_T u);
extern real_T rt_urand_Upu32_Yd_f_pw(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw(uint32_T *u);

//
// Output and update for atomic system:
//    '<S9>/DCM 2 Lean Vector'
//    '<S10>/MATLAB Function'
//
void MatlabControllerClass::DCM2LeanVector(const real32_T rtu_M_bg[9], real32_T
  rty_n_g[3])
{
  for (int32_T i = 0; i < 3; i++) {
    rty_n_g[i] = 0.0F - rtu_M_bg[3 * i + 2];
  }
}

//
// Output and update for atomic system:
//    '<S52>/n ref norm'
//    '<S86>/n ref norm'
//    '<S87>/n ref norm'
//
void MatlabControllerClass::nrefnorm(const real32_T rtu_y[3], const real32_T
  rtu_y_dt[3], const real32_T rtu_y_dt2[3], real32_T rty_n[3], real32_T
  rty_n_dt[3], real32_T rty_n_dt2[3])
{
  real_T n_dt2_idx_0;
  real_T n_dt2_idx_1;
  real32_T scale_0[9];
  real32_T absxk;
  real32_T c_xyz;
  real32_T c_xyz_tmp;
  real32_T c_xyz_tmp_0;
  real32_T c_xyz_tmp_1;
  real32_T c_xyz_tmp_2;
  real32_T f_B;
  real32_T g_B;
  real32_T n_dt2_idx_0_tmp;
  real32_T n_dt2_idx_0_tmp_0;
  real32_T n_dt2_idx_0_tmp_1;
  real32_T n_dt2_idx_0_tmp_2;
  real32_T norm_n;
  real32_T norm_n_tmp;
  real32_T norm_n_tmp_0;
  real32_T norm_n_tmp_1;
  real32_T norm_n_tmp_2;
  real32_T scale;
  real32_T scale_tmp;
  real32_T scale_tmp_0;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = std::abs(rtu_y[0]);
  if (absxk > 1.29246971E-26F) {
    norm_n = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    norm_n = t * t;
  }

  absxk = std::abs(rtu_y[1]);
  if (absxk > scale) {
    t = scale / absxk;
    norm_n = norm_n * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_n += t * t;
  }

  absxk = std::abs(rtu_y[2]);
  if (absxk > scale) {
    t = scale / absxk;
    norm_n = norm_n * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    norm_n += t * t;
  }

  norm_n = scale * std::sqrt(norm_n);
  if (norm_n < 2.22044605E-16F) {
    norm_n = 2.22044605E-16F;
  }

  rty_n[0] = rtu_y[0] / norm_n;
  rty_n[1] = rtu_y[1] / norm_n;
  rty_n[2] = rtu_y[2] / norm_n;
  norm_n_tmp = rtu_y[1] * rtu_y[1];
  norm_n_tmp_0 = rtu_y[2] * rtu_y[2];
  absxk = rtu_y[0] * rtu_y[0];
  norm_n_tmp_1 = absxk + norm_n_tmp;
  norm_n_tmp_2 = norm_n_tmp_1 + norm_n_tmp_0;
  norm_n = std::pow(norm_n_tmp_2, 1.5F);
  scale = norm_n;
  if (norm_n < 2.22044605E-16F) {
    scale = 2.22044605E-16F;
  }

  scale = 1.0F / scale;
  scale_0[0] = (norm_n_tmp + norm_n_tmp_0) * scale;
  scale_tmp = -rtu_y[0] * rtu_y[1] * scale;
  scale_0[3] = scale_tmp;
  t = -rtu_y[0] * rtu_y[2];
  scale_tmp_0 = t * scale;
  scale_0[6] = scale_tmp_0;
  scale_0[1] = scale_tmp;
  scale_tmp = absxk + norm_n_tmp_0;
  scale_0[4] = scale_tmp * scale;
  norm_n_tmp_0 = -rtu_y[1] * rtu_y[2] * scale;
  scale_0[7] = norm_n_tmp_0;
  scale_0[2] = scale_tmp_0;
  scale_0[5] = norm_n_tmp_0;
  scale_0[8] = norm_n_tmp_1 * scale;
  rty_n_dt[0] = 0.0F;
  rty_n_dt[1] = 0.0F;
  rty_n_dt[2] = 0.0F;
  scale = rty_n_dt[0];
  norm_n_tmp_1 = rty_n_dt[1];
  scale_tmp_0 = rty_n_dt[2];
  for (int32_T i = 0; i < 3; i++) {
    norm_n_tmp_0 = rtu_y_dt[i];
    scale += scale_0[3 * i] * norm_n_tmp_0;
    norm_n_tmp_1 += scale_0[3 * i + 1] * norm_n_tmp_0;
    scale_tmp_0 += scale_0[3 * i + 2] * norm_n_tmp_0;
  }

  rty_n_dt[2] = scale_tmp_0;
  rty_n_dt[1] = norm_n_tmp_1;
  rty_n_dt[0] = scale;
  scale = norm_n;
  if (norm_n < 2.22044605E-16F) {
    scale = 2.22044605E-16F;
  }

  rty_n_dt[2] = ((rtu_y[1] * rtu_y_dt[2] - rtu_y_dt[1] * rtu_y[2]) * rtu_y[1] +
                 (t * rtu_y_dt[0] + absxk * rtu_y_dt[2])) * (1.0F / scale);
  t = norm_n;
  c_xyz_tmp = 2.0F * rtu_y[0];
  c_xyz_tmp_0 = 2.0F * rtu_y[1];
  c_xyz_tmp_1 = 2.0F * rtu_y[2];
  norm_n_tmp_1 = c_xyz_tmp_1 * rtu_y_dt[2];
  scale_tmp_0 = c_xyz_tmp * rtu_y_dt[0];
  norm_n_tmp_0 = c_xyz_tmp_0 * rtu_y_dt[1];
  c_xyz_tmp_2 = (scale_tmp_0 + norm_n_tmp_0) + norm_n_tmp_1;
  absxk = 4.0F * std::pow(norm_n_tmp_2, 2.5F);
  f_B = absxk;
  c_xyz = 2.0F * norm_n;
  g_B = c_xyz;
  scale = std::sqrt(norm_n_tmp_2);
  norm_n_tmp_2 = scale;
  if (scale < 2.22044605E-16F) {
    norm_n_tmp_2 = 2.22044605E-16F;
  }

  if (norm_n < 2.22044605E-16F) {
    t = 2.22044605E-16F;
  }

  if (absxk < 2.22044605E-16F) {
    f_B = 2.22044605E-16F;
  }

  if (c_xyz < 2.22044605E-16F) {
    g_B = 2.22044605E-16F;
  }

  n_dt2_idx_0_tmp = c_xyz_tmp_2 * c_xyz_tmp_2 * 3.0F;
  c_xyz_tmp_0 *= rtu_y_dt2[1];
  n_dt2_idx_0_tmp_0 = rtu_y_dt[1] * rtu_y_dt[1] * 2.0F;
  c_xyz_tmp *= rtu_y_dt2[0];
  n_dt2_idx_0_tmp_1 = rtu_y_dt[0] * rtu_y_dt[0] * 2.0F;
  c_xyz_tmp_1 *= rtu_y_dt2[2];
  n_dt2_idx_0_tmp_2 = rtu_y_dt[2] * rtu_y_dt[2] * 2.0F;
  n_dt2_idx_0 = (n_dt2_idx_0_tmp / f_B - (((((c_xyz_tmp + n_dt2_idx_0_tmp_1) +
    c_xyz_tmp_0) + n_dt2_idx_0_tmp_0) + c_xyz_tmp_1) + n_dt2_idx_0_tmp_2) / g_B)
    * rtu_y[0] + (rtu_y_dt2[0] / norm_n_tmp_2 - c_xyz_tmp_2 * rtu_y_dt[0] / t);
  if (scale < 2.22044605E-16F) {
    scale = 2.22044605E-16F;
  }

  if (norm_n < 2.22044605E-16F) {
    norm_n = 2.22044605E-16F;
  }

  if (absxk < 2.22044605E-16F) {
    absxk = 2.22044605E-16F;
  }

  if (c_xyz < 2.22044605E-16F) {
    c_xyz = 2.22044605E-16F;
  }

  n_dt2_idx_1 = (n_dt2_idx_0_tmp / absxk - (((((c_xyz_tmp_0 + n_dt2_idx_0_tmp_0)
    + c_xyz_tmp) + n_dt2_idx_0_tmp_1) + c_xyz_tmp_1) + n_dt2_idx_0_tmp_2) /
                 c_xyz) * rtu_y[1] + (rtu_y_dt2[1] / scale - c_xyz_tmp_2 *
    rtu_y_dt[1] / norm_n);
  c_xyz = scale_tmp + norm_n_tmp;
  norm_n = std::pow(c_xyz, 1.5F);
  scale = (norm_n_tmp_1 + scale_tmp_0) + norm_n_tmp_0;
  absxk = 4.0F * std::pow(c_xyz, 2.5F);
  t = 2.0F * norm_n;
  c_xyz = std::sqrt(c_xyz);
  if (c_xyz < 2.22044605E-16F) {
    c_xyz = 2.22044605E-16F;
  }

  if (norm_n < 2.22044605E-16F) {
    norm_n = 2.22044605E-16F;
  }

  if (absxk < 2.22044605E-16F) {
    absxk = 2.22044605E-16F;
  }

  if (t < 2.22044605E-16F) {
    t = 2.22044605E-16F;
  }

  rty_n_dt2[0] = static_cast<real32_T>(n_dt2_idx_0);
  rty_n_dt2[1] = static_cast<real32_T>(n_dt2_idx_1);
  rty_n_dt2[2] = (scale * scale * 3.0F / absxk - (((((c_xyz_tmp_1 +
    n_dt2_idx_0_tmp_2) + c_xyz_tmp) + n_dt2_idx_0_tmp_1) + c_xyz_tmp_0) +
    n_dt2_idx_0_tmp_0) / t) * rtu_y[2] + (rtu_y_dt2[2] / c_xyz - scale *
    rtu_y_dt[2] / norm_n);
}

//
// Output and update for atomic system:
//    '<S63>/DCM to quaternions'
//    '<S68>/DCM to quaternions'
//
void MatlabControllerClass::DCMtoquaternions(const real32_T rtu_M_bg[9],
  real32_T rty_q_bg[4])
{
  int32_T iindx;
  real32_T ex;
  real32_T q_0;
  real32_T q_1;
  real32_T q_2;
  real32_T q_3;
  q_3 = ((rtu_M_bg[0] + 1.0F) + rtu_M_bg[4]) + rtu_M_bg[8];
  if (q_3 <= 0.0F) {
    q_3 = 0.0F;
  }

  q_0 = 0.5F * std::sqrt(q_3);
  q_3 = ((rtu_M_bg[0] + 1.0F) - rtu_M_bg[4]) - rtu_M_bg[8];
  if (q_3 <= 0.0F) {
    q_3 = 0.0F;
  }

  q_1 = 0.5F * std::sqrt(q_3);
  q_3 = ((1.0F - rtu_M_bg[0]) + rtu_M_bg[4]) - rtu_M_bg[8];
  if (q_3 <= 0.0F) {
    q_3 = 0.0F;
  }

  q_2 = 0.5F * std::sqrt(q_3);
  q_3 = ((1.0F - rtu_M_bg[0]) - rtu_M_bg[4]) + rtu_M_bg[8];
  if (q_3 <= 0.0F) {
    q_3 = 0.0F;
  }

  q_3 = 0.5F * std::sqrt(q_3);
  ex = q_0;
  iindx = 0;
  if (q_0 < q_1) {
    ex = q_1;
    iindx = 1;
  }

  if (ex < q_2) {
    ex = q_2;
    iindx = 2;
  }

  if (ex < q_3) {
    iindx = 3;
  }

  switch (iindx) {
   case 0:
    ex = rtu_M_bg[7] - rtu_M_bg[5];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_1 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[2] - rtu_M_bg[6];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_2 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[3] - rtu_M_bg[1];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_3 *= static_cast<real32_T>(iindx);
    break;

   case 1:
    ex = rtu_M_bg[7] - rtu_M_bg[5];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_0 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[1] + rtu_M_bg[3];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_2 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[2] + rtu_M_bg[6];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_3 *= static_cast<real32_T>(iindx);
    break;

   case 2:
    ex = rtu_M_bg[2] - rtu_M_bg[6];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_0 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[1] + rtu_M_bg[3];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_1 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[5] + rtu_M_bg[7];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_3 *= static_cast<real32_T>(iindx);
    break;

   default:
    ex = rtu_M_bg[3] - rtu_M_bg[1];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_0 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[2] + rtu_M_bg[6];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_1 *= static_cast<real32_T>(iindx);
    ex = rtu_M_bg[5] + rtu_M_bg[7];
    if (ex < 0.0F) {
      iindx = -1;
    } else {
      iindx = (ex > 0.0F);
    }

    q_2 *= static_cast<real32_T>(iindx);
    break;
  }

  rty_q_bg[0] = q_0;
  rty_q_bg[1] = q_1;
  rty_q_bg[2] = q_2;
  rty_q_bg[3] = q_3;
  q_1 = 1.29246971E-26F;
  q_2 = std::abs(rty_q_bg[0]);
  if (q_2 > 1.29246971E-26F) {
    q_0 = 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / 1.29246971E-26F;
    q_0 = q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[1]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[2]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_2 = std::abs(rty_q_bg[3]);
  if (q_2 > q_1) {
    q_3 = q_1 / q_2;
    q_0 = q_0 * q_3 * q_3 + 1.0F;
    q_1 = q_2;
  } else {
    q_3 = q_2 / q_1;
    q_0 += q_3 * q_3;
  }

  q_0 = q_1 * std::sqrt(q_0);
  if (q_0 <= 2.22044605E-16F) {
    q_0 = 2.22044605E-16F;
  }

  rty_q_bg[0] /= q_0;
  rty_q_bg[1] /= q_0;
  rty_q_bg[2] /= q_0;
  rty_q_bg[3] /= q_0;
}

// Function for MATLAB Function: '<S63>/Quaternion Reduced'
real32_T MatlabControllerClass::norm(const real32_T x[4])
{
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  scale = 1.29246971E-26F;
  absxk = std::abs(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

//
// Output and update for atomic system:
//    '<S63>/Quaternion Reduced'
//    '<S68>/Quaternion Reduced'
//
void MatlabControllerClass::QuaternionReduced(const real32_T rtu_q_bg[4],
  real32_T rty_q_red[4], real32_T *rty_yaw)
{
  int32_T tmp;
  real32_T q_yaw[4];
  real32_T M_bg_idx_2;
  real32_T q0_q0;
  real32_T q1_q1;
  real32_T q2_q2;
  real32_T q_bg_idx_0;
  real32_T q_bg_idx_2;
  real32_T q_bg_idx_3;
  q0_q0 = norm(rtu_q_bg);
  if (q0_q0 <= 2.22044605E-16F) {
    q0_q0 = 2.22044605E-16F;
  }

  q_bg_idx_0 = rtu_q_bg[0] / q0_q0;
  q2_q2 = rtu_q_bg[1] / q0_q0;
  q_bg_idx_2 = rtu_q_bg[2] / q0_q0;
  q_bg_idx_3 = rtu_q_bg[3] / q0_q0;
  M_bg_idx_2 = (q2_q2 * q_bg_idx_3 + q_bg_idx_0 * q_bg_idx_2) * 2.0F;
  q1_q1 = ((q_bg_idx_0 * q_bg_idx_0 - q2_q2 * q2_q2) - q_bg_idx_2 * q_bg_idx_2)
    + q_bg_idx_3 * q_bg_idx_3;
  if (q1_q1 >= 1.0F) {
    q1_q1 = 1.0F;
  }

  if (q1_q1 <= -1.0F) {
    q1_q1 = -1.0F;
  }

  q0_q0 = std::acos(q1_q1);
  q1_q1 = std::sin(q0_q0);
  q1_q1 = q1_q1 * q1_q1 - M_bg_idx_2 * M_bg_idx_2;
  if ((q_bg_idx_2 * q_bg_idx_3 - q_bg_idx_0 * q2_q2) * 2.0F >= 0.0F) {
    tmp = -1;
  } else {
    tmp = 1;
  }

  if (q1_q1 <= 0.0F) {
    q1_q1 = 0.0F;
  }

  q1_q1 = std::atan2(static_cast<real32_T>(tmp) * std::sqrt(q1_q1), -M_bg_idx_2);
  q_bg_idx_0 = q0_q0 / 2.0F;
  q2_q2 = std::sin(q_bg_idx_0);
  rty_q_red[0] = std::cos(q_bg_idx_0);
  rty_q_red[1] = std::sin(q1_q1) * q2_q2;
  rty_q_red[2] = -std::cos(q1_q1) * q2_q2;
  rty_q_red[3] = 0.0F;
  q0_q0 = ((rty_q_red[0] * rty_q_red[0] + rty_q_red[1] * rty_q_red[1]) +
           rty_q_red[2] * rty_q_red[2]) + rty_q_red[3] * rty_q_red[3];
  if (q0_q0 <= 2.22044605E-16F) {
    q0_q0 = 2.22044605E-16F;
  }

  q_bg_idx_0 = rty_q_red[0] / q0_q0;
  q2_q2 = -rty_q_red[1] / q0_q0;
  q_bg_idx_2 = -rty_q_red[2] / q0_q0;
  q_bg_idx_3 = -rty_q_red[3] / q0_q0;
  q_yaw[0] = ((q_bg_idx_0 * rtu_q_bg[0] - q2_q2 * rtu_q_bg[1]) - q_bg_idx_2 *
              rtu_q_bg[2]) - q_bg_idx_3 * rtu_q_bg[3];
  q_yaw[1] = (q_bg_idx_0 * rtu_q_bg[1] + rtu_q_bg[0] * q2_q2) + (q_bg_idx_2 *
    rtu_q_bg[3] - rtu_q_bg[2] * q_bg_idx_3);
  q_yaw[2] = (q_bg_idx_0 * rtu_q_bg[2] + rtu_q_bg[0] * q_bg_idx_2) + (rtu_q_bg[1]
    * q_bg_idx_3 - q2_q2 * rtu_q_bg[3]);
  q_yaw[3] = (q_bg_idx_0 * rtu_q_bg[3] + rtu_q_bg[0] * q_bg_idx_3) + (q2_q2 *
    rtu_q_bg[2] - rtu_q_bg[1] * q_bg_idx_2);
  q0_q0 = norm(q_yaw);
  if (q0_q0 <= 2.22044605E-16F) {
    q0_q0 = 2.22044605E-16F;
  }

  q_yaw[0] /= q0_q0;
  q_yaw[3] /= q0_q0;
  if (q_yaw[3] < 0.0F) {
    if (-q_yaw[0] >= 1.0F) {
      q_bg_idx_0 = 1.0F;
    } else {
      q_bg_idx_0 = -q_yaw[0];
    }

    if (q_bg_idx_0 <= -1.0F) {
      q_bg_idx_0 = -1.0F;
    }

    *rty_yaw = 2.0F * std::acos(q_bg_idx_0);
  } else {
    if (q_yaw[0] >= 1.0F) {
      q_bg_idx_0 = 1.0F;
    } else {
      q_bg_idx_0 = q_yaw[0];
    }

    if (q_bg_idx_0 <= -1.0F) {
      q_bg_idx_0 = -1.0F;
    }

    *rty_yaw = 2.0F * std::acos(q_bg_idx_0);
  }
}

//
// Output and update for atomic system:
//    '<S67>/wrap angle'
//    '<S67>/wrap angle1'
//
void MatlabControllerClass::wrapangle(real32_T rtu_angle, real32_T
  *rty_angle_0_2pi)
{
  real32_T x;
  x = std::abs(rtu_angle);
  x -= std::floor(x / 6.28318548F) * 6.28318548F;
  if (rtu_angle >= 0.0F) {
    *rty_angle_0_2pi = x;
  } else {
    *rty_angle_0_2pi = 6.28318548F - x;
  }
}

//
// Output and update for atomic system:
//    '<S72>/Lean Vector Derivative Trafo'
//    '<S72>/Lean Vector Derivative Trafo Delay'
//
void MatlabControllerClass::LeanVectorDerivativeTrafo(const real32_T rtu_n_g[3],
  const real32_T rtu_n_g_dt[3], const real32_T rtu_n_g_dt2[3], const real32_T
  rtu_M_bg[9], const real32_T rtu_omega_Kb[3], const real32_T rtu_omega_Kb_dt[3],
  real32_T rty_n_b[3], real32_T rty_n_b_dt[3], real32_T rty_n_b_dt2[3])
{
  real32_T rtu_M_bg_0[9];
  real32_T tmp[9];
  real32_T rtu_omega_Kb_0[3];
  real32_T rtu_omega_Kb_dt_0[3];
  real32_T rtu_omega_Kb_dt_1[3];
  real32_T rtu_M_bg_1;
  real32_T rtu_M_bg_2;
  real32_T rtu_M_bg_3;
  real32_T rtu_M_bg_idx_0;
  real32_T rtu_M_bg_idx_1;
  real32_T rtu_M_bg_idx_2;
  real32_T rty_n_b_0;
  real32_T rty_n_b_1;
  real32_T rty_n_b_2;
  real32_T tmp_0;
  rty_n_b[0] = 0.0F;
  rty_n_b[1] = 0.0F;
  rty_n_b[2] = 0.0F;
  rtu_M_bg_idx_0 = 0.0F;
  rtu_M_bg_idx_1 = 0.0F;
  rtu_M_bg_idx_2 = 0.0F;
  rty_n_b_0 = rty_n_b[0];
  rty_n_b_1 = rty_n_b[1];
  rty_n_b_2 = rty_n_b[2];
  for (int32_T i = 0; i < 3; i++) {
    tmp_0 = rtu_n_g[i];
    rtu_M_bg_1 = rtu_M_bg[3 * i];
    rty_n_b_0 += rtu_M_bg_1 * tmp_0;
    rtu_M_bg_2 = rtu_M_bg[3 * i + 1];
    rty_n_b_1 += rtu_M_bg_2 * tmp_0;
    rtu_M_bg_3 = rtu_M_bg[3 * i + 2];
    rty_n_b_2 += rtu_M_bg_3 * tmp_0;
    tmp_0 = rtu_n_g_dt[i];
    rtu_M_bg_idx_0 += rtu_M_bg_1 * tmp_0;
    rtu_M_bg_idx_1 += rtu_M_bg_2 * tmp_0;
    rtu_M_bg_idx_2 += rtu_M_bg_3 * tmp_0;
  }

  rty_n_b[2] = rty_n_b_2;
  rty_n_b[1] = rty_n_b_1;
  rty_n_b[0] = rty_n_b_0;
  rty_n_b_dt[0] = -(rtu_omega_Kb[1] * rty_n_b[2] - rty_n_b[1] * rtu_omega_Kb[2])
    + rtu_M_bg_idx_0;
  rty_n_b_dt[1] = -(rty_n_b[0] * rtu_omega_Kb[2] - rtu_omega_Kb[0] * rty_n_b[2])
    + rtu_M_bg_idx_1;
  rty_n_b_dt[2] = -(rtu_omega_Kb[0] * rty_n_b[1] - rty_n_b[0] * rtu_omega_Kb[1])
    + rtu_M_bg_idx_2;
  rtu_omega_Kb_dt_0[0] = -(rtu_omega_Kb_dt[1] * rty_n_b[2] - rty_n_b[1] *
    rtu_omega_Kb_dt[2]);
  rtu_omega_Kb_dt_0[1] = -(rty_n_b[0] * rtu_omega_Kb_dt[2] - rtu_omega_Kb_dt[0] *
    rty_n_b[2]);
  rtu_omega_Kb_dt_0[2] = -(rtu_omega_Kb_dt[0] * rty_n_b[1] - rty_n_b[0] *
    rtu_omega_Kb_dt[1]);
  rtu_omega_Kb_0[0] = rtu_omega_Kb[1] * rty_n_b_dt[2] - rty_n_b_dt[1] *
    rtu_omega_Kb[2];
  rtu_omega_Kb_0[1] = rty_n_b_dt[0] * rtu_omega_Kb[2] - rtu_omega_Kb[0] *
    rty_n_b_dt[2];
  rtu_omega_Kb_0[2] = rtu_omega_Kb[0] * rty_n_b_dt[1] - rty_n_b_dt[0] *
    rtu_omega_Kb[1];
  rtu_M_bg_0[0] = 0.0F;
  rtu_M_bg_0[3] = -rtu_omega_Kb[2];
  rtu_M_bg_0[6] = rtu_omega_Kb[1];
  rtu_M_bg_0[1] = rtu_omega_Kb[2];
  rtu_M_bg_0[4] = 0.0F;
  rtu_M_bg_0[7] = -rtu_omega_Kb[0];
  rtu_M_bg_0[2] = -rtu_omega_Kb[1];
  rtu_M_bg_0[5] = rtu_omega_Kb[0];
  rtu_M_bg_0[8] = 0.0F;
  for (int32_T i = 0; i < 3; i++) {
    tmp_0 = rtu_M_bg_0[3 * i + 1];
    rtu_M_bg_1 = rtu_M_bg_0[3 * i];
    rtu_M_bg_2 = rtu_M_bg_0[3 * i + 2];
    for (int32_T i_0 = 0; i_0 < 3; i_0++) {
      tmp[i_0 + 3 * i] = (rtu_M_bg[3 * i_0 + 1] * tmp_0 + rtu_M_bg[3 * i_0] *
                          rtu_M_bg_1) + rtu_M_bg[3 * i_0 + 2] * rtu_M_bg_2;
    }
  }

  for (int32_T i = 0; i < 3; i++) {
    rtu_M_bg_0[3 * i] = tmp[i];
    rtu_M_bg_0[3 * i + 1] = tmp[i + 3];
    rtu_M_bg_0[3 * i + 2] = tmp[i + 6];
  }

  rtu_M_bg_idx_0 = rtu_n_g_dt[1];
  rtu_M_bg_idx_1 = rtu_n_g_dt[0];
  rtu_M_bg_idx_2 = rtu_n_g_dt[2];
  rtu_M_bg_1 = 0.0F;
  rtu_M_bg_2 = 0.0F;
  rtu_M_bg_3 = 0.0F;
  for (int32_T i = 0; i < 3; i++) {
    rtu_omega_Kb_dt_1[i] = ((rtu_M_bg_0[i + 3] * rtu_M_bg_idx_0 + rtu_M_bg_0[i] *
      rtu_M_bg_idx_1) + rtu_M_bg_0[i + 6] * rtu_M_bg_idx_2) +
      (rtu_omega_Kb_dt_0[i] - rtu_omega_Kb_0[i]);
    tmp_0 = rtu_n_g_dt2[i];
    rtu_M_bg_1 += rtu_M_bg[3 * i] * tmp_0;
    rtu_M_bg_2 += rtu_M_bg[3 * i + 1] * tmp_0;
    rtu_M_bg_3 += rtu_M_bg[3 * i + 2] * tmp_0;
  }

  rty_n_b_dt2[0] = rtu_omega_Kb_dt_1[0] + rtu_M_bg_1;
  rty_n_b_dt2[1] = rtu_omega_Kb_dt_1[1] + rtu_M_bg_2;
  rty_n_b_dt2[2] = rtu_omega_Kb_dt_1[2] + rtu_M_bg_3;
}

// Function for MATLAB Function: '<S45>/caIndiWls'
real32_T MatlabControllerClass::xnrm2(int32_T n, const real32_T x_data[],
  int32_T ix0)
{
  int32_T kend;
  real32_T scale;
  real32_T y;
  y = 0.0F;
  scale = 1.29246971E-26F;
  kend = ix0 + n;
  for (int32_T k = ix0; k < kend; k++) {
    real32_T absxk;
    absxk = std::abs(x_data[k - 1]);
    if (absxk > scale) {
      real32_T t;
      t = scale / absxk;
      y = y * t * t + 1.0F;
      scale = absxk;
    } else {
      real32_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

real32_T rt_hypotf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0F) * a;
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

// Function for MATLAB Function: '<S45>/caIndiWls'
void MatlabControllerClass::mldivide(const real32_T A_data[], const int32_T
  A_size[2], const real32_T B_0[8], real32_T Y_data[], int32_T *Y_size)
{
  int32_T b_A_size[2];
  int32_T b_ix;
  int32_T exitg1;
  int32_T f_i;
  int32_T i;
  int32_T ia;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T p;
  int32_T rankA;
  int32_T rankA_tmp;
  real32_T b_A_data[32];
  real32_T b_B[8];
  real32_T tau_data[4];
  real32_T vn1_data[4];
  real32_T vn2_data[4];
  real32_T work_data[4];
  real32_T absxk;
  real32_T scale;
  real32_T smax;
  real32_T t;
  int8_T jpvt_data[4];
  int8_T jpvt;
  boolean_T exitg2;
  if (A_size[1] == 0) {
    *Y_size = 0;
  } else {
    for (i = 0; i < 8; i++) {
      b_B[i] = B_0[i];
    }

    rankA_tmp = A_size[1];
    b_A_size[1] = A_size[1];
    std::memcpy(&b_A_data[0], &A_data[0], static_cast<uint32_T>(A_size[1] << 3) *
                sizeof(real32_T));
    for (k = 0; k < rankA_tmp; k++) {
      jpvt_data[k] = static_cast<int8_T>(k + 1);
      tau_data[k] = 0.0F;
      work_data[k] = 0.0F;
      vn1_data[k] = 0.0F;
      vn2_data[k] = 0.0F;
      i = (k << 3) + 1;
      smax = 0.0F;
      scale = 1.29246971E-26F;
      for (rankA = i; rankA <= i + 7; rankA++) {
        absxk = std::abs(A_data[rankA - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          smax = smax * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          smax += t * t;
        }
      }

      absxk = scale * std::sqrt(smax);
      vn1_data[k] = absxk;
      vn2_data[k] = absxk;
    }

    for (k = 0; k < rankA_tmp; k++) {
      iy = k << 3;
      i = iy + k;
      rankA = (rankA_tmp - k) - 2;
      if (rankA + 1 < 0) {
        f_i = -1;
      } else {
        f_i = 0;
        if (rankA + 1 > 0) {
          ix = k;
          smax = std::abs(vn1_data[k]);
          for (b_ix = 2; b_ix <= rankA + 2; b_ix++) {
            ix++;
            scale = std::abs(vn1_data[ix]);
            if (scale > smax) {
              f_i = b_ix - 1;
              smax = scale;
            }
          }
        }
      }

      ix = k + f_i;
      if (ix != k) {
        b_ix = ix << 3;
        for (f_i = 0; f_i < 8; f_i++) {
          smax = b_A_data[b_ix];
          b_A_data[b_ix] = b_A_data[iy];
          b_A_data[iy] = smax;
          b_ix++;
          iy++;
        }

        b_ix = jpvt_data[ix];
        jpvt_data[ix] = jpvt_data[k];
        jpvt_data[k] = static_cast<int8_T>(b_ix);
        vn1_data[ix] = vn1_data[k];
        vn2_data[ix] = vn2_data[k];
      }

      scale = b_A_data[i];
      ix = i + 2;
      tau_data[k] = 0.0F;
      smax = xnrm2(7 - k, b_A_data, i + 2);
      if (smax != 0.0F) {
        smax = rt_hypotf(b_A_data[i], smax);
        if (b_A_data[i] >= 0.0F) {
          smax = -smax;
        }

        if (std::abs(smax) < 9.86076132E-32F) {
          b_ix = 0;
          iy = (i - k) + 8;
          do {
            b_ix++;
            for (f_i = ix; f_i <= iy; f_i++) {
              b_A_data[f_i - 1] *= 1.01412048E+31F;
            }

            smax *= 1.01412048E+31F;
            scale *= 1.01412048E+31F;
          } while ((std::abs(smax) < 9.86076132E-32F) && (b_ix < 20));

          smax = rt_hypotf(scale, xnrm2(7 - k, b_A_data, i + 2));
          if (scale >= 0.0F) {
            smax = -smax;
          }

          tau_data[k] = (smax - scale) / smax;
          scale = 1.0F / (scale - smax);
          for (f_i = ix; f_i <= iy; f_i++) {
            b_A_data[f_i - 1] *= scale;
          }

          for (f_i = 0; f_i < b_ix; f_i++) {
            smax *= 9.86076132E-32F;
          }

          scale = smax;
        } else {
          tau_data[k] = (smax - b_A_data[i]) / smax;
          scale = 1.0F / (b_A_data[i] - smax);
          b_ix = (i - k) + 8;
          for (iy = ix; iy <= b_ix; iy++) {
            b_A_data[iy - 1] *= scale;
          }

          scale = smax;
        }
      }

      b_A_data[i] = scale;
      if (k + 1 < rankA_tmp) {
        smax = b_A_data[i];
        b_A_data[i] = 1.0F;
        if (tau_data[k] != 0.0F) {
          b_ix = 8 - k;
          f_i = (i - k) + 7;
          while ((b_ix > 0) && (b_A_data[f_i] == 0.0F)) {
            b_ix--;
            f_i--;
          }

          exitg2 = false;
          while ((!exitg2) && (rankA + 1 > 0)) {
            f_i = ((rankA << 3) + i) + 8;
            ix = f_i;
            do {
              exitg1 = 0;
              if (ix + 1 <= f_i + b_ix) {
                if (b_A_data[ix] != 0.0F) {
                  exitg1 = 1;
                } else {
                  ix++;
                }
              } else {
                rankA--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          b_ix = 0;
          rankA = -1;
        }

        if (b_ix > 0) {
          if (rankA + 1 != 0) {
            if (rankA >= 0) {
              std::memset(&work_data[0], 0, static_cast<uint32_T>(rankA + 1) *
                          sizeof(real32_T));
            }

            iy = 0;
            f_i = ((rankA << 3) + i) + 9;
            for (ix = i + 9; ix <= f_i; ix += 8) {
              scale = 0.0F;
              p = ix + b_ix;
              for (ia = ix; ia < p; ia++) {
                scale += b_A_data[(i + ia) - ix] * b_A_data[ia - 1];
              }

              work_data[iy] += scale;
              iy++;
            }
          }

          if (-tau_data[k] != 0.0F) {
            iy = i + 9;
            for (ix = 0; ix <= rankA; ix++) {
              scale = work_data[ix];
              if (scale != 0.0F) {
                scale *= -tau_data[k];
                p = b_ix + iy;
                for (ia = iy; ia < p; ia++) {
                  b_A_data[ia - 1] += b_A_data[(i + ia) - iy] * scale;
                }
              }

              iy += 8;
            }
          }
        }

        b_A_data[i] = smax;
      }

      for (i = k + 2; i <= rankA_tmp; i++) {
        rankA = ((i - 1) << 3) + k;
        absxk = vn1_data[i - 1];
        if (absxk != 0.0F) {
          smax = std::abs(b_A_data[rankA]) / absxk;
          smax = 1.0F - smax * smax;
          if (smax < 0.0F) {
            smax = 0.0F;
          }

          scale = absxk / vn2_data[i - 1];
          scale = scale * scale * smax;
          if (scale <= 0.000345266977F) {
            absxk = xnrm2(7 - k, b_A_data, rankA + 2);
            vn1_data[i - 1] = absxk;
            vn2_data[i - 1] = absxk;
          } else {
            vn1_data[i - 1] = absxk * std::sqrt(smax);
          }
        }
      }
    }

    rankA = 0;
    while ((rankA < b_A_size[1]) && (std::abs(b_A_data[(rankA << 3) + rankA]) >
            9.53674316E-6F * std::abs(b_A_data[0]))) {
      rankA++;
    }

    *Y_size = A_size[1];
    for (k = 0; k < rankA_tmp; k++) {
      Y_data[k] = 0.0F;
      if (tau_data[k] != 0.0F) {
        smax = b_B[k];
        for (i = k + 2; i < 9; i++) {
          smax += b_A_data[((k << 3) + i) - 1] * b_B[i - 1];
        }

        smax *= tau_data[k];
        if (smax != 0.0F) {
          b_B[k] -= smax;
          for (i = k + 2; i < 9; i++) {
            b_B[i - 1] -= b_A_data[((k << 3) + i) - 1] * smax;
          }
        }
      }
    }

    for (rankA_tmp = 0; rankA_tmp < rankA; rankA_tmp++) {
      Y_data[jpvt_data[rankA_tmp] - 1] = b_B[rankA_tmp];
    }

    for (rankA_tmp = rankA; rankA_tmp >= 1; rankA_tmp--) {
      jpvt = jpvt_data[rankA_tmp - 1];
      iy = (rankA_tmp - 1) << 3;
      Y_data[jpvt - 1] /= b_A_data[(rankA_tmp + iy) - 1];
      for (i = 0; i <= rankA_tmp - 2; i++) {
        k = jpvt_data[i] - 1;
        Y_data[k] -= Y_data[jpvt - 1] * b_A_data[i + iy];
      }
    }
  }
}

real32_T rt_roundf(real32_T u)
{
  real32_T y;
  if (std::abs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = std::floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = 0.0F;
    } else {
      y = std::ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_urand_Upu32_Yd_f_pw(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = std::sqrt(-2.0 * std::log(si) / si) * sr;
  return y;
}

// Model step function
void MatlabControllerClass::step()
{
  real_T W_v[16];
  real_T b_d[16];
  real_T p[4];
  real_T rtb_Output[4];
  real_T x[4];
  real_T W_v_0;
  int32_T tmp_data[4];
  int32_T A_size[2];
  int32_T i;
  int32_T k;
  int32_T rtb_G1_tmp;
  int32_T rtb_G2_tmp;
  int32_T stage_;
  real32_T A[32];
  real32_T A_data[32];
  real32_T G_omega[16];
  real32_T G_omega_0[16];
  real32_T rtb_G1[16];
  real32_T rtb_G2[16];
  real32_T rtb_y_ne[16];
  real32_T rtb_M_bg[9];
  real32_T rtb_Transpose[9];
  real32_T tmp[9];
  real32_T tmp_0[9];
  real32_T A_0[8];
  real32_T A_tmp_0[8];
  real32_T d[8];
  real32_T A_tmp[4];
  real32_T p_free_data[4];
  real32_T rtb_q_red_j[4];
  real32_T rtb_y_dy[4];
  real32_T u_opt[4];
  real32_T umax[4];
  real32_T umin[4];
  real32_T Omega_Kg_des[3];
  real32_T dir_next_wp[3];
  real32_T rtb_V_Kg_n0[3];
  real32_T rtb_n_b_dt[3];
  real32_T rtb_n_dt[3];
  real32_T rtb_n_dt2[3];
  real32_T rtb_n_dt2_p[3];
  real32_T rtb_p_ahead_g[3];
  real32_T rtb_p_match[3];
  real32_T rtb_p_match_2[3];
  real32_T A_tmp_1;
  real32_T A_tmp_2;
  real32_T cos_Phi;
  real32_T cos_Psi;
  real32_T cos_Theta;
  real32_T cos_Theta_0;
  real32_T rtb_Gain;
  real32_T rtb_Reshape_idx_1;
  real32_T rtb_a_idx_1;
  real32_T rtb_a_idx_2;
  real32_T rtb_p_match_0;
  real32_T rtb_p_match_1;
  real32_T rtb_pq_Kb_dt_idx_0;
  real32_T rtb_pq_Kb_dt_idx_1;
  real32_T sin_Phi;
  real32_T sin_Psi;
  real32_T sin_Theta;
  boolean_T i_free[4];
  boolean_T infeasible[4];
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T rtb_Compare;

  // DiscreteIntegrator: '<S61>/Discrete-Time Integrator y' incorporates:
  //   Inport: '<Root>/measure'

  if (rtDW.DiscreteTimeIntegratory_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegratory_DSTATE[0] = rtU.measure.s_Kg[0];
    rtDW.DiscreteTimeIntegratory_DSTATE[1] = rtU.measure.s_Kg[1];
    rtDW.DiscreteTimeIntegratory_DSTATE[2] = rtU.measure.s_Kg[2];
  }

  // DiscreteIntegrator: '<S60>/Discrete-Time Integrator y' incorporates:
  //   Inport: '<Root>/measure'

  if (rtDW.DiscreteTimeIntegratory_IC_LO_b != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_e[0] = rtU.measure.V_Kg[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_e[1] = rtU.measure.V_Kg[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_e[2] = rtU.measure.V_Kg[2];
  }

  // RelationalOperator: '<S112>/Compare' incorporates:
  //   Constant: '<S112>/Constant'
  //   Constant: '<S2>/Constant3'
  //   Sum: '<S15>/Add2'
  //   UnitDelay: '<S15>/Unit Delay1'

  rtb_Compare = (3.0F - rtDW.UnitDelay1_DSTATE != 0.0F);

  // MATLAB Function: '<S5>/Euler Angles to Rotation Matrix' incorporates:
  //   Inport: '<Root>/measure'

  sin_Phi = std::sin(rtU.measure.EulerAngles[0]);
  cos_Phi = std::cos(rtU.measure.EulerAngles[0]);
  sin_Theta = std::sin(rtU.measure.EulerAngles[1]);
  cos_Theta = std::cos(rtU.measure.EulerAngles[1]);
  sin_Psi = std::sin(rtU.measure.EulerAngles[2]);
  cos_Psi = std::cos(rtU.measure.EulerAngles[2]);
  rtb_M_bg[0] = cos_Psi * cos_Theta;
  rtb_M_bg[3] = sin_Psi * cos_Theta;
  rtb_M_bg[6] = -sin_Theta;
  rtb_a_idx_1 = cos_Psi * sin_Theta;
  rtb_M_bg[1] = rtb_a_idx_1 * sin_Phi - sin_Psi * cos_Phi;
  rtb_a_idx_2 = sin_Psi * sin_Theta;
  rtb_M_bg[4] = rtb_a_idx_2 * sin_Phi + cos_Psi * cos_Phi;
  rtb_M_bg[7] = cos_Theta * sin_Phi;
  rtb_M_bg[2] = rtb_a_idx_1 * cos_Phi + sin_Psi * sin_Phi;
  rtb_M_bg[5] = rtb_a_idx_2 * cos_Phi - cos_Psi * sin_Phi;
  rtb_M_bg[8] = cos_Theta * cos_Phi;

  // DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  if (rtDW.DiscreteTimeIntegratory_IC_L_b1 != 0) {
    for (i = 0; i < 9; i++) {
      rtDW.DiscreteTimeIntegratory_DSTA_br[i] = rtb_M_bg[i];
    }
  }

  // MATLAB Function: '<S63>/DCM to quaternions' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  DCMtoquaternions(rtDW.DiscreteTimeIntegratory_DSTA_br, rtb_y_dy);

  // MATLAB Function: '<S63>/Quaternion Reduced'
  QuaternionReduced(rtb_y_dy, rtb_q_red_j, &sin_Phi);

  // DiscreteIntegrator: '<S72>/Discrete-Time Integrator2'
  if (rtDW.DiscreteTimeIntegrator2_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegrator2_DSTATE = sin_Phi;
  }

  // Delay: '<S16>/Delay' incorporates:
  //   Inport: '<Root>/cmd'

  if (rtDW.icLoad) {
    rtDW.Delay_DSTATE = rtU.cmd.yaw_init;
  }

  // End of Delay: '<S16>/Delay'

  // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/measure'

  cos_Phi = rtU.measure.s_Kg[0] * rtU.measure.s_Kg[0] + rtU.measure.s_Kg[1] *
    rtU.measure.s_Kg[1];
  if (cos_Phi <= 0.0F) {
    cos_Phi = 0.0F;
  }

  if (std::sqrt(cos_Phi) > 10.0F) {
    // Update for Delay: '<S16>/Delay'
    rtDW.Delay_DSTATE = std::atan2(rtU.measure.s_Kg[1], rtU.measure.s_Kg[0]);
  }

  // End of MATLAB Function: '<S16>/MATLAB Function1'

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   Gain: '<S2>/Gain'
  //   Inport: '<Root>/cmd'

  sin_Theta = std::cos(rtU.cmd.yaw_init);
  cos_Theta = std::sin(rtU.cmd.yaw_init);
  cos_Phi = rtU.cmd.roll * sin_Theta + -rtU.cmd.pitch * cos_Theta;
  rtb_Gain = -rtU.cmd.pitch * sin_Theta - rtU.cmd.roll * cos_Theta;

  // Outputs for Enabled SubSystem: '<S4>/NDI position controller for copters reference model' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (!rtDW.NDIpositioncontrollerforcopte_i) {
    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' 
    rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
    rtDW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' 
    rtDW.DiscreteTimeIntegrator_PrevRe_k = 2;
    rtDW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' 
    rtDW.DiscreteTimeIntegrator_PrevRe_m = 2;
    rtDW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
    rtDW.NDIpositioncontrollerforcopte_i = true;
  }

  // DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S61>/Discrete-Time Integrator y'

  if (rtDW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    rtDW.DiscreteTimeIntegrator1_DSTATE[0] =
      rtDW.DiscreteTimeIntegratory_DSTATE[0];
    rtDW.DiscreteTimeIntegrator1_DSTATE[1] =
      rtDW.DiscreteTimeIntegratory_DSTATE[1];
    rtDW.DiscreteTimeIntegrator1_DSTATE[2] =
      rtDW.DiscreteTimeIntegratory_DSTATE[2];
  }

  if (rtb_Compare && (rtDW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
    rtDW.DiscreteTimeIntegrator1_DSTATE[0] =
      rtDW.DiscreteTimeIntegratory_DSTATE[0];
    rtDW.DiscreteTimeIntegrator1_DSTATE[1] =
      rtDW.DiscreteTimeIntegratory_DSTATE[1];
    rtDW.DiscreteTimeIntegrator1_DSTATE[2] =
      rtDW.DiscreteTimeIntegratory_DSTATE[2];
  }

  // Merge generated from: '<S4>/Merge3' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
  //   SignalConversion generated from: '<S12>/reference'

  rtDW.s_g_ref[0] = rtDW.DiscreteTimeIntegrator1_DSTATE[0];
  rtDW.s_g_ref[1] = rtDW.DiscreteTimeIntegrator1_DSTATE[1];
  rtDW.s_g_ref[2] = rtDW.DiscreteTimeIntegrator1_DSTATE[2];

  // DiscreteIntegrator: '<S96>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'

  if (rtDW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE_c[0] =
      rtDW.DiscreteTimeIntegratory_DSTAT_e[0];
    rtDW.DiscreteTimeIntegrator_DSTATE_c[1] =
      rtDW.DiscreteTimeIntegratory_DSTAT_e[1];
  }

  if (rtb_Compare && (rtDW.DiscreteTimeIntegrator_PrevRe_k <= 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_c[0] =
      rtDW.DiscreteTimeIntegratory_DSTAT_e[0];
    rtDW.DiscreteTimeIntegrator_DSTATE_c[1] =
      rtDW.DiscreteTimeIntegratory_DSTAT_e[1];
  }

  // DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'

  if (rtDW.DiscreteTimeIntegrator_IC_LOA_h != 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE_k = rtDW.DiscreteTimeIntegratory_DSTAT_e
      [2];
  }

  if (rtb_Compare && (rtDW.DiscreteTimeIntegrator_PrevRe_m <= 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_k = rtDW.DiscreteTimeIntegratory_DSTAT_e
      [2];
  }

  // Merge generated from: '<S4>/Merge3' incorporates:
  //   DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
  //   SignalConversion generated from: '<S12>/reference'

  rtDW.s_g_ref_dt[0] = rtDW.DiscreteTimeIntegrator_DSTATE_c[0];
  rtDW.s_g_ref_dt[1] = rtDW.DiscreteTimeIntegrator_DSTATE_c[1];
  rtDW.s_g_ref_dt[2] = rtDW.DiscreteTimeIntegrator_DSTATE_k;

  // Outputs for Enabled SubSystem: '<S4>/Pilot Reduced Attitude Commands' incorporates:
  //   EnablePort: '<S14>/Enable'

  // MATLAB Function: '<S100>/stickRP2LeanCmd' incorporates:
  //   Gain: '<S98>/Gain'
  //   MATLAB Function: '<S14>/MATLAB Function'

  rtb_pq_Kb_dt_idx_0 = std::atan2(cos_Phi, rtb_Gain);

  // End of Outputs for SubSystem: '<S4>/Pilot Reduced Attitude Commands'
  cos_Theta_0 = std::sqrt(cos_Phi * cos_Phi + -rtb_Gain * -rtb_Gain);
  if (cos_Theta_0 <= 1.0F) {
    cos_Theta = cos_Theta_0;
  } else {
    cos_Theta = 1.0F;
  }

  // Outputs for Enabled SubSystem: '<S4>/Pilot Reduced Attitude Commands' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Trigonometry: '<S98>/Cos' incorporates:
  //   MATLAB Function: '<S100>/stickRP2LeanCmd'
  //   MATLAB Function: '<S14>/MATLAB Function1'

  cos_Phi = std::cos(rtb_pq_Kb_dt_idx_0);

  // End of Outputs for SubSystem: '<S4>/Pilot Reduced Attitude Commands'

  // Product: '<S96>/Divide' incorporates:
  //   Constant: '<S96>/T'
  //   DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
  //   Gain: '<S12>/velxymax'
  //   Product: '<S98>/Multiply'
  //   Sum: '<S96>/Sum2'
  //   Trigonometry: '<S98>/Cos'

  sin_Psi = (cos_Theta * cos_Phi * 13.2389574F -
             rtDW.DiscreteTimeIntegrator_DSTATE_c[0]) / 0.948934376F;

  // Saturate: '<S96>/Saturation'
  if (sin_Psi > 31.2780762F) {
    sin_Psi = 31.2780762F;
  } else if (sin_Psi < -31.2780762F) {
    sin_Psi = -31.2780762F;
  }

  // Outputs for Enabled SubSystem: '<S4>/Pilot Reduced Attitude Commands' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Trigonometry: '<S98>/Sin' incorporates:
  //   MATLAB Function: '<S100>/stickRP2LeanCmd'
  //   MATLAB Function: '<S14>/MATLAB Function1'

  rtb_Gain = std::sin(rtb_pq_Kb_dt_idx_0);

  // End of Outputs for SubSystem: '<S4>/Pilot Reduced Attitude Commands'

  // Product: '<S96>/Divide' incorporates:
  //   Constant: '<S96>/T'
  //   DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
  //   Gain: '<S12>/velxymax'
  //   Product: '<S98>/Multiply1'
  //   Sum: '<S96>/Sum2'
  //   Trigonometry: '<S98>/Sin'

  cos_Theta = (cos_Theta * rtb_Gain * 13.2389574F -
               rtDW.DiscreteTimeIntegrator_DSTATE_c[1]) / 0.948934376F;

  // Saturate: '<S96>/Saturation'
  if (cos_Theta > 31.2780762F) {
    cos_Theta = 31.2780762F;
  } else if (cos_Theta < -31.2780762F) {
    cos_Theta = -31.2780762F;
  }

  // MATLAB Function: '<S99>/MATLAB Function' incorporates:
  //   Inport: '<Root>/cmd'

  if (rtU.cmd.thr < 0.0F) {
    cos_Psi = -3.84421086F * rtU.cmd.thr;
  } else {
    cos_Psi = -12.1524172F * rtU.cmd.thr;
  }

  // Product: '<S97>/Divide' incorporates:
  //   Constant: '<S97>/T'
  //   DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
  //   MATLAB Function: '<S99>/MATLAB Function'
  //   Sum: '<S97>/Sum2'

  sin_Theta = (cos_Psi - rtDW.DiscreteTimeIntegrator_DSTATE_k) / 0.948934376F;

  // Saturate: '<S97>/Saturation'
  if (sin_Theta > 6.98508215F) {
    sin_Theta = 6.98508215F;
  } else if (sin_Theta < -24.7742729F) {
    sin_Theta = -24.7742729F;
  }

  // End of Saturate: '<S97>/Saturation'

  // Merge generated from: '<S4>/Merge3' incorporates:
  //   SignalConversion generated from: '<S12>/reference'

  rtDW.s_g_ref_dt2[2] = sin_Theta;

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
  rtDW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  // Merge generated from: '<S4>/Merge3' incorporates:
  //   SignalConversion generated from: '<S12>/reference'

  rtDW.s_g_ref_dt2[0] = sin_Psi;
  rtDW.s_g_ref_dt2[1] = cos_Theta;

  // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S97>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator1_DSTATE[0] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_c[0];
  rtDW.DiscreteTimeIntegrator1_DSTATE[1] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_c[1];
  rtDW.DiscreteTimeIntegrator1_DSTATE[2] += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_k;
  rtDW.DiscreteTimeIntegrator1_PrevRes = static_cast<int8_T>(rtb_Compare);

  // Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
  //   Saturate: '<S96>/Saturation'

  rtDW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  rtDW.DiscreteTimeIntegrator_DSTATE_c[0] += 0.0025F * sin_Psi;
  rtDW.DiscreteTimeIntegrator_DSTATE_c[1] += 0.0025F * cos_Theta;
  rtDW.DiscreteTimeIntegrator_PrevRe_k = static_cast<int8_T>(rtb_Compare);

  // Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'

  rtDW.DiscreteTimeIntegrator_IC_LOA_h = 0U;
  rtDW.DiscreteTimeIntegrator_DSTATE_k += 0.0025F * sin_Theta;
  rtDW.DiscreteTimeIntegrator_PrevRe_m = static_cast<int8_T>(rtb_Compare);

  // End of Outputs for SubSystem: '<S4>/NDI position controller for copters reference model' 

  // Outputs for Enabled SubSystem: '<S4>/Waypoint Navigation' incorporates:
  //   EnablePort: '<S18>/Enable'

  if (rtDW.WaypointNavigation_MODE) {
    // Disable for Enabled SubSystem: '<S119>/Flight Path Smoothing'
    rtDW.FlightPathSmoothing_MODE = false;

    // End of Disable for SubSystem: '<S119>/Flight Path Smoothing'
    rtDW.WaypointNavigation_MODE = false;
  }

  // End of Outputs for SubSystem: '<S4>/Waypoint Navigation'

  // Outputs for Enabled SubSystem: '<S4>/NDI position controller for copters with reference input' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (!rtDW.NDIpositioncontrollerforcopters) {
    // InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y' 
    rtDW.DiscreteTimeIntegratory_PrevR_o = 2;
    rtDW.DiscreteTimeIntegratory_IC_LO_p = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' 
    for (i = 0; i < 9; i++) {
      rtDW.DiscreteTimeIntegratory_dt_DS_p[i] = 0.0F;
    }

    rtDW.DiscreteTimeIntegratory_dt_Pr_j = 2;

    // End of InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' 
    rtDW.NDIpositioncontrollerforcopters = true;
  }

  // DiscreteIntegrator: '<S105>/Discrete-Time Integrator y' incorporates:
  //   Math: '<S5>/Transpose'

  if (rtDW.DiscreteTimeIntegratory_IC_LO_p != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_l[0] = rtDW.s_g_ref[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[3] = rtDW.s_g_ref_dt[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[6] = rtDW.s_g_ref_dt2[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[1] = rtDW.s_g_ref[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[4] = rtDW.s_g_ref_dt[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[7] = rtDW.s_g_ref_dt2[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[2] = rtDW.s_g_ref[2];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[5] = rtDW.s_g_ref_dt[2];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[8] = rtDW.s_g_ref_dt2[2];
  }

  if (rtb_Compare && (rtDW.DiscreteTimeIntegratory_PrevR_o <= 0)) {
    rtDW.DiscreteTimeIntegratory_DSTAT_l[0] = rtDW.s_g_ref[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[3] = rtDW.s_g_ref_dt[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[6] = rtDW.s_g_ref_dt2[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[1] = rtDW.s_g_ref[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[4] = rtDW.s_g_ref_dt[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[7] = rtDW.s_g_ref_dt2[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[2] = rtDW.s_g_ref[2];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[5] = rtDW.s_g_ref_dt[2];
    rtDW.DiscreteTimeIntegratory_DSTAT_l[8] = rtDW.s_g_ref_dt2[2];
  }

  for (i = 0; i < 9; i++) {
    rtb_Transpose[i] = rtDW.DiscreteTimeIntegratory_DSTAT_l[i];

    // DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' incorporates:
    //   Math: '<S5>/Transpose'

    if (rtb_Compare && (rtDW.DiscreteTimeIntegratory_dt_Pr_j <= 0)) {
      rtDW.DiscreteTimeIntegratory_dt_DS_p[i] = 0.0F;
    }
  }

  // End of DiscreteIntegrator: '<S105>/Discrete-Time Integrator y'

  // Sum: '<S104>/Add' incorporates:
  //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S61>/Discrete-Time Integrator y'
  //   Math: '<S5>/Transpose'

  rtDW.Add[0] = rtb_Transpose[0] - rtDW.DiscreteTimeIntegratory_DSTATE[0];
  rtDW.Add[3] = rtb_Transpose[3] - rtDW.DiscreteTimeIntegratory_DSTAT_e[0];
  rtDW.Add[6] = rtb_Transpose[6] - rtDW.DiscreteTimeIntegratory_DSTAT_b[0];
  rtDW.Add[1] = rtb_Transpose[1] - rtDW.DiscreteTimeIntegratory_DSTATE[1];
  rtDW.Add[4] = rtb_Transpose[4] - rtDW.DiscreteTimeIntegratory_DSTAT_e[1];
  rtDW.Add[7] = rtb_Transpose[7] - rtDW.DiscreteTimeIntegratory_DSTAT_b[1];
  rtDW.Add[2] = rtb_Transpose[2] - rtDW.DiscreteTimeIntegratory_DSTATE[2];
  rtDW.Add[5] = rtb_Transpose[5] - rtDW.DiscreteTimeIntegratory_DSTAT_e[2];
  rtDW.Add[8] = rtb_Transpose[8] - rtDW.DiscreteTimeIntegratory_DSTAT_b[2];

  // Switch: '<S106>/Switch2' incorporates:
  //   RelationalOperator: '<S106>/LowerRelop1'
  //   RelationalOperator: '<S106>/UpperRelop'
  //   Switch: '<S106>/Switch'

  if (rtDW.Add[0] > 13.4901152F) {
    cos_Psi = 13.4901152F;
  } else if (rtDW.Add[0] < -13.4901152F) {
    // Switch: '<S106>/Switch'
    cos_Psi = -13.4901152F;
  } else {
    cos_Psi = rtDW.Add[0];
  }

  // Sum: '<S104>/Add1' incorporates:
  //   Gain: '<S104>/Gain'
  //   Gain: '<S104>/Gain3'
  //   Gain: '<S104>/Gain4'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S106>/Switch2'

  rtb_p_match[0] = (1.68574107F * cos_Psi + 2.45388794F * rtDW.Add[3]) +
    0.374285728F * rtDW.Add[6];

  // Switch: '<S106>/Switch2' incorporates:
  //   RelationalOperator: '<S106>/LowerRelop1'
  //   RelationalOperator: '<S106>/UpperRelop'
  //   Switch: '<S106>/Switch'

  if (rtDW.Add[1] > 13.4901152F) {
    cos_Psi = 13.4901152F;
  } else if (rtDW.Add[1] < -13.4901152F) {
    // Switch: '<S106>/Switch'
    cos_Psi = -13.4901152F;
  } else {
    cos_Psi = rtDW.Add[1];
  }

  // Sum: '<S104>/Add1' incorporates:
  //   Gain: '<S104>/Gain'
  //   Gain: '<S104>/Gain3'
  //   Gain: '<S104>/Gain4'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S106>/Switch2'

  rtb_p_match[1] = (1.68574107F * cos_Psi + 2.45388794F * rtDW.Add[4]) +
    0.374285728F * rtDW.Add[7];

  // Switch: '<S106>/Switch2' incorporates:
  //   RelationalOperator: '<S106>/LowerRelop1'
  //   RelationalOperator: '<S106>/UpperRelop'
  //   Switch: '<S106>/Switch'

  if (rtDW.Add[2] > 13.4901152F) {
    cos_Psi = 13.4901152F;
  } else if (rtDW.Add[2] < -13.4901152F) {
    // Switch: '<S106>/Switch'
    cos_Psi = -13.4901152F;
  } else {
    cos_Psi = rtDW.Add[2];
  }

  // Sum: '<S104>/Add1' incorporates:
  //   Gain: '<S104>/Gain'
  //   Gain: '<S104>/Gain3'
  //   Gain: '<S104>/Gain4'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S106>/Switch2'

  rtb_p_match[2] = (1.68574107F * cos_Psi + 2.45388794F * rtDW.Add[5]) +
    0.374285728F * rtDW.Add[8];

  // RelationalOperator: '<S107>/LowerRelop1' incorporates:
  //   Sum: '<S61>/Sum2'

  rtb_p_match_1 = rtb_p_match[0];

  // Switch: '<S107>/Switch2' incorporates:
  //   RelationalOperator: '<S107>/LowerRelop1'
  //   RelationalOperator: '<S107>/UpperRelop'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S107>/Switch'

  if (rtb_p_match[0] > 23.4585571F) {
    rtb_p_match_1 = 23.4585571F;
  } else if (rtb_p_match[0] < -23.4585571F) {
    // Switch: '<S107>/Switch'
    rtb_p_match_1 = -23.4585571F;
  }

  // Sum: '<S13>/Add1' incorporates:
  //   Merge generated from: '<S4>/Merge3'
  //   Sum: '<S61>/Sum2'

  rtDW.nu[0] = rtDW.s_g_ref_dt2[0] + rtb_p_match_1;

  // RelationalOperator: '<S107>/LowerRelop1' incorporates:
  //   Sum: '<S61>/Sum2'

  rtb_p_match_1 = rtb_p_match[1];

  // Switch: '<S107>/Switch2' incorporates:
  //   RelationalOperator: '<S107>/LowerRelop1'
  //   RelationalOperator: '<S107>/UpperRelop'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S107>/Switch'

  if (rtb_p_match[1] > 23.4585571F) {
    rtb_p_match_1 = 23.4585571F;
  } else if (rtb_p_match[1] < -23.4585571F) {
    // Switch: '<S107>/Switch'
    rtb_p_match_1 = -23.4585571F;
  }

  // Sum: '<S13>/Add1' incorporates:
  //   Merge generated from: '<S4>/Merge3'
  //   Sum: '<S61>/Sum2'

  rtDW.nu[1] = rtDW.s_g_ref_dt2[1] + rtb_p_match_1;

  // RelationalOperator: '<S107>/LowerRelop1' incorporates:
  //   Sum: '<S61>/Sum2'

  rtb_p_match_1 = rtb_p_match[2];

  // Switch: '<S107>/Switch2' incorporates:
  //   RelationalOperator: '<S107>/LowerRelop1'
  //   RelationalOperator: '<S107>/UpperRelop'
  //   Sum: '<S61>/Sum2'
  //   Switch: '<S107>/Switch'

  if (rtb_p_match[2] > 23.4585571F) {
    rtb_p_match_1 = 23.4585571F;
  } else if (rtb_p_match[2] < -23.4585571F) {
    // Switch: '<S107>/Switch'
    rtb_p_match_1 = -23.4585571F;
  }

  // Sum: '<S13>/Add1' incorporates:
  //   Merge generated from: '<S4>/Merge3'
  //   Sum: '<S61>/Sum2'

  rtDW.nu[2] = rtDW.s_g_ref_dt2[2] + rtb_p_match_1;

  // Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'

  rtDW.DiscreteTimeIntegratory_IC_LO_p = 0U;

  // Outputs for Enabled SubSystem: '<S4>/NDI position controller for copters reference model' incorporates:
  //   EnablePort: '<S12>/Enable'

  rtDW.DiscreteTimeIntegratory_PrevR_o = static_cast<int8_T>(rtb_Compare);

  // End of Outputs for SubSystem: '<S4>/NDI position controller for copters reference model' 

  // Sum: '<S105>/Sum2'
  tmp[0] = rtDW.s_g_ref[0];
  tmp[3] = rtDW.s_g_ref_dt[0];
  tmp[6] = rtDW.s_g_ref_dt2[0];
  tmp[1] = rtDW.s_g_ref[1];
  tmp[4] = rtDW.s_g_ref_dt[1];
  tmp[7] = rtDW.s_g_ref_dt2[1];
  tmp[2] = rtDW.s_g_ref[2];
  tmp[5] = rtDW.s_g_ref_dt[2];
  tmp[8] = rtDW.s_g_ref_dt2[2];
  for (k = 0; k < 9; k++) {
    // DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' incorporates:
    //   DiscreteIntegrator: '<S105>/Discrete-Time Integrator y'

    cos_Psi = rtDW.DiscreteTimeIntegratory_dt_DS_p[k];

    // Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTAT_l[k] += 0.0025F * cos_Psi;

    // Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' incorporates:
    //   Math: '<S5>/Transpose'
    //   Product: '<S105>/Product1'
    //   Product: '<S105>/Product2'
    //   Sum: '<S105>/Sum2'
    //   Sum: '<S105>/Sum3'

    rtDW.DiscreteTimeIntegratory_dt_DS_p[k] = (tmp[k] - (cos_Psi * 0.271124125F
      + rtb_Transpose[k])) * 27.2072945F * 0.0025F + cos_Psi;
  }

  // Outputs for Enabled SubSystem: '<S4>/NDI position controller for copters reference model' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'

  rtDW.DiscreteTimeIntegratory_dt_Pr_j = static_cast<int8_T>(rtb_Compare);

  // End of Outputs for SubSystem: '<S4>/NDI position controller for copters reference model' 
  // End of Outputs for SubSystem: '<S4>/NDI position controller for copters with reference input' 

  // MATLAB Function: '<S21>/create diag' incorporates:
  //   Delay: '<S25>/Delay'

  std::memset(&rtb_y_ne[0], 0, sizeof(real32_T) << 4U);
  rtb_y_ne[0] = rtDW.Delay_DSTATE_a[0];

  // MinMax: '<S44>/Max' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[0] >= 0.1F) {
    rtb_y_dy[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0];
  } else {
    rtb_y_dy[0] = 0.1F;
  }

  // MATLAB Function: '<S21>/create diag' incorporates:
  //   Delay: '<S25>/Delay'

  rtb_y_ne[5] = rtDW.Delay_DSTATE_a[1];

  // MinMax: '<S44>/Max' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[1] >= 0.1F) {
    rtb_y_dy[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1];
  } else {
    rtb_y_dy[1] = 0.1F;
  }

  // MATLAB Function: '<S21>/create diag' incorporates:
  //   Delay: '<S25>/Delay'

  rtb_y_ne[10] = rtDW.Delay_DSTATE_a[2];

  // MinMax: '<S44>/Max' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[2] >= 0.1F) {
    rtb_y_dy[2] = rtDW.DiscreteTimeIntegrator_DSTATE[2];
  } else {
    rtb_y_dy[2] = 0.1F;
  }

  // MATLAB Function: '<S21>/create diag' incorporates:
  //   Delay: '<S25>/Delay'

  rtb_y_ne[15] = rtDW.Delay_DSTATE_a[3];

  // MinMax: '<S44>/Max' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[3] >= 0.1F) {
    rtb_y_dy[3] = rtDW.DiscreteTimeIntegrator_DSTATE[3];
  } else {
    rtb_y_dy[3] = 0.1F;
  }

  // MATLAB Function: '<S44>/MATLAB Function'
  cos_Psi = std::sqrt(1.3039763E-8F * rtb_y_dy[0] + 3.46332598E-8F);
  rtb_q_red_j[0] = (cos_Psi - 0.000186100136F) / 3.22927214E-8F;
  sin_Phi = std::sqrt(1.3039763E-8F * rtb_y_dy[1] + 3.46332598E-8F);
  rtb_q_red_j[1] = (sin_Phi - 0.000186100136F) / 3.22927214E-8F;
  rtb_a_idx_1 = std::sqrt(1.3039763E-8F * rtb_y_dy[2] + 3.46332598E-8F);
  rtb_q_red_j[2] = (rtb_a_idx_1 - 0.000186100136F) / 3.22927214E-8F;
  rtb_q_red_j[3] = (std::sqrt(1.3039763E-8F * rtb_y_dy[3] + 3.46332598E-8F) -
                    0.000186100136F) / 3.22927214E-8F;
  rtb_y_dy[0] = 0.201899409F / cos_Psi;
  rtb_y_dy[1] = 0.201899409F / sin_Phi;
  rtb_y_dy[2] = 0.201899409F / rtb_a_idx_1;

  // MinMax: '<S44>/Max' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  if (rtDW.DiscreteTimeIntegrator_DSTATE[3] >= 0.1F) {
    cos_Psi = rtDW.DiscreteTimeIntegrator_DSTATE[3];
  } else {
    cos_Psi = 0.1F;
  }

  // MATLAB Function: '<S44>/MATLAB Function' incorporates:
  //   MinMax: '<S44>/Max'

  rtb_y_dy[3] = 0.201899409F / std::sqrt(1.3039763E-8F * cos_Psi +
    3.46332598E-8F);
  std::memset(&G_omega[0], 0, sizeof(real32_T) << 4U);
  std::memset(&rtb_G2[0], 0, sizeof(real32_T) << 4U);
  G_omega[0] = rtb_y_dy[0];
  G_omega[5] = rtb_y_dy[1];
  G_omega[10] = rtb_y_dy[2];
  G_omega[15] = rtb_y_dy[3];
  for (stage_ = 0; stage_ < 4; stage_++) {
    rtb_G2_tmp = stage_ << 2;
    rtb_G2[stage_ + rtb_G2_tmp] = rtb_q_red_j[stage_];
    G_omega_0[rtb_G2_tmp] = 0.0F;
    G_omega_0[rtb_G2_tmp + 1] = 0.0F;
    G_omega_0[rtb_G2_tmp + 2] = 0.0F;
    G_omega_0[rtb_G2_tmp + 3] = 0.0F;
  }

  for (k = 0; k < 4; k++) {
    i = k << 2;
    cos_Psi = G_omega_0[i];
    A_tmp_1 = G_omega_0[i + 1];
    A_tmp_2 = G_omega_0[i + 2];
    sin_Phi = G_omega_0[i + 3];
    for (stage_ = 0; stage_ < 4; stage_++) {
      rtb_G1_tmp = i + stage_;
      rtb_a_idx_1 = rtb_G2[rtb_G1_tmp];
      rtb_G2_tmp = stage_ << 2;
      cos_Psi += rtConstP.MATLABFunction_G10[rtb_G2_tmp] * rtb_a_idx_1;
      A_tmp_1 += rtConstP.MATLABFunction_G10[rtb_G2_tmp + 1] * rtb_a_idx_1;
      A_tmp_2 += rtConstP.MATLABFunction_G10[rtb_G2_tmp + 2] * rtb_a_idx_1;
      sin_Phi += rtConstP.MATLABFunction_G10[rtb_G2_tmp + 3] * rtb_a_idx_1;
      rtb_G1[rtb_G1_tmp] = 0.0F;
    }

    G_omega_0[i + 3] = sin_Phi;
    G_omega_0[i + 2] = A_tmp_2;
    G_omega_0[i + 1] = A_tmp_1;
    G_omega_0[i] = cos_Psi;
  }

  for (k = 0; k < 4; k++) {
    // Product: '<S21>/correct G1'
    rtb_G1_tmp = k << 2;
    sin_Phi = rtb_G1[rtb_G1_tmp];
    rtb_a_idx_1 = rtb_G1[rtb_G1_tmp + 1];
    rtb_a_idx_2 = rtb_G1[rtb_G1_tmp + 2];
    rtb_Reshape_idx_1 = rtb_G1[rtb_G1_tmp + 3];
    for (i = 0; i < 4; i++) {
      stage_ = rtb_G1_tmp + i;
      cos_Psi = G_omega[stage_];
      rtb_G2_tmp = i << 2;
      sin_Phi += G_omega_0[rtb_G2_tmp] * cos_Psi;
      rtb_a_idx_1 += G_omega_0[rtb_G2_tmp + 1] * cos_Psi;
      rtb_a_idx_2 += G_omega_0[rtb_G2_tmp + 2] * cos_Psi;
      rtb_Reshape_idx_1 += G_omega_0[rtb_G2_tmp + 3] * cos_Psi;
      rtb_G2[stage_] = 0.0F;
    }

    rtb_G1[rtb_G1_tmp + 3] = rtb_Reshape_idx_1;
    rtb_G1[rtb_G1_tmp + 2] = rtb_a_idx_2;
    rtb_G1[rtb_G1_tmp + 1] = rtb_a_idx_1;
    rtb_G1[rtb_G1_tmp] = sin_Phi;
    sin_Phi = rtb_G2[rtb_G1_tmp];
    rtb_a_idx_1 = rtb_G2[rtb_G1_tmp + 1];
    rtb_a_idx_2 = rtb_G2[rtb_G1_tmp + 2];
    rtb_Reshape_idx_1 = rtb_G2[rtb_G1_tmp + 3];

    // Product: '<S21>/correct G1'
    for (i = 0; i < 4; i++) {
      stage_ = rtb_G1_tmp + i;
      cos_Psi = G_omega[stage_];
      rtb_G2_tmp = i << 2;
      sin_Phi += rtConstP.MATLABFunction_G20[rtb_G2_tmp] * cos_Psi;
      rtb_a_idx_1 += rtConstP.MATLABFunction_G20[rtb_G2_tmp + 1] * cos_Psi;
      rtb_a_idx_2 += rtConstP.MATLABFunction_G20[rtb_G2_tmp + 2] * cos_Psi;
      rtb_Reshape_idx_1 += rtConstP.MATLABFunction_G20[rtb_G2_tmp + 3] * cos_Psi;
      G_omega[stage_] = 0.0F;
    }

    rtb_G2[rtb_G1_tmp + 3] = rtb_Reshape_idx_1;
    rtb_G2[rtb_G1_tmp + 2] = rtb_a_idx_2;
    rtb_G2[rtb_G1_tmp + 1] = rtb_a_idx_1;
    rtb_G2[rtb_G1_tmp] = sin_Phi;

    // Product: '<S21>/correct G1'
    sin_Phi = G_omega[rtb_G1_tmp];
    rtb_a_idx_1 = G_omega[rtb_G1_tmp + 1];
    rtb_a_idx_2 = G_omega[rtb_G1_tmp + 2];
    rtb_Reshape_idx_1 = G_omega[rtb_G1_tmp + 3];
    for (i = 0; i < 4; i++) {
      cos_Psi = rtb_G1[rtb_G1_tmp + i];
      stage_ = i << 2;
      sin_Phi += rtb_y_ne[stage_] * cos_Psi;
      rtb_a_idx_1 += rtb_y_ne[stage_ + 1] * cos_Psi;
      rtb_a_idx_2 += rtb_y_ne[stage_ + 2] * cos_Psi;
      rtb_Reshape_idx_1 += rtb_y_ne[stage_ + 3] * cos_Psi;
    }

    G_omega[rtb_G1_tmp + 3] = rtb_Reshape_idx_1;
    G_omega[rtb_G1_tmp + 2] = rtb_a_idx_2;
    G_omega[rtb_G1_tmp + 1] = rtb_a_idx_1;
    G_omega[rtb_G1_tmp] = sin_Phi;
  }

  // Product: '<S21>/correct G2' incorporates:
  //   Delay: '<S26>/Delay1'

  for (i = 0; i < 16; i++) {
    rtb_y_ne[i] = rtDW.Delay1_DSTATE * rtb_G2[i];
  }

  // End of Product: '<S21>/correct G2'

  // DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'
  sin_Phi = rtDW.DiscreteTimeIntegratory_dt_DSTA[0];
  rtb_a_idx_1 = rtDW.DiscreteTimeIntegratory_dt_DSTA[1];
  rtb_a_idx_2 = rtDW.DiscreteTimeIntegratory_dt_DSTA[2];

  // Outputs for Enabled SubSystem: '<S21>/Copter Random Excitation' incorporates:
  //   EnablePort: '<S23>/Enable'

  if (rtDW.CopterRandomExcitation_MODE) {
    // Disable for Gain: '<S23>/Gain1' incorporates:
    //   Outport: '<S23>/yaw_rate_excite'

    rtDW.Gain1 = 0.0F;

    // Disable for Gain: '<S23>/Gain' incorporates:
    //   Outport: '<S23>/s_g_dt2_excite'

    rtDW.Gain[0] = 0.0F;
    rtDW.Gain[1] = 0.0F;
    rtDW.Gain[2] = 0.0F;
    rtDW.CopterRandomExcitation_MODE = false;
  }

  // End of Outputs for SubSystem: '<S21>/Copter Random Excitation'

  // Sum: '<S4>/Add1' incorporates:
  //   Sum: '<S13>/Add1'

  rtb_p_match[0] = rtDW.Gain[0] + rtDW.nu[0];
  rtb_p_match[1] = rtDW.Gain[1] + rtDW.nu[1];
  rtb_p_match[2] = rtDW.Gain[2] + rtDW.nu[2];

  // Outputs for Enabled SubSystem: '<S4>/Pilot Reduced Attitude Commands' incorporates:
  //   EnablePort: '<S14>/Enable'

  // MATLAB Function: '<S14>/MATLAB Function1' incorporates:
  //   Gain: '<S14>/Gain1'
  //   MATLAB Function: '<S14>/MATLAB Function'

  sin_Psi = 3.14159274F * cos_Theta_0;
  sin_Theta = std::sin(sin_Psi);

  // Merge generated from: '<S4>/Merge' incorporates:
  //   MATLAB Function: '<S14>/MATLAB Function1'
  //   SignalConversion generated from: '<S14>/red_atti_des'

  rtDW.n_g_des[0] = sin_Theta * cos_Phi;
  rtDW.n_g_des[1] = sin_Theta * rtb_Gain;
  rtDW.n_g_des[2] = -std::cos(sin_Psi);

  // Merge generated from: '<S4>/Merge' incorporates:
  //   SignalConversion generated from: '<S14>/red_atti_des'

  rtDW.lean_dir_angle_des = rtb_pq_Kb_dt_idx_0;

  // Merge generated from: '<S4>/Merge' incorporates:
  //   MATLAB Function: '<S14>/MATLAB Function'
  //   SignalConversion generated from: '<S14>/red_atti_des'

  rtDW.cmd_lean_angle_01 = cos_Theta_0;

  // End of Outputs for SubSystem: '<S4>/Pilot Reduced Attitude Commands'

  // Outputs for Enabled SubSystem: '<S4>/Vertical Acc to Specific Thrust' incorporates:
  //   EnablePort: '<S17>/Enable'

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   Constant: '<S17>/Constant'
  //   Constant: '<S4>/Constant2'
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  if (rtDW.DiscreteTimeIntegratory_DSTA_br[8] < 0.395975322F) {
    // Merge: '<S4>/Merge1'
    rtDW.Merge1 = 0.0F;
  } else {
    // Merge: '<S4>/Merge1'
    rtDW.Merge1 = (-rtb_p_match[2] + 9.81F) /
      rtDW.DiscreteTimeIntegratory_DSTA_br[8];
  }

  // End of MATLAB Function: '<S17>/MATLAB Function'
  // End of Outputs for SubSystem: '<S4>/Vertical Acc to Specific Thrust'

  // Outputs for Enabled SubSystem: '<S4>/Incremental specific thrust' incorporates:
  //   EnablePort: '<S9>/Enable'

  // DiscreteIntegrator: '<S55>/Discrete-Time Integrator y'
  if (rtDW.DiscreteTimeIntegratory_IC_LO_e != 0) {
    rtDW.DiscreteTimeIntegratory_DSTA_ez[0] = rtDW.n_g_des[0];
    rtDW.DiscreteTimeIntegratory_DSTA_ez[1] = rtDW.n_g_des[1];
    rtDW.DiscreteTimeIntegratory_DSTA_ez[2] = rtDW.n_g_des[2];
  }

  // Product: '<S55>/Product1' incorporates:
  //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y_dt'
  //   Product: '<S55>/Product2'
  //   Sum: '<S55>/Sum2'
  //   Sum: '<S55>/Sum3'

  rtb_p_match_2[0] = (rtDW.n_g_des[0] - (rtDW.DiscreteTimeIntegratory_dt_DS_h[0]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_ez[0])) * 89.9523926F;
  rtb_p_match_2[1] = (rtDW.n_g_des[1] - (rtDW.DiscreteTimeIntegratory_dt_DS_h[1]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_ez[1])) * 89.9523926F;
  rtb_p_match_2[2] = (rtDW.n_g_des[2] - (rtDW.DiscreteTimeIntegratory_dt_DS_h[2]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_ez[2])) * 89.9523926F;

  // MATLAB Function: '<S52>/n ref norm' incorporates:
  //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y_dt'

  nrefnorm(rtDW.DiscreteTimeIntegratory_DSTA_ez,
           rtDW.DiscreteTimeIntegratory_dt_DS_h, rtb_p_match_2, rtb_p_match,
           dir_next_wp, rtb_p_ahead_g);

  // MATLAB Function: '<S9>/DCM 2 Lean Vector' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  DCM2LeanVector(rtDW.DiscreteTimeIntegratory_DSTA_br, rtb_p_ahead_g);

  // MATLAB Function: '<S9>/desired and measured specific thrust' incorporates:
  //   Constant: '<S4>/Constant2'

  cos_Theta_0 = 0.0F;
  rtb_V_Kg_n0[0] = 0.0F;
  rtb_V_Kg_n0[1] = 0.0F;
  rtb_V_Kg_n0[2] = 9.81F;

  // MATLAB Function: '<S9>/incremental thrust atti correction'
  rtb_Gain = 0.0F;

  // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LO_e = 0U;

  // MATLAB Function: '<S9>/desired and measured specific thrust' incorporates:
  //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  cos_Psi = 0.0F;
  for (k = 0; k < 3; k++) {
    i = 3 * k + 2;
    cos_Theta_0 += rtDW.DiscreteTimeIntegratory_DSTA_br[i] *
      rtDW.DiscreteTimeIntegratory_DSTAT_b[k];
    cos_Psi += rtDW.DiscreteTimeIntegratory_DSTA_br[i] * rtb_V_Kg_n0[k];

    // MATLAB Function: '<S9>/incremental thrust atti correction' incorporates:
    //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

    rtb_Gain += rtb_p_ahead_g[k] * rtb_p_match[k];

    // DiscreteIntegrator: '<S55>/Discrete-Time Integrator y_dt' incorporates:
    //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y'

    cos_Phi = rtDW.DiscreteTimeIntegratory_dt_DS_h[k];

    // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTA_ez[k] += 0.0025F * cos_Phi;

    // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator y_dt'
    rtDW.DiscreteTimeIntegratory_dt_DS_h[k] = 0.0025F * rtb_p_match_2[k] +
      cos_Phi;
  }

  rtDW.a_T_meas = cos_Theta_0 - cos_Psi;

  // Sum: '<S9>/Add' incorporates:
  //   Abs: '<S9>/Abs'
  //   DotProduct: '<S9>/Dot Product'
  //   Gain: '<S9>/Gain'
  //   Product: '<S9>/Product'

  rtDW.Delta_nu_a_T = std::abs((rtDW.n_g_des[0] * rtb_p_match[0] + rtDW.n_g_des
    [1] * rtb_p_match[1]) + rtDW.n_g_des[2] * rtb_p_match[2]) * -rtDW.Merge1 -
    rtDW.a_T_meas;

  // MATLAB Function: '<S9>/incremental thrust atti correction'
  if (rtb_Gain < 0.0F) {
    rtDW.Delta_nu_a_T = 0.0F;
  } else {
    rtDW.Delta_nu_a_T *= rtb_Gain;
  }

  // End of Outputs for SubSystem: '<S4>/Incremental specific thrust'

  // DiscreteIntegrator: '<S62>/Discrete-Time Integrator y' incorporates:
  //   Inport: '<Root>/measure'

  if (rtDW.DiscreteTimeIntegratory_IC_LO_m != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_f[0] = rtU.measure.omega_Kb[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_f[1] = rtU.measure.omega_Kb[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_f[2] = rtU.measure.omega_Kb[2];
  }

  // SignalConversion generated from: '<S90>/ SFunction ' incorporates:
  //   Gain: '<S80>/leanmax'
  //   MATLAB Function: '<S72>/lean angles 2 lean vector'
  //   Reshape: '<S11>/Reshape'

  sin_Psi = 3.14159274F * rtDW.cmd_lean_angle_01;

  // MATLAB Function: '<S72>/lean angles 2 lean vector' incorporates:
  //   Reshape: '<S11>/Reshape'

  sin_Theta = std::sin(sin_Psi);
  rtb_p_match_2[0] = sin_Theta * std::cos(rtDW.lean_dir_angle_des);
  rtb_p_match_2[1] = sin_Theta * std::sin(rtDW.lean_dir_angle_des);
  rtb_p_match_2[2] = -std::cos(sin_Psi);

  // DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'
  if (rtDW.DiscreteTimeIntegratory_IC_LO_d != 0) {
    rtDW.DiscreteTimeIntegratory_DSTA_by[0] = rtb_p_match_2[0];
    rtDW.DiscreteTimeIntegratory_DSTA_by[1] = rtb_p_match_2[1];
    rtDW.DiscreteTimeIntegratory_DSTA_by[2] = rtb_p_match_2[2];
  }

  // Product: '<S92>/Product1' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt'
  //   Product: '<S92>/Product2'
  //   Sum: '<S92>/Sum2'
  //   Sum: '<S92>/Sum3'

  rtb_p_match_2[0] = (rtb_p_match_2[0] - (rtDW.DiscreteTimeIntegratory_dt_DS_o[0]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_by[0])) * 89.9523926F;
  rtb_p_match_2[1] = (rtb_p_match_2[1] - (rtDW.DiscreteTimeIntegratory_dt_DS_o[1]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_by[1])) * 89.9523926F;
  rtb_p_match_2[2] = (rtb_p_match_2[2] - (rtDW.DiscreteTimeIntegratory_dt_DS_o[2]
    * 0.210874289F + rtDW.DiscreteTimeIntegratory_DSTA_by[2])) * 89.9523926F;

  // MATLAB Function: '<S86>/n ref norm' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt'

  nrefnorm(rtDW.DiscreteTimeIntegratory_DSTA_by,
           rtDW.DiscreteTimeIntegratory_dt_DS_o, rtb_p_match_2, rtb_p_ahead_g,
           rtb_V_Kg_n0, rtb_n_dt2_p);

  // DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'
  if (rtDW.DiscreteTimeIntegratory_IC_L_bz != 0) {
    rtDW.DiscreteTimeIntegratory_DSTAT_k[0] = rtb_p_ahead_g[0];
    rtDW.DiscreteTimeIntegratory_DSTAT_k[1] = rtb_p_ahead_g[1];
    rtDW.DiscreteTimeIntegratory_DSTAT_k[2] = rtb_p_ahead_g[2];
  }

  // Product: '<S94>/Product1' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt'
  //   Product: '<S94>/Product2'
  //   Sum: '<S94>/Sum2'
  //   Sum: '<S94>/Sum3'

  dir_next_wp[0] = (rtb_p_ahead_g[0] - (rtDW.DiscreteTimeIntegratory_dt_DS_n[0] *
    0.0602498F + rtDW.DiscreteTimeIntegratory_DSTAT_k[0])) * 1101.91663F;
  dir_next_wp[1] = (rtb_p_ahead_g[1] - (rtDW.DiscreteTimeIntegratory_dt_DS_n[1] *
    0.0602498F + rtDW.DiscreteTimeIntegratory_DSTAT_k[1])) * 1101.91663F;
  dir_next_wp[2] = (rtb_p_ahead_g[2] - (rtDW.DiscreteTimeIntegratory_dt_DS_n[2] *
    0.0602498F + rtDW.DiscreteTimeIntegratory_DSTAT_k[2])) * 1101.91663F;

  // MATLAB Function: '<S87>/n ref norm' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt'

  nrefnorm(rtDW.DiscreteTimeIntegratory_DSTAT_k,
           rtDW.DiscreteTimeIntegratory_dt_DS_n, dir_next_wp, rtb_p_match,
           rtb_n_dt, rtb_n_dt2);

  // MATLAB Function: '<S72>/Desired Roll Pitch' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  Omega_Kg_des[0] = rtb_p_match[1] * rtb_n_dt[2] - rtb_n_dt[1] * rtb_p_match[2];
  Omega_Kg_des[1] = rtb_n_dt[0] * rtb_p_match[2] - rtb_p_match[0] * rtb_n_dt[2];
  Omega_Kg_des[2] = rtb_p_match[0] * rtb_n_dt[1] - rtb_n_dt[0] * rtb_p_match[1];
  cos_Theta = 0.0F;
  sin_Psi = 0.0F;
  for (k = 0; k < 3; k++) {
    cos_Psi = Omega_Kg_des[k];
    cos_Theta += rtDW.DiscreteTimeIntegratory_DSTA_br[3 * k] * cos_Psi;
    sin_Psi += rtDW.DiscreteTimeIntegratory_DSTA_br[3 * k + 1] * cos_Psi;
  }

  // Sum: '<S67>/error1 1' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'

  cos_Theta_0 = cos_Theta - rtDW.DiscreteTimeIntegratory_DSTAT_f[0];
  rtb_Reshape_idx_1 = sin_Psi - rtDW.DiscreteTimeIntegratory_DSTAT_f[1];

  // MATLAB Function: '<S72>/Desired Roll Pitch' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'

  rtb_n_b_dt[0] = rtb_p_match[1] * rtb_n_dt2[2] - rtb_n_dt2[1] * rtb_p_match[2];
  rtb_n_b_dt[1] = rtb_n_dt2[0] * rtb_p_match[2] - rtb_p_match[0] * rtb_n_dt2[2];
  rtb_n_b_dt[2] = rtb_p_match[0] * rtb_n_dt2[1] - rtb_n_dt2[0] * rtb_p_match[1];
  tmp[0] = 0.0F;
  tmp[3] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[2];
  tmp[6] = rtDW.DiscreteTimeIntegratory_DSTAT_f[1];
  tmp[1] = rtDW.DiscreteTimeIntegratory_DSTAT_f[2];
  tmp[4] = 0.0F;
  tmp[7] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[0];
  tmp[2] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[1];
  tmp[5] = rtDW.DiscreteTimeIntegratory_DSTAT_f[0];
  tmp[8] = 0.0F;
  for (k = 0; k < 3; k++) {
    cos_Psi = tmp[3 * k + 1];
    A_tmp_1 = tmp[3 * k];
    A_tmp_2 = tmp[3 * k + 2];
    for (i = 0; i < 3; i++) {
      tmp_0[i + 3 * k] = (rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i + 1] *
                          cos_Psi + rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i] *
                          A_tmp_1) + rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i
        + 2] * A_tmp_2;
    }
  }

  cos_Theta = 0.0F;
  sin_Psi = 0.0F;
  cos_Psi = 0.0F;
  A_tmp_1 = 0.0F;
  for (k = 0; k < 3; k++) {
    tmp[3 * k] = tmp_0[k];
    i = 3 * k + 1;
    tmp[i] = tmp_0[k + 3];
    tmp[3 * k + 2] = tmp_0[k + 6];
    A_tmp_2 = rtb_n_b_dt[k];
    cos_Psi += rtDW.DiscreteTimeIntegratory_DSTA_br[3 * k] * A_tmp_2;
    A_tmp_1 += rtDW.DiscreteTimeIntegratory_DSTA_br[i] * A_tmp_2;
    A_tmp_2 = Omega_Kg_des[k];
    cos_Theta += tmp[3 * k] * A_tmp_2;
    sin_Psi += tmp[i] * A_tmp_2;
  }

  // Sum: '<S67>/error1 2' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'
  //   MATLAB Function: '<S72>/Desired Roll Pitch'

  rtb_pq_Kb_dt_idx_0 = (cos_Psi + cos_Theta) -
    rtDW.DiscreteTimeIntegratory_dt_DSTA[0];
  rtb_pq_Kb_dt_idx_1 = (A_tmp_1 + sin_Psi) -
    rtDW.DiscreteTimeIntegratory_dt_DSTA[1];

  // MATLAB Function: '<S72>/Lean Vector Derivative Trafo Delay' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'

  LeanVectorDerivativeTrafo(rtb_p_match, rtb_n_dt, rtb_n_dt2,
    rtDW.DiscreteTimeIntegratory_DSTA_br, rtDW.DiscreteTimeIntegratory_DSTAT_f,
    rtDW.DiscreteTimeIntegratory_dt_DSTA, Omega_Kg_des, rtb_n_b_dt,
    &rtb_Transpose[0]);

  // MATLAB Function: '<S72>/Lean Vector Derivative Trafo' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'

  LeanVectorDerivativeTrafo(rtb_p_ahead_g, rtb_V_Kg_n0, rtb_n_dt2_p,
    rtDW.DiscreteTimeIntegratory_DSTA_br, rtDW.DiscreteTimeIntegratory_DSTAT_f,
    rtDW.DiscreteTimeIntegratory_dt_DSTA, rtb_n_dt, rtb_n_dt2, rtb_p_match);

  // MATLAB Function: '<S72>/MATLAB Function'
  rtb_n_dt[0] = Omega_Kg_des[0];
  rtb_n_dt2[0] = rtb_Transpose[0];
  rtb_n_dt[1] = Omega_Kg_des[1];
  rtb_n_dt2[1] = rtb_Transpose[1];
  if (Omega_Kg_des[2] > 0.0F) {
    if (Omega_Kg_des[2] > 0.999) {
      sin_Psi = 0.0F;
      Omega_Kg_des[0] = 0.0F;
      cos_Theta = -1.0F;
      Omega_Kg_des[1] = 0.0F;
    } else {
      rtb_Gain = 1.29246971E-26F;
      sin_Psi = std::abs(Omega_Kg_des[0]);
      if (sin_Psi > 1.29246971E-26F) {
        cos_Theta = 1.0F;
        rtb_Gain = sin_Psi;
      } else {
        sin_Theta = sin_Psi / 1.29246971E-26F;
        cos_Theta = sin_Theta * sin_Theta;
      }

      sin_Psi = std::abs(Omega_Kg_des[1]);
      if (sin_Psi > rtb_Gain) {
        sin_Theta = rtb_Gain / sin_Psi;
        cos_Theta = cos_Theta * sin_Theta * sin_Theta + 1.0F;
        rtb_Gain = sin_Psi;
      } else {
        sin_Theta = sin_Psi / rtb_Gain;
        cos_Theta += sin_Theta * sin_Theta;
      }

      cos_Theta = rtb_Gain * std::sqrt(cos_Theta);
      if (cos_Theta < 2.22044605E-16F) {
        cos_Theta = 2.22044605E-16F;
      }

      sin_Psi = Omega_Kg_des[0] / cos_Theta;
      cos_Theta = Omega_Kg_des[1] / cos_Theta;
    }

    rtb_n_dt[0] = 2.0F * sin_Psi - Omega_Kg_des[0];
    rtb_n_b_dt[0] = -rtb_n_b_dt[0];
    rtb_n_dt2[0] = -rtb_Transpose[0];
    rtb_n_dt[1] = 2.0F * cos_Theta - Omega_Kg_des[1];
    rtb_n_b_dt[1] = -rtb_n_b_dt[1];
    rtb_n_dt2[1] = -rtb_Transpose[1];
  }

  // MATLAB Function: '<S66>/Reduced Attitude Weighting Factors' incorporates:
  //   MATLAB Function: '<S72>/MATLAB Function'

  rtb_Gain = 0.0F - Omega_Kg_des[2];
  if (0.0F - Omega_Kg_des[2] < 0.0F) {
    rtb_Gain = 0.0F;
  }

  // Product: '<S91>/Divide' incorporates:
  //   Constant: '<S91>/T'
  //   DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
  //   Gain: '<S72>/r_max'
  //   Inport: '<Root>/cmd'
  //   Sum: '<S4>/Add'
  //   Sum: '<S91>/Sum2'

  cos_Phi = ((rtDW.Gain1 + rtU.cmd.yaw) * 6.28318548F -
             rtDW.DiscreteTimeIntegrator_DSTATE_l) / 0.225452587F;

  // MATLAB Function: '<S67>/wrap angle' incorporates:
  //   DiscreteIntegrator: '<S72>/Discrete-Time Integrator2'

  wrapangle(rtDW.DiscreteTimeIntegrator2_DSTATE, &cos_Theta);

  // MATLAB Function: '<S68>/DCM to quaternions' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  DCMtoquaternions(rtDW.DiscreteTimeIntegratory_DSTA_br, rtb_y_dy);

  // MATLAB Function: '<S68>/Quaternion Reduced'
  QuaternionReduced(rtb_y_dy, rtb_q_red_j, &sin_Theta);

  // MATLAB Function: '<S67>/wrap angle1'
  wrapangle(sin_Theta, &cos_Psi);

  // MATLAB Function: '<S67>/angle error'
  sin_Theta = cos_Theta - cos_Psi;
  if (sin_Theta > 3.1415926535897931) {
    sin_Theta -= 6.28318548F;
  } else if (sin_Theta < -3.1415926535897931) {
    sin_Theta += 6.28318548F;
  }

  // End of MATLAB Function: '<S67>/angle error'

  // Gain: '<S70>/Gain' incorporates:
  //   MATLAB Function: '<S72>/MATLAB Function'

  rtb_p_match_1 = rtb_p_match[1];
  rtb_p_match_0 = rtb_p_match[0];

  // MATLAB Function: '<S72>/Pseudo-Control Roll Pitch' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'

  rtb_p_match[0] = rtb_p_ahead_g[1] * rtb_n_dt2_p[2] - rtb_n_dt2_p[1] *
    rtb_p_ahead_g[2];
  rtb_p_match[1] = rtb_n_dt2_p[0] * rtb_p_ahead_g[2] - rtb_p_ahead_g[0] *
    rtb_n_dt2_p[2];
  rtb_p_match[2] = rtb_p_ahead_g[0] * rtb_n_dt2_p[1] - rtb_n_dt2_p[0] *
    rtb_p_ahead_g[1];
  tmp[0] = 0.0F;
  tmp[3] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[2];
  tmp[6] = rtDW.DiscreteTimeIntegratory_DSTAT_f[1];
  tmp[1] = rtDW.DiscreteTimeIntegratory_DSTAT_f[2];
  tmp[4] = 0.0F;
  tmp[7] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[0];
  tmp[2] = -rtDW.DiscreteTimeIntegratory_DSTAT_f[1];
  tmp[5] = rtDW.DiscreteTimeIntegratory_DSTAT_f[0];
  tmp[8] = 0.0F;
  for (k = 0; k < 3; k++) {
    cos_Psi = tmp[3 * k + 1];
    A_tmp_1 = tmp[3 * k];
    A_tmp_2 = tmp[3 * k + 2];
    for (i = 0; i < 3; i++) {
      tmp_0[i + 3 * k] = (rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i + 1] *
                          cos_Psi + rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i] *
                          A_tmp_1) + rtDW.DiscreteTimeIntegratory_DSTA_br[3 * i
        + 2] * A_tmp_2;
    }
  }

  rtb_n_dt2_p[0] = rtb_p_ahead_g[1] * rtb_V_Kg_n0[2] - rtb_V_Kg_n0[1] *
    rtb_p_ahead_g[2];
  rtb_n_dt2_p[1] = rtb_V_Kg_n0[0] * rtb_p_ahead_g[2] - rtb_p_ahead_g[0] *
    rtb_V_Kg_n0[2];
  rtb_n_dt2_p[2] = rtb_p_ahead_g[0] * rtb_V_Kg_n0[1] - rtb_V_Kg_n0[0] *
    rtb_p_ahead_g[1];
  cos_Theta = 0.0F;
  sin_Psi = 0.0F;
  cos_Psi = 0.0F;
  A_tmp_1 = 0.0F;
  for (k = 0; k < 3; k++) {
    tmp[3 * k] = tmp_0[k];
    i = 3 * k + 1;
    tmp[i] = tmp_0[k + 3];
    tmp[3 * k + 2] = tmp_0[k + 6];
    A_tmp_2 = rtb_p_match[k];
    cos_Psi += rtDW.DiscreteTimeIntegratory_DSTA_br[3 * k] * A_tmp_2;
    A_tmp_1 += rtDW.DiscreteTimeIntegratory_DSTA_br[i] * A_tmp_2;
    A_tmp_2 = rtb_n_dt2_p[k];
    cos_Theta += tmp[3 * k] * A_tmp_2;
    sin_Psi += tmp[i] * A_tmp_2;
  }

  // Sum: '<S11>/Add2' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'
  //   DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
  //   Gain: '<S69>/Gain'
  //   Gain: '<S69>/Gain1'
  //   Gain: '<S69>/Gain2'
  //   Gain: '<S69>/Gain3'
  //   Gain: '<S69>/Gain4'
  //   Gain: '<S69>/Gain5'
  //   Gain: '<S69>/Gain6'
  //   Gain: '<S69>/Gain7'
  //   Gain: '<S69>/Gain8'
  //   Gain: '<S70>/Gain'
  //   MATLAB Function: '<S66>/Reduced Attitude Weighting Factors'
  //   MATLAB Function: '<S72>/Pseudo-Control Roll Pitch'
  //   MATLAB Function: '<S72>/Simulink Trickster'
  //   Product: '<S69>/Product'
  //   Product: '<S69>/Product1'
  //   Product: '<S69>/Product3'
  //   Product: '<S69>/Product4'
  //   Product: '<S70>/Product'
  //   Product: '<S70>/Product1'
  //   Product: '<S71>/Product'
  //   Sum: '<S11>/Add1'
  //   Sum: '<S61>/Sum2'
  //   Sum: '<S67>/error1 1'
  //   Sum: '<S67>/error1 2'
  //   Sum: '<S67>/error1 4'
  //   Sum: '<S67>/error1 5'
  //   Sum: '<S67>/error1 6'
  //   Sum: '<S67>/error1 8'
  //   Sum: '<S67>/error1 9'
  //   Sum: '<S69>/Add'
  //   Sum: '<S69>/Add1'
  //   Sum: '<S69>/Add2'
  //   Sum: '<S69>/Add3'
  //   Sum: '<S70>/Add'
  //   Sum: '<S71>/Add'

  rtb_p_match[0] = (((((1.0F - rtb_Gain) * cos_Theta_0 + rtb_Gain * rtb_n_b_dt[1])
                      * 16.2588387F + 51.4013634F * rtb_n_dt[1]) + ((1.0F -
    rtb_Gain) * rtb_pq_Kb_dt_idx_0 + rtb_Gain * rtb_n_dt2[1]) * 0.714285731F) +
                    ((1.0F - rtb_Gain) * (cos_Psi + cos_Theta) + rtb_Gain *
                     rtb_p_match_1)) - (1.0F - rtb_Gain) *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[0];
  rtb_p_match[1] = (((((1.0F - rtb_Gain) * rtb_Reshape_idx_1 + rtb_Gain *
                       -rtb_n_b_dt[0]) * 16.2588387F + 51.4013634F * -rtb_n_dt[0])
                     + ((1.0F - rtb_Gain) * rtb_pq_Kb_dt_idx_1 + rtb_Gain *
                        -rtb_n_dt2[0]) * 0.714285731F) + ((1.0F - rtb_Gain) *
    (A_tmp_1 + sin_Psi) + rtb_Gain * -rtb_p_match_0)) - (1.0F - rtb_Gain) *
    rtDW.DiscreteTimeIntegratory_dt_DSTA[1];
  rtb_p_match[2] = ((((rtDW.DiscreteTimeIntegrator_DSTATE_l -
                       rtDW.DiscreteTimeIntegratory_DSTAT_f[2]) * 3.55603814F +
                      5.25762892F * sin_Theta) + (cos_Phi -
    rtDW.DiscreteTimeIntegratory_dt_DSTA[2]) * -0.198281989F) + cos_Phi) -
    rtDW.DiscreteTimeIntegratory_dt_DSTA[2];

  // Product: '<S41>/MatrixMultiply2' incorporates:
  //   Product: '<S21>/correct G2'
  //   Switch: '<S8>/Switch1'
  //   UnitDelay: '<S41>/Unit Delay1'

  rtb_Gain = 0.0F;
  cos_Theta = 0.0F;
  sin_Theta = 0.0F;
  sin_Psi = 0.0F;
  for (k = 0; k < 4; k++) {
    cos_Psi = rtDW.UnitDelay1_DSTATE_m[k];
    i = k << 2;
    rtb_Gain += rtb_y_ne[i] * cos_Psi;
    cos_Theta += rtb_y_ne[i + 1] * cos_Psi;
    sin_Theta += rtb_y_ne[i + 2] * cos_Psi;
    sin_Psi += rtb_y_ne[i + 3] * cos_Psi;
  }

  // End of Product: '<S41>/MatrixMultiply2'

  // Sum: '<S41>/Add2'
  rtb_q_red_j[0] = rtb_p_match[0] + rtb_Gain;
  rtb_q_red_j[1] = rtb_p_match[1] + cos_Theta;
  rtb_q_red_j[2] = rtb_p_match[2] + sin_Theta;
  rtb_q_red_j[3] = rtDW.Delta_nu_a_T + sin_Psi;

  // MATLAB Function: '<S10>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  DCM2LeanVector(rtDW.DiscreteTimeIntegratory_DSTA_br, rtb_p_match);

  // MATLAB Function: '<S8>/Control Allocation Vertical Acc Weighting'
  rtb_Gain = (rtb_p_match[0] * rtDW.n_g_des[0] + rtb_p_match[1] * rtDW.n_g_des[1])
    + rtb_p_match[2] * rtDW.n_g_des[2];

  // MATLAB Function: '<S45>/caIndiWls' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  rtb_y_dy[0] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[0]) + (1.0F -
    rtDW.DiscreteTimeIntegrator_DSTATE[0])) * 0.5F;
  if (0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[0] >= -0.9F) {
    umin[0] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[0];
  } else {
    umin[0] = -0.9F;
  }

  if (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[0] <= 0.9F) {
    umax[0] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[0];
  } else {
    umax[0] = 0.9F;
  }

  rtb_y_dy[1] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[1]) + (1.0F -
    rtDW.DiscreteTimeIntegrator_DSTATE[1])) * 0.5F;
  if (0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[1] >= -0.9F) {
    umin[1] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[1];
  } else {
    umin[1] = -0.9F;
  }

  if (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[1] <= 0.9F) {
    umax[1] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[1];
  } else {
    umax[1] = 0.9F;
  }

  rtb_y_dy[2] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[2]) + (1.0F -
    rtDW.DiscreteTimeIntegrator_DSTATE[2])) * 0.5F;
  if (0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[2] >= -0.9F) {
    umin[2] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[2];
  } else {
    umin[2] = -0.9F;
  }

  if (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[2] <= 0.9F) {
    umax[2] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[2];
  } else {
    umax[2] = 0.9F;
  }

  rtb_y_dy[3] = ((0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3]) + (1.0F -
    rtDW.DiscreteTimeIntegrator_DSTATE[3])) * 0.5F;
  if (0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3] >= -0.9F) {
    umin[3] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[3];
  } else {
    umin[3] = -0.9F;
  }

  if (1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[3] <= 0.9F) {
    umax[3] = 1.0F - rtDW.DiscreteTimeIntegrator_DSTATE[3];
  } else {
    umax[3] = 0.9F;
  }

  std::memset(&W_v[0], 0, sizeof(real_T) << 4U);
  W_v[0] = 10.0;
  W_v[5] = 10.0;
  W_v[10] = 0.01;
  W_v[15] = 1.0;
  std::memset(&b_d[0], 0, sizeof(real_T) << 4U);
  b_d[0] = 0.0;
  b_d[5] = 0.0;
  b_d[10] = 0.0;

  // MATLAB Function: '<S8>/Control Allocation Vertical Acc Weighting'
  if (rtb_Gain < 0.0F) {
    cos_Psi = 0.0F;
  } else {
    cos_Psi = rtb_Gain * rtb_Gain * -9.0F + 10.0F;
  }

  // MATLAB Function: '<S45>/caIndiWls' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
  //   MATLAB Function: '<S8>/Control Allocation Vertical Acc Weighting'
  //   Sum: '<S41>/Add2'

  b_d[15] = cos_Psi - 1.0F;
  rtb_Output[0] = 0.0;
  rtb_Output[1] = 0.0;
  rtb_Output[2] = 0.0;
  rtb_Output[3] = 0.0;
  for (k = 0; k < 16; k++) {
    W_v_0 = W_v[k] + b_d[k];
    W_v[k] = W_v_0;
    b_d[k] = 0.0;
    rtb_G2[k] = static_cast<real32_T>(31.622776601683793 * W_v_0);

    // Sum: '<S41>/Add1' incorporates:
    //   Product: '<S21>/correct G1'
    //   Product: '<S21>/correct G2'
    //   Switch: '<S8>/Switch'
    //   Switch: '<S8>/Switch1'

    G_omega_0[k] = G_omega[k] + rtb_y_ne[k];
  }

  b_d[0] = 1.0;
  b_d[5] = 1.0;
  b_d[10] = 1.0;
  b_d[15] = 1.0;
  rtb_Gain = 0.0F;
  cos_Theta = 0.0F;
  sin_Theta = 0.0F;
  sin_Psi = 0.0F;
  for (k = 0; k < 4; k++) {
    rtb_p_match_1 = 0.0F;
    A_tmp_1 = 0.0F;
    A_tmp_2 = 0.0F;
    rtb_p_match_0 = 0.0F;
    for (i = 0; i < 4; i++) {
      cos_Psi = G_omega_0[(k << 2) + i];
      stage_ = i << 2;
      rtb_p_match_1 += rtb_G2[stage_] * cos_Psi;
      A_tmp_1 += rtb_G2[stage_ + 1] * cos_Psi;
      A_tmp_2 += rtb_G2[stage_ + 2] * cos_Psi;
      rtb_p_match_0 += rtb_G2[stage_ + 3] * cos_Psi;
    }

    i = k << 3;
    A[i] = rtb_p_match_1;
    stage_ = k << 2;
    A[i + 4] = static_cast<real32_T>(b_d[stage_]);
    A[i + 1] = A_tmp_1;
    A[i + 5] = static_cast<real32_T>(b_d[stage_ + 1]);
    A[i + 2] = A_tmp_2;
    A[i + 6] = static_cast<real32_T>(b_d[stage_ + 2]);
    A[i + 3] = rtb_p_match_0;
    A[i + 7] = static_cast<real32_T>(b_d[stage_ + 3]);
    p_free_data[k] = 0.1F - rtDW.DiscreteTimeIntegrator_DSTATE[k];
    cos_Psi = rtb_q_red_j[k];
    rtb_Gain += rtb_G2[stage_] * cos_Psi;
    cos_Theta += rtb_G2[stage_ + 1] * cos_Psi;
    sin_Theta += rtb_G2[stage_ + 2] * cos_Psi;
    sin_Psi += rtb_G2[stage_ + 3] * cos_Psi;
  }

  A_tmp[3] = sin_Psi;
  A_tmp[2] = sin_Theta;
  A_tmp[1] = cos_Theta;
  A_tmp[0] = rtb_Gain;
  rtb_Gain = 0.0F;
  cos_Theta = 0.0F;
  sin_Theta = 0.0F;
  sin_Psi = 0.0F;
  for (k = 0; k < 4; k++) {
    cos_Psi = p_free_data[k];
    i = k << 2;
    rtb_Gain += static_cast<real32_T>(b_d[i]) * cos_Psi;
    cos_Theta += static_cast<real32_T>(b_d[i + 1]) * cos_Psi;
    sin_Theta += static_cast<real32_T>(b_d[i + 2]) * cos_Psi;
    sin_Psi += static_cast<real32_T>(b_d[i + 3]) * cos_Psi;
    A_tmp_0[k] = A_tmp[k];
  }

  A_tmp_0[4] = rtb_Gain;
  A_tmp_0[5] = cos_Theta;
  A_tmp_0[6] = sin_Theta;
  A_tmp_0[7] = sin_Psi;
  for (k = 0; k < 8; k++) {
    A_0[k] = 0.0F;
  }

  for (k = 0; k < 4; k++) {
    cos_Psi = rtb_y_dy[k];
    for (i = 0; i < 8; i++) {
      A_0[i] += A[(k << 3) + i] * cos_Psi;
    }
  }

  for (k = 0; k < 8; k++) {
    d[k] = A_tmp_0[k] - A_0[k];
  }

  i_free[0] = true;
  i_free[1] = true;
  i_free[2] = true;
  i_free[3] = true;
  stage_ = 0;
  exitg1 = false;
  while ((!exitg1) && (stage_ <= 99)) {
    k = 0;
    for (i = 0; i < 4; i++) {
      if (i_free[i]) {
        k++;
      }
    }

    rtb_G1_tmp = k;
    k = 0;
    for (i = 0; i < 4; i++) {
      if (i_free[i]) {
        tmp_data[k] = i;
        k++;
      }
    }

    A_size[0] = 8;
    A_size[1] = rtb_G1_tmp;
    for (k = 0; k < rtb_G1_tmp; k++) {
      for (i = 0; i < 8; i++) {
        A_data[i + (k << 3)] = A[(tmp_data[k] << 3) + i];
      }
    }

    mldivide(A_data, A_size, d, p_free_data, &i);
    p[0] = 0.0;
    p[1] = 0.0;
    p[2] = 0.0;
    p[3] = 0.0;
    for (k = 0; k < i; k++) {
      p[static_cast<int8_T>(tmp_data[k])] = p_free_data[k];
    }

    u_opt[0] = rtb_y_dy[0] + static_cast<real32_T>(p[0]);
    u_opt[1] = rtb_y_dy[1] + static_cast<real32_T>(p[1]);
    u_opt[2] = rtb_y_dy[2] + static_cast<real32_T>(p[2]);
    u_opt[3] = rtb_y_dy[3] + static_cast<real32_T>(p[3]);
    rtb_Compare = false;
    rtb_G2_tmp = 0;
    exitg2 = false;
    while ((!exitg2) && (rtb_G2_tmp + 1 <= rtb_G1_tmp)) {
      cos_Psi = u_opt[tmp_data[rtb_G2_tmp]];
      if ((cos_Psi < umin[tmp_data[rtb_G2_tmp]]) || (cos_Psi >
           umax[tmp_data[rtb_G2_tmp]])) {
        rtb_Compare = true;
        exitg2 = true;
      } else {
        rtb_G2_tmp++;
      }
    }

    if (!rtb_Compare) {
      rtb_y_dy[0] = u_opt[0];
      rtb_y_dy[1] = u_opt[1];
      rtb_y_dy[2] = u_opt[2];
      rtb_y_dy[3] = u_opt[3];
      for (k = 0; k < 8; k++) {
        cos_Psi = 0.0F;
        for (i = 0; i < rtb_G1_tmp; i++) {
          cos_Psi += A[(tmp_data[i] << 3) + k] * p_free_data[i];
        }

        d[k] -= cos_Psi;
      }

      for (i = 0; i < 4; i++) {
        cos_Psi = 0.0F;
        for (k = 0; k < 8; k++) {
          cos_Psi += A[(i << 3) + k] * d[k];
        }

        cos_Psi *= static_cast<real32_T>(rtb_Output[i]);
        u_opt[i] = cos_Psi;
        infeasible[i] = (cos_Psi >= -2.22044605E-16F);
      }

      rtb_Compare = true;
      rtb_G2_tmp = 0;
      exitg2 = false;
      while ((!exitg2) && (rtb_G2_tmp < 4)) {
        if (!infeasible[rtb_G2_tmp]) {
          rtb_Compare = false;
          exitg2 = true;
        } else {
          rtb_G2_tmp++;
        }
      }

      if (rtb_Compare) {
        exitg1 = true;
      } else {
        rtb_Gain = u_opt[0];
        rtb_G2_tmp = 0;
        if (u_opt[0] > u_opt[1]) {
          rtb_Gain = u_opt[1];
          rtb_G2_tmp = 1;
        }

        if (rtb_Gain > u_opt[2]) {
          rtb_Gain = u_opt[2];
          rtb_G2_tmp = 2;
        }

        if (rtb_Gain > u_opt[3]) {
          rtb_G2_tmp = 3;
        }

        rtb_Output[rtb_G2_tmp] = 0.0;
        i_free[rtb_G2_tmp] = true;
        stage_++;
      }
    } else {
      x[0] = 1.0;
      x[1] = 1.0;
      x[2] = 1.0;
      x[3] = 1.0;
      for (i = 0; i < 4; i++) {
        W_v_0 = p[i];
        rtb_Compare = i_free[i];
        if (rtb_Compare && (W_v_0 < 0.0)) {
          x[i] = (umin[i] - rtb_y_dy[i]) / static_cast<real32_T>(W_v_0);
        }

        if (rtb_Compare && (W_v_0 > 0.0)) {
          x[i] = (umax[i] - rtb_y_dy[i]) / static_cast<real32_T>(W_v_0);
        }
      }

      W_v_0 = x[0];
      rtb_G2_tmp = 0;
      if (x[0] > x[1]) {
        W_v_0 = x[1];
        rtb_G2_tmp = 1;
      }

      if (W_v_0 > x[2]) {
        W_v_0 = x[2];
        rtb_G2_tmp = 2;
      }

      if (W_v_0 > x[3]) {
        W_v_0 = x[3];
        rtb_G2_tmp = 3;
      }

      rtb_y_dy[0] += static_cast<real32_T>(W_v_0 * p[0]);
      rtb_y_dy[1] += static_cast<real32_T>(W_v_0 * p[1]);
      rtb_y_dy[2] += static_cast<real32_T>(W_v_0 * p[2]);
      rtb_y_dy[3] += static_cast<real32_T>(W_v_0 * p[3]);
      for (k = 0; k < 8; k++) {
        cos_Psi = 0.0F;
        for (i = 0; i < rtb_G1_tmp; i++) {
          cos_Psi += A[(tmp_data[i] << 3) + k] * static_cast<real32_T>(W_v_0) *
            p_free_data[i];
        }

        d[k] -= cos_Psi;
      }

      W_v_0 = p[rtb_G2_tmp];
      if (W_v_0 < 0.0) {
        rtb_Output[rtb_G2_tmp] = -1.0;
      } else {
        rtb_Output[rtb_G2_tmp] = (W_v_0 > 0.0);
      }

      i_free[rtb_G2_tmp] = false;
      stage_++;
    }
  }

  // Sum: '<S8>/Add6' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'

  rtb_Gain = rtb_y_dy[0] + rtDW.DiscreteTimeIntegratory_DSTA_eg[0];

  // Saturate: '<S8>/Saturation3'
  if (rtb_Gain > 1.0F) {
    rtb_Gain = 1.0F;
  } else if (rtb_Gain < 0.1F) {
    rtb_Gain = 0.1F;
  }

  rtb_q_red_j[0] = rtb_Gain;

  // Outport: '<Root>/logs' incorporates:
  //   MATLAB Function: '<S3>/Auxiliary function to define log_config in generated C++ code'
  //   SignalConversion generated from: '<S134>/ SFunction '

  rtY.logs[0] = rtb_Gain;

  // Sum: '<S8>/Add6' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'

  rtb_Gain = rtb_y_dy[1] + rtDW.DiscreteTimeIntegratory_DSTA_eg[1];

  // Saturate: '<S8>/Saturation3'
  if (rtb_Gain > 1.0F) {
    rtb_Gain = 1.0F;
  } else if (rtb_Gain < 0.1F) {
    rtb_Gain = 0.1F;
  }

  rtb_q_red_j[1] = rtb_Gain;

  // Outport: '<Root>/logs' incorporates:
  //   MATLAB Function: '<S3>/Auxiliary function to define log_config in generated C++ code'
  //   SignalConversion generated from: '<S134>/ SFunction '

  rtY.logs[1] = rtb_Gain;

  // Sum: '<S8>/Add6' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'

  rtb_Gain = rtb_y_dy[2] + rtDW.DiscreteTimeIntegratory_DSTA_eg[2];

  // Saturate: '<S8>/Saturation3'
  if (rtb_Gain > 1.0F) {
    rtb_Gain = 1.0F;
  } else if (rtb_Gain < 0.1F) {
    rtb_Gain = 0.1F;
  }

  rtb_q_red_j[2] = rtb_Gain;

  // Outport: '<Root>/logs' incorporates:
  //   MATLAB Function: '<S3>/Auxiliary function to define log_config in generated C++ code'
  //   SignalConversion generated from: '<S134>/ SFunction '

  rtY.logs[2] = rtb_Gain;

  // Sum: '<S8>/Add6' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'

  rtb_Gain = rtb_y_dy[3] + rtDW.DiscreteTimeIntegratory_DSTA_eg[3];

  // Saturate: '<S8>/Saturation3'
  if (rtb_Gain > 1.0F) {
    rtb_Gain = 1.0F;
  } else if (rtb_Gain < 0.1F) {
    rtb_Gain = 0.1F;
  }

  // Outport: '<Root>/logs' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'
  //   MATLAB Function: '<S3>/Auxiliary function to define log_config in generated C++ code'
  //   SignalConversion generated from: '<S134>/ SFunction '

  rtY.logs[3] = rtb_Gain;
  rtY.logs[4] = rtDW.Add[0];
  rtY.logs[5] = rtDW.Add[1];
  rtY.logs[6] = rtDW.Add[2];
  rtY.logs[7] = cos_Theta_0;
  rtY.logs[9] = rtb_pq_Kb_dt_idx_0;
  rtY.logs[8] = rtb_Reshape_idx_1;
  rtY.logs[10] = rtb_pq_Kb_dt_idx_1;
  rtY.logs[11] = rtDW.DiscreteTimeIntegratory_dt_DSTA[0];
  rtY.logs[12] = rtDW.DiscreteTimeIntegratory_dt_DSTA[1];
  rtY.logs[13] = rtDW.DiscreteTimeIntegratory_dt_DSTA[2];
  rtY.logs[14] = 0.0F;

  // Sum: '<S59>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y_dt'
  //   Product: '<S59>/Product2'
  //   Sum: '<S59>/Sum3'

  for (k = 0; k < 9; k++) {
    rtb_Transpose[k] = rtb_M_bg[k] - (rtDW.DiscreteTimeIntegratory_dt_D_jl[k] *
      0.0301249F + rtDW.DiscreteTimeIntegratory_DSTA_br[k]);
  }

  // End of Sum: '<S59>/Sum2'

  // Outport: '<Root>/u' incorporates:
  //   Quantizer: '<S2>/Quantizer'
  //   Saturate: '<S8>/Saturation3'

  rtY.u[0] = rt_roundf(rtb_q_red_j[0] / 0.001F) * 0.001F;
  rtY.u[1] = rt_roundf(rtb_q_red_j[1] / 0.001F) * 0.001F;
  rtY.u[2] = rt_roundf(rtb_q_red_j[2] / 0.001F) * 0.001F;
  rtY.u[3] = rt_roundf(rtb_Gain / 0.001F) * 0.001F;
  rtY.u[4] = 0.0F;
  rtY.u[5] = 0.0F;
  rtY.u[6] = 0.0F;
  rtY.u[7] = 0.0F;

  // Outputs for Enabled SubSystem: '<S21>/Adaptive INDI G1 and G2 correction' incorporates:
  //   EnablePort: '<S22>/Enable'

  if (rtDW.AdaptiveINDIG1andG2correction_M) {
    // Disable for Product: '<S22>/apply learn rate' incorporates:
    //   Outport: '<S22>/Delta_factors_G1'

    rtDW.Delta_factors_G1[0] = 0.0F;
    rtDW.Delta_factors_G1[1] = 0.0F;
    rtDW.Delta_factors_G1[2] = 0.0F;
    rtDW.Delta_factors_G1[3] = 0.0F;

    // Disable for Product: '<S22>/apply learn rate2' incorporates:
    //   Outport: '<S22>/Delta_factors_G2'

    rtDW.Delta_factors_G2 = 0.0F;
    rtDW.AdaptiveINDIG1andG2correction_M = false;
  }

  // End of Outputs for SubSystem: '<S21>/Adaptive INDI G1 and G2 correction'

  // Sum: '<S43>/Sum2' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt'
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
  //   Product: '<S43>/Product2'
  //   Sum: '<S43>/Sum3'

  umin[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0] -
    (rtDW.DiscreteTimeIntegratory_dt_DS_j[0] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTA_eg[0]);
  umin[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1] -
    (rtDW.DiscreteTimeIntegratory_dt_DS_j[1] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTA_eg[1]);
  umin[2] = rtDW.DiscreteTimeIntegrator_DSTATE[2] -
    (rtDW.DiscreteTimeIntegratory_dt_DS_j[2] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTA_eg[2]);
  umin[3] = rtDW.DiscreteTimeIntegrator_DSTATE[3] -
    (rtDW.DiscreteTimeIntegratory_dt_DS_j[3] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTA_eg[3]);

  // Product: '<S5>/Matrix Multiply1' incorporates:
  //   Inport: '<Root>/measure'

  rtb_p_match_1 = 0.0F;
  rtb_p_match_0 = 0.0F;
  cos_Theta_0 = 0.0F;
  for (k = 0; k < 3; k++) {
    cos_Psi = rtU.measure.V_Kg[k];
    rtb_p_match_1 += rtb_M_bg[3 * k] * cos_Psi;
    rtb_p_match_0 += rtb_M_bg[3 * k + 1] * cos_Psi;
    cos_Theta_0 += rtb_M_bg[3 * k + 2] * cos_Psi;
  }

  // MATLAB Function: '<S5>/accelerometer' incorporates:
  //   Inport: '<Root>/measure'
  //   Product: '<S5>/Matrix Multiply1'

  cos_Theta = (rtU.measure.omega_Kb[1] * cos_Theta_0 - rtb_p_match_0 *
               rtU.measure.omega_Kb[2]) + rtU.measure.a_Kb[0];
  sin_Psi = (rtb_p_match_1 * rtU.measure.omega_Kb[2] - rtU.measure.omega_Kb[0] *
             cos_Theta_0) + rtU.measure.a_Kb[1];
  cos_Theta_0 = (rtU.measure.omega_Kb[0] * rtb_p_match_0 - rtb_p_match_1 *
                 rtU.measure.omega_Kb[1]) + rtU.measure.a_Kb[2];

  // Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LOAD = 0U;

  // Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LO_b = 0U;

  // Update for UnitDelay: '<S15>/Unit Delay1' incorporates:
  //   Constant: '<S2>/Constant3'

  rtDW.UnitDelay1_DSTATE = 3.0F;
  for (i = 0; i < 3; i++) {
    // DiscreteIntegrator: '<S58>/Discrete-Time Integrator y' incorporates:
    //   Math: '<S5>/Transpose'

    cos_Psi = rtDW.DiscreteTimeIntegratory_DSTAT_b[i];

    // DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt' incorporates:
    //   Math: '<S5>/Transpose'

    rtb_Reshape_idx_1 = rtDW.DiscreteTimeIntegratory_dt_DS_l[i];

    // Sum: '<S58>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt'
    //   MATLAB Function: '<S5>/accelerometer'
    //   Math: '<S5>/Transpose'
    //   Product: '<S58>/Product2'
    //   Sum: '<S58>/Sum3'

    rtb_p_ahead_g[i] = ((rtb_M_bg[3 * i + 1] * sin_Psi + rtb_M_bg[3 * i] *
                         cos_Theta) + rtb_M_bg[3 * i + 2] * cos_Theta_0) -
      (rtb_Reshape_idx_1 * 0.0301249F + cos_Psi);

    // DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'
    rtb_pq_Kb_dt_idx_0 = rtDW.DiscreteTimeIntegratory_DSTAT_e[i];

    // DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt'
    rtb_pq_Kb_dt_idx_1 = rtDW.DiscreteTimeIntegratory_dt_DS_g[i];

    // Sum: '<S60>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt'
    //   Inport: '<Root>/measure'
    //   Product: '<S60>/Product2'
    //   Sum: '<S60>/Sum3'
    //   Sum: '<S61>/Sum2'

    rtb_p_match[i] = rtU.measure.V_Kg[i] - (rtb_pq_Kb_dt_idx_1 * 0.0301249F +
      rtb_pq_Kb_dt_idx_0);

    // DiscreteIntegrator: '<S61>/Discrete-Time Integrator y'
    sin_Theta = rtDW.DiscreteTimeIntegratory_DSTATE[i];

    // DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt'
    rtb_p_match_1 = rtDW.DiscreteTimeIntegratory_dt_D_oh[i];

    // Sum: '<S61>/Sum2' incorporates:
    //   DiscreteIntegrator: '<S61>/Discrete-Time Integrator y'
    //   DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt'
    //   Inport: '<Root>/measure'
    //   Product: '<S61>/Product2'
    //   Sum: '<S61>/Sum3'

    rtb_V_Kg_n0[i] = rtU.measure.s_Kg[i] - (rtb_p_match_1 * 0.0301249F +
      sin_Theta);

    // Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTATE[i] = 0.0025F * rtb_p_match_1 + sin_Theta;

    // Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTAT_e[i] = 0.0025F * rtb_pq_Kb_dt_idx_1 +
      rtb_pq_Kb_dt_idx_0;

    // Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator y' incorporates:
    //   DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt'

    rtDW.DiscreteTimeIntegratory_DSTAT_b[i] = 0.0025F * rtb_Reshape_idx_1 +
      cos_Psi;
  }

  // Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S59>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_IC_L_b1 = 0U;
  for (k = 0; k < 9; k++) {
    rtDW.DiscreteTimeIntegratory_DSTA_br[k] += 0.0025F *
      rtDW.DiscreteTimeIntegratory_dt_D_jl[k];
  }

  // End of Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator y'

  // Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator2' incorporates:
  //   DiscreteIntegrator: '<S91>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator2_IC_LOAD = 0U;
  rtDW.DiscreteTimeIntegrator2_DSTATE += 0.0025F *
    rtDW.DiscreteTimeIntegrator_DSTATE_l;

  // Update for Delay: '<S16>/Delay'
  rtDW.icLoad = false;

  // Saturate: '<S25>/Saturation1' incorporates:
  //   Product: '<S22>/apply learn rate'

  if (rtDW.Delta_factors_G1[0] > 0.1F) {
    cos_Psi = 0.1F;
  } else if (rtDW.Delta_factors_G1[0] < -0.1F) {
    cos_Psi = -0.1F;
  } else {
    cos_Psi = rtDW.Delta_factors_G1[0];
  }

  // Saturate: '<S25>/Saturation2' incorporates:
  //   Delay: '<S25>/Delay'
  //   Product: '<S22>/apply learn rate'
  //   Saturate: '<S25>/Saturation1'
  //   Sum: '<S25>/Add'

  cos_Psi += rtDW.Delay_DSTATE_a[0];
  if (cos_Psi > 4.0F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[0] = 4.0F;
  } else if (cos_Psi < 0.25F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[0] = 0.25F;
  } else {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[0] = cos_Psi;
  }

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S49>/T'
  //   Product: '<S49>/Divide'
  //   Sum: '<S49>/Sum2'

  rtDW.DiscreteTimeIntegrator_DSTATE[0] += (rtb_q_red_j[0] -
    rtDW.DiscreteTimeIntegrator_DSTATE[0]) / 0.0301249F * 0.0025F;

  // Saturate: '<S25>/Saturation1' incorporates:
  //   Product: '<S22>/apply learn rate'

  if (rtDW.Delta_factors_G1[1] > 0.1F) {
    cos_Psi = 0.1F;
  } else if (rtDW.Delta_factors_G1[1] < -0.1F) {
    cos_Psi = -0.1F;
  } else {
    cos_Psi = rtDW.Delta_factors_G1[1];
  }

  // Saturate: '<S25>/Saturation2' incorporates:
  //   Delay: '<S25>/Delay'
  //   Product: '<S22>/apply learn rate'
  //   Saturate: '<S25>/Saturation1'
  //   Sum: '<S25>/Add'

  cos_Psi += rtDW.Delay_DSTATE_a[1];
  if (cos_Psi > 4.0F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[1] = 4.0F;
  } else if (cos_Psi < 0.25F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[1] = 0.25F;
  } else {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[1] = cos_Psi;
  }

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S49>/T'
  //   Product: '<S49>/Divide'
  //   Sum: '<S49>/Sum2'

  rtDW.DiscreteTimeIntegrator_DSTATE[1] += (rtb_q_red_j[1] -
    rtDW.DiscreteTimeIntegrator_DSTATE[1]) / 0.0301249F * 0.0025F;

  // Saturate: '<S25>/Saturation1' incorporates:
  //   Product: '<S22>/apply learn rate'

  if (rtDW.Delta_factors_G1[2] > 0.1F) {
    cos_Psi = 0.1F;
  } else if (rtDW.Delta_factors_G1[2] < -0.1F) {
    cos_Psi = -0.1F;
  } else {
    cos_Psi = rtDW.Delta_factors_G1[2];
  }

  // Saturate: '<S25>/Saturation2' incorporates:
  //   Delay: '<S25>/Delay'
  //   Product: '<S22>/apply learn rate'
  //   Saturate: '<S25>/Saturation1'
  //   Sum: '<S25>/Add'

  cos_Psi += rtDW.Delay_DSTATE_a[2];
  if (cos_Psi > 4.0F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[2] = 4.0F;
  } else if (cos_Psi < 0.25F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[2] = 0.25F;
  } else {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[2] = cos_Psi;
  }

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S49>/T'
  //   Product: '<S49>/Divide'
  //   Sum: '<S49>/Sum2'

  rtDW.DiscreteTimeIntegrator_DSTATE[2] += (rtb_q_red_j[2] -
    rtDW.DiscreteTimeIntegrator_DSTATE[2]) / 0.0301249F * 0.0025F;

  // Saturate: '<S25>/Saturation1' incorporates:
  //   Product: '<S22>/apply learn rate'

  if (rtDW.Delta_factors_G1[3] > 0.1F) {
    cos_Psi = 0.1F;
  } else if (rtDW.Delta_factors_G1[3] < -0.1F) {
    cos_Psi = -0.1F;
  } else {
    cos_Psi = rtDW.Delta_factors_G1[3];
  }

  // Saturate: '<S25>/Saturation2' incorporates:
  //   Delay: '<S25>/Delay'
  //   Product: '<S22>/apply learn rate'
  //   Saturate: '<S25>/Saturation1'
  //   Sum: '<S25>/Add'

  cos_Psi += rtDW.Delay_DSTATE_a[3];
  if (cos_Psi > 4.0F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[3] = 4.0F;
  } else if (cos_Psi < 0.25F) {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[3] = 0.25F;
  } else {
    // Update for Delay: '<S25>/Delay'
    rtDW.Delay_DSTATE_a[3] = cos_Psi;
  }

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S49>/T'
  //   Product: '<S49>/Divide'
  //   Saturate: '<S8>/Saturation3'
  //   Sum: '<S49>/Sum2'

  rtDW.DiscreteTimeIntegrator_DSTATE[3] += (rtb_Gain -
    rtDW.DiscreteTimeIntegrator_DSTATE[3]) / 0.0301249F * 0.0025F;

  // Saturate: '<S26>/Saturation1'
  if (rtDW.Delta_factors_G2 > 0.1F) {
    cos_Psi = 0.1F;
  } else if (rtDW.Delta_factors_G2 < -0.1F) {
    cos_Psi = -0.1F;
  } else {
    cos_Psi = rtDW.Delta_factors_G2;
  }

  // Sum: '<S26>/Add1' incorporates:
  //   Delay: '<S26>/Delay1'
  //   Saturate: '<S26>/Saturation1'

  rtb_Gain = cos_Psi + rtDW.Delay1_DSTATE;

  // Saturate: '<S26>/Saturation3'
  if (rtb_Gain > 4.0F) {
    // Update for Delay: '<S26>/Delay1'
    rtDW.Delay1_DSTATE = 4.0F;
  } else if (rtb_Gain < 0.25F) {
    // Update for Delay: '<S26>/Delay1'
    rtDW.Delay1_DSTATE = 0.25F;
  } else {
    // Update for Delay: '<S26>/Delay1'
    rtDW.Delay1_DSTATE = rtb_Gain;
  }

  // End of Saturate: '<S26>/Saturation3'

  // Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'
  //   Inport: '<Root>/measure'
  //   Product: '<S62>/Product1'
  //   Product: '<S62>/Product2'
  //   Sum: '<S62>/Sum2'
  //   Sum: '<S62>/Sum3'

  rtDW.DiscreteTimeIntegratory_dt_DSTA[0] += (rtU.measure.omega_Kb[0] -
    (rtDW.DiscreteTimeIntegratory_dt_DSTA[0] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTAT_f[0])) * 4407.6665F * 0.0025F;
  rtDW.DiscreteTimeIntegratory_dt_DSTA[1] += (rtU.measure.omega_Kb[1] -
    (rtDW.DiscreteTimeIntegratory_dt_DSTA[1] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTAT_f[1])) * 4407.6665F * 0.0025F;
  rtDW.DiscreteTimeIntegratory_dt_DSTA[2] += (rtU.measure.omega_Kb[2] -
    (rtDW.DiscreteTimeIntegratory_dt_DSTA[2] * 0.0301249F +
     rtDW.DiscreteTimeIntegratory_DSTAT_f[2])) * 4407.6665F * 0.0025F;

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_eg[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[0];

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'
  //   Product: '<S43>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[0] += umin[0] * 4407.6665F * 0.0025F;

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_eg[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[1];

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'
  //   Product: '<S43>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[1] += umin[1] * 4407.6665F * 0.0025F;

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_eg[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[2];

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'
  //   Product: '<S43>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[2] += umin[2] * 4407.6665F * 0.0025F;

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_eg[3] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_j[3];

  // Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S43>/Discrete-Time Integrator y'
  //   Product: '<S43>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_j[3] += umin[3] * 4407.6665F * 0.0025F;

  // Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LO_m = 0U;

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_LO_d = 0U;

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'
  rtDW.DiscreteTimeIntegratory_IC_L_bz = 0U;

  // Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_f[0] += 0.0025F * sin_Phi;

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_by[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_o[0];

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_o[0] += 0.0025F * rtb_p_match_2[0];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_k[0] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_n[0];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_n[0] += 0.0025F * dir_next_wp[0];

  // Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_f[1] += 0.0025F * rtb_a_idx_1;

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_by[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_o[1];

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_o[1] += 0.0025F * rtb_p_match_2[1];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_k[1] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_n[1];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_n[1] += 0.0025F * dir_next_wp[1];

  // Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S62>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_f[2] += 0.0025F * rtb_a_idx_2;

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTA_by[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_o[2];

  // Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S92>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_o[2] += 0.0025F * rtb_p_match_2[2];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt'

  rtDW.DiscreteTimeIntegratory_DSTAT_k[2] += 0.0025F *
    rtDW.DiscreteTimeIntegratory_dt_DS_n[2];

  // Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y_dt' incorporates:
  //   DiscreteIntegrator: '<S94>/Discrete-Time Integrator y'

  rtDW.DiscreteTimeIntegratory_dt_DS_n[2] += 0.0025F * dir_next_wp[2];

  // Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE_l += 0.0025F * cos_Phi;

  // Update for UnitDelay: '<S41>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE_m[0] = rtb_y_dy[0];
  rtDW.UnitDelay1_DSTATE_m[1] = rtb_y_dy[1];
  rtDW.UnitDelay1_DSTATE_m[2] = rtb_y_dy[2];
  rtDW.UnitDelay1_DSTATE_m[3] = rtb_y_dy[3];

  // Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S59>/Product1'
  //   Sum: '<S59>/Sum2'

  for (k = 0; k < 9; k++) {
    rtDW.DiscreteTimeIntegratory_dt_D_jl[k] += rtb_Transpose[k] * 4407.6665F *
      0.0025F;
  }

  // End of Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator y_dt' 

  // Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S58>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_l[0] += rtb_p_ahead_g[0] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S60>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[0] += rtb_p_match[0] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S61>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_D_oh[0] += rtb_V_Kg_n0[0] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S58>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_l[1] += rtb_p_ahead_g[1] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S60>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[1] += rtb_p_match[1] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S61>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_D_oh[1] += rtb_V_Kg_n0[1] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S58>/Product1'

  rtDW.DiscreteTimeIntegratory_dt_DS_l[2] += rtb_p_ahead_g[2] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S60>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_DS_g[2] += rtb_p_match[2] * 4407.6665F *
    0.0025F;

  // Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y_dt' incorporates:
  //   Product: '<S61>/Product1'
  //   Sum: '<S61>/Sum2'

  rtDW.DiscreteTimeIntegratory_dt_D_oh[2] += rtb_V_Kg_n0[2] * 4407.6665F *
    0.0025F;
}

// Model initialize function
void MatlabControllerClass::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S61>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LOAD = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S60>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_b = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_L_b1 = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator2' 
  rtDW.DiscreteTimeIntegrator2_IC_LOAD = 1U;

  // InitializeConditions for Delay: '<S16>/Delay'
  rtDW.icLoad = true;

  // InitializeConditions for Delay: '<S25>/Delay'
  rtDW.Delay_DSTATE_a[0] = 1.0F;
  rtDW.Delay_DSTATE_a[1] = 1.0F;
  rtDW.Delay_DSTATE_a[2] = 1.0F;
  rtDW.Delay_DSTATE_a[3] = 1.0F;

  // InitializeConditions for Delay: '<S26>/Delay1'
  rtDW.Delay1_DSTATE = 1.0F;

  // InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_m = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_d = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_L_bz = 1U;

  // SystemInitialize for Enabled SubSystem: '<S4>/NDI position controller for copters reference model' 
  // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' 
  rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
  rtDW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_PrevRe_k = 2;
  rtDW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_PrevRe_m = 2;
  rtDW.DiscreteTimeIntegrator_IC_LOA_h = 1U;

  // End of SystemInitialize for SubSystem: '<S4>/NDI position controller for copters reference model' 

  // SystemInitialize for Enabled SubSystem: '<S4>/Waypoint Navigation'
  // InitializeConditions for UnitDelay: '<S18>/Unit Delay'
  rtDW.UnitDelay_DSTATE_h = 1;

  // InitializeConditions for UnitDelay: '<S18>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE_b = 1;

  // InitializeConditions for UnitDelay: '<S18>/Unit Delay2'
  rtDW.UnitDelay2_DSTATE = 2;

  // SystemInitialize for Enabled SubSystem: '<S119>/Flight Path Smoothing'
  // InitializeConditions for DiscreteIntegrator: '<S129>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_L_bc = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S130>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_o = 1U;

  // End of SystemInitialize for SubSystem: '<S119>/Flight Path Smoothing'

  // InitializeConditions for UnitDelay: '<S18>/Unit Delay6'
  rtDW.UnitDelay6_DSTATE[0] = 1.0F;
  rtDW.UnitDelay6_DSTATE[1] = 1.0F;
  rtDW.UnitDelay6_DSTATE[2] = 1.0F;

  // End of SystemInitialize for SubSystem: '<S4>/Waypoint Navigation'

  // SystemInitialize for Enabled SubSystem: '<S4>/NDI position controller for copters with reference input' 
  // InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_PrevR_o = 2;
  rtDW.DiscreteTimeIntegratory_IC_LO_p = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator y_dt' 
  rtDW.DiscreteTimeIntegratory_dt_Pr_j = 2;

  // End of SystemInitialize for SubSystem: '<S4>/NDI position controller for copters with reference input' 

  // SystemInitialize for Enabled SubSystem: '<S21>/Copter Random Excitation'
  // InitializeConditions for RandomNumber: '<S33>/White Noise'
  rtDW.RandSeed[0] = 1529675776U;
  rtDW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw(&rtDW.RandSeed[0]);
  rtDW.RandSeed[1] = 1529741312U;
  rtDW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw(&rtDW.RandSeed[1]);
  rtDW.RandSeed[2] = 1529806848U;
  rtDW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw(&rtDW.RandSeed[2]);
  rtDW.RandSeed[3] = 1529872384U;
  rtDW.NextOutput[3] = rt_nrand_Upu32_Yd_f_pw(&rtDW.RandSeed[3]);

  // End of SystemInitialize for SubSystem: '<S21>/Copter Random Excitation'

  // SystemInitialize for Enabled SubSystem: '<S4>/Incremental specific thrust'
  // InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_e = 1U;

  // End of SystemInitialize for SubSystem: '<S4>/Incremental specific thrust'

  // SystemInitialize for Enabled SubSystem: '<S21>/INDI Inversion Check'
  // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_n = 1U;

  // InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator y' 
  rtDW.DiscreteTimeIntegratory_IC_LO_f = 1U;

  // End of SystemInitialize for SubSystem: '<S21>/INDI Inversion Check'
}

// Constructor
MatlabControllerClass::MatlabControllerClass():
  rtU(),
  rtY(),
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
MatlabControllerClass::~MatlabControllerClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
