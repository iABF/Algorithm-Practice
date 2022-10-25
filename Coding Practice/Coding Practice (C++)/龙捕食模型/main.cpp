#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<fstream>
#include<algorithm>
using namespace std;
#define Pai 3.1415926535897
#define MAXN 10010
int mp[MAXN][MAXN];
const int num = 10000;//city number

typedef struct node {
	int x;
	int y;
}city;
city citys[MAXN];//citys
double dic[MAXN][MAXN];//distance from two citys;
bool vis[MAXN][MAXN];
bool visit[num];//visited
int N;//real citys
int R;//radius
int seq[MAXN];//
double answer;
bool init(int n,double rou) 
{
	srand(time(nullptr));
	R = ceil(sqrt((double)n / Pai / rou));
	if (R < 3)return false;
	citys[0].x = citys[0].y = R;
	memset(vis, false, sizeof(vis));
	vis[R][R] = true;
	int k = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		double t = (double)rand() / (double)32768;
		double uu = sqrt(t)*R;
		double theta = (double)((double)rand()/(double)32768) * (2 * Pai);
		int uuu = uu * cos(theta) + R;
		int vvv = uu * sin(theta) + R;
		if (vis[uuu][vvv])
		{
			continue;
		}
		else citys[i].x = uuu, citys[i].y = vvv, vis[uuu][vvv] = true, k = 0;
	}
	N = n + 1;
	return true;
	
}
void set_dic() {//set distance
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dic[i][j] = sqrt(pow(citys[i].x - citys[j].x, 2) + pow(citys[i].y - citys[j].y, 2));
		}
	}
}
double dic_two_point(city a, city b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double count_energy(int* conf) {
	double temp = 0;
	for (int i = 1; i < N; ++i) {
		temp += dic_two_point(citys[conf[i]], citys[conf[i - 1]]);
	}
	temp += dic_two_point(citys[conf[0]], citys[conf[N - 1]]);
	return temp;
}
void moni() {
	memset(visit, false, sizeof(visit));
	int temp = 0;
	seq[0] = temp;
	visit[temp] = true;
	int mini = -1;
	int ans = 1e9;
	for (int i = 1; i < N; ++i) {//第i位应该经过的点
		ans = 1e9;
		mini = -1;
		for (int j = 0; j < N; ++j) {
			if (!visit[j] && ans > dic[seq[i - 1]][j]) {
				ans = dic[seq[i - 1]][j];
				mini = j;
			}
		}
		seq[i] = mini;
		visit[mini] = true;
	}
	answer = count_energy(seq);
}

int main() {
	srand(time(nullptr));
	//init(567, 0.1);
	int t;
	double fans;
	int cnt;
	ofstream OOt("out.txt");
	//for (int i = 0; i < 567; i++)OOt << citys[i].x << ' ' << citys[i].y << endl;
	for (int i = 3; i <= 1000; i++)
	{
		OOt << i << ' ';
		fans = 0;
		cnt = 0;
		for (int j=0;j<10;j++)
		{
			if(init(i, 0.0001))
			{
				set_dic();
				moni();
				fans += answer;
				cnt++;
			}
		}
		if(cnt>0)OOt << (int)(fans /cnt) << endl;
		else  OOt << endl;
		cout << i << endl;
	}
	return 0;
}
