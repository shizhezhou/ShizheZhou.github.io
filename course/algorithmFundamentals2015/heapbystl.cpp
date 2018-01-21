#include <iostream>
#include <iterator>
#include <queue>

/*demo the usage of stl implementation of heap structure for students.*/

using namespace std;

void heap_sort(){
	int array[10];
	for (int i=0; i<10; i++)
	{
		array[i] = rand();
	}
	cerr<<"input :\n";
	copy(&array[0], &array[10], ostream_iterator<int>(cout,", ")); cerr<<"\n";

	std::priority_queue<int> Q;
	for (int i=0; i<10; i++)
	{
		Q.push(array[i]);
	}

	int sorted_array[10];
	for (int i=0; i<10; i++)
	{
		sorted_array[i] = Q.top();	
		Q.pop();
	}
	cerr<<"sorting result : \n";
	copy(&sorted_array[0], &sorted_array[10],ostream_iterator<int>(cout,", ")); cerr<<"\n";
}

void use_makeheap(){
	int array[10];
	for (int i=0; i<10; i++)
	{
		array[i] = rand();
	}
	cerr<<"input :\n";
	copy(&array[0], &array[10], ostream_iterator<int>(cout,", ")); cerr<<"\n";

	make_heap(array,array+10,std::less<int>());
	cerr<<"heap: \n";
	copy(array,array+10, ostream_iterator<int>(cout," "));
}

int _tmain(int argc, _TCHAR* argv[])
{ 
	heap_sort();
	use_makeheap();
	return 0;
}


