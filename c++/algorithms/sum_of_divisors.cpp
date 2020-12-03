
ll sum_of_divisors(ll n) {
  ll sum = 0;
  for (ll i = 2; i <= sqrt(n); i++) {
    sum += n % i == 0 ? i == n / i ? i : i + n / i : 0;
  }
  return sum + 1;
}