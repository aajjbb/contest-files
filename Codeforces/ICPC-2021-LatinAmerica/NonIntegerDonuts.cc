#include <stdio.h>
#include <math.h>

int main(void) {
  int N;
  double start_d;
  double curr_value;

  scanf("%d\n%*c%lf", &N, &start_d);

  curr_value = start_d;

  int ans = 0;

  for (int i = 0; i < N; i++) {
    double dep = 0;
    scanf("\n%*c%lf", &dep);

    curr_value += dep;

    double rounded = round(curr_value);

    if (fabs(rounded - curr_value) > 1e-7) {
      ans += 1;
    }
  }

  printf("%d\n", ans);

  return 0;
}
