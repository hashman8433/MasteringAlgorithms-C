#include "stdlib.h" 
#include "stdio.h"
#include "string.h"

int issort(void *data,int size,int esize,int (*compare)(const void *key1,const void *key2))
{
	char *a = data;
	void *key;
	int i,j;

	if(NULL == (key= (char*)malloc(esize)) ) return -1;

	for(j=1; j < size ;j++)
	{
		memcpy(key ,&a[j * esize],esize);
		i = j - 1;
	
		while(i>=0 && compare(&a[i * size],key) > 0){
		
			memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
			i--;
		}

		memcpy(&a[(i + 1) * esize], key, esize);
		
	}
	free(key);
	return 0;
}

int compare_int(const void *i, const void *j)
{
	if(*(const int *)i > *(const int *)j) return 1;
	return 0;
}


int main(int argc ,char **argv )
{
	
	char *key;
	key = malloc(sizeof(char));
	//printf("hello" );
	
	int *iarray = (int*)malloc(sizeof(int) * 10);
	
	iarray[0] = 1;
	iarray[1] = 3;
	iarray[2] = 2;
	iarray[3] = 6;

	printf("%d  %d  %d  %d\n",iarray[0],iarray[1],iarray[2],iarray[3]);
	issort(iarray,4,sizeof(int),compare_int);
	printf("%d  %d  %d  %d\n",iarray[0],iarray[1],iarray[2],iarray[3]);

	
}

