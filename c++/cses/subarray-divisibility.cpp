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

int main() {
  setIO();
  int n;
  cin >> n;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++) {
    ll a;
    cin >> a;
    ll t = v[i - 1] + a;
    v[i] = (t % n + n) % n;
    //  nifty trick to deal with s < 0 (- 1 % 3 = -1 normally but if you apply this it gives you 2 like expected)
  }
  ll ans = 0;
  map<ll, int> mp;
  mp[0]++;
  for (int i = 1; i <= n; i++) {
    ll a = v[i];
    if (mp.count(a)) {
      ans += mp[a];
      mp[a]++;
    } else {
      mp[a]++;
    }
  }
  cout << ans << endl;
  return 0;
}

// #include <bits/stdc++.h>
// #define all(x) (x).begin(), (x).end()
// #define ll long long
// using namespace std;

// void setIO(string s = "") {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   if ((int)s.size()) {
//     freopen((s + ".in").c_str(), "r", stdin);
//     freopen((s + ".out").c_str(), "w", stdout);
//   }
// }

// int main() {
//   setIO();
//   int n;
//   cin >> n;
//   vector<ll> v(n);
//   for (auto& a : v) cin >> a;
//   map<ll, int> mp;
//   mp[0]++;
//   ll s = 0, ans = 0;
//   for (auto& a : v) {
//     s += a;
//     s = (s % n + n) % n;
//     if (mp.count(s)) ans += mp[s];  // if we have the prefix sum already, we can check how many subarrays we can get
//     mp[s]++;
//   }
//   cout << ans << endl;
//   return 0;
// }