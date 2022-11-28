// Reproduction of the C program source code for 2nd ICEO problem
//
// version 1.
// original implementation existed in 
// http://iridia.ulb.ac.be:80/~aroli/ICEO/Functions/Functions.html
// hosted by Gregory Seront (one of the committee members of 2nd ICEO )
// was excavated in web archive (Wayback Machine)
//
// version 2.
// a reviced version written by Yohei Nishidate in C++ 
// 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

using REAL = double;

// --- version 1 begins from here
/*  Chebychev Polynomial */
/* Valid for D=9 or D=17 */
REAL Chebychev(REAL *tmp, int D) {
    int i, j;
    REAL px,x=-1,result=0,dx;
   
    if ( D == 9 )  dx = 72.66066;
    if ( D == 17 ) dx = 10558.145;

    for ( i=0; i<=100; i++ ) {
	px = tmp[0];
	
	//an alternative way for calculating abscissae for more precise function evaluation
	//REAL x = -1.0 + 2.0*(REAL)i/100.0;
	
	for ( j=1; j<D; j++) px = x*px + tmp[j];
	if ( px < -1 || px > 1 ) result += (1. - px)*(1. - px);
	x += .02;
    }
    
    px = tmp[0];
    for ( j=1; j<D; j++ ) px = 1.2*px + tmp[j];
    px = px - dx;
    if ( px < 0 ) result += px*px;
    
    px = tmp[0];
    for ( j=1; j<D; j++ ) px = -1.2*px + tmp[j];
    px = px - dx;
    if ( px < 0 ) result += px*px;
    
    return result;
}
// --- version 1 ends here

// --- version 2 starts from here
REAL Tchebychev( const vector<REAL>& x ) {

    size_t N = x.size();
    
    REAL res = 0.0;
    
    REAL dx = 0.0;
    if      ( N == 9 ) dx = 72.66066;
    else if ( N == 17 ) dx = 10558.145;
    else { assert( false ); }
    
    for ( int i=0; i<=100; ++i ) {
	REAL px = x[0];

	//!!! a few differences would be found from original implementation
	//since we avoid accumulated expressions
	//for calculating abscissae t (x in original source code)
	//if this t is calculated in the same way with the original one, they coincide
	REAL t = -1.0 + 2.0*(REAL)i/100.0;
	///-------
	
	for ( int j=1; j<N; ++j ) px = t*px + x[j];
	if ( px < -1 || px > 1 ) res += ( 1.0 - px )*( 1.0 - px );
    }

    REAL px = x[0];
    for ( int j=1; j<N; ++j ) px = 1.2*px + x[j];
    px -= dx;
    if ( px < 0 ) res += px*px;
    
    px = x[0];
    for ( int j=1; j<N; ++j ) px = -1.2*px + x[j];
    px -= dx;
    if ( px < 0 ) res += px*px;

    return res;
}
// --- version 2 ends here

// confirmed above two versions are identical through the following test code
#ifdef _TEST
const REAL EPS = 1e-12;
const REAL min_x = 0;
const REAL max_x = 10;
const int DIM = 9;
const int samples = 6;

bool IsEqual( const REAL& a, const REAL& b ) {
    // check absolute diff if a is too small (close to 0)
    if ( fabs( a ) < EPS ) return fabs( a - b ) < EPS;
    // check relative absolute diff otherwise
    return fabs( (a - b)/a ) < EPS;    
}

void eval( vector<REAL> x, int curr ) {

    int N = x.size();
    
    if ( curr == x.size() ) {

	REAL f1 = Chebychev( &x[0], N );//how to use version 1
	REAL f2 = Tchebychev( x ); //how to use version 2
	
	if ( !IsEqual( f1, f2 ) ) {//checking
	    cout << setprecision(20) << f1 << " " << f2 << endl;
	}
	
	return;
    }

    for ( int k=0; k<=samples; ++k ) {
	REAL z = min_x + (max_x - min_x)*(REAL)k/(REAL)samples;
	x[curr] = z;
	eval( x, curr + 1 );
    }
}

int main() {

    vector<REAL> x( DIM );
    eval( x, 0 );

    return 0;
}
#endif
