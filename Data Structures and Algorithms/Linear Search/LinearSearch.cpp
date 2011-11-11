#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Nguyên mẫu hàm
void RandomArray(int a[], int &n);
void PrintArray(int a[], int n);
int LinearSearch(int a[], int n, int x);

// Hàm main
void main()
{
	int a[100];
	int n;
	RandomArray(a,n);
	PrintArray(a,n);
	int x;
	printf("\nNhap x: ");
	scanf("%d",&x);
	int j = LinearSearch(a,n,x);
	printf("Vi tri tim thay: %d",j);
	getch();
}

// Khởi tạo một mãng ngẫu nhiên
void RandomArray(int a[], int &n)
{
	printf("Nhap n: ");
	scanf("%d", &n);
	// Sử dụng srand để kiến tạo seed
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i] = rand() % 99;
	}
}

void PrintArray(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d ",a[i]);
	}
}

/*
Hàm LinearSearch
Đây là thuật toán tìm kiếm đơn giản nhất
*/

int LinearSearch(int a[], int n, int x)
{
	int i = 0;
	// Điều kiện lặp
	while(i<=n-1)
	{
		if(a[i] == x)
			return i;
		i++;
	}
	return -1;
}