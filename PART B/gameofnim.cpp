//
// Created by rect0r on 07-03-2020.
//
#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    if(n<=4){
        cout << "Player 1 picks " << n << " sticks and wins....";
        return;
    }
    int x=n%5;
    int y=rand()%4 +1;
    cout << "Player 1 picks " << x << " sticks.\n";
    cout << "Player 2 picks " << y << " sticks.\n";
    return solve(n-x-y);
}

int main(){
    cout << "Enter the total number of sticks: ";
    int n;
    cin >> n;
    if(n%5 == 0)
        cout << "Impossible for player 1 to win...";
    else {
        solve(n);
    }
    return 0;
}
