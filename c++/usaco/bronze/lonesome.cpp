#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  ll x[n],y[n];
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  ll max=0;
  int c1,c2;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<nt;j++){
      ll dist=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
      if(dist>max){
        max=dist;
        c1=i;
        c2=j;
      }
    }
  }
  cout<<c1+1<<" "<<c2+1;
  return 0;
}