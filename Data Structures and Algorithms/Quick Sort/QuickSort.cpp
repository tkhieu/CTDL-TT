#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m, int &n);
void SimpleSort(int a[], int n);
void Partition(int a[], int low, int up, int p);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	Partition(a,0,n-1,n/2);
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

void Partition(int a[], int low, int up, int p)
{
	int Pivot, l, u;
	Pivot = a[p]; l = low; u = up;

	while(l < u)
	{
		while(a[l] <= Pivot && l < up)
			l++;
		while(a[u] > Pivot)
			u--;
		if (l < u)
		{
			Swap(a[l],a[u]);
		}
	}
	a[low] = a[u];
	a[u] = Pivot;
	p = u;
}