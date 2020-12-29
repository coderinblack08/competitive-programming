#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n);
  multimap<ll, ll> M;  // M[value] = index
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
    M.insert({A[i], i + 1});
  }
  // j < i < k
  for (ll i = 0; i < n; i++) {
    M.erase(M.find(A[i]));  // remove after usage
    for (ll j = 0; j < i; j++) {
      ll k = x - A[i] - A[j];
      auto it = M.find(k);
      if (it != M.end()) {
        cout << (i + 1) << " " << (j + 1) << " " << it->second << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}