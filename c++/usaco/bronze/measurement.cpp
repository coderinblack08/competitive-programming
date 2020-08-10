#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Cow {
  string name;
  int day,gain;
};

bool orderDate(Cow a,Cow b){
  return a.day<b.day;
}

int main() {
  int n;
  cin>>n;
  Cow c[n];
  int t=0;
  for(int i=0;i<n;i++)
    cin>>c[i].day>>c[i].name>>c[i].gain;
  sort(c,c+n,orderDate);
  int tb=7,te=7,tm=7;
  string winnerList="BEM";
  for(int i=0;i<n;i++){
    if(c[i].name=="Bessie"){
      tb+=c[i].gain;
    }
    if(c[i].name=="Elsie"){
      te+=c[i].gain;
    }
    if(c[i].name=="Mildred"){
      tm+=c[i].gain;
    }
    int winner=max(max(tb,te),tm);
    string newList="";
    if(winner==tb)newList+='B';
    if(winner==te)newList+='E';
    if(winner==tm)newList+='M';
    if(newList!=winnerList){
      winnerList=newList;
      t++;
    }
  }
  cout<<t;
  return 0;
}