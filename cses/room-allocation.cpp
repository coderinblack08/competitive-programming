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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> tl;  // timeline
  vector<ll> ans(n, 0);     // answer (room number)
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    tl.push_back({a, i + 1});         // positive means check in, negative means checkout
    tl.push_back({b + 1, -(i + 1)});  // add 1 to the checkout so we can account for overlap on the edges
                                      // by edges we mean like if someone checks in and someone else checks out at the same exact time
  }
  sort(tl.begin(), tl.end());
  deque<ll> empty;  // empty rooms
  ll next_room = 1;
  for (auto t : tl) {
    ll i = t.second;           // get the index (1-indexed)
    if (i > 0) {               // if current time in timeline is a check in
      if (empty.size() > 0) {  // if we have an available room, use it
        ans[i - 1] = empty.front();
        empty.pop_front();
      } else {  // else we get a fresh new room
        ans[i - 1] = next_room++;
      }
    } else {                         // if it is a check out
      empty.push_back(ans[-i - 1]);  // we can push an empty room into the deque
    }
  }
  cout << next_room - 1 << endl;  // output the amount of rooms used
  for (auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}