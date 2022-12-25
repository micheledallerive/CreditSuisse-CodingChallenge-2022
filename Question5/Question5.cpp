#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<stdio.h>

#define gc getchar_unlocked
#define max(a,b) a>b?a:b

void scan_integer( int* x )
{
    register int c = gc();
    *x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        *x = ((*x) << 1) + ((*x) << 3) + c - 48;
    }
    if( neg )
        (*x)=-(*x);
}

int main() {
	int C;
	int N;
	
	scan_integer(&C);
	scan_integer(&N);

	int values[N];
	for (int i = 0; i < N; ++i) {
		scan_integer(&values[i]);
	}

	int i = 0;
	int j = 0;
	int ans = 0;
	int csum = 0;

	while (j < N) {
		if ((csum + values[j]) < C) {
			csum += values[j];
			++j;
			++ans;
		} else {
			csum = max(0, (csum - values[i]));
			++i;
			j = max(j, i);
			ans += (j-i)*(csum < C);
		}
	}
	printf("%d", (ans + (((j-i-1) * (j-i)) >> 1)*(j==N)));
}
