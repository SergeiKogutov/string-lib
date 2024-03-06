#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *newstr = S21_NULL;
  if (str) {
    newstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  }
  if (newstr) {
    s21_strncpy(newstr, str, s21_strlen(str) + 1);
    for (s21_size_t i = 0; i < s21_strlen(newstr); i++) {
      if (newstr[i] >= 65 && newstr[i] <= 90) {
        newstr[i] += 32;
      }
    }
  }
  return (void *)newstr;
}