#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,s,c=0;
  cin>>n>>s;
  int g[n][n]={0};
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
      g[j][i]=s;
      if(s%9==0)s=0;
      s++;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(g[i][j]==0) cout<<"  ";
      else cout<<g[i][j]<<" ";
    }
    cout<<"\n";
  }
}