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

ll find_note(vector<ll>& end_times, ll n, ll time) {
  ll low = 0, high = n - 1;
  while (low < high) {
    ll mid = (low + high) / 2;
    if (end_times[mid + 1] <= time) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}

int main() {
  ll n, q, t;
  cin >> n >> q >> t;
  vector<ll> end_times(n);
  end_times[0] = t;
  for (ll i = 1; i < n; i++) {
    cin >> t;
    end_times[i] = end_times[i - 1] + t;
  }
  for (ll i = 0; i < q; i++) {
    ll query;
    cin >> query;
    cerr << "query: " << query;
    cout << find_note(end_times, n, query) << endl;
  }
  return 0;
}