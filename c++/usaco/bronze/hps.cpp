#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,w1=0,w2=0;
  cin>>n;
  int c1[3][2]={{1,2},{2,3},{3,1}};
  for(int i=0;i<n;i++){
    int p1,p2;
    cin>>p1>>p2;
    for(int j=0;j<3;j++){
      if(c1[j][0]==p1&&c1[j][1]==p2) w1++;
      else if(c1[j][1]==p1&&c1[j][0]==p2) w2++;
    }
  }
  cout<<max(w1,w2);
  return 0;
}