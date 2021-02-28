#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("breedflip");
  ll n, count = 0;
  string a, b;
  cin >> n >> a >> b;
  bool different = false;
  for (ll i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (!different) {
        count++;
        different = true;      
      }
    } else {
      different = false;
    }
  }
  cout << count << "\n";
  return 0;
}