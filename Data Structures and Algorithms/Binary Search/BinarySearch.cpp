#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m, int &n);
void SimpleSort(int a[], int n);
int BinarySearch(int a[], int n, int x);

void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	SimpleSort(a,n);
	PrintArray(a,n);
	int x;
	printf("\nNhap x: ");
	scanf("%d",&x);
	int j = BinarySearch(a,n,x);
	printf("Vi tri tim thay: %d",j);
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


int BinarySearch(int a[], int n, int x)
{
	int left = 0;
	int right = n-1;
	int middle;
	while(left <= right)
	{
		middle = (left+right)/2;
		if(a[middle] == x)
			return middle;
		else if(a[middle] > x)
			right = middle -1;
		else if(a[middle] < x)
			left = middle+1;
	}
	return -1;
}