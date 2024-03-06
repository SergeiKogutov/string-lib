#include "../s21_string.h"

char *s21_strncpy(char *destinationArr, const char *sourceArr,
                  s21_size_t rightLimiterNum) {
  s21_size_t cnt;
  for (cnt = 0; cnt < rightLimiterNum; cnt++) {
    if (sourceArr[cnt] == '\0') {
      for (; cnt < rightLimiterNum; cnt++) {
        destinationArr[cnt] = '\0';
      }
      break;
    }
    destinationArr[cnt] = sourceArr[cnt];
  }
  destinationArr[cnt] = '\0';

  return destinationArr;
}