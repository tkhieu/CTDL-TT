#include <stdio.h>
#include <conio.h>


void HoanViThamTri(int a, int b)
{
	int t = a; a = b; b = t;
}

void HoanViThamBien(int *a, int *b)
{
	int t = *a; *a = *b; *b = t;
}

void HoanViThamChieu(int &a, int &b)
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
	printf("\n*pa= %d",*pa);
	// Lấy địa chỉ ô nhớ từ biến con trỏ
	printf("\n%p",pa);
	printf("\n%p",&pa);
	printf("\n%p",&a);

	// Truyền biến sử dụng tham trị
	printf("\nHoan vi Truyen Tham Tri");
	HoanViThamTri(a,b);
	printf("\na:%d b:%d",a,b);

	// Truyền biến sử dụng tham số
	printf("\nHoan vi Truyen Tham Bien su dung dia chi o nho");
	HoanViThamBien(&a,&b);
	printf("\na:%d b:%d",a,b);

	// Truyền biến sử dụng tham Chiếu
	printf("\nHoan vi Truyen Tham Bien su dung tham chieu");
	HoanViThamChieu(a,b);
	printf("\na:%d b:%d",a,b);




	getch();
}