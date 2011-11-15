#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m,int &n);
void BubbleSort(int a[], int n);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	BubbleSort(a,n);
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

void BubbleSort(int a[], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=n-1;j>i;j--)
		{
			if (a[j]<a[j-1])
			{
				Swap(a[j],a[j-1]);
			}
		}
	}
}


void Swap(int &m,int &n)
{
	int temp = m;
	m = n;
	n=temp;
}