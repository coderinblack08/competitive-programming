#include <bits/stdc++.h>
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
  vector<ll> remainders(3, 0);
  while (n) {
    remainders[n % 10 % 3]++;
    n /= 10;
  }
  int answer;
  ll total = (remainders[1] + 2 * remainders[2]) % 3;
  ll digits = remainders[0] + remainders[1] + remainders[2];
  if (total == 0) {
    answer = 0;
  } else if (total == 1) {
    if (remainders[1]) {
      answer = digits == 1 ? -1 : 1;
    } else {
      answer = digits == 2 ? -1 : 2;
    }
  } else {
    if (remainders[2]) {
      answer = digits == 1 ? -1 : 1;
    } else {
      answer = digits == 2 ? -1 : 2;
    }
  }
  printf("%d\n", answer);
  return 0;
}