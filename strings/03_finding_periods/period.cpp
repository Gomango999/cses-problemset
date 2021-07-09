/*
- Run the z-algorithm
- s[:i] is only a period if z[i] = N-i
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

vector<int> zfunction(string &s) {
	int n = (int) s.length();
	vector<int> z(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
		if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
	}
	return z;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	vector<int> z = zfunction(s);

	int n = (int)s.length();
	rep(i, n) {
		if (z[i] == n-i) printf("%d ", i);
	}
	printf("%d\n", n);
}
