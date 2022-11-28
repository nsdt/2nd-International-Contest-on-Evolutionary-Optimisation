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
/* original Michalewitz */
REAL Micha( REAL* y, int n ) { 
    const REAL m = 10.0;
    const int MaxDim = 10;

    REAL x[MaxDim];
    //REAL PI = 3.1415927; //this original one may be too short so digits extended
    REAL PI = 3.1415926535897932384626433832795;
    REAL u = 0, temp;
    REAL cost = cos(PI/6), sint = sin(PI/6);
    int i;

    for ( i = 0; i <n-1; i+=2 ) {
	x[i] = y[i]*cost - y[i+1]*sint;
	x[i+1] = y[i]*sint + y[i+1]*cost;
    }
	
    if ( i = n-1 ) x[i] = y[i];

    for ( i=0; i<n; i++ ) {
	u = u + sin(x[i])
	    * pow(sin((i+1)*x[i]*x[i]/PI),2.0*m); 
    }

    return -u; 
}
// --- version 1 ends here

// --- version 2 starts from here
static REAL EpistaticMichalewicz( const vector<REAL>& x ) {

    size_t N = x.size();

    const int m = 10;
    const REAL t = M_PI/6.0;
    REAL c = cos( t );
    REAL s = sin( t );

    REAL res = 0.0;
    for ( int i=1; i<=N; ++i ) {
	REAL y = 0.0;

	int k = i%2;
	if ( i == N ) y = x[i-1];
	else if ( k == 1 ) y = x[i-1]*c - x[i]*s;
	else if ( k == 0 ) y = x[i-1]*s + x[i]*c;

	res += sin(y)*pow( sin((REAL)i*y*y/M_PI), 2.0*(REAL)m );
    }
    return -res; 
}
// --- version 2 ends here

// confirmed above two versions are identical through the following test code
#ifdef _TEST
const REAL EPS = 1e-12;
const REAL min_x = 0;
const REAL max_x = M_PI;
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

	REAL f1 = Micha( &x[0], N );//how to use version 1
	REAL f2 = EpistaticMichalewicz( x ); //how to use version 2
	
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
