/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test.check" instead.
 */

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int equal(double result, long double s21_result) {
  if ((isnan(result) && isnan(s21_result)) ||
      (isinf(result) && isinf(s21_result))) {
    return 1;
  } else if (fabs(result) != 0.0 && fabs((double)s21_result) != 0.0) {
    int count = (int)log10(fabs(result));
    result = (int)(result * pow(10, (16 - count))) / pow(10, (16 - count));
    s21_result =
        (int)(s21_result * pow(10, (16 - count))) / pow(10, (16 - count));
    if (result == s21_result) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 1;
  }
}

START_TEST(abs_test) {
  for (int i = -10; i < 11; ++i) {
    ck_assert_int_eq(abs(i), s21_abs(i));
  }
}
END_TEST

START_TEST(acos_test) {
  printf("\n====acos====\n");
  double x = -1.0;
  long double s21_result;
  double result;
  while (x <= 1.0) {
    s21_result = s21_acos(x);
    result = acos(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)acos(x) - (double)s21_acos(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(asin_test) {
  printf("\n====asin====\n");
  double x = -1.0;
  long double s21_result;
  double result;
  while (x <= 1.0) {
    s21_result = s21_asin(x);
    result = asin(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)asin(x) - (double)s21_asin(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(atan_test) {
  printf("\n====atan====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_atan(x);
    result = atan(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)atan(x) - (double)s21_atan(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(ceil_test) {
  printf("\n====ceil====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_ceil(x);
    result = ceil(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)ceil(x) - (double)s21_ceil(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(cos_test) {
  printf("\n====cos====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_cos(x);
    result = cos(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)cos(x) - (double)s21_cos(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(exp_test) {
  printf("\n====exp====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_exp(x);
    result = exp(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)exp(x) - (double)s21_exp(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(fabs_test) {
  printf("\n====fabs====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_fabs(x);
    result = fabs(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)fabs(x) - (double)s21_fabs(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(floor_test) {
  printf("\n====floor====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_floor(x);
    result = floor(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)floor(x) - (double)s21_floor(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(log_test) {
  printf("\n====log====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_log(x);
    result = log(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)log(x) - (double)s21_log(x)));
    x += 0.1;
  }
}
END_TEST

START_TEST(sin_test) {
  printf("\n====sin====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_sin(x);
    result = sin(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)sin(x) - (double)s21_sin(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(sqrt_test) {
  printf("\n====sqrt====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_sqrt(x);
    result = sqrt(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)sqrt(x) - (double)s21_sqrt(x)));
    x += 0.1;
  }
}
END_TEST

START_TEST(tan_test) {
  printf("\n====tan====\n");
  double x = -100.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    s21_result = s21_tan(x);
    result = tan(x);
    if (!equal(result, s21_result)) {
      printf("%f --- %.6f != %.6Lf ", x, result, s21_result);
      printf("FAIL\n");
    }
    ck_assert_int_le(0.000001, fabs((double)tan(x) - (double)s21_tan(x)));
    x += 0.01;
  }
}
END_TEST

START_TEST(fmod_test) {
  printf("\n====fmod====\n");
  double x = -100.0, y = -50.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    while (y <= 50.0) {
      s21_result = s21_fmod(x, y);
      result = fmod(x, y);
      if (!equal(result, s21_result)) {
        printf("%f %f--- %.6f != %.6Lf ", x, y, result, s21_result);
        printf("FAIL\n");
      }
      ck_assert_int_le(0.000001,
                       fabs((double)fmod(x, y) - (double)s21_fmod(x, y)));
      y += 0.01;
    }
    x += 0.01;
  }
}
END_TEST

START_TEST(pow_test) {
  printf("\n====pow====\n");
  double x = -100.0, y = -50.0;
  long double s21_result;
  double result;
  while (x <= 100.0) {
    while (y <= 50.0) {
      s21_result = s21_pow(x, y);
      result = pow(x, y);
      if (!equal(result, s21_result)) {
        printf("%f %f--- %.6f != %.6Lf ", x, y, result, s21_result);
        printf("FAIL\n");
      }
      ck_assert_int_le(0.000001,
                       fabs((double)pow(x, y) - (double)s21_pow(x, y)));
      y += 0.01;
    }
    x += 0.01;
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, abs_test);
  tcase_add_test(tc1_1, acos_test);
  tcase_add_test(tc1_1, asin_test);
  tcase_add_test(tc1_1, atan_test);
  tcase_add_test(tc1_1, ceil_test);
  tcase_add_test(tc1_1, cos_test);
  tcase_add_test(tc1_1, exp_test);
  tcase_add_test(tc1_1, fabs_test);
  tcase_add_test(tc1_1, floor_test);
  tcase_add_test(tc1_1, log_test);
  tcase_add_test(tc1_1, sin_test);
  tcase_add_test(tc1_1, sqrt_test);
  tcase_add_test(tc1_1, tan_test);
  tcase_add_test(tc1_1, fmod_test);
  tcase_add_test(tc1_1, pow_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}