#include <stdio.h>

#define SIZE 16
#define MAP_SIZE 20

int D[SIZE];
int map[2][MAP_SIZE][MAP_SIZE];
const char Mark[4] = {'.','!','X','#'};

int n;

void Input() {
	scanf("%d", &n);
	for (int i=0;i<SIZE;i++) scanf("%d", D+i);
	for (int i=0;i<MAP_SIZE;i++) {
		for (int j=0;j<MAP_SIZE;j++) scanf("%d", &map[0][i][j]);
	}
}

void Print(int z) {
	for (int i=0;i<MAP_SIZE;i++) {
		for (int j=0;j<MAP_SIZE;j++) printf("%c", Mark[ map[z][i][j] ]);
		printf("\r\n");
	}
}

int Next(int x, int y ,int z) {
	int k = map[z][x][y];
	k += (x) ? map[z][x-1][y] : NULL;
	k += ((x+1)<MAP_SIZE) ? map[z][x+1][y] : NULL;
	k += (y) ? map[z][x][y-1] : NULL;
	k += ((y+1)<MAP_SIZE) ? map[z][x][y+1] : NULL;
	int result = (map[z][x][y]+D[k]);
	if (result>3) result = 3;
	else if (result<0) result = 0;
	return result;
}

int main() {
	int time;
	scanf("%d",&time);
	int z;
	for (int i=0;i<time;i++) {
		Input();
		z = 0;
		for (int t=0;t<n;t++) {
			for (int i=0;i<MAP_SIZE;i++) {
				for (int j=0;j<MAP_SIZE;j++) map[z xor 1][i][j] = Next(i,j,z);
			}
			z = z xor 1;
		}
		Print(z);
		if (i<(time-1)) printf("\r\n");
	}
	return 0;
}

	
	
