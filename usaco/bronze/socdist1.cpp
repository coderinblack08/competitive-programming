#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll largestInteriorGap(string s, ll &gapStart) {
  ll biggestGap = 0, currentStart = -1, n = s.length();
  for (ll i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (currentStart != -1 && i - currentStart > biggestGap) {
        biggestGap = i - currentStart;
        gapStart = currentStart;
      }
      currentStart = i;
    }
  }
  return biggestGap;
}

ll smallestInteriorGap(string s) {
  ll smallestGap = LONG_LONG_MAX, currentStart = -1, n = s.length();
  for (ll i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (currentStart != -1 && i - currentStart < smallestGap) {
        smallestGap = i - currentStart;
      }
      currentStart = i;
    }
  }
  return smallestGap;
}

ll tryCowInLargestGap(string s) {
  ll gapStart, largestGap = largestInteriorGap(s, gapStart);
  if (largestGap >= 2) {
    s[gapStart + largestGap / 2] = '1';
    return smallestInteriorGap(s);
  }
  return -1;
}

int main() {
  setIO("socdist1");
  ll n;
  string s, temp;
  ll answer = 0;
  cin >> n >> s;
  ll gapStart, largestGap = largestInteriorGap(s, gapStart);

  // 1. two cows in one gap
  if (largestGap >= 3) {
    temp = s;
    temp[gapStart + largestGap / 3] = '1';
    temp[gapStart + largestGap * 2 / 3] = '1';
    answer = max(smallestInteriorGap(temp), answer);
  }

  // 2. cows on either ends
  if (s[0] == '0' && s[n - 1] == '0') {
    temp = s;
    temp[0] = temp[n - 1] = '1';
    answer = max(smallestInteriorGap(temp), answer);
  }

  // 3. cow in interior and one on the left
  if (s[0] == '0') {
    temp = s;
    temp[0] = '1';
    answer = max(answer, tryCowInLargestGap(temp));
  }

  // 4. cow in interior and one on the right
  if (s[n - 1] == '0') {
    temp = s;
    temp[n - 1] = '1';
    answer = max(answer, tryCowInLargestGap(temp));
  }

  // 5. cows both in interior but not in same gap
  if (largestGap >= 2) {
    temp = s;
    temp[gapStart + largestGap / 2] = '1';
    answer = max(answer, tryCowInLargestGap(temp));
  }

  cout << answer << "\n";
  return 0;
}