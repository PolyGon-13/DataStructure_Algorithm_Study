#include <stdio.h>
#include <stdlib.h>

void shell(int a[],int n)
{
    int i,j,h;
    
    for(h=n/2;h>0;h/=2)
        for(i=h;i<n;i++)
        // i가 h부터 시작하고 i를 1씩 증가시키므로, 지정한 h칸만큼 요소들을 비교할 수 있음
        {
            int tmp=a[i];
            for(j=i-h;j>=0 && a[j]>tmp;j-=h)
            // h칸만큼 감소하며 값을 비교
                a[j+h]=a[j];
            a[j+h]=tmp;
        }
}

int main()
{
    int i;
    int nx;
    puts("셸 정렬");
    printf("요소 개수 : ");
    scanf("%d",&nx);
    int *x=calloc(nx,sizeof(int));
    for(i=0;i<nx;i++)
    {
        printf("x[%d] : ",i);
        scanf("%d",&x[i]);
    }
    
    shell(x,nx);
    
    puts("오름차순으로 정렬했습니다.");
    for(i=0;i<nx;i++)
        printf("x[%d] = %d\n",i,x[i]);
        
    free(x);
    
    return 0;
}
