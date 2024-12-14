#include<bits/stdc++.h>
using namespace std;
int heap[100005]; // 定义一个数组来存储堆
int heap_size = 0; // 定义堆的大小
void put(int d){
    int son,pa;
    heap[++heap_size] = d; // 将元素d放入堆中
    son = heap_size;
    while(son > 1){
        pa=son >> 1; // 计算父节点的位置
        if(heap[son] >= heap[pa]) break; // 如果当前节点大于等于父节点，则退出循环
        swap(heap[son],heap[pa]); // 交换当前节点和父节点的位置
        son = pa;
    }
}
int get(){
    int pa,son,res;
    res = heap[1]; // 取出堆顶元素
    heap[1] = heap[heap_size--]; // 将堆尾元素放到堆顶
    pa = 1;
    while(pa * 2 <= heap_size){
        son = pa * 2;
        if(son < heap_size && heap[son+1] > heap[son]) son++; // 如果右子节点大于左子节点，则选择右子节点
        if(heap[pa] <= heap[son]) break; // 如果当前节点小于等于子节点，则退出循环
        swap(heap[pa],heap[son]); // 交换当前节点和子节点的位置
        pa = son;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        put(d);
    }
    for(int i = 1; i <= n; i++) {
        cout << get() << " ";
    }
    return 0;
}