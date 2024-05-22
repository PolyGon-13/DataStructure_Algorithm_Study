#include <stdio.h>

int main()
{
	int no;
	printf("2자리 양수를 입력하세요.\n");
	do{
		printf("수는: ");
		scanf("%d",&no);
	}while(no<10 || no>99);
	
	printf("변수 no값은 %d이 되었습니다.",no);
	return 0; 
}
