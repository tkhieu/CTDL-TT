#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m, int &n);
void SimpleSort(int a[], int n);
void BinaryInsertionSort(int a[], int n);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	//SimpleSort(a,n);
	BinaryInsertionSort(a,n);
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

void SimpleSort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i] > a[j])
				Swap(a[i],a[j]);
}

void Swap(int &m, int &n)
{
	int temp = m;
	m = n;
	n=temp;
}

void BinaryInsertionSort(int a[], int n)
{
	int left, right, middle, i,x;
	for (i=0;i<n;i++)
	{
		x= a[i];
		left = 0;
		right = i-1;
		while(left <= right)
		{
			middle = (left+right)/2;
			if (x<a[middle])
			{
				right = middle-1;
			} 
			else
			{
				left = middle+1;
			}
		}
		for (int j=i-1;j>=left;j--)
		{
			a[j+1]=a[j];
		}
		a[left] = x;
	}
}