#ifndef ___IntDeck
#define ___IntDeck

typedef struct
{
	int max;
	int num;
	int front;
	int rear;
	int* deck;
} IntDeck;

int Initialize(IntDeck* d,int max);

int Endeck(IntDeck* d,int x);

int Endeck2(IntDeck* d,int x);

int Dedeck(IntDeck* d,int* x);

int Dedeck2(IntDeck* d,int* x);

int Peek(const IntDeck* d,int* x);

void Clear(IntDeck* d);

int Capacity(const IntDeck* d);

int Size(const IntDeck* d);

int IsEmpty(const IntDeck* d);

int IsFull(const IntDeck* d);

int Search(const IntDeck* d,int x);

void Print(const IntDeck* d);

void Terminate(IntDeck* d);

#endif
