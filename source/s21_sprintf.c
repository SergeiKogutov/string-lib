#include "../s21_string.h"

int s21_sprintf(char *resultStr, const char *formatStr, ...) {
  va_list paramsArgs;
  va_start(paramsArgs, formatStr);

  int counters[2] = {0, 0};

  for (; counters[0] < (int)s21_strlen(formatStr);
       counters[0]++, counters[1]++) {
    if (formatStr[counters[0]] == '%' && formatStr[counters[0] + 1] != '%') {
      parceFormatStr(formatStr, counters, resultStr, paramsArgs);
    } else if (formatStr[counters[0]] == '%' &&
               formatStr[counters[0] + 1] == '%') {
      resultStr[counters[1]] = formatStr[counters[0]];
    } else {
      resultStr[counters[1]] = formatStr[counters[0]];
    }
  }

  resultStr[counters[1]] = '\0';

  va_end(paramsArgs);
  return (int)s21_strlen(resultStr);
}

void parceFormatStr(const char *formatStr, int *counters, char *resultStr,
                    va_list paramsArgs) {
  format_t params;

  params.minus = 0;
  params.plus = 0;
  params.space = 0;
  params.zero = 0;
  params.length = ' ';
  params.width = 0;
  params.isprec = 0;
  params.prec = 0;
  params.spec = '\0';
  params.hash = 0;

  for (; counters[0] < (int)s21_strlen(formatStr) &&
         s21_strchr("cdifsugGeExXonp", formatStr[counters[0]]) == NULL;
       counters[0]++) {
    switch (formatStr[counters[0]]) {
      case '0':
        if (!params.isprec && !params.zero && !params.width) {
          params.zero = 1;
        }
        break;

      case '+':
        params.plus = 1;
        break;

      case '-':
        params.minus = 1;
        break;

      case ' ':
        params.space = 1;
        break;

      case 'l':
        params.length = 'l';
        break;

      case 'h':
        params.length = 'h';
        break;

      case 'L':
        params.length = 'L';
        break;

      case '.':
        params.isprec = 1;
        break;

      case '#':
        params.hash = 1;
        break;
    }

    if (params.isprec && formatStr[counters[0]] == '*') {
      params.prec = va_arg(paramsArgs, int);
    } else if (params.isprec &&
               (formatStr[counters[0]] > 47 && formatStr[counters[0]] < 58)) {
      params.prec = params.prec * 10 + formatStr[counters[0]] - 48;
    } else if (formatStr[counters[0]] > 47 && formatStr[counters[0]] < 58) {
      params.width = params.width * 10 + formatStr[counters[0]] - 48;
    } else if (formatStr[counters[0]] == '*') {
      params.width = va_arg(paramsArgs, int);
    }
  }

  params.spec = formatStr[counters[0]];

  parseSpecifierChar(counters, resultStr, paramsArgs, params);
}

