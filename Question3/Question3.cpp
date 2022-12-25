#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<stdio.h>
#define gc getchar_unlocked
#define pc putchar_unlocked 
void scan_integer( int* x )
{
    register int c = gc();
    *x = 0;
    for( ;c>47 && c<58; c = gc() ) {
        *x = ((*x) << 1) + ((*x) << 3) + c - 48;
    }
} 
int main() {
	int N,M;
	scan_integer(&N);
	scan_integer(&M);
	int value;
	int prev = -1;
	for (unsigned int i = 0; i < N; ++i) {
		scan_integer(&value);
		if ((value<<1) >= M) {
		 	if (prev > value) {
				return pc('0');
			}
			prev = value;
		}
	}
	return pc('1');
}
