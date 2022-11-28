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
REAL temp1(REAL d1, REAL d0) {
    return (d1 - d0*d0);
}

REAL temp2(REAL d0) {
    return (1. - d0);
}

REAL RozenBrock(REAL *x, int N) { // maybe typo 'Z' in original one (should be Rosenbrock)

    REAL t0, tt, t1, d=0;
    int i;

    t0=x[0];
    for ( i=1; i < N; i++) {
	t1 = x[i];
	tt = temp2(t0);
	d += tt*tt;
	tt = temp1(t1,t0);
	d += 100*tt*tt;
      
	t0 = t1;
    }
   
    return d;
}
// --- version 1 ends here


// --- version 2 starts from here
static REAL Rosenbrock( const vector<REAL>& x ) {

    size_t N = x.size();
    
    REAL val = 0.0;
    for ( int i=0; i<N-1; ++i ) {
	REAL a = x[i+1] - x[i]*x[i];
	REAL b = x[i] - 1.0;
	val += 100.0*a*a + b*b;
    }
    return val;
}
// --- version 2 ends here


// confirmed above two versions are identical through the following test code
#ifdef _TEST
const REAL EPS = 1e-12;
const REAL min_x = -5.12;
const REAL max_x = 5.12;
const int DIM = 2;
const int samples = 100;

bool IsEqual( const REAL& a, const REAL& b ) {
    // check absolute diff if a is too small (close to 0)
    if ( fabs( a ) < EPS ) return fabs( a - b ) < EPS;
    // check relative absolute diff otherwise
    return fabs( (a - b)/a ) < EPS;    
}

void eval( vector<REAL> x, int curr ) {

    int N = x.size();
    
    if ( curr == x.size() ) {

	REAL f1 = RozenBrock( &x[0], N );//how to use version 1
	REAL f2 = Rosenbrock( x ); //how to use version 2
	
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
