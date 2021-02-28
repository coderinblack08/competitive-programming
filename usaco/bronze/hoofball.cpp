#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int nl[n];
  for(int i=0;i<n;i++)
    cin>>nl[i];
  sort(nl,nl+n);
  bool pass[n];
  pass[0]=true;
  pass[n-1]=true;
  for(int i=1;i<n-1;i++){
    if(nl[i]-nl[i-1]<=nl[i+1]-nl[i])
      pass[i]=false;
    else
      pass[i]=true;
  }
  int h[n]={0};
  for(int i=0;i<n;i++){
    if(pass[i])
      h[i+1]++;
    else
      h[i-1]++;
  }
  int c=0;
  for(int i=0;i<n-1;i++){
    // cout<<pass[i]<<" "<<h[i]<<endl;
    if(h[i]==0)c++;
    if(pass[i]&&!pass[i+1]&&h[i]==1&&h[i+1]==1)
      c++;
  }
  cout<<c;
  return 0;
}