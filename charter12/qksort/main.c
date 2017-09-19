/* qksort.c */
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//http://www.cnblogs.com/fengty90/p/3768827.html

/* compare_int */

static int compare_int(const void *int1,const void *int2)
{
	/* Compare two integers (used during median-of-three partitioning)  */
	if (*(const int *)int1 > *(const int *)int2)
		return 1;
	else if (*(const int *)int1 < *(const int *)int2)
		return -1;
	else
		return 0;

}

/* issort  */
int issort(void *data, int size, int esize,int (*compare)(const void *key1,const void *key2))
{
	char *a = data;
	void *key ;
	int i,j;
	
	if(NULL == (key= (char*)malloc(esize)) ) return -1;

	for(j = 1; j < size; j++){
		
		memcpy(key, &a[j * esize], esize);	
		i = j - 1;
		
		while(i > 0 && compare( &a[i * esize], key) > 0)
		{
			memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
			i--;
		}
		memcpy( &a[(i + 1) * esize], key, esize);
	}
	return 0;

}


/*  partition  */
static int partition(void *data, int esize, int i, int k, int (*compare)
	(const void * key1, const void *key2))
{

	char *a = data;
	void *pval, *temp;
	int r[3];

	/* Allocate storage for the partition value and swaping  */
	if((pval = malloc(esize)) == NULL)
		return -1;

	if((temp = malloc(esize)) == NULL)
	{
		free(pval);
		return -1;

	}

	/* Use the median-of-three method to find the partition value  */
	r[0] = (rand() % (k - i + 1) + i);
	r[1] = (rand() % (k - i + 1) + i);
	r[2] = (rand() % (k - i + 1) + i);
		
	if(issort(r,3,sizeof(int),compare_int) < 0 )
		return -1;	
	memcpy( pval, &a[r[1] * esize], esize);	

	printf("issort : %d %d %d  pval : %d\n ", r[0], r[1], r[2], *(int *)pval);
	i--;
	k++;
	while(1)
	{
		do {
			k--;	
		}while (compare(&a[k * esize], pval) > 0);

		do{
			i++;
		}while( compare(&a[i * esize], pval) < 0);	
	
		if(k <= i){
			break;
		} else {
			memcpy(temp, &a[i * esize], esize);
			memcpy( &a[i * esize], &a[k * esize], esize);
			memcpy( &a[k * esize], temp, esize);
		}
	}
	
	
	free(pval);
	free(temp);
	return k;
}

int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2))
{

	int j = 0;
	printf("i = %d k = %d\n" ,i, k);
	if(k <= i) return -1;
	
	if((j = partition(data, esize, i, k, compare)) < 0) return -1;
	printf("j = %d\n", j);
	
	if(qksort(data,size, sizeof(int), i, j, compare_int) < 0)
		return -1;
	
	if(qksort(data,size, sizeof(int), j+1, k, compare_int) < 0)
		return -1;

	return 	0;
}


int main()
{

	int qarray[10] = {0,1,7,5,4};

	printf("%d %d %d %d %d\n",qarray[0], qarray[1], qarray[2], qarray[3], qarray[4]);
	
	qksort(qarray, 5, sizeof(int), 0, 4, compare_int);

	//issort(qarray, 5, sizeof(int),compare_int);
	printf("%d %d %d %d %d\n",qarray[0], qarray[1], qarray[2], qarray[3], qarray[4]);
	return 1;
}
