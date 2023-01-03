#ifndef SRC_MATH_H
#define SRC_MATH_H

#include <stdbool.h>

#define S21_M_E 2.7182818284590452354
#define S21_M_PI 3.14159265358979323846
#define S21_ln2 \
  0.6931471805599453094172321214581765680755001343602552541206800094
#define S21_EPS 1e-7
#define S21_EPS_TAYLOR 1e-13
#define S21_NAN 0.0 / 0.0
#define S21_INF __builtin_huge_vall()
#define S21_MIN_INF -__builtin_huge_vall()
#define S21_LN10 2.30258509299404568401799145468436421
#define s21_isnan(x) __builtin_isnan(x)
#define s21_isfinite(x) __builtin_isfinite(x)

long double s21_sqrt(double S);
long double s21_log(double S);
long double s21_exp(double S);
long double s21_asin(double S);
long double to_range(double x);
long double s21_sin(double x);
long double s21_factorial(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
int s21_abs(int x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_pow(double base, double exp);
long double s21_fmod(double x, double y);

#endif  // SRC_MATH_H
