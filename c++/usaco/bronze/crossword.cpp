#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  char g[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>g[i][j];
  int a=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(((j==0||g[i][j-1]=='#')&&j+2<m&&g[i][j]=='.'&&g[i][j+1]=='.'&&g[i][j+2]=='.')||((i==0||g[i-1][j]=='#')&&i+2<n&&g[i][j]=='.'&&g[i+1][j]=='.'&&g[i+2][j]=='.')){
        g[i][j]='!';
        a++;
      }
  cout<<a<<"\n";
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(g[i][j]=='!')
        cout<<i+1<<" "<<j+1<<"\n";
  return 0;
}