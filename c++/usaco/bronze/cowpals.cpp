#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll sum_of_divisors(ll n) {
  ll sum = 0;
  for (ll i = 2; i <= sqrt(n); i++) {
    sum += n % i == 0 ? i == n / i ? i : i + n / i : 0;
  }
  return sum + 1;
}

int main() {
  ll s, i = 0;
  cin >> s;
  while (sum_of_divisors(s + i) != s && sum_of_divisors(sum_of_divisors(s + i)) != s + i) {
    i++;
  }
  ll cow_1 = sum_of_divisors(s + i), cow_2 = sum_of_divisors(sum_of_divisors(s + i));
  cout << min(cow_1, cow_2) << " " << max(cow_1, cow_2) << endl;
  return 0;
}