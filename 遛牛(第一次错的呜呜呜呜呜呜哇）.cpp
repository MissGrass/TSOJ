/*C. ��ţ
��Ŀ����
�������������ʣ������÷�⡣�ھ�����һ�����µ�����������ũ�� Jony ������ĸţ���췢ù�ˣ�
���ڽ������������ˡ�Jony ������������ĸţһ���ȥ�����
����������Ұ���Ұ����������ô�����ˣ�ĸţ�����ݣ�������Щ�ط����������ף�����ͨ����
ĸţ�߹��ĵط���ݶ��������ˣ�����ĸţ�����������ߣ������߻�ͷ·����
���� Jony վ����Ұ��һ�ߣ����ж����ַ����ܹ������յ㡣

��������
һ�� �����ַ� m , n ( 2 < m, n < 20 )
��ʾ m �� n �� ��һƬ��Ұ
���� m �У�ÿ�� n ���ַ���ʾ��Ұ
1 ��ʾ�ݵ� (����ͨ��)
0 ��ʾ���׵� (����ͨ��)
S ��ʾ���
E ��ʾ�յ�

�������
һ�У����ж�����·�߿��Դ���㵽���յ㡣

��������
5 5
000S0
01010
01010
01110
E1000
�������
1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, p, q, cnt = 0;
char a[21][21], book[21][21];
void dfs(int x, int y, int step) {
	int next[4][2] = {{0,1},//������ 
					  {1,0},//������ 
					  {0,-1},//������ 
					  {-1,0}};//������
	int tx, ty, k;
	//�ж��Ƿ񵽴��յ�
	if(x == p && y == q) {
		//����·����
		cnt += 1;
		return;//���ﷵ��
	} 
	
	//ö��4���߷�
	for(k = 0; k <= 3; k++) {
		//������һ���������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if(tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		//�жϸõ��Ƿ�Ϊ���׵ػ����Ѿ��߹�
		if(a[tx][ty] == 0 && book[tx][ty] ==0) {
			book[tx][ty] = 1;//���������Ѿ��߹�
			dfs(tx, ty, step+1);//��ʼ������һ����
			book[tx][ty] = 0;//���Խ�����ȡ�������ı�� 
		} 
	} 
	return ; 
}
int main() {
	freopen("test.txt", "r", stdin); 
	int i, j, startx, starty;
	//m��n��
	scanf("%d%d", &m, &n);
	//�����Թ� 
	for(i = 1; i <= m+1; i++) 
		for(j = 1; j <= n; j++)
			 {
			 	scanf("%c", &a[i][j]);
			 }
	//Ѱ����� a[startx][starty]���յ�a[p][q] 
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
	//����㿪ʼ����
	book[startx][starty] = 1;//�������Ѿ���·���У���ֹ�����ظ���
	//���ú���
	dfs(startx, starty, 0); 
	printf("%d %d %d %d\n", startx,starty,p,q);
	//���·����
	printf("%d",cnt);
	getchar(); getchar();
	return 0;
}

