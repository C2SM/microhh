/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The ODE Jacobian of Chemical Model File                          */
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
/* File                 : tm5_ifs_Jacobian.c                        */
/* Time                 : Fri Apr 16 15:52:25 2021                  */
/* Working directory    : /home/WUR/szena001/kpp/examples           */
/* Equation file        : tm5_ifs.kpp                               */
/* Output root filename : tm5_ifs                                   */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ifs_Parameters.h"
#include "ifs_Global.h"
#include "ifs_Sparse.h"


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Jac_SP - the Jacobian of Variables in sparse matrix representation */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      JVS       - sparse Jacobian of variables                    */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Jac_SP( 
  double V[],                            /* Concentrations of variable species (local) */
  double F[],                            /* Concentrations of fixed species (local) */
  double RCT[],                          /* Rate constants (local) */
  double JVS[]                           /* sparse Jacobian of variables */
)
{

/* Local variables                                                  */
double B[49];                            /* Temporary array */

/* B(0) = dA(0)/dV(8)                                               */
  B[0] = RCT[0]*F[3];
/* B(2) = dA(1)/dV(7)                                               */
  B[2] = RCT[1]*V[8];
/* B(3) = dA(1)/dV(8)                                               */
  B[3] = RCT[1]*V[7];
/* B(4) = dA(2)/dV(7)                                               */
  B[4] = RCT[2]*F[3];
/* B(6) = dA(3)/dV(7)                                               */
  B[6] = RCT[3]*2*V[7];
/* B(7) = dA(4)/dV(1)                                               */
  B[7] = RCT[4]*F[3];
/* B(10) = dA(6)/dV(8)                                              */
  B[10] = RCT[6]*V[10];
/* B(11) = dA(6)/dV(10)                                             */
  B[11] = RCT[6]*V[8];
/* B(12) = dA(7)/dV(7)                                              */
  B[12] = RCT[7]*V[10];
/* B(13) = dA(7)/dV(10)                                             */
  B[13] = RCT[7]*V[7];
/* B(14) = dA(8)/dV(6)                                              */
  B[14] = RCT[8]*F[3];
/* B(18) = dA(10)/dV(9)                                             */
  B[18] = RCT[10]*V[10];
/* B(19) = dA(10)/dV(10)                                            */
  B[19] = RCT[10]*V[9];
/* B(20) = dA(11)/dV(7)                                             */
  B[20] = RCT[11]*V[9];
/* B(21) = dA(11)/dV(9)                                             */
  B[21] = RCT[11]*V[7];
/* B(22) = dA(12)/dV(7)                                             */
  B[22] = RCT[12]*V[9];
/* B(23) = dA(12)/dV(9)                                             */
  B[23] = RCT[12]*V[7];
/* B(24) = dA(13)/dV(5)                                             */
  B[24] = RCT[13]*F[3];
/* B(26) = dA(14)/dV(2)                                             */
  B[26] = RCT[14]*F[3];
/* B(28) = dA(15)/dV(4)                                             */
  B[28] = RCT[15]*F[3];
/* B(30) = dA(16)/dV(3)                                             */
  B[30] = 8e-17*V[8];
/* B(31) = dA(16)/dV(8)                                             */
  B[31] = 8e-17*V[3];
/* B(32) = dA(17)/dV(3)                                             */
  B[32] = RCT[17]*F[3];
/* B(34) = dA(18)/dV(8)                                             */
  B[34] = RCT[18];
/* B(35) = dA(19)/dV(6)                                             */
  B[35] = RCT[19];
/* B(36) = dA(20)/dV(4)                                             */
  B[36] = RCT[20];
/* B(37) = dA(21)/dV(4)                                             */
  B[37] = RCT[21];
/* B(38) = dA(22)/dV(5)                                             */
  B[38] = RCT[22];
/* B(39) = dA(23)/dV(1)                                             */
  B[39] = RCT[23];
/* B(42) = dA(26)/dV(8)                                             */
  B[42] = RCT[26];
/* B(43) = dA(27)/dV(10)                                            */
  B[43] = RCT[27];
/* B(44) = dA(28)/dV(6)                                             */
  B[44] = RCT[28];
/* B(45) = dA(29)/dV(3)                                             */
  B[45] = RCT[29];
/* B(46) = dA(30)/dV(0)                                             */
  B[46] = RCT[30];
/* B(47) = dA(31)/dV(5)                                             */
  B[47] = RCT[31];
/* B(48) = dA(32)/dV(1)                                             */
  B[48] = RCT[32];

/* Construct the Jacobian terms from B's                            */
/* JVS(0) = Jac_FULL(0,0)                                           */
  JVS[0] = -B[46];
/* JVS(1) = Jac_FULL(0,6)                                           */
  JVS[1] = B[14];
/* JVS(2) = Jac_FULL(1,1)                                           */
  JVS[2] = -B[7]-B[39]-B[48];
/* JVS(3) = Jac_FULL(1,7)                                           */
  JVS[3] = B[6];
/* JVS(4) = Jac_FULL(2,2)                                           */
  JVS[4] = -B[26];
/* JVS(5) = Jac_FULL(2,4)                                           */
  JVS[5] = B[28]+B[36]+B[37];
/* JVS(6) = Jac_FULL(3,3)                                           */
  JVS[6] = -B[30]-B[32]-B[45];
/* JVS(7) = Jac_FULL(3,8)                                           */
  JVS[7] = -B[31];
/* JVS(8) = Jac_FULL(4,4)                                           */
  JVS[8] = -B[28]-B[36]-B[37];
/* JVS(9) = Jac_FULL(4,5)                                           */
  JVS[9] = 0.4*B[24]+B[38];
/* JVS(10) = Jac_FULL(4,7)                                          */
  JVS[10] = B[22];
/* JVS(11) = Jac_FULL(4,9)                                          */
  JVS[11] = B[18]+B[23];
/* JVS(12) = Jac_FULL(4,10)                                         */
  JVS[12] = B[19];
/* JVS(13) = Jac_FULL(5,5)                                          */
  JVS[13] = -B[24]-B[38]-B[47];
/* JVS(14) = Jac_FULL(5,7)                                          */
  JVS[14] = B[20];
/* JVS(15) = Jac_FULL(5,9)                                          */
  JVS[15] = B[21];
/* JVS(16) = Jac_FULL(6,6)                                          */
  JVS[16] = -B[14]-B[35]-B[44];
/* JVS(17) = Jac_FULL(6,7)                                          */
  JVS[17] = B[12];
/* JVS(18) = Jac_FULL(6,8)                                          */
  JVS[18] = B[10];
/* JVS(19) = Jac_FULL(6,9)                                          */
  JVS[19] = B[18];
/* JVS(20) = Jac_FULL(6,10)                                         */
  JVS[20] = B[11]+B[13]+B[19];
/* JVS(21) = Jac_FULL(7,1)                                          */
  JVS[21] = B[7];
/* JVS(22) = Jac_FULL(7,2)                                          */
  JVS[22] = B[26];
/* JVS(23) = Jac_FULL(7,4)                                          */
  JVS[23] = B[28]+2*B[36];
/* JVS(24) = Jac_FULL(7,5)                                          */
  JVS[24] = B[38];
/* JVS(25) = Jac_FULL(7,7)                                          */
  JVS[25] = -B[2]-B[4]-2*B[6]-B[12]-B[20]-B[22];
/* JVS(26) = Jac_FULL(7,8)                                          */
  JVS[26] = B[0]-B[3];
/* JVS(27) = Jac_FULL(7,9)                                          */
  JVS[27] = B[18]-B[21]-B[23];
/* JVS(28) = Jac_FULL(7,10)                                         */
  JVS[28] = -B[13]+B[19];
/* JVS(29) = Jac_FULL(8,3)                                          */
  JVS[29] = -B[30];
/* JVS(30) = Jac_FULL(8,6)                                          */
  JVS[30] = B[35];
/* JVS(31) = Jac_FULL(8,7)                                          */
  JVS[31] = -B[2];
/* JVS(32) = Jac_FULL(8,8)                                          */
  JVS[32] = -B[0]-B[3]-B[10]-B[31]-B[34]-B[42];
/* JVS(33) = Jac_FULL(8,9)                                          */
  JVS[33] = 0;
/* JVS(34) = Jac_FULL(8,10)                                         */
  JVS[34] = -B[11];
/* JVS(35) = Jac_FULL(9,3)                                          */
  JVS[35] = 0.75*B[30]+B[32];
/* JVS(36) = Jac_FULL(9,5)                                          */
  JVS[36] = 0.6*B[24];
/* JVS(37) = Jac_FULL(9,7)                                          */
  JVS[37] = -B[20]-B[22];
/* JVS(38) = Jac_FULL(9,8)                                          */
  JVS[38] = 0.75*B[31];
/* JVS(39) = Jac_FULL(9,9)                                          */
  JVS[39] = -B[18]-B[21]-B[23];
/* JVS(40) = Jac_FULL(9,10)                                         */
  JVS[40] = -B[19];
/* JVS(41) = Jac_FULL(10,6)                                         */
  JVS[41] = B[35];
/* JVS(42) = Jac_FULL(10,7)                                         */
  JVS[42] = -B[12];
/* JVS(43) = Jac_FULL(10,8)                                         */
  JVS[43] = -B[10];
/* JVS(44) = Jac_FULL(10,9)                                         */
  JVS[44] = -B[18];
/* JVS(45) = Jac_FULL(10,10)                                        */
  JVS[45] = -B[11]-B[13]-B[19]-B[43];
}

