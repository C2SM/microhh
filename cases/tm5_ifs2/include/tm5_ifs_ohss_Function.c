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
/* File                 : tm5_ifs_ohss_Function.c                   */
/* Time                 : Sat Apr  3 22:32:57 2021                  */
/* Working directory    : /home/WUR/krol005/kpp/examples            */
/* Equation file        : tm5_ifs_ohss.kpp                          */
/* Output root filename : tm5_ifs_ohss                              */
/*                                                                  */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tm5_ifs_ohss_Parameters.h"
#include "tm5_ifs_ohss_Global.h"
#include "tm5_ifs_ohss_Sparse.h"


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
  double Vdot[]                          /* Time derivative of variable species concentrations */
)
{

/* Local variables                                                  */
double A[NREACT];                        /* Rate for each equation */

/* Computation of equation rates                                    */
  A[0] = RCT[0]*V[9]*F[1];
  A[1] = RCT[1]*V[9]*V[11];
  A[2] = RCT[2]*V[11]*F[1];
  A[3] = RCT[3]*V[11]*V[11];
  A[4] = RCT[4]*F[1];
  A[5] = RCT[5]*V[8]*V[9];
  A[6] = RCT[6]*V[7]*V[9];
  A[7] = RCT[7]*V[6]*V[7];
  A[8] = RCT[8]*V[3];
  A[9] = RCT[9]*V[8]*V[11];
  A[10] = RCT[10]*V[7]*F[1];
  A[11] = RCT[11]*F[0]*F[1];
  A[12] = RCT[12]*V[8]*V[10];
  A[13] = RCT[13]*V[10]*V[11];
  A[14] = RCT[14]*V[4]*F[1];
  A[15] = RCT[15]*V[1]*F[1];
  A[16] = RCT[16]*V[2]*F[1];
  A[17] = 8e-17*V[5]*V[9];
  A[18] = RCT[18]*V[5]*F[1];
  A[19] = 4e-12*V[5]*V[6];
  A[20] = RCT[20]*V[9];
  A[21] = RCT[21]*V[7];
  A[22] = RCT[22]*V[3];
  A[23] = RCT[23]*V[2];
  A[24] = RCT[24]*V[2];
  A[25] = RCT[25]*V[4];
  A[26] = RCT[26]*V[6];
  A[27] = RCT[27]*V[6];
  A[28] = RCT[28]*V[3];
  A[29] = RCT[29]*F[3];
  A[30] = RCT[30]*F[3];
  A[31] = RCT[31]*V[9];
  A[32] = RCT[32]*V[8];
  A[33] = RCT[33]*V[7];
  A[34] = RCT[34]*V[5];
  A[35] = RCT[35]*V[0];
  A[36] = RCT[36]*V[4];

/* Aggregate function                                               */
  Vdot[0] = A[10]+2*A[28]-A[35];
  Vdot[1] = -A[15]+A[16]+A[23]+A[24];
  Vdot[2] = A[12]+0.4*A[14]-A[16]-A[23]-A[24]+A[25];
  Vdot[3] = A[7]-A[8]-A[22]-A[28];
  Vdot[4] = A[13]-A[14]-A[25]-A[36];
  Vdot[5] = -A[17]-A[18]-A[19]+A[29]-A[34];
  Vdot[6] = A[6]-A[7]+A[8]-A[19]+A[22]-A[26]-A[27];
  Vdot[7] = A[5]-A[6]-A[7]+A[8]+A[9]-A[10]+A[12]+A[19]-A[21]+A[22]
           +A[26]-A[33];
  Vdot[8] = -A[5]-A[9]-A[12]+A[21]+A[27]+A[30]-A[32];
  Vdot[9] = -A[0]-A[1]-A[5]-A[6]-A[17]-A[20]+A[21]+A[26]-A[31];
  Vdot[10] = A[11]-A[12]-A[13]+0.6*A[14]+0.75*A[17]+A[18]+A[19];
  Vdot[11] = A[0]-A[1]-A[2]-2*A[3]+A[4]-A[9]+A[12]-A[13]+A[15]+A[16]+2
            *A[23]+A[25];
}

/* End of Fun function                                              */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


