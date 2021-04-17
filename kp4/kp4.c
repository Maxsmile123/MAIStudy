#include <math.h> 
#include <stdio.h> 
 
typedef struct root_x root;
 
struct root_x 
{
  double x;
  int steps;
};
 
double square(double x) 
{
  return x * x;
}
 
root solve_binary_search(double f(double), double l, double r, int k, double acc) 
{
  int step = 0;
  double m;
  while (r - l > acc) {
    step++;
    m = (l + r) / 2.0;
  if (f(m) * f(l) < 0) {
    r = m;
} else {
    l = m;
  }
}
  root ans = { m, step };
  return ans;
}
 
 
 
root solve_iteration(double f(double), double x0, int k, double acc) 
{
  int step = 0;
  double cur = x0;
  double prev = cur + 1;
  while (fabs(cur - prev) > acc) {
    prev = cur;
    cur = f(prev);
    step++;
  }
  root ans = { cur, step };
  return ans;
}
 
 
root solve_newton(double f(double), double derivative_f(double), double x0, int k, double acc) 
{
  int step = 0;
  double cur = x0;
  double prev = cur + 1;
  while (fabs(cur - prev) > acc) {
    prev = cur;
    cur = prev - f(prev) / derivative_f(prev);
    step++;
  }
  root ans = { cur, step };
  return ans;
}
 
 
double f13(double x) {
  return x * tan(x) - 1.0 / 3.0;
}
 
double squeeze_f13(double x) {
  return x - f13(x) / 1.564962;
}
 
double d_dx_f13(double x) {
  return tan(x) + x / square(cos(x));
}
 
double f14(double x) {
  return tan(x / 2.0) - 1 / tan(x / 2.0) + x;
}
 
double squeeze_f14(double x) {
  return x - f14(x) / 3.010057;
}
 
double d_dx_f14(double x) {
  return 1.0 / (2.0 * square(cos(x / 2.0))) + 1 / (2.0 * square(sin(x / 2.0))) + 1;
}
 
int main() {
  int k;
  scanf_s("%d", &k);
  double e0 = 1.0;
  while ((1.0 + e0 / 2.0) > 1.0) {
    e0 = e0 / 2.0;
  }
  double acc = e0 * pow(10, 16 - k);
  root x0;
  printf("Machine epsilon equals %.8e\n", e0);
  printf("______________________________________\n");
  printf("Answer for x*tg(x)-1/3=0\n");
  x0 = solve_binary_search(f13, 0.2, 1.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);

  x0 = solve_iteration(squeeze_f13, (0.2 + 1.0) / 2.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);
  x0 = solve_newton(f13, d_dx_f13, (0.2 + 1.0) / 2.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);
  printf("Answer for tg(x/2)-ctg(x/2)+x=0\n");
  x0 = solve_binary_search(f14, 1.0, 2.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);
  x0 = solve_iteration(squeeze_f14, (1.0 + 2.0) / 2.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);
  x0 = solve_newton(f14, d_dx_f14, (1.0 + 2.0) / 2.0, k, acc);
  printf("%.*f | %d\n", k, x0.x, x0.steps);
  return 0;
}
