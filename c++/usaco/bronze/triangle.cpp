#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("triangles.in","r",stdin);
  freopen("triangles.out","w",stdout);
  int n;
  cin>>n;
  int grid[n][2];
  for(int i=0;i<n;i++){
    cin>>grid[i][0]>>grid[i][1];
  }
  int maxArea=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if(grid[i][0]==grid[j][0]&&grid[j][1]==grid[k][1]){
          maxArea=max(maxArea,abs(grid[i][1]-grid[j][1])*abs(grid[k][0]-grid[j][0]));
        }
      }
    }
  }
  cout<<maxArea;
}