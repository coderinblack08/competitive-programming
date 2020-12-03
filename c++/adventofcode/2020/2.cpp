#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> read(string file) {
  ifstream fin(file);
  vector<string> G;

  while (true) {
    if (fin.eof()) {
      break;
    }
    string temp;
    getline(fin, temp);
    G.push_back(temp);
  }

  fin.close();
  return G;
}

int main() {
  ll answer = 0;
  vector<string> lines = read("2.txt");
  for (ll i = 0; i < lines.size(); i++) {
    ll low = stoi(lines[i].substr(0, lines[i].find('-'))),
       high = stoi(lines[i].substr(lines[i].find('-') + 1, lines[i].find(' ') + 1));
    char letter = lines[i][4];
    string word = lines[i].substr(7, lines[i].length());

    cout << word << " " << low << " " << high << "\n";
  }
  cout << answer;
  return 0;
}
