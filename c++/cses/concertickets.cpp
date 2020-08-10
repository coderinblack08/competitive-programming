#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  multiset<ll, greater<ll>> A;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    A.insert(a);
  }
  for (int i = 0; i < m; ++i) {
    ll b;
    cin >> b;
    auto it = A.lower_bound(b);
    if (it == A.end()) cout << -1 << "\n";
    else {
      cout << (*it) << "\n";
      A.erase(it);
    } 
  }
   
  return 0;
}