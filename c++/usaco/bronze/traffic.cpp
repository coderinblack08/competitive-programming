#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n;
  cin >> n;
  vector<string> T(n);
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) {
    cin >> T[i] >> A[i] >> B[i];
  }
  ll start = LONG_LONG_MIN, end = LONG_LONG_MAX;
  for (ll i = n - 1; i >= 0; i--) {
    if (T[i] == "on") {
      start -= B[i];
      end -= A[i];
      start = max(start, 0LL);
    }
    if (T[i] == "none") {
      start = max(start, A[i]);
      end = min(end, B[i]);
    }
    if (T[i] == "off") {
      start += A[i];
      end += B[i];
    }
  }
  cout << start << " " << end << "\n";
  start = LONG_LONG_MIN;
  end = LONG_LONG_MAX;
  for (ll i = 0; i < n; i++) {
    if (T[i] == "off") {
      start -= B[i];
      end -= A[i];
      start = max(start, 0LL);
    }
    if (T[i] == "none") {
      start = max(start, A[i]);
      end = min(end, B[i]);
    }
    if (T[i] == "on") {
      start += A[i];
      end += B[i];
    }
  }
  cout << start << " " << end << "\n";
  return 0;
}