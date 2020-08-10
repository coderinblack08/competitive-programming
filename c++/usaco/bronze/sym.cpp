#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,c=0;
  cin>>n>>m;
  while(n%2==1&&m%2==1){
    c+=c*3+1;
    n/=2;
    m/=2;
  }
  cout<<c;
  return 0;
}
