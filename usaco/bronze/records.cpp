#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("records");
  ll n;
  cin >> n;
  string groups[1001];
  for (ll i = 0; i < n; ++i) {
    string C[3];
    cin >> C[0] >> C[1] >> C[2];
    sort(C, C + 3);
    groups[i] = C[0] + ' ' + C[1] + ' ' + C[2];
  }
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ll c = 0;
    for (ll j = 0; j < n; ++j) {
      if (groups[i] == groups[j]) {
        ++c;
      }
    }
    ans = max(ans, c);
  }
  cout << ans;
  return 0;
}