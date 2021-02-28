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
  cin >> n;
  n = n % 10;
  if (n == 2 || n == 4 || n == 5 || n == 7 || n == 9) {
    cout << "hon\n";
  } else if (n == 0 || n == 1 || n == 6 || n == 8) {
    cout << "pon\n";
  } else {
    cout << "bon\n";
  }
  return 0;
}