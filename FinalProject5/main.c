#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fix() {
  FILE *csv_file, *new_file;
  char line[1024];
  char field[256];
  int field_index = 0;
  int in_quotes = 0;
  int i;
  csv_file = fopen("statscan_diabetes.csv", "r");
  new_file = fopen("statscan_diabetesnew.csv", "w");
  while (fgets(line, 1024, csv_file)) {
    field_index = 0;
    in_quotes = 0;
    for (i = 0; i < strlen(line); i++) {
      if (line[i] == ',' && !in_quotes) {
        field[field_index] = '\0';
        fprintf(new_file, "%s%c", field, ',');
        field_index = 0;
      } else if (line[i] == '\"') {
        in_quotes = !in_quotes;
      } else {
        field[field_index++] = line[i];
      }
    }
    field[field_index] = '\0';
    fprintf(new_file, "%s\n", field);
  }

  fclose(csv_file);
  fclose(new_file);
  remove("statscan_diabetes.csv");
  rename("statscan_diabetesnew.csv", "statscan_diabetes.csv");
}

struct canada {
  int year;
  char range[50];
  char sex[6];
  double percentage;
};

struct quebec {
  int year;
  char range[50];
  char sex[6];
  double percentage;
  char status;
};

struct ontario {
  int year;
  char range[50];
  char sex[6];
  double percentage;
  char status;
};

struct alberta {
  int year;
  char range[50];
  char sex[6];
  double percentage;
  char status;
};

struct british {
  int year;
  char range[50];
  char sex[6];
  double percentage;
  char status;
};

struct canada data[50];

struct quebec dataQ[50];
struct quebec dataQ2[50];

struct ontario dataO[50];
struct ontario dataO2[50];

struct alberta dataA[50];
struct alberta dataA2[50];

struct british dataB[50];
struct british dataB2[50];

double average(double arr[], int size) {
  double sum = 0, avg = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  avg = sum / size;
  return avg;
}

double averageYears(int years[], double vals[], int k) {
  int year = 2015 + k, j = 0;
  double avg = 0, sum = 0;

  for (int i = 0; i < 42; i++) {
    if (years[i] == year) {
      sum += vals[i];
      j++;
    }
  }
  avg = sum / j;
  return avg;
}

double averageAge(char ages[][20], double vals[], char range[]) {
  int i = 0, j = 0;
  for (;;) {
    if (strcmp(ages[i], range) == 0) {
      break;
    }
    i++;
  }

  double avg = 0, sum = 0;
  while (strcmp(ages[i], range) == 0) {
    sum += vals[i];
    j++;
    i++;
  }
  avg = sum / j;
  return avg;
}

double highest(double vals[], int years[], int *year, double *hi) {
  double high = vals[0];
  int yr;
  for (int i = 1; i < 42; i++) {
    if (vals[i] > high) {
      high = vals[i];
      yr = years[i];
    }
  }
  *hi = high;
  *year = yr;
}

double lowest(double vals[], int years[], int *year, double *lo) {
  double low = vals[0];
  int yr;
  for (int i = 1; i < 42; i++) {
    if (vals[i] < low && vals[i] != 0) {
      low = vals[i];
      yr = years[i];
    }
  }
  *lo = low;
  *year = yr;
}

int compare(const void *a, const void *b) {
  const double *da = (const double *)a;
  const double *db = (const double *)b;
  if (*da < *db)
    return -1;
  if (*da > *db)
    return 1;
  return 0;
}

