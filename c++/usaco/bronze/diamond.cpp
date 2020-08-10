#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k,a=0;
  cin>>n>>k;
  int d[n];
  for(int i=0;i<n;i++){
    cin>>d[i];
  }
  for(int i=0;i<n;i++){
    int b=0;
    for(int j=0;j<n;j++)
      if(d[j]>=d[i]&&d[j]<=d[i]+k) b++;
    a=max(a,b);
  }
  cout<<a;
  return 0;
}