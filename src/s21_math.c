#include "s21_math.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double s21_asin(double S) {
  long double ans0 = 0, ans = 0, S0 = 0, eps = 1e-12, delta = 0;
  char minus_flag = 0;
  if (S < -1)
    ans = strtod("nan", NULL);
  else if (S != S)
    ans = strtod("nan", NULL);
  else if (S > 1)
    ans = strtod("nan", NULL);
  else if (S == S21_INF)
    ans = strtod("nan", NULL);
  else if (S == S21_MIN_INF)
    ans = strtod("nan", NULL);
  else {
    if (S < 0) {
      minus_flag = 1;
      S *= -1;
    }
    if ((S > -1) || (S < 1)) S0 = (S / sqrt(1 - (S * S)));
    if ((S0 < 1) && (S0 > -1)) {
      ans0 += pow(-1, 0) * pow(S0, 2 * 0 + 1) / (2 * 0 + 1);
      delta = fabs(ans0 - ans);
      int i = 1;
      while (delta > eps) {
        ans0 += pow(-1, i) * pow(S0, 2 * i + 1) / (2 * i + 1);
        delta = fabs(ans0 - ans);
        ans = ans0;
        ++i;
      }
    } else if (S0 >= 1) {
      ans0 += S21_M_PI / 2;
      ans0 -= pow(-1, 0) / pow(S0, 2 * 0 + 1) / (2 * 0 + 1);
      delta = fabs(ans0 - ans);
      ans = ans0;
      int i = 1;
      while (delta > eps) {
        ans0 -= pow(-1, i) / pow(S0, 2 * i + 1) / (2 * i + 1);
        delta = fabs(ans0 - ans);
        ans = ans0;
        ++i;
      }
    }
    if (S == 0)
      ans = 0;
    else if ((S > 1.0) || (S < -1.0))
      ans = strtod("nan", NULL);
    if (minus_flag) {
      ans *= -1;
      S *= -1;
    }
    return ans;
  }
}

long double s21_log(double S) {
  long double xi = 0, ans = 1000;
  unsigned int power = 1;

  if (S == 0)
    ans = -S21_MIN_INF;
  else if (S < 0)
    ans = strtod("nan", NULL);
  else if (S != S)
    ans = strtod("nan", NULL);
  else if (S == S21_INF)
    ans = S21_INF;
  else if (S == S21_MIN_INF)
    ans = strtod("nan", NULL);
  else if (S > 0) {
    int decs = 0;
    while (S > 1) {
      S /= 10;
      ++decs;
    }
    S -= 1;
    long double ans0 = 0, S0 = S;
    for (int i = 1; fabs(S / i) > S21_EPS; ++i) {
      ans = ans0;
      ans0 += S / i;
      S *= -S0;
    }
    ans = ans0;
    ans += decs * S21_LN10;
  } else {
    ans = S21_NAN;
  }
  return ans;
}

long double s21_sqrt(double S) {
  long double xi = S / 2;
  long double xi_1 = S / 2;
  long double eps = 1;
  if (S == 0)
    xi = 0;
  else if (S < 0)
    xi = strtod("nan", NULL);
  else if (S != S)
    xi = S21_NAN;
  else if (S == S21_INF)
    xi = S21_INF;
  else if (S == S21_MIN_INF)
    xi = strtod("nan", NULL);
  else if (S > 0) {
    xi = S / 2;
    while ((S > 0) && (eps > S21_EPS)) {
      xi = (xi_1 + S / xi_1) / 2;
      eps = -(S - xi * xi) / (2 * xi);
      xi_1 = xi;
    }
  }
  return xi;
}

long double to_range(double x) {
  while (x < -S21_M_PI || x > S21_M_PI) {
    x -= 2 * S21_M_PI;
  }
  return x;
}

long double s21_sin(double x) {
  if (s21_isnan(x) || !s21_isfinite(x)) return S21_NAN;
  x = to_range(x);
  double temp = x;
  long double n = 1., con = x;
  while (s21_fabs(temp) > S21_EPS) {
    temp = (s21_pow(-1., n) * s21_pow(con, 2. * n + 1.)) /
           s21_factorial(2. * n + 1.);
    n += 1.;
    x += temp;
  }
  return x;
}

long double s21_cos(double x) {
  if (s21_isnan(x) || !s21_isfinite(x)) return S21_NAN;
  x = to_range(x);
  double temp = x;
  long double n = 1., con = x;
  x = 1;
  while (s21_fabs(temp) > S21_EPS) {
    temp = (s21_pow(-1., n) * s21_pow(con, 2. * n)) / s21_factorial(2. * n);
    n += 1.;
    x += temp;
  }
  return x;
}

long double s21_tan(double x) {
  if (s21_isnan(x) || !s21_isfinite(x)) return S21_NAN;
  return s21_sin(x) / s21_cos(x);
}

long double s21_atan(double x) { return s21_cos(x) / s21_sin(x); }

long double s21_floor(double x) {
  return x >= 0. ? x = (int)x : (x = (int)(x - 1.));
}

long double s21_factorial(double x) {
  return x == 0. ? 1. : x * s21_factorial(x - 1.);
}

long double s21_fabs(double x) { return x < 0.0 ? -x : x; }

long double simplePow(double num, double pow) {
  long double res = num;
  for (int i = 1; i < pow; i++) {
    res *= num;
  }
  if (pow == 0) res = 1;
  return res;
}

long double fRoot(double num, double exp) {
  long double i, prec = 0.000001;
  for (i = 1; simplePow(i, exp) <= num; i++)
    ;
  for (--i; simplePow(i, exp) < num; i += prec)
    ;
  return i;
}

bool isInt(double val) { return (val == ((double)((int)val))); }

void convert(double *num, double *fract) {
  *fract = 1;
  while (!isInt(*num)) {
    *num *= 10;
    *fract *= 10;
  }
}

long double s21_pow(double base, double exp) {
  long double res = base;
  if (isInt(exp) && exp > 0) {
    res = simplePow(base, exp);
  } else if (exp > 0 && !isInt(exp)) {
    double fraction;
    convert(&exp, &fraction);
    double temp = (double)simplePow(base, exp);
    res = fRoot(temp, fraction);
  } else if (exp == 0) {
    res = 1;
  } else if (exp < 0) {
    exp = (double)s21_fabs(exp);
    res = (float)1 / s21_pow(base, exp);
  }
  return res;
}

long double s21_ceil(double x) {
  long double res;
  if (isInt(x) || x == 0) {
    res = x;
  } else if (x > 0) {
    res = (int)x + 1;
  } else if (x < 0) {
    double dif = x - (int)x;
    res = x - dif;
  }
  return res;
}
