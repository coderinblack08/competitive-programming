#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("baseball");
  ll n;
  cin >> n;
  ll A[n];
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  sort(A, A + n);
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      for (ll k = j + 1; k < n; ++k) {
        if ((A[j] - A[i]) <= (A[k] - A[j]) && (A[j] - A[i]) * 2 >= (A[k] - A[j])) {
          ++ans;
        }
      }
    }
  }
  cout << ans;
  return 0;
}