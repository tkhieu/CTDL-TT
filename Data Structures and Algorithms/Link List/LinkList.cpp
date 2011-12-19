#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

// Định nghĩa kiểu dữ liệu chứa thông tin
typedef struct Data{
	string Name;
	int	Number;
} DATA;

// Định nghĩa kiểu dữ liệu của một Node
typedef struct Node {
	DATA Data;
	struct Node *pNext;
} *NODE;

// Định nghĩa kiểu dữ liệu của một LinkList
typedef struct LinkList {
	NODE *pHead;
	NODE *pTail;
} LIST;



void main()
{
	
}

///////////////////////////////////////////////////////////////////////////////////////////
// CÁC TÁC VỤ TRÊN LINK-LIST
//
// 01. GetNode: Cấp phát một biến động làm nút cho DSLK
NODE GetNode()
{
	NODE p;
	p = (NODE)malloc(sizeof(struct Node));
	return(p);
}

// 02. FreeNode: Giải phóng vùng nhớ đã cấp trước đó
// 03. Initilaze: Khởi động danh sách liên kết
// 04. IsEmpty: Kiểm tra danh sách có bị rỗng không
// 05. NodePointer: Xác định con trỏ của nút thứ i trong danh sách
// 06. Position: Xác định vị trí thứ i của con trỏ trong danh sách
// 07. PreNode: Xác định nút trước nút P trong DSLK
// 08. Push: Thêm nút có nội dung X vào đầu DSLK
// 09. InsAfter: Thêm một nút có nội dung X ngay sau nút P
// 10. Pop: Xóa một nút ở đầu DSLK: Trả về nội dung nút vừa bị xóa
// 11. DelAfter: Xóa một nút ngay sau nút P, trả về nội dung nút vừa được xóa.
// 12. Place: Thêm một nút có nội dung X vào trong DSLK có thứ tự
// 13. Traverse: Duyệt DSLK
// 14. Search: Tìm kiếm nút có nội dung X trong DSLK
// 15. Sort: Tác vụ sắp xếp sử dụng Selection Sort
// 16. ClearList: Xóa danh sách liên kết bằng cách giải phóng mọi nút.
///////////////////////////////////////////////////////////////////////////////////////////



// 01. GetNode: Cấp phát một biến động làm nút cho DSLK
// 02. FreeNode: Giải phóng vùng nhớ đã cấp trước đó
// 03. Initilaze: Khởi động danh sách liên kết
// 04. IsEmpty: Kiểm tra danh sách có bị rỗng không
// 05. NodePointer: Xác định con trỏ của nút thứ i trong danh sách
// 06. Position: Xác định vị trí thứ i của con trỏ trong danh sách
// 07. PreNode: Xác định nút trước nút P trong DSLK
// 08. Push: Thêm nút có nội dung X vào đầu DSLK
// 09. InsAfter: Thêm một nút có nội dung X ngay sau nút P
// 10. Pop: Xóa một nút ở đầu DSLK: Trả về nội dung nút vừa bị xóa
// 11. DelAfter: Xóa một nút ngay sau nút P, trả về nội dung nút vừa được xóa.
// 12. Place: Thêm một nút có nội dung X vào trong DSLK có thứ tự
// 13. Traverse: Duyệt DSLK
// 14. Search: Tìm kiếm nút có nội dung X trong DSLK
// 15. Sort: Tác vụ sắp xếp sử dụng Selection Sort
// 16. ClearList: Xóa danh sách liên kết bằng cách giải phóng mọi nút.