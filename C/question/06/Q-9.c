#include <stdio.h>
#include <stdlib.h>

void insertion(int a[],int n)
{
    int i,j;

    for(i=1; i<n; i++) 
    {
        int tmp=a[0]=a[i];
        for(j=i; a[j-1]>tmp; j--)
            a[j]=a[j-1];
        if(j)
        // j가 0이 되어서 나왔다면 tmp보다 큰 값이 존재하지 않는다는 의미이므로, 아래 코드를 실행하지 않는다.
            a[j]=tmp;
        // 보초법. 배열을 생성할 때 끝에 원하는 검색결과(보초값)을 넣어준다.
        // 보초값을 넣어주었기에 당연히 원하는 검색결과를 찾게 되는데, 인덱스가 배열의 끝이면 검색되지 않은 것이고, 배열의 끝이 아니라면 검색이 된 것이라고 할 수 있다.
    }
}

int main()
{
    int i;
    int nx;
    puts("단순 삽입 정렬");
    printf("요소 개수 : ");
    scanf("%d",&nx);
    int *x=calloc(nx+1,sizeof(int)); // a[0]을 보초로 사용하기 때문에 n+1개의 배열을 생성

    for(i=1; i<nx+1; i++) 
    {
        printf("x[%d] : ",i);
        scanf("%d",&x[i]);
    }

    insertion(x,nx+1);

    puts("오름차순으로 정렬했습니다.");
    for(i=1; i<nx+1; i++)
        printf("x[%d] = %d\n",i,x[i]);

    free(x);

    return 0;
}
