#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
#pragma GCC optimize("inline")

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked 

inline void scan_integer( int &x )
{
    register int c = gc();
    x = 0;
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
} 


int visited[2000];
vector<int> adj[2000];

inline int dfs(int i) {
	visited[i] = 1;
	int res = false;
	for (int& child: adj[i]) {
		if (visited[child] == 1 || (visited[child] == 0 && dfs(child))) {
			visited[i] = 2;
			return true;
		}
	}
	visited[i] = 2;

	return false;

}

int main()
{
		register int N, T;
		scan_integer(N);
		scan_integer(T);

		register int from,to;
		for (int i = 0; i < T; i++) {
			scan_integer(from);
			scan_integer(to);
			if (from != to) {
				adj[from].push_back(to);
			}
		}

		for (int i = 0; i < N; i+=1+visited[i+1]&1) {
			if (visited[i]&1 || (visited[i] == 0 && dfs(i))) {
				putchar('I');
				putchar('n');
				putchar('e');
				putchar('l');
				putchar('i');
				putchar('g');
				putchar('i');
				putchar('b');
				putchar('l');
				return putchar('e');
			}
		}

				putchar('E');
				putchar('l');
				putchar('i');
				putchar('g');
				putchar('i');
				putchar('b');
				putchar('l');
				return putchar('e');
}
