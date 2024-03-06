#ifndef S21_STRING_H
#define S21_STRING_H
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define S21_NULL (void *)0

#define BUFF_SIZE 4096

typedef struct format_struct {
  int minus;    // прижать к левому краю
  int plus;     // всегда выводить знак
  int space;    // зарезервировано место под знак
  char length;  // тип переменной (lf, Lf, Ld и т.д.)
  int width;
  int zero;  // заполнять свободное пространство нолями
  int prec;  // точность (количество знаков после запятой)
  int isprec;  // наличие точки (задана дачность)
  char spec;   //
  int hash;    // 16 или 8-ричные числа
} format_t;

void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *destinationArr, const char *sourceArr,
                  s21_size_t rightLimiterNum);
s21_size_t s21_strcspn(const char *str1, const char *str2);

void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcat(char *dest, const char *app);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sscanf(const char *str, const char *format, ...);

int s21_sprintf(char *resultStr, const char *formatStr, ...);
void parceFormatStr(const char *format, int *counters, char *resultStr,
                    va_list paramsArgs);
void parseSpecifierChar(int *counters, char *resultStr, va_list paramsArgs,
                        format_t format_data);
void parseFlags(char *temp, format_t params, char *resultStr, int *counters,
                int mode);
void hideZerosForShotFormat(char *resultStr, int *counters);
void prependMantiss(char *resultStr, int pow, char sign, int *counters);
void upperCase(char *str);
void parseMantiss(format_t params, char *resultStr, long double val,
                  int *counters);
int isZeros(char *s21_check_zeroes);

void parseSpecifierC(const char c, format_t params, char *resultStr,
                     int *counters);
void parseSpecifierD(int64_t d, format_t params, char *resultStr, int *counters,
                     int base);
void parseSpecifierF(long double f, format_t params, char *s21_check_zeroes,
                     int *counters);
void parseSpecifierG(long double f, format_t params, char *resultStr,
                     int *counters);
void parseSpecifierO(format_t params, char *s21_check_zeroes, int64_t val,
                     int *counters);
void parseSpecifierS(va_list p_args, format_t params, char *s21_check_zeroes,
                     int *counters);
void parseSpecifierU(uint64_t d, format_t params, char *s21_check_zeroes,
                     int *counters, int base);
void parseSpecifierX(format_t params, char *s21_check_zeroes, int64_t val,
                     int *counters);
void parseSpecifierP(format_t params, char *s21_check_zeroes, int64_t val,
                     int *icounters);
void parseSpecifierLC(wchar_t c1, format_t params, char *s21_check_zeroes,
                      int *counters);

#endif