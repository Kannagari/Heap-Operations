#include "myheap.h"
#include <iostream>
#include <iomanip>

using namespace std;



myHeap::myHeap(int n)
{
	maxSize=n;
	data=new double[n];
	last=-1;
}

bool myHeap::top(double& x)
{
	if (last<0)//If the heap is empty
		return false;
	x = data[0];
	return true;
}


void myHeap::emptyHeap()
{
	last=-1;
}

void myHeap::printHeap()
{
	printHelper(0,0);
}


void myHeap::printHelper(int root, int level)
{
	int lchild;
	if (root<=last)
	{
		lchild=2*root+1;
		printHelper(lchild+1, level+1);
		for (int i=0; i<level; i++)
			cout<<"    ";
		cout<<setw(4)<<data[root]<<endl;
		printHelper(lchild, level+1);
	}
}

bool myHeap::insert(double x)
{

	if (last>=(maxSize-1))//If the heap is full, return false
		return false;
	data[last+1]=x;//Put the new data at the bottom of the heap
	last++;
	reHeapUp(last);
	return true;



}

bool myHeap::remove()
{
	if (last<=0)
		return false;
	data[0]=data[last];
	last--;
	reHeapDown(0);
	return true;




}

bool myHeap:: buildHeap(double* A, int n)
{
	for(int i = n/2; i>= 0; i--)
	{
		int largest;
		int left = 2*i +1; //Calculating left childs position compared to its parent
		int right = 2*i +2; //Calculating right childs position compared to its parent
		if (left <= n && A[left] > A[i])
			 largest = left;
		else
			largest =i;
		if (right <=n && A[right] > A[largest])
			largest = right;
		if(largest !=i)
		{
			double temp = A[i];
			A[i] = A[largest];
			A[largest] = temp;

			buildHeap(A, largest);
		}
		
	}


	return true;

}

void heapSort(double A[], int n)
{
	double temp;
	int first;

	for (int i = n - 1; i > 0; i--) 
	{
		first = 0;
		for (int j = 1; j <= i; j++) 
		{
			if (A[j] < A[first])
				first = j;
		}
		temp = A[first];
		A[first] = A[i];
		A[i] = temp;
	}
	return;
}

void myHeap::reHeapUp(int x)
{

	if (x>0)
	{

		int parent = ((x-1)/2);
		if (data[x]>data[parent])
		{
			double temp =data[x];
			data[x]=data[parent];
			data[parent] = temp;

		}

		reHeapUp(parent);

	}

}




void myHeap::reHeapDown(int x)
{

	int LeftChildIndex = ((2*x)+1);
	int RightChildIndex = ((2*x)+2);
	int minIndex;

	if(RightChildIndex>last)
		if(LeftChildIndex>last)
			return;
		else
			minIndex = LeftChildIndex;
	else
	{ 
		if(data[LeftChildIndex] <= data[RightChildIndex])
			minIndex = LeftChildIndex;
		else
			minIndex =RightChildIndex;

	}
	
	if (data[x] > data[minIndex])
	{
		double temp = data[minIndex];
		data[minIndex] = data[x];
		data[x] = temp;
		reHeapDown(minIndex);

	}
		

}

///////////////////////////////////////////////////////////////////////
