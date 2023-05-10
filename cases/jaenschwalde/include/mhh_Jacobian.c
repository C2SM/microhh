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
/* File                 : mhh_Jacobian.c                            */
/* Time                 : Tue Oct 18 15:45:13 2022                  */
/* Working directory    : /home/WUR/krol005/kpp/examples            */
/* Equation file        : mhh.kpp                                   */
/* Output root filename : mhh                                       */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "mhh_Parameters.h"
#include "mhh_Global.h"
#include "mhh_Sparse.h"


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
double B[70];                            /* Temporary array */

/* B(0) = dA(0)/dV(8)                                               */
  B[0] = RCT[0]*V[9];
/* B(1) = dA(0)/dV(9)                                               */
  B[1] = RCT[0]*V[8];
/* B(2) = dA(1)/dV(8)                                               */
  B[2] = RCT[1]*V[10];
/* B(3) = dA(1)/dV(10)                                              */
  B[3] = RCT[1]*V[8];
/* B(4) = dA(2)/dV(9)                                               */
  B[4] = RCT[2]*V[10];
/* B(5) = dA(2)/dV(10)                                              */
  B[5] = RCT[2]*V[9];
/* B(6) = dA(3)/dV(10)                                              */
  B[6] = RCT[3]*2*V[10];
/* B(7) = dA(4)/dV(0)                                               */
  B[7] = RCT[4]*V[9];
/* B(8) = dA(4)/dV(9)                                               */
  B[8] = RCT[4]*V[0];
/* B(9) = dA(5)/dV(9)                                               */
  B[9] = RCT[5];
/* B(10) = dA(6)/dV(8)                                              */
  B[10] = RCT[6]*V[13];
/* B(11) = dA(6)/dV(13)                                             */
  B[11] = RCT[6]*V[8];
/* B(12) = dA(7)/dV(7)                                              */
  B[12] = RCT[7]*V[8];
/* B(13) = dA(7)/dV(8)                                              */
  B[13] = RCT[7]*V[7];
/* B(14) = dA(8)/dV(11)                                             */
  B[14] = RCT[8]*V[13];
/* B(15) = dA(8)/dV(13)                                             */
  B[15] = RCT[8]*V[11];
/* B(16) = dA(9)/dV(7)                                              */
  B[16] = RCT[9]*V[11];
/* B(17) = dA(9)/dV(11)                                             */
  B[17] = RCT[9]*V[7];
/* B(18) = dA(10)/dV(1)                                             */
  B[18] = RCT[10];
/* B(19) = dA(11)/dV(10)                                            */
  B[19] = RCT[11]*V[13];
/* B(20) = dA(11)/dV(13)                                            */
  B[20] = RCT[11]*V[10];
/* B(21) = dA(12)/dV(7)                                             */
  B[21] = RCT[12]*V[9];
/* B(22) = dA(12)/dV(9)                                             */
  B[22] = RCT[12]*V[7];
/* B(23) = dA(13)/dV(10)                                            */
  B[23] = 4e-12*V[11];
/* B(24) = dA(13)/dV(11)                                            */
  B[24] = 4e-12*V[10];
/* B(25) = dA(14)/dV(3)                                             */
  B[25] = RCT[14]*V[9];
/* B(26) = dA(14)/dV(9)                                             */
  B[26] = RCT[14]*V[3];
/* B(27) = dA(15)/dV(1)                                             */
  B[27] = 0.0004;
/* B(28) = dA(16)/dV(9)                                             */
  B[28] = RCT[16]*F[0];
/* B(30) = dA(17)/dV(10)                                            */
  B[30] = RCT[17]*V[12];
/* B(31) = dA(17)/dV(12)                                            */
  B[31] = RCT[17]*V[10];
/* B(32) = dA(18)/dV(10)                                            */
  B[32] = RCT[18]*V[12];
/* B(33) = dA(18)/dV(12)                                            */
  B[33] = RCT[18]*V[10];
/* B(34) = dA(19)/dV(12)                                            */
  B[34] = RCT[19]*V[13];
/* B(35) = dA(19)/dV(13)                                            */
  B[35] = RCT[19]*V[12];
/* B(36) = dA(20)/dV(11)                                            */
  B[36] = 1.2e-12*V[12];
/* B(37) = dA(20)/dV(12)                                            */
  B[37] = 1.2e-12*V[11];
