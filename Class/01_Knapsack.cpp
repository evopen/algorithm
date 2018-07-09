#include <iostream>

using namespace std;

int c = 30;              //背包容量
int n = 3;               //对象数目
int w[] = {0, 20, 15, 30};  //对象重量数组
int v[] = {0, 40, 25, 25};  //对象收益数组
int cw = 0;              //当前背包重量
int cp = 0;              //当前背包中物品价值
int bestp = 0;           //当前最优价值
int perp[100];           //单位物品价值排序后

//按单位价值排序
void knapsack() {
    int i, j;
    int temp = 0;

    for (i = 1; i <= n; i++) perp[i] = v[i] / w[i];
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++)
            if (perp[i] < perp[j])  //冒泡排序
            {
                temp = perp[i];
                perp[i] = perp[i];
                perp[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }

    }
}


/**
 * 计算上界函数
 *
 * @return 子树上界
 * */
double bound(int i) {
    double cleft = c - cw;  //剩余容量
    double b = cp;          //目前最佳价值
    while (i <= n && w[i] <= cleft) {
        cleft -= w[i];
        b += v[i];
        i++;
    }
    if (i <= n) b += (double)v[i] / w[i] * cleft;
    return b;
}

//回溯函数
void backtrack(int i) {
    if (i > n) {
        bestp = cp;
        return;
    }
    if (cw + w[i] <= c) {
        cw += w[i];
        cp += v[i];
        backtrack(i + 1);
        cw -= w[i];
        cp -= v[i];
    }
    if (bound(i + 1) > bestp)  //符合条件搜索右子数
        backtrack(i + 1);
}

int main() {
    knapsack();
    backtrack(1);
    printf("最优价值为：%i\n", bestp);
    return 0;
}
