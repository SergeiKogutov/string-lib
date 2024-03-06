#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int flag = 1;
  for (s21_size_t i = 0; i < s21_strlen(str1) && flag == 1; i++) {
    for (s21_size_t k = 0; k < s21_strlen(str2); k++) {
      if (str1[i] == str2[k]) {
        flag = 0;
      }
    }
    if (flag == 1) {
      count++;
    }
  }
  return count;
}