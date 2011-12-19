#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

struct Data {
	string Info;
	int Number;
};
typedef struct Data DATA;

struct Node {
	struct Node *pNext;
	DATA Data;
};
typedef struct Node NODE;

struct LinkList {
	NODE *pHead;
	Node *pTail;
};
typedef struct LinkList LIST;

void main(){

}


// CÁC TÁC VỤ
// 01. GetNode: Khởi tạo Node
NODE *GetNode(DATA d){
	NODE *p;
	p = new NODE;
	if (p == NULL)
	{
		printf("\nKhong du bo nho");
		exit(1);
	} else
	{
		p->Data = d;
		p->pNext = NULL;
	}
	return p;
}

// 02. Insert: Chèn một dữ liệu vào DSLK
// 02.1: AddFirst: Chèn vào đầu danh sách
void AddFirst(LIST &l, NODE *node)
{
	if (l.pHead == NULL)
	{
		l.pTail = node;
		l.pHead = node;
	} else {
		node->pNext = l.pHead;
		l.pHead = node;
	}
}

NODE *InsertHead(LIST &l, Data d){
	NODE *node = GetNode(d);
	if (node == NULL)
	{
		return NULL;
	}
	if (l.pHead == NULL)
	{
		l.pTail = node;
		l.pHead = node;
	} else {
		node->pNext = l.pHead;
		l.pHead = node;
	}
	return node;
}
