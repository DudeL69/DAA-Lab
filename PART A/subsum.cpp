#include <bits/stdc++.h>

using namespace std;

static int total_nodes;

void print(int A[], int size) {
   for (int i = 0; i < size; i++) {
      printf("%*d", 5, A[i]);
   }
   printf("\n");
}

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
   total_nodes++;
   if (target_sum == sum) {
      print(t, t_size);
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      return;
   }
   else {
      for (int i = ite; i < s_size; i++) {
         t[t_size] = s[i];
         subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}

void generateSubsets(int s[], int size, int target_sum) {
   int* subset = (int*)malloc(size * sizeof(int));
   subset_sum(s, subset, size, 0, 0, 0, target_sum);
   free(subset);
}

int main() {
   /*freopen("input.txt", "rt", stdin);
   freopen("output.txt", "w", stdout);*/
   int n, sum;
   cout << "Enter the set size: ";
   cin >> n;
   cout << "Enter the elements of the set: ";
   int s[n];
   for (int i = 0; i < n; i++)
      cin >> s[i];
   cout << "\nEnter the target sum: ";
   cin >> sum;
   cout << "\n";
   cout << "The subsets are: \n";
   generateSubsets(s, n, sum);
   return 0;
}