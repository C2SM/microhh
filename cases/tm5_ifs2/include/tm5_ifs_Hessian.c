/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hessian File                                                     */
/*                                                                  */
/* Generated by KPP-2.2.3 symbolic chemistry Kinetics PreProcessor  */
/*       (http://www.cs.vt.edu/~asandu/Software/KPP)                */
/* KPP is distributed under GPL, the general public licence         */
/*       (http://www.gnu.org/copyleft/gpl.html)                     */
/* (C) 1995-1997, V. Damian & A. Sandu, CGRER, Univ. Iowa           */
/* (C) 1997-2005, A. Sandu, Michigan Tech, Virginia Tech            */
/*     With important contributions from:                           */
/*        M. Damian, Villanova University, USA                      */
/*        R. Sander, Max-Planck Institute for Chemistry, Mainz, Germany */
/*                                                                  */
/* File                 : tm5_ifs_Hessian.c                         */
/* Time                 : Tue Aug 31 13:57:36 2021                  */
/* Working directory    : /home/WUR/krol005/kpp/examples            */
/* Equation file        : tm5_ifs.kpp                               */
/* Output root filename : tm5_ifs                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tm5_ifs_Parameters.h"
#include "tm5_ifs_Global.h"
#include "tm5_ifs_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hessian - function for Hessian (Jac derivative w.r.t. variables) */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Hessian( 
  double V[],                            /* Concentrations of variable species (local) */
  double F[],                            /* Concentrations of fixed species (local) */
  double RCT[],                          /* Rate constants (local) */
  double HESS[]                          /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
)
{
/* --------------------------------------------------------         */
/* Note: HESS is represented in coordinate sparse format:           */
/*       HESS(m) = d^2 f_i / dv_j dv_k = d Jac_{i,j} / dv_k         */
/*       where i = IHESS_I(m), j = IHESS_J(m), k = IHESS_K(m).      */
/* --------------------------------------------------------         */
/* Note: d^2 f_i / dv_j dv_k = d^2 f_i / dv_k dv_j,                 */
/*       therefore only the terms d^2 f_i / dv_j dv_k               */
/*       with j <= k are computed and stored in HESS.               */
/* --------------------------------------------------------         */

/* Local variables                                                  */
double D2A[23];                          /* Second derivatives of equation rates */

/* Computation of the second derivatives of equation rates          */
/* D2A(0) = d^2 A(0) / dV(11)dV(15)                                 */
  D2A[0] = RCT[0];
/* D2A(1) = d^2 A(1) / dV(10)dV(11)                                 */
  D2A[1] = RCT[1];
/* D2A(2) = d^2 A(2) / dV(10)dV(15)                                 */
  D2A[2] = RCT[2];
/* D2A(3) = d^2 A(3)/{dV(10)dV(10)}                                 */
  D2A[3] = RCT[3]*2;
/* D2A(4) = d^2 A(4) / dV(2)dV(15)                                  */
  D2A[4] = RCT[4];
/* D2A(5) = d^2 A(6) / dV(11)dV(12)                                 */
  D2A[5] = RCT[6];
/* D2A(6) = d^2 A(7) / dV(10)dV(12)                                 */
  D2A[6] = RCT[7];
/* D2A(7) = d^2 A(8) / dV(14)dV(15)                                 */
  D2A[7] = RCT[8];
/* D2A(8) = d^2 A(10) / dV(9)dV(12)                                 */
  D2A[8] = RCT[10];
/* D2A(9) = d^2 A(11) / dV(9)dV(10)                                 */
  D2A[9] = RCT[11];
/* D2A(10) = d^2 A(12) / dV(9)dV(10)                                */
  D2A[10] = RCT[12];
/* D2A(11) = d^2 A(13) / dV(7)dV(15)                                */
  D2A[11] = RCT[13];
/* D2A(12) = d^2 A(14) / dV(7)dV(15)                                */
  D2A[12] = 2e-11;
/* D2A(13) = d^2 A(15) / dV(3)dV(15)                                */
  D2A[13] = RCT[15];
/* D2A(14) = d^2 A(16) / dV(6)dV(15)                                */
  D2A[14] = RCT[16];
/* D2A(15) = d^2 A(17) / dV(8)dV(11)                                */
  D2A[15] = 8e-17;
/* D2A(16) = d^2 A(18) / dV(8)dV(15)                                */
  D2A[16] = RCT[18];
/* D2A(17) = d^2 A(25) / dV(5)dV(14)                                */
  D2A[17] = RCT[25];
/* D2A(18) = d^2 A(28) / dV(11)dV(14)                               */
  D2A[18] = RCT[28];
/* D2A(19) = d^2 A(29) / dV(12)dV(13)                               */
  D2A[19] = RCT[29];
/* D2A(20) = d^2 A(30) / dV(13)dV(14)                               */
  D2A[20] = RCT[30];
/* D2A(21) = d^2 A(32) / dV(10)dV(13)                               */
  D2A[21] = 4e-12;
/* D2A(22) = d^2 A(34) / dV(8)dV(13)                                */
  D2A[22] = 4e-12;

/* Computation of the Jacobian derivative                           */
/* HESS(0) = d^2 Vdot(0)/{dV(10)dV(13)} = d^2 Vdot(0)/{dV(13)dV(10)} */
  HESS[0] = D2A[21];
/* HESS(1) = d^2 Vdot(0)/{dV(14)dV(15)} = d^2 Vdot(0)/{dV(15)dV(14)} */
  HESS[1] = D2A[7];
/* HESS(2) = d^2 Vdot(1)/{dV(13)dV(14)} = d^2 Vdot(1)/{dV(14)dV(13)} */
  HESS[2] = D2A[20];
/* HESS(3) = d^2 Vdot(2)/{dV(2)dV(15)} = d^2 Vdot(2)/{dV(15)dV(2)}  */
  HESS[3] = -D2A[4];
/* HESS(4) = d^2 Vdot(2)/{dV(10)dV(10)} = d^2 Vdot(2)/{dV(10)dV(10)} */
  HESS[4] = D2A[3];
/* HESS(5) = d^2 Vdot(3)/{dV(3)dV(15)} = d^2 Vdot(3)/{dV(15)dV(3)}  */
  HESS[5] = -D2A[13];
/* HESS(6) = d^2 Vdot(3)/{dV(6)dV(15)} = d^2 Vdot(3)/{dV(15)dV(6)}  */
  HESS[6] = D2A[14];
/* HESS(7) = d^2 Vdot(4)/{dV(5)dV(14)} = d^2 Vdot(4)/{dV(14)dV(5)}  */
  HESS[7] = D2A[17];
/* HESS(8) = d^2 Vdot(5)/{dV(5)dV(14)} = d^2 Vdot(5)/{dV(14)dV(5)}  */
  HESS[8] = -D2A[17];
/* HESS(9) = d^2 Vdot(5)/{dV(8)dV(11)} = d^2 Vdot(5)/{dV(11)dV(8)}  */
  HESS[9] = 0.1*D2A[15];
/* HESS(10) = d^2 Vdot(5)/{dV(8)dV(13)} = d^2 Vdot(5)/{dV(13)dV(8)} */
  HESS[10] = 0.1*D2A[22];
/* HESS(11) = d^2 Vdot(5)/{dV(8)dV(15)} = d^2 Vdot(5)/{dV(15)dV(8)} */
  HESS[11] = 0.1*D2A[16];
/* HESS(12) = d^2 Vdot(6)/{dV(6)dV(15)} = d^2 Vdot(6)/{dV(15)dV(6)} */
  HESS[12] = -D2A[14];
/* HESS(13) = d^2 Vdot(6)/{dV(7)dV(15)} = d^2 Vdot(6)/{dV(15)dV(7)} */
  HESS[13] = 0.4*D2A[11];
/* HESS(14) = d^2 Vdot(6)/{dV(9)dV(10)} = d^2 Vdot(6)/{dV(10)dV(9)} */
  HESS[14] = D2A[10];
/* HESS(15) = d^2 Vdot(6)/{dV(9)dV(12)} = d^2 Vdot(6)/{dV(12)dV(9)} */
  HESS[15] = D2A[8];
/* HESS(16) = d^2 Vdot(7)/{dV(7)dV(15)} = d^2 Vdot(7)/{dV(15)dV(7)} */
  HESS[16] = -D2A[11]-D2A[12];
/* HESS(17) = d^2 Vdot(7)/{dV(9)dV(10)} = d^2 Vdot(7)/{dV(10)dV(9)} */
  HESS[17] = D2A[9];
/* HESS(18) = d^2 Vdot(8)/{dV(8)dV(11)} = d^2 Vdot(8)/{dV(11)dV(8)} */
  HESS[18] = -D2A[15];
/* HESS(19) = d^2 Vdot(8)/{dV(8)dV(13)} = d^2 Vdot(8)/{dV(13)dV(8)} */
  HESS[19] = -D2A[22];
/* HESS(20) = d^2 Vdot(8)/{dV(8)dV(15)} = d^2 Vdot(8)/{dV(15)dV(8)} */
  HESS[20] = -D2A[16];
/* HESS(21) = d^2 Vdot(9)/{dV(7)dV(15)} = d^2 Vdot(9)/{dV(15)dV(7)} */
  HESS[21] = 0.6*D2A[11];
/* HESS(22) = d^2 Vdot(9)/{dV(8)dV(11)} = d^2 Vdot(9)/{dV(11)dV(8)} */
  HESS[22] = 0.75*D2A[15];
/* HESS(23) = d^2 Vdot(9)/{dV(8)dV(13)} = d^2 Vdot(9)/{dV(13)dV(8)} */
  HESS[23] = D2A[22];
/* HESS(24) = d^2 Vdot(9)/{dV(8)dV(15)} = d^2 Vdot(9)/{dV(15)dV(8)} */
  HESS[24] = D2A[16];
/* HESS(25) = d^2 Vdot(9)/{dV(9)dV(10)} = d^2 Vdot(9)/{dV(10)dV(9)} */
  HESS[25] = -D2A[9]-D2A[10];
/* HESS(26) = d^2 Vdot(9)/{dV(9)dV(12)} = d^2 Vdot(9)/{dV(12)dV(9)} */
  HESS[26] = -D2A[8];
/* HESS(27) = d^2 Vdot(10)/{dV(2)dV(15)} = d^2 Vdot(10)/{dV(15)dV(2)} */
  HESS[27] = D2A[4];
/* HESS(28) = d^2 Vdot(10)/{dV(3)dV(15)} = d^2 Vdot(10)/{dV(15)dV(3)} */
  HESS[28] = D2A[13];
/* HESS(29) = d^2 Vdot(10)/{dV(6)dV(15)} = d^2 Vdot(10)/{dV(15)dV(6)} */
  HESS[29] = D2A[14];
/* HESS(30) = d^2 Vdot(10)/{dV(9)dV(10)} = d^2 Vdot(10)/{dV(10)dV(9)} */
  HESS[30] = -D2A[9]-D2A[10];
/* HESS(31) = d^2 Vdot(10)/{dV(9)dV(12)} = d^2 Vdot(10)/{dV(12)dV(9)} */
  HESS[31] = D2A[8];
/* HESS(32) = d^2 Vdot(10)/{dV(10)dV(10)} = d^2 Vdot(10)/{dV(10)dV(10)} */
  HESS[32] = -2*D2A[3];
/* HESS(33) = d^2 Vdot(10)/{dV(10)dV(11)} = d^2 Vdot(10)/{dV(11)dV(10)} */
  HESS[33] = -D2A[1];
/* HESS(34) = d^2 Vdot(10)/{dV(10)dV(12)} = d^2 Vdot(10)/{dV(12)dV(10)} */
  HESS[34] = -D2A[6];
/* HESS(35) = d^2 Vdot(10)/{dV(10)dV(13)} = d^2 Vdot(10)/{dV(13)dV(10)} */
  HESS[35] = -D2A[21];
/* HESS(36) = d^2 Vdot(10)/{dV(10)dV(15)} = d^2 Vdot(10)/{dV(15)dV(10)} */
  HESS[36] = -D2A[2];
/* HESS(37) = d^2 Vdot(10)/{dV(11)dV(15)} = d^2 Vdot(10)/{dV(15)dV(11)} */
  HESS[37] = D2A[0];
/* HESS(38) = d^2 Vdot(11)/{dV(8)dV(11)} = d^2 Vdot(11)/{dV(11)dV(8)} */
  HESS[38] = -D2A[15];
/* HESS(39) = d^2 Vdot(11)/{dV(10)dV(11)} = d^2 Vdot(11)/{dV(11)dV(10)} */
  HESS[39] = -D2A[1];
/* HESS(40) = d^2 Vdot(11)/{dV(11)dV(12)} = d^2 Vdot(11)/{dV(12)dV(11)} */
  HESS[40] = -D2A[5];
/* HESS(41) = d^2 Vdot(11)/{dV(11)dV(14)} = d^2 Vdot(11)/{dV(14)dV(11)} */
  HESS[41] = -D2A[18];
/* HESS(42) = d^2 Vdot(11)/{dV(11)dV(15)} = d^2 Vdot(11)/{dV(15)dV(11)} */
  HESS[42] = -D2A[0];
/* HESS(43) = d^2 Vdot(12)/{dV(9)dV(12)} = d^2 Vdot(12)/{dV(12)dV(9)} */
  HESS[43] = -D2A[8];
/* HESS(44) = d^2 Vdot(12)/{dV(10)dV(12)} = d^2 Vdot(12)/{dV(12)dV(10)} */
  HESS[44] = -D2A[6];
/* HESS(45) = d^2 Vdot(12)/{dV(11)dV(12)} = d^2 Vdot(12)/{dV(12)dV(11)} */
  HESS[45] = -D2A[5];
/* HESS(46) = d^2 Vdot(12)/{dV(12)dV(13)} = d^2 Vdot(12)/{dV(13)dV(12)} */
  HESS[46] = -D2A[19];
/* HESS(47) = d^2 Vdot(13)/{dV(8)dV(13)} = d^2 Vdot(13)/{dV(13)dV(8)} */
  HESS[47] = -D2A[22];
/* HESS(48) = d^2 Vdot(13)/{dV(10)dV(13)} = d^2 Vdot(13)/{dV(13)dV(10)} */
  HESS[48] = -D2A[21];
/* HESS(49) = d^2 Vdot(13)/{dV(11)dV(14)} = d^2 Vdot(13)/{dV(14)dV(11)} */
  HESS[49] = D2A[18];
/* HESS(50) = d^2 Vdot(13)/{dV(12)dV(13)} = d^2 Vdot(13)/{dV(13)dV(12)} */
  HESS[50] = -D2A[19];
/* HESS(51) = d^2 Vdot(13)/{dV(13)dV(14)} = d^2 Vdot(13)/{dV(14)dV(13)} */
  HESS[51] = -D2A[20];
/* HESS(52) = d^2 Vdot(14)/{dV(5)dV(14)} = d^2 Vdot(14)/{dV(14)dV(5)} */
  HESS[52] = -D2A[17];
/* HESS(53) = d^2 Vdot(14)/{dV(8)dV(13)} = d^2 Vdot(14)/{dV(13)dV(8)} */
  HESS[53] = D2A[22];
/* HESS(54) = d^2 Vdot(14)/{dV(9)dV(12)} = d^2 Vdot(14)/{dV(12)dV(9)} */
  HESS[54] = D2A[8];
/* HESS(55) = d^2 Vdot(14)/{dV(10)dV(12)} = d^2 Vdot(14)/{dV(12)dV(10)} */
  HESS[55] = D2A[6];
/* HESS(56) = d^2 Vdot(14)/{dV(11)dV(12)} = d^2 Vdot(14)/{dV(12)dV(11)} */
  HESS[56] = D2A[5];
/* HESS(57) = d^2 Vdot(14)/{dV(11)dV(14)} = d^2 Vdot(14)/{dV(14)dV(11)} */
  HESS[57] = -D2A[18];
/* HESS(58) = d^2 Vdot(14)/{dV(12)dV(13)} = d^2 Vdot(14)/{dV(13)dV(12)} */
  HESS[58] = 2*D2A[19];
/* HESS(59) = d^2 Vdot(14)/{dV(13)dV(14)} = d^2 Vdot(14)/{dV(14)dV(13)} */
  HESS[59] = -D2A[20];
/* HESS(60) = d^2 Vdot(14)/{dV(14)dV(15)} = d^2 Vdot(14)/{dV(15)dV(14)} */
  HESS[60] = -D2A[7];
/* HESS(61) = d^2 Vdot(15)/{dV(2)dV(15)} = d^2 Vdot(15)/{dV(15)dV(2)} */
  HESS[61] = -D2A[4];
/* HESS(62) = d^2 Vdot(15)/{dV(3)dV(15)} = d^2 Vdot(15)/{dV(15)dV(3)} */
  HESS[62] = -D2A[13];
/* HESS(63) = d^2 Vdot(15)/{dV(6)dV(15)} = d^2 Vdot(15)/{dV(15)dV(6)} */
  HESS[63] = -D2A[14];
/* HESS(64) = d^2 Vdot(15)/{dV(7)dV(15)} = d^2 Vdot(15)/{dV(15)dV(7)} */
  HESS[64] = -0.6*D2A[11]-0.77*D2A[12];
/* HESS(65) = d^2 Vdot(15)/{dV(8)dV(11)} = d^2 Vdot(15)/{dV(11)dV(8)} */
  HESS[65] = 0.8*D2A[15];
/* HESS(66) = d^2 Vdot(15)/{dV(8)dV(15)} = d^2 Vdot(15)/{dV(15)dV(8)} */
  HESS[66] = -D2A[16];
/* HESS(67) = d^2 Vdot(15)/{dV(10)dV(11)} = d^2 Vdot(15)/{dV(11)dV(10)} */
  HESS[67] = D2A[1];
/* HESS(68) = d^2 Vdot(15)/{dV(10)dV(12)} = d^2 Vdot(15)/{dV(12)dV(10)} */
  HESS[68] = D2A[6];
/* HESS(69) = d^2 Vdot(15)/{dV(10)dV(15)} = d^2 Vdot(15)/{dV(15)dV(10)} */
  HESS[69] = -D2A[2];
/* HESS(70) = d^2 Vdot(15)/{dV(11)dV(15)} = d^2 Vdot(15)/{dV(15)dV(11)} */
  HESS[70] = -D2A[0];
/* HESS(71) = d^2 Vdot(15)/{dV(14)dV(15)} = d^2 Vdot(15)/{dV(15)dV(14)} */
  HESS[71] = -D2A[7];
}

