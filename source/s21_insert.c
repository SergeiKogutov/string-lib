#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *newstr = S21_NULL;
  s21_size_t srclen = 0;
  s21_size_t strlen = 0;
  if (src != S21_NULL && str != S21_NULL) {
    srclen = s21_strlen(src);
    strlen = s21_strlen(str);
  }
  if (start_index < (srclen + 1) && (long long int)start_index >= 0) {
    newstr = malloc(sizeof(char) * (srclen + strlen + 1));
    for (s21_size_t i = 0, n = 0, k = 0; i < srclen + strlen; i++) {
      if (i == start_index && k < strlen) {
        newstr[i] = str[k];
        k++;
        start_index++;
      } else {
        newstr[i] = src[n];
        n++;
      }
    }
    newstr[srclen + strlen] = '\0';
  }
  return newstr;
}