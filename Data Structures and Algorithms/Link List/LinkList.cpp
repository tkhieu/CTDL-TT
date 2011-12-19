﻿#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

struct Data {
	char Info;
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

void Initalize(LIST &l){
	//l.pHead = new NODE;
	l.pHead = NULL;
	l.pTail = NULL;
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
		}
	} else {
		AddFirst(l,node);
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
	while(node != NULL)
	{
		printf("\n%d - %c",node->Data.Number,node->Data.Info);
		node = node->pNext;
	}
	//printf("\n%d - %c",node->Data.Number,node->Data.Info);
}


// 03. Lấy một Node từ vị trí k

NODE *Search(LIST &l, Data d){
	NODE *node = NULL;
	node = l.pHead;
	while(node != NULL){
		if(node->Data.Info == d.Info && node->Data.Number == d.Number)
			return node;
		node = node->pNext;
	}
	return NULL;
}

///////////////////////////////////////////////////////////


void InsertElement(LIST *list){
	// Chèn phần tử đầu tiên
	DATA d;
	d.Info = 'A';
	d.Number = 1;
	NODE *node1 = GetNode(d);
	AddFirst(*list,node1);

	// Chèn phần tử thứ hai
	d.Info = 'B';
	d.Number = 2;
	InsertHead(*list,d);

	// Chèn phần tử thứ ba
	d.Info = 'C';
	d.Number = 3;
	NODE *node2 = GetNode(d);
	AddFirst(*list,node2);

	// Chèn phần tử thứ tư
	d.Info = 'D';
	d.Number = 4;
	InsertTail(*list,d);

	// Chèn phần tử thứ năm
	d.Info = 'C';
	d.Number = 3;
	NODE *node3 = Search(*list,d);
	d.Info = 'E';
	d.Number = 5;
	NODE *node4 = GetNode(d);
	AddAfter(*list,node3,node4);

	// Chèn phần tử thứ sáu
	d.Info = 'C';
	d.Number = 3;
	NODE *node5 = Search(*list,d);
	d.Info = 'F';
	d.Number = 6;
	NODE *node6 = GetNode(d);
	InsertAfter(*list,node3,d);
}

///////////////////////////////////////////////////////////

void main(){
	LIST *list = new LIST;
	Initalize(*list);
	InsertElement(list);
	PrintLinkList(*list);
	getch();
}