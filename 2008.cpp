#include <stdio.h>
#include <string.h>
#define maxn 1000010

int head,tail;
int list[maxn];
int dist[maxn];
bool vist[maxn];
int sum;
int pre[2][maxn],now[2][maxn],son[2][maxn],cost[2][maxn];
int P,Q;

inline 
void Build(const int& way,const int &x,const int &y,const int &dis) {	//Build False Linked-List 
	pre[way][sum] = now[way][x];
	now[way][x] = sum;
	son[way][sum] = y;
	cost[way][sum] = dis;
}

inline 
void Input() {
	sum=0;
	memset(pre,0,sizeof(pre));
	memset(now,0,sizeof(now));
	memset(son,0,sizeof(son));
	memset(cost,0,sizeof(cost));
	scanf("%d%d",&P,&Q);
	int x,y,dis;
	for (int i=0;i<Q;i++) {
		scanf("%d%d%d",&x,&y,&dis);
		sum++;
		Build(0,x,y,dis);  	//Forward Path 
		Build(1,y,x,dis);	//Backward Path
	}
}

int Spfa(const int &way) {
	memset(vist,0,sizeof(vist));
	memset(dist,0x3f,sizeof(dist));
	int head=0,tail=1;
	vist[1]=true; 
	dist[1]=0;
	list[1]=1;
	int dot,ptr;
	int next,value;
	while (head!=tail) {
		head = head%maxn+1;
		dot = list[head];
		vist[dot] = false;
		ptr = now[way][dot];
		while (ptr) {
			next = son[way][ptr];
			value = dist[dot] + cost[way][ptr];
			if ( dist[ next ]> value ) {
				dist[ next ] = value;
				if (!vist[ next ]) {
					vist[ next ] = true;
					if ( dist[ next ]>dist[ head%maxn+1 ] ) {  	//SLF
						tail = tail%maxn + 1;
						list[tail] = next;
					} else {
						list[head] = next;
						head--;
						if (head==-1) head=maxn; 
					}											//SLF END 
				}
			}
			ptr = pre[way][ptr];
		}
	} 
	int result=0;
	for (int i=2;i<=P;i++) result += dist[i];
	return result;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		Input();
		printf("%d\n",Spfa(0)+Spfa(1));
	}
}

