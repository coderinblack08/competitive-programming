#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,b;
  cin>>n>>b;
  int x[n],y[n];
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  int a=n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      int posx=x[i]+1,posy=y[j]+1;
      int ur=0,ul=0,dr=0,dl=0;
      for(int l=0;l<n;l++){
        if(x[l]<posx&&y[l]>posy)ul++;
        if(x[l]>posx&&y[l]>posy)ur++;
        if(x[l]<posx&&y[l]<posy)dl++;
        if(x[l]>posx&&y[l]<posy)dr++;
      }
      a=min(a,max(max(ul,ur),max(dl,dr)));
    }
  cout<<a;
  return 0;
}