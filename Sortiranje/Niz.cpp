#include"Niz.h"
#include<iostream>
using namespace std;

int*temp;

Niz::Niz()
{
	this->n = 10;
	this->A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Unesite broj: = ";
		cin >> A[i];
	}
}
Niz::Niz(int n)
{
	this->n = n;
	this->A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Unesite broj: = ";
		cin >> A[i];
	}
}
Niz::~Niz()
{
	delete[]A;
}

void Niz::print()
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

	
}
void Niz::Booublesort()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (A[i]>A[j])
			{
				int pon = A[i];
				A[i] = A[j];
				A[j]=pon;
			}
		}
}
void Niz::SelectonSort()
{
	int max;
	int pom;
	for (int i = 0; i < n- 1; i++)
	{
		max = i;
		for (int j = i+ 1; j < n; j++)
		{
			if (A[j]>A[max])
				max = j;
		}

		pom = A[i];
		A[i] = A[max];
		A[max] = pom;
	}
	
}
void Niz::InsertSort()
{
	int pom;
	for (int i = 1; i < n; i++)
	{
		pom = A[i];
		for (int j = i; j>0 && pom < A[j - 1]; j--)
		{
			A[j] = A[j - 1];
			A[j-1] = pom;
		}
	}
}
void Niz::QuickSort(int *A, int start, int end)
{
	if (start < end)
	{
		int Pindex = this->Partition(A, start, end);
		this->QuickSort(A, start, Pindex - 1);
		this->QuickSort(A, Pindex + 1, end);
	}
}
int Niz::Partition(int*A, int start, int end)
{
	int pivot = A[end];
	int Pind = start;
	for (int i = start; i < end; i++)
	{
		if (A[i] < pivot)
		{
			int pom = A[i];
			A[i] = A[Pind];
			A[Pind] = pom;
			Pind++;
		}
	}
	int pom = A[end];
	A[end] = A[Pind];
	A[Pind] = pom;
	return Pind;
}

void Niz::mergesort(int*niz, int dim)
{
	temp = new int[dim];
	mergesort(niz, 0, dim - 1);
	delete[] temp;
}
void Niz::mergesort(int*niz, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(niz, start, mid);
		mergesort(niz, mid + 1, end);
		merge(niz, start, end);
	}
}

void Niz::merge(int*niz, int start, int end)
{
	int mid, i, j, k;
	mid = (start + end) / 2;
	i = 0;
	j = mid + 1;
	k = 0;
	while (i <= mid&&j <= end)
	{
		if (niz[i] <= niz[j])
			temp[k++] = niz[i++];
		else
			temp[k++] = niz[j++];
	}
	while (i <= mid)
		temp[k++] = niz[i++];

	while (j <= end)
		temp[k++] = niz[j++];
	j = 0;
	i = start;
	while (i <= end)
		niz[i++] = temp[j++];
}