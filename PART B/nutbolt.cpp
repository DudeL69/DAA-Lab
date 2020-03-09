#include <bits/stdc++.h>

using namespace std;

int b[100],cnt=0;

void merge(int a[],int low,int mid,int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] > a[j]) {
            b[k++] = a[j++];
            cnt++;
        } else {
            b[k++] = a[i++];
            cnt++;
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
        cnt++;
    }
    while (j <= high) {
        b[k++] = a[j++];
        cnt++;
    }
    for (i = 0; i <= high; i++)
        a[i] = b[i];
}

void mergesort(int a[],int low,int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


int binarysearch(int C[], int x, int l, int r) {
    if (r >= l) {
        cnt++;
        int m = l + (r - l) / 2;
        if (C[m] == x)
            return m;
        if (C[m] > x)
            return binarysearch(C, x, l, m - 1);
        return binarysearch(C, x, m + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of nuts and bolts: ";
    cin >> n;
    int N[n], B[n], C[n], ind[n];
    cout << "Enter the nuts :\n";
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        N[i] = (int) c;
    }
    cout << "Enter the bolts :\n";
    for (int i = 0; i < n; i++) {
        cin >> c;
        B[i] = (int) c;
    }
    for (int i = 0; i < n; i++) {
        C[i] = B[i];
    }
    mergesort(C, 0, n - 1);
    for (int j = 0; j < n; j++) {
        int m = C[j];
        for (int k = 0; k < n; k++) {
            if (B[k] == m) {
                ind[j] = k;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x = N[i];
        int ans = binarysearch(C, x, 0, n - 1);
        int pos = ind[ans];
        cout << "The nut " << (char) N[i] << " at index " << i + 1
             << " has been matched with corresponding bolt at index " << pos + 1 << endl;
    }
    cout << "Count = " << cnt << endl;
    return 0;
}