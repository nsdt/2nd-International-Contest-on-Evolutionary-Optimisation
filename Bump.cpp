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

using namespace std;

using REAL = double;

// --- version 1 begins from here 
/* Returns the value of the function in itself */
REAL Bump( REAL x[], int NVARS ) {
    //constraints
    REAL c1 = 1.0;
    REAL c2 = 0.0;
    for ( int i=0; i<NVARS; ++i ) {
	c1 *= x[i];
	c2 += x[i];
    }
    if ( c1 < 0.75 || c2 > 7.5*(REAL)NVARS ) return 1e32; //inf

    int ii;
    REAL sumc4, prodc2, sumsq, obj;
 
    sumc4 = 0.0;
    prodc2 = 1.0;
    sumsq = 0.0;
    for (ii = 0; ii<NVARS; ii++) {
	sumc4 = sumc4 + cos(x[ii]) * cos(x[ii]) * cos(x[ii]) * cos(x[ii]);
	prodc2 = prodc2 * cos(x[ii]) * cos(x[ii]);
	sumsq = sumsq + (REAL)(ii+1) * x[ii] * x[ii];
    }
    sumsq = sqrt(sumsq);
    obj = (sumc4 - 2.0 * prodc2)/sumsq;
    return fabs( obj );
}
// --- version 1 ends here

// --- version 2 starts from here
static REAL Bump( const vector<REAL>& x ) {

    size_t N = x.size();

    //constraints
    REAL c1 = 1.0;
    REAL c2 = 0.0;
    for ( int i=0; i<N; ++i ) {
	c1 *= x[i];
	c2 += x[i];
    }
    if ( c1 < 0.75 || c2 > 7.5*(REAL)N ) return 1e32; //inf
    
    REAL t1 = 0.0, t2 = 1.0;
    REAL d = 0.0;
    for ( int i=0; i<N; ++i ) {
	REAL c = cos( x[i] );
	t1 += c*c*c*c;
	t2 *= c*c;
	d += x[i]*x[i]*(REAL)(i+1);
    }

    REAL v = (t1 - 2.0*t2)/sqrt( d );
    return fabs( v );
}
// --- version 2 ends here


// confirmed above two versions are identical through the following test code
#ifdef _TEST
const REAL EPS = 1e-12;
const REAL min_x = 0;
const REAL max_x = 10;
const int DIM = 10;
const int samples = 5;

bool IsEqual( const REAL& a, const REAL& b ) {
    // check absolute diff if a is too small (close to 0)
    if ( fabs( a ) < EPS ) return fabs( a - b ) < EPS;
    // check relative absolute diff otherwise
    return fabs( (a - b)/a ) < EPS;    
}

void eval( vector<REAL> x, int curr ) {

    int N = x.size();
    
    if ( curr == x.size() ) {

	REAL f1 = Bump( &x[0], N );//how to use version 1
	REAL f2 = Bump( x ); //how to use version 2
	
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
