#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buffer;
  int k = 0;
  if (str) {
    buffer = str;
    while (*buffer && s21_strchr(delim, *buffer)) *buffer++ = '\0';
  }
  if (!*buffer) {
    k = 1;
  } else {
    str = buffer;
    while (*buffer && !s21_strchr(delim, *buffer)) ++buffer;
    while (*buffer && s21_strchr(delim, *buffer)) *buffer++ = '\0';
  }
  return k ? S21_NULL : str;
}