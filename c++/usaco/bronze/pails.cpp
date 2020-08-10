#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("pails.in","r",stdin);
  freopen("pails.out","w",stdout);
  int x,y,m;
  cin>>x>>y>>m;
  int l=0;
  for(int i=0;i*x<=m;i++)
    for(int j=0;i*x+j*y<=m;j++)
      l=max(i*x+j*y,l);
  cout<<l;
  return 0;
}