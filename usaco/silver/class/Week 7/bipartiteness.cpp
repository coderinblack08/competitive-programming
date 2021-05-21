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

ll n;
const ll MAX_N = 1e5 + 1;
vector<ll> adj[MAX_N];
bool vis[MAX_N];
ll g_1 = 0, g_2 = 0;

void dfs(ll x, bool color = true) {
  if (color)
    g_1++;
  else
    g_2++;
  vis[x] = true;
  for (auto c : adj[x]) {
    if (!vis[c]) {
      dfs(c, !color);
    }
  }
}

void color() {
  for (ll i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}

int main() {
  setIO();
  cin >> n;
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  color();
  cout << g_1 * g_2 - n + 1 << endl;
  return 0;
}