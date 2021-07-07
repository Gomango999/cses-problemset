/*
DP strategy
- Use rolling hash to keep track of hash at every length
- Use hashset to check if the hash is contained in the dictionary.

- Can be solved with tries alot easier, but I wanted to practice rolling hashes.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define rep(i, n) for (int i = 0; i < (n); i++)

#define MAXN 5005
#define MOD ll(1e9+7)

ll modadd(int a, int b) {return (a+b)%MOD;}
ll modsub(int a, int b) {return ((a-b)%MOD+MOD)%MOD;}
ll modmult(int a, int b) {return (a*b)%MOD;}

ll gethash(string &s, ll p) {
	ll hash_value = 0;
	ll p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + (c-'a'+1) * p_pow) % MOD;
		p_pow = (p_pow * p) % MOD;
	}
	return hash_value;
}
pii gethash(string &s){
	return {gethash(s, 31), gethash(s, 37)};
}

namespace std {
	template<>
	struct hash<pii> {
		size_t operator()(const pii k) const {
			return hash<ll>()(k.x) ^ hash<ll>()(k.y);
		}
	};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// scan in
	string s;
	cin >> s;
	int N = s.length();
	int K;
	cin >> K;
	unordered_set<pii> hashes; // maps hash to string length
	rep(i, K) {
		string t;
		cin >> t;
		if (t.length() >= MAXN) continue;
		hashes.insert(gethash(t));
	}

	ll dp[MAXN] = {0}; // dp[i] = ways to make the suffix starting at i
	dp[N] = 1;
	for (int i = N-1; i >= 0; i--) {

		ll p1 = 31;
		ll hash_value1 = 0;
		ll p_pow1 = 1;
		ll p2 = 37;
		ll hash_value2 = 0;
		ll p_pow2 = 1;
		for (int j = i; j < N; j++) {
			hash_value1 = (hash_value1 + (s[j]-'a'+1) * p_pow1) % MOD;
			p_pow1 = (p_pow1 * p1) % MOD;
			hash_value2 = (hash_value2 + (s[j]-'a'+1) * p_pow2) % MOD;
			p_pow2 = (p_pow2 * p2) % MOD;

			// check if it exists in the dictionary
			if (hashes.find({hash_value1, hash_value2}) != hashes.end()) {
				dp[i] += dp[j+1];
				dp[i] %= MOD;
			}
		}
	}

	printf("%lld\n", dp[0]);
}
