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

// 02.02: Chèn vào cuối DSLK
void AddEnd(LIST &l, NODE *node){
	if (l.pHead == NULL)AddFirst(l,node);
	else
	{
		l.pTail->pNext = node;
		l.pTail = node;
	}
}

NODE *InsertTail(LIST &l, DATA d){
	NODE *node = GetNode(d);
	if (node == NULL) return NULL;
	if (l.pHead == NULL) InsertHead(l,d);
	else
	{
		l.pTail->pNext = node;
		l.pTail = node;
	}	
	return node;
}

// 02.03: Chèn vào giữa danh sách
void AddAfter(LIST &l, NODE *q, NODE *node){
	if (q !=NULL)
	{
		node->pNext = q->pNext;
		q->pNext = node;
		if (q == l.pTail)
		{
			l.pTail = node;
		} else {
			AddFirst(l,node);
		}
	}
}

NODE *InsertAfter(LIST &l, NODE *q, DATA d){
	NODE *node = GetNode(d);
	if (node == NULL) return NULL;
	if (q != NULL)
	{
		node->pNext = q->pNext;
		q->pNext = node;
		if (q == l.pTail)
		{
			l.pTail = node;
		}
	} else InsertHead(l,d);
}

void PrintLinkList(LIST &l)
{
	NODE *node = l.pHead;
	while(node->pNext != l.pTail)
	{
		printf("\n%d - %c",node->Data.Number,node->Data.Info);
		node = node->pNext;
	}
	printf("\n%d - %c",node->Data.Number,node->Data.Info);
}
///////////////////////////////////////////////////////////
void main(){
	LIST *list = new LIST;
	// Chèn phần tử đầu tiên
	DATA d;
	d.Info = 'A';
	d.Number = 1;
	NODE *node = GetNode(d);
	AddFirst(*list,node);

	// Chèn phần tử thứ hai
	d.Info = 'B';
	d.Number = 2;
	InsertHead(*list,d);

	PrintLinkList(*list);
	getch();
}