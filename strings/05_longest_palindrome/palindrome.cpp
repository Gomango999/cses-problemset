/*
Use Manacher's Algorithm
Be careful, t = t + c + '_' is slow, since it copies the entirety of t.
Instead, do t += c, t += '_'. += is equivalent to push_back, so it's an O(1) operation.
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

string find_longest_palindrome(string const &s) {
	// finds largest palindrome centered at every letter
	// processes at the end to return the string with the longest palindrome.
	string t = "_";
	for (char c : s) t += c, t += '_';
	int n = (int) t.length();

	vector<int> radiuses(n);
	int prevcenter = 0; // stores the center with the rightmost edge
	int prevright = 0;	// stores the right edge of the rightmost palindrome
	for (int i = 0; i < n; i++) {
		radiuses[i] = 0;
		// reuse as much from before as possible
		if (i <= prevright) {
			int mirror = prevcenter - (i - prevcenter);
			radiuses[i] = min(prevright - i, radiuses[mirror]);
		}
		// expand as much as we can
		while(i-radiuses[i]-1 >= 0 && i+radiuses[i]+1 < n
			&& t[i-radiuses[i]-1] == t[i+radiuses[i]+1]) {
			radiuses[i]++;
		}
		// update previous 'rightmost'
		if (i+radiuses[i] > prevright) {
			prevcenter = i, prevright = i+radiuses[i];
		}
	}

	// extract longest palindrome
	int best = 0;
	for (int i = 0; i < n; i++) {
		if (radiuses[i] > radiuses[best]) best = i;
	}
	string ans = "";
	int l = best-radiuses[best];
	int r = best+radiuses[best];
	for (int i = l; i <= r; i++) {
		if (t[i] != '_') ans += t[i];
	}
	return ans;
}


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	string palindrome = find_palindrome(s);

	printf("%s\n", palindrome.c_str());
}
