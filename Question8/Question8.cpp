#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<stdio.h>
#include<limits.h>
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
#define gc getchar_unlocked
void scan_integer( int* x )
{
    register int c = gc();
    *x = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        *x = ((*x) << 1) + ((*x) << 3) + c - 48;
    }
} 

int main() {
	int K,N;
	scan_integer(&K);
	scan_integer(&N);

	int values[N];

	for (int i = 0; i < N; ++i) scan_integer(&values[i]);

	if ((K<<1)>=N) {
		int val = 0;
		for (int i = 1; i < N; ++i) {
			val += max(values[i] - values[i-1], 0);
		}
		return printf("%d", val);
	}

	int b[101];
	int s[101];

	for (int i = 1; i <= K; ++i) b[i] = INT_MAX;

	for (int i = 0; i < N; ++i) {
		for (int k = 1; k <= K; ++k) {
			b[k] = min(b[k], values[i]-s[k-1]);
			s[k] = max(s[k], values[i]-b[k]);
		}
	}

	printf("%d", s[K]);
}
