#include <math.h>
#include <stdio.h>

double maleMHR(int age) {

  double ans = (203.7) / (1 + exp(0.033 * (age - 104.3)));

  return ans;
}

double femaleMHR(int age) {

  double ans = (190.2) / (1 + exp(0.0453 * (age - 107.5)));

  return ans;
}

int finalTHR(double mhr, double rhr, double inten) {
  double ans = (inten * (mhr - rhr)) + rhr;

  return round(ans);
}

int main(void) {
  char gen, fitlev;
  double mhr, rhr, inten;
  int age;

  printf("Enter your gender (Enter 'M' for male or 'F' for female): ");
  scanf("%c", &gen);

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your resting heart rate: ");
  scanf("%lf", &rhr);

  printf(
      "Enter your fitness level ('L' for low, 'M' for medium, 'H' for high): ");
  scanf(" %c", &fitlev);

  switch (gen) {

  case 'M':
    mhr = maleMHR(age);
    break;

  case 'F':
    mhr = femaleMHR(age);
    break;
  }

  switch (fitlev) {
  case 'L':
    inten = 0.55;
    break;

  case 'M':
    inten = 0.65;
    break;

  case 'H':
    inten = 0.8;
    break;
  }

  printf("Your training heart rate is: %d", finalTHR(mhr, rhr, inten));

  return 0;
}