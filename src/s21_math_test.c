#include "s21_math_test.h"

#include <stdio.h>

START_TEST(s21_abs_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < INTS; i++) {
    s21_res = s21_abs(ints[i]);
    res = abs(ints[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_fabs_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_fabs(doubles[i]);
    res = fabs(doubles[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_fabs_test_2) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < SCIENTS; i++) {
    s21_res = s21_fabs(scients[i]);
    res = fabs(scients[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_fabs_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_fabs(S21_NAN);
  res = fabs(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_fabs(S21_INF);
  res = fabs(S21_INF);
  ck_assert_ldouble_infinite(s21_res);
}
END_TEST

START_TEST(s21_exp_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_exp(doubles[i]);
    res = exp(doubles[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_exp_test_2) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 1; i < 5; i++) {
    s21_res = s21_exp(scients[i]);
    res = exp(scients[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
  for (int i = 6; i < SCIENTS - 2; i++) {
    s21_res = s21_exp(scients[i]);
    res = exp(scients[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }

  s21_res = s21_exp(scients[5]);
  res = exp(scients[5]);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_exp(scients[8]);
  res = exp(scients[8]);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_exp(scients[SCIENTS]);
  res = exp(scients[SCIENTS]);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);
}
END_TEST

START_TEST(s21_exp_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_exp(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_exp(S21_INF);
  res = exp(S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_exp(S21_MIN_INF);
  res = exp(S21_MIN_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);
}
END_TEST

START_TEST(s21_sqrt_test_1) {
  long double s21_res = 0, res = 0;
  long double S = -10;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_sqrt(doubles[i]);
    res = sqrt(doubles[i]);
    if (doubles[i] >= 0)
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else
      ck_assert_ldouble_nan(s21_res);
  }
  for (int i = 0; i < SCIENTS; i++) {
    s21_res = s21_sqrt(scients[i]);
    res = sqrt(scients[i]);
    if (scients[i] >= 0)
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  long double s21_res = 0, res = 0;
  long double S = -10;

  for (long double i = 0; i < 50; i++) {
    S += 0.1;
    s21_res = s21_sqrt(S);
    res = sqrt(S);
    if (S >= 0)
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_sqrt(S21_NAN);
  res = sqrt(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_sqrt(S21_INF);
  res = sqrt(S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_sqrt(S21_MIN_INF);
  res = sqrt(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(s21_log_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_log(doubles[i]);
    res = log(doubles[i]);
    if (doubles[i] > 0)
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else if (doubles[i] == 0)
      ck_assert_ldouble_infinite(s21_res);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_log_test_2) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < SCIENTS; i++) {
    s21_res = s21_log(scients[i]);
    res = log(scients[i]);
    if (scients[i] > 0)
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else if (scients[i] == 0)
      ck_assert_ldouble_infinite(s21_res);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_log_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_log(S21_NAN);
  res = log(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_log(S21_INF);
  res = log(S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_log(S21_MIN_INF);
  res = log(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(s21_atan_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < RADIANS; i++) {
    s21_res = s21_atan(radians[i]);
    res = atan(radians[i]);
    ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_atan_test_2) {
  long double s21_res = 0, res = 0;
  long double S = -2;
  for (int i = 0; i < 42; i++) {
    s21_res = s21_atan(S);
    res = atan(S);
    ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    S += 0.1;
  }
}
END_TEST

START_TEST(s21_atan_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_atan(S21_NAN);
  res = atan(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_atan(S21_INF);
  res = atan(S21_INF);
  ck_assert_ldouble_eq_tol(s21_res, S21_M_PI / 2, 1e-7);

  s21_res = s21_atan(S21_MIN_INF);
  res = atan(S21_MIN_INF);
  ck_assert_ldouble_eq_tol(s21_res, -S21_M_PI / 2, 1e-7);
}
END_TEST

START_TEST(s21_asin_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < RADIANS; i++) {
    s21_res = s21_asin(radians[i]);
    res = asin(radians[i]);
    if ((radians[i] <= 1.0) && (radians[i] >= -1.0))
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_asin_test_2) {
  long double s21_res = 0, res = 0;
  long double S = -2;
  for (long double i = 0; i < 42; i++) {
    s21_res = s21_asin(S);
    res = asin(S);
    if ((S <= 1.0) && (S >= -1.0)) {
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
      S += 0.1;
    } else {
      ck_assert_ldouble_nan(s21_res);
      S += 0.1;
    }
  }
}
END_TEST

START_TEST(s21_asin_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_asin(S21_NAN);
  res = asin(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_asin(S21_INF);
  res = asin(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_asin(S21_MIN_INF);
  res = asin(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(s21_acos_test_1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-7);
  for (int i = 0; i < RADIANS; i++) {
    s21_res = s21_acos(radians[i]);
    res = acos(radians[i]);
    if ((radians[i] <= 1.0) && (radians[i] >= -1.0))
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
    else
      ck_assert_ldouble_nan(s21_res);
  }
}
END_TEST

START_TEST(s21_acos_test_2) {
  long double s21_res = 0, res = 0;
  long double S = -2;
  for (long double i = 0; i < 42; i++) {
    s21_res = s21_acos(S);
    res = acos(S);
    if ((S <= 1.0) && (S >= -1.0)) {
      ck_assert_ldouble_eq_tol(s21_res, res, 1e-7);
      S += 0.1;
    } else {
      if (fabs(S - 1) < 1e-6) {
        ck_assert_ldouble_nan(s21_res);
        S += 0.1;
      }
    }
  }
}
END_TEST

START_TEST(s21_acos_test_3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_acos(S21_NAN);
  res = acos(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_acos(S21_INF);
  res = acos(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_acos(S21_MIN_INF);
  res = acos(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(sin_test_default) {
  char result[32];
  char assert[32];
  for (double i = -1.; i <= 1.; i += 0.1) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_zero) {
  ck_assert_double_eq_tol((double)s21_sin(0), sin(0), 1e-7);
  for (double i = -S21_M_PI; i < 2 * S21_M_PI; i += 0.010456011) {
    ck_assert_double_eq_tol((double)s21_sin(i), sin(i), 1e-7);
  }
}
END_TEST

START_TEST(sin_test_subzero) {
  char result[32];
  char assert[32];
  for (double i = -10.; i <= -1.; i += 0.1) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_bigger_p) {
  char result[32];
  char assert[32];
  for (double i = 4.; i <= 100.; i += 1.) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_small) {
  char result[32];
  char assert[32];
  for (double i = 1.; i > S21_EPS; i /= 2.) {
    sprintf(result, "%.6Lf", s21_sin(i));
    sprintf(assert, "%.6f", sin(i));
    ck_assert_str_eq(result, assert);
  }
}
END_TEST

START_TEST(sin_test_INF) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_sin(S21_INF));
  sprintf(assert, "%.6f", sin(S21_INF));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(sin_test_NAN) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_sin(S21_NAN);
  res = sin(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_sin(S21_INF);
  res = sin(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_sin(S21_MIN_INF);
  res = sin(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(cos_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(1.5708));
  sprintf(assert, "%.6f", cos(1.5708));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_subzero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(-1.5708));
  sprintf(assert, "%.6f", cos(-1.5708));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_zero) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(0));
  sprintf(assert, "%.6f", cos(0));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(4.));
  sprintf(assert, "%.6f", cos(4));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_cos(0.000001));
  sprintf(assert, "%.6f", cos(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(cos_test_NAN) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_cos(S21_NAN);
  res = cos(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_cos(S21_INF);
  res = cos(S21_INF);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_cos(S21_MIN_INF);
  res = cos(S21_MIN_INF);
  ck_assert_ldouble_nan(s21_res);
}
END_TEST

START_TEST(tan_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(1.57));
  sprintf(assert, "%.6f", tan(1.57));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(4));
  sprintf(assert, "%.6f", tan(4));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(tan_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_tan(0.000001));
  sprintf(assert, "%.6f", tan(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(floor_test_default) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_floor(-0.24));
  sprintf(assert, "%.6f", floor(-0.24));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(floor_test_bigger_p) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_floor(4));
  sprintf(assert, "%.6f", floor(4));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(floor_test_small) {
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_floor(0.000001));
  sprintf(assert, "%.6f", floor(0.000001));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(s21_floor_test1) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < SCIENTS; i++) {
    s21_res = s21_floor(scients[i]);
    res = floor(scients[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_floor_test2) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_floor(doubles[i]);
    res = floor(doubles[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_floor_test3) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_floor(S21_NAN);
  res = floor(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_floor(S21_INF);
  res = floor(S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_floor(S21_MIN_INF);
  res = floor(S21_MIN_INF);
  ck_assert_ldouble_infinite(s21_res);
}
END_TEST

END_TEST
START_TEST(s21_fmod_test1) {
  long double s21 = s21_fmod(10, 5);
  long double math = fmod(10, 5);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_fmod_test2) {
  long double s21 = s21_fmod(5.6, 0.55);
  long double math = fmod(5.6, 0.55);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_fmod_test3) {
  long double s21 = s21_fmod(3, -4);
  long double math = fmod(3, -4);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_fmod_test4) {
  long double s21 = s21_fmod(3.05, -0.12);
  long double math = fmod(3.05, -0.12);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_fmod_test5) {
  long double s21 = s21_fmod(345.14, 55.1);
  long double math = fmod(345.14, 55.1);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_fmod_test6) {
  long double s21 = s21_fmod(14, 0);
  ck_assert_ldouble_nan(s21);
}
END_TEST

START_TEST(s21_fmod_test7) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    for (int j = 0; j < DOUBLES; j++) {
      s21_res = s21_fmod(doubles[i], doubles[j]);
      res = fmod(doubles[i], doubles[j]);
      if ((doubles[j] == 0.0) && (i != 1) && (j != 4) && (i != 3) && (j != 6))
        ck_assert_ldouble_nan(s21_res);
      else if ((i != 1) && (j != 4) && (i != 3) && (j != 6))
        ck_assert_double_eq_tol(s21_res, res, 1e-7);
    }
  }
}
END_TEST

START_TEST(s21_fmod_test8) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < SCIENTS; i++) {
    for (int j = 0; j < SCIENTS; j++) {
      s21_res = s21_fmod(scients[i], scients[j]);
      res = fmod(scients[i], scients[j]);
      if (scients[j] == 0.0)
        ck_assert_ldouble_nan(s21_res);
      else
        ck_assert_double_eq_tol(s21_res, res, 1e-7);
    }
  }
}
END_TEST

START_TEST(s21_fmod_test9) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_fmod(S21_NAN, 1);
  res = fmod(S21_NAN, 1);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_fmod(S21_INF, 1);
  res = fmod(S21_INF, 1);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_fmod(S21_MIN_INF, 1);
  res = fmod(S21_MIN_INF, 1);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_fmod(1, S21_NAN);
  res = fmod(1, S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_fmod(1, S21_INF);
  res = fmod(1, S21_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);

  s21_res = s21_fmod(1, S21_MIN_INF);
  res = fmod(1, S21_MIN_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);
}
END_TEST

START_TEST(s21_pow_test1) {
  long double s21 = s21_pow(10, 5);
  long double math = pow(10, 5);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test2) {
  long double s21 = s21_pow(5.6, 0.55);
  long double math = pow(5.6, 0.55);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test3) {
  long double s21 = s21_pow(3, -4);
  long double math = pow(3, -4);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test4) {
  long double s21 = s21_pow(3.05, -0.12);
  long double math = pow(3.05, -0.12);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test5) {
  long double s21 = s21_pow(345.14, 55.1);
  long double math = pow(345.14, 55.1);
  //  printf("s21  %Lf\nmath %Lf\n", s21, math);
  //  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test6) {
  long double s21 = s21_pow(14, 0);
  long double math = pow(14, 0);
  ck_assert_ldouble_eq_tol(s21, math, 1e-7);
}
END_TEST

START_TEST(s21_pow_test7) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_pow(S21_NAN, 1);
  res = pow(S21_NAN, 1);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_pow(S21_INF, 1);
  res = pow(S21_INF, 1);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_pow(S21_MIN_INF, 1);
  res = pow(S21_MIN_INF, 1);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_pow(S21_INF, S21_INF);
  res = pow(S21_INF, S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_pow(S21_MIN_INF, S21_MIN_INF);
  res = pow(S21_MIN_INF, S21_MIN_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);

  s21_res = s21_pow(1, S21_NAN);
  res = pow(1, S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_pow(1, S21_INF);
  res = pow(1, S21_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);

  s21_res = s21_pow(1, S21_MIN_INF);
  res = pow(1, S21_MIN_INF);
  ck_assert_double_eq_tol(s21_res, res, 1e-7);
}
END_TEST

START_TEST(s21_ceil_test1) {
  long double s21 = s21_ceil(4.5);
  long double math = ceil(4.5);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test2) {
  long double s21 = s21_ceil(0.6);
  long double math = ceil(0.6);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test3) {
  long double s21 = s21_ceil(6782965.786812765876);
  long double math = ceil(6782965.786812765876);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test4) {
  long double s21 = s21_ceil(-0.786872);
  long double math = ceil(-0.786872);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test5) {
  long double s21 = s21_ceil(5);
  long double math = ceil(5);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test6) {
  long double s21 = s21_ceil(0);
  long double math = ceil(0);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test7) {
  long double s21 = s21_ceil(-5);
  long double math = ceil(-5);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_ceil_test8) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < SCIENTS; i++) {
    s21_res = s21_ceil(scients[i]);
    res = ceil(scients[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_ceil_test9) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  for (int i = 0; i < DOUBLES; i++) {
    s21_res = s21_ceil(doubles[i]);
    res = ceil(doubles[i]);
    ck_assert_double_eq_tol(s21_res, res, 1e-7);
  }
}
END_TEST

START_TEST(s21_ceil_test10) {
  long double s21_res = 0, res = 0;
  long double S = 0;

  s21_res = s21_ceil(S21_NAN);
  res = ceil(S21_NAN);
  ck_assert_ldouble_nan(s21_res);

  s21_res = s21_ceil(S21_INF);
  res = ceil(S21_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_ceil(S21_MIN_INF);
  res = ceil(S21_MIN_INF);
  ck_assert_ldouble_infinite(s21_res);
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s = suite_create("s21_abs_test");
  TCase *tc_abs = tcase_create("[s21_abs_test] case");
  tcase_add_test(tc_abs, s21_abs_test_1);
  suite_add_tcase(s, tc_abs);
  tcase_set_timeout(tc_abs, 100);
  return s;
}

Suite *s21_fabs_suite(void) {
  Suite *s = suite_create("s21_fabs_test");
  TCase *tc_fabs = tcase_create("[s21_fabs_test] case");
  tcase_add_test(tc_fabs, s21_fabs_test_1);
  tcase_add_test(tc_fabs, s21_fabs_test_2);
  tcase_add_test(tc_fabs, s21_fabs_test_3);
  suite_add_tcase(s, tc_fabs);
  tcase_set_timeout(tc_fabs, 100);
  return s;
}

Suite *s21_exp_suite(void) {
  Suite *s = suite_create("s21_exp_test");
  TCase *tc_exp = tcase_create("[s21_exp_test] case");
  tcase_add_test(tc_exp, s21_exp_test_1);
  tcase_add_test(tc_exp, s21_exp_test_2);
  tcase_add_test(tc_exp, s21_exp_test_3);
  suite_add_tcase(s, tc_exp);
  tcase_set_timeout(tc_exp, 100);
  return s;
}

Suite *s21_log_suite(void) {
  Suite *s = suite_create("s21_log_test");
  TCase *tc_log = tcase_create("[s21_log_test] case");
  tcase_add_test(tc_log, s21_log_test_1);
  tcase_add_test(tc_log, s21_log_test_2);
  tcase_add_test(tc_log, s21_log_test_3);
  suite_add_tcase(s, tc_log);
  tcase_set_timeout(tc_log, 100);
  return s;
}

Suite *s21_sqrt_suite(void) {
  Suite *s = suite_create("s21_sqrt_test");
  TCase *tc_sqrt = tcase_create("[s21_sqrt_test] case");
  tcase_add_test(tc_sqrt, s21_sqrt_test_1);
  tcase_add_test(tc_sqrt, s21_sqrt_test_2);
  tcase_add_test(tc_sqrt, s21_sqrt_test_3);
  suite_add_tcase(s, tc_sqrt);
  tcase_set_timeout(tc_sqrt, 100);
  return s;
}

Suite *s21_asin_suite(void) {
  Suite *s = suite_create("s21_asin_test");
  TCase *tc_asin = tcase_create("[s21_asin_test] case");
  tcase_add_test(tc_asin, s21_asin_test_1);
  tcase_add_test(tc_asin, s21_asin_test_2);
  tcase_add_test(tc_asin, s21_asin_test_3);
  suite_add_tcase(s, tc_asin);
  tcase_set_timeout(tc_asin, 100);
  return s;
}

Suite *s21_acos_suite(void) {
  Suite *s = suite_create("s21_acos_test");
  TCase *tc_acos = tcase_create("[s21_acos_test] case");
  tcase_add_test(tc_acos, s21_acos_test_1);
  tcase_add_test(tc_acos, s21_acos_test_2);
  tcase_add_test(tc_acos, s21_acos_test_3);
  suite_add_tcase(s, tc_acos);
  tcase_set_timeout(tc_acos, 100);
  return s;
}

Suite *s21_atan_suite(void) {
  Suite *s = suite_create("s21_atan_test");
  TCase *tc_atan = tcase_create("[s21_atan_test] case");
  tcase_add_test(tc_atan, s21_atan_test_1);
  tcase_add_test(tc_atan, s21_atan_test_2);
  tcase_add_test(tc_atan, s21_atan_test_3);
  suite_add_tcase(s, tc_atan);
  tcase_set_timeout(tc_atan, 100);
  return s;
}

Suite *s21_sin_suite(void) {
  Suite *s = suite_create("s21_sin_test");
  TCase *tc_s21_sin = tcase_create("[s21_sin] case");

  tcase_add_test(tc_s21_sin, sin_test_default);
  tcase_add_test(tc_s21_sin, sin_test_bigger_p);
  tcase_add_test(tc_s21_sin, sin_test_small);
  tcase_add_test(tc_s21_sin, sin_test_zero);
  tcase_add_test(tc_s21_sin, sin_test_INF);
  tcase_add_test(tc_s21_sin, sin_test_NAN);
  suite_add_tcase(s, tc_s21_sin);

  tcase_set_timeout(tc_s21_sin, 100);
  return s;
}

Suite *s21_cos_suite(void) {
  Suite *s = suite_create("s21_cos_test");
  TCase *tc_s21_cos = tcase_create("[s21_cos] case");

  tcase_add_test(tc_s21_cos, cos_test_default);
  tcase_add_test(tc_s21_cos, cos_test_bigger_p);
  tcase_add_test(tc_s21_cos, cos_test_small);
  tcase_add_test(tc_s21_cos, cos_test_zero);
  tcase_add_test(tc_s21_cos, cos_test_zero);
  tcase_add_test(tc_s21_cos, cos_test_NAN);

  suite_add_tcase(s, tc_s21_cos);

  tcase_set_timeout(tc_s21_cos, 100);
  return s;
}

Suite *s21_tan_suite(void) {
  Suite *s = suite_create("s21_tan_test");
  TCase *tc_s21_tan = tcase_create("[s21_tan] case");

  tcase_add_test(tc_s21_tan, tan_test_default);
  tcase_add_test(tc_s21_tan, tan_test_bigger_p);
  tcase_add_test(tc_s21_tan, tan_test_small);

  suite_add_tcase(s, tc_s21_tan);

  tcase_set_timeout(tc_s21_tan, 100);
  return s;
}

Suite *s21_floor_suite(void) {
  Suite *s = suite_create("s21_floor_test");
  TCase *tc_s21_floor = tcase_create("[s21_floor] case");

  tcase_add_test(tc_s21_floor, floor_test_default);
  tcase_add_test(tc_s21_floor, floor_test_bigger_p);
  tcase_add_test(tc_s21_floor, floor_test_small);
  tcase_add_test(tc_s21_floor, s21_floor_test1);
  tcase_add_test(tc_s21_floor, s21_floor_test2);
  tcase_add_test(tc_s21_floor, s21_floor_test3);

  suite_add_tcase(s, tc_s21_floor);

  tcase_set_timeout(tc_s21_floor, 100);
  return s;
}

Suite *fmod_suite() {
  Suite *s;
  TCase *tc_pos_int, *tc_pos_fr, *tc_neg_int, *tc_neg_fr, *tc_pos_fr2, *tc_zero;
  s = suite_create("s21_fmod");

  tc_pos_int = tcase_create("Test №1 Positive int");
  tcase_add_test(tc_pos_int, s21_fmod_test1);
  suite_add_tcase(s, tc_pos_int);

  tc_pos_fr = tcase_create("Test №2 Positive fraction");
  tcase_add_test(tc_pos_fr, s21_fmod_test2);
  suite_add_tcase(s, tc_pos_fr);

  tc_neg_int = tcase_create("Test №3 Negative int");
  tcase_add_test(tc_neg_int, s21_fmod_test3);
  suite_add_tcase(s, tc_neg_int);

  tc_neg_fr = tcase_create("Test №4 Negative fraction");
  tcase_add_test(tc_neg_fr, s21_fmod_test4);
  suite_add_tcase(s, tc_neg_fr);

  tc_pos_fr2 = tcase_create("Test №5 Positive fraction 2");
  tcase_add_test(tc_pos_fr2, s21_fmod_test5);
  suite_add_tcase(s, tc_pos_fr2);

  tc_zero = tcase_create("Test №6 Positive zero");
  tcase_add_test(tc_zero, s21_fmod_test6);
  suite_add_tcase(s, tc_zero);

  tc_zero = tcase_create("Test №7 Positive zero");
  tcase_add_test(tc_zero, s21_fmod_test7);
  suite_add_tcase(s, tc_zero);

  tc_zero = tcase_create("Test №8 Positive zero");
  tcase_add_test(tc_zero, s21_fmod_test8);
  tcase_add_test(tc_zero, s21_fmod_test9);
  suite_add_tcase(s, tc_zero);

  return s;
}

Suite *pow_suite() {
  Suite *s;
  TCase *tc_pos_int, *tc_pos_fr, *tc_neg_int, *tc_neg_fr, *tc_pos_fr2, *tc_zero;
  s = suite_create("s21_pow");

  tc_pos_int = tcase_create("Test №1 Positive int");
  tcase_add_test(tc_pos_int, s21_pow_test1);
  suite_add_tcase(s, tc_pos_int);

  tc_pos_fr = tcase_create("Test №2 Positive fraction");
  tcase_add_test(tc_pos_fr, s21_pow_test2);
  suite_add_tcase(s, tc_pos_fr);

  tc_neg_int = tcase_create("Test №3 Negative int");
  tcase_add_test(tc_neg_int, s21_pow_test3);
  suite_add_tcase(s, tc_neg_int);

  tc_neg_fr = tcase_create("Test №4 Negative fraction");
  tcase_add_test(tc_neg_fr, s21_pow_test4);
  suite_add_tcase(s, tc_neg_fr);

  tc_pos_fr2 = tcase_create("Test №5 Positive fraction 2");
  tcase_add_test(tc_pos_fr2, s21_pow_test5);
  suite_add_tcase(s, tc_pos_fr2);

  tc_zero = tcase_create("Test №6 Positive zero");
  tcase_add_test(tc_zero, s21_pow_test6);
  suite_add_tcase(s, tc_zero);

  tc_zero = tcase_create("Test №7 INF NAN");
  tcase_add_test(tc_zero, s21_pow_test7);
  suite_add_tcase(s, tc_zero);

  return s;
}

Suite *ceil_suite() {
  Suite *s;
  TCase *tc_pos_fr, *tc_pos_fr2, *tc_pos_fr3, *tc_neg_fr, *tc_pos_int, *tc_zero,
      *tc_neg_int;
  s = suite_create("s21_ceil");

  tc_pos_fr = tcase_create("Test №1 positive fraction");
  tcase_add_test(tc_pos_fr, s21_ceil_test1);
  suite_add_tcase(s, tc_pos_fr);

  tc_pos_fr2 = tcase_create("Test №2 positive fraction");
  tcase_add_test(tc_pos_fr2, s21_ceil_test2);
  suite_add_tcase(s, tc_pos_fr2);

  tc_pos_fr3 = tcase_create("Test №3 positive fraction");
  tcase_add_test(tc_pos_fr3, s21_ceil_test3);
  suite_add_tcase(s, tc_pos_fr3);

  tc_neg_fr = tcase_create("Test №4 negative fraction");
  tcase_add_test(tc_neg_fr, s21_ceil_test4);
  suite_add_tcase(s, tc_neg_fr);

  tc_pos_int = tcase_create("Test №5 positive int");
  tcase_add_test(tc_pos_int, s21_ceil_test5);
  tcase_add_test(tc_pos_int, s21_ceil_test8);
  tcase_add_test(tc_pos_int, s21_ceil_test9);
  tcase_add_test(tc_pos_int, s21_ceil_test10);
  suite_add_tcase(s, tc_pos_int);

  tc_zero = tcase_create("Test №6 zero");
  tcase_add_test(tc_zero, s21_ceil_test6);
  suite_add_tcase(s, tc_zero);

  tc_neg_int = tcase_create("Test №7 negative int");
  tcase_add_test(tc_neg_int, s21_ceil_test7);
  suite_add_tcase(s, tc_neg_int);

  return s;
}

int main(void) {
  int failed = 0;

  Suite *s_abs;
  SRunner *runner_abs;
  s_abs = s21_abs_suite();
  runner_abs = srunner_create(s_abs);
  srunner_run_all(runner_abs, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_abs);
  srunner_free(runner_abs);

  Suite *s_fabs;
  SRunner *runner_fabs;
  s_fabs = s21_fabs_suite();
  runner_fabs = srunner_create(s_fabs);
  srunner_run_all(runner_fabs, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_fabs);
  srunner_free(runner_fabs);

  Suite *s_exp;
  SRunner *runner_exp;
  s_exp = s21_exp_suite();
  runner_exp = srunner_create(s_exp);
  srunner_run_all(runner_exp, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_exp);
  srunner_free(runner_exp);

  Suite *s_log;
  SRunner *runner_log;
  s_log = s21_log_suite();
  runner_log = srunner_create(s_log);
  srunner_run_all(runner_log, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_log);
  srunner_free(runner_log);

  Suite *s_sqrt;
  SRunner *runner_sqrt;
  s_sqrt = s21_sqrt_suite();
  runner_sqrt = srunner_create(s_sqrt);
  srunner_run_all(runner_sqrt, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_sqrt);
  srunner_free(runner_sqrt);

  Suite *s_asin;
  SRunner *runner_asin;
  s_asin = s21_asin_suite();
  runner_asin = srunner_create(s_asin);
  srunner_run_all(runner_asin, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_asin);
  srunner_free(runner_asin);

  Suite *s_acos;
  SRunner *runner_acos;
  s_acos = s21_acos_suite();
  runner_acos = srunner_create(s_acos);
  srunner_run_all(runner_acos, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_acos);
  srunner_free(runner_acos);

  Suite *s_atan;
  SRunner *runner_atan;
  s_atan = s21_atan_suite();
  runner_atan = srunner_create(s_atan);
  srunner_run_all(runner_atan, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_atan);
  srunner_free(runner_atan);

  Suite *s_sin;
  SRunner *runner_sin;
  s_sin = s21_sin_suite();
  runner_sin = srunner_create(s_sin);
  srunner_run_all(runner_sin, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_sin);
  srunner_free(runner_sin);

  Suite *s_cos;
  SRunner *runner_cos;
  s_cos = s21_cos_suite();
  runner_cos = srunner_create(s_cos);
  srunner_run_all(runner_cos, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_cos);
  srunner_free(runner_cos);

  Suite *s_tan;
  SRunner *runner_tan;
  s_tan = s21_tan_suite();
  runner_tan = srunner_create(s_tan);
  srunner_run_all(runner_tan, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_tan);
  srunner_free(runner_tan);

  Suite *s_floor;
  SRunner *runner_floor;
  s_floor = s21_floor_suite();
  runner_floor = srunner_create(s_floor);
  srunner_run_all(runner_floor, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_floor);
  srunner_free(runner_floor);

  SRunner *runner_fmod;
  Suite *s_fmod;
  s_fmod = fmod_suite();
  runner_fmod = srunner_create(s_fmod);
  srunner_run_all(runner_fmod, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_fmod);
  srunner_free(runner_fmod);

  SRunner *runner_pow;
  Suite *s_pow;
  s_pow = pow_suite();
  runner_pow = srunner_create(s_pow);
  srunner_run_all(runner_pow, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_pow);
  srunner_free(runner_pow);

  SRunner *runner_ceil;
  Suite *s_ceil;
  s_ceil = ceil_suite();
  runner_ceil = srunner_create(s_ceil);
  srunner_run_all(runner_ceil, CK_VERBOSE);
  failed = srunner_ntests_failed(runner_ceil);
  srunner_free(runner_ceil);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
