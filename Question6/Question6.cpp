#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("O3,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
//#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")

#include<iostream>
using namespace std;
#define gc getchar_unlocked

void scan_integer( int &x )
{
    int c = gc();
    x = 0;
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
} 

int main()
{
	int N;
	scan_integer(N);
	int values[N];
	int* result[N];
	int base = -1;

	for (unsigned int i = 0; i < N; ++i) {
		scan_integer(values[i]);
		result[i] = &base;
	}
	for (int i = 0; i < N; i++) {
		if (result[i] != &base) continue;
		int current = i;
		int* steps = new int;
		*steps = 0;
		while (current != i || *steps == 0) {
			result[current] = steps;
			(*steps)++;
			current = values[current]-1;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", *(result[i])); 
	}
}

