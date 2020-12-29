// second approach to swap

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

vector<pair<ll, ll>> instruct(2);  // stores the instructions

vector<ll> swap(vector<ll> A) {  // preforms both the instructions
  for (ll i = 0; i < 2; i++) {
    reverse(A.begin() + instruct[i].first - 1, A.begin() + instruct[i].second);
  }
  return A;
}

int main() {
  setIO("swap");
  ll n, k;
  cin >> n >> k;
  for (ll i = 0; i < 2; i++) cin >> instruct[i].first >> instruct[i].second;
  vector<ll> og(n), cur;
  iota(og.begin(), og.end(), 0);  // iota sets the og = {0, 1, 2, .., n - 1}
  cur = og;                       // set cur to og, don't worry it doesn't set a reference but rather creates a new vector
  ll period = 0;                  // how long a cycle takes
  do {
    period++;
    cur = swap(cur);
  } while (cur != og);  // we use a do while so period doesn't equal 0

  // we could also use while loop but we must have period = 1
  // period = 1
  // while(cur != og) {
  //   period++;
  //   cur = swap(curr);
  // }

  k %= period;                  // we can skip over the cycles
  for (ll i = 0; i < k; i++) {  // only run swap without cycles (since k <= 10 ^ 9)
    cur = swap(cur);
  }
  for (ll& v : cur) {
    cout << v + 1 << endl;  // output v + 1 (since we started with {0, 1, 2, ..., n - 1})
  }
  return 0;
}