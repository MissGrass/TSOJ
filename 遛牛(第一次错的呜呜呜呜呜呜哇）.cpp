/*C. 遛牛
题目描述
今天天气好晴朗，处处好风光。在经过了一个多月的阴雨天气，农夫 Jony 和他的母牛都快发霉了，
终于今天天气放晴了。Jony 决定带着他的母牛一起出去溜达溜达。
他们来到田野里，田野里的青草是那么的诱人，母牛想吃青草，但是有些地方种上了玉米，不能通过。
母牛走过的地方青草都被吃完了，所以母牛不会再往回走（不会走回头路）。
现在 Jony 站在田野的一边，问有多少种方法能够到达终点。

输入描述
一行 两个字符 m , n ( 2 < m, n < 20 )
表示 m 行 n 列 的一片田野
接着 m 行，每行 n 个字符表示田野
1 表示草地 (可以通行)
0 表示玉米地 (不能通行)
S 表示起点
E 表示终点

输出描述
一行，问有多少条路线可以从起点到达终点。

样例输入
5 5
000S0
01010
01010
01110
E1000
样例输出
1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, p, q, cnt = 0;
char a[21][21], book[21][21];
void dfs(int x, int y, int step) {
	int next[4][2] = {{0,1},//向右走 
					  {1,0},//向下走 
					  {0,-1},//向左走 
					  {-1,0}};//向上走
	int tx, ty, k;
	//判断是否到达终点
	if(x == p && y == q) {
		//更新路径数
		cnt += 1;
		return;//这里返回
	} 
	
	//枚举4种走法
	for(k = 0; k <= 3; k++) {
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		//判断该点是否为玉米地或者已经走过
		if(a[tx][ty] == 0 && book[tx][ty] ==0) {
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx, ty, step+1);//开始尝试下一个点
			book[tx][ty] = 0;//尝试结束，取消这个点的标记 
		} 
	} 
	return ; 
}
int main() {
	freopen("test.txt", "r", stdin); 
	int i, j, startx, starty;
	//m行n列
	scanf("%d%d", &m, &n);
	//读入迷宫 
	for(i = 1; i <= m+1; i++) 
		for(j = 1; j <= n; j++)
			 {
			 	scanf("%c", &a[i][j]);
			 }
	//寻找起点 a[startx][starty]和终点a[p][q] 
	for(i = 1; i <= m; i++) 
		for(j = 1; j <= n; j++) { 
			if(a[i][j] == 'S') {
				startx = i;
				starty = j;
			}
			if(a[i][j] == 'E') {
				p = i;
				q = j;
			}
		}
	//从起点开始搜索
	book[startx][starty] = 1;//标记起点已经在路径中，防止后面重复走
	//调用函数
	dfs(startx, starty, 0); 
	printf("%d %d %d %d\n", startx,starty,p,q);
	//输出路径数
	printf("%d",cnt);
	getchar(); getchar();
	return 0;
}

