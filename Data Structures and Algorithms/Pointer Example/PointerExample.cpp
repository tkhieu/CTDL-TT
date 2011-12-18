#include <stdio.h>
#include <conio.h>


void HoanVi(int a, int b)
{
	int t = a; a = b; b = t;
}

void main()
{
	int a = 10, b = 20;
	int *pa, *pb;

	pa = &a;
	pb = &b;

	printf("a = %d \nb = %d",a,b);

	// Lấy giá trị từ biến con trỏ
	printf("\n%d",*pa);
	// Lấy địa chỉ ô nhớ từ biến con trỏ
	printf("\n%p",pa);
	printf("\n%p",&pa);
	printf("\n%p",&a);

	printf("\nHoan vi Truyen Tham Tri");
	HoanVi(a,b);
	printf("\na:%d b:%d",a,b);

	getch();
}