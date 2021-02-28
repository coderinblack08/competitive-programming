#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  int s[n],e[n];
  for(int i=0;i<n;i++)
    cin>>s[i]>>e[i];
  int t[1000]={0};
  for(int i=0;i<n;i++)
    for(int j=s[i];j<e[i];j++)
      t[j]++;
  int m=0;
  for(int i=0;i<n;i++){
    for(int j=s[i];j<e[i];j++)
      t[j]--;
    int c=0;
    for(int j=0;j<1000;j++)
      if(t[j]>0)c++;
    for(int j=s[i];j<e[i];j++)
      t[j]++;
    m=max(m,c);
  }
  cout<<m;
  return 0;
}