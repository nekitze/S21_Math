#include "s21_math_test.h"
#include <stdio.h>

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
    if (S >= 0 ) 
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
  res = sqrt(S21_MIN_INF);
  ck_assert_ldouble_infinite(s21_res);

  s21_res = s21_sqrt(S21_INF);
  res = sqrt(S21_MIN_INF);
  ck_assert_ldouble_infinite(s21_res);

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
    }
    else {
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
  char result[32];
  char assert[32];
  sprintf(result, "%.6Lf", s21_sin(0));
  sprintf(assert, "%.6f", sin(0));
  ck_assert_str_eq(result, assert);
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

START_TEST(s21_pow_test1) {
  long double s21 = s21_pow(10, 5);
  long double math = pow(10, 5);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_pow_test2) {
  long double s21 = s21_pow(5.6, 0.55);
  long double math = pow(5.6, 0.55);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_pow_test3) {
  long double s21 = s21_pow(3, -4);
  long double math = pow(3, -4);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_pow_test4) {
  long double s21 = s21_pow(3.05, -0.12);
  long double math = pow(3.05, -0.12);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_pow_test5) {
  long double s21 = s21_pow(345.14, 55.1);
  long double math = pow(345.14, 55.1);
  ck_assert_double_eq(s21, math);
}
END_TEST

START_TEST(s21_pow_test6) {
  long double s21 = s21_pow(14, 0);
  long double math = pow(14, 0);
  ck_assert_double_eq(s21, math);
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

Suite *s21_sin_suite(void) {
  Suite *s = suite_create("s21_sin_test");
  TCase *tc_s21_sin = tcase_create("[s21_sin] case");
  
  tcase_add_test(tc_s21_sin, sin_test_default);
  tcase_add_test(tc_s21_sin, sin_test_bigger_p);
  tcase_add_test(tc_s21_sin, sin_test_small);
  tcase_add_test(tc_s21_sin, sin_test_zero);
  tcase_add_test(tc_s21_sin, sin_test_INF);
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

  suite_add_tcase(s, tc_s21_floor);

  tcase_set_timeout(tc_s21_floor, 100);
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

