//eskere
#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<iostream>
#include<climits>
#include<set>
#include<vector>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;

inline void scan_integer( int &x )
{
    register int c = gc();
    x = 0;
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
} 

int main() {
	int N; 
	scan_integer(N);

	string names[N];
	for (int i = 0; i < N; ++i) cin >> names[i];

	vector<int> start[22];
	vector<int> end[22];

	int t1,t2;
	int diff = 0;
	for (int i = 0; i < N; ++i) {
		scan_integer(t1);
		start[t1].push_back(i);
		scan_integer(t2);
		end[t2].push_back(i);

		diff += (start[t1].size()==1 && end[t1].size()==0);
		diff += (start[t2].size()==1 && end[t2].size()==0);
	}

	printf("%d\n", diff-1);

	auto cmp = [](string* a, string* b) {return *a < *b;};
	set<string*,decltype(cmp)> available(cmp);
	int prev_time = -1;
	for (int i = 1; i < 22; ++i) {
		if (start[i].size() == 0 && end[i].size() == 0) continue;
		if (prev_time != -1 && prev_time != i) {
			printf("%d %d %d ", prev_time, i, available.size());
			for (auto it = available.begin(); it != available.end();) {
				for (const char& c : *(*it)) putchar(c);
				if (++it != available.end()) putchar(' ');
			}
			putchar('\n');
		}
		prev_time = i;
		for (const int x : start[i]) available.insert(&names[x]);
		for (const int x : end[i]) available.erase(&names[x]);
	}

    return 0;
}

