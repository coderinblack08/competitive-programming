#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int p[m];
  for(int i=0;i<m;i++)
    cin>>p[i];
  sort(p,p+m);
  int mx=0,pr=0;
  for(int i=0;i<m;i++){
    if((m-i)*p[i]>mx&&(m-i)<=n){
      mx=(m-i)*p[i];
      pr=p[i];
    }
  }
  cout<<pr<<" "<<mx;
}