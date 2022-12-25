#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

inline void scan_integer( int &x )
{
    int c = gc();
    x = 0;
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
} 


#define row_empty(row, fcol, tcol) (rdp[row][tcol]-rdp[row][fcol-1]==0)
#define col_empty(col, frow, trow) (cdp[col][trow]-cdp[col][frow-1]==0)
#define check(frow, fcol, trow, tcol) frow < 0 || fcol < 0 || trow >= N || tcol >= N || frow > trow || fcol > tcol

unordered_map<int, int> dp;
 
int cdp[51][51];
int rdp[51][51];
int N;

union coord_u {
	uint8_t coords[4];
	uint32_t hash;
};

inline coord_u makec(int frow, int fcol, int trow, int tcol) {
	coord_u coords;
	coords.coords[0] = frow;
	coords.coords[1] = fcol;
	coords.coords[2] = trow;
	coords.coords[3] = tcol;
	return coords;
}

int count(coord_u pos) {
	int frow = pos.coords[0];
	int fcol = pos.coords[1];
	int trow = pos.coords[2];
	int tcol = pos.coords[3];
	if (check(frow, fcol, trow, tcol)) return 0;
	while(row_empty(frow, fcol, tcol)) { frow++; }
	while(row_empty(trow, fcol, tcol)) { trow--; }
	while(col_empty(fcol, frow, trow)) { fcol++; }
	while(col_empty(tcol, frow, trow)) { tcol--; }
	
	int h = trow-frow+1;
	int w = tcol-fcol+1;
	
	int square_size = max(w,h);

	int coords = pos.hash;
	//int n = 40;
	//int coords = frow*n*n*30 + fcol*n*n + trow*n+ tcol;
	auto found = dp.find(coords);
	if (found != dp.end()) return found->second;

	dp[coords] = square_size;

	if (h >= w) {
		for (int i = frow+1; i <= trow-1; ++i) {
			if (row_empty(i, fcol, tcol)) {
				int s = i;
				while (row_empty(i, fcol, tcol)) {
					++i;
				}
				int res = count(makec(frow,fcol,s-1,tcol))+count(makec(i,fcol,trow,tcol));
				if (res < dp[coords]) dp[coords] = res;
			}
		}
		return dp[coords];
	}

	if (w >= h) {
		for (int i = fcol+1; i <= tcol-1; ++i) {
			if (col_empty(i, frow, trow)) {
				int s = i;
				while (col_empty(i, frow, trow)) {
					++i;
				}
				int res = count(makec(frow,fcol,trow,s-1))+count(makec(frow,i,trow,tcol));
				if (res < dp[coords]) dp[coords] = res;
			}
		}
	}

	return dp[coords];
}

int main()
{
	scan_integer(N);
	int c;
	int found_one = false;
	int all_ones = false;
	for (int i = 0; i < N; ++i) {
		int row_all_ones = 1;
		for (int j = 0; j < N; ++j) {
			c = gc();
			rdp[i][j] = c=='$';
			found_one |= rdp[i][j];
			row_all_ones &= rdp[i][j];
		}
		all_ones |= row_all_ones;
		gc();
	}
	if (all_ones) return printf("%d", N);
	if (!found_one) {
		return putchar_unlocked('0');
	}

	for (int i = 0; i < N; ++i) {
		cdp[i][0] = rdp[0][i];
		for (int j = 0; j < N; ++j) {
			cdp[i][j] = cdp[i][j-1] + rdp[j][i];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			rdp[i][j] += rdp[i][j-1];
		}
	}
/*
	for (int i = 0; i < N; ++i) {
		if (cdp[i][N-1] != 0) {
			if (fcol == -1) fcol = i;
			tcol = i;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (rdp[i][N-1] != 0) {
			if (frow == -1) frow = i;
			trow = i;
		}
	}
	*/

	printf("%d", count(makec(0,0,N-1,N-1)));

    return 0;
}


