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
/* File                 : orlando_Hessian.c                         */
/* Time                 : Wed Aug 19 11:17:37 2020                  */
/* Working directory    : /home/WUR/krol005/kpp/examples            */
/* Equation file        : orlando.kpp                               */
/* Output root filename : orlando                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "orlando_Parameters.h"
#include "orlando_Global.h"
#include "orlando_Sparse.h"


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
double D2A[30];                          /* Second derivatives of equation rates */

/* Computation of the second derivatives of equation rates          */
/* D2A(0) = d^2 A(4) / dV(12)dV(18)                                 */
  D2A[0] = RCT[4];
/* D2A(1) = d^2 A(5) / dV(17)dV(18)                                 */
  D2A[1] = RCT[5];
/* D2A(2) = d^2 A(6)/{dV(12)dV(12)}                                 */
  D2A[2] = RCT[6]*2;
/* D2A(3) = d^2 A(7) / dV(12)dV(17)                                 */
  D2A[3] = RCT[7];
/* D2A(4) = d^2 A(8) / dV(13)dV(17)                                 */
  D2A[4] = RCT[8];
/* D2A(5) = d^2 A(9) / dV(11)dV(18)                                 */
  D2A[5] = RCT[9];
/* D2A(6) = d^2 A(10) / dV(11)dV(17)                                */
  D2A[6] = RCT[10];
/* D2A(7) = d^2 A(11) / dV(12)dV(13)                                */
  D2A[7] = RCT[11];
/* D2A(8) = d^2 A(12) / dV(11)dV(16)                                */
  D2A[8] = RCT[12];
/* D2A(9) = d^2 A(13) / dV(13)dV(16)                                */
  D2A[9] = RCT[13];
/* D2A(10) = d^2 A(14) / dV(12)dV(16)                               */
  D2A[10] = RCT[14];
/* D2A(11) = d^2 A(18) / dV(13)dV(15)                               */
  D2A[11] = RCT[18];
/* D2A(12) = d^2 A(19) / dV(12)dV(15)                               */
  D2A[12] = RCT[19];
/* D2A(13) = d^2 A(20) / dV(4)dV(18)                                */
  D2A[13] = RCT[20];
/* D2A(14) = d^2 A(21) / dV(0)dV(18)                                */
  D2A[14] = RCT[21];
/* D2A(15) = d^2 A(22) / dV(5)dV(18)                                */
  D2A[15] = RCT[22];
/* D2A(16) = d^2 A(23) / dV(7)dV(18)                                */
  D2A[16] = RCT[23];
/* D2A(17) = d^2 A(24) / dV(10)dV(15)                               */
  D2A[17] = RCT[24];
/* D2A(18) = d^2 A(25) / dV(10)dV(12)                               */
  D2A[18] = RCT[25];
/* D2A(19) = d^2 A(26) / dV(10)dV(13)                               */
  D2A[19] = RCT[26];
/* D2A(20) = d^2 A(27) / dV(14)dV(15)                               */
  D2A[20] = RCT[27];
/* D2A(21) = d^2 A(28) / dV(12)dV(14)                               */
  D2A[21] = RCT[28];
/* D2A(22) = d^2 A(30) / dV(13)dV(14)                               */
  D2A[22] = RCT[30];
/* D2A(23) = d^2 A(31) / dV(6)dV(18)                                */
  D2A[23] = RCT[31];
/* D2A(24) = d^2 A(33) / dV(3)dV(18)                                */
  D2A[24] = RCT[33];
/* D2A(25) = d^2 A(35) / dV(8)dV(12)                                */
  D2A[25] = RCT[35];
/* D2A(26) = d^2 A(36) / dV(8)dV(13)                                */
  D2A[26] = RCT[36];
/* D2A(27) = d^2 A(37) / dV(9)dV(18)                                */
  D2A[27] = RCT[37];
/* D2A(28) = d^2 A(38) / dV(7)dV(17)                                */
  D2A[28] = RCT[38];
/* D2A(29) = d^2 A(39) / dV(7)dV(16)                                */
  D2A[29] = RCT[39];

/* Computation of the Jacobian derivative                           */
/* HESS(0) = d^2 Vdot(0)/{dV(0)dV(18)} = d^2 Vdot(0)/{dV(18)dV(0)}  */
  HESS[0] = -D2A[14];
/* HESS(1) = d^2 Vdot(1)/{dV(7)dV(17)} = d^2 Vdot(1)/{dV(17)dV(7)}  */
  HESS[1] = 0.29*D2A[28];
/* HESS(2) = d^2 Vdot(1)/{dV(12)dV(12)} = d^2 Vdot(1)/{dV(12)dV(12)} */
  HESS[2] = D2A[2];
/* HESS(3) = d^2 Vdot(2)/{dV(11)dV(16)} = d^2 Vdot(2)/{dV(16)dV(11)} */
  HESS[3] = D2A[8];
/* HESS(4) = d^2 Vdot(3)/{dV(3)dV(18)} = d^2 Vdot(3)/{dV(18)dV(3)}  */
  HESS[4] = -D2A[24];
/* HESS(5) = d^2 Vdot(3)/{dV(13)dV(14)} = d^2 Vdot(3)/{dV(14)dV(13)} */
  HESS[5] = 0.87*D2A[22];
/* HESS(6) = d^2 Vdot(3)/{dV(14)dV(15)} = d^2 Vdot(3)/{dV(15)dV(14)} */
  HESS[6] = 0.75*D2A[20];
/* HESS(7) = d^2 Vdot(4)/{dV(4)dV(18)} = d^2 Vdot(4)/{dV(18)dV(4)}  */
  HESS[7] = -D2A[13];
/* HESS(8) = d^2 Vdot(4)/{dV(5)dV(18)} = d^2 Vdot(4)/{dV(18)dV(5)}  */
  HESS[8] = D2A[15];
/* HESS(9) = d^2 Vdot(4)/{dV(7)dV(17)} = d^2 Vdot(4)/{dV(17)dV(7)}  */
  HESS[9] = 0.363*D2A[28];
/* HESS(10) = d^2 Vdot(4)/{dV(8)dV(13)} = d^2 Vdot(4)/{dV(13)dV(8)} */
  HESS[10] = 0.25*D2A[26];
