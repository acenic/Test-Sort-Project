#include"Niz.h"
#include<iostream>
using namespace std;
void main()
{
	int A[] = { 1, 8, 5, 3, 2 };
	Niz niz(5);
	niz.mergesort(A, 5);
	//niz.print();
	for (int i = 0; i < 5; i++)
		cout << A[i] << " ";
}