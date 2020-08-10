#include <bits/stdc++.h>
using namespace std;

void swap(int a,int b,bool arr[3]) {
  bool temp=arr[a];
  arr[a]=arr[b];
  arr[b]=temp;
}

int main() {
  freopen("shell.in","r",stdin);
  freopen("shell.out","w",stdout);
  int n;
  cin>>n;
  bool a[3]={false,false,true},b[3]={false,true,false},c[3]={true,false,false};
  int ac=0,bc=0,cc=0;
  for(int i=0;i<n;i++){
    int x,y,g;
    cin>>x>>y>>g;
    swap(x,y,a);
    swap(x,y,b);
    swap(x,y,c);
    if(a[g])ac++;
    if(b[g])bc++;
    if(c[g])cc++;
  }
  cout<<max(max(ac,bc),cc);
}