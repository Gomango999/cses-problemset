/*
This can be solved using KMP and then recursively looking at border lengths.
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

#define MAXN 1000005

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	int N = s.length();

	int pi[MAXN] = {0};
	for (int i = 1; i < N; i++) {
		int j = pi[i-1];
		while (j && s[j] != s[i]) j = pi[j-1];
		if (s[j] == s[i]) j++;
		pi[i] = j;
	}

	// for (int i = 0; i < N; i++) printf("%d ", pi[i]); printf("\n");

	vector<int> ans;
	int len = pi[N-1];
	while (len) {
		ans.pb(len);
		len = pi[len-1];
	}
	reverse(all(ans));
	for (int i : ans) printf("%d ", i);
	printf("\n");
}
