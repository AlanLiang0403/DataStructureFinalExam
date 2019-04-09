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
	heap = new T[capacity + 1]; // heap [0] ¤£¨Ï¥Î
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
{ // ¥[¤J¤¸¯À e ¨ì³Ì¤j°ï¿n¤¤¡C
	if (heapSize == capacity) { 
		cout << "Capacity is exceeded.";
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e)
	{ // ®ðªw¤W¤Éªk 
		heap[currentNode] = heap[currentNode / 2]; // ±N¤÷¸`ÂI©¹¤U²¾
		currentNode /= 2;
	}
	heap[currentNode] = e;
}


template <class T>
void MaxHeap<T>::Pop()
{ // ²¾°£³Ì¤j¤¸¯À
	if (IsEmpty()) cout << "Can't be deleted.";
	//heap[1].ƒ{T(); // ²¾°£³Ì¤j¤¸¯À

	// ±q°ï¿n¤¤²¾°£³Ì«á¤@­Ó¤¸¯À
	T lastE = heap[heapSize--];

	// º¯³zªk
	int currentNode = 1; // ¾ð®Ú
	int child = 2;      // currentNodeªº¤@­Ó¨à¤l¸`ÂI
	while (child <= heapSize)
	{
		// ³]©wchild¬°currentNodeªº¨à¤l¤¤¤ñ¸û¤jªº¤@­Ó
		if (child < heapSize && heap[child] < heap[child + 1]) child++;

		// ¥i¥H±NlastE©ñ¤JcurrentNode¸Ì¶Ü¡H
		if (lastE >= heap[child]) break; // ¥i¥H

		// ¤£¥i¥H
		heap[currentNode] = heap[child];  // ¤l¸`ÂI¤W²¾
		currentNode = child; child *= 2;   // ¤U²¾¤@¼h
	}
	heap[currentNode] = lastE;
}

template <class T>
void MaxHeap<T>::Big()
{ // ¥[¤J¤¸¯À e ¨ì³Ì¤j°ï¿n¤¤¡C
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
