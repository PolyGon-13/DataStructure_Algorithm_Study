#ifndef ___Member
#define ___Member

typedef struct
{
	int no; // 번호
	char name[20]; // 이름
} Member;

#define MEMBER_NO 1 
// 번호를 나타내는 정숫값
#define MEMBER_NAME 2 
// 이름을 나타내는 정숫값

int MemberNoCmp(const Member *x,const Member *y);
int MemberNameCmp(const Member *x,const Member *y);
void Print(const Member *x);
void PrintLnMember(const Member *x);
Member ScanMember(const char *message,int sw);

#endif
