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
	heap = new T[capacity + 1]; // heap [0] ���ϥ�
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
{ // �[�J���� e ��̤j��n���C
	if (heapSize == capacity) { 
		cout << "Capacity is exceeded.";
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e)
	{ // ��w�W�ɪk 
		heap[currentNode] = heap[currentNode / 2]; // �N���`�I���U��
		currentNode /= 2;
	}
	heap[currentNode] = e;
}


template <class T>
void MaxHeap<T>::Pop()
{ // �����̤j����
	if (IsEmpty()) cout << "Can't be deleted.";
	//heap[1].�{T(); // �����̤j����

	// �q��n�������̫�@�Ӥ���
	T lastE = heap[heapSize--];

	// ���z�k
	int currentNode = 1; // ���
	int child = 2;      // currentNode���@�Ө�l�`�I
	while (child <= heapSize)
	{
		// �]�wchild��currentNode����l������j���@��
		if (child < heapSize && heap[child] < heap[child + 1]) child++;

		// �i�H�NlastE��JcurrentNode�̶ܡH
		if (lastE >= heap[child]) break; // �i�H

		// ���i�H
		heap[currentNode] = heap[child];  // �l�`�I�W��
		currentNode = child; child *= 2;   // �U���@�h
	}
	heap[currentNode] = lastE;
}

template <class T>
void MaxHeap<T>::Big()
{ // �[�J���� e ��̤j��n���C
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
