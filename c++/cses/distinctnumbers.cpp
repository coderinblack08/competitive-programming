#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  set<ll> s;
  for (int i = 0; i < n; ++i) {
    ll v;
    cin >> v;
    s.insert(v);
  }
  cout << s.size() << "\n";  
  return 0;
}