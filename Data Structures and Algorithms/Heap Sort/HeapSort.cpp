#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int heapSize = 0;


void RandomArray(int a[], int &n, int &heapSize)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	heapSize = n;
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

int parent(int i) {
	if(i==1)
		return 0;

	if(i%2==0)
		return ( (i / 2)-1);
	else
		return ( (i / 2));
}

int left(int i) {
	return (2 * i) + 1;
}

int right(int i) {
	return (2 * i) + 2;
}

void heapify(int a[], int i) {
	int l = left(i), great;
	int r = right(i);
	if ( (a[l] > a[i]) && (l < heapSize)) {
		great = l;
	}
	else {
		great = i;
	}
	if ( (a[r] > a[great]) && (r < heapSize)) {
		great = r;
	}
	if (great != i) {
		int temp = a[i];
		a[i] = a[great];
		a[great] = temp;
		heapify(a, great);
	}
}

void BuildMaxHeap(int a[]) {
	for (int i = (heapSize - 1) / 2; i >= 0; i--) {
		heapify(a, i);
	}
}

void HeapSort(int a[]) {
	BuildMaxHeap(a);
	for (int i = heapSize; i > 0; i--) {
		int temp = a[0];
		a[0] = a[heapSize - 1];
		a[heapSize - 1] = temp;
		heapSize = heapSize - 1;
		heapify(a, 0);
	}

}

void main() {

	int arr[100];
	int n;
	RandomArray(arr,n,heapSize);
	PrintArray(arr,n);
	HeapSort(arr);
	PrintArray(arr,n);
	getch();
}