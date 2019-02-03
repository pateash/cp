#define MAX 20
int n; // Number of elements in A
int A[MAX];
bool V[MAX];

void subsets(int i)
{
  if (i == n) {
    for (int j = 0; j < n; j++)
      if (V[j])
        printf("%d ", A[j]);
    printf("\n");
  } else {
    // Each element of the original set may be or not in the subsets
    // Since each element has two options the total number subsets is:
    // 2 * 2 * 2 * ... * 2 = 2^n
    // -------------------------
    // 1   2   3   ...   n

    V[i] = true;      // This element will be in the subset
    subsets(i + 1);
    V[i] = false;     // This element won't be in the subset
    subsets(i + 1);
  }
}