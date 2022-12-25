#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<stdio.h>
#include<stdlib.h>
#define gc getchar_unlocked
int main() {
	register char prev = 0;
	register char current = 0;
	for(int c = gc();c>=48&&c<=57;c=gc()) {
		prev = current;
		current = c - 48;
	}
	u_int8_t N = prev*10+current;
	if (N&1) {
		return printf("SELL");
	} else if (N&2) {
		return printf("PASS");
	}
	return printf("BUY");
}
