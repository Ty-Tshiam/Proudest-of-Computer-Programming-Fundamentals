#include <stdio.h>

int main(void) {

  double gl = 50.0 / 300;
  double maxtemp = 500 / gl;
  double maxpres = 500;
  double temp = 273.15;
  double pres = 10;

  printf("Temperature (K)                 Pressure (atm)\n");
  printf("—--------------	                --------------\n");
  while (temp <= maxtemp && pres <= maxpres) {
    printf("%-32.2lf%.2lf\n", temp, pres);

    gl = pres / temp;
    temp += 100;
    pres = temp * gl;
  }

  printf("KABOOM!");
  return 0;
}