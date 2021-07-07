/*
This can be solved simply with KMP
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define rep(i, n) for (int i = 0; i < (n); i++)

#define MAXN 2000005

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	string t;
	cin >> s >> t;
	s = t + "$" + s;
	int N = s.length();

	int pi[MAXN] = {0}; // pi[i] = longest proper prefix that is a suffix of s[:i]
	for (int i = 1; i < N; i++) {
		int j = pi[i-1];
		while (j > 0 && s[j] != s[i]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (pi[i] == sz(t)) cnt++;
	}
	printf("%d\n", cnt);
}