/* HESS(11) = d^2 Vdot(4)/{dV(10)dV(13)} = d^2 Vdot(4)/{dV(13)dV(10)} */
  HESS[11] = 0.9*D2A[19];
/* HESS(12) = d^2 Vdot(4)/{dV(13)dV(14)} = d^2 Vdot(4)/{dV(14)dV(13)} */
  HESS[12] = 0.15*D2A[22];
/* HESS(13) = d^2 Vdot(5)/{dV(5)dV(18)} = d^2 Vdot(5)/{dV(18)dV(5)} */
  HESS[13] = -D2A[15];
/* HESS(14) = d^2 Vdot(5)/{dV(7)dV(17)} = d^2 Vdot(5)/{dV(17)dV(7)} */
  HESS[14] = 0.785*D2A[28];
/* HESS(15) = d^2 Vdot(5)/{dV(8)dV(13)} = d^2 Vdot(5)/{dV(13)dV(8)} */
  HESS[15] = 0.25*D2A[26];
/* HESS(16) = d^2 Vdot(5)/{dV(9)dV(18)} = d^2 Vdot(5)/{dV(18)dV(9)} */
  HESS[16] = D2A[27];
/* HESS(17) = d^2 Vdot(5)/{dV(10)dV(13)} = d^2 Vdot(5)/{dV(13)dV(10)} */
  HESS[17] = 0.9*D2A[19];
/* HESS(18) = d^2 Vdot(5)/{dV(10)dV(15)} = d^2 Vdot(5)/{dV(15)dV(10)} */
  HESS[18] = 1.5*D2A[17];
/* HESS(19) = d^2 Vdot(5)/{dV(13)dV(14)} = d^2 Vdot(5)/{dV(14)dV(13)} */
  HESS[19] = 0.1*D2A[22];
/* HESS(20) = d^2 Vdot(5)/{dV(13)dV(15)} = d^2 Vdot(5)/{dV(15)dV(13)} */
  HESS[20] = D2A[11];
/* HESS(21) = d^2 Vdot(5)/{dV(14)dV(15)} = d^2 Vdot(5)/{dV(15)dV(14)} */
  HESS[21] = 0.75*D2A[20];
/* HESS(22) = d^2 Vdot(6)/{dV(6)dV(18)} = d^2 Vdot(6)/{dV(18)dV(6)} */
  HESS[22] = -D2A[23];
/* HESS(23) = d^2 Vdot(6)/{dV(10)dV(12)} = d^2 Vdot(6)/{dV(12)dV(10)} */
  HESS[23] = D2A[18];
/* HESS(24) = d^2 Vdot(6)/{dV(12)dV(14)} = d^2 Vdot(6)/{dV(14)dV(12)} */
  HESS[24] = D2A[21];
/* HESS(25) = d^2 Vdot(7)/{dV(7)dV(16)} = d^2 Vdot(7)/{dV(16)dV(7)} */
  HESS[25] = -D2A[29];
/* HESS(26) = d^2 Vdot(7)/{dV(7)dV(17)} = d^2 Vdot(7)/{dV(17)dV(7)} */
  HESS[26] = -D2A[28];
/* HESS(27) = d^2 Vdot(7)/{dV(7)dV(18)} = d^2 Vdot(7)/{dV(18)dV(7)} */
  HESS[27] = -D2A[16];
/* HESS(28) = d^2 Vdot(8)/{dV(3)dV(18)} = d^2 Vdot(8)/{dV(18)dV(3)} */
  HESS[28] = D2A[24];
/* HESS(29) = d^2 Vdot(8)/{dV(6)dV(18)} = d^2 Vdot(8)/{dV(18)dV(6)} */
  HESS[29] = 0.4*D2A[23];
/* HESS(30) = d^2 Vdot(8)/{dV(8)dV(12)} = d^2 Vdot(8)/{dV(12)dV(8)} */
  HESS[30] = -D2A[25];
/* HESS(31) = d^2 Vdot(8)/{dV(8)dV(13)} = d^2 Vdot(8)/{dV(13)dV(8)} */
  HESS[31] = -D2A[26];
/* HESS(32) = d^2 Vdot(9)/{dV(7)dV(17)} = d^2 Vdot(9)/{dV(17)dV(7)} */
  HESS[32] = 0.675*D2A[28];
/* HESS(33) = d^2 Vdot(9)/{dV(9)dV(18)} = d^2 Vdot(9)/{dV(18)dV(9)} */
  HESS[33] = -D2A[27];
/* HESS(34) = d^2 Vdot(9)/{dV(10)dV(13)} = d^2 Vdot(9)/{dV(13)dV(10)} */
  HESS[34] = 0.9*D2A[19];
/* HESS(35) = d^2 Vdot(9)/{dV(10)dV(15)} = d^2 Vdot(9)/{dV(15)dV(10)} */
  HESS[35] = 0.75*D2A[17];
/* HESS(36) = d^2 Vdot(10)/{dV(7)dV(18)} = d^2 Vdot(10)/{dV(18)dV(7)} */
  HESS[36] = 0.6*D2A[16];
/* HESS(37) = d^2 Vdot(10)/{dV(10)dV(12)} = d^2 Vdot(10)/{dV(12)dV(10)} */
  HESS[37] = -D2A[18];
/* HESS(38) = d^2 Vdot(10)/{dV(10)dV(13)} = d^2 Vdot(10)/{dV(13)dV(10)} */
  HESS[38] = -D2A[19];
/* HESS(39) = d^2 Vdot(10)/{dV(10)dV(15)} = d^2 Vdot(10)/{dV(15)dV(10)} */
  HESS[39] = -D2A[17];
/* HESS(40) = d^2 Vdot(11)/{dV(8)dV(13)} = d^2 Vdot(11)/{dV(13)dV(8)} */
  HESS[40] = 0.9*D2A[26];
/* HESS(41) = d^2 Vdot(11)/{dV(10)dV(13)} = d^2 Vdot(11)/{dV(13)dV(10)} */
  HESS[41] = 0.9*D2A[19];
/* HESS(42) = d^2 Vdot(11)/{dV(11)dV(16)} = d^2 Vdot(11)/{dV(16)dV(11)} */
  HESS[42] = -D2A[8];
