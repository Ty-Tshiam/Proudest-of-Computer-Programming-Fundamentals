#include <stdio.h>

// sort function takes three integers and three pointers to store the sorted values
int sort(int a, int b, int c, int *hv, int *mv, int *lv) {

  // determine the lowest integer and assign it to the lowest value pointer
  if (a <= b && a <= c) {
    *lv = a;
  } else if (b <= a && b <= c) {
    *lv = b;
  } else if (c <= a && c <= b) {
    *lv = c;
  }
  // determine the highest integer and assign it to the highest value pointer
  if (a >= b && a >= c) {
    *hv = a;
  } else if (b >= a && b >= c) {
    *hv = b;
  } else if (c >= a && c >= b) {
    *hv = c;
  }

  // determine the middle integer and assign it to the middle value pointer
  if ((a >= b && a <= c) || (a <= b && a >= c)) {
    *mv = a;
  } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
    *mv = b;
  } else if ((c >= b && c <= a) || (c <= b && c >= a)) {
    *mv = c;
  }
}
int main(void) {
  int x, y, z;

  // ask the user to input three integers
  printf("Enter three integers: ");
  scanf("%d %d %d", &x, &y, &z);

  // call the sort function and pass the input integers as well as their pointers
  sort(x, y, z, &x, &y, &z);

  // print the sorted integers in ascending order
  printf("%d %d %d\n", z, y, x);

  return 0;
}