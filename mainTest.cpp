#include <iostream>
#include "myheap.h"

using namespace std;

int main()
{
	myHeap H1;
	double A[32];
	for (int i=0; i<32; i++)
		A[i]=rand()%101;

	cout<<"Testing buildHeap.. "<<endl;
	H1.buildHeap(A,16);
	H1.printHeap();

	system("pause");

	H1.emptyHeap();
	cout<<"Emptied the Heap.  Testing insert.. "<<endl;
	
	
	H1.printHeap();

	for (int i=0; i<20; i++)
	{
		cout<<"Insert "<<A[i]<<endl;
		H1.insert(A[i]);
		H1.printHeap();
		system("pause");
	}
	cout<<"Testing remove and top.. "<<endl;
	for (int i=0; i<5; i++)
	{
		double x;
		H1.top(x);

		H1.remove();
		cout<<"Removed "<<x<<endl;
		
		H1.printHeap();
		system("pause");
	}	


	cout<<"Testing Heap Sort"<<endl;
	double B[100];
	for (int i=0; i<100; i++)
		B[i]=rand()%1001;
	for (int i=0; i<100; i++)
		cout<<B[i]<<", ";
	cout<<endl;
	
	heapSort(B, 100);
	cout<<"Sorted array:"<<endl;
	for (int i=0; i<100; i++)
		cout<<B[i]<<", ";


	system("pause");
	return 0;
}