void parseSpecifierChar(int *counters, char *resultStr, va_list paramsArgs,
                        format_t params) {
  switch (params.spec) {
    case 'c':
      parseSpecifierC(va_arg(paramsArgs, int), params, resultStr, counters);
      break;

    case 'd':
    case 'i':
      if (params.length == 'l') {
        parseSpecifierD(va_arg(paramsArgs, long int), params, resultStr,
                        counters, 10);
      } else if (params.length == 'h') {
        parseSpecifierD((short)va_arg(paramsArgs, int), params, resultStr,
                        counters, 10);
      } else if (params.length == 'L') {
        parseSpecifierD(va_arg(paramsArgs, long long), params, resultStr,
                        counters, 10);
      } else {
        parseSpecifierD(va_arg(paramsArgs, int), params, resultStr, counters,
                        10);
      }
      break;

    case 'e':
    case 'E':
      if (params.length == 'L') {
        parseMantiss(params, resultStr, va_arg(paramsArgs, long double),
                     counters);
      } else {
        parseMantiss(params, resultStr, va_arg(paramsArgs, double), counters);
      }
      break;

    case 'f':
      if (params.length == 'L') {
        parseSpecifierF(va_arg(paramsArgs, long double), params, resultStr,
                        counters);
      } else {
        parseSpecifierF(va_arg(paramsArgs, double), params, resultStr,
                        counters);
      }
      break;

    case 'g':
    case 'G':
      if (params.length == 'L') {
        parseSpecifierG(va_arg(paramsArgs, long double), params, resultStr,
                        counters);
      } else {
        parseSpecifierG(va_arg(paramsArgs, double), params, resultStr,
                        counters);
      }
      break;

    case 'o':
      if (params.length == 'l') {
        parseSpecifierD((int64_t)va_arg(paramsArgs, long int), params,
                        resultStr, counters, 8);
      } else if (params.length == 'h') {
        parseSpecifierD((short)va_arg(paramsArgs, int), params, resultStr,
                        counters, 8);
      } else {
        parseSpecifierO(params, resultStr, va_arg(paramsArgs, int64_t),
                        counters);
      }
      break;

    case 's':
      parseSpecifierS(paramsArgs, params, resultStr, counters);
      break;

    case 'u':
      if (params.length == 'l') {
        parseSpecifierD(va_arg(paramsArgs, long int), params, resultStr,
                        counters, 10);
      } else if (params.length == 'h') {
        parseSpecifierD((short)va_arg(paramsArgs, int), params, resultStr,
                        counters, 10);
      } else {
        parseSpecifierU(va_arg(paramsArgs, uint64_t), params, resultStr,
                        counters, 10);
      }
      break;

    case 'x':
    case 'X':
      parseSpecifierX(params, resultStr, va_arg(paramsArgs, int64_t), counters);
      break;

    case 'p':
      parseSpecifierP(params, resultStr, va_arg(paramsArgs, uint64_t),
                      counters);
      break;

    case 'n':
      counters[1]--;
      break;
  }

  if (params.spec == 'G' || params.spec == 'E') {
    upperCase(resultStr);
  }
}

void parseFlags(char *temp, format_t params, char *resultStr, int *counters,
                int mode) {
  int base_w = (int)s21_strlen(temp);

  if ((params.hash && (params.spec == 'x' || params.spec == 'X')) ||
      params.spec == 'p') {
    if (!isZeros(temp) || params.spec == 'p') {
      if (params.width) {
        params.width -= 2;
      }
    }
  }

  if (params.width && !params.minus) {
    for (int j = 0; j < params.width - mode - base_w; j++) {
      if (!params.zero) {
        resultStr[counters[1]++] = ' ';
      }
    }

    if ((params.hash && (params.spec == 'x' || params.spec == 'X')) ||
        params.spec == 'p') {
      if (!isZeros(temp) || params.spec == 'p') {
        resultStr[counters[1]++] = '0';
        resultStr[counters[1]++] = 'x';
      }
    }

    for (int j = 0; j < base_w; j++) {
      resultStr[counters[1]++] = temp[base_w - 1 - j];
    }
    counters[1]--;
  } else if (params.width && params.minus) {
    if ((params.hash && (params.spec == 'x' || params.spec == 'X')) ||
        params.spec == 'p') {
      if (!isZeros(temp) || params.spec == 'p') {
        resultStr[counters[1]++] = '0';
        if (params.spec == 'X') {
          resultStr[counters[1]++] = 'X';
        } else {
          resultStr[counters[1]++] = 'x';
        }
      }
    }

    for (int j = 0; j < base_w; j++) {
      resultStr[counters[1]++] = temp[base_w - 1 - j];
    }

    for (int j = 0; j < params.width - mode - base_w; j++) {
      resultStr[counters[1]++] = ' ';
    }
    counters[1]--;
  } else {
    if ((params.hash && (params.spec == 'x' || params.spec == 'X')) ||
        params.spec == 'p') {
      if (!isZeros(temp) || params.spec == 'p') {
        resultStr[counters[1]++] = '0';
        if (params.spec == 'X') {
          resultStr[counters[1]++] = 'X';
        } else {
          resultStr[counters[1]++] = 'x';
        }
      }
    }

    for (int j = 0; j < base_w; j++) {
      resultStr[counters[1]++] = temp[base_w - 1 - j];
    }
    counters[1]--;
  }
}

void hideZerosForShotFormat(char *resultStr, int *counters) {
  for (; resultStr[counters[1]] == '0' || resultStr[counters[1]] == '.';
       counters[1]--) {
    if (resultStr[counters[1]] == '.') {
      resultStr[counters[1]] = '\0';
      break;
    } else {
      resultStr[counters[1]] = '\0';
    }
  }
}

