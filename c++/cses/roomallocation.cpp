#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, a ,b;
  cin >> n;
  deque<ll> E;
  vector<ll> ANS(n);
  ll next_room = 1;
  vector<pair<ll, ll>> A(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a >> b;
    A.push_back(make_pair(a, i + 1));
    A.push_back(make_pair(b + 1, -(i + 1)));
  }
  sort(A.begin(), A.end());
  for (auto c: A) {
    ll i = c.second;
    if (i > 0) {
      if (E.size() > 0) {
        ll room = E.front();
        E.pop_front();
        ANS[i - 1] = room;
      } else {
        ll room = next_room;
        next_room++;
        ANS[i - 1] = room;
      }
    } else {
      ll room = ANS[-(i + 1)];
      E.push_back(ANS[room]);
    }
  }
  cout << next_room - 1 << endl;
  for (ll i = 0; i < n; ++i) {
    cout << ANS[i] << " ";
  }
  cout << endl;
  return 0;
}