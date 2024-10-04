#include <stdio.h>

int main(void) {
  FILE *in;

  int empnum, shif, hrs, inp;
  double wage, gross, prem;

  in = fopen("L4_data.txt", "r");

  printf("Employee number     Total hours     Gross pay\n");

  while (!feof(in)) {
    fscanf(in, "%d%d%lf", &empnum, &shif, &wage);
    hrs = 0;
    for (int i = 1; i <= shif; ++i) {
      fscanf(in, "%d", &inp);
      hrs = hrs + inp;
    }

    if (hrs <= 15) {
      gross = wage * hrs;
    } else if (hrs > 15 && hrs <= 25) {
      gross = hrs * wage;
      prem = gross * 0.05;
      gross += prem;
    } else if (hrs > 25) {
      gross = hrs * wage;
      prem = gross * 0.1;
      gross += prem;
    }
    printf("%-20d%-16d%.2lf\n", empnum, hrs, gross);
  }
  fclose(in);
  return (0);
}
