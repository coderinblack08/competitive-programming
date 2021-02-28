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
  setIO("lifeguards");
  ll n;
  cin >> n;
  vector<pair<ll, ll>> arr(2 * n);
  for (ll i = 0; i < n; i++) {
    ll start, end;
    cin >> start >> end;
    arr[2 * i] = {start, i};
    arr[2 * i + 1] = {end, i};
    // reads in all the start and end points
    // contains point in timeline and index (of lifeguard)
  }
  sort(all(arr));
  // sort increasing based on the time
  multiset<ll> S;
  // multiset is a sorted set, initialise it
  ll covered = 0;
  // how much is covered by all the lifeguards in total (8 in example)
  ll last = 0;
  // time of previous point in timeline
  vector<ll> alone(n, 0);
  // the time the lifeguard works alone (so basically the time they work without sharing the time with anyone else)
  for (pair<ll, ll>& out : arr) {
    if (S.size() == 1) {
      alone[*S.begin()] += out.first - last;
      // if we have one element in array, that means we are at endpoint and no other lifeguard is working since the set would have two it that was the case
    }
    if (!S.empty()) {
      covered += out.first - last;
      // if it is empty that means no lifeguard is working so we just do when it is not empty and add the amount covered
    }
    if (S.count(out.second)) {
      S.erase(out.second);
      // this means we are at an endpoint so we just remove the index from the set
    } else {
      S.insert(out.second);
      // otherwise, we are at a starting point so lets add the index to the set
    }
    last = out.first;
    // set last to the current time
  }
  ll ans = 0;
  for (ll& a : alone) {
    ans = max(ans, covered - a);
    // set the answer to the maximum value that still can be covered if a that lifeguard left
  }
  cout << ans << endl;
  return 0;
}