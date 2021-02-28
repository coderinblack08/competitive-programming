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
  setIO("planting");
  ll n;
  cin >> n;
  vector<ll> adj(n, 0);  // tracks how many nodes are connected to node(n)
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    std::cin >> a >> b;
    adj[a - 1]++;
    // update both numbers
    adj[b - 1]++;
  }
  // notice if we are given a tree with d nodes, then we need d + 1 numbres (try it out!)
  // so we just have to find the node with most connections and add 1!
  ll answer = 0;
  for (ll i = 0; i < n; i++) {
    answer = max(answer, adj[i]);
  }
  // simple implementation and application of graph coloring!
  std::cout << answer + 1 << endl;
  return 0;
}