#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *newstr = S21_NULL;

  if (src) {
    if (src != S21_NULL && trim_chars != S21_NULL) {
      s21_size_t srclen = s21_strlen(src);
      s21_size_t trimlen = s21_strlen(trim_chars);

      s21_size_t k = 0;
      while (src && k != trimlen) {
        if ((*src) == trim_chars[k]) {
          src++;
          srclen -= 1;
          k = 0;
          continue;
        }
        k++;
      }
      if (srclen) {
        s21_size_t n = 0;
        s21_size_t t = srclen - 1;
        while (src && n != trimlen) {
          if (src[t] == trim_chars[n]) {
            t--;
            srclen--;
            n = 0;
            continue;
          }
          n++;
        }
      }
      newstr = (char *)malloc(sizeof(char) * (srclen + 1));
      if (newstr) {
        for (s21_size_t i = 0; i < srclen + 1; i++) {
          if (i < srclen) {
            newstr[i] = src[i];
          } else {
            newstr[i] = '\0';
          }
        }
      }
    }
  }

  return newstr;
}