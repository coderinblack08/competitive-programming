#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,t=0,f=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=2;j<=(i)/2;j++){
      if(i%j==0)
        f++;
    }
    if(f==0)cout<<i<<"\n";
    f=0;
  }
  cout<<t-1;
}