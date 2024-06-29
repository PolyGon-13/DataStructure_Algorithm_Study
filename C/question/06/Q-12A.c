// Ver.A
#include <stdio.h>
#include <stdlib.h>

int cnt=0;

void shell(int a[],int n)
{
    int i,j,h;
    
    for(h=n/2;h>0;h/=2)
        for(i=h;i<n;i++)
        {
            int tmp=a[i];
            for(j=i-h;j>=0 && a[j]>tmp;j-=h)
            {
                a[j+h]=a[j];
                cnt++;
            }
            a[j+h]=tmp;
            cnt++;
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
    printf("실행 횟수 : %d\n",cnt);
        
    free(x);
    
    return 0;
}

// Ver.B
#include <stdio.h>
#include <stdlib.h>

int cnt=0;

void shell(int a[],int n)
{
    int i,j,h;
    
    for(h=1;h<n;h=h*3+1)
        ;
    for(;h>0;h/=3)
        for(i=h;i<n;i++)
        {
            int tmp=a[i];
            for(j=i-h;j>=0 && a[j]>tmp;j-=h)
            {
                a[j+h]=a[j];
                cnt++;
            }
            a[j+h]=tmp;
            cnt++;
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
    printf("실행 횟수 : %d\n",cnt);
        
    free(x);
    
    return 0;
}
