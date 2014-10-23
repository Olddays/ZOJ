#include <stdio.h>

int n;

int JosephusRing(const int &k) {
	int ans = 0;
	for (int i=2;i<=n;i++) ans = (ans+k)%i;
	return ans;
}

int main() {
	int m;
	while (scanf("%d",&n)&&n) {
		n = n-1;
		m = 1;
		while ( JosephusRing(m) ) m++;	//Mark CGB,3nd Building,4th Building...Nth Building with 0,1,2...n-2
		printf("%d\n",m);				//So It's not the right m If The Answer of Josephus Problem is not 0,which stand for CGB
	}
}

