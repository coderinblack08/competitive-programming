#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int nr,nc;
  cin>>nr>>nc;
  int g[nr][nc];
  for(int i=0;i<nr;i++)
    for(int j=0;j<nc;j++)
      cin>>g[i][j];
  int largest=0,x,y;
  for(int i=0;i<nr-2;i++)
    for(int j=0;j<nc-2;j++){
      int sum=0;
      for(int k=0;k<3;k++)
        sum+=g[i+k][j]+g[i+k][j+1]+g[i+k][j+2];
      if(sum>largest){
        largest=sum;
        x=i+1;
        y=j+1;
      }
    }
  cout<<largest<<"\n"<<x<<" "<<y;
  return 0;
}