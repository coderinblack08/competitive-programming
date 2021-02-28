/*
ID: kevinlu4
LANG: C++
TASK: gift1
*/

#include <bits/stdc++.h>
using namespace std;

struct Person
{
  string name;
  int value = 0;
};

int main()
{
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);
  int n;
  cin >> n;
  Person ar[n];
  for (int i = 0; i < n; i++)
    cin >> ar[i].name;
  for (int i = 0; i < n; i++)
  {
    string person;
    int a, b;
    cin >> person >> a >> b;
    for (int j = 0; j < n; j++)
    {
      if (ar[j].name == person)
      {
        if (a != 0)
          ar[j].value -= a - (a % b);
        break;
      }
    }
    for (int j = 0; j < b; j++)
    {
      string person2;
      cin >> person2;
      for (int k = 0; k < n; k++)
      {
        if (ar[k].name == person2)
          if (b != 0)
          {
            ar[k].value += a / b;
          }
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << ar[i].name << " " << ar[i].value << "\n";
  return 0;
}