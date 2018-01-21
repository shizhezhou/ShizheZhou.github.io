//simple heap class for students, if you detect bugs, please email to szhou@ustc.edu.cn

#include "stdafx.h"

#define MAXHEAP /*this is a max-at-top heap class*/

template<class T>  
class Heap{
public: 
	Heap(){ m_h= new T[_MaxN]; m_n=0;}
	Heap(T *array, int n){
		if(array&&n){
			m_h=NULL; m_n=0;
			buildHeap(array,n);
			m_h = array;
			m_n= n;
		}
	}
	~Heap(){ if(m_h) delete[] m_h; }
protected:
	int m_n;	
	T  *m_h;
	static int _MaxN;


private:
void swap(T &a, T &b){
	T c = a;
	a = b;
	b = c;
}

void buildHeap(int *H, int n){  //make in-place heap
	int N = 0;
	for (int i=0; i<n; i++)
	{
		int a = H[i];
		N++;
		int parent = (N-1)/2;
		int child = N-1;
		while(parent>=0){
			if( H[child]>H[parent] ){
				swap(H[child], H[parent]);
				child = parent;
				parent = (parent-1)/2;
			}
			else
				break;
		}
	}
}

public:
	void push(T a){
		insert(a);
	}
	void insert(T a){
		if(m_n>=_MaxN){
			_MaxN*=2;
			T *newH = new T[_MaxN];
			for (int i=0; i<m_n; i++)
				newH[i] = m_h[i];
			delete[] m_h;
			m_h = newH;	
		}
		m_h[m_n] = a;
		m_n++;
		int parent = m_n/2-1;
		int child = m_n-1;
		while(parent>=0){
			if( m_h[child]>m_h[parent] ){
				swap(m_h[child], m_h[parent]);
				child = parent;
				parent = (parent-1)/2;
			}
			else
				break;
		}
	}

	T pop(){
		if(m_n>0){
			T top = m_h[0];
			m_h[0] = m_h[m_n-1];
			m_n--;
			int parent = 0;
			int child = parent*2+1;  //c style
	
			while( child <=m_n-1 ){
				if(m_h[child+1]>m_h[child])
					child = child + 1; 
				if(m_h[child] > m_h[parent]){
					swap(m_h[child], m_h[parent]);
					parent = child;
					child = child*2+1;  //c style
				}
				else
					break;
			}
			return top;
		}
		else{
			return T();
		}
	}

	T top(){ return m_h[0]; }

	void print(){
		for (int i=0; i<m_n; i++)	printf("%d ", m_h[i]);
	}
	int size(){
		return m_n;
	}
	bool empty(){
		return m_n<=0;
	}
};
template<class T> int Heap<T>::_MaxN=8;