/* HESS(43) = d^2 Vdot(11)/{dV(11)dV(17)} = d^2 Vdot(11)/{dV(17)dV(11)} */
  HESS[43] = -D2A[6];
/* HESS(44) = d^2 Vdot(11)/{dV(11)dV(18)} = d^2 Vdot(11)/{dV(18)dV(11)} */
  HESS[44] = -D2A[5];
/* HESS(45) = d^2 Vdot(11)/{dV(12)dV(13)} = d^2 Vdot(11)/{dV(13)dV(12)} */
  HESS[45] = D2A[7];
/* HESS(46) = d^2 Vdot(11)/{dV(12)dV(16)} = d^2 Vdot(11)/{dV(16)dV(12)} */
  HESS[46] = D2A[10];
/* HESS(47) = d^2 Vdot(11)/{dV(13)dV(14)} = d^2 Vdot(11)/{dV(14)dV(13)} */
  HESS[47] = 0.9*D2A[22];
/* HESS(48) = d^2 Vdot(11)/{dV(13)dV(15)} = d^2 Vdot(11)/{dV(15)dV(13)} */
  HESS[48] = 0.99*D2A[11];
/* HESS(49) = d^2 Vdot(11)/{dV(13)dV(16)} = d^2 Vdot(11)/{dV(16)dV(13)} */
  HESS[49] = 2*D2A[9];
/* HESS(50) = d^2 Vdot(11)/{dV(13)dV(17)} = d^2 Vdot(11)/{dV(17)dV(13)} */
  HESS[50] = D2A[4];
/* HESS(51) = d^2 Vdot(12)/{dV(4)dV(18)} = d^2 Vdot(12)/{dV(18)dV(4)} */
  HESS[51] = D2A[13];
/* HESS(52) = d^2 Vdot(12)/{dV(5)dV(18)} = d^2 Vdot(12)/{dV(18)dV(5)} */
  HESS[52] = D2A[15];
/* HESS(53) = d^2 Vdot(12)/{dV(7)dV(17)} = d^2 Vdot(12)/{dV(17)dV(7)} */
  HESS[53] = 0.125*D2A[28];
/* HESS(54) = d^2 Vdot(12)/{dV(8)dV(12)} = d^2 Vdot(12)/{dV(12)dV(8)} */
  HESS[54] = -D2A[25];
/* HESS(55) = d^2 Vdot(12)/{dV(8)dV(13)} = d^2 Vdot(12)/{dV(13)dV(8)} */
  HESS[55] = D2A[26];
/* HESS(56) = d^2 Vdot(12)/{dV(9)dV(18)} = d^2 Vdot(12)/{dV(18)dV(9)} */
  HESS[56] = D2A[27];
/* HESS(57) = d^2 Vdot(12)/{dV(10)dV(12)} = d^2 Vdot(12)/{dV(12)dV(10)} */
  HESS[57] = -D2A[18];
/* HESS(58) = d^2 Vdot(12)/{dV(10)dV(13)} = d^2 Vdot(12)/{dV(13)dV(10)} */
  HESS[58] = 0.9*D2A[19];
/* HESS(59) = d^2 Vdot(12)/{dV(10)dV(15)} = d^2 Vdot(12)/{dV(15)dV(10)} */
  HESS[59] = D2A[17];
/* HESS(60) = d^2 Vdot(12)/{dV(12)dV(12)} = d^2 Vdot(12)/{dV(12)dV(12)} */
  HESS[60] = -2*D2A[2];
/* HESS(61) = d^2 Vdot(12)/{dV(12)dV(13)} = d^2 Vdot(12)/{dV(13)dV(12)} */
  HESS[61] = -D2A[7];
/* HESS(62) = d^2 Vdot(12)/{dV(12)dV(14)} = d^2 Vdot(12)/{dV(14)dV(12)} */
  HESS[62] = -D2A[21];
/* HESS(63) = d^2 Vdot(12)/{dV(12)dV(15)} = d^2 Vdot(12)/{dV(15)dV(12)} */
  HESS[63] = -D2A[12];
/* HESS(64) = d^2 Vdot(12)/{dV(12)dV(16)} = d^2 Vdot(12)/{dV(16)dV(12)} */
  HESS[64] = -D2A[10];
/* HESS(65) = d^2 Vdot(12)/{dV(12)dV(17)} = d^2 Vdot(12)/{dV(17)dV(12)} */
  HESS[65] = -D2A[3];
/* HESS(66) = d^2 Vdot(12)/{dV(12)dV(18)} = d^2 Vdot(12)/{dV(18)dV(12)} */
  HESS[66] = -D2A[0];
/* HESS(67) = d^2 Vdot(12)/{dV(13)dV(14)} = d^2 Vdot(12)/{dV(14)dV(13)} */
  HESS[67] = 0.97*D2A[22];
/* HESS(68) = d^2 Vdot(12)/{dV(13)dV(15)} = d^2 Vdot(12)/{dV(15)dV(13)} */
  HESS[68] = D2A[11];
/* HESS(69) = d^2 Vdot(12)/{dV(14)dV(15)} = d^2 Vdot(12)/{dV(15)dV(14)} */
  HESS[69] = D2A[20];
/* HESS(70) = d^2 Vdot(12)/{dV(17)dV(18)} = d^2 Vdot(12)/{dV(18)dV(17)} */
  HESS[70] = D2A[1];
/* HESS(71) = d^2 Vdot(13)/{dV(8)dV(13)} = d^2 Vdot(13)/{dV(13)dV(8)} */
  HESS[71] = -D2A[26];
/* HESS(72) = d^2 Vdot(13)/{dV(10)dV(13)} = d^2 Vdot(13)/{dV(13)dV(10)} */
  HESS[72] = -D2A[19];
/* HESS(73) = d^2 Vdot(13)/{dV(12)dV(13)} = d^2 Vdot(13)/{dV(13)dV(12)} */
  HESS[73] = -D2A[7];
/* HESS(74) = d^2 Vdot(13)/{dV(13)dV(14)} = d^2 Vdot(13)/{dV(14)dV(13)} */
  HESS[74] = -D2A[22];
/* HESS(75) = d^2 Vdot(13)/{dV(13)dV(15)} = d^2 Vdot(13)/{dV(15)dV(13)} */
  HESS[75] = -D2A[11];
