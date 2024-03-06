#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  unsigned char *str1 = (unsigned char *)haystack;
  unsigned char *str2 = (unsigned char *)needle;
  char *res = S21_NULL;
  if (str2 == S21_NULL || !*str2) res = (char *)str1;
  for (int i = 0; str1[i] != '\0' && !res; i++) {
    int k = i;
    for (int j = 0; str2[j] != '\0' && !res && str1[k] == str2[j]; j++, k++) {
      if (str2[j + 1] == '\0') res = (char *)(str1 + i);
    }
  }
  return res;
}
