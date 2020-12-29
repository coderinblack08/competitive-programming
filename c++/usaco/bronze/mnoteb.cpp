#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  int s[n], l[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    if (i == 0)
      s[i] = 0;
    else
      s[i] = s[i - 1] + l[i - 1];
  }
  for (int i = 0; i < q; i++) {
    int index, question;
    cin >> question;
    for (int j = 0; j < n; j++) {
      if (s[j] <= question && question < s[j + 1] && j != n - 1)
        index = j + 1;
      if (j == n - 1 && s[j] <= question)
        index = j + 1;
    }
    cout << index << "\n";
  }
  return 0;
}