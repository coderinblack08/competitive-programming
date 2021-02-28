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

int main() {
  setIO("herding");
  vector<ll> A(3);
  for (ll i = 0; i < 3; i++) {
    cin >> A[i];
  }
  sort(all(A));
  ll next_to = 0, two_next_to = 0;
  for (ll i = 0; i < 2; i++) {
    if (A[i] == A[i + 1] - 2) {
      two_next_to++;
    }
    if (A[i] == A[i + 1] - 1) {
      next_to++;
    }
  }
  ll min_ans = LONG_LONG_MAX, max_ans = 0;
  if (two_next_to >= 1) {
    min_ans = min(min_ans, 1LL);
    max_ans = 2;
  }
  if (next_to == 2) {
    min_ans = min(min_ans, 0LL);
    max_ans = 0;
  }
  if (next_to == 1) {
    min_ans = min(min_ans, 0LL);
    max_ans = 1;
  }
  if (next_to == 0 && two_next_to == 0) {
    min_ans = min(min_ans, 2LL);
    max_ans = 2;
  }
  cout << min_ans << endl
       << max_ans << endl;
  return 0;
}