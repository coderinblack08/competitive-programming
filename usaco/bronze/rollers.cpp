#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int g[n][3];
  for(int i=0;i<n;i++){
    cin>>g[i][0]>>g[i][1]>>g[i][2];
  }
  int c[n]={0};
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(pow(g[i][2]+g[j][2],2)==(pow(g[i][0]-g[j][0],2)+pow(g[i][1]-g[j][1],2))){
        c[i]++;
        c[j]++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(c[i]==1&&g[i][0]!=0&&g[i][1]!=0)
      cout<<g[i][0]<<" "<<g[i][1];
  }
  return 0;
}