// This is moded code from USACO Solution
#include <bits/stdc++.h>
using namespace std;

void pour(int c1,int m1,int c2,int m2) {
  int a=min(m1,c2-m2);
  m1-=a;
  m2+=a;
}

int main() {
  ifstream fin ("test.in");
  ofstream fout ("test.out");
  int c1,c2,c3;
  int m1,m2,m3;
  fin>>c1>>m1;
  fin>>c2>>m2;
  fin>>c3>>m3;
  for(int i=0;i<33;i++){
    pour(c1,m1,c2,m2);
    pour(c2,m2,c3,m3);
    pour(c3,m3,c1,m1);
  }
  pour(c1,m1,c2,m2);
  fout<<m1<<"\n"<<m2<<"\n"<<m3;
}