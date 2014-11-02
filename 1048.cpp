#include <stdio.h>

int main() {
  double ans(0),temp;
  for (int i=0;i<12;i++) {
    scanf("%lf",&temp);
    ans+=temp;
  }
  printf("$%.2f\n",ans/12);
  return 0;
}
