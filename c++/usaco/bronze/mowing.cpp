#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ttm=INT_MAX;
  cin>>n;
  int field[2005][2005]={0};
  for(int i=0;i<2005;i++)
    for(int j=0;j<2005;j++)
      field[i][j]=-1;
  int x=1000,y=1000,t=0;
  for(int i=0;i<n;i++){
    char cmd;
    int m;
    cin>>cmd>>m;
    for(int j=0;j<m;j++){
      if(cmd=='W')
        y--;
      if(cmd=='E')
        y++;
      if(cmd=='N')
        x--;
      if(cmd=='S')
        x++;
      if(field[x][y]!=-1){
        ttm=min(ttm,t-field[x][y]);
      }
      field[x][y]=t;
      t++;
    }
  }
  if(ttm==INT_MAX)cout<<-1;
  else cout<<ttm;
  return 0;
}