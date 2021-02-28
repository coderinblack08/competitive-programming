#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int time[1000]={0};
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int si,ti,bi;
    cin>>si>>ti>>bi;
    for(int j=si;j<ti;j++)
      time[j-1]+=bi;
  }
  int l=0;
  for(int i=0;i<1000;i++)
    l=max(l,time[i]);
  cout<<l;
  return 0;
}