/* B(38) = dA(21)/dV(4)                                             */
  B[38] = RCT[21]*V[9];
/* B(39) = dA(21)/dV(9)                                             */
  B[39] = RCT[21]*V[4];
/* B(40) = dA(22)/dV(6)                                             */
  B[40] = RCT[22]*V[9];
/* B(41) = dA(22)/dV(9)                                             */
  B[41] = RCT[22]*V[6];
/* B(42) = dA(23)/dV(6)                                             */
  B[42] = 5.8e-16*V[11];
/* B(43) = dA(23)/dV(11)                                            */
  B[43] = 5.8e-16*V[6];
/* B(44) = dA(24)/dV(2)                                             */
  B[44] = RCT[24]*V[9];
/* B(45) = dA(24)/dV(9)                                             */
  B[45] = RCT[24]*V[2];
/* B(46) = dA(25)/dV(12)                                            */
  B[46] = RCT[25]*2*V[12];
/* B(47) = dA(26)/dV(5)                                             */
  B[47] = RCT[26]*V[8];
/* B(48) = dA(26)/dV(8)                                             */
  B[48] = RCT[26]*V[5];
/* B(49) = dA(27)/dV(5)                                             */
  B[49] = RCT[27]*V[9];
/* B(50) = dA(27)/dV(9)                                             */
  B[50] = RCT[27]*V[5];
/* B(51) = dA(28)/dV(5)                                             */
  B[51] = RCT[28]*V[11];
/* B(52) = dA(28)/dV(11)                                            */
  B[52] = RCT[28]*V[5];
/* B(53) = dA(29)/dV(8)                                             */
  B[53] = RCT[29];
/* B(54) = dA(30)/dV(7)                                             */
  B[54] = RCT[30];
/* B(55) = dA(31)/dV(1)                                             */
  B[55] = RCT[31];
/* B(56) = dA(32)/dV(11)                                            */
  B[56] = RCT[32];
/* B(57) = dA(33)/dV(4)                                             */
  B[57] = RCT[33];
/* B(58) = dA(34)/dV(6)                                             */
  B[58] = RCT[34];
/* B(59) = dA(35)/dV(6)                                             */
  B[59] = RCT[35];
/* B(60) = dA(36)/dV(0)                                             */
  B[60] = RCT[36];
/* B(63) = dA(39)/dV(8)                                             */
  B[63] = RCT[39];
/* B(64) = dA(40)/dV(13)                                            */
  B[64] = RCT[40];
/* B(65) = dA(41)/dV(7)                                             */
  B[65] = RCT[41];
/* B(66) = dA(42)/dV(3)                                             */
  B[66] = RCT[42];
/* B(67) = dA(43)/dV(0)                                             */
  B[67] = RCT[43];
/* B(68) = dA(44)/dV(6)                                             */
  B[68] = RCT[44];
/* B(69) = dA(45)/dV(4)                                             */
  B[69] = RCT[45];

/* Construct the Jacobian terms from B's                            */
/* JVS(0) = Jac_FULL(0,0)                                           */
  JVS[0] = -B[7]-B[60]-B[67];
/* JVS(1) = Jac_FULL(0,9)                                           */
  JVS[1] = -B[8];
/* JVS(2) = Jac_FULL(0,10)                                          */
  JVS[2] = B[6];
/* JVS(3) = Jac_FULL(1,1)                                           */
  JVS[3] = -B[18]-B[27]-B[55];
/* JVS(4) = Jac_FULL(1,7)                                           */
  JVS[4] = B[16];
/* JVS(5) = Jac_FULL(1,11)                                          */
  JVS[5] = B[17];
/* JVS(6) = Jac_FULL(2,2)                                           */
  JVS[6] = -B[44];
/* JVS(7) = Jac_FULL(2,5)                                           */
  JVS[7] = 0.56*B[47];
/* JVS(8) = Jac_FULL(2,6)                                           */
  JVS[8] = B[40]+B[58]+B[59];
/* JVS(9) = Jac_FULL(2,8)                                           */
  JVS[9] = 0.56*B[48];
/* JVS(10) = Jac_FULL(2,9)                                          */
  JVS[10] = B[41]-B[45];
/* JVS(11) = Jac_FULL(3,1)                                          */
  JVS[11] = 2*B[27];
/* JVS(12) = Jac_FULL(3,3)                                          */
  JVS[12] = -B[25]-B[66];
