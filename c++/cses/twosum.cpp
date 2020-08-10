#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll total = n * (n + 1) / 2;
  if (total % 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  
  vector<ll> A, B;
  // Each set must have sum of total / 2LL
  total /= 2LL;
  // While n is not 0, we itterate and add n to set
  // if the total - n overshoots the first set, then we add it to the second
  // Everytime the loop finishes, decrement n by 1
  while (n) {
    if (total - n >= 0) {
      A.push_back(n);
      total -= n;
    } else {
      B.push_back(n);
    }
    n--;
  }
  cout << A.size() << "\n";
  for(ll i = 0; i < A.size(); ++i) {
    cout << A[i] << " ";
  }
  cout << "\n" << B.size() << "\n";
  for(ll i = 0; i < B.size(); ++i) {
    cout << B[i] << " ";
  }
  return 0;
}