#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;
  int x = s21_strlen(str);
  for (int i = x; i >= 0; i--) {
    if (str[i] == c) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}