/* JVS(13) = Jac_FULL(3,6)                                          */
  JVS[13] = B[42];
/* JVS(14) = Jac_FULL(3,7)                                          */
  JVS[14] = B[21];
/* JVS(15) = Jac_FULL(3,9)                                          */
  JVS[15] = B[22]-B[26];
/* JVS(16) = Jac_FULL(3,10)                                         */
  JVS[16] = B[23];
/* JVS(17) = Jac_FULL(3,11)                                         */
  JVS[17] = B[24]+B[43];
/* JVS(18) = Jac_FULL(4,4)                                          */
  JVS[18] = -B[38]-B[57]-B[69];
/* JVS(19) = Jac_FULL(4,9)                                          */
  JVS[19] = -B[39];
/* JVS(20) = Jac_FULL(4,10)                                         */
  JVS[20] = B[30];
/* JVS(21) = Jac_FULL(4,12)                                         */
  JVS[21] = B[31];
/* JVS(22) = Jac_FULL(5,5)                                          */
  JVS[22] = -B[47]-B[49]-B[51];
/* JVS(23) = Jac_FULL(5,8)                                          */
  JVS[23] = -B[48];
/* JVS(24) = Jac_FULL(5,9)                                          */
  JVS[24] = -B[50];
/* JVS(25) = Jac_FULL(5,11)                                         */
  JVS[25] = -B[52];
/* JVS(26) = Jac_FULL(6,4)                                          */
  JVS[26] = 0.4*B[38]+B[57];
/* JVS(27) = Jac_FULL(6,5)                                          */
  JVS[27] = 1.04*B[47]+1.5*B[49];
/* JVS(28) = Jac_FULL(6,6)                                          */
  JVS[28] = -B[40]-B[42]-B[58]-B[59]-B[68];
/* JVS(29) = Jac_FULL(6,8)                                          */
  JVS[29] = 1.04*B[48];
/* JVS(30) = Jac_FULL(6,9)                                          */
  JVS[30] = 0.4*B[39]-B[41]+1.5*B[50];
/* JVS(31) = Jac_FULL(6,10)                                         */
  JVS[31] = B[32];
/* JVS(32) = Jac_FULL(6,11)                                         */
  JVS[32] = B[36]-B[43];
/* JVS(33) = Jac_FULL(6,12)                                         */
  JVS[33] = B[33]+B[34]+B[37]+1.37*B[46];
/* JVS(34) = Jac_FULL(6,13)                                         */
  JVS[34] = B[35];
/* JVS(35) = Jac_FULL(7,1)                                          */
  JVS[35] = B[18]+B[55];
/* JVS(36) = Jac_FULL(7,7)                                          */
  JVS[36] = -B[12]-B[16]-B[21]-B[54]-B[65];
/* JVS(37) = Jac_FULL(7,8)                                          */
  JVS[37] = B[10]-B[13];
/* JVS(38) = Jac_FULL(7,9)                                          */
  JVS[38] = -B[22];
/* JVS(39) = Jac_FULL(7,10)                                         */
  JVS[39] = B[19];
/* JVS(40) = Jac_FULL(7,11)                                         */
  JVS[40] = 2*B[14]-B[17]+B[36]+B[56];
/* JVS(41) = Jac_FULL(7,12)                                         */
  JVS[41] = B[34]+B[37];
/* JVS(42) = Jac_FULL(7,13)                                         */
  JVS[42] = B[11]+2*B[15]+B[20]+B[35];
/* JVS(43) = Jac_FULL(8,5)                                          */
  JVS[43] = -B[47];
/* JVS(44) = Jac_FULL(8,7)                                          */
  JVS[44] = -B[12]+B[54];
/* JVS(45) = Jac_FULL(8,8)                                          */
  JVS[45] = -B[0]-B[2]-B[10]-B[13]-B[48]-B[53]-B[63];
/* JVS(46) = Jac_FULL(8,9)                                          */
  JVS[46] = -B[1];
/* JVS(47) = Jac_FULL(8,10)                                         */
  JVS[47] = -B[3];
/* JVS(48) = Jac_FULL(8,11)                                         */
  JVS[48] = B[56];
/* JVS(49) = Jac_FULL(8,12)                                         */
  JVS[49] = 0;
/* JVS(50) = Jac_FULL(8,13)                                         */
  JVS[50] = -B[11];
