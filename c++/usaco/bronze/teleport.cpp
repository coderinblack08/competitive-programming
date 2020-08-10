#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ifstream fin("teleport.in");
  ofstream fout("teleport.out");
  int a,b,x,y;
  fin>>a>>b>>x>>y;
  int dist1=abs(b-a);
  int dist2=abs(a-x)+abs(b-y);
  int dist3=abs(a-y)+abs(b-x);
  int min=(dist1>dist2)?dist2:dist1;
  fout<<((min<dist3)?min:dist3);
  return 0;
}