#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;
// ......queue 
template <class T>
class Queue {
	public:
		Queue(int cap);
		void Add(T);
		T Del();
		bool isEmpty();
	private:
		int front, rear;
		T *array;
		int capacity;
};

template <class T>
Queue<T>::Queue(int cap) {
	//Bag<T>();
	array = new T[cap];
	capacity = cap;
	front = rear = 0;
}

template <class T>
void Queue<T>::Add(T x) {
	int tmp = rear + 1;
	tmp %= capacity;
	if(tmp == front) cout << "Queue is full";
	else array[rear = tmp] = x;
}

template <class T>
T Queue<T>::Del() {
	if(front == rear) {
		cout << "Queue is empty.";	
	}
	else {
		front = (front + 1) % capacity;
		return(array[front]);
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	if(rear == front) return(1);
	else return(0);
}

template <class T>
class Graph
{
public:
	virtual ~Graph() {}
	Graph(int n) {N = n; for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = 0;}
	void directed_add(int, int);
	void dfs(int);
	void dfs_driver(int);
	int out_degree(int nd);
	void delete_out();
private:
        T g[100][100];
		int visited[100];
        int N;
        int out=0;
};

template <class T>
void Graph<T>::directed_add(int i, int j) {
	g[i][j] = 1;
	g[j][i] = 0;
}

template <class T>
void Graph<T>::dfs_driver(int nd) {
	for(int i = 0; i < N; i++){
		visited[i] = 0;
	}
	
	cout << endl;
	dfs(nd);
	cout << endl;
}

template <class T>
void Graph<T>::dfs(int nd) {
	int i;
	visited[nd] = 1;
	cout << nd << " ";
	for(i = 0; i < N; i++) 
	{
		
		if(g[nd][i] && ! visited[i]) 
		{
			dfs(i);
		}
	}
}

template <class T>
int Graph<T>::out_degree(int nd)
{
	for(int i = 0; i < N; i++){
		visited[i] = 0;
		if(g[nd][i] && ! visited[i]) 
		{
			out++;
		}
	}
	return out;
}

template <class T>
void Graph<T>::delete_out()
{
	out=0;
}

int main() {
    Graph<int> g1(100);
	g1.directed_add(1, 4);
	g1.directed_add(1, 2);
	g1.directed_add(3, 4);
	g1.directed_add(4, 2);
	g1.directed_add(2, 1);
	g1.directed_add(1, 0);
	g1.directed_add(0, 4);
	g1.directed_add(0, 3);
	g1.dfs_driver(4);
	cout<<"0's out-degree: "<<g1.out_degree(0)<<endl;
	g1.delete_out();
	cout<<"1's out-degree: "<<g1.out_degree(1)<<endl;
	g1.delete_out();
	cout<<"2's out-degree: "<<g1.out_degree(2)<<endl;
	g1.delete_out();
	cout<<"3's out-degree: "<<g1.out_degree(3)<<endl;
	g1.delete_out();
	cout<<"4's out-degree: "<<g1.out_degree(4)<<endl;
	getchar();
}
