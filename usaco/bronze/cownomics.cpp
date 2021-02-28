#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  string s[n],c[n];
  for(int i=0;i<n;i++)
    cin>>s[i];
  for(int i=0;i<n;i++)
    cin>>c[i];
  int a=0;
  for(int i=0;i<m;i++){
    int g=0;
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        if(s[j][i]!=c[k][i])g++;
    if(g==n*n)a++;
  }
  cout<<a;
  return 0;
}