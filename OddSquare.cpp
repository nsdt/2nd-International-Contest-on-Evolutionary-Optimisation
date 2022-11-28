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
/*
 * 1st ICEO test function
 *
 * Problem 5: The Langerman's function 
 *
 */

REAL center_point[] = {1., 1.3, .8, -.4, -1.3, 1.6, -.2, -.6, .5, 1.4, 
		       1., 1.3, .8, -.4, -1.3, 1.6, -.2, -.6, .5, 1.4};

REAL SqrDst( REAL *x1, REAL *x2, int n ) {
    REAL dist = 0.0, d;
    int i;

    dist = 0;

    for ( i = 0; i<n; i++ ) {
	d =x1[i] - x2[i];
	dist += d*d;
    }

    return sqrt(dist);
}

REAL MaxSqrDst( REAL *x1, REAL *x2, int n ) {
    REAL dist = 0.0;
    int i;

    dist = 0.0;

    for ( i=0; i<n; i++ )
	dist = dist > fabs(x1[i] - x2[i]) ? dist : fabs(x1[i] - x2[i]);

    return sqrt(n*dist*dist);
}


REAL vicious_square( REAL *x, int n ) {
 
    REAL Att, PII, dist;

    //PII  = 3.141592653; //this original one may be too short so digits extended
    PII = 3.1415926535897932384626433832795;
        
    dist = MaxSqrDst( x, center_point, n );

    Att = (exp(-dist/(2*PII)) * cos( PII * dist ) ) 
	* ( 1 + 0.2 * (SqrDst( x, center_point, n )/(dist+.01)));

    return -Att;
}
// --- version 1 ends here

// --- version 2 starts from here
static REAL OddSquare( const vector<REAL>& x ) {

    size_t N = x.size();

    const REAL b[20] =
	{ 1, 1.3, 0.8, -0.4, -1.3, 1.6, -0.2, -0.6, 0.5, 1.4,
	  1, 1.3, 0.8, -0.4, -1.3, 1.6, -0.2, -0.6, 0.5, 1.4 };
    REAL l2 = 0.0, linf = 0.0;

    for ( int i=0; i<N; ++i ) {
	REAL a = x[i] - b[i];
	l2 += a * a;
	linf = std::max( linf, (REAL)fabs(a) );
    }
    l2 = sqrt( l2 );
    linf *= sqrt( (REAL)N );

    return -( (1.0 + 0.2*l2/( linf + 0.01 ))*cos( linf*M_PI )*exp( -0.5*linf/M_PI ) );
}
// --- version 2 ends here

// confirmed above two versions are identical through the following test code
#ifdef _TEST
const REAL EPS = 1e-12;
const REAL min_x = -5*M_PI;
const REAL max_x = 5*M_PI;
const int DIM = 5;
const int samples = 20;

bool IsEqual( const REAL& a, const REAL& b ) {
    // check absolute diff if a is too small (close to 0)
    if ( fabs( a ) < EPS ) return fabs( a - b ) < EPS;
    // check relative absolute diff otherwise
    return fabs( (a - b)/a ) < EPS;    
}

void eval( vector<REAL> x, int curr ) {

    int N = x.size();
    
    if ( curr == x.size() ) {

	REAL f1 = vicious_square( &x[0], N );//how to use version 1
	REAL f2 = OddSquare( x ); //how to use version 2
	
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
