#include <stdio.h>
#include <string.h>

int str_len(const char *s)
{
	int len=0;
	
	while(s[len])
		len++;
	
	return len;
}

int main()
{
	char str[256];
	printf("문자열 : ");
	scanf("%s",str);
	// 문자열은 단순한 변수가 아니라 배열 형태로 처리됨
	// 배열은 메모리 상에서 연속된 공간에 데이터를 저장하며, 이름 자체가 시작 주소를 나타냄
	// 따라서 문자열을 입력받을 때에는 &를 붙이지 않아도 됨
	printf("이 문자열의 길이는 %d입니다.\n",str_len(str));
	
	return 0;
}
