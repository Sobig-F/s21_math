#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int main() {
  const double test_numbers[13] = {-10,    -9.999, -1.001, -1,    -0.999,
                                   -0.001, 0,      0.001,  0.999, 1,
                                   1.001,  9.999,  10};
  long double math, s21_math;

  // s21_abs
  printf("s21_abs\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = (int)abs((int)test_numbers[i]);
    s21_math = (int)s21_abs((int)test_numbers[i]);

    printf("%d) %d %d - ", i + 1, (int)math,
           (int)s21_math || (isnan(math) && isnan(s21_math)) ||
               (isinf(math) && isinf(s21_math)));
    if (math == s21_math) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_acos
  printf("s21_acos\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = acos(test_numbers[i]);
    s21_math = s21_acos(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_asin
  printf("s21_asin\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = asin(test_numbers[i]);
    s21_math = s21_asin(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_atan
  printf("s21_atan\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = atan(test_numbers[i]);
    s21_math = s21_atan(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_ceil
  printf("s21_ceil\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = ceil(test_numbers[i]);
    s21_math = s21_ceil(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_cos
  printf("s21_cos\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = cos(test_numbers[i]);
    s21_math = s21_cos(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_exp
  printf("s21_exp\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = exp(test_numbers[i]);
    s21_math = s21_exp(test_numbers[i]);

    printf("%d) %.6Lf %.6Lf - ", i + 1, math, s21_math);
    if ((fabs((double)math - (double)s21_math) < 0.000001) ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_fabs
  printf("s21_fabs\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = fabs(test_numbers[i]);
    s21_math = s21_fabs(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_floor
  printf("s21_floor\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = floor(test_numbers[i]);
    s21_math = s21_floor(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_fmod
  printf("s21_fmod\n==========\n");
  for (int i = 0; i < 13; ++i) {
    for (int j = 0; j < 13; ++j) {
      math = fmod(test_numbers[i], test_numbers[j]);
      s21_math = s21_fmod(test_numbers[i], test_numbers[j]);

      printf("%d - %d ) %.6Lf %.6Lf - ", i + 1, j + 1, math, s21_math);
      if (fabs((double)math - (double)s21_math) < 0.000001 ||
          (isnan(math) && isnan(s21_math)) ||
          (isinf(math) && isinf(s21_math))) {
        printf("SUCCESS");
      } else {
        printf("FAIL");
      }
      printf("\n");
    }
  }
  printf("==========\n\n");

  // s21_log
  printf("s21_log\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = log(test_numbers[i]);
    s21_math = s21_log(test_numbers[i]);

    printf("%d) %.6Lf %.6Lf - ", i + 1, math, s21_math);
    if ((fabs((double)math - (double)s21_math) < 0.000001) ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_pow
  printf("s21_pow\n==========\n");
  for (int i = 0; i < 13; ++i) {
    for (int j = 0; j < 13; ++j) {
      math = pow(test_numbers[i], test_numbers[j]);
      s21_math = s21_pow(test_numbers[i], test_numbers[j]);

      printf("%.3f-%.3f) %.6Lf %.6Lf - ", test_numbers[i], test_numbers[j],
             math, s21_math);
      if ((fabs((double)math - (double)s21_math) < 0.000001) ||
          (isnan(math) && isnan(s21_math)) ||
          (isinf(math) && isinf(s21_math))) {
        printf("SUCCESS");
      } else {
        printf("FAIL");
      }
      printf("\n");
    }
  }
  printf("==========\n\n");

  // s21_sin
  printf("s21_sin\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = sin(test_numbers[i]);
    s21_math = s21_sin(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_sqrt
  printf("s21_acos\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = sqrt(test_numbers[i]);
    s21_math = s21_sqrt(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // s21_tan
  printf("s21_tan\n==========\n");
  for (int i = 0; i < 13; ++i) {
    math = tan(test_numbers[i]);
    s21_math = s21_tan(test_numbers[i]);

    printf("%.6Lf %.6Lf - ", math, s21_math);
    if (fabs((double)math - (double)s21_math) < 0.000001 ||
        (isnan(math) && isnan(s21_math)) || (isinf(math) && isinf(s21_math))) {
      printf("SUCCESS");
    } else {
      printf("FAIL");
    }
    printf("\n");
  }
  printf("==========\n\n");

  // printf("%.6f - %.6Lf\n", acos(NAN), s21_acos(NAN));
  // printf("%.6f - %.6Lf\n", asin(NAN), s21_asin(NAN));
  // printf("%.6f - %.6Lf\n", atan(NAN), s21_atan(NAN));
  // printf("%.6f - %.6Lf\n", ceil(NAN), s21_ceil(NAN));
  // printf("%.6f - %.6Lf\n", cos(NAN), s21_cos(NAN));
  // printf("%.6f - %.6Lf\n", exp(NAN), s21_exp(NAN));
  // printf("%.6f - %.6Lf\n", fabs(NAN), s21_fabs(NAN));
  // printf("%.6f - %.6Lf\n", floor(NAN), s21_floor(NAN));
  // printf("%.6f - %.6Lf\n", fmod(NAN, NAN), s21_fmod(NAN, NAN));
  // printf("%.6f - %.6Lf\n", log(NAN), s21_log(NAN));
  // printf("%.6f - %.6Lf\n", pow(NAN, NAN), s21_pow(NAN, NAN));
  // printf("%.6f - %.6Lf\n", sin(NAN), s21_sin(NAN));
  // printf("%.6f - %.6Lf\n", sqrt(NAN), s21_sqrt(NAN));
  // printf("%.6f - %.6Lf\n", tan(NAN), s21_tan(NAN));

  // printf("%.6f - %.6Lf\n", acos(INF), s21_acos(INF));
  // printf("%.6f - %.6Lf\n", asin(INF), s21_asin(INF));
  // printf("%.6f - %.6Lf\n", atan(INF), s21_atan(INF));
  // printf("%.6f - %.6Lf\n", ceil(INF), s21_ceil(INF));
  // printf("%.6f - %.6Lf\n", cos(INF), s21_cos(INF));
  // printf("%.6f - %.6Lf\n", exp(INF), s21_exp(INF));
  // printf("%.6f - %.6Lf\n", fabs(INF), s21_fabs(INF));
  // printf("%.6f - %.6Lf\n", floor(INF), s21_floor(INF));
  // printf("%.6f - %.6Lf\n", fmod(INF, INF), s21_fmod(INF, INF));
  // printf("%.6f - %.6Lf\n", log(INF), s21_log(INF));
  // printf("%.6f - %.6Lf\n", pow(INF, 2), s21_pow(INF, 2));
  // printf("%.6f - %.6Lf\n", sin(INF), s21_sin(INF));
  // printf("%.6f - %.6Lf\n", sqrt(INF), s21_sqrt(INF));
  // printf("%.6f - %.6Lf\n", tan(INF), s21_tan(INF));
}