/* End of Hessian function                                          */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* HessTR_Vec - Hessian transposed times user vectors               */
/*   Arguments :                                                    */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*      U1        - User vector                                     */
/*      U2        - User vector                                     */
/*      HTU       - Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2  */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void HessTR_Vec( 
  double HESS[],                         /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
  double U1[],                           /* User vector */
  double U2[],                           /* User vector */
  double HTU[]                           /* Transposed Hessian times user vectors: (Hess x U2)^T * U1 = [d (Jac^T*U1)/d Var] * U2  */
)
{
/* Compute the vector HTU =(Hess x U2)^T * U1 = d (Jac^T*U1)/d Var * U2  */
  HTU[0] = 0;
  HTU[1] = 0;
  HTU[2] = HESS[3]*(U1[2]*U2[15])+HESS[27]*(U1[10]*U2[15])+HESS[61]
          *(U1[15]*U2[15]);
  HTU[3] = HESS[5]*(U1[3]*U2[15])+HESS[28]*(U1[10]*U2[15])+HESS[62]
          *(U1[15]*U2[15]);
  HTU[4] = 0;
  HTU[5] = HESS[7]*(U1[4]*U2[14])+HESS[8]*(U1[5]*U2[14])+HESS[52]
          *(U1[14]*U2[14]);
  HTU[6] = HESS[6]*(U1[3]*U2[15])+HESS[12]*(U1[6]*U2[15])+HESS[29]
          *(U1[10]*U2[15])+HESS[63]*(U1[15]*U2[15]);
  HTU[7] = HESS[13]*(U1[6]*U2[15])+HESS[16]*(U1[7]*U2[15])+HESS[21]
          *(U1[9]*U2[15])+HESS[64]*(U1[15]*U2[15]);
  HTU[8] = HESS[9]*(U1[5]*U2[11])+HESS[10]*(U1[5]*U2[13])+HESS[11]
          *(U1[5]*U2[15])+HESS[18]*(U1[8]*U2[11])+HESS[19]*(U1[8]
          *U2[13])+HESS[20]*(U1[8]*U2[15])+HESS[22]*(U1[9]*U2[11])
          +HESS[23]*(U1[9]*U2[13])+HESS[24]*(U1[9]*U2[15])+HESS[38]
          *(U1[11]*U2[11])+HESS[47]*(U1[13]*U2[13])+HESS[53]*(U1[14]
          *U2[13])+HESS[65]*(U1[15]*U2[11])+HESS[66]*(U1[15]*U2[15]);
  HTU[9] = HESS[14]*(U1[6]*U2[10])+HESS[15]*(U1[6]*U2[12])+HESS[17]
          *(U1[7]*U2[10])+HESS[25]*(U1[9]*U2[10])+HESS[26]*(U1[9]
          *U2[12])+HESS[30]*(U1[10]*U2[10])+HESS[31]*(U1[10]*U2[12])
          +HESS[43]*(U1[12]*U2[12])+HESS[54]*(U1[14]*U2[12]);
  HTU[10] = HESS[0]*(U1[0]*U2[13])+HESS[4]*(U1[2]*U2[10])+HESS[14]
           *(U1[6]*U2[9])+HESS[17]*(U1[7]*U2[9])+HESS[25]*(U1[9]*U2[9])
           +HESS[30]*(U1[10]*U2[9])+HESS[32]*(U1[10]*U2[10])+HESS[33]
           *(U1[10]*U2[11])+HESS[34]*(U1[10]*U2[12])+HESS[35]*(U1[10]
           *U2[13])+HESS[36]*(U1[10]*U2[15])+HESS[39]*(U1[11]*U2[11])
           +HESS[44]*(U1[12]*U2[12])+HESS[48]*(U1[13]*U2[13])+HESS[55]
           *(U1[14]*U2[12])+HESS[67]*(U1[15]*U2[11])+HESS[68]*(U1[15]
           *U2[12])+HESS[69]*(U1[15]*U2[15]);
  HTU[11] = HESS[9]*(U1[5]*U2[8])+HESS[18]*(U1[8]*U2[8])+HESS[22]
           *(U1[9]*U2[8])+HESS[33]*(U1[10]*U2[10])+HESS[37]*(U1[10]
           *U2[15])+HESS[38]*(U1[11]*U2[8])+HESS[39]*(U1[11]*U2[10])
           +HESS[40]*(U1[11]*U2[12])+HESS[41]*(U1[11]*U2[14])+HESS[42]
           *(U1[11]*U2[15])+HESS[45]*(U1[12]*U2[12])+HESS[49]*(U1[13]
           *U2[14])+HESS[56]*(U1[14]*U2[12])+HESS[57]*(U1[14]*U2[14])
           +HESS[65]*(U1[15]*U2[8])+HESS[67]*(U1[15]*U2[10])+HESS[70]
           *(U1[15]*U2[15]);
  HTU[12] = HESS[15]*(U1[6]*U2[9])+HESS[26]*(U1[9]*U2[9])+HESS[31]
           *(U1[10]*U2[9])+HESS[34]*(U1[10]*U2[10])+HESS[40]*(U1[11]
           *U2[11])+HESS[43]*(U1[12]*U2[9])+HESS[44]*(U1[12]*U2[10])
           +HESS[45]*(U1[12]*U2[11])+HESS[46]*(U1[12]*U2[13])+HESS[50]
           *(U1[13]*U2[13])+HESS[54]*(U1[14]*U2[9])+HESS[55]*(U1[14]
           *U2[10])+HESS[56]*(U1[14]*U2[11])+HESS[58]*(U1[14]*U2[13])
           +HESS[68]*(U1[15]*U2[10]);
  HTU[13] = HESS[0]*(U1[0]*U2[10])+HESS[2]*(U1[1]*U2[14])+HESS[10]
           *(U1[5]*U2[8])+HESS[19]*(U1[8]*U2[8])+HESS[23]*(U1[9]*U2[8])
           +HESS[35]*(U1[10]*U2[10])+HESS[46]*(U1[12]*U2[12])+HESS[47]
           *(U1[13]*U2[8])+HESS[48]*(U1[13]*U2[10])+HESS[50]*(U1[13]
           *U2[12])+HESS[51]*(U1[13]*U2[14])+HESS[53]*(U1[14]*U2[8])
           +HESS[58]*(U1[14]*U2[12])+HESS[59]*(U1[14]*U2[14]);
  HTU[14] = HESS[1]*(U1[0]*U2[15])+HESS[2]*(U1[1]*U2[13])+HESS[7]
           *(U1[4]*U2[5])+HESS[8]*(U1[5]*U2[5])+HESS[41]*(U1[11]
           *U2[11])+HESS[49]*(U1[13]*U2[11])+HESS[51]*(U1[13]*U2[13])
           +HESS[52]*(U1[14]*U2[5])+HESS[57]*(U1[14]*U2[11])+HESS[59]
           *(U1[14]*U2[13])+HESS[60]*(U1[14]*U2[15])+HESS[71]*(U1[15]
           *U2[15]);
  HTU[15] = HESS[1]*(U1[0]*U2[14])+HESS[3]*(U1[2]*U2[2])+HESS[5]*(U1[3]
           *U2[3])+HESS[6]*(U1[3]*U2[6])+HESS[11]*(U1[5]*U2[8])
           +HESS[12]*(U1[6]*U2[6])+HESS[13]*(U1[6]*U2[7])+HESS[16]
           *(U1[7]*U2[7])+HESS[20]*(U1[8]*U2[8])+HESS[21]*(U1[9]*U2[7])
           +HESS[24]*(U1[9]*U2[8])+HESS[27]*(U1[10]*U2[2])+HESS[28]
           *(U1[10]*U2[3])+HESS[29]*(U1[10]*U2[6])+HESS[36]*(U1[10]
           *U2[10])+HESS[37]*(U1[10]*U2[11])+HESS[42]*(U1[11]*U2[11])
           +HESS[60]*(U1[14]*U2[14])+HESS[61]*(U1[15]*U2[2])+HESS[62]
           *(U1[15]*U2[3])+HESS[63]*(U1[15]*U2[6])+HESS[64]*(U1[15]
           *U2[7])+HESS[66]*(U1[15]*U2[8])+HESS[69]*(U1[15]*U2[10])
           +HESS[70]*(U1[15]*U2[11])+HESS[71]*(U1[15]*U2[14]);
}