void prependMantiss(char *resultStr, int pow, char sign, int *counters) {
  resultStr[counters[1]] = 'e';
  resultStr[counters[1] + 1] = sign;
  resultStr[counters[1] + 3] = pow % 10 + '0';
  pow /= 10;
  resultStr[counters[1] + 2] = pow % 10 + '0';
  counters[1] += 3;
}

void upperCase(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') {
      *str = *str - ('a' - 'A');
    }
    str++;
  }
}

void parseMantiss(format_t params, char *resultStr, long double val,
                  int *counters) {
  int pow = 0;
  char sign = (int)val == 0 ? '-' : '+';

  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }

  if (!params.isprec) {
    params.prec = 6;
  }

  if (params.prec == 0) {
    params.width -= 3;
    parseSpecifierF(round(val), params, resultStr, counters);
    prependMantiss(resultStr, pow, sign, counters);
  } else {
    params.width -= 3;
    params.prec += 1;
    parseSpecifierF(val, params, resultStr, counters);
    prependMantiss(resultStr, pow, sign, counters);
  }
}

void parseSpecifierC(const char c, format_t params, char *resultStr,
                     int *counters) {
  if (params.width && !params.minus) {
    for (int j = 0; j < params.width - 1; j++) {
      resultStr[counters[1]] = ' ';
      counters[1]++;
    }
    resultStr[counters[1]] = c;
  } else if (params.width && params.minus) {
    resultStr[counters[1]] = c;
    counters[1]++;

    for (int j = 0; j < params.width - 1; j++) {
      resultStr[counters[1]] = ' ';
      counters[1]++;
    }

    counters[1]--;
  } else {
    resultStr[counters[1]] = c;
  }
}

void parseSpecifierD(int64_t d, format_t params, char *resultStr, int *counters,
                     int base) {
  int m = 0;

  if (d < 0 && d != 0) {
    d = -d;
    m = 1;
  }

  char temp[BUFF_SIZE] = {'\0'};
  int j = 0;

  if (d == 0) {
    temp[0] = '0';
    j++;
  } else {
    while (d != 0) {
      temp[j] = "0123456789abcdef"[d % base];
      j++;
      d /= base;
    }
  }

  int len = (int)s21_strlen(temp);

  while (len < params.prec) {
    temp[j++] = '0';
    params.prec--;
  }

  if (params.space && !m) temp[j] = ' ';
  if (params.plus && !m) temp[j] = '+';
  if (params.hash && !(params.spec == 'x' || params.spec == 'X')) temp[j] = '0';
  if (m) temp[j] = '-';

  if (params.spec == 'X') upperCase(temp);

  parseFlags(temp, params, resultStr, counters, 0);
}

void parseSpecifierF(long double f, format_t params, char *resultStr,
                     int *counters) {
  int m = 0;

  if (f < 0. && f != 0.) {
    f = -f;
    m = 1;
  }
  int count = 0;
  long double man = 0, ipartd = 0;
  long long ipart = 0;
  char temp[BUFF_SIZE] = {'\0'};

  man += modfl(f, &ipartd);
  if (params.spec == 'e' || params.spec == 'E') {
    ipart = round(ipartd);
  } else {
    ipart = ipartd;
  }
  long long del = 0;

  if (params.prec) {
    if (params.spec == 'e' || params.spec == 'E') {
      del = pow(10, params.prec - 1);
    } else {
      del = pow(10, params.prec);
    }
    man = roundl(man * del) / del;
  } else {
    del = pow(10, 6);
    man = roundl(man * del) / del;
  }

  if (!params.prec && params.isprec) {
    man = roundl(man);
  }

  int j = 0;
  if (!(!params.prec && params.isprec) ||
      (params.spec != 'f' && !params.prec)) {
    temp[j++] = '.';
  }

  if (ipart == 0) {
    temp[j++] = '0';
  }

  while (ipart != 0) {
    temp[j] = (long int)ipart % 10 + '0';
    j++;
    ipart /= 10;
  }

  if (params.space && !m) {
    temp[j] = ' ';
  }
  if (params.plus && !m) {
    temp[j] = '+';
  }
  if (m) {
    temp[j] = '-';
  }

  if (params.spec == 'f' && !params.prec) {
    count = 6;
  } else if (params.prec == 0 && params.isprec) {
    count = 1;
  } else if (params.prec) {
    count = params.prec;
  }
  parseFlags(temp, params, resultStr, counters, count);

  counters[1]++;

  if (!(!params.prec && params.isprec)) {
    long long mani = man * pow(10, count) + 0.05;
    char temp1[BUFF_SIZE] = {'\0'};

    int k = 0;
    for (; k < count; k++) {
      temp1[k] = mani % 10 + '0';
      mani /= 10;
    }
    k--;
    for (; k >= 0; k--) {
      resultStr[counters[1]++] = temp1[k];
    }
  }

  counters[1]--;
}

