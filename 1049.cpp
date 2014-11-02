#include <stdio.h>
#include <math.h>

#define pi M_PI

int main() {
  int n;
  double x,y;
  int ans;
  scanf("%d",&n);
  for (int i=1;i<=n;i++) {
    scanf("%lf%lf",&x,&y);
    ans=(int)ceil((x*x+y*y)*pi/100);
    printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
  }
  printf("END OF OUTPUT.\n");
  return 0;
}
  
    
