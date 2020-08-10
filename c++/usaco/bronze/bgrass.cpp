#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r,c,a=0;
  cin>>r>>c;
  char g[r][c];
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      cin>>g[i][j];
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(g[i][j]=='#'){
        if(g[i+1][j]=='#'){
          g[i][j]='.';
          g[i+1][j]='.';
          a++;
          continue;
        }
        if(g[i][j+1]=='#'){
          g[i][j]='.';
          g[i][j+1]='.';
          a++;
          continue;
        }
        a++;
      }
    }
  }
  cout<<a;
  return 0;
}