/* JVS(51) = Jac_FULL(9,0)                                          */
  JVS[51] = -B[7]+2*B[60];
/* JVS(52) = Jac_FULL(9,2)                                          */
  JVS[52] = -B[44];
/* JVS(53) = Jac_FULL(9,3)                                          */
  JVS[53] = -B[25];
/* JVS(54) = Jac_FULL(9,4)                                          */
  JVS[54] = -0.6*B[38]+B[57];
/* JVS(55) = Jac_FULL(9,5)                                          */
  JVS[55] = 0.33*B[47]-B[49];
/* JVS(56) = Jac_FULL(9,6)                                          */
  JVS[56] = -B[40];
/* JVS(57) = Jac_FULL(9,7)                                          */
  JVS[57] = -B[21];
/* JVS(58) = Jac_FULL(9,8)                                          */
  JVS[58] = -B[0]+B[2]+0.33*B[48]+2*B[53];
/* JVS(59) = Jac_FULL(9,9)                                          */
  JVS[59] = -B[1]-B[4]-B[8]-B[9]-B[22]-B[26]-B[28]-0.6*B[39]-B[41]
           -B[45]-B[50];
/* JVS(60) = Jac_FULL(9,10)                                         */
  JVS[60] = B[3]-B[5]+B[19];
/* JVS(61) = Jac_FULL(9,11)                                         */
  JVS[61] = 0;
/* JVS(62) = Jac_FULL(9,12)                                         */
  JVS[62] = 0;
/* JVS(63) = Jac_FULL(9,13)                                         */
  JVS[63] = B[20];
/* JVS(64) = Jac_FULL(10,0)                                         */
  JVS[64] = B[7];
/* JVS(65) = Jac_FULL(10,2)                                         */
  JVS[65] = B[44];
/* JVS(66) = Jac_FULL(10,4)                                         */
  JVS[66] = B[57];
/* JVS(67) = Jac_FULL(10,5)                                         */
  JVS[67] = 0.19*B[47];
/* JVS(68) = Jac_FULL(10,6)                                         */
  JVS[68] = B[40]+2*B[59];
/* JVS(69) = Jac_FULL(10,8)                                         */
  JVS[69] = B[0]-B[2]+0.19*B[48];
/* JVS(70) = Jac_FULL(10,9)                                         */
  JVS[70] = B[1]-B[4]+B[8]+B[9]+B[41]+B[45];
/* JVS(71) = Jac_FULL(10,10)                                        */
  JVS[71] = -B[3]-B[5]-2*B[6]-B[19]-B[23]-B[30]-B[32];
/* JVS(72) = Jac_FULL(10,11)                                        */
  JVS[72] = -B[24]+B[36];
/* JVS(73) = Jac_FULL(10,12)                                        */
  JVS[73] = -B[31]-B[33]+B[34]+B[37]+0.74*B[46];
/* JVS(74) = Jac_FULL(10,13)                                        */
  JVS[74] = -B[20]+B[35];
/* JVS(75) = Jac_FULL(11,1)                                         */
  JVS[75] = B[18]+B[55];
/* JVS(76) = Jac_FULL(11,3)                                         */
  JVS[76] = B[25];
/* JVS(77) = Jac_FULL(11,5)                                         */
  JVS[77] = -B[51];
/* JVS(78) = Jac_FULL(11,6)                                         */
  JVS[78] = -B[42];
/* JVS(79) = Jac_FULL(11,7)                                         */
  JVS[79] = B[12]-B[16];
/* JVS(80) = Jac_FULL(11,8)                                         */
  JVS[80] = B[13];
/* JVS(81) = Jac_FULL(11,9)                                         */
  JVS[81] = B[26];
/* JVS(82) = Jac_FULL(11,10)                                        */
  JVS[82] = -B[23];
/* JVS(83) = Jac_FULL(11,11)                                        */
  JVS[83] = -B[14]-B[17]-B[24]-B[36]-B[43]-B[52]-B[56];
/* JVS(84) = Jac_FULL(11,12)                                        */
  JVS[84] = -B[37];
/* JVS(85) = Jac_FULL(11,13)                                        */
  JVS[85] = -B[15];
/* JVS(86) = Jac_FULL(12,4)                                         */
  JVS[86] = 0.6*B[38];
