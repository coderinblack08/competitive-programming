#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Toy {
  int index,price,joy;
  double score;
};

bool comp(Toy a,Toy b) {
  return a.score>b.score;
}

int main() {
  int n;
  cin>>n;
  Toy t[n];
  for(int i=0;i<n;i++){
    t[i].index=i;
    cin>>t[i].joy>>t[i].price;
    t[i].score=(double)t[i].joy/t[i].price;
  }
  sort(t,t+n,comp);
  int tp=t[0].price+t[1].price+t[2].price;
  cout<<tp<<"\n";
  for(int i=0;i<3;i++)
    cout<<t[i].index+1<<"\n";
  return 0;
}