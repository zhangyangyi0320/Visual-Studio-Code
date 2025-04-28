/*
#include<iostream>
using namespace std;
int n , a[109];
void Divide(int l , int r)
{
    //边界条件
    if(l==r)return;

    //输出每一次的划分
    int mid=(l+r)/2;
    for(int i=l;i<=r;i++){
        cout << a[i] << " ";
        if(i==mid) cout << ", ";
    }
    cout << endl;
    //递归处理左半部分
    Divide(l , mid);

    //递归处理右半部分
    Divide(mid+1 , r);

}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    Divide(1 , n);
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int n, m;
int a[10010], b[10010], c[10010];
void Merge()
{
    // 两个序列从左端点开始，依次比较，每一次较小的数存入结果数组c
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= m)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    // 判断两个序列，是否有剩余，把剩余的数全部存入结果数组c
    while (i <= n)
    {
        c[k++] = a[i++];
    }
    // 输出结果数组c
    for (int i = 1; i <= n + m; i++)
    {
        cout << c[i] << " ";
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    // 定义 Merge 函数，完成合并
    Merge();
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int n, a[1010], temp[1010];
void MergeSort(int l, int r)
{
    // 2.1、递归的结束条件:只有一个数，就不用再递归下去，直接返回
    if (l == r)
        return;
    // 2.2、找到中间位置，递归处理左半部分，递归处理右半部分
    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    // 3、合并，两个序列分别为[l,mid] 和 [mid+1,r]，从最左边开始，依次比较，小的数放入结果数组temp，下标右移
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    // 3.1、判断两个序列是否有剩余，有剩余的，全部放入结果数组 temp
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    // 4、把结果数组 temp 重新赋给 a 数组
    for (int i = l; i <= r; i++)
        a[i] = temp[i];
    // 5、输出a数组
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    // 1、定义变量 n 和数组
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 2、划分，左端点为 1，右端点为 n，递归处理
    MergeSort(1, n);
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
int n , a[109];
void Divide(int l , int r)
{
    //边界条件
    if(l==r)return;

    //输出每一次的划分
    int mid=(l+r)/2;
    for(int i=l;i<=r;i++){
        cout << a[i] << " ";
        if(i==mid) cout << ", ";
    }
    cout << endl;
    //递归处理左半部分
    Divide(l , mid);

    //递归处理右半部分
    Divide(mid+1 , r);

}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    Divide(1 , n);
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int n, m;
int a[10010], b[10010], c[10010];
void Merge()
{
    // 两个序列从左端点开始，依次比较，每一次较小的数存入结果数组c
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= m)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    // 判断两个序列，是否有剩余，把剩余的数全部存入结果数组c
    while (i <= n)
    {
        c[k++] = a[i++];
    }
    // 输出结果数组c
    for (int i = 1; i <= n + m; i++)
    {
        cout << c[i] << " ";
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    // 定义 Merge 函数，完成合并
    Merge();
    return 0;
}
*/
#include <iostream>
using namespace std;
int n, a[1010], temp[1010];
void MergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = temp[i];
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    MergeSort(1, n);
    return 0;
}