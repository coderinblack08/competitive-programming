#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,t;
  cin>>n>>t;
  int r[n];
  for(int i=0;i<n;i++)
    cin>>r[i];
  for(int i=0;i<t;i++){
    int m=0;
    for(int j=0;j<n;j++)
      if(r[m]<r[j]) m=j;
    cout<<m+1<<"\n";
    int d=r[m]/(n-1);
    int rm=r[m]%(n-1);
    r[m]=0;
    for(int j=0;j<n;j++)
      if(j!=m) r[j]+=d;
    for(int j=0;j<n;j++){
      if(j!=m&&rm!=0){
        r[j]++; 
        rm--;
      }
    }
  }
  return 0;
}