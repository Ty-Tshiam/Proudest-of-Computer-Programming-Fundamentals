#include <stdio.h>

void sortArray(double arr[], int n) {
  int i, j;
  double temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {

        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main(void) {
  int cnt;
  double max, min, norm;

  FILE *prob1;
  prob1 = fopen("data.file", "r");
  fscanf(prob1, "%d%lf%lf", &cnt, &min, &max);

  double nums[cnt];
  for (int i = 0; i <= cnt; ++i) {
    fscanf(prob1, "%lf", &nums[i]);
  }
  fclose(prob1);

  sortArray(nums, cnt);

  double norms[cnt];
  for (int i = 0; i < cnt; i++) {
    norm =
        min + (nums[i] - nums[0]) * (max - min) / (nums[(cnt - 1)] - nums[0]);
    norms[i] = norm;
  }

  printf("Original Values  Normalized Values\n");
  for (int i = 0; i < cnt; i++) {
    printf("%-16.1lf %.2lf\n", nums[i], norms[i]);
  }

  return 0;
}