/* End of HessTR_Vec function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Hess_Vec - Hessian times user vectors                            */
/*   Arguments :                                                    */
/*      HESS      - Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
/*      U1        - User vector                                     */
/*      U2        - User vector                                     */
/*      HU        - Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2 */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Hess_Vec( 
  double HESS[],                         /* Hessian of Var (i.e. the 3-tensor d Jac / d Var) */
  double U1[],                           /* User vector */
  double U2[],                           /* User vector */
  double HU[]                            /* Hessian times user vectors: (Hess x U2) * U1 = [d (Jac*U1)/d Var] * U2 */
)
{
/* Compute the vector HU =(Hess x U2) * U1 = d (Jac*U1)/d Var * U2  */
  HU[0] = HESS[0]*(U1[10]*U2[13])+HESS[0]*(U1[13]*U2[10])+HESS[1]
         *(U1[14]*U2[15])+HESS[1]*(U1[15]*U2[14]);
  HU[1] = HESS[2]*(U1[13]*U2[14])+HESS[2]*(U1[14]*U2[13]);
  HU[2] = HESS[3]*(U1[2]*U2[15])+HESS[3]*(U1[15]*U2[2])+HESS[4]*(U1[10]
         *U2[10]);
  HU[3] = HESS[5]*(U1[3]*U2[15])+HESS[5]*(U1[15]*U2[3])+HESS[6]*(U1[6]
         *U2[15])+HESS[6]*(U1[15]*U2[6]);
  HU[4] = HESS[7]*(U1[5]*U2[14])+HESS[7]*(U1[14]*U2[5]);
  HU[5] = HESS[8]*(U1[5]*U2[14])+HESS[8]*(U1[14]*U2[5])+HESS[9]*(U1[8]
         *U2[11])+HESS[9]*(U1[11]*U2[8])+HESS[10]*(U1[8]*U2[13])
         +HESS[10]*(U1[13]*U2[8])+HESS[11]*(U1[8]*U2[15])+HESS[11]
         *(U1[15]*U2[8]);
  HU[6] = HESS[12]*(U1[6]*U2[15])+HESS[12]*(U1[15]*U2[6])+HESS[13]
         *(U1[7]*U2[15])+HESS[13]*(U1[15]*U2[7])+HESS[14]*(U1[9]
         *U2[10])+HESS[14]*(U1[10]*U2[9])+HESS[15]*(U1[9]*U2[12])
         +HESS[15]*(U1[12]*U2[9]);
  HU[7] = HESS[16]*(U1[7]*U2[15])+HESS[16]*(U1[15]*U2[7])+HESS[17]
         *(U1[9]*U2[10])+HESS[17]*(U1[10]*U2[9]);
  HU[8] = HESS[18]*(U1[8]*U2[11])+HESS[18]*(U1[11]*U2[8])+HESS[19]
         *(U1[8]*U2[13])+HESS[19]*(U1[13]*U2[8])+HESS[20]*(U1[8]
         *U2[15])+HESS[20]*(U1[15]*U2[8]);
  HU[9] = HESS[21]*(U1[7]*U2[15])+HESS[21]*(U1[15]*U2[7])+HESS[22]
         *(U1[8]*U2[11])+HESS[22]*(U1[11]*U2[8])+HESS[23]*(U1[8]
         *U2[13])+HESS[23]*(U1[13]*U2[8])+HESS[24]*(U1[8]*U2[15])
         +HESS[24]*(U1[15]*U2[8])+HESS[25]*(U1[9]*U2[10])+HESS[25]
         *(U1[10]*U2[9])+HESS[26]*(U1[9]*U2[12])+HESS[26]*(U1[12]
         *U2[9]);
  HU[10] = HESS[27]*(U1[2]*U2[15])+HESS[27]*(U1[15]*U2[2])+HESS[28]
          *(U1[3]*U2[15])+HESS[28]*(U1[15]*U2[3])+HESS[29]*(U1[6]
          *U2[15])+HESS[29]*(U1[15]*U2[6])+HESS[30]*(U1[9]*U2[10])
          +HESS[30]*(U1[10]*U2[9])+HESS[31]*(U1[9]*U2[12])+HESS[31]
          *(U1[12]*U2[9])+HESS[32]*(U1[10]*U2[10])+HESS[33]*(U1[10]
          *U2[11])+HESS[33]*(U1[11]*U2[10])+HESS[34]*(U1[10]*U2[12])
          +HESS[34]*(U1[12]*U2[10])+HESS[35]*(U1[10]*U2[13])+HESS[35]
          *(U1[13]*U2[10])+HESS[36]*(U1[10]*U2[15])+HESS[36]*(U1[15]
          *U2[10])+HESS[37]*(U1[11]*U2[15])+HESS[37]*(U1[15]*U2[11]);
  HU[11] = HESS[38]*(U1[8]*U2[11])+HESS[38]*(U1[11]*U2[8])+HESS[39]
          *(U1[10]*U2[11])+HESS[39]*(U1[11]*U2[10])+HESS[40]*(U1[11]
          *U2[12])+HESS[40]*(U1[12]*U2[11])+HESS[41]*(U1[11]*U2[14])
          +HESS[41]*(U1[14]*U2[11])+HESS[42]*(U1[11]*U2[15])+HESS[42]
          *(U1[15]*U2[11]);
  HU[12] = HESS[43]*(U1[9]*U2[12])+HESS[43]*(U1[12]*U2[9])+HESS[44]
          *(U1[10]*U2[12])+HESS[44]*(U1[12]*U2[10])+HESS[45]*(U1[11]
          *U2[12])+HESS[45]*(U1[12]*U2[11])+HESS[46]*(U1[12]*U2[13])
          +HESS[46]*(U1[13]*U2[12]);
  HU[13] = HESS[47]*(U1[8]*U2[13])+HESS[47]*(U1[13]*U2[8])+HESS[48]
          *(U1[10]*U2[13])+HESS[48]*(U1[13]*U2[10])+HESS[49]*(U1[11]
          *U2[14])+HESS[49]*(U1[14]*U2[11])+HESS[50]*(U1[12]*U2[13])
          +HESS[50]*(U1[13]*U2[12])+HESS[51]*(U1[13]*U2[14])+HESS[51]
          *(U1[14]*U2[13]);
  HU[14] = HESS[52]*(U1[5]*U2[14])+HESS[52]*(U1[14]*U2[5])+HESS[53]
          *(U1[8]*U2[13])+HESS[53]*(U1[13]*U2[8])+HESS[54]*(U1[9]
          *U2[12])+HESS[54]*(U1[12]*U2[9])+HESS[55]*(U1[10]*U2[12])
          +HESS[55]*(U1[12]*U2[10])+HESS[56]*(U1[11]*U2[12])+HESS[56]
          *(U1[12]*U2[11])+HESS[57]*(U1[11]*U2[14])+HESS[57]*(U1[14]
          *U2[11])+HESS[58]*(U1[12]*U2[13])+HESS[58]*(U1[13]*U2[12])
          +HESS[59]*(U1[13]*U2[14])+HESS[59]*(U1[14]*U2[13])+HESS[60]
          *(U1[14]*U2[15])+HESS[60]*(U1[15]*U2[14]);
  HU[15] = HESS[61]*(U1[2]*U2[15])+HESS[61]*(U1[15]*U2[2])+HESS[62]
          *(U1[3]*U2[15])+HESS[62]*(U1[15]*U2[3])+HESS[63]*(U1[6]
          *U2[15])+HESS[63]*(U1[15]*U2[6])+HESS[64]*(U1[7]*U2[15])
          +HESS[64]*(U1[15]*U2[7])+HESS[65]*(U1[8]*U2[11])+HESS[65]
          *(U1[11]*U2[8])+HESS[66]*(U1[8]*U2[15])+HESS[66]*(U1[15]
          *U2[8])+HESS[67]*(U1[10]*U2[11])+HESS[67]*(U1[11]*U2[10])
          +HESS[68]*(U1[10]*U2[12])+HESS[68]*(U1[12]*U2[10])+HESS[69]
          *(U1[10]*U2[15])+HESS[69]*(U1[15]*U2[10])+HESS[70]*(U1[11]
          *U2[15])+HESS[70]*(U1[15]*U2[11])+HESS[71]*(U1[14]*U2[15])
          +HESS[71]*(U1[15]*U2[14]);
}

/* End of Hess_Vec function                                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


