/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                  */
/* The ODE Function of Chemical Model File                          */
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
/* File                 : tm5_ifs_Function.c                        */
/* Time                 : Tue Feb  1 10:46:30 2022                  */
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
/* Fun - time derivatives of variables - Agregate form              */
/*   Arguments :                                                    */
/*      V         - Concentrations of variable species (local)      */
/*      F         - Concentrations of fixed species (local)         */
/*      RCT       - Rate constants (local)                          */
/*      Vdot      - Time derivative of variable species concentrations */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Fun( 
  double V[],                            /* Concentrations of variable species (local) */
  double F[],                            /* Concentrations of fixed species (local) */
  double RCT[],                          /* Rate constants (local) */
  double Vdot[],                         /* Time derivative of variable species concentrations */
  double A[]                             /* Rate for each equation */
)
{

/* Local variables                                                  */

/* Computation of equation rates                                    */
  A[0] = RCT[0]*V[10]*V[13];
  A[1] = RCT[1]*V[8]*V[10];
  A[2] = RCT[2]*V[8]*V[13];
  A[3] = RCT[3]*V[8]*V[8];
  A[4] = RCT[4]*V[2]*V[13];
  A[5] = RCT[5]*V[13];
  A[6] = RCT[6]*V[10]*V[12];
  A[7] = RCT[7]*V[8]*V[12];
  A[8] = RCT[8]*V[11]*V[13];
  A[9] = RCT[9]*V[13]*F[0];
  A[10] = RCT[10]*V[7]*V[12];
  A[11] = RCT[11]*V[7]*V[8];
  A[12] = RCT[12]*V[7]*V[8];
  A[13] = RCT[13]*V[4]*V[13];
  A[14] = 2e-11*V[4]*V[13];
  A[15] = RCT[15]*V[3]*V[13];
  A[16] = RCT[16]*V[5]*V[13];
  A[17] = RCT[17]*V[6]*V[10];
  A[18] = RCT[18]*V[6]*V[13];
  A[19] = RCT[19]*V[10];
  A[20] = RCT[20]*V[11];
  A[21] = RCT[21]*V[5];
  A[22] = RCT[22]*V[5];
  A[23] = RCT[23]*V[4];
  A[24] = RCT[24]*V[2];
  A[25] = RCT[25]*V[10]*V[11];
  A[26] = RCT[26]*V[9]*V[12];
  A[27] = RCT[27]*V[9]*V[11];
  A[28] = RCT[28]*V[1];
  A[29] = 4e-12*V[8]*V[9];
  A[30] = 1.5e-21*V[1];
  A[31] = RCT[31]*V[6]*V[9];
  A[32] = RCT[32]*V[9];
  A[33] = RCT[33]*V[1];
  A[34] = RCT[34]*F[2];
  A[35] = RCT[35]*F[2];
  A[36] = RCT[36]*V[10];
  A[37] = RCT[37]*V[12];
  A[38] = RCT[38]*V[11];
  A[39] = RCT[39]*V[0];
  A[40] = RCT[40]*V[4];
  A[41] = RCT[41]*V[2];
  A[42] = RCT[42]*V[5];

/* Aggregate function                                               */
  Vdot[0] = A[8]+A[29]+2*A[30]-A[39];
  Vdot[1] = A[27]-A[28]-A[30]-A[33];
  Vdot[2] = A[3]-A[4]-A[24]-A[41];
  Vdot[3] = -A[15]+A[16]+0.56*A[17]+A[21]+A[22];
  Vdot[4] = A[11]-A[13]-A[14]-A[23]-A[40];
  Vdot[5] = A[10]+A[12]+0.4*A[13]-A[16]+0.54*A[17]-A[21]-A[22]+A[23]
           -A[42];
  Vdot[6] = -A[17]-A[18]-A[31]+A[34];
  Vdot[7] = A[9]-A[10]-A[11]-A[12]+0.6*A[13]+0.31*A[17]+A[18]+A[31];
  Vdot[8] = A[0]-A[1]-A[2]-2*A[3]+A[4]+A[5]-A[7]+A[10]-A[11]-A[12]
           +A[15]+A[16]+0.19*A[17]+2*A[21]+A[23]-A[29];
  Vdot[9] = A[25]-A[26]-A[27]+A[28]-A[29]-A[31]-A[32]+A[33];
  Vdot[10] = -A[0]-A[1]-A[6]-A[17]-A[19]+A[20]-A[25]+A[32]-A[36];
  Vdot[11] = A[6]+A[7]-A[8]+A[10]-A[20]-A[25]+2*A[26]-A[27]+A[28]+A[31]
            +A[32]+A[33]-A[38];
  Vdot[12] = -A[6]-A[7]-A[10]+A[20]-A[26]+A[35]-A[37];
  Vdot[13] = -A[0]+A[1]-A[2]-A[4]-A[5]+A[7]-A[8]-A[9]-0.6*A[13]-0.77
            *A[14]-A[15]-A[16]+0.33*A[17]-A[18]+2*A[19]+A[23]+2*A[24];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


