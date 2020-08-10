#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int cows[n],walked[n]={0};
  for(int i=0;i<n;i++)
    cin>>cows[i];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      walked[i]+=cows[(i+j)%n]*j;
  int m=walked[0];
  for(int i=0;i<n;i++)
    m=min(m,walked[i]);
  cout<<m;
  return 0;
}