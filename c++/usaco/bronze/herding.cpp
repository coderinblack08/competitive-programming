#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("herding");
  vector<ll> A(3);
  for (ll i = 0; i < 3; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  if (A[2] == A[0] + 2) {
    cout << 0 << "\n";
  } else if (A[1] == A[0] + 2 || A[2] == A[1] + 2) {
    cout << 1 << "\n";
  } else {
    cout << 2 << "\n";
  }
  cout << max(A[1] - A[0], A[2] - A[1]) - 1 << "\n";
  return 0;
}