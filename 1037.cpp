#include <stdio.h>
#include <math.h>

int main() {
  int time;
  int n,m;
  double ans;
  scanf("%d",&time);
  for (int i=1;i<=time;i++) {
    scanf("%d%d",&n,&m);
    ans=(double)n*m;
    if (n&m&1) ans+=sqrt(2.0)-1;
    printf("Scenario #%d:\n%.2f\n\n",i,ans);
  }
  return 0;
}
