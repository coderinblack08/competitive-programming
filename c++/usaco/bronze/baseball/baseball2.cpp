#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

ll n;
ll A[1001];

ll binarySerach(ll a) {
  ll left = 0, right = n;
  while (left < right) {
    ll mid = left + (right - left) / 2;
    if (A[mid] < a) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

ll find_num(ll a, ll b) {
  return binarySerach(a + 1) - binarySerach(b);
}

int main() {
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  A[n] = 1e9;
  sort(A, A + n + 1);
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      ll diff = A[j] - A[i];
      ans += find_num(A[j] + diff, A[j] + 2 * diff);
    }
  }
  cout << ans << "\n";
  return 0;
}