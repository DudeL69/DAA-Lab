//
// Created by rect0r on 02-03-2020.
//
#include <bits/stdc++.h>

using namespace std;

int cnt;

void badchars(string p,int m,int bad[]) {
    for (int i = 0; i < 256; i++) {
        bad[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        bad[(int) p[i]] = i;
    }
}

void search(string s,string p) {
    int n = s.size();
    int m = p.size();
    int bad[256];
    badchars(p, m, bad);
    int x = 0;
    while (x <= (n - m)) {
        int i = m - 1;
        while (i >= 0 && p[i] == s[x + i])
            i--;
        if (i < 0) {
            cout << "Pattern occurs at start index " << x << endl;
            cnt++;
            x += (x + m < n) ? m - bad[s[x + m]] : 1;
        } else {
            x += max(1, i - bad[s[x + i]]);
        }
    }
}

int main() {
    string s, p;
    cout << "Enter the text: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;
    int n = s.length();
    int m = p.length();
    if (m > n) {
        cout << "Matching impossible!!!\n";
        return 0;
    }
    search(s, p);
    if (!cnt)
        cout << "No match found...\n";
    return 0;
}
