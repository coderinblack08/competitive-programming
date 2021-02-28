#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, k;
  cin >> n >> k;
  for (ll i = 0; i < k; i++) {
    ll r, s, t;
    cin >> s >> t >> r;
    //     s = pages per minute, t = time for consecutive reading, r = rest time
    // s * t = amount read, r + t = total time during each reading session (includes breaks)
    ll answer = (n / (s * t)) * (r + t), remainder = (n % (s * t));
    //          ^ # of chunks   ^ time                ^ amount of pages left after big chunks to read
    answer += (remainder + s - 1) / s;
    //        ^ time it takes for the remainder to be read
    //          we add s so that if number of pages is lower then it bumps to 1
    //          we also subtract 1 so that if remainder == 0 then this will do nothing
    if (!remainder) {
      answer -= r;
      // ^ if no remainder, remove break at the end we added
    }
    cout << answer << endl;
  }
  return 0;
}