#ifndef MYHEAP_H
#define MYHEAP_H
//create a heap of doubles
class myHeap
{
public:
	myHeap(int=1000); 
	//constructor, sets maximum size of the heap to the parameter
	bool top(double&);    
	// get the top of the heap (no removal).  return true if successful 
	void emptyHeap();  
	// empty the whole heap
	void printHeap();  
	//print the heap

	
	bool insert(double);  
	//insert an element to the heap.  return true if successful 
	// 15 points

	bool remove();        
	//remove the top of the heap.  return true if successful 
	// 15 points

	bool buildHeap(double* A, int n);   
	//given an array A of n doubles, build a heap from the values of A 
	//return true if successful 
    // 15 points

	void reHeapUp(int);  
	//starting at the position given by the parameter, perform reheap up
	// 15 points

	void reHeapDown(int); 
	//starting at the position given by the parameter, perform reheap down
	// 15 points


	
private:
	double *data;  //the heap data
	int last;   //index of last element
	int maxSize; // maximum size of the heap
	void printHelper(int, int); 

};

void heapSort(double A[], int n);   
//Implement heap sort algorithm
//25 points

#endif