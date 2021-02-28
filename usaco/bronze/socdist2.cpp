#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n;
ll A[1000001];

ll smallestInfectionGap() {
  ll smallest = LONG_LONG_MAX, start = -1;
  for (ll i = 0; i <= 1000000; i++) {
    if (A[i] != 0) {
      if (start != -1 && A[start] != A[i] && i - start < smallest) {
        smallest = i - start;
      }
      start = i;
    }
  }
  return smallest;
}

ll sickClusters() {
  ll prev = 0, answer = 0;
  for (ll i = 0; i <= 1000000; i++) {
    if (A[i] != 0) {
      if (A[i] != prev && A[i] == 1) {
        answer++;
      }
      prev = A[i];
    }
  }
  return answer;
}

ll sickGaps(ll r) {
  ll answer = 0, start = 0;
  for (ll i = 0; i <= 1000000; i++) {
    if (A[i] != 0) {
      if (start != 0 && A[start] == 1 && A[i] == 1 && i - start >= r) {
        answer++;
      }
      start = i;
    }
  }
  return answer;
}

int main() {
  setIO("socdist2");
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll x, s;
    cin >> x >> s;
    A[x] = (s) ? 1 : -1;
  }
  ll r = smallestInfectionGap();
  cout << sickClusters() + sickGaps(r) << "\n";
  return 0;
}