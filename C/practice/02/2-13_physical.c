#include <stdio.h>
#define VMAX 21

typedef struct
{
	char name[20];
	int height;
	double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[],int n)
{
	int i;
	double sum=0;
	
	for(i=0;i<n;i++)
		sum+=dat[i].height;
	
	return sum/n;
}

void dist_vision(const PhysCheck dat[],int n,int dist[])
{
	int i;
	
	for(i=0;i<VMAX;i++)
		dist[i]=0;
	for(i=0;i<n;i++)
		if(dat[i].vision>=0.0 && dat[i].vision<=VMAX<=VMAX/10.0)
			dist[(int)(dat[i].vision*10)]++;
}

int main()
{
	int i;
	
	PhysCheck x[]=
	{
		{"박현규",162,0.3},
		{"함진아",173,0.7},
		{"최윤미",175,2.0},
		{"홍연의",171,1.5},
		{"이수진",168,0.4},
		{"김영준",174,1.2},
		{"박용규",169,0.8}
	};
	
	int nx=sizeof(x)/sizeof(x[0]);
	int vdist[VMAX];
	
	puts("--- 신체검사표 ---");
	puts("    이름    키  시력");
	puts("-------------------");
	for(i=0;i<nx;i++)
		printf("%-18.18s %4d %5.1f\n",x[i].name,x[i].height,x[i].vision);
	printf("\n평균 키: %5.1f cm\n",ave_height(x,nx));
	dist_vision(x,nx,vdist);
	printf("\n시력 분포\n");
	for(i=0;i<VMAX;i++)
		printf("%3.1f ~: %2d 명\n",i/10.0,vdist[i]);
	
	return 0;
}
// %-18.18s
// -는 왼쪽 정렬을 의미
// 18은 최소너비를 의미(출력할 문자열의 길이가 18보다 짧으면 나머지 부분은 공백으로 채워짐)
// 두 번째 18은 최대 출력 길이를 의미(출력할 문자열이 18보다 길면 18자까지 잘라서 출력됨)
