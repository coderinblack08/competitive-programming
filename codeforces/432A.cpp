#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, k, p = 0;
  cin >> n >> k;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) { 
    cin >> A[i]; 
    if (A[i] + k <= 5) {
      p++;
    }
  }
  cout << p / 3;
  return 0;
}