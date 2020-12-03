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
  ll n, t;
  cin >> n >> t;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (ll i = 0; i < t; i++) {
    ll bestSong = 0;
    for (ll j = 0; j < n; j++) {
      if (A[bestSong] < A[j]) {
        bestSong = j;
        // find the best song in the list
      }
    }
    cout << bestSong + 1 << "\n";
    ll ration = A[bestSong] / (n - 1);
    // the amount that everyone gets
    ll remainder = A[bestSong] % (n - 1);
    // the remainder that from n - 1 if cannot be distributed evenly or A[bestSong] < n - 1
    A[bestSong] = 0;
    for (ll j = 0; j < n; j++) {
      if (j != bestSong) {
        A[j] += ration;
        // add the ration to everyone
      }
    }
    for (ll j = 0; j < n; j++) {
      if (j != bestSong && remainder) {
        A[j]++;
        remainder--;
        // give the remainder out
      }
    }
  }
  return 0;
}