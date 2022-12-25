#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2")
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define gc getchar_unlocked

#define C 52

int main() {
	int counter[C] = {0};

	int c = gc();
	while (c != EOF && c != '\n') {
		counter[(c)-(isupper(c)?'A'-26:'a')]++;
		c = gc();
	}
	int count = 0;
	for (int i = 0; i < C; ++i) {
		count += (counter[i]>0)*(2*(counter[c]&1)-1);
	}
/*
	int count = 0;
	for (int i = 0; i < C; ++i) {
		if (counter[i] > 0) {
			count += (counter[i]-(counter[i]&1)*(count&1));
		}
	}*/

	printf("%d", count);
}
