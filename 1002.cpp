#include <string.h>
#include <iostream>
using namespace std;

bool Wall[4][4];
bool State[4][4];
int n;
int ans;

inline void Input(){
	ans = 0;
	memset(Wall, 0, sizeof(Wall));
	memset(State, 0, sizeof(State));
	char temp;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++){
			cin >> temp;
			Wall[i][j] = (temp == 'X');
		}
}

void DFS(const int r, const int c, const int now){
	ans = ans<now ? now : ans;
	if (Wall[r][c]){
		DFS(r+(c+1)/n, (c + 1)%n, now);
		return;
	}
	if (r >= n) return;
	bool flag = true;
	for (int k = r - 1; flag && (k >= 0) && !Wall[k][c]; k--){
		if (State[k][c]) flag = false;
	}
	for (int k = r + 1; flag && (k<n) && !Wall[k][c]; k++){
		if (State[k][c]) flag = false;
	}
	for (int k = c - 1; flag && (k >= 0) && !Wall[r][k]; k--){
		if (State[r][k]) flag = false;
	}
	for (int k = c + 1; flag && (k<n) && !Wall[r][k]; k++){
		if (State[r][k]) flag = false;
	}
	if (flag){
		State[r][c] = true;
		DFS(r + (c + 1) / n, (c + 1) % n, now + 1);
		State[r][c] = false;
	}
	DFS(r + (c + 1) / n, (c + 1) % n, now);
}

int main(){
	while ((cin >> n)&&n){
		Input();
		DFS(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