void parseSpecifierS(va_list p_args, format_t params, char *resultStr,
                     int *counters) {
  int j = 0;

  char *str = va_arg(p_args, char *);
  if (str != S21_NULL) {
    j = s21_strlen(str);
    if (params.width && !params.minus) {
      for (int k = 0; k < params.width - j; k++) {
        resultStr[counters[1]++] = ' ';
      }
    }
    j = 0;
    while (*str != '\0' && (!params.isprec || j < params.prec)) {
      resultStr[counters[1]++] = *str;
      str++;
      j++;
    }

    if (params.width && params.minus) {
      for (int k = 0; k < params.width - j; k++) {
        resultStr[counters[1]++] = ' ';
      }
    }
    counters[1]--;
  } else {
    s21_strncat(resultStr, "(null)", 5);
    counters[1] += 5;
  }
}

void parseSpecifierU(uint64_t d, format_t params, char *resultStr,
                     int *counters, int base) {
  if (params.length == 'l') {
    d = (uint64_t)d;
  } else if (params.length == 'h') {
    d = (uint16_t)d;
  } else if (params.length == ' ') {
    d = (uint32_t)d;
  }
  char temp[BUFF_SIZE] = {'\0'};
  int j = 0;

  if (d == 0) {
    temp[0] = '0';
    j++;
  } else {
    while (d != 0) {
      temp[j] = "0123456789abcdef"[d % base];
      j++;
      d /= base;
    }
  }

  int len = (int)s21_strlen(temp);

  while (len < params.prec) {
    temp[j++] = '0';
    params.prec--;
  }

  if (params.space) {
    temp[j] = ' ';
  }

  if (params.plus) {
    temp[j] = '+';
  }

  parseFlags(temp, params, resultStr, counters, 0);
}

void parseSpecifierG(long double f, format_t params, char *resultStr,
                     int *counters) {
  if (params.prec == 0 && params.isprec) {
    params.prec = 1;
  }

  long double m_val = f + 0.000000001;
  int pow = 0;

  if ((int)f - f) {
    while ((int)m_val == 0) {
      pow++;
      m_val *= 10;
    }
  }
  if (pow > 4) {
    params.width -= 3;
    params.prec = 0;
    parseSpecifierF(m_val, params, resultStr, counters);
  } else {
    params.prec = 10;
    parseSpecifierF(f, params, resultStr, counters);
  }
  if (pow > 4) {
    prependMantiss(resultStr, pow, '-', counters);
  }
  hideZerosForShotFormat(resultStr, counters);
}

void parseSpecifierO(format_t params, char *resultStr, int64_t val,
                     int *counters) {
  parseSpecifierD(val, params, resultStr, counters, 8);
}

void parseSpecifierX(format_t params, char *resultStr, int64_t val,
                     int *counters) {
  parseSpecifierD(val, params, resultStr, counters, 16);
}

int isZeros(char *resultStr) {
  int result = 1;
  for (int cnt = 0; resultStr[cnt]; cnt++) {
    if (resultStr[cnt] != '0') {
      result = 0;
    }
  }
  return result;
}

void parseSpecifierP(format_t params, char *resultStr, int64_t val,
                     int *counters) {
  if (val)
    parseSpecifierD(val, params, resultStr, counters, 16);
  else {
    s21_memset(resultStr, 0, 1);
    s21_strncat(resultStr, "(nil)", 5);
    counters[1] += 6;
  }
}