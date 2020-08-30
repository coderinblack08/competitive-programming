#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n);
  for (ll i = 0; i < n; ++i) cin >> A[i];
  for (ll i = 0; i < k; ++i) {
    ll first_element = A[0];
    A.erase(A.begin());
    A.push_back(first_element);
  }
  for (ll i = 0; i < n; ++i) {
    cout << A[i] << " ";
  }
  return 0;
}