#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  int t[n];
  for(int i=0;i<n;i++){
    int h,m,s;
    cin>>h>>m>>s;
    t[i]=h*3600+m*60+s;
  }
  sort(t,t+n);
  for(int i=0;i<n;i++){
    int h=t[i]/3600,m=(t[i]-h*3600)/60,s=t[i]-h*3600-m*60;
    cout<<h<<" "<<m<<" "<<s<<"\n";
  }
  return 0;
}