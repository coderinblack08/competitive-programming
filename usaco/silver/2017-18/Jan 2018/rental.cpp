#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first > b.first;
}

int main() {
  setIO("rental");
  int n, m, r;
  cin >> n >> m >> r;

  vector<int> production(n);

  for (int i = 0; i < n; i++) {
    cin >> production[i];
  }

  vector<pair<int, int>> shops(m);

  for (int i = 0; i < m; i++) {
    cin >> shops[i].second >> shops[i].first;
  }

  vector<int> rent(r);

  for (int i = 0; i < r; i++) {
    cin >> rent[i];
  }

  sort(rent.begin(), rent.end(), greater<int>());
  sort(shops.begin(), shops.end(), cmp);
  sort(production.begin(), production.end(), greater<int>());

  int iShop = 0;
  int iRent = 0;
  int i = 0;
  ll sol = 0;
  while (i < n) {
    int litres = production[i];
    int moneyT = 0, curI = iShop;
    // moneyT = money earned
    // curI = which shop we are on, goes down when we finish trading (after we go over the quantity)
    int last = 0;
    // last = store how much
    while (curI < m) {
      int rest = min(litres, shops[curI].second);
      // find max number of liters we wanna sell
      moneyT += shops[curI].first * rest;
      // sell the most we can (greedy) and then add it to how much we earn
      litres -= rest;
      // remove the liters we sold

      if (litres == 0) {
        // once liters = 0, which means we sold all the milk for the highest paying dealer
        last = rest;
        break;
      } else {
        curI++;
      }
    }

    if (iRent >= r || moneyT > rent[iRent]) {
      sol += moneyT;
      iShop = curI;
      if (iShop < m) shops[iShop].second -= last;
      i++;
    } else {
      sol += rent[iRent];
      n--;
      iRent++;
    }
  }

  cout << sol << '\n';
}