#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int t) {
  if (h >= 1) {
    int m = l + (h - l) / 2;
    if (arr[m] == t)
      return m;
    else if (arr[m] > t)
      return binarySearch(arr, l, m - 1, t);
    else
      return binarySearch(arr, m + 1, h, t);
  } else
    return -1;
}

int main() {
  int n, search;
  cin>>n>>search;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin>>arr[i];
  }
  int result = binarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, search); 
  cout << result << endl;
  return 0;
}
