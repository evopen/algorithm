#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int INF = 10000000;
int low, up, n, used[20], graph[20][20];
struct node {
    bool vis[20];
    int st;    //路径的起点
    int ed;    //路径的终点
    int k;     //走过的点数
    int sumv;  //经过路径的距离
    int lb;    //目标函数的值
    bool operator<(const node &p) const { return lb > p.lb; }
};
priority_queue<node> q;

int get_up_helper(int v, int j, int len) {
    if (j == n) return len + graph[v][1];
    int minlen = INF, pos;
    for (int i = 1; i <= n; i++) {
        //采用贪心算法取权值最小的边
        if (used[i] == 0 && minlen > graph[v][i]) {
            minlen = graph[v][i];
            pos = i;
        }
    }
    used[pos] = 1;
    return get_up_helper(pos, j + 1, len + minlen);
}

//计算上界
void get_up() {
    used[1] = 1;
    up = get_up_helper(1, 1, 0);
}

//部分解的目标函数的下界
int get_lb(node p) {
    int ret = p.sumv * 2;
    int min1 = INF, min2 = INF;
    //从起点到最近未遍历城市的距离
    for (int i = 1; i <= n; i++) {
        if (p.vis[i] == 0 && min1 > graph[p.st][i]) {
            min1 = graph[p.st][i];
        }
    }
    ret += min1;
    //从终点到最近未遍历城市的距离
    for (int i = 1; i <= n; i++) {
        if (p.vis[i] == 0 && min2 > graph[p.ed][i]) {
            min2 = graph[p.ed][i];
        }
    }
    ret += min2;
    //进入并离开每个未遍历城市的最小成本
    for (int i = 1; i <= n; i++) {
        if (p.vis[i] == 0) {
            min1 = min2 = INF;
            for (int j = 1; j <= n; j++) {
                if (min1 > graph[i][j]) min1 = graph[i][j];
            }
            for (int j = 1; j <= n; j++) {
                if (min2 > graph[j][i]) min2 = graph[j][i];
            }
            ret += min1 + min2;
        }
    }
    //向上取整
    return ret % 2 == 0 ? (ret / 2) : (ret / 2 + 1);
}

//计算下界
void get_low() {
    low = 0;
    for (int i = 1; i <= n; i++) {
        int temp[20];
        for (int j = 1; j <= n; j++) {
            temp[j] = graph[i][j];
        }
        sort(temp + 1, temp + 1 + n);
        low = low + temp[1] + temp[2];
    }
    low = low / 2;
}

int solve() {
    get_up();
    get_low();
    node start;
    start.st = 1;
    start.ed = 1;
    start.k = 1;
    for (int i = 1; i <= n; i++) start.vis[i] = 0;
    start.vis[1] = 1;
    start.sumv = 0;
    start.lb = low;
    int ret = INF;
    q.push(start);
    node next, temp;
    while (!q.empty()) {
        temp = q.top();
        q.pop();
        if (temp.k == n - 1)
        //如果只剩最后一个点了
        {
            int pos = 0;
            for (int i = 1; i <= n; i++) {
                if (temp.vis[i] == 0) {
                    pos = i;
                    break;
                }
            }
            if (pos == 0) break;
            int ans = temp.sumv + graph[pos][temp.st] + graph[temp.ed][pos];
            node judge = q.top();
            //如果当前的路径和比所有的目标函数值都小则跳出并直接输出最优解
            if (ans <= judge.lb) {
                ret = min(ans, ret);
                break;
            }
            //否则继续求其他可能的路径和并更新上界
            else {
                up = min(up, ans);
                ret = min(ret, ans);
                continue;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (temp.vis[i] == 0) {
                next.st = temp.st;
                next.sumv = temp.sumv + graph[temp.ed][i];
                next.ed = i;
                next.k = temp.k + 1;
                for (int j = 1; j <= n; j++) next.vis[j] = temp.vis[j];
                next.vis[i] = 1;
                next.lb = get_lb(next);
                if (next.lb >= up) continue;
                q.push(next);
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x[20], y[20];
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = INF;
            else
                graph[i][j] = ceil(sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                                        (y[i] - y[j]) * (y[i] - y[j])));
        }
    }
    cout << solve() << endl;
}