/* JVS(87) = Jac_FULL(12,5)                                         */
  JVS[87] = 0.31*B[47]+B[49];
/* JVS(88) = Jac_FULL(12,8)                                         */
  JVS[88] = 0.31*B[48];
/* JVS(89) = Jac_FULL(12,9)                                         */
  JVS[89] = B[28]+0.6*B[39]+B[50];
/* JVS(90) = Jac_FULL(12,10)                                        */
  JVS[90] = -B[30]-B[32];
/* JVS(91) = Jac_FULL(12,11)                                        */
  JVS[91] = -B[36];
/* JVS(92) = Jac_FULL(12,12)                                        */
  JVS[92] = -B[31]-B[33]-B[34]-B[37]-2*B[46];
/* JVS(93) = Jac_FULL(12,13)                                        */
  JVS[93] = -B[35];
/* JVS(94) = Jac_FULL(13,7)                                         */
  JVS[94] = B[54];
/* JVS(95) = Jac_FULL(13,8)                                         */
  JVS[95] = -B[10];
/* JVS(96) = Jac_FULL(13,9)                                         */
  JVS[96] = 0;
/* JVS(97) = Jac_FULL(13,10)                                        */
  JVS[97] = -B[19];
/* JVS(98) = Jac_FULL(13,11)                                        */
  JVS[98] = -B[14];
/* JVS(99) = Jac_FULL(13,12)                                        */
  JVS[99] = -B[34];
