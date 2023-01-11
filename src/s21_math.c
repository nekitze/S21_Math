#include "s21_math.h"

long double s21_exp(double x) {
  long double ans0 = 0, ans = 0;
  if (x != x)
    ans0 = S21_NAN;
  else if (x == S21_MIN_INF)
    ans0 = 0;
  else if (x == S21_INF)
    ans0 = S21_INF;
  else {
    ans0 = 1;
    int n = 1;
    long double npow = x, nfac = 1;
    while (s21_fabs(ans0 - ans) > 1e-15) {
      ans = ans0;
      ans0 += npow / nfac;
      nfac *= ++n;
      npow *= x;
    }
  }
  return ans0;
}

long double s21_fmod(double x, double y) {
  long double ans = 0, min_flag = 0;
  if ((x == S21_INF) || (x == S21_MIN_INF))
    ans = S21_NAN;
  else if (s21_fabs(y) < S21_EPS)
    ans = S21_NAN;
  else if ((y == S21_INF) || (y == S21_MIN_INF))
    ans = x;
  else {
    if (y < 0) {
      y *= -1;
    }
    if (x < 0) {
      x *= -1;
      min_flag = 1;
    }
    if (min_flag)
      ans = -1 * (x - y * (long long int)(x / y));
    else
      ans = x - y * (long long int)(x / y);
  }
  return ans;
}

long double s21_acos(double x) {
  long double ans = S21_NAN;
  if (s21_fabs(-1.0 - x) < S21_EPS)
    ans = S21_M_PI;
  else if (s21_fabs(x - 1) < S21_EPS)
    ans = 0;
  else if (x > -1.0 && x < 1.0)
    ans = S21_M_PI / 2 - s21_asin(x);
  return ans;
}

long double s21_atan(double x) {
  long double ans0 = 0, ans = 0, eps = 5e-8, delta = 0, S = x;
  int big_flag = 0, minus_flag = 0;
  if (S != S)
    ans = S21_NAN;
  else if (S == S21_INF)
    ans = S21_M_PI / 2;
  else if (S == S21_MIN_INF)
    ans = -S21_M_PI / 2;
  else if (s21_fabs(S) < S21_EPS)
    ans = 0;
  else if (s21_fabs(S - 1.0) < eps) {
    ans = S21_M_PI / 4;
  } else if (S == -1.0)
    ans = -S21_M_PI / 4;
  else {
    if (S > 1) {
      S = 1 / S;
      big_flag = 1;
    }
    if (S < 0) {
      S *= -1;
      minus_flag = 1;
    }
    int n = 1;
    if ((S < 1) && (S > -1)) {
      ans0 += S / (2 * 0 + 1);
      delta = s21_fabs(ans0 - ans);
      int i = 1;
      while (delta > eps) {
        n *= -1;
        ans0 += n * s21_pow(S, 2 * i + 1) / (2 * i + 1);
        delta = s21_fabs(ans0 - ans);
        ans = ans0;
        ++i;
      }
    } else if (S >= 1) {
      ans0 += S21_M_PI / 2;
      ans0 -= 1 / S / (2 * 0 + 1);
      delta = s21_fabs(ans0 - ans);
      ans = ans0;
      int i = 1;
      while (delta > eps) {
        n *= -1;
        ans0 -= n / s21_pow(S, 2 * i + 1) / (2 * i + 1);
        delta = s21_fabs(ans0 - ans);
        ans = ans0;
        ++i;
      }
    }
  }
  if (big_flag) ans = S21_M_PI / 2 - ans;
  if (minus_flag) ans *= -1;
  return ans;
}

