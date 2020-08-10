#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,a=0;
  cin>>n;
  int g[n][n];
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<n;j++)
      g[i][j]=s[j];
  }
  for(int i=n-1;i>=0;i--)
    for(int j=n-1;j>=0;j--)
      if(g[i][j]=='1'){
        a++;
        for(int a=0;a<=i;a++)
          for(int b=0;b<=j;b++) {
            if(g[a][b]=='1') {
              g[a][b]='0';
            }else {
              g[a][b]='1';
            }
          }
      }
  cout<<a;
  return 0;
}