/* End of Jac_SP function                                           */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* Jac_SP_Vec - function for sparse multiplication: sparse Jacobian times vector */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      UV        - User vector for variables                       */
/*      JUV       - Jacobian times user vector                      */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Jac_SP_Vec( 
  double JVS[],                          /* sparse Jacobian of variables */
  double UV[],                           /* User vector for variables */
  double JUV[]                           /* Jacobian times user vector */
)
{
  JUV[0] = JVS[0]*UV[0]+JVS[1]*UV[6];
  JUV[1] = JVS[2]*UV[1]+JVS[3]*UV[7];
  JUV[2] = JVS[4]*UV[2]+JVS[5]*UV[4];
  JUV[3] = JVS[6]*UV[3]+JVS[7]*UV[8];
  JUV[4] = JVS[8]*UV[4]+JVS[9]*UV[5]+JVS[10]*UV[7]+JVS[11]*UV[9]
          +JVS[12]*UV[10];
  JUV[5] = JVS[13]*UV[5]+JVS[14]*UV[7]+JVS[15]*UV[9];
  JUV[6] = JVS[16]*UV[6]+JVS[17]*UV[7]+JVS[18]*UV[8]+JVS[19]*UV[9]
          +JVS[20]*UV[10];
  JUV[7] = JVS[21]*UV[1]+JVS[22]*UV[2]+JVS[23]*UV[4]+JVS[24]*UV[5]
          +JVS[25]*UV[7]+JVS[26]*UV[8]+JVS[27]*UV[9]+JVS[28]*UV[10];
  JUV[8] = JVS[29]*UV[3]+JVS[30]*UV[6]+JVS[31]*UV[7]+JVS[32]*UV[8]
          +JVS[34]*UV[10];
  JUV[9] = JVS[35]*UV[3]+JVS[36]*UV[5]+JVS[37]*UV[7]+JVS[38]*UV[8]
          +JVS[39]*UV[9]+JVS[40]*UV[10];
  JUV[10] = JVS[41]*UV[6]+JVS[42]*UV[7]+JVS[43]*UV[8]+JVS[44]*UV[9]
           +JVS[45]*UV[10];
}