/* JVS(100) = Jac_FULL(13,13)                                       */
  JVS[100] = -B[11]-B[15]-B[20]-B[35]-B[64];
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
  JUV[0] = JVS[0]*UV[0]+JVS[1]*UV[9]+JVS[2]*UV[10];
  JUV[1] = JVS[3]*UV[1]+JVS[4]*UV[7]+JVS[5]*UV[11];
  JUV[2] = JVS[6]*UV[2]+JVS[7]*UV[5]+JVS[8]*UV[6]+JVS[9]*UV[8]+JVS[10]
          *UV[9];
  JUV[3] = JVS[11]*UV[1]+JVS[12]*UV[3]+JVS[13]*UV[6]+JVS[14]*UV[7]
          +JVS[15]*UV[9]+JVS[16]*UV[10]+JVS[17]*UV[11];
  JUV[4] = JVS[18]*UV[4]+JVS[19]*UV[9]+JVS[20]*UV[10]+JVS[21]*UV[12];
  JUV[5] = JVS[22]*UV[5]+JVS[23]*UV[8]+JVS[24]*UV[9]+JVS[25]*UV[11];
  JUV[6] = JVS[26]*UV[4]+JVS[27]*UV[5]+JVS[28]*UV[6]+JVS[29]*UV[8]
          +JVS[30]*UV[9]+JVS[31]*UV[10]+JVS[32]*UV[11]+JVS[33]*UV[12]
          +JVS[34]*UV[13];
  JUV[7] = JVS[35]*UV[1]+JVS[36]*UV[7]+JVS[37]*UV[8]+JVS[38]*UV[9]
          +JVS[39]*UV[10]+JVS[40]*UV[11]+JVS[41]*UV[12]+JVS[42]*UV[13];
  JUV[8] = JVS[43]*UV[5]+JVS[44]*UV[7]+JVS[45]*UV[8]+JVS[46]*UV[9]
          +JVS[47]*UV[10]+JVS[48]*UV[11]+JVS[50]*UV[13];
  JUV[9] = JVS[51]*UV[0]+JVS[52]*UV[2]+JVS[53]*UV[3]+JVS[54]*UV[4]
          +JVS[55]*UV[5]+JVS[56]*UV[6]+JVS[57]*UV[7]+JVS[58]*UV[8]
          +JVS[59]*UV[9]+JVS[60]*UV[10]+JVS[63]*UV[13];
  JUV[10] = JVS[64]*UV[0]+JVS[65]*UV[2]+JVS[66]*UV[4]+JVS[67]*UV[5]
           +JVS[68]*UV[6]+JVS[69]*UV[8]+JVS[70]*UV[9]+JVS[71]*UV[10]
           +JVS[72]*UV[11]+JVS[73]*UV[12]+JVS[74]*UV[13];
  JUV[11] = JVS[75]*UV[1]+JVS[76]*UV[3]+JVS[77]*UV[5]+JVS[78]*UV[6]
           +JVS[79]*UV[7]+JVS[80]*UV[8]+JVS[81]*UV[9]+JVS[82]*UV[10]
           +JVS[83]*UV[11]+JVS[84]*UV[12]+JVS[85]*UV[13];
  JUV[12] = JVS[86]*UV[4]+JVS[87]*UV[5]+JVS[88]*UV[8]+JVS[89]*UV[9]
           +JVS[90]*UV[10]+JVS[91]*UV[11]+JVS[92]*UV[12]+JVS[93]*UV[13];
  JUV[13] = JVS[94]*UV[7]+JVS[95]*UV[8]+JVS[97]*UV[10]+JVS[98]*UV[11]
           +JVS[99]*UV[12]+JVS[100]*UV[13];
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
  JTUV[0] = JVS[0]*UV[0]+JVS[51]*UV[9]+JVS[64]*UV[10];
  JTUV[1] = JVS[3]*UV[1]+JVS[11]*UV[3]+JVS[35]*UV[7]+JVS[75]*UV[11];
  JTUV[2] = JVS[6]*UV[2]+JVS[52]*UV[9]+JVS[65]*UV[10];
  JTUV[3] = JVS[12]*UV[3]+JVS[53]*UV[9]+JVS[76]*UV[11];
  JTUV[4] = JVS[18]*UV[4]+JVS[26]*UV[6]+JVS[54]*UV[9]+JVS[66]*UV[10]
           +JVS[86]*UV[12];
  JTUV[5] = JVS[7]*UV[2]+JVS[22]*UV[5]+JVS[27]*UV[6]+JVS[43]*UV[8]
           +JVS[55]*UV[9]+JVS[67]*UV[10]+JVS[77]*UV[11]+JVS[87]*UV[12];
  JTUV[6] = JVS[8]*UV[2]+JVS[13]*UV[3]+JVS[28]*UV[6]+JVS[56]*UV[9]
           +JVS[68]*UV[10]+JVS[78]*UV[11];
  JTUV[7] = JVS[4]*UV[1]+JVS[14]*UV[3]+JVS[36]*UV[7]+JVS[44]*UV[8]
           +JVS[57]*UV[9]+JVS[79]*UV[11]+JVS[94]*UV[13];
  JTUV[8] = JVS[9]*UV[2]+JVS[23]*UV[5]+JVS[29]*UV[6]+JVS[37]*UV[7]
           +JVS[45]*UV[8]+JVS[58]*UV[9]+JVS[69]*UV[10]+JVS[80]*UV[11]
           +JVS[88]*UV[12]+JVS[95]*UV[13];
  JTUV[9] = JVS[1]*UV[0]+JVS[10]*UV[2]+JVS[15]*UV[3]+JVS[19]*UV[4]
           +JVS[24]*UV[5]+JVS[30]*UV[6]+JVS[38]*UV[7]+JVS[46]*UV[8]
           +JVS[59]*UV[9]+JVS[70]*UV[10]+JVS[81]*UV[11]+JVS[89]*UV[12];
  JTUV[10] = JVS[2]*UV[0]+JVS[16]*UV[3]+JVS[20]*UV[4]+JVS[31]*UV[6]
            +JVS[39]*UV[7]+JVS[47]*UV[8]+JVS[60]*UV[9]+JVS[71]*UV[10]
            +JVS[82]*UV[11]+JVS[90]*UV[12]+JVS[97]*UV[13];
  JTUV[11] = JVS[5]*UV[1]+JVS[17]*UV[3]+JVS[25]*UV[5]+JVS[32]*UV[6]
            +JVS[40]*UV[7]+JVS[48]*UV[8]+JVS[72]*UV[10]+JVS[83]*UV[11]
            +JVS[91]*UV[12]+JVS[98]*UV[13];
  JTUV[12] = JVS[21]*UV[4]+JVS[33]*UV[6]+JVS[41]*UV[7]+JVS[73]*UV[10]
            +JVS[84]*UV[11]+JVS[92]*UV[12]+JVS[99]*UV[13];
  JTUV[13] = JVS[34]*UV[6]+JVS[42]*UV[7]+JVS[50]*UV[8]+JVS[63]*UV[9]
            +JVS[74]*UV[10]+JVS[85]*UV[11]+JVS[93]*UV[12]+JVS[100]
            *UV[13];
}

/* End of JacTR_SP_Vec function                                     */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


