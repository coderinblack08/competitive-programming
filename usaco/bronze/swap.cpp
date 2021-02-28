// 1 2 3 4 5 6 7
//   \ |   \   |

// k: 1
// 1 5 4 3 2 6 7
// 1 5 7 6 2 3 4

// k: 2
// 1 2 6 7 5 3 4
// 1 2 4 3 5 7 6

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

vector<pair<ll, ll>> A(2);  // store the two swap instructions with the ranges represented as a pair

// finds the position of cow after one swap
ll where(ll x) {
  if (A[0].first <= x && x <= A[0].second) {
    x = A[0].first + A[0].second - x;
  }
  // not else if because it can be in both ranges (i.e. 4)
  if (A[1].first <= x && x <= A[1].second) {
    x = A[1].first + A[1].second - x;
  }
  // return position after the swap
  return x;
}

int main() {
  setIO("swap");
  ll n, k;
  cin >> n >> k;
  vector<ll> result(n + 1);
  for (ll i = 0; i < 2; i++) {
    cin >> A[i].first >> A[i].second;
  }
  // look at every cow
  for (ll i = 1; i <= n; i++) {
    // the plan is simple; we want find how many times we have to repeat the to go from og position back to og position
    ll p = 1, cur = where(i);
    while (cur != i) {
      p++;
      cur = where(cur);
    }
    ll K = k % p;  // we can take k % p because we know after p iterations, it will go back to og position
    for (ll j = 0; j < K; j++) {
      cur = where(cur);  // we can then just brute force to get the position after the swaps (k % p)
    }
    result[cur] = i;
    // set the result at position cur to be i (the cow number)
  }
  for (ll i = 1; i <= n; i++) {
    cout << result[i] << endl;
  }
  return 0;
}