/* HESS(76) = d^2 Vdot(13)/{dV(13)dV(16)} = d^2 Vdot(13)/{dV(16)dV(13)} */
  HESS[76] = -D2A[9];
/* HESS(77) = d^2 Vdot(13)/{dV(13)dV(17)} = d^2 Vdot(13)/{dV(17)dV(13)} */
  HESS[77] = -D2A[4];
/* HESS(78) = d^2 Vdot(14)/{dV(7)dV(18)} = d^2 Vdot(14)/{dV(18)dV(7)} */
  HESS[78] = 0.4*D2A[16];
/* HESS(79) = d^2 Vdot(14)/{dV(12)dV(14)} = d^2 Vdot(14)/{dV(14)dV(12)} */
  HESS[79] = -D2A[21];
/* HESS(80) = d^2 Vdot(14)/{dV(13)dV(14)} = d^2 Vdot(14)/{dV(14)dV(13)} */
  HESS[80] = -D2A[22];
/* HESS(81) = d^2 Vdot(14)/{dV(14)dV(15)} = d^2 Vdot(14)/{dV(15)dV(14)} */
  HESS[81] = -D2A[20];
/* HESS(82) = d^2 Vdot(15)/{dV(0)dV(18)} = d^2 Vdot(15)/{dV(18)dV(0)} */
  HESS[82] = D2A[14];
/* HESS(83) = d^2 Vdot(15)/{dV(7)dV(17)} = d^2 Vdot(15)/{dV(17)dV(7)} */
  HESS[83] = 0.181*D2A[28];
/* HESS(84) = d^2 Vdot(15)/{dV(9)dV(18)} = d^2 Vdot(15)/{dV(18)dV(9)} */
  HESS[84] = 1.5*D2A[27];
/* HESS(85) = d^2 Vdot(15)/{dV(10)dV(15)} = d^2 Vdot(15)/{dV(15)dV(10)} */
  HESS[85] = -D2A[17];
/* HESS(86) = d^2 Vdot(15)/{dV(12)dV(15)} = d^2 Vdot(15)/{dV(15)dV(12)} */
  HESS[86] = -D2A[12];
/* HESS(87) = d^2 Vdot(15)/{dV(13)dV(15)} = d^2 Vdot(15)/{dV(15)dV(13)} */
  HESS[87] = -D2A[11];
/* HESS(88) = d^2 Vdot(15)/{dV(14)dV(15)} = d^2 Vdot(15)/{dV(15)dV(14)} */
  HESS[88] = -D2A[20];
/* HESS(89) = d^2 Vdot(16)/{dV(7)dV(16)} = d^2 Vdot(16)/{dV(16)dV(7)} */
  HESS[89] = -D2A[29];
/* HESS(90) = d^2 Vdot(16)/{dV(11)dV(16)} = d^2 Vdot(16)/{dV(16)dV(11)} */
  HESS[90] = -D2A[8];
/* HESS(91) = d^2 Vdot(16)/{dV(11)dV(17)} = d^2 Vdot(16)/{dV(17)dV(11)} */
  HESS[91] = D2A[6];
/* HESS(92) = d^2 Vdot(16)/{dV(12)dV(16)} = d^2 Vdot(16)/{dV(16)dV(12)} */
  HESS[92] = -D2A[10];
/* HESS(93) = d^2 Vdot(16)/{dV(13)dV(16)} = d^2 Vdot(16)/{dV(16)dV(13)} */
  HESS[93] = -D2A[9];
/* HESS(94) = d^2 Vdot(17)/{dV(7)dV(17)} = d^2 Vdot(17)/{dV(17)dV(7)} */
  HESS[94] = -D2A[28];
/* HESS(95) = d^2 Vdot(17)/{dV(11)dV(17)} = d^2 Vdot(17)/{dV(17)dV(11)} */
  HESS[95] = -D2A[6];
/* HESS(96) = d^2 Vdot(17)/{dV(12)dV(17)} = d^2 Vdot(17)/{dV(17)dV(12)} */
  HESS[96] = -D2A[3];
/* HESS(97) = d^2 Vdot(17)/{dV(13)dV(17)} = d^2 Vdot(17)/{dV(17)dV(13)} */
  HESS[97] = -D2A[4];
/* HESS(98) = d^2 Vdot(17)/{dV(17)dV(18)} = d^2 Vdot(17)/{dV(18)dV(17)} */
  HESS[98] = -D2A[1];
/* HESS(99) = d^2 Vdot(18)/{dV(0)dV(18)} = d^2 Vdot(18)/{dV(18)dV(0)} */
  HESS[99] = -D2A[14];
/* HESS(100) = d^2 Vdot(18)/{dV(3)dV(18)} = d^2 Vdot(18)/{dV(18)dV(3)} */
  HESS[100] = -D2A[24];
/* HESS(101) = d^2 Vdot(18)/{dV(4)dV(18)} = d^2 Vdot(18)/{dV(18)dV(4)} */
  HESS[101] = -D2A[13];
/* HESS(102) = d^2 Vdot(18)/{dV(5)dV(18)} = d^2 Vdot(18)/{dV(18)dV(5)} */
  HESS[102] = -D2A[15];
/* HESS(103) = d^2 Vdot(18)/{dV(6)dV(18)} = d^2 Vdot(18)/{dV(18)dV(6)} */
  HESS[103] = -0.4*D2A[23];
/* HESS(104) = d^2 Vdot(18)/{dV(7)dV(17)} = d^2 Vdot(18)/{dV(17)dV(7)} */
  HESS[104] = 0.205*D2A[28];
/* HESS(105) = d^2 Vdot(18)/{dV(7)dV(18)} = d^2 Vdot(18)/{dV(18)dV(7)} */
  HESS[105] = -D2A[16];
/* HESS(106) = d^2 Vdot(18)/{dV(9)dV(18)} = d^2 Vdot(18)/{dV(18)dV(9)} */
  HESS[106] = -D2A[27];
/* HESS(107) = d^2 Vdot(18)/{dV(11)dV(18)} = d^2 Vdot(18)/{dV(18)dV(11)} */
  HESS[107] = -D2A[5];
/* HESS(108) = d^2 Vdot(18)/{dV(12)dV(13)} = d^2 Vdot(18)/{dV(13)dV(12)} */
  HESS[108] = D2A[7];