long double s21_asin(double x) {
  long double ans = 0;
  if (x < -1)
    ans = S21_NAN;
  else if (x != x)
    ans = S21_NAN;
  else if (x > 1)
    ans = S21_NAN;
  else if (x == S21_INF)
    ans = S21_NAN;
  else if (x == S21_MIN_INF)
    ans = S21_NAN;
  else {
    ans = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return ans;
}

long double s21_log(double x) {
  long double ans = 1000, S = x;
  if (S < 0)
    ans = S21_NAN;
  else if (s21_fabs(S) < 1e-6)
    ans = S21_MIN_INF;
  else if (S != S)
    ans = S21_NAN;
  else if (S == S21_INF)
    ans = S21_INF;
  else if (S == S21_MIN_INF)
    ans = S21_NAN;
  else if (S > 0) {
    long double ans0 = 0;
    for (int i = 1; ((i < 5500) && (s21_fabs(s21_fabs(ans) - s21_fabs(ans0)) >
                                    S21_EPS_TAYLOR));
         ++i) {
      ans = ans0;
      ans0 += 2 * (x - s21_exp(ans0)) / (x + s21_exp(ans0));
    }
  }
  return ans;
}

long double s21_sqrt(double x) {
  long double S = x;
  long double xi = S / 2;
  long double xi_1 = S / 2;
  long double eps = 1;
  if (s21_fabs(S) < S21_EPS)
    xi = 0;
  else if (S < 0)
    xi = S21_NAN;
  else if (S != S)
    xi = S21_NAN;
  else if (S == S21_INF)
    xi = S21_INF;
  else if (S == S21_MIN_INF)
    xi = S21_NAN;
  else if (S > 0) {
    xi = S / 2;
    while ((S > 0) && (eps > S21_EPS_TAYLOR)) {
      xi = (xi_1 + S / xi_1) / 2;
      eps = -(S - xi * xi) / (2 * xi);
      xi_1 = xi;
    }
  }
  return xi;
}

long double to_range(double x) {
  long long int y = x / 2 / S21_M_PI;
  x = x - y * 2 * S21_M_PI - 2 * S21_M_PI;
  return x;
}

long double s21_sin(double x) {
  long double ans = 0;
  if (s21_isnan(x) || !s21_isfinite(x))
    ans = S21_NAN;
  else {
    x = to_range(x);
    long double n = 1, sign = 1, ans0 = 2, npow = x, fac = 1;
    while (s21_fabs(s21_fabs(ans0) - s21_fabs(ans)) > S21_EPS_TAYLOR) {
      ans0 = ans;
      ans += sign * npow / fac;
      sign *= -1;
      npow *= x * x;
      fac *= (2 * n) * (2 * n + 1);
      ++n;
    }
  }
  return ans;
}

long double s21_cos(double x) {
  long double ans = 0;
  if (s21_isnan(x) || !s21_isfinite(x))
    ans = S21_NAN;
  else {
    x = to_range(x);
    long double n = 1, sign = 1, ans0 = 2, npow = 1, fac = 1;
    while (s21_fabs(s21_fabs(ans0) - s21_fabs(ans)) > S21_EPS_TAYLOR) {
      ans0 = ans;
      ans += sign * npow / fac;
      sign *= -1;
      npow *= x * x;
      fac *= (2 * n - 1) * (2 * n);
      ++n;
    }
  }
  return ans;
}

long double s21_tan(double x) {
  if (s21_isnan(x) || !s21_isfinite(x)) return S21_NAN;
  return s21_sin(x) / s21_cos(x);
}

long double s21_floor(double x) {
  long double ans = x >= 0. ? (int)x : (int)(x - 1.);
  if (x != x) {
    ans = S21_NAN;
  } else if (x == -S21_INF) {
    ans = S21_INF;
  } else if (x == S21_INF) {
    ans = S21_MIN_INF;
  } else if ((s21_fabs((int)x - x) < S21_EPS) && (x < 0))
    ++ans;
  return ans;
}

long double s21_fabs(double x) {
  long double result = x;
  if (x != x)
    result = S21_NAN;
  else if (x < 0)
    result *= -1.0;
  return result;
}

int s21_abs(int x) { return (x < 0) ? x *= -1 : x; }

bool isInt(double val) { return (val == ((double)((int)val))); }

long double s21_pow(double base, double exp) {
  long double ans = 1;
  if ((exp != exp) || (base != base)) {
    ans = S21_NAN;
  } else if (exp == -S21_INF) {
    if (base != 1)
      ans = 0;
    else
      ans = 1;
  } else if (exp == S21_INF) {
    if (base != 1)
      ans = S21_INF;
    else
      ans = 1;
  } else {
    if (exp > 0) {
      for (long long int i = 0; i < (long long int)exp; ++i) {
        ans *= base;
      }
    } else if (exp < 0) {
      for (long long int i = 0; i > (long long int)exp; --i) {
        ans /= base;
      }
    }
    long double expl = s21_fabs(exp) - s21_fabs((long long int)exp);
    if (expl > 0) {
      if (exp > 0) {
        ans *= s21_exp(expl * s21_log(base));
      } else if (exp < 0) {
        ans *= s21_exp(expl * s21_log(1 / base));
      }
    }
  }
  return ans;
}

long double s21_ceil(double x) {
  long double res;
  if (x != x) {
    res = S21_NAN;
  } else if (x == -S21_INF) {
    res = S21_INF;
  } else if (x == S21_INF) {
    res = S21_MIN_INF;
  } else if (isInt(x) || x == 0) {
    res = x;
  } else if (x > 0) {
    res = (int)x + 1;
  } else if (x < 0) {
    double dif = x - (int)x;
    res = x - dif;
  }
  return res;
}
