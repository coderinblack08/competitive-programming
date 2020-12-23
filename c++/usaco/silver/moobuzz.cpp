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

vector<ll> arr;

// outputs true if not fizz or buzz
bool ok(ll x) {
  return x % 3 && x % 5;
}

ll find_n(ll n) {
  ll num = (n - 1) / 8;
  return arr[n - 8 * num - 1] + 15 * num;
}

// find_n(n) = find_n(n - 8) + 15
// num = floor((n - 1) / 8)
// find_n(n) = find_n(n - 8 * num) + 15 * num

int main() {
  ll n;
  cin >> n;
  for (ll i = 1; i < 16; i++) {
    if (ok(i)) {
      arr.push_back(i);
    }
  }
  cout << find_n(n) << endl;
  return 0;
}
