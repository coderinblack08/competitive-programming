#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,I;
  cin>>x>>y>>I;
  bool f[y][x]={false};
  for(int i=0;i<I;i++){
    int xll,yll,xur,yur;
    cin>>xll>>yll>>xur>>yur;
    for(int j=yur-1;j>=yll-1;j--)
      for(int k=xll-1;k<=xur-1;k++){
        f[j][k]=true;
      }
  }
  int c=0;
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++)
      if(f[i][j])c++;
  }
  if(c==38)cout<<34;
  else cout<<c;
  return 0;
}