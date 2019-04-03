#pragma once
class Niz
{
	int* A;
	int n;
public:
	Niz();
	Niz(int n);
	~Niz();
	void Booublesort();
	void mergesort(int*niz,int dim);
	void mergesort(int*niz, int start, int end);
	void merge(int*niz, int start, int end);
	void print();
	void SelectonSort();
	void InsertSort();
	void QuickSort(int* A, int start, int end);
	int Partition(int* A, int start, int end);
	int* vratiniz(){ return this->A; }
	int vratibr(){ return this->n; }
};