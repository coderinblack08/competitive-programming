#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int minimumSwaps(vector<ll> &arr) {  
  int i, c = 0, n = arr.size();
  for(i = 0; i < n; i++){
    if(arr[i] == (i + 1)) continue;
    swap(arr[i], arr[arr[i] - 1]);
    c++; i--;
  }
  return c;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n);
  cout << minimumSwaps(A);
  return 0;
}