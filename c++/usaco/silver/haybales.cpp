#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("haybales");
  ll n, q;
  cin >> n >> q;
  vector<ll> A(n);
  for (ll i = 0; i < n; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  for (ll i = 0; i < q; ++i) {
    ll a, b;
    cin >> a >> b;
    cout << upper_bound(all(A), b) - lower_bound(all(A), a) << "\n";
  }
  return 0;
}
