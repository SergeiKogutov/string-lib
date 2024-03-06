#include "../s21_string.h"

char* s21_strchr(const char* str, int c) {
  const char* res = S21_NULL;
  char str1 = s21_strlen(str) + 1;

  for (int i = 0; i < str1; i++) {
    if ((unsigned char)str[i] == c) {
      res = &str[i];
      break;
    }
  }
  return (char*)res;
}