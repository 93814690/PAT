


#include "stdio.h"
#include "stdlib.h"

#define Max 1010

typedef struct mooncake{
	float capacity;
	float totalPrice;
	float singlePrice;
}mc;

int cmp(const void *a,const void *b)
{
	return (*(mc *)b).singlePrice > (*(mc *)a).singlePrice? 1 : -1 ;
}

int main(int argc, char const *argv[])
{
	int n,m,i;
	float result = 0.0;
	mc cake[Max];
	scanf("%d %d",&n,&m);
	for (i = 0; i < n; ++i)
	{
		scanf("%f",&cake[i].capacity);
	}
	for (i = 0; i < n; ++i)
	{
		scanf("%f",&cake[i].totalPrice);
		cake[i].singlePrice = cake[i].totalPrice / cake[i].capacity;
	}
	qsort(cake,n,sizeof(cake[0]),cmp);
	i = 0;
	while(m>0 && i<n){
		if (m >= cake[i].capacity)
		{
			result += cake[i].totalPrice;
			m -= cake[i].capacity;
			i++;
		}else{
			result += m * cake[i].singlePrice;
			m = 0;
		}
	}
	printf("%.2lf\n", result );

	return 0;
}