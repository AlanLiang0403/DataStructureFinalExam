#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

template <class T>
class MaxHeap {
public:
	MaxHeap(int);
	void Push(const T&e);
	void Pop();
	void print();
	int IsEmpty();
	void Big();
private:
	int capacity, heapSize;
	T *heap;
};

template <class T>
int MaxHeap<T>::IsEmpty() {
	if (heapSize == 0) return(1);
	else return(0);
}

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity)
{
	capacity = theCapacity;
	heapSize = 0;
	heap = new T[capacity + 1]; // heap [0] 不使用
}

template <class T>
void MaxHeap<T>::print() {
	int i;
	cout << endl;
	for (i = 1; i <= heapSize; i++) cout << heap[i] << " ";
	cout << endl;
}


template <class T>
void MaxHeap<T>::Push(const T& e)
{ // 加入元素 e 到最大堆積中。
	if (heapSize == capacity) { 
		cout << "Capacity is exceeded.";
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e)
	{ // 氣泡上升法 
		heap[currentNode] = heap[currentNode / 2]; // 將父節點往下移
		currentNode /= 2;
	}
	heap[currentNode] = e;
}


template <class T>
void MaxHeap<T>::Pop()
{ // 移除最大元素
	if (IsEmpty()) cout << "Can't be deleted.";
	//heap[1].�{T(); // 移除最大元素

	// 從堆積中移除最後一個元素
	T lastE = heap[heapSize--];

	// 滲透法
	int currentNode = 1; // 樹根
	int child = 2;      // currentNode的一個兒子節點
	while (child <= heapSize)
	{
		// 設定child為currentNode的兒子中比較大的一個
		if (child < heapSize && heap[child] < heap[child + 1]) child++;

		// 可以將lastE放入currentNode裡嗎？
		if (lastE >= heap[child]) break; // 可以

		// 不可以
		heap[currentNode] = heap[child];  // 子節點上移
		currentNode = child; child *= 2;   // 下移一層
	}
	heap[currentNode] = lastE;
}

template <class T>
void MaxHeap<T>::Big()
{ // 加入元素 e 到最大堆積中。
	for(int i=1 ; i < heapSize+1 ; i++)
	{
		for(int j=1 ; j < heapSize+1 ; j++)
	{
		if(heap[i]<heap[j])
		{
			int a;
			a=heap[i];
			heap[i]=heap[j];
			heap[j]=a;
		}
	}
	}

}

int main() {
	MaxHeap<int> hp(100);
	
	hp.Push(15);
	hp.Push(11);
	hp.Push(4);
	hp.Push(8);
	hp.Push(2);
	hp.Push(9);
	hp.Push(12);
	hp.Push(1);
	hp.Push(0);
	hp.Push(3);
	hp.Push(6);
	hp.print();
	hp.Big();
	hp.print();
	getchar();


}