/* End of Jac_SP_Vec function                                       */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* JacTR_SP_Vec - sparse multiplication: sparse Jacobian transposed times vector */
/*   Arguments :                                                    */
/*      JVS       - sparse Jacobian of variables                    */
/*      UV        - User vector for variables                       */
/*      JTUV      - Jacobian transposed times user vector           */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void JacTR_SP_Vec( 
  double JVS[],                          /* sparse Jacobian of variables */
  double UV[],                           /* User vector for variables */
  double JTUV[]                          /* Jacobian transposed times user vector */
)
{
  JTUV[0] = JVS[0]*UV[0];
  JTUV[1] = JVS[2]*UV[1]+JVS[21]*UV[7];
  JTUV[2] = JVS[4]*UV[2]+JVS[22]*UV[7];
  JTUV[3] = JVS[6]*UV[3]+JVS[29]*UV[8]+JVS[35]*UV[9];
  JTUV[4] = JVS[5]*UV[2]+JVS[8]*UV[4]+JVS[23]*UV[7];
  JTUV[5] = JVS[9]*UV[4]+JVS[13]*UV[5]+JVS[24]*UV[7]+JVS[36]*UV[9];
  JTUV[6] = JVS[1]*UV[0]+JVS[16]*UV[6]+JVS[30]*UV[8]+JVS[41]*UV[10];
  JTUV[7] = JVS[3]*UV[1]+JVS[10]*UV[4]+JVS[14]*UV[5]+JVS[17]*UV[6]
           +JVS[25]*UV[7]+JVS[31]*UV[8]+JVS[37]*UV[9]+JVS[42]*UV[10];
  JTUV[8] = JVS[7]*UV[3]+JVS[18]*UV[6]+JVS[26]*UV[7]+JVS[32]*UV[8]
           +JVS[38]*UV[9]+JVS[43]*UV[10];
  JTUV[9] = JVS[11]*UV[4]+JVS[15]*UV[5]+JVS[19]*UV[6]+JVS[27]*UV[7]
           +JVS[39]*UV[9]+JVS[44]*UV[10];
  JTUV[10] = JVS[12]*UV[4]+JVS[20]*UV[6]+JVS[28]*UV[7]+JVS[34]*UV[8]
            +JVS[40]*UV[9]+JVS[45]*UV[10];
}

/* End of JacTR_SP_Vec function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


