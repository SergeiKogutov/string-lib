#include "s21_string.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

START_TEST(s21_memchr_test) {
  char test1[] = "TT";
  char test2 = 'M';
  char test3 = 'r';
  char test4[] = "8919/\0";
  char test5[] = "?";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  char test_8[] = "";
  char test_10[] = "1";
  char test_11 = '1';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 10),
                    (unsigned long)memchr(test1, test2, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 10),
                    (unsigned long)memchr(test1, test3, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 7),
                    (unsigned long)memchr(test4, test6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 7),
                    (unsigned long)memchr(test4, test8, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 7),
                    (unsigned long)memchr(test4, test9, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_8, test7, 1),
                    (unsigned long)memchr(test_8, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_10, test_11, 1),
                    (unsigned long)memchr(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[BUFF_SIZE] = "Vengeful_Spirit";
  char test_2[BUFF_SIZE] = "  ";
  char test_3[BUFF_SIZE] = "///  ";
  char test_4[BUFF_SIZE] = "   & ///";
  char test_5[BUFF_SIZE] = "";
  char test_6[BUFF_SIZE] = "8922486";
  char test_7[BUFF_SIZE] = "5526\0123";
  char test_8[BUFF_SIZE] = "";
  char test_9[BUFF_SIZE] = "";
  char test_10[BUFF_SIZE] = "1";
  char test_11[BUFF_SIZE] = "1";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_6, test_7, 4), memcpy(test_6, test_7, 4));
  ck_assert_str_eq(s21_memcpy(test_8, test_9, 1), memcpy(test_8, test_9, 1));
  ck_assert_str_eq(s21_memcpy(test_10, test_11, 1),
                   memcpy(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[BUFF_SIZE] = "It's hard to be god";
  char test2[BUFF_SIZE] = "Code like god";
  char test3[] = "\0";
  char test4[] = "Wanna\0 sleep";
  char test5[] = "Wanna\0 sleep";
  char test_8[] = "";
  char test_9[] = "";
  char test_10[] = "1";
  char test_11[] = "1";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 14), memcmp(test1, test2, 14));
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
  ck_assert_uint_eq(s21_memcmp(test_8, test_9, 1) == 0,
                    memcmp(test_8, test_9, 1) == 0);
  ck_assert_uint_eq(s21_memcmp(test_10, test_11, 1) == 0,
                    memcmp(test_10, test_11, 1) == 0);
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "Jonny WTF";
  unsigned char test2[10] = "Lochanta";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '-', 10),
                    (unsigned long)memset(test1, '-', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '6', 10),
                    (unsigned long)memset(test1, '6', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(test2, '!', 6),
                    (unsigned long)memset(test2, '!', 6));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '9', 0),
                    (unsigned long)memset(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, 'a', 5),
                    (unsigned long)memset(test1, 'a', 5));
  ck_assert_uint_eq((unsigned long)s21_memset(test2, '>', 3),
                    (unsigned long)memset(test2, '>', 3));
  ck_assert_uint_eq((unsigned long)s21_memset(test2, ' ', 1),
                    (unsigned long)memset(test2, ' ', 1));
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "BrewMaster";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = " ";
  char test_5[] = "123\0456";
  char test_6[] = "qqq\\\0";
  char test_8[] = "";
  char test_10[] = "1";

  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
  ck_assert_int_eq(s21_strlen(test_8), strlen(test_8));
  ck_assert_int_eq(s21_strlen(test_10), strlen(test_10));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "9876 54326 10";
  char test2[] = "a;b;c;d;e;f;g;h;i;j;h";
  char test3[] = " $ ! @ # $ ^ & * ( $ ) $ ";
  char test4[] = "$";

  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'h'),
                    (unsigned long)strrchr(test2, 'h'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, '$'),
                    (unsigned long)strrchr(test3, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test4, '$'),
                    (unsigned long)strrchr(test4, '$'));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "Monkey King";
  char test_2[] = "king";
  char test_3[] = "AssassinAsssasssinAsasin";
  char test_4[] = "Assassin";
  char test_5[] = "1234";
  char test_6[] = "";
  char test_7[] = "5123451234512345";
  char test_8[] = "1234";
  char test_9[] = "1";
  char test_10[] = "4";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
  ck_assert_ptr_eq(s21_strstr(test_8, test_9), strstr(test_8, test_9));
  ck_assert_ptr_eq(s21_strstr(test_8, test_10), strstr(test_8, test_10));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_1[16] = "Happy";
  char test_2[16] = " New Year";
  char test_3[2] = "5";
  char test_4[] = "";
  char str1[99] = "Regular";
  char str2[99] = "Regular";
  char str3[] = " normal mother";
  char str4[99] = "";
  char str5[99] = "";
  char str6[99] = "1";
  char str7[99] = "1";

  ck_assert_str_eq(strncat(str1, str3, 4), s21_strncat(str2, str3, 4));
  ck_assert_str_eq(strncat(str4, str5, 3), s21_strncat(str4, str5, 3));
  ck_assert_str_eq(strncat(str6, str7, 0), s21_strncat(str6, str7, 0));
  ck_assert_str_eq(s21_strncat(test_1, test_2, 9), "Happy New Year");
  ck_assert_str_eq(s21_strncat(test_3, test_4, 0), strncat(test_3, test_4, 0));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "Earth Spirit";
  char str2[] = "EarthShaker";
  char str3[] = "EarthShaker\0";
  char str4[] = "";
  char str5[] = "";

  ck_assert_int_eq(s21_strncmp(str1, str2, 5) == 0,
                   strncmp(str1, str2, 5) == 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
  ck_assert_int_eq(s21_strncmp(str1, str3, 10) > 0,
                   strncmp(str1, str3, 10) > 0);
  ck_assert_int_eq(s21_strncmp(str4, str5, 1) == 0,
                   strncmp(str4, str5, 1) == 0);
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Templar Assasin";
  char str_oneof[] = "Ass";
  char *str = "This is the road to hell";
  char *empty = "";
  char *empty2 = "T";
  char *empty3 = "l";

  char str_oneof2[] = "Of";

  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "Assasin");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));
  char str_for_strpbrk2[] = "State Of New York";

  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk2, str_oneof2),
                   strpbrk(str_for_strpbrk2, str_oneof2));

  ck_assert(s21_strpbrk(str, empty) == S21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty2),
                    (unsigned long)strpbrk(str, empty2));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty3),
                    (unsigned long)strpbrk(str, empty3));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Dota2";
  int symbol1 = 'o';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "ota2");

  char str2[] = "Dota2";
  int symbol2 = 'o';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);

  char str5[] = "abcd";
  int symbol5 = 'a';
  char *ach5 = s21_strchr(str5, symbol5);
  char str6[] = "abcd";
  int symbol6 = 'a';
  char *ach6 = strchr(str6, symbol6);
  ck_assert_str_eq(ach5, ach6);
  ck_assert_str_eq(str5, str6);

  char str7[] = "abcd";
  int symbol7 = 'd';
  char *ach7 = s21_strchr(str7, symbol7);
  char str8[] = "abcd";
  int symbol8 = 'd';
  char *ach8 = strchr(str8, symbol8);
  ck_assert_str_eq(ach7, ach8);
  ck_assert_str_eq(str7, str8);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "DawnBreaker";
  char test2[] = "Dawn";
  char test3[] = "Primal Beast";
  char test4[] = "beast";
  char test5[] = "0/";
  char test6[] = "//#";
  char test7[] = " ";
  char test8[] = "0987654321";
  char test9[] = "0";
  char test10[] = "1";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
  ck_assert_uint_eq(s21_strcspn(test8, test9), strcspn(test8, test9));
  ck_assert_uint_eq(s21_strcspn(test8, test10), strcspn(test8, test10));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "Anti-mage/Medusa/Clinkz(Weaver)Witch Doctor";
  char delim1[] = "/";

  char str_strtok2[] = "Anti-mage/Medusa/Clinkz(Weaver)Witch Doctor";
  char delim2[] = "/";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim1);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}

