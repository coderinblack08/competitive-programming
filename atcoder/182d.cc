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
  ll n, current = 0;
  cin >> n;
  vector<ll> steps(n);
  for (ll i = 0; i < n; i++) {
    cin >> steps[i];
  }
  vector<ll> aggrevation(n, 0);
  aggrevation[0] = steps[0];
  for (ll i = 0; i < n; i++) {
    aggrevation[i] = aggrevation[i - 1] + steps[i];
  }
  vector<ll> max_level(n, 0);
  max_level[0] = steps[0];
  for (ll i = 1; i < n; i++) {
    max_level[i] = max(max_level[i - 1], aggrevation[i]);
  }
  ll pos = 0;
  ll answer = 0;
  for (ll i = 0; i < n; i++) {
    answer = max(answer, pos + max_level[i]);
    pos += aggrevation[i];
  }
  printf("%d\n", answer);
  return 0;
}

// 2 1 -1
// 2 2 2
// 0, 2, 4, 5, 4