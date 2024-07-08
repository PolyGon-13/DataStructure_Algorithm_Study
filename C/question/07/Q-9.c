 #include <stdio.h>
 #include <stdlib.h>

int str_cmpic(const char *s1, const char *s2) 
{
     while(abs(*s1-*s2) == 32 || *s1 == *s2) // 두 문자의 차이를 구해서 32(대문자와 소문자의 차이)라면 같은 문자로 취급
	 {
         if(*s1 == '\0')
             return 0;
         s1++;
         s2++;
     }
	 
     return *s1-*s2;
}

int str_ncmpic(const char *s1, const char *s2, size_t n) 
{
     while((abs(*s1-*s2)==32 || *s1 == *s2) && (*s1!='\0' && *s2!='\0')) 
	 {
         n--;
         
         if(n == 0) // 모든 문자가 같은 경우
             return 0;
         
         s1++;
         s2++;
     }
     return *s1 - *s2;
}

int main() 
{
     char st[128];
     int sz;
     puts("\"ABCD\"와 비교합니다.");
     puts("\"XXXX\"면 종료합니다.");
     
     while(1) {
         printf("문자열 st : ");
         scanf("%s", st);
         
         printf("비교할 갯수 : ");
         scanf("%d", &sz);
         
         
         if(str_ncmpic("XXXX", st, sz) == 0)
             break;
         printf("str_ncmpic(\"ABCD\", st, sz) = %d\n", str_ncmpic("ABCD", st, sz));
     }
     return 0;
}


// toupper 함수를 사용해서 해결하는 풀이도 가능
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int str_cmpic(const char *s1, const char *s2)
{
	while (toupper(*s1) == toupper(*s2)) 
	{
		if (*s1 == '\0')			
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
}

int str_ncmpic(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2) 
	{
		if (toupper(*s1) != toupper(*s2))			
			return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
		s1++;
		s2++;
		n--;
	}
	if (!n)  return 0;
	if (*s1) return toupper(*s1);
	return toupper(*s2);
}
*/
