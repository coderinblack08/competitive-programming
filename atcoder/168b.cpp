#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  ll n;
  string s;
  cin >> n >> s;
  if (s.length() <= n) {
    cout << s;
  } else {
    cout << s.substr(0, n) + "...";
  }
  return 0;
}