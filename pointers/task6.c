#include <stdio.h>

int compareasc(int a, int b) {
  return a < b;
}

int comparedesc(int a, int b) {
  return a > b;
}

void bubblesort(int arr[], int n, int (*compare)(int, int)) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (compare(arr[j], arr[j + 1])) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("UP: \n");
  bubblesort(arr, n, compareasc);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Down:\n");
  bubblesort(arr, n, comparedesc);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
