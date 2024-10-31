#include <ctype.h>
#include <stdio.h>
#include <string.h>

void clean(char before[], char after[]) {
  int i, j;
  char c;

  for (i = 0, j = 0; before[i] != '\0'; i++) {
    c = before[i];

    if (isalnum(c)) {
      if (isupper(c)) {
        c = tolower(c);
      }
      after[j] = c;
      j++;
    }
  }

  after[j] = '\0';
}
void reverse(char before[], char after[]) {
  if (*before == '\0') {
    *after = '\0';
  } else {
    reverse(before + 1, after);
    strncat(after, before, 1);
  }
}

int main(void) {
  char str1[100], str2[100], str3[100];

  printf("Enter a string: ");
  scanf(" %[^\n]", str1);
  printf("You entered: %s\n", str1);

  clean(str1, str2);
  printf("Clean string: %s\n", str2);

  reverse(str2, str3);
  printf("Reverse string: %s\n", str2);

  if (strcmp(str3, str2) == 0) {
    printf("This is a palindrome!");
  } else {
    printf("This is a not palindrome.");
  }

  return 0;
}
