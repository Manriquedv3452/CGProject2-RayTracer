#include <math.h>

#define max(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

#define min(a,b) \
  ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; })

int double_is_equal(long double x, long double y);

#define EPSILON_AUX 0.00001

int double_is_equal(long double x, long double y)
{
	return (fabs(x - y) < EPSILON_AUX && fabs(x - y) > -EPSILON_AUX);
}

long double power_int(long double element, int exponent)
{
  long double result = element;

  if (exponent == 0)
    return 1.0;

  for (int i = 1; i < exponent; i++)
    result *= element;

  return result;
}