END_TEST

START_TEST(s21_strncpy_test) {
  char sourceStr1[] = "Bond, James Bond";
  char sourceStr2[] = "Bond \0";
  char sourceStr3[] = " Bond ";
  char sourceStr4[] = "D";
  char sourceStr5[] = "pulllRequest";
  char destinationStr[80];

  ck_assert_str_eq("Bond,", s21_strncpy(destinationStr, sourceStr1, 5));
  ck_assert_str_eq("Bond ", s21_strncpy(destinationStr, sourceStr2, 5));
  ck_assert_str_eq(" ", s21_strncpy(destinationStr, sourceStr3, 1));
  ck_assert_str_eq("D", s21_strncpy(destinationStr, sourceStr4, 1));
  ck_assert_str_eq(strncpy(destinationStr, sourceStr5, 20),
                   s21_strncpy(destinationStr, sourceStr5, 20));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(3);
  char *case10 = strerror(3);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(100);
  char *case8 = strerror(100);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  char *case5 = s21_strerror(INT_MAX);
  char *case6 = strerror(INT_MAX);
  ck_assert_uint_eq((unsigned long)*case5, (unsigned long)*case6);

  char *case11 = s21_strerror(-1);
  char *case12 = strerror(-1);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char bufferStr1[80];
  char bufferStr2[80];
  char sourceStr[] = "Hello, world!";
  sprintf(bufferStr1, "%s", sourceStr);
  s21_sprintf(bufferStr2, "%s", sourceStr);
  ck_assert_str_eq(bufferStr1, sourceStr);
  s21_sprintf(bufferStr2, "%s", sourceStr);
  ck_assert_str_eq(bufferStr2, sourceStr);
}
END_TEST

START_TEST(s21_trim_test) {
  char *result;
  char *banner = " \n   !* * *'\' Much Ado About Nothing * * '\'*  !\n";
  result = s21_trim(banner, " *!\n '\'");
  if (result) {
    ck_assert_str_eq(result, "Much Ado About Nothing");
    free(result);
  }

  char *banner2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  result = s21_trim(banner2, format_str);
  if (result) {
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
  }

  char *banner3 = "  Hello, world!  ";
  char *format_str2 = "  ";
  result = s21_trim(banner3, format_str2);
  if (result) {
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
  }
}

START_TEST(s21_to_upper_test) {
  char str1[] = "everything seems imposible until it's done";
  char str2[] = "dota2forever";
  char str3[] = "";
  char str4[] = "a";
  char str5[] = "13123";

  char *str = s21_to_upper(str1);

  if (str) {
    ck_assert_str_eq(str, "EVERYTHING SEEMS IMPOSIBLE UNTIL IT'S DONE");
    free(str);
  }

  str = s21_to_upper(str2);

  if (str) {
    ck_assert_str_eq(str, "DOTA2FOREVER");
    free(str);
  }
  str = s21_to_upper(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_upper(str4);

  if (str) {
    ck_assert_str_eq(str, "A");
    free(str);
  }

  str = s21_to_upper(str5);

  if (str) {
    ck_assert_str_eq(str, "13123");
    free(str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "EVERYTHING SEEMS IMPOSIBLE UNTIL IT'S DONE";
  char str2[] = "DOTA2FOREVER";
  char str3[] = "";
  char str4[] = "A";
  char str5[] = "13123";
  char *str = s21_to_lower(str1);
  if (str) {
    ck_assert_str_eq(str, "everything seems imposible until it's done");
    free(str);
  }

  str = s21_to_lower(str2);

  if (str) {
    ck_assert_str_eq(str, "dota2forever");
    free(str);
  }
  str = s21_to_lower(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_lower(str4);

  if (str) {
    ck_assert_str_eq(str, "a");
    free(str);
  }

  str = s21_to_lower(str5);

  if (str) {
    ck_assert_str_eq(str, "13123");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Regular!";
  char *str = ", brain";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brain!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", brain!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brain!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", brain!!", 35);
  ck_assert(new_str == S21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "2555";
  char *str1 = "13";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "213555");
    free(new_str2);
  }
}

START_TEST(s21_sscanf_test_d) {
  int a, b, c, d;

  int result = s21_sscanf(" -65 65", "%d %d", &a, &b);
  int result_orig = sscanf(" -65 65", "%d %d", &c, &d);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long int a1, b1, c1, d1;

  result = s21_sscanf(" +5 65", "%ld %ld", &a1, &b1);
  result_orig = sscanf(" +5 65", "%ld %ld", &c1, &d1);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(a1, c1);
  ck_assert_int_eq(b1, d1);

  long long int a2, b2, c2, d2;

  result = s21_sscanf(" -65 65", "%Ld %Ld", &a2, &b2);
  result_orig = sscanf(" -65 65", "%lld %lld", &c2, &d2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(a2, c2);
  ck_assert_int_eq(b2, d2);

  short int a3, b3, c3, d3;

  result = s21_sscanf(" -65 65", "%hd %hd", &a3, &b3);
  result_orig = sscanf(" -65 65", "%hd %hd", &c3, &d3);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(a3, c3);
  ck_assert_int_eq(b3, d3);
}
END_TEST

START_TEST(s21_sscanf_test_i) {
  int i, i2;

  int result = s21_sscanf("111", "%i", &i);
  int result_orig = sscanf("111", "%i", &i2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(i, i2);

  long int i1, i3;

  result = s21_sscanf("-111", "%li", &i3);
  result_orig = sscanf("-111", "%li", &i1);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(i1, i3);

  short int o4, o5;

  result = s21_sscanf("1e11", "%hi", &o5);
  result_orig = sscanf("1e11", "%hi", &o4);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(o4, o5);
  s21_sscanf("0111", "%hi", &o5);
  s21_sscanf("0x111", "%x", &o5);
  s21_sscanf("ee111", "%f", &o5);
}
END_TEST

START_TEST(s21_sscanf_test_f) {
  float ax = 0;
  float bx = 0;
  float cx = 0;
  float dx = 0;

  int result = s21_sscanf("-12.2 12.2", "%hf %hf", &ax, &bx);
  int result_orig = sscanf("-12.2 12.2", "%f %f", &cx, &dx);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax, cx);
  ck_assert_int_eq(bx, dx);

  double ax1 = 0;
  double bx1 = 0;
  double cx1 = 0;
  double dx1 = 0;

  result = s21_sscanf("-12.2 12.2", "%lf %lf", &ax1, &bx1);
  result_orig = sscanf("-12.2 12.2", "%lf %lf", &cx1, &dx1);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax1, cx1);
  ck_assert_int_eq(bx1, dx1);

  long double ax2 = 0;
  long double bx2 = 0;
  long double cx2 = 0;
  long double dx2 = 0;

  result = s21_sscanf("-12.2 12.2", "%Lf %Lf", &ax2, &bx2);
  result_orig = sscanf("-12.2 12.2", "%Lf %Lf", &cx2, &dx2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax2, cx2);
  ck_assert_int_eq(bx2, dx2);

  double ax3 = 0;
  double bx3 = 0;
  double cx3 = 0;
  double dx3 = 0;

  result = s21_sscanf("-12.2 12.2", "%f %f", &ax3, &bx3);
  result_orig = sscanf("-12.2 12.2", "%lf %lf", &cx3, &dx3);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax3, cx3);
  ck_assert_int_eq(bx3, dx3);
}
END_TEST

START_TEST(s21_sscanf_test_g) {
  float ax = 0;
  float bx = 0;
  float cx = 0;
  float dx = 0;

  int result = s21_sscanf("-12.2 12.2", "%hg %hg", &ax, &bx);
  int result_orig = sscanf("-12.2 12.2", "%g %g", &cx, &dx);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax, cx);
  ck_assert_int_eq(bx, dx);
}
END_TEST

START_TEST(s21_sscanf_test_G) {
  float ax = 0;
  float bx = 0;
  float cx = 0;
  float dx = 0;

  int result = s21_sscanf("-12.2 12.2", "%hG %hG", &ax, &bx);
  int result_orig = sscanf("-12.2 12.2", "%G %G", &cx, &dx);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax, cx);
  ck_assert_int_eq(bx, dx);
}
END_TEST

START_TEST(s21_sscanf_test_e) {
  float ax = 0;
  float bx = 0;
  float cx = 0;
  float dx = 0;

  int result = s21_sscanf("-12.2 12.2", "%he %he", &ax, &bx);
  int result_orig = sscanf("-12.2 12.2", "%e %e", &cx, &dx);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax, cx);
  ck_assert_int_eq(bx, dx);
}
END_TEST

START_TEST(s21_sscanf_test_E) {
  float ax = 0;
  float bx = 0;
  float cx = 0;
  float dx = 0;

  int result = s21_sscanf("+12.2 12.2", "%hE %hE", &ax, &bx);
  int result_orig = sscanf("+12.2 12.2", "%E %E", &cx, &dx);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(ax, cx);
  ck_assert_int_eq(bx, dx);
}
END_TEST

START_TEST(s21_sscanf_test_x) {
  int x, x2;

  int result = s21_sscanf("111", "%x", &x);
  int result_orig = sscanf("111", "%x", &x2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(s21_sscanf_test_X) {
  int X, X2;

  int result = s21_sscanf("111", "%X", &X);
  int result_orig = sscanf("111", "%X", &X2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(X, X2);
}
END_TEST

START_TEST(s21_sscanf_test_c) {
  char c1, c2;

  int result = s21_sscanf("&", "%c", &c1);
  int result_orig = sscanf("&", "%c", &c2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_uint_eq(c1, c2);

  char c4, c3;

  result = s21_sscanf("A", "%c", &c3);
  result_orig = sscanf("A", "%c", &c4);
  ck_assert_int_eq(result, result_orig);
  ck_assert_uint_eq(c4, c3);
}
END_TEST

START_TEST(s21_sscanf_test_o) {
  int o, o2;

  int result = s21_sscanf("111", "%o", &o);
  int result_orig = sscanf("111", "%o", &o2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(o, o2);

  long int o1, o3;

  result = s21_sscanf("-111", "%lo", &o1);
  result_orig = sscanf("-111", "%lo", &o3);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(o1, o3);

  short int o4, o5;

  result = s21_sscanf("+111", "%ho", &o5);
  result_orig = sscanf("+111", "%ho", &o4);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(o4, o5);

  long long int o6, o7;

  result = s21_sscanf("0111", "%Lo", &o6);
  result_orig = sscanf("0111", "%llo", &o7);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(o6, o7);
}
END_TEST

START_TEST(s21_sscanf_test_p) {
  void **p, *p2;

  int result = s21_sscanf("111", "%p", &p);
  int result_orig = sscanf("111", "%p", &p2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_ptr_eq(p, p2);
}
END_TEST

START_TEST(s21_sscanf_test_u) {
  int u, u2;

  int result = s21_sscanf("111", "%u", &u);
  int result_orig = sscanf("111", "%u", &u2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(u, u2);

  long int u1, u3;

  result = s21_sscanf("111", "%lu", &u1);
  result_orig = sscanf("111", "%lu", &u3);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(u1, u3);

  long long int u4, u5;

  result = s21_sscanf("111", "%Lu", &u4);
  result_orig = sscanf("111", "%llu", &u5);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(u5, u4);

  short int u6, u7;

  result = s21_sscanf("111", "%hu", &u6);
  result_orig = sscanf("111", "%hu", &u7);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(u6, u7);
}
END_TEST

START_TEST(s21_sscanf_test_n) {
  int i, i2;

  int result = s21_sscanf("111", "%n", &i);
  int result_orig = sscanf("111", "%n", &i2);
  ck_assert_int_eq(result, result_orig);
  ck_assert_int_eq(i, i2);
}
END_TEST

START_TEST(sprintf_c_check) {
  char str[5100];
  char str2[5100];
  sprintf(str, "%11c %c", 'A', 'b');
  s21_sprintf(str2, "%11c %c", 'A', 'b');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c %97c", 'n', 'j');
  s21_sprintf(str2, "%c %97c", 'n', 'j');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c", 'j', 'z');
  s21_sprintf(str2, "%-c %-3c", 'j', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  s21_sprintf(str2, "%-c %-3c %c %c %c %c", 'j', 'z', 'z', 'z', 'z', 'z');
  ck_assert_str_eq(str, str2);
  sprintf(str, "%c", 'A');
  s21_sprintf(str2, "%c", 'A');
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_d_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%d", 0);
  s21_sprintf(str2, "%d", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", 4);
  s21_sprintf(str2, "%d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d", -4);
  s21_sprintf(str2, "%d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3d", 4);
  s21_sprintf(str2, "%-10.3d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3d", -4);
  s21_sprintf(str2, "%-10.3d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10d", 4);
  s21_sprintf(str2, "%-3.10d", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10d", -4);
  s21_sprintf(str2, "%-3.10d", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.2d", 4000000);
  s21_sprintf(str2, "%+.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.d", 4000000);
  s21_sprintf(str2, "%+2.d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0d", 0);
  s21_sprintf(str2, "%0d", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.2d", -4000000);
  s21_sprintf(str2, "%+.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15d", 4000000);
  s21_sprintf(str2, "%15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15d", -4000000);
  s21_sprintf(str2, "%16.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15d", -4000000);
  s21_sprintf(str2, "%15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2d", -4000000);
  s21_sprintf(str2, "%12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2d", 4000000);
  s21_sprintf(str2, "%12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12d", 4000000);
  s21_sprintf(str2, "%2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12d", -4000000);
  s21_sprintf(str2, "%2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2d", 4000000);
  s21_sprintf(str2, "%2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2d", -4000000);
  s21_sprintf(str2, "%2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", 4000000);
  s21_sprintf(str2, "%+2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+2.2d", -4000000);
  s21_sprintf(str2, "%+2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%d%%", 4000000);
  s21_sprintf(str2, "%d%%", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2d", 4000000);
  s21_sprintf(str2, "%.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", -4000000);
  s21_sprintf(str2, "%+-2.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15d", 4000000);
  s21_sprintf(str2, "%-15.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15d", -4000000);
  s21_sprintf(str2, "%-15.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2d", -4000000);
  s21_sprintf(str2, "%-12.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2d", 4000000);
  s21_sprintf(str2, "%-12.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12d", 4000000);
  s21_sprintf(str2, "%-2.12d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12d", -4000000);
  s21_sprintf(str2, "%-2.12d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2.2d", 4000000);
  s21_sprintf(str2, "%+-2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-d%%", 4000000);
  s21_sprintf(str2, "%-d%%", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2d", 4000000);
  s21_sprintf(str2, "%-.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.*d", 2, 4000000);
  s21_sprintf(str2, "%-.*d", 2, 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2d", 4000000);
  s21_sprintf(str2, "%-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10d", 4000000);
  s21_sprintf(str2, "%-10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-2d", 4000000);
  s21_sprintf(str2, "%+-2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10d", 4000000);
  s21_sprintf(str2, "%+-10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10d", 4000000);
  s21_sprintf(str2, "%11.10d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "% 2.2d", 4000000);
  s21_sprintf(str2, "% 2.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15d", -4000000);
  s21_sprintf(str2, "%.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15d", 4000000);
  s21_sprintf(str2, "%.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.15d", 4000000);
  s21_sprintf(str2, "%+.15d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.15d", -4000000);
  s21_sprintf(str2, "%+.15d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2d", 4000000);
  s21_sprintf(str2, "%15.2d", 4000000);
  sprintf(str, "%+15.2d", 4000000);
  s21_sprintf(str2, "%+15.2d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+15.2d", -4000000);
  s21_sprintf(str2, "%+15.2d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8d", -4000000);
  s21_sprintf(str2, "%15.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8d", -4000000);
  s21_sprintf(str2, "%-.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+.8d", 4000000);
  s21_sprintf(str2, "%+.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-.8d", 4000000);
  s21_sprintf(str2, "%+-.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-11d", -4000000);
  s21_sprintf(str2, "%+-11d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", 4000000);
  s21_sprintf(str2, "%+-10.8d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10.8d", -4000000);
  s21_sprintf(str2, "%+-10.8d", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+13.10d", -4000000);
  s21_sprintf(str2, "%+13.10d", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-11.11d", 4000000);
  s21_sprintf(str2, "%+-11.11d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-5.11d", 4000000);
  s21_sprintf(str2, "%+-5.11d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-9.7d", 4000000);
  s21_sprintf(str2, "%+-9.7d", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  s21_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_i_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%i", 4);
  s21_sprintf(str2, "%i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10i", 4);
  s21_sprintf(str2, "%10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%+-10i", 4);
  s21_sprintf(str2, "%-+10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10i", 4);
  s21_sprintf(str2, "%-10i", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%1Li", (long long int)4);
  s21_sprintf(str2, "%1Li", (long long int)4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_e_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%.2e", 4000.1);
  s21_sprintf(str2, "%.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2e", -4000.1);
  s21_sprintf(str2, "%.2e", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10e", 1.0);
  s21_sprintf(str2, "%10e", 1.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%e", 1.123123);
  s21_sprintf(str2, "%e", 1.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%e", 0.123123);
  s21_sprintf(str2, "%e", 0.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%e", 0.);
  s21_sprintf(str2, "%e", 0.);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#E", 0.0);
  s21_sprintf(str2, "%#E", 0.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#.10e", 0.10000000001);
  s21_sprintf(str2, "%#.10e", 0.10000000001);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%Le", (long double)4123123123123);
  s21_sprintf(str2, "%Le", (long double)4123123123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#e", 40.32);
  s21_sprintf(str2, "%#e", 40.32);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.6e", 5.99);
  s21_sprintf(str2, "%.6e", 5.99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_f_check) {
  char str[100];
  char str2[100];

  sprintf(str, "%f", 3.14);
  s21_sprintf(str2, "%f", 3.14);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%Lf", (long double)3.14);
  s21_sprintf(str2, "%Lf", (long double)3.14);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_s_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%s", "abcde");
  s21_sprintf(str2, "%s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.1s", "abcde");
  s21_sprintf(str2, "%.1s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.20s", "abcde");
  s21_sprintf(str2, "%.20s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10s", "abcde");
  s21_sprintf(str2, "%10s", "abcde");
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10s", "abcde");
  s21_sprintf(str2, "%-10s", "abcde");
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_u_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%hu", (unsigned short)4);
  s21_sprintf(str2, "%hu", (unsigned short)4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2u", (unsigned int)4);
  s21_sprintf(str2, "%2u", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.5u", (unsigned int)4);
  s21_sprintf(str2, "%2.5u", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-u", (unsigned int)6);
  s21_sprintf(str2, "%-u", 6);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_x_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%x", 4);
  s21_sprintf(str2, "%x", 4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%.2x", 4);
  s21_sprintf(str2, "%.2x", 4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%X", 0x4);
  s21_sprintf(str2, "%X", 0x4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%x", 0x4);
  s21_sprintf(str2, "%x", 0x4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%X", 4);
  s21_sprintf(str2, "%X", 4);
  ck_assert_str_eq(str, str2);

  sprintf(str, "%.2X", 4);
  s21_sprintf(str2, "%.2X", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_n_check) {
  char str[100];
  char str2[100];
  int bufferForStrLength1;
  int bufferForStrLength2;
  sprintf(str, "%s%n", "hello,world!", &bufferForStrLength1);
  s21_sprintf(str2, "%s%n", "hello,world!", &bufferForStrLength2);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_o_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%o", 4);
  s21_sprintf(str2, "%o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", -4);
  s21_sprintf(str2, "%o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3o", -4);
  s21_sprintf(str2, "%-10.3o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", 4);
  s21_sprintf(str2, "%-3.10o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", -4);
  s21_sprintf(str2, "%-3.10o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.o", 4000000);
  s21_sprintf(str2, "%2.o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", -4000000);
  s21_sprintf(str2, "%.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", 4000000);
  s21_sprintf(str2, "%15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15o", -4000000);
  s21_sprintf(str2, "%16.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", -4000000);
  s21_sprintf(str2, "%15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", -4000000);
  s21_sprintf(str2, "%12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", 4000000);
  s21_sprintf(str2, "%12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", 4000000);
  s21_sprintf(str2, "%2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", -4000000);
  s21_sprintf(str2, "%2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  s21_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  s21_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", 4000000);
  s21_sprintf(str2, "%o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  s21_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", -4000000);
  s21_sprintf(str2, "%-2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", 4000000);
  s21_sprintf(str2, "%-15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", -4000000);
  s21_sprintf(str2, "%-15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", -4000000);
  s21_sprintf(str2, "%-12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", 4000000);
  s21_sprintf(str2, "%-12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", 4000000);
  s21_sprintf(str2, "%-2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", -4000000);
  s21_sprintf(str2, "%-2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  s21_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%ho", (short)4000000);
  s21_sprintf(str2, "%ho", (short)4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lo", (long unsigned int)4000000);
  s21_sprintf(str2, "%lo", (long unsigned int)4000000);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_lhidu_check) {
  char str[100];
  char str2[100];
  long int s = 4;
  sprintf(str, "%ld", s);
  s21_sprintf(str2, "%ld", s);
  ck_assert_str_eq(str, str2);
  long unsigned f = 10;
  sprintf(str, "%lu", f);
  s21_sprintf(str2, "%lu", f);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hd", (short int)4);
  s21_sprintf(str2, "%hd", 4);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_p_check) {
  char str[100];
  char str2[100];

  s21_sprintf(str, "%p", str);
  sprintf(str2, "%p", str);
  ck_assert_str_eq(str, str2);

  s21_sprintf(str, "%*p", 20, str);
  sprintf(str2, "%*p", 20, str);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(sprintf_return_check) {
  char str[100];
  char str2[100];
  ck_assert_int_eq(s21_sprintf(str, "%G", 0.12345),
                   sprintf(str2, "%G", 0.12345));
  ck_assert_int_eq(s21_sprintf(str, "%G", 0.000000000000000000000003),
                   sprintf(str2, "%G", 0.000000000000000000000003));
  ck_assert_int_eq(
      s21_sprintf(str, "%LG", (long double)0.000000000000000000000003),
      sprintf(str2, "%LG", (long double)0.000000000000000000000003));
}
END_TEST

Suite *s21_string_tests_create() {
  Suite *s21_string = suite_create("s21_string");
  TCase *test_case_1 = tcase_create("S21_STRING");

  tcase_add_test(test_case_1, s21_memchr_test);
  tcase_add_test(test_case_1, s21_memcpy_test);
  tcase_add_test(test_case_1, s21_memcmp_test);
  tcase_add_test(test_case_1, s21_memset_test);
  tcase_add_test(test_case_1, s21_strlen_test);
  tcase_add_test(test_case_1, s21_strrchr_test);
  tcase_add_test(test_case_1, s21_strstr_test);
  tcase_add_test(test_case_1, s21_strncat_test);
  tcase_add_test(test_case_1, s21_strncmp_test);
  tcase_add_test(test_case_1, s21_strpbrk_test);
  tcase_add_test(test_case_1, s21_strchr_test);
  tcase_add_test(test_case_1, s21_strcspn_test);
  tcase_add_test(test_case_1, s21_strtok_test);
  tcase_add_test(test_case_1, s21_strncpy_test);
  tcase_add_test(test_case_1, s21_sprintf_test);
  tcase_add_test(test_case_1, s21_strerror_test);

  // test sscanf

  tcase_add_test(test_case_1, s21_sscanf_test_c);
  tcase_add_test(test_case_1, s21_sscanf_test_d);
  tcase_add_test(test_case_1, s21_sscanf_test_i);
  tcase_add_test(test_case_1, s21_sscanf_test_f);
  tcase_add_test(test_case_1, s21_sscanf_test_g);
  tcase_add_test(test_case_1, s21_sscanf_test_G);
  tcase_add_test(test_case_1, s21_sscanf_test_e);
  tcase_add_test(test_case_1, s21_sscanf_test_E);
  tcase_add_test(test_case_1, s21_sscanf_test_p);
  tcase_add_test(test_case_1, s21_sscanf_test_o);
  tcase_add_test(test_case_1, s21_sscanf_test_u);
  tcase_add_test(test_case_1, s21_sscanf_test_x);
  tcase_add_test(test_case_1, s21_sscanf_test_X);
  tcase_add_test(test_case_1, s21_sscanf_test_n);

  // test sprintf

  tcase_add_test(test_case_1, sprintf_c_check);
  tcase_add_test(test_case_1, sprintf_d_check);
  tcase_add_test(test_case_1, sprintf_i_check);
  tcase_add_test(test_case_1, sprintf_e_check);
  tcase_add_test(test_case_1, sprintf_f_check);
  tcase_add_test(test_case_1, sprintf_s_check);
  tcase_add_test(test_case_1, sprintf_u_check);
  tcase_add_test(test_case_1, sprintf_x_check);
  tcase_add_test(test_case_1, sprintf_o_check);
  tcase_add_test(test_case_1, sprintf_p_check);
  tcase_add_test(test_case_1, sprintf_n_check);
  tcase_add_test(test_case_1, sprintf_lhidu_check);
  tcase_add_test(test_case_1, sprintf_return_check);

  // test c# func

  tcase_add_test(test_case_1, s21_trim_test);
  tcase_add_test(test_case_1, s21_to_upper_test);
  tcase_add_test(test_case_1, s21_to_lower_test);
  tcase_add_test(test_case_1, s21_insert_test);

  suite_add_tcase(s21_string, test_case_1);
  return s21_string;
}

int main() {
  Suite *s21_string = s21_string_tests_create();
  SRunner *s21_string_runner = srunner_create(s21_string);
  float number_failed;
  srunner_run_all(s21_string_runner, CK_ENV);
  number_failed = srunner_ntests_failed(s21_string_runner);
  srunner_free(s21_string_runner);

  return number_failed == 0 ? 0 : 1;
}
