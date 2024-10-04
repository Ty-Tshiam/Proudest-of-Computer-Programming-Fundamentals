#include <stdio.h>

int main(void) {

  double wei, hei, bmi;

  printf("Enter your weight (kg): ");
  scanf("%lf", &wei);

  printf("Enter your height (m): ");
  scanf("%lf", &hei);

  bmi = wei / (hei * hei);

  if (bmi < 18.5) {

    printf("Your BMI value is %.1lf, which classifies you as underweight", bmi);

  } else if (bmi <= 24.9 && bmi >= 18.5) {

    printf("Your BMI value is %.1lf, which classifies you as normal", bmi);

  } else if (bmi <= 29.9 && bmi >= 25) {

    printf("Your BMI value is %.1lf, which classifies you as overweight", bmi);

  } else if (bmi >= 30) {

    printf("Your BMI value is %.1lf, which classifies you as obese", bmi);
  }

  return 0;
}