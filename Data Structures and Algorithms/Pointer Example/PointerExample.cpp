#include <stdio.h>
#include <conio.h>


typedef struct phanso {
	int tu;
	int mau;
} PHANSO;

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

// Hàm xuất phân số
void InPhanSo(PHANSO p)
{
	printf("\nPhan so: %d/%d",p.tu,p.mau);
}

void InPhanSoP(PHANSO *p)
{
	printf("\nPhan so: %d/%d",p->tu,p->mau);
}

void InPhanSoP1(PHANSO &p)
{
	printf("\nPhan so: %d/%d",p.tu,p.mau);
}

void InPhanSoP2(PHANSO *p)
{
	printf("\nPhan so: %d/%d",(*p).tu,(*p).mau);
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

	//////////////////////////////////
	//								//
	//			CON TRỎ MÃNG		//
	//								//
	//////////////////////////////////

	int array[5] = {1,2,3,4,5};
	int *parray;
	parray = array;

	 int *p1, *p2;
	p1 = array;
	p2 = &array[3];

	// Cho khoãng cách theo số phần tử
	printf("\nByte distance:%d",(p2 - p1)*sizeof(float));
	printf("\nDistance:%d",(p2 - p1));

	// Truy xuất đến phần tử thứ k của mãng
	printf("\narray[3]: %d",array[3]);
	printf("\nparray[3]: %d",parray[3]);
	printf("\n*(p1 + 3): %d",*(p1 + 3));

	////////////////////////////////////////////////////
	//								
	//			CON TRỎ KDL CÓ CẤU TRÚC		
	//								
	////////////////////////////////////////////////////

	
	
	PHANSO ps, *Pps;

	ps.tu = 9;
	ps.mau = 10;

	Pps = &ps;

	InPhanSo(*Pps);
	InPhanSo(ps);
	InPhanSoP(Pps);
	InPhanSoP1(ps);
	InPhanSoP2(Pps);	

	getch();
}