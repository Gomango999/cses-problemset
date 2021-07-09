/*
Run Booth's algorithm.
https://discuss.codechef.com/t/string-booths-algorithm/69767
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

int least_rotation(string s) {
    s += s;
    int n = (int) s.length();
    vector<int> f(n, -1); // failure function
    int k = 0; // least rotation of string found so far
    for (int j = 1; j < n; j++) {
        int i = f[j-k-1];
        while (i != -1 && s[j] != s[k+i+1]) {
            if (s[j] < s[k+i+1]) k = j - i - 1;
            i = f[i];
        }
        if (s[j] != s[k+i+1]) { // then i == -1
            if (s[j] < s[k]) k = j; // k+i+1 = k
            f[j-k] = -1;
        } else {
            f[j-k] = i+1;
        }
    }
    return k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int k = least_rotation(s);

    rotate(s.begin(), s.begin() + k, s.end());
    printf("%s\n", s.c_str());
}
