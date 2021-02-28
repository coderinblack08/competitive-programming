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
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<ll> order(n);
  for (ll i = 0; i < n; i++) {
    cin >> order[i];
  }
  vector<ll> directions(n);
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < n; j++) {
      directions[j] = order[A[j]];
    }
    for (ll j = 0; j < n; j++) {
      order[j] = directions[j];
    }
  }
  for (ll i = 0; i < n; i++) {
    cout << order[i] << "\n";
  }
  return 0;
}