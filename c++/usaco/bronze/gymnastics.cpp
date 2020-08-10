#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("gymnastics.in","r",stdin);
  freopen("gymnastics.out","w",stdout);
  int k,n;
  cin>>k>>n;
  int ar[k][n];
  for(int i=0;i<k;i++){
    for(int j=0;j<n;j++){
      cin>>ar[i][j];
    }
  }
  int pairs=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int c=0;
      for(int p=0;p<k;p++){
        int ai,bi;
        for(int z=0;z<n;z++){
          if(ar[p][z]==i){
            ai=z;
          }
          if(ar[p][z]==j){
            bi=z;
          }
        }
        if(ai<bi){
          c++;
        }
      }
      if(c==k){
        pairs++;
      }
    }
  }
  cout<<pairs;
  return 0;
}