/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
                   Matlab Gateway for the Hessian 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "mex.h"
#define min( x, y ) (x) < (y) ? (x) : (y)
#define max( x, y ) (x) > (y) ? (x) : (y)

void mexFunction( int nlhs, mxArray *plhs[], 
                     int nrhs, const mxArray *prhs[] )
{
 int mrows, mcols;
 double *V, *F, *RCT, *HESS;


/* Check for the right number and size of input arguments */
 if ( nrhs != 3 ) {
   mexErrMsgTxt("ifss_Hessian requires 3 input vectors: V(11), F(4), RCT(33)");
 }
 mrows =  mxGetM(prhs[0]); mcols = mxGetN(prhs[0]);
 if ( ( mrows != 11 )||( mcols != 1 ) ) {
   mexPrintf("First ifss_Hessian input argument is of size V(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("First ifss_Hessian input argument should be a column vector V(11,1)");
 }
 mrows =  mxGetM(prhs[1]); mcols = mxGetN(prhs[1]);
 if ( ( mrows != 4 )||( mcols != 1 ) ) {
   mexPrintf("Second ifss_Hessian input argument is of size F(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Second ifss_Hessian input argument should be a column vector F(4,1)");
 }
 mrows =  mxGetM(prhs[2]); mcols = mxGetN(prhs[2]);
 if ( (  mrows != 33 )||( mcols != 1 ) ) {
   mexPrintf("Third ifss_Hessian input argument is of size RCT(%d,%d).",  
               mrows, mcols);
   mexErrMsgTxt("Third ifss_Hessian input argument should be a column vector RCT(33,1)");
 }
 
/* Check for the right number of output arguments */
 if ( nlhs != 1 ) {
   mexErrMsgTxt("ifss_Hessian requires 1 output column vector: HESS(22)");
 }


 V   = mxGetPr(prhs[0]);
 F   = mxGetPr(prhs[1]);
 RCT = mxGetPr(prhs[2]);

 plhs[0] = mxCreateDoubleMatrix(22,1,mxREAL);
 HESS = mxGetPr(plhs[0]);

 Hessian( V, F, RCT, HESS );

}
