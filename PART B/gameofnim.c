//
// Created by rect0r on 07-03-2020.
//
#include <stdio.h>
#include <stdlib.h>

void solve(int n) {
    if (n <= 4) {
        printf("Player 1 picks %d sticks and wins....", n);
        return;
    }
    int x = n % 5;
    int y = rand() % 4 + 1;
    printf("Player 1 picks %d sticks.\n", x);
    printf("Player 2 picks %d sticks.\n", y);
    return solve(n - x - y);
}

int main() {
    printf("Enter the total number of sticks: ");
    int n;
    scanf("%d", &n);
    if (n % 5 == 0)
        printf("Impossible for player 1 to win...");
    else {
        solve(n);
    }
    return 0;
}
