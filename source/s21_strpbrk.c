#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  for (; *str1 != '\0' && !res; str1++) {
    for (char *substr = (char *)str2; *substr != '\0' && !res; substr++) {
      if (*str1 == *substr) res = (char *)str1;
    }
  }
  return res;
}