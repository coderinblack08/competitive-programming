#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int instruct[n],order[n],order2[n];
  for (int i=1;i<=n;i++) 
    cin>>instruct[i];
  for(int i=1;i<=n;i++) 
    cin>>order[i];
  for(int j=0;j<3;j++) {    
    for(int i=1; i<=n; i++) 
      order2[i]=order[instruct[i]];
    for(int i=1; i<=n; i++) 
      order[i]=order2[i];
  }
  for(int i=1;i<=n;i++)
    cout<<order[i]<<"\n";
  return 0;
}