#include <bits/stdc++.h>
#define int long long

using namespace std;

static int c;
int col[50], diag1[100], diag2[100];

void solve(int y, int N)
{
	if (y == N)
	{
		c++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (col[i] || diag1[i + y] || diag2[i - y + N - 1])
			continue;

		col[i] = diag1[i + y] = diag2[i - y + N - 1] = 1;
		solve(y + 1, N);

		col[i] = diag1[i + y] = diag2[i - y + N - 1] = 0;
	}
}

int32_t main()
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "w", stdout);

	int N;

	cout << "Enter the value of N: ";
	cin >> N;

	solve(0, N);

	cout << "\nTotal number of ways = " << c;

	return 0;
}