int main() {

  fix();

  FILE *info;

  info = fopen("statscan_diabetes.csv", "r");

  if (info == NULL) {
    printf("\nIsuue Opening File\n");
    return 1;
  }

  int i = 0;
  int q = 0;

  char header[256];
  fgets(header, sizeof(header), info);

  // Canada

  for (i = 0; i <= 41; i++) {
    fscanf(info,
           "%d,%*[^,],,%49[^,],%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,"
           "],%*[^,],%*[^,],%lf,%*[^\n]",
           &data[i].year, data[i].range, data[i].sex, &data[i].percentage);
  }

  int h = 0;
  int p;

  // Quebec

  p = 0;
  for (q = 0; q < 42; q++) {
    h = fscanf(info,
               "%d,%*[^,],%*[^,],%49[^,],%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*"
               "[^,],%*[^,],%*[^,],%*[^,],%lf,%*[^\n]",
               &dataQ[q].year, dataQ[q].range, dataQ[q].sex,
               &dataQ[q].percentage);

    if (h != 4) {
      dataQ[q].percentage = -3;

      fscanf(info, "%*[^\n]");
    }

    if (dataQ[q].percentage != -3) {
      dataQ2[p] = dataQ[q];
      p = p + 1;
    }
  }

  // Ontario

  p = 0;
  for (q = 0; q < 42; q++) {
    h = fscanf(info,
               "%d,%*[^,],%*[^,],%49[^,],%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*"
               "[^,],%*[^,],%*[^,],%*[^,],%lf,%*[^\n]",
               &dataO[q].year, dataO[q].range, dataO[q].sex,
               &dataO[q].percentage);

    if (h != 4) {
      dataO[q].percentage = -3;

      fscanf(info, "%*[^\n]");
    }

    if (dataO[q].percentage != -3) {
      dataO2[p] = dataO[q];
      p = p + 1;
    }
  }

  // Alberta

  p = 0;
  for (q = 0; q < 42; q++) {
    h = fscanf(info,
               "%d,%*[^,],%*[^,],%49[^,],%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*"
               "[^,],%*[^,],%*[^,],%*[^,],%lf,%*[^\n]",
               &dataA[q].year, dataA[q].range, dataA[q].sex,
               &dataA[q].percentage);

    if (h != 4) {
      dataA[q].percentage = -3;

      fscanf(info, "%*[^\n]");
    }

    if (dataA[q].percentage != -3) {
      dataA2[p] = dataA[q];
      p = p + 1;
    }
  }

  // British columbia

  p = 0;
  for (q = 0; q < 42; q++) {
    h = fscanf(info,
               "%d,%*[^,],%*[^,],%49[^,],%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*"
               "[^,],%*[^,],%*[^,],%*[^,],%lf,%*[^\n]",
               &dataB[q].year, dataB[q].range, dataB[q].sex,
               &dataB[q].percentage);

    if (h != 4) {
      dataB[q].percentage = -3;

      fscanf(info, "%*[^\n]");
    }

    if (dataB[q].percentage != -3) {
      dataB2[p] = dataB[q];
      p = p + 1;
    }
  }
  fclose(info);

  double Cvals[42];
  int Cyrs[42];
  char Cages[42][20];
  for (i = 0; i < 42; i++) {
    strcpy(Cages[i], data[i].range);
    Cyrs[i] = data[i].year;
    Cvals[i] = data[i].percentage;
  }

  double Ovals[42];
  int Oyrs[42];
  char Oages[42][20];
  for (i = 0; i < 42; i++) {
    strcpy(Oages[i], dataO2[i].range);
    Oyrs[i] = dataO2[i].year;
    Ovals[i] = dataO2[i].percentage;
  }

  double Bvals[42];
  int Byrs[42];
  char Bages[42][20];
  for (i = 0; i < 42; i++) {
    strcpy(Bages[i], dataB2[i].range);
    Byrs[i] = dataB2[i].year;
    Bvals[i] = dataB2[i].percentage;
  }

  double Avals[42];
  int Ayrs[42];
  char Aages[42][20];
  for (i = 0; i < 42; i++) {
    strcpy(Aages[i], dataA2[i].range);
    Ayrs[i] = dataA2[i].year;
    Avals[i] = dataA2[i].percentage;
  }

  double Qvals[42];
  int Qyrs[42];
  char Qages[42][20];
  for (i = 0; i < 42; i++) {
    strcpy(Qages[i], dataQ2[i].range);
    Qyrs[i] = dataQ2[i].year;
    Qvals[i] = dataQ2[i].percentage;
  }
  // Question 1
  printf("\n\nLocation			    Overall average\n");
  printf("National			    %lf%%\n", average(Cvals, 42));
  printf("Ontario  			    %lf%%\n", average(Ovals, 42));
  printf("British Columbia 		%lf%%\n", average(Bvals, 37));
  printf("Alberta  	 		    %lf%%\n", average(Avals, 40));
  printf("Quebec  			    %lf%%\n", average(Qvals, 41));
  printf("\n");

  printf("Year		Location	      	 Average\n");
  for (int k = 0; k < 7; k++) {
    int year = 2015 + k;
    printf("%d 		Canada 		 	     %lf%%\n", year,
           averageYears(Cyrs, Cvals, k));
    printf("%d 		Ontario 		     %lf%%\n", year,
           averageYears(Oyrs, Ovals, k));
    printf("%d 		British Columbia     %lf%%\n", year,
           averageYears(Byrs, Bvals, k));
    printf("%d 		Alberta 		     %lf%%\n", year,
           averageYears(Ayrs, Avals, k));
    printf("%d 		Quebec 		       	 %lf%%\n", year,
           averageYears(Qyrs, Qvals, k));
    printf("\n");
  }

  printf("");
  printf("Location		    Age			Percentage\n");
  printf("National   		    35-49	 	%lf%%\n",
         averageAge(Cages, Cvals, "35 to 49 years"));
  printf("Ontario 		    35-49 		%lf%%\n",
         averageAge(Oages, Ovals, "35 to 49 years"));
  printf("British Columbia 	35-49 		%lf%%\n",
         averageAge(Bages, Bvals, "35 to 49 years"));
  printf("Alberta  		    35-49 		%lf%%\n",
         averageAge(Aages, Avals, "35 to 49 years"));
  printf("Quebec  		    35-49		%lf%%\n",
         averageAge(Qages, Qvals, "35 to 49 years"));
  printf("\n");
  printf("National  		    50-64		%lf%%\n",
         averageAge(Cages, Cvals, "50 to 64 years"));
  printf("Ontario  		    50-64		%lf%%\n",
         averageAge(Oages, Ovals, "50 to 64 years"));
  printf("British Columbia	50-64		%lf%%\n",
         averageAge(Bages, Bvals, "50 to 64 years"));
  printf("Alberta		 	    50-64		%lf%%\n",
         averageAge(Aages, Avals, "50 to 64 years"));
  printf("Quebec			    50-64		%lf%%\n",
         averageAge(Qages, Qvals, "50 to 64 years"));
  printf("\n");
  printf("National 		    65+		    %lf%%\n",
         averageAge(Cages, Cvals, "65 years and over"));
  printf("Ontario  		    65+         %lf%%\n",
         averageAge(Oages, Ovals, "65 years and over"));
  printf("British Columbia  	65+		    %lf%%\n",
         averageAge(Bages, Bvals, "65 years and over"));
  printf("Alberta  		    65+		    %lf%%\n",
         averageAge(Aages, Avals, "65 years and over"));
  printf("Quebec 			    65+		    %lf%%\n",
         averageAge(Qages, Qvals, "65 years and over"));
  printf("\n");

  // Question 2
  double avgs[] = {average(Avals, 40), average(Qvals, 41), average(Ovals, 42),
                   average(Bvals, 37)};
  int n = sizeof(avgs) / sizeof(double);

  qsort(avgs, n, sizeof(double), compare);

  if (average(Ovals, 42) == avgs[0]) {
    printf("Ontario has the lowest average percentage\n");
  } else if (average(Bvals, 37) == avgs[0]) {
    printf("British Columbia has the lowest average percentage\n");
  } else if (average(Qvals, 41) == avgs[0]) {
    printf("Quebec has the lowest average percentage\n");
  } else if (average(Avals, 40) == avgs[0]) {
    printf("Alberta has the lowest average percentage\n");
  }

  if (average(Ovals, 42) == avgs[(n - 1)]) {
    printf("Ontario has the highest average percentage\n");
  } else if (average(Bvals, 37) == avgs[(n - 1)]) {
    printf("British Columbia has the highest average percentage\n");
  } else if (average(Qvals, 41) == avgs[(n - 1)]) {
    printf("Quebec has the highest average percentage\n");
  } else if (average(Avals, 40) == avgs[(n - 1)]) {
    printf("Alberta has the highest average percentage\n");
  }
  printf("\n");

  // Question 3
  if (average(Ovals, 42) > average(Cvals, 42)) {
    printf("Ontario's average diabetes percentage is above the national "
           "average\n");
  } else {
    printf("Ontario's  average diabetes percentage is below the national "
           "average\n");
  }

  if (average(Bvals, 37) > average(Cvals, 42)) {
    printf("British Columbia's average diabetes percentage is above the "
           "national average\n");
  } else {
    printf("British Columbia's average diabetes percentage is below the "
           "national average\n");
  }

  if (average(Qvals, 41) > average(Cvals, 42)) {
    printf(
        "Quebec's average diabetes percentage is above the national average\n");
  } else {
    printf(
        "Quebec's average diabetes percentage is below the national average\n");
  }

  if (average(Avals, 40) > average(Cvals, 42)) {
    printf("Alberta's average diabetes percentage is above the national "
           "average\n");
  } else {
    printf("Alberta's average diabetes percentage is below the national "
           "average\n");
  }
  printf("\n");

  // Question 4
  int Qyear, Oyear, Ayear, Byear;
  double hiA, hiQ, hiB, hiO, loO, loQ, loA, loB;

  highest(Ovals, Oyrs, &Oyear, &hiO);
  highest(Bvals, Byrs, &Byear, &hiB);
  highest(Avals, Ayrs, &Ayear, &hiA);
  highest(Qvals, Qyrs, &Qyear, &hiQ);
  if (hiO > hiB && hiO > hiQ && hiO > hiA) {
    printf("The highest percentage of diabetes was in Ontario %.1lf%% in year "
           "%d\n",
           hiO, Oyear);
  } else if (hiB > hiO && hiB > hiQ && hiB > hiA) {
    printf("The highest percentage of diabetes was in British Columbia %.1lf%% "
           "in year %d\n",
           hiB, Byear);
  } else if (hiQ > hiO && hiQ > hiB && hiQ > hiA) {
    printf(
        "The highest percentage of diabetes was in Quebec %.1lf%% in year %d\n",
        hiQ, Qyear);
  } else if (hiA > hiO && hiA > hiB && hiA > hiQ) {
    printf("The highest percentage of diabetes was in Alberta %.1lf%% in year "
           "%d\n",
           hiA, Ayear);
  }
  printf("\n");

  lowest(Ovals, Oyrs, &Oyear, &loO);
  lowest(Bvals, Byrs, &Byear, &loB);
  lowest(Avals, Ayrs, &Ayear, &loA);
  lowest(Qvals, Qyrs, &Qyear, &loQ);
  if (loO < loB && loO < loQ && loO < loA) {
    printf("The lowest percentage of diabetes was in Ontario %.1lf%% in year "
           "%d\n",
           loO, Oyear);
  } else if (loB < loO && loB < loQ && loB < loA) {
    printf("The lowest percentage of diabetes was in British Columbia %.1lf%% "
           "in year %d\n",
           loB, Byear);
  } else if (loQ < loO && loQ < loB && loQ < loA) {
    printf("The lowest percentage of diabetes was in Quebec %.1lf%% in year "
           "%d\n",
           loQ, Qyear);
  } else if (loA < loO && loA < loB && loA < loQ) {
    printf("The lowest percentage of diabetes was in Alberta %.1lf%% in year "
           "%d\n",
           loA, Ayear);
  }
  return 0;
}
