#include <iostream>

using namespace std;

int length(int i);

void Compress(int n, int p[], int s[], int l[], int b[]);

void Traceback(int n, int &i, int s[], int l[]);

void Output(int s[], int l[], int b[], int n);

int main() {
    int n = 7;
    int p[] = {0, 0b1010, 0b1100, 0b1111, 0b11111111, 0b11, 0b01};//图像灰度数组{p1,p2,p3,p4,p5,p6} 下标从1开始计数
    int s[n], l[n], b[n];

    cout << "图像的灰度序列为：" << endl;

    for (int i = 1; i < n; i++)
        cout << p[i] << " ";
    cout << endl;

    Compress(n - 1, p, s, l, b);
    Output(s, l, b, n - 1);
    return 0;
}

//n个像素，存在数组p[]中，s 为分段比特数，l 为分段像素数，b 为需要几位表示像素
void Compress(int n, int p[], int s[], int l[], int b[]) {
//    分段最长为256
    int Lmax = 256;

//    头部长度为11位：8位表示像素数，3位表示需要几位表示像素
    int header = 11;
    s[0] = 0;

    for (int i = 1; i <= n; i++) {
        b[i] = length(p[i]); //计算像素点p需要的存储位数
        int bmax = b[i];
        s[i] = s[i - 1] + bmax;
        l[i] = 1;

        for (int j = 2; j <= i && j <= Lmax; j++) //i=1时，不进入此循环
        {
            if (bmax < b[i - j + 1]) {
                bmax = b[i - j + 1];
            }

            if (s[i] > s[i - j] + j * bmax) {
                s[i] = s[i - j] + j * bmax;
                l[i] = j;
            }
        }
        s[i] += header;
    }
}

int length(int i)//存储像素pi所需的位数
{
    int k = 1;
    i /= 2;
    while (i > 0) {
        k++;
        i /= 2;
    }
    return k;
}

void Traceback(int n, int &i, int s[], int l[]) {
    if (n == 0)
        return;
    Traceback(n - l[n], i, s, l);//p1,p2,p3,...,p(n-l[n])像素序列，最后一段有l[n]个像素
    s[i++] = n - l[n];//重新为s[]数组赋值，用来存储分段位置，最终i为共分了多少段
}

void Output(int s[], int l[], int b[], int n) {
    //在输出s[n]存储位数后，s[]数组则被重新赋值，用来存储分段的位置
    cout << "图像压缩后的最小空间为：" << s[n] << endl;
    int m = 0;
    Traceback(n, m, s, l);//s[0]:第一段从哪分，s[1]:第二段从哪分...，s[m-1]第m段从哪分
    s[m] = n;//此时m为总段数，设s[m]=n，分割位置为第n个像素
    cout << "将原灰度序列分成" << m << "段序列段" << endl;
    for (int i = 1; i <= m; i++) {
        l[i] = l[s[i]];
        b[i] = b[s[i]];
    }
    for (int j = 1; j <= m; j++) {
        cout << "段长度：" << l[j] << ",所需存储位数:" << b[j] << endl; // 此处b[j]似乎有误， 待查证
        // TODO: Check this out with my teacher
    }
}
