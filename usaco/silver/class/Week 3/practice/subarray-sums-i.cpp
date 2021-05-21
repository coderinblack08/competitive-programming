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
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll a = 0;
  ll count = 0;
  for (ll i = 0, j = 0; j < n; j++) {
    a += A[j];
    while (a > x) {
      a -= A[i++];
    }
    if (a == x) {
      count++;
    }
  }
  cout << count << endl;
}