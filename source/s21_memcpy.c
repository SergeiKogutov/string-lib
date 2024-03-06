#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  unsigned char *s = (unsigned char *)src;
  for (int i = 0; i < (int)n; i++) {
    d[i] = s[i];
  }
  return dest;
}