/* HESS(109) = d^2 Vdot(18)/{dV(12)dV(16)} = d^2 Vdot(18)/{dV(16)dV(12)} */
  HESS[109] = D2A[10];
/* HESS(110) = d^2 Vdot(18)/{dV(12)dV(17)} = d^2 Vdot(18)/{dV(17)dV(12)} */
  HESS[110] = D2A[3];
/* HESS(111) = d^2 Vdot(18)/{dV(12)dV(18)} = d^2 Vdot(18)/{dV(18)dV(12)} */
  HESS[111] = -D2A[0];
/* HESS(112) = d^2 Vdot(18)/{dV(17)dV(18)} = d^2 Vdot(18)/{dV(18)dV(17)} */
  HESS[112] = -D2A[1];
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
  HTU[0] = HESS[0]*(U1[0]*U2[18])+HESS[82]*(U1[15]*U2[18])+HESS[99]
          *(U1[18]*U2[18]);
  HTU[1] = 0;
  HTU[2] = 0;
  HTU[3] = HESS[4]*(U1[3]*U2[18])+HESS[28]*(U1[8]*U2[18])+HESS[100]
          *(U1[18]*U2[18]);
  HTU[4] = HESS[7]*(U1[4]*U2[18])+HESS[51]*(U1[12]*U2[18])+HESS[101]
          *(U1[18]*U2[18]);
  HTU[5] = HESS[8]*(U1[4]*U2[18])+HESS[13]*(U1[5]*U2[18])+HESS[52]
          *(U1[12]*U2[18])+HESS[102]*(U1[18]*U2[18]);
  HTU[6] = HESS[22]*(U1[6]*U2[18])+HESS[29]*(U1[8]*U2[18])+HESS[103]
          *(U1[18]*U2[18]);
  HTU[7] = HESS[1]*(U1[1]*U2[17])+HESS[9]*(U1[4]*U2[17])+HESS[14]
          *(U1[5]*U2[17])+HESS[25]*(U1[7]*U2[16])+HESS[26]*(U1[7]
          *U2[17])+HESS[27]*(U1[7]*U2[18])+HESS[32]*(U1[9]*U2[17])
          +HESS[36]*(U1[10]*U2[18])+HESS[53]*(U1[12]*U2[17])+HESS[78]
          *(U1[14]*U2[18])+HESS[83]*(U1[15]*U2[17])+HESS[89]*(U1[16]
          *U2[16])+HESS[94]*(U1[17]*U2[17])+HESS[104]*(U1[18]*U2[17])
          +HESS[105]*(U1[18]*U2[18]);
  HTU[8] = HESS[10]*(U1[4]*U2[13])+HESS[15]*(U1[5]*U2[13])+HESS[30]
          *(U1[8]*U2[12])+HESS[31]*(U1[8]*U2[13])+HESS[40]*(U1[11]
          *U2[13])+HESS[54]*(U1[12]*U2[12])+HESS[55]*(U1[12]*U2[13])
          +HESS[71]*(U1[13]*U2[13]);
  HTU[9] = HESS[16]*(U1[5]*U2[18])+HESS[33]*(U1[9]*U2[18])+HESS[56]
          *(U1[12]*U2[18])+HESS[84]*(U1[15]*U2[18])+HESS[106]*(U1[18]
          *U2[18]);
  HTU[10] = HESS[11]*(U1[4]*U2[13])+HESS[17]*(U1[5]*U2[13])+HESS[18]
           *(U1[5]*U2[15])+HESS[23]*(U1[6]*U2[12])+HESS[34]*(U1[9]
           *U2[13])+HESS[35]*(U1[9]*U2[15])+HESS[37]*(U1[10]*U2[12])
           +HESS[38]*(U1[10]*U2[13])+HESS[39]*(U1[10]*U2[15])+HESS[41]
           *(U1[11]*U2[13])+HESS[57]*(U1[12]*U2[12])+HESS[58]*(U1[12]
           *U2[13])+HESS[59]*(U1[12]*U2[15])+HESS[72]*(U1[13]*U2[13])
           +HESS[85]*(U1[15]*U2[15]);
  HTU[11] = HESS[3]*(U1[2]*U2[16])+HESS[42]*(U1[11]*U2[16])+HESS[43]
           *(U1[11]*U2[17])+HESS[44]*(U1[11]*U2[18])+HESS[90]*(U1[16]
           *U2[16])+HESS[91]*(U1[16]*U2[17])+HESS[95]*(U1[17]*U2[17])
           +HESS[107]*(U1[18]*U2[18]);
  HTU[12] = HESS[2]*(U1[1]*U2[12])+HESS[23]*(U1[6]*U2[10])+HESS[24]
           *(U1[6]*U2[14])+HESS[30]*(U1[8]*U2[8])+HESS[37]*(U1[10]
           *U2[10])+HESS[45]*(U1[11]*U2[13])+HESS[46]*(U1[11]*U2[16])
           +HESS[54]*(U1[12]*U2[8])+HESS[57]*(U1[12]*U2[10])+HESS[60]
           *(U1[12]*U2[12])+HESS[61]*(U1[12]*U2[13])+HESS[62]*(U1[12]
           *U2[14])+HESS[63]*(U1[12]*U2[15])+HESS[64]*(U1[12]*U2[16])
           +HESS[65]*(U1[12]*U2[17])+HESS[66]*(U1[12]*U2[18])+HESS[73]
           *(U1[13]*U2[13])+HESS[79]*(U1[14]*U2[14])+HESS[86]*(U1[15]
           *U2[15])+HESS[92]*(U1[16]*U2[16])+HESS[96]*(U1[17]*U2[17])
           +HESS[108]*(U1[18]*U2[13])+HESS[109]*(U1[18]*U2[16])
           +HESS[110]*(U1[18]*U2[17])+HESS[111]*(U1[18]*U2[18]);
  HTU[13] = HESS[5]*(U1[3]*U2[14])+HESS[10]*(U1[4]*U2[8])+HESS[11]
           *(U1[4]*U2[10])+HESS[12]*(U1[4]*U2[14])+HESS[15]*(U1[5]
           *U2[8])+HESS[17]*(U1[5]*U2[10])+HESS[19]*(U1[5]*U2[14])
           +HESS[20]*(U1[5]*U2[15])+HESS[31]*(U1[8]*U2[8])+HESS[34]
           *(U1[9]*U2[10])+HESS[38]*(U1[10]*U2[10])+HESS[40]*(U1[11]
           *U2[8])+HESS[41]*(U1[11]*U2[10])+HESS[45]*(U1[11]*U2[12])
           +HESS[47]*(U1[11]*U2[14])+HESS[48]*(U1[11]*U2[15])+HESS[49]
           *(U1[11]*U2[16])+HESS[50]*(U1[11]*U2[17])+HESS[55]*(U1[12]
           *U2[8])+HESS[58]*(U1[12]*U2[10])+HESS[61]*(U1[12]*U2[12])
           +HESS[67]*(U1[12]*U2[14])+HESS[68]*(U1[12]*U2[15])+HESS[71]
           *(U1[13]*U2[8])+HESS[72]*(U1[13]*U2[10])+HESS[73]*(U1[13]
           *U2[12])+HESS[74]*(U1[13]*U2[14])+HESS[75]*(U1[13]*U2[15])
           +HESS[76]*(U1[13]*U2[16])+HESS[77]*(U1[13]*U2[17])+HESS[80]
           *(U1[14]*U2[14])+HESS[87]*(U1[15]*U2[15])+HESS[93]*(U1[16]
           *U2[16])+HESS[97]*(U1[17]*U2[17])+HESS[108]*(U1[18]*U2[12]);
  HTU[14] = HESS[5]*(U1[3]*U2[13])+HESS[6]*(U1[3]*U2[15])+HESS[12]
           *(U1[4]*U2[13])+HESS[19]*(U1[5]*U2[13])+HESS[21]*(U1[5]
           *U2[15])+HESS[24]*(U1[6]*U2[12])+HESS[47]*(U1[11]*U2[13])
           +HESS[62]*(U1[12]*U2[12])+HESS[67]*(U1[12]*U2[13])+HESS[69]
           *(U1[12]*U2[15])+HESS[74]*(U1[13]*U2[13])+HESS[79]*(U1[14]
           *U2[12])+HESS[80]*(U1[14]*U2[13])+HESS[81]*(U1[14]*U2[15])
           +HESS[88]*(U1[15]*U2[15]);
  HTU[15] = HESS[6]*(U1[3]*U2[14])+HESS[18]*(U1[5]*U2[10])+HESS[20]
           *(U1[5]*U2[13])+HESS[21]*(U1[5]*U2[14])+HESS[35]*(U1[9]
           *U2[10])+HESS[39]*(U1[10]*U2[10])+HESS[48]*(U1[11]*U2[13])
           +HESS[59]*(U1[12]*U2[10])+HESS[63]*(U1[12]*U2[12])+HESS[68]
           *(U1[12]*U2[13])+HESS[69]*(U1[12]*U2[14])+HESS[75]*(U1[13]
           *U2[13])+HESS[81]*(U1[14]*U2[14])+HESS[85]*(U1[15]*U2[10])
           +HESS[86]*(U1[15]*U2[12])+HESS[87]*(U1[15]*U2[13])+HESS[88]
           *(U1[15]*U2[14]);
  HTU[16] = HESS[3]*(U1[2]*U2[11])+HESS[25]*(U1[7]*U2[7])+HESS[42]
           *(U1[11]*U2[11])+HESS[46]*(U1[11]*U2[12])+HESS[49]*(U1[11]
           *U2[13])+HESS[64]*(U1[12]*U2[12])+HESS[76]*(U1[13]*U2[13])
           +HESS[89]*(U1[16]*U2[7])+HESS[90]*(U1[16]*U2[11])+HESS[92]
           *(U1[16]*U2[12])+HESS[93]*(U1[16]*U2[13])+HESS[109]*(U1[18]
           *U2[12]);
  HTU[17] = HESS[1]*(U1[1]*U2[7])+HESS[9]*(U1[4]*U2[7])+HESS[14]*(U1[5]
           *U2[7])+HESS[26]*(U1[7]*U2[7])+HESS[32]*(U1[9]*U2[7])
           +HESS[43]*(U1[11]*U2[11])+HESS[50]*(U1[11]*U2[13])+HESS[53]
           *(U1[12]*U2[7])+HESS[65]*(U1[12]*U2[12])+HESS[70]*(U1[12]
           *U2[18])+HESS[77]*(U1[13]*U2[13])+HESS[83]*(U1[15]*U2[7])
           +HESS[91]*(U1[16]*U2[11])+HESS[94]*(U1[17]*U2[7])+HESS[95]
           *(U1[17]*U2[11])+HESS[96]*(U1[17]*U2[12])+HESS[97]*(U1[17]
           *U2[13])+HESS[98]*(U1[17]*U2[18])+HESS[104]*(U1[18]*U2[7])
           +HESS[110]*(U1[18]*U2[12])+HESS[112]*(U1[18]*U2[18]);
  HTU[18] = HESS[0]*(U1[0]*U2[0])+HESS[4]*(U1[3]*U2[3])+HESS[7]*(U1[4]
           *U2[4])+HESS[8]*(U1[4]*U2[5])+HESS[13]*(U1[5]*U2[5])
           +HESS[16]*(U1[5]*U2[9])+HESS[22]*(U1[6]*U2[6])+HESS[27]
           *(U1[7]*U2[7])+HESS[28]*(U1[8]*U2[3])+HESS[29]*(U1[8]*U2[6])
           +HESS[33]*(U1[9]*U2[9])+HESS[36]*(U1[10]*U2[7])+HESS[44]
           *(U1[11]*U2[11])+HESS[51]*(U1[12]*U2[4])+HESS[52]*(U1[12]
           *U2[5])+HESS[56]*(U1[12]*U2[9])+HESS[66]*(U1[12]*U2[12])
           +HESS[70]*(U1[12]*U2[17])+HESS[78]*(U1[14]*U2[7])+HESS[82]
           *(U1[15]*U2[0])+HESS[84]*(U1[15]*U2[9])+HESS[98]*(U1[17]
           *U2[17])+HESS[99]*(U1[18]*U2[0])+HESS[100]*(U1[18]*U2[3])
           +HESS[101]*(U1[18]*U2[4])+HESS[102]*(U1[18]*U2[5])+HESS[103]
           *(U1[18]*U2[6])+HESS[105]*(U1[18]*U2[7])+HESS[106]*(U1[18]
           *U2[9])+HESS[107]*(U1[18]*U2[11])+HESS[111]*(U1[18]*U2[12])
           +HESS[112]*(U1[18]*U2[17]);
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
  HU[0] = HESS[0]*(U1[0]*U2[18])+HESS[0]*(U1[18]*U2[0]);
  HU[1] = HESS[1]*(U1[7]*U2[17])+HESS[1]*(U1[17]*U2[7])+HESS[2]*(U1[12]
         *U2[12]);
  HU[2] = HESS[3]*(U1[11]*U2[16])+HESS[3]*(U1[16]*U2[11]);
  HU[3] = HESS[4]*(U1[3]*U2[18])+HESS[4]*(U1[18]*U2[3])+HESS[5]*(U1[13]
         *U2[14])+HESS[5]*(U1[14]*U2[13])+HESS[6]*(U1[14]*U2[15])
         +HESS[6]*(U1[15]*U2[14]);
  HU[4] = HESS[7]*(U1[4]*U2[18])+HESS[7]*(U1[18]*U2[4])+HESS[8]*(U1[5]
         *U2[18])+HESS[8]*(U1[18]*U2[5])+HESS[9]*(U1[7]*U2[17])+HESS[9]
         *(U1[17]*U2[7])+HESS[10]*(U1[8]*U2[13])+HESS[10]*(U1[13]
         *U2[8])+HESS[11]*(U1[10]*U2[13])+HESS[11]*(U1[13]*U2[10])
         +HESS[12]*(U1[13]*U2[14])+HESS[12]*(U1[14]*U2[13]);
  HU[5] = HESS[13]*(U1[5]*U2[18])+HESS[13]*(U1[18]*U2[5])+HESS[14]
         *(U1[7]*U2[17])+HESS[14]*(U1[17]*U2[7])+HESS[15]*(U1[8]
         *U2[13])+HESS[15]*(U1[13]*U2[8])+HESS[16]*(U1[9]*U2[18])
         +HESS[16]*(U1[18]*U2[9])+HESS[17]*(U1[10]*U2[13])+HESS[17]
         *(U1[13]*U2[10])+HESS[18]*(U1[10]*U2[15])+HESS[18]*(U1[15]
         *U2[10])+HESS[19]*(U1[13]*U2[14])+HESS[19]*(U1[14]*U2[13])
         +HESS[20]*(U1[13]*U2[15])+HESS[20]*(U1[15]*U2[13])+HESS[21]
         *(U1[14]*U2[15])+HESS[21]*(U1[15]*U2[14]);
  HU[6] = HESS[22]*(U1[6]*U2[18])+HESS[22]*(U1[18]*U2[6])+HESS[23]
         *(U1[10]*U2[12])+HESS[23]*(U1[12]*U2[10])+HESS[24]*(U1[12]
         *U2[14])+HESS[24]*(U1[14]*U2[12]);
  HU[7] = HESS[25]*(U1[7]*U2[16])+HESS[25]*(U1[16]*U2[7])+HESS[26]
         *(U1[7]*U2[17])+HESS[26]*(U1[17]*U2[7])+HESS[27]*(U1[7]
         *U2[18])+HESS[27]*(U1[18]*U2[7]);
  HU[8] = HESS[28]*(U1[3]*U2[18])+HESS[28]*(U1[18]*U2[3])+HESS[29]
         *(U1[6]*U2[18])+HESS[29]*(U1[18]*U2[6])+HESS[30]*(U1[8]
         *U2[12])+HESS[30]*(U1[12]*U2[8])+HESS[31]*(U1[8]*U2[13])
         +HESS[31]*(U1[13]*U2[8]);
  HU[9] = HESS[32]*(U1[7]*U2[17])+HESS[32]*(U1[17]*U2[7])+HESS[33]
         *(U1[9]*U2[18])+HESS[33]*(U1[18]*U2[9])+HESS[34]*(U1[10]
         *U2[13])+HESS[34]*(U1[13]*U2[10])+HESS[35]*(U1[10]*U2[15])
         +HESS[35]*(U1[15]*U2[10]);
  HU[10] = HESS[36]*(U1[7]*U2[18])+HESS[36]*(U1[18]*U2[7])+HESS[37]
          *(U1[10]*U2[12])+HESS[37]*(U1[12]*U2[10])+HESS[38]*(U1[10]
          *U2[13])+HESS[38]*(U1[13]*U2[10])+HESS[39]*(U1[10]*U2[15])
          +HESS[39]*(U1[15]*U2[10]);
  HU[11] = HESS[40]*(U1[8]*U2[13])+HESS[40]*(U1[13]*U2[8])+HESS[41]
          *(U1[10]*U2[13])+HESS[41]*(U1[13]*U2[10])+HESS[42]*(U1[11]
          *U2[16])+HESS[42]*(U1[16]*U2[11])+HESS[43]*(U1[11]*U2[17])
          +HESS[43]*(U1[17]*U2[11])+HESS[44]*(U1[11]*U2[18])+HESS[44]
          *(U1[18]*U2[11])+HESS[45]*(U1[12]*U2[13])+HESS[45]*(U1[13]
          *U2[12])+HESS[46]*(U1[12]*U2[16])+HESS[46]*(U1[16]*U2[12])
          +HESS[47]*(U1[13]*U2[14])+HESS[47]*(U1[14]*U2[13])+HESS[48]
          *(U1[13]*U2[15])+HESS[48]*(U1[15]*U2[13])+HESS[49]*(U1[13]
          *U2[16])+HESS[49]*(U1[16]*U2[13])+HESS[50]*(U1[13]*U2[17])
          +HESS[50]*(U1[17]*U2[13]);
  HU[12] = HESS[51]*(U1[4]*U2[18])+HESS[51]*(U1[18]*U2[4])+HESS[52]
          *(U1[5]*U2[18])+HESS[52]*(U1[18]*U2[5])+HESS[53]*(U1[7]
          *U2[17])+HESS[53]*(U1[17]*U2[7])+HESS[54]*(U1[8]*U2[12])
          +HESS[54]*(U1[12]*U2[8])+HESS[55]*(U1[8]*U2[13])+HESS[55]
          *(U1[13]*U2[8])+HESS[56]*(U1[9]*U2[18])+HESS[56]*(U1[18]
          *U2[9])+HESS[57]*(U1[10]*U2[12])+HESS[57]*(U1[12]*U2[10])
          +HESS[58]*(U1[10]*U2[13])+HESS[58]*(U1[13]*U2[10])+HESS[59]
          *(U1[10]*U2[15])+HESS[59]*(U1[15]*U2[10])+HESS[60]*(U1[12]
          *U2[12])+HESS[61]*(U1[12]*U2[13])+HESS[61]*(U1[13]*U2[12])
          +HESS[62]*(U1[12]*U2[14])+HESS[62]*(U1[14]*U2[12])+HESS[63]
          *(U1[12]*U2[15])+HESS[63]*(U1[15]*U2[12])+HESS[64]*(U1[12]
          *U2[16])+HESS[64]*(U1[16]*U2[12])+HESS[65]*(U1[12]*U2[17])
          +HESS[65]*(U1[17]*U2[12])+HESS[66]*(U1[12]*U2[18])+HESS[66]
          *(U1[18]*U2[12])+HESS[67]*(U1[13]*U2[14])+HESS[67]*(U1[14]
          *U2[13])+HESS[68]*(U1[13]*U2[15])+HESS[68]*(U1[15]*U2[13])
          +HESS[69]*(U1[14]*U2[15])+HESS[69]*(U1[15]*U2[14])+HESS[70]
          *(U1[17]*U2[18])+HESS[70]*(U1[18]*U2[17]);
  HU[13] = HESS[71]*(U1[8]*U2[13])+HESS[71]*(U1[13]*U2[8])+HESS[72]
          *(U1[10]*U2[13])+HESS[72]*(U1[13]*U2[10])+HESS[73]*(U1[12]
          *U2[13])+HESS[73]*(U1[13]*U2[12])+HESS[74]*(U1[13]*U2[14])
          +HESS[74]*(U1[14]*U2[13])+HESS[75]*(U1[13]*U2[15])+HESS[75]
          *(U1[15]*U2[13])+HESS[76]*(U1[13]*U2[16])+HESS[76]*(U1[16]
          *U2[13])+HESS[77]*(U1[13]*U2[17])+HESS[77]*(U1[17]*U2[13]);
  HU[14] = HESS[78]*(U1[7]*U2[18])+HESS[78]*(U1[18]*U2[7])+HESS[79]
          *(U1[12]*U2[14])+HESS[79]*(U1[14]*U2[12])+HESS[80]*(U1[13]
          *U2[14])+HESS[80]*(U1[14]*U2[13])+HESS[81]*(U1[14]*U2[15])
          +HESS[81]*(U1[15]*U2[14]);
  HU[15] = HESS[82]*(U1[0]*U2[18])+HESS[82]*(U1[18]*U2[0])+HESS[83]
          *(U1[7]*U2[17])+HESS[83]*(U1[17]*U2[7])+HESS[84]*(U1[9]
          *U2[18])+HESS[84]*(U1[18]*U2[9])+HESS[85]*(U1[10]*U2[15])
          +HESS[85]*(U1[15]*U2[10])+HESS[86]*(U1[12]*U2[15])+HESS[86]
          *(U1[15]*U2[12])+HESS[87]*(U1[13]*U2[15])+HESS[87]*(U1[15]
          *U2[13])+HESS[88]*(U1[14]*U2[15])+HESS[88]*(U1[15]*U2[14]);
  HU[16] = HESS[89]*(U1[7]*U2[16])+HESS[89]*(U1[16]*U2[7])+HESS[90]
          *(U1[11]*U2[16])+HESS[90]*(U1[16]*U2[11])+HESS[91]*(U1[11]
          *U2[17])+HESS[91]*(U1[17]*U2[11])+HESS[92]*(U1[12]*U2[16])
          +HESS[92]*(U1[16]*U2[12])+HESS[93]*(U1[13]*U2[16])+HESS[93]
          *(U1[16]*U2[13]);
  HU[17] = HESS[94]*(U1[7]*U2[17])+HESS[94]*(U1[17]*U2[7])+HESS[95]
          *(U1[11]*U2[17])+HESS[95]*(U1[17]*U2[11])+HESS[96]*(U1[12]
          *U2[17])+HESS[96]*(U1[17]*U2[12])+HESS[97]*(U1[13]*U2[17])
          +HESS[97]*(U1[17]*U2[13])+HESS[98]*(U1[17]*U2[18])+HESS[98]
          *(U1[18]*U2[17]);
  HU[18] = HESS[99]*(U1[0]*U2[18])+HESS[99]*(U1[18]*U2[0])+HESS[100]
          *(U1[3]*U2[18])+HESS[100]*(U1[18]*U2[3])+HESS[101]*(U1[4]
          *U2[18])+HESS[101]*(U1[18]*U2[4])+HESS[102]*(U1[5]*U2[18])
          +HESS[102]*(U1[18]*U2[5])+HESS[103]*(U1[6]*U2[18])+HESS[103]
          *(U1[18]*U2[6])+HESS[104]*(U1[7]*U2[17])+HESS[104]*(U1[17]
          *U2[7])+HESS[105]*(U1[7]*U2[18])+HESS[105]*(U1[18]*U2[7])
          +HESS[106]*(U1[9]*U2[18])+HESS[106]*(U1[18]*U2[9])+HESS[107]
          *(U1[11]*U2[18])+HESS[107]*(U1[18]*U2[11])+HESS[108]*(U1[12]
          *U2[13])+HESS[108]*(U1[13]*U2[12])+HESS[109]*(U1[12]*U2[16])
          +HESS[109]*(U1[16]*U2[12])+HESS[110]*(U1[12]*U2[17])
          +HESS[110]*(U1[17]*U2[12])+HESS[111]*(U1[12]*U2[18])
          +HESS[111]*(U1[18]*U2[12])+HESS[112]*(U1[17]*U2[18])
          +HESS[112]*(U1[18]*U2[17]);
}

/* End of Hess_Vec function                                         */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


