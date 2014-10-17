#include<stdio.h>

bool okay_a,okay_b;

void DFS(int x,int y,int dep) {
	if (dep>100||okay_a&&okay_b) return;
	if (y==1) {
		okay_b=true;
		if (x==1) okay_a=true;
	}
	if (y%dep==0) DFS(x,y/dep,dep+1);
	if (x%dep==0) DFS(x/dep,y,dep+1);
	DFS(x,y,dep+1);
}

int main(){
	int a,b;
	while ( scanf("%d%d",&a,&b)!=EOF ) {
		okay_a=okay_b=false;
		a>b?:(a=a^b,b=a^b,a=a^b);
		DFS(a,b,2);
		if (!okay_a&&okay_b) printf("%d\n",b); else printf("%d\n",a); 
	}
	return 0;
}
