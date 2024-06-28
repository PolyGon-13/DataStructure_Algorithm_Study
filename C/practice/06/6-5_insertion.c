#include <stdio.h>
#include <stdlib.h>

void insertion(int a[],int n)
{
    int i;

    for(i=1; i<n; i++) 
    {
        int tmp=a[i];
        int j;
        for(j=i; j>0 && a[j-1]>tmp; j--)
        // j가 0보다 크고, j-1번째 요소가 처음에 저장한 a[i]보다 큰 경우에만 for문 실행
            a[j]=a[j-1];
            // j-1이 a[i]보다 크면 계속해서 j번째 요소에 j-1번째 요소가 덧씌워짐
        a[j]=tmp;
        // for문 반복이 중단되었다는 것은 j-1번째 요소가 a[i]보다 작다는 것이므로 종료된 시점의 j번째 요소에는 처음에 저장한 a[i]를 넣어준다.
    }
}

int main()
{
    int nx;
    puts("단순 삽입 정렬");
    printf("요소 개수 : ");
    scanf("%d",&nx);
    int *x=calloc(nx,sizeof(int));
    int i;

    for(i=0; i<nx; i++) 
    {
        printf("x[%d] : ",i);
        scanf("%d",&x[i]);
    }

    insertion(x,nx);

    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx; i++)
        printf("x[%d] = %d\n",i,x[i]);

    free(x);

    return 0;
}
