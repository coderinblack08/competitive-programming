#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int gr[256][2];
  for(int i=0;i<n;i++){
    char a;
    int b;
    cin>>a>>b;
    if(b%2==0)gr[a][0]++;
    else gr[a][1]++;
  }
  long long c=0;
  for(int b=0;b<2;b++)
    for(int e=0;e<2;e++)
      for(int s=0;s<2;s++)
        for(int i=0;i<2;i++)
          for(int g=0;g<2;g++)
            for(int o=0;o<2;o++)
              for(int m=0;m<2;m++)
                if((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o)%2==0)
                  c+=gr['B'][b]*gr['E'][e]*gr['S'][s]*gr['I'][i]*gr['G'][g]*gr['O'][o]*gr['M'][m];
  cout<<c;
  return 0;
}