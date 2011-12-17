#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
void Swap(int &m, int &n);
void SimpleSort(int a[], int n);
void ShellSort(int a[], int n, int h[], int k);
void GetSteps(int h[], int &k, int n);

void main()
{
	int a[100];
	int h[100];
	int n,k;
	RandomArray(a,n);
	PrintArray(a,n);

	GetSteps(h,k,n);
	ShellSort(a,n,h,k);
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

void GetSteps(int h[], int &k, int n)
{
	k = (int)(log10((double)n)/log10((double)3)+0.5);
	for (int i = k-1;i>=0;i--)
	{
		if (i+1 == k)
		{
			h[k-1] = 1;
		}
		h[i-1] = h[i]*3 + 1;
	}
}

void ShellSort(int a[], int n, int h[], int k)
{
	int step,i,j;
	int x,len;

	for (step = 0;step<k;step++)
	{
		len = h[step];
		for (i = len;i<n;i++)
		{
			x = a[i];
			j = i-len;
			while((x<a[j]) && (j>=0)){
				a[j+len] = a[j];
				j = j-len;
			}
			a[j+len] = x;
		}
	}
	h = (0);
}