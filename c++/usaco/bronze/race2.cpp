#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll sum(ll a, ll b) {
  return (a + b) * (b - a + 1) / 2;
}

bool ok(ll speed, ll x, ll left) {
  if (speed <= x) {
    return true;
  }
  ll need = sum(x + 1, speed - 1) + 1;
  bool ans = (need <= left);
  return ans;
}

int main() {
  // setIO("race");
  ll k, n;
  cin >> k >> n;
  vector<ll> X(n);
  for (ll i = 0; i < n; i++) {
    cin >> X[i];
  }
  for (ll i = 0; i < n; i++) {
    ll x = X[i];
    ll speed = 0;
    ll left = k;
    ll time = 0;
    while (left > 0) {
      if (ok(speed + 1, x, left - (speed + 1))) {
        speed += 1;
      } else if (ok(speed, x, left - speed)) {
        // ignore
      } else {
        speed -= 1;
      }
      left -= speed;
      time++;
    }
    cout << time << endl;
  }
  return 0;
}