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
	struct Info *pNext;
	DATA Data;
};
typedef struct Node NODE;

struct LinkList {
	NODE *pHead;
	Node *pTail;
};
typedef struct LinkList LIST;