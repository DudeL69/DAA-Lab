//
// Created by rect0r on 02-03-2020.
//
#include <bits/stdc++.h>

using namespace std;

int cnt;

void heapify(int a[],int n,int i) {
    cnt++;
    int l = 2 * i + 1;
    int r = 2 * (i + 1);
    int lar = i;
    if (l < n && a[l] > a[lar])
        lar = l;
    if (r < n && a[r] > a[lar])
        lar = r;
    if (lar != i) {
        swap(a[i], a[lar]);
        heapify(a, n, lar);
    }
}

void heapsort(int a[],int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        cnt++;
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heapsort(a, n);
    cout << "The sorted array is:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cnt = 0;
    cout << "\nEnter the value of n: ";
    cin >> n;
    int inc[n], dec[n], ran[n];
    for (int i = 0; i < n; i++) {
        inc[i] = i + 1;
        dec[i] = 2 * n - i;
        ran[i] = rand() % n + 1;
    }
    heapsort(inc, n);
    cout << "Ascending order input: " << cnt;
    cnt = 0;
    heapsort(dec, n);
    cout << "\nDecreasing order input: " << cnt;
    cnt = 0;
    heapsort(ran, n);
    cout << "\nRandom entries: " << cnt;
    cout << '\n';
    return 0;
}