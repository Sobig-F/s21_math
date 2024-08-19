#include "s21_math.h"

#include <stdlib.h>

#define NAN 0.0 / 0.0

int *int_to_bin(int x) {
  int count = 1, temp = 2;
  int *bin = NULL;
  while (temp <= x) {
    ++count;
    temp *= 2;
  }
  bin = (int *)calloc((count + 1), sizeof(int));
  if (bin != NULL) {
    bin[0] = count;
  }
  while (x > 0) {
    if (bin != NULL) {
      bin[count] = (int)s21_fmod((double)x, 2.0);
      --count;
      x /= 2;
    }
  }
  return bin;
}

long double bin_degree(int *bin, long double x) {
  long double integer_degree = 1;
  if (bin != NULL) {
    for (int i = 1; i <= bin[0]; ++i) {
      integer_degree *= integer_degree;
      if (bin != NULL && bin[i] == 1) {
        integer_degree = integer_degree * x;
      }
    }
  }

  return integer_degree;
}

long double s21_fabs(double x) {
  if (x < 0.0) {
    x *= -1.0;
  }
  return x;
}

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_ceil(double x) {
  long double result;
  if ((double)x == x && x != INF) {
    result = (long long int)x;
    if (x > 0.0 && result < x) {
      result += 1.0;
    }
  } else {
    result = x;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = (long long int)x;
  if ((double)x == x && x != INF) {
    result = (long long int)x;
    if (x < 0.0 && result > x) {
      result -= 1.0;
    }
  } else {
    result = x;
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result;
  if ((double)x == x && y == INF) {
    result = x;
  } else if (y == 0.0) {
    result = NAN;
  } else if (x == 0.0) {
    result = 0;
  } else if (x / y < 0.0) {
    result = x - y * s21_ceil(x / y);
  } else {
    result = x - y * s21_floor(x / y);
  }
  return result;
}

long double s21_exp(double x) {
  long double result;
  if ((double)x == x && x != INF) {
    double abs_x = s21_fabs(x), fractional;
    long double integer_degree = 1, fractional_degree = 1.0, slogaemoe = 1.0;
    int whole;
    int *whole_to_bin = NULL;

    whole = (int)s21_floor(abs_x);
    fractional = abs_x - whole;
    whole_to_bin = int_to_bin(whole);
    if (whole_to_bin != NULL) {
      integer_degree = bin_degree(whole_to_bin, E);
    }
    free(whole_to_bin);

    for (int i = 1; i < 30; ++i) {
      slogaemoe *= fractional / (double)i;
      fractional_degree += slogaemoe;
    }

    result = integer_degree * fractional_degree;

    if (x < 0) {
      result = 1.0 / result;
    }
  } else {
    result = x;
  }

  return result;
}

long double s21_log(double x) {
  long double result;
  if ((double)x == x && x != INF) {
    if (x < 0) {
      result = NAN;
    } else if (x == 0) {
      result = -INF;
    } else {
      result = 0;
      for (int i = 0; i < 200; ++i) {
        result += 2 * (x - s21_exp(result)) / (x + s21_exp(result));
      }
    }
  } else {
    result = x;
  }
  return result;
}

long double s21_sin(double x) {
  long double result, slogaemoe;
  if (x > 2 * PI || x < 2 * PI) {
    x = s21_fmod(x, 2 * PI);
  }
  result = x;
  slogaemoe = x;
  for (int i = 3; i < 200; i += 2) {
    slogaemoe *= (x / (i - 1)) * (x / i) * (-1);
    result += slogaemoe;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 1.0, slogaemoe;
  if (x == INF) {
    result = NAN;
  } else if ((double)x == x) {
    if (x > 2 * PI || x < -2 * PI) {
      x = s21_fmod(x, 2 * PI);
    }
    slogaemoe = 1.0;
    for (int i = 2; i < 200; i += 2) {
      slogaemoe *= (x / (i - 1)) * (x / i) * (-1);
      result += slogaemoe;
    }
  } else {
    result = x;
  }
  return result;
}

long double s21_tan(double x) {
  long double result;
  result = s21_sin(x) / s21_cos(x);
  return result;
}

long double s21_atan(double x) {
  double this_x, slogaemoe;
  long double result;
  if (s21_fabs(x) >= 1.0) {
    this_x = 1.0 / x;
  } else {
    this_x = x;
  }

  if (s21_fabs(x) == 1.0) {
    result = PI / 4 * x;
  } else {
    result = this_x;
    slogaemoe = this_x;

    for (int i = 3; i < 200; i += 2) {
      slogaemoe *= (i - 2) * this_x * this_x / i * (-1);
      result += slogaemoe;
    }

    if (x > 1.0) {
      result = PI / 2 - result;
    } else if (x < -1.0) {
      result = PI / (-2) - result;
    }
  }

  return result;
}

long double s21_asin(double x) {
  long double result;
  if (s21_fabs(x) > 1.0) {
    result = NAN;
  } else {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return result;
}

long double s21_acos(double x) {
  long double result;

  if (x == 0.0) {
    result = PI / 2;
  } else {
    result = s21_atan(s21_sqrt(1 - x * x) / x);
    if (x < 0) {
      result += PI;
    }
  }

  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (base == 0.0) {
    if (exp < 0) {
      result = INF;
    } else if (exp == 0.0) {
      result = 1.0;
    } else {
      result = 0;
    }
  } else if (s21_fabs(exp) == 1.0) {
    if (exp < 0) {
      result = 1.0 / base;
    } else {
      result = base;
    }
  } else if (base < 0.0 && exp - (int)exp != 0.0) {
    result = NAN;
  } else if (exp - (int)exp == 0.0) {
    int *exp_to_bin = NULL;
    exp_to_bin = int_to_bin(s21_abs((int)exp));
    if (exp_to_bin != NULL) {
      result = bin_degree(exp_to_bin, base);
    }
    free(exp_to_bin);
    if (exp < 0) {
      result = 1.0 / result;
    }
  } else {
    result = s21_exp(exp * s21_log(base));
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result;
  if (x < 0.0) {
    result = NAN;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}