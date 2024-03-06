#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct token {
  bool star;
  int width;
  char lenght;
  char modifier;
} Token;

#define LLONG_MAX 0x7fffffffffffffff
#define LLONG_MIN (-LLONG_MAX - 1LL)
#define ULLONG_MAX 0xffffffffffffffff
#define INT_MAX 0x7fffffff

#include "../s21_string.h"

void caseModif(char *f, Token *t) {
  switch (*f) {
    case 'c':
      t->modifier = 'c';
      break;
    case 'd':
      t->modifier = 'd';
      break;
    case 'i':
      t->modifier = 'i';
      break;
    case 'E':
      t->modifier = 'E';
      break;
    case 'e':
      t->modifier = 'e';
      break;
    case 'f':
      t->modifier = 'f';
      break;
    case 'g':
      t->modifier = 'g';
      break;
    case 'G':
      t->modifier = 'G';
      break;
    case 'o':
      t->modifier = 'o';
      break;
    case 's':
      t->modifier = 's';
      break;
    case 'u':
      t->modifier = 'u';
      break;
    case 'x':
      t->modifier = 'x';
      break;
    case 'X':
      t->modifier = 'X';
      break;
    case 'p':
      t->modifier = 'p';
      break;
    case 'n':
      t->modifier = 'n';
      break;
    default:
      break;
  }
}

bool isDigit(char c, int base) {
  bool res;
  if (base <= 10) {
    res = c >= '0' && c < '0' + base;
  } else {
    res = (c >= 'a' && c < 'a' + base - 10) ||
          (c >= 'A' && c < 'A' + base - 10) || (c >= '0' && c <= '9');
  }
  return res;
}

bool scanInt(char **str, int width, long long *dest) {
  bool flag = false, find = false, neg = false;
  if (width == 0) {
    width = INT_MAX;
  }
  long long res = 0;
  if (**str == '-') {
    neg = true;
    (*str)++;
    width--;
  } else if (**str == '+') {
    (*str)++;
    width--;
  }

  if (isDigit(**str, 10)) {
    find = true;
  }
  if (find) {
    while (isDigit(**str, 10) && width--) {
      if (res > (LLONG_MAX - (**str - '0')) / 10) {
        find = false;
        flag = true;
        res = LLONG_MAX;
        if (neg) res = -res - 1;
        while (**str && width--) (str)++;
        break;
      }
      res = res * 10 + (**str - '0');
      (*str)++;
    }
  }
  if (neg) {
    res = -res;
  }
  if (find || flag) {
    *dest = res;
  }
  return find || flag;
}

bool parseInt(Token t, char **str, va_list ap) {
  long long res = 0;
  bool result = scanInt(str, t.width, &res);

  if (result) switch (t.lenght) {
      case 'h':
        *(va_arg(ap, short *)) = (short)res;
        break;
      case 'l':
        *(va_arg(ap, long *)) = (long)res;
        break;
      case 'L':
        *(va_arg(ap, long long *)) = (long long)res;
        break;
      default:
        *(va_arg(ap, int *)) = (int)res;
        break;
    }
  return result;
}

bool parseString(Token t, char **str, va_list ap) {
  bool result = false;
  int index = 0;
  char *d = va_arg(ap, char *);
  if (t.width == 0) {
    if (t.modifier == 'c') {
      t.width = 1;
    } else {
      t.width = s21_strlen((const char *)str);
    }
  }
  while (*str && t.width > 0 && *str[0] != ' ') {
    d[index] = *str[0];
    (*str)++;
    index++;
    t.width--;
  }
  if (t.modifier == 's') {
    d[index] = '\0';
  }
  result = true;
  return result;
}

char chrLower(char c) {
  if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
  return c;
}

bool strstrIcase(char **str, char *pat) {
  bool res = false;
  char *s = *str;
  while (*s && chrLower(*s) == chrLower(*pat)) s++, pat++;
  if (*pat == '\0') *str = s, res = true;
  return res;
}

bool nanInf(char **str, long double *dest) {
  bool res = false;
  if (strstrIcase(str, "nan")) res = true, *dest = NAN;
  if (strstrIcase(str, "inf")) res = true, *dest = INFINITY;
  return res;
}

long double s21_atof(char **str, int *width) {
  long double res = 0;
  while (isDigit(**str, 10) && width) {
    res = res * 10 + (**str - '0');
    (*str)++;
    (*width)--;
  }
  if (**str == '.') {
    (*str)++;
    (*width)--;
    long double frac_coef = 1;
    int frac_width = 0;
    while (isDigit(*(*str + frac_width), 10) && (*width)--) frac_width++;
    while (frac_width--) {
      frac_coef /= 10;
      res += frac_coef * (**str - '0');
      (*str)++;
    }
  }
  return res;
}

bool scientific(char **str, int *width, long double *res) {
  long long exp = 0;
  bool find = false;

  if (**str == 'e' || **str == 'E') {
    (*str)++, (*width)--, find = scanInt(str, *width, &exp);
  }
  *res *= pow(10, exp);
  return find;
}

bool scanFloat(char **str, int width, long double *dest) {
  bool find = false;
  bool neg = false;
  long double res = 0;
  if (**str == '-') {
    neg = true;
    (*str)++;
    width--;
  } else if (**str == '+') {
    (*str)++;
    width--;
  }
  if (nanInf(str, &res)) find = true;
  if (isDigit(**str, 10) || **str == '.') {
    find = true;
    res = s21_atof(str, &width);
    scientific(str, &width, &res);
  }
  if (find) {
    if (neg) res = -res;
    *dest += res;
  }
  return find;
}

bool parseFloat(Token t, char **str, va_list ap) {
  bool res = false;
  if (t.width == 0) {
    t.width = INT_MAX;
  }
  long double res_d = 0;
  res = scanFloat(str, t.width, &res_d);
  if (res) switch (t.lenght) {
      case 'h':
        *(va_arg(ap, float *)) = (float)res_d;
        break;
      case 'l':
        *(va_arg(ap, double *)) = (double)res_d;
        break;
      case 'L':
        *(va_arg(ap, long double *)) = res_d;
        break;
      default:
        *va_arg(ap, double *) = (double)res_d;
        break;
    }

  return res;
}

s21_size_t toDigit(char c, int base) {
  s21_size_t res = 0;
  if (base <= 10) {
    res = c - '0';
  } else {
    if (c <= '9') {
      res = c - '0';
    } else {
      res = c - 'a' + 10;
    }
  }
  return res;
}

bool scanBasedUint(char **str, int width, unsigned long long *dest, int base,
                   bool neg) {
  bool find = false;
  if (width == 0) width = INT_MAX;
  unsigned long long res = 0;
  if (isDigit(**str, base)) {
    find = true;
  }
  if (find) {
    while (isDigit(**str, base) && width--) {
      res = res * base + toDigit(**str, base);
      (*str)++;
    }
    if (neg) {
      res = res * -1;
    }
    *dest = res;
  }
  return find;
}

bool parseBasedUint(Token t, char **str, va_list ap, int base, bool neg) {
  unsigned long long res = 0;
  bool result = scanBasedUint(str, t.width, &res, base, neg);
  if (result) switch (t.lenght) {
      case 'h':
        *(va_arg(ap, unsigned short *)) = (unsigned short)res;
        break;
      case 'l':
        *(va_arg(ap, unsigned long *)) = (unsigned long)res;
        break;
      case 'L':
        *(va_arg(ap, unsigned long long *)) = (unsigned long long)res;
        break;
      default:
        *(va_arg(ap, unsigned int *)) = (unsigned int)res;
        break;
    }
  return result;
}

bool parseUint(Token t, char **str, va_list ap) {
  bool res = false;
  bool f = true;
  bool neg = false;
  if (**str == '-') {
    (*str)++;
    t.width--;
    neg = true;
  } else if (**str == '+') {
    (*str)++;
    t.width--;
  }
  if (f) {
    res = parseBasedUint(t, str, ap, 10, neg);
  }
  return res;
}

bool parseXx(Token t, char **str, va_list ap) {
  bool neg = false;
  bool res = neg;
  if (**str == '-' && !neg) {
    (*str)++;
    t.width--;
    neg = true;
  } else if (**str == '+') {
    (*str)++;
    t.width--;
  }
  if (**str == '0' && ((*(*str + 1) == 'x') || *(*str + 1) == 'X')) {
    *str += 2;
    res |= true;
  }
  res |= parseBasedUint(t, str, ap, 16, neg);
  return res;
}

bool parseOct(Token t, char **str, va_list ap) {
  bool neg = false;
  if (**str == '-') {
    neg = true;
    (*str)++;
    t.width--;
  } else if (**str == '+') {
    (*str)++;
    t.width--;
  }
  bool res = neg;
  if (**str == '0') {
    (*str)++;
    t.width--;
    res |= true;
  }
  res |= parseBasedUint(t, str, ap, 8, neg);
  return res;
}

bool parseIUint(Token t, char **str, va_list ap) {
  bool res = false;
  if (**str == '0') {
    (*str)++;
    if (**str == 'x') {
      (*str)++;
      res = parseXx(t, str, ap);
    } else {
      res = parseOct(t, str, ap);
    }
  } else {
    res = parseUint(t, str, ap);
  }
  return res;
}

bool parsePtr(Token t, char **str, va_list ap) {
  t.lenght = 'l';
  return parseXx(t, str, ap);
}

int caseRes(char **s, Token t, va_list ap, char *start) {
  int r = 0;
  if (*s) switch (t.modifier) {
      case 'c':
        parseString(t, s, ap);
        break;
      case 'd':
        parseInt(t, s, ap);
        break;
      case 'i':
        parseIUint(t, s, ap);
        break;
      case 'E':
        parseFloat(t, s, ap);
        break;
      case 'e':
        parseFloat(t, s, ap);
        break;
      case 'f':
        parseFloat(t, s, ap);
        break;
      case 'g':
        parseFloat(t, s, ap);
        break;
      case 'G':
        parseFloat(t, s, ap);
        break;
      case 'o':
        parseOct(t, s, ap);
        break;
      case 's':
        parseString(t, s, ap);
        break;
      case 'u':
        parseUint(t, s, ap);
        break;
      case 'x':
        parseXx(t, s, ap);
        break;
      case 'X':
        parseXx(t, s, ap);
        break;
      case 'p':
        parsePtr(t, s, ap);
        break;
      case 'n':
        *va_arg(ap, long int *) = s21_strlen(*s) - s21_strlen(start);
        break;
      default:
        break;
    }
  return r;
}

int s21_sscanf(const char *str, const char *format, ...) {
  int result = *str ? 0 : -1;
  va_list ap;
  int couter = 0;
  char *s = (char *)str;
  char *start = (char *)str;
  char *param = (char *)format;
  va_start(ap, *format);
  while (s && *param && result != -1) {
    couter++;
    if (*param == '%') {
      param++;
      Token t = {false, 0, 0, ' '};
      if (*param == '*') {
        t.star = true;
        param++;
      } else if (*param == 'h' || *param == 'l' || *param == 'L') {
        if (*param == 'h') {
          t.lenght = 'h';
          param++;
        } else if (*param == 'l') {
          t.lenght = 'l';
          param++;
        } else if (*param == 'L') {
          t.lenght = 'L';
          param++;
        }
      }
      if (*param >= 1 || *param <= 9) {
        if (*param != 'c' && *param != 'f' && *param != 'd' && *param != 'i' &&
            *param != 'X' && *param != 'x' && *param != 'G' && *param != 'g' &&
            *param != 'o' && *param != 'u' && *param != 'e' && *param != 'E' &&
            *param != 's' && *param != 'p' && *param != 'n' && *param != '%') {
          t.width = 0 * 10 + (param[0] - '0');
          param++;
        }
      }

      caseModif(param, &t);
      if (t.modifier != 'c') {
        while (s[0] == ' ') {
          s++;
        }
      }
      caseRes(&s, t, ap, start);
      if (t.modifier == 'n') {
        couter--;
      }
      s++;
      param++;
    }
    if (*param == ' ') {
      param++;
    } else if (*s == ' ') {
      s++;
    } else {
      break;
    }
  }
  va_end(ap);
  return couter;
}