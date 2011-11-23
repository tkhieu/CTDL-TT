#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m, int &n);

void Shift(int a[], int l, int r);
void CreateHeap(int a[], int n);
void HeapSort(int a[], int n);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	HeapSort(a,n);
	PrintArray(a,n);
	getch();
}

void RandomArray(int a[], int &n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i] = rand() % 99;
	}
}

void PrintArray(int a[], int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%3d ",a[i]);
	}
}


void Swap(int &m, int &n)
{
	int temp = m;
	m = n;
	n=temp;
}

void Shift(int a[], int l, int r)
{
	
}

void CreateHeap(int a[], int n)
{
	int l;
	l = n/2;
	while(l > 0)
	{
		Shift(a,l,n);
		PrintArray(a,n);
		l--;
	}
}

void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a,n);
	r = n-1;
	while(r > 0)
	{
		Swap(a[0],a[r]);
		r--;
		Shift(a,0,r);
	}
}