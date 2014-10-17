#include <stdio.h>
#include <string.h> 

char str1[255],str2[255];
char stack[255];
char ans[511];

void DFS(int x,int y,int top) {
	if (y==strlen(str2)) {
		for (int i=0;i<strlen(str2)<<1;i++) {
			printf("%c ",ans[i]);
		}
		printf("\n");
		return;
	}
	if ( x<strlen(str1) ) {
		stack[top]=str1[x];
		ans[x+y]='i';
		DFS(x+1,y,top+1);
	}
	if ( y<strlen(str2)&&top&&stack[top-1]==str2[y] ) {
		ans[x+y]='o';
		DFS(x,y+1,top-1);
		stack[top-1]=str2[y];	//DO NOT FORGET THIS!!! 
	}
}

int main() {
	while ( scanf("%s\n%s",str1,str2)!=EOF ) {
		printf("[\n");
		if ( strlen(str1)==strlen(str2) ) DFS(0,0,0);
		printf("]\n");
	}	
}
