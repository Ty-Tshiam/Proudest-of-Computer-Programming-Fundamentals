#include <stdio.h>

double finH(double quiavg, double mid, double fin) {

  double ans = (0.25 * quiavg) + (0.25 * mid) + (0.5 * fin);
  return ans;
}

double midH(double quiavg, double mid, double fin) {

  double ans = (0.25 * quiavg) + (0.35 * mid) + (0.4 * fin);
  return ans;
}

double dropQ(double q1, double q2, double q3, double q4, double q5, double q6,
             double q7, double q8, double q9, double q10) {

  double ans;

  if (q1 < q2 && q1 < q3 && q1 < q4 && q1 < q5 && q1 < q6 && q1 < q7 &&
      q1 < q8 && q1 < q9 && q1 < q10) {

    ans = q1;

  } else if (q2 < q1 && q2 < q3 && q2 < q4 && q2 < q5 && q2 < q6 && q2 < q7 &&
             q2 < q8 && q2 < q9 && q2 < q10) {

    ans = q2;

  } else if (q3 < q1 && q3 < q2 && q3 < q4 && q3 < q5 && q3 < q6 && q3 < q7 &&
             q3 < q8 && q3 < q9 && q3 < q10) {

    ans = q3;

  } else if (q4 < q1 && q4 < q2 && q4 < q3 && q4 < q5 && q4 < q6 && q4 < q7 &&
             q4 < q8 && q4 < q9 && q4 < q10) {

    ans = q4;

  } else if (q5 < q1 && q5 < q2 && q5 < q3 && q5 < q4 && q5 < q6 && q5 < q7 &&
             q5 < q8 && q5 < q9 && q5 < q10) {

    ans = q5;

  } else if (q6 < q1 && q6 < q2 && q6 < q3 && q6 < q4 && q6 < q5 && q6 < q7 &&
             q6 < q8 && q6 < q9 && q6 < q10) {

    ans = q6;

  } else if (q7 < q1 && q7 < q2 && q7 < q3 && q7 < q4 && q7 < q5 && q7 < q6 &&
             q7 < q8 && q7 < q9 && q7 < q10) {

    ans = q7;

  } else if (q8 < q1 && q8 < q2 && q8 < q3 && q8 < q4 && q8 < q5 && q8 < q6 &&
             q8 < q7 && q8 < q9 && q8 < q10) {

    ans = q8;

  } else if (q9 < q1 && q9 < q2 && q9 < q3 && q9 < q4 && q9 < q5 && q9 < q6 &&
             q9 < q7 && q9 < q8 && q9 < q10) {

    ans = q9;
  } else if (q10 < q1 && q10 < q2 && q10 < q3 && q10 < q4 && q10 < q5 &&
             q10 < q6 && q10 < q7 && q10 < q8 && q10 < q9) {

    ans = q10;
  }

  return ans;
}

int main(void) {
  double quiavg, mid, fin, grade, smal;
  double q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;

  printf("Enter all quiz scores: ");
  scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &q1, &q2, &q3, &q4, &q5, &q6,
        &q7, &q8, &q9, &q10);

  printf("Enter midterm score: ");
  scanf("%lf", &mid);
  mid = mid / 100;

  printf("Enter final exam score: ");
  scanf("%lf", &fin);
  fin = fin / 100;

  smal = dropQ(q1, q2, q3, q4, q5, q6, q7, q8, q9, q10);

  quiavg = ((q1 + q2 + q3 + q4 + q5 + q6 + q7 + q8 + q9 + q10 - smal) / 90);

  if (mid >= fin) {

    grade = midH(quiavg, mid, fin) * 100;

  } else if (fin > mid) {

    grade = finH(quiavg, mid, fin) * 100;
  }

  printf("Your final grade is %.2lf%%", grade);

  return 0;
}