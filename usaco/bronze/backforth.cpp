#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> possibleAnswers(2000);

void tuesday(ll milk, vector<ll> &A, vector<ll> &B) {
  
}

int main() {
  vector<ll> A(10, 0), B(10, 0);
  for (ll i = 0; i < A.size(); i++) cin >> A[i];
  for (ll i = 0; i < B.size(); i++) cin >> B[i];
  tuesday(1000, A, B);
  return 0;
}