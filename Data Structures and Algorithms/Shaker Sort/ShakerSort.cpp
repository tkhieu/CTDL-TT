#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m,int &n);
void ShakerSort(int a[], int n);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	ShakerSort(a,n);
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

void ShakerSort(int a[], int n)
{
	int i,k,left,right;
	k=0;
	left = 0;
	right = n-1;
	while(left < right)
	{
		for (i=right;i>left;i--)
		{
			if (a[i]<a[i-1])
			{
				Swap(a[i],a[i-1]);
				k=i;
			}
		}
		left = k;
		for (i = left;i<right;i++)
		{
			if (a[i]>a[i+1])
			{
				Swap(a[i],a[i+1]);
				k=i;
			}
		}
		right = k;
	}
}


void Swap(int &m,int &n)
{
	int temp = m;
	m = n;
	n=temp;
}