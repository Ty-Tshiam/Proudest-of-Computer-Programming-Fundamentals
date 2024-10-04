#include <stdio.h>
#include <string.h>

// calculating the time it takes to the Moon with a certain mode of transport
double toMoon(int speed, double *time1, double *time2) {
  int per = 363104, apo = 405696;
  *time1 = (double)per / speed;
  *time2 = (double)apo / speed;
}
// calculating the time it takes to Mars with a certain mode of transport
double toMars(int speed, double *time1, double *time2) {
  int per = 54600000, apo = 401000000;
  *time1 = (double)per / speed;
  *time2 = (double)apo / speed;
}
// calculating the time it takes to Venus with a certain mode of transport
double toVenus(int speed, double *time1, double *time2) {
  int per = 38000000, apo = 261000000;
  *time1 = (double)per / speed;
  *time2 = (double)apo / speed;
}

int main(void) {
  // initializing variables
  int car = 100, plane = 500, rocket = 41000, choice1 = 0, choice2 = 0;
  double mintime = 0, maxtime = 0;
  char place[20] = "";
  char transport[20] = "";

  // loop runs forever until choice1 or choice2 is equal to 4, if that condition
  // is met, then it will break the loop
  for (;;) {

    // Asking the user where they want to go
    printf("Where do you want to go?\n");
    printf("1. Moon\n");
    printf("2. Mars\n");
    printf("3. Venus\n");
    printf("4. Exit Program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);
    printf("\n");

    // break the loop if user enters four
    if (choice1 == 4) {
      printf("Exiting program...\n");
      break;
    }
    // asks for the mode of transportaion which each has their respective speeds
    if (!(choice1 == 4)) {
      printf("How do you want to go?\n");
      printf("1. Car\n");
      printf("2. Airplane\n");
      printf("3. Rocket\n");
      printf("4. Exit Program\n");
      printf("Enter your choice: ");
      scanf("%d", &choice2);
      printf("\n");

      // break the loop if user enters four
      if (choice2 == 4) {
        printf("Exiting program...\n");
      } else if (choice1 ==
                 1) { // user chooses to travel to the Moon and their second
                      // choice will determine how long it will take to get
                      // there depending on their mode of transport
        strcpy(place, "Moon");
        if (choice2 == 1) {
          toMoon(car, &mintime, &maxtime);
          strcpy(transport, "car");
        } else if (choice2 == 2) {
          toMoon(plane, &mintime, &maxtime);
          strcpy(transport, "airplane");
        } else if (choice2 == 3) {
          toMoon(rocket, &mintime, &maxtime);
          strcpy(transport, "rocket");
        }
      } else if (choice1 == 2) { // the user chooses Mars
        strcpy(place, "Mars");
        if (choice2 == 1) {
          toMars(car, &mintime, &maxtime);
          strcpy(transport, "car");
        } else if (choice2 == 2) {
          toMars(plane, &mintime, &maxtime);
          strcpy(transport, "airplane");
        } else if (choice2 == 3) {
          toMars(rocket, &mintime, &maxtime);
          strcpy(transport, "rocket");
        }
      } else if (choice1 == 3) { // the user chooses Venus
        strcpy(place, "Venus");
        if (choice2 == 1) {
          toVenus(car, &mintime, &maxtime);
          strcpy(transport, "car");
        } else if (choice2 == 2) {
          toVenus(plane, &mintime, &maxtime);
          strcpy(transport, "airplane");
        } else if (choice2 == 3) {
          toVenus(rocket, &mintime, &maxtime);
          strcpy(transport, "rocket");
        }
      }
      if (!(choice2 == 4)) { // outputs the range of estimated time arrival
        printf("The time it will take to get to %s by %s is between %.2lf and "
               "%.2lf hours.\n",
               place, transport, mintime, maxtime);
        printf("\n");
      } else { // break the loop if user enters four
        break;
      }
    }
  }
  return 0;
}