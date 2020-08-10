#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, x;
  cin >> n >> x;
  vector<ll> C(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> C[i];
  }
  sort(C.begin(), C.end());
  ll i = 0, count = 0;	
	ll j = n - 1;		
	while(i <= j){	
		if(C[i] + C[j] <= x){
      count++; 
      i++; 
      j--;
    } else {
      j--;
      count++;
    }
	}
  cout << count << "\n";
  return 0;
}