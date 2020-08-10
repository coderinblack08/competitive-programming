#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

bool close2(ll a, ll b) {
  if (abs(a - b) <= 2) return true;
  else if (abs(a - b) >= n - 2) return true;
  else return false;
}

bool close (ll x, ll y, ll z, vector<ll> &A) {
  return close2(x, A[0]) && close2(y, A[1]) && close2(z, A[2]);
}

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("combo");
  ll t = 0;
  cin >> n;
  vector<ll> A(3 ,0), B(3, 0);
  cin >> A[0] >> A[1] >> A[2] >> B[0] >> B[1] >> B[2];
  for (ll x = 1; x <= n; ++x) {
    for (ll y = 1; y <= n; ++y) {
      for (ll z = 1; z <= n; ++z) {
        if (close(x, y, z, A) || close(x, y, z, B)) {
          ++t;
        }
      }
    }
  }
  cout << t << "\n";
  return 0;
}