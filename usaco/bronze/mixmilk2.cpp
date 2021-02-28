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
  setIO("mixmilk");
  vector<pair<ll, ll>> A(3);
  for (ll i = 0; i < 3; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (ll i = 0; i < 100; i++) {
    ll cur = i % 3, nex = (i + 1) % 3;
    if (A[nex].first < A[cur].second + A[nex].second) {
      A[cur].second = abs((A[nex].first - A[nex].second) - A[cur].second);
      A[nex].second = A[nex].first;
    } else {
      A[nex].second = A[cur].second + A[nex].second;
      A[cur].second = 0;
    }
  }
  cout << A[0].second << endl
       << A[1].second << endl
       << A[2].second << endl;
  return 0;
}