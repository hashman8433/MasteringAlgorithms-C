//
//  mgsort.c
//  Algorithms - Merge sort
//
//  Created by Hashman8433 on 17/09/2017.
//  Copyright ? 2017 Hashman8433. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int merge(void *data, int esize, int i, int j, int k,
			int (*compare)(const void *key1, const void *key2)){
	char *a = data, *m;
	int ipos, jpos, mpos;
	
	ipos = i;
	jpos = j + 1;
	mpos = 0;
	
	if((m = (char *)malloc(esize * (k - i + 1))) == NULL) return -1;
	//i = 0 j = 1 k = 2
	//6     4     5
	while(ipos <= j || jpos <= k){
		printf("ipos %d jpos %d mpos %d\n", ipos, jpos, mpos);
	
		if(jpos > k){
			while(ipos <= j){
				memcpy(&m[mpos * esize], &a[ipos * esize], esize);
				ipos++;
				mpos++;
			}
			printf("after ipos %d jpos %d mpos %d\n", ipos, jpos, mpos);
			continue;
		}else if(ipos > j){
			while(jpos <= k){
				memcpy(&m[mpos * esize], &a[jpos * esize], esize);
				jpos++;
				mpos++;
			}
			printf("after ipos %d jpos %d mpos %d\n", ipos, jpos, mpos);
			continue;
		}
		
	
		if(compare(&a[ipos * esize], &a[jpos * esize]) > 0){
			memcpy(&m[mpos * esize], &a[ipos * esize], esize);
			ipos++;
			mpos++;
		}else{
			memcpy(&m[mpos * esize], &a[jpos * esize], esize);
			jpos++;
			mpos++;
		
		}
		
	
	}
	memcpy(&a[i * esize], m, esize * ((k - i) + 1));
	free(m);
	return 0;
}

int compare_int(const void *key1, const void *key2)
{
	int i,j;
	i = *(const int *)key1;
	j = *(const int *)key2;
	if(i > j) return 1;
	if(i < j) return -1;
	if(i = j) return 0;
	
}

int mgsort(void *data, int esize, int i, int k,int (*compare)(const void *key1, const void *key2))
{
	int j;
	
	if(i < k){
			
		
		j = (i + k - 1)/2;
		printf("mgsort %d %d %d\n", i, j ,k);
		
		if(mgsort(data, esize, i, j, compare) < 0) return -1;
		if(mgsort(data, esize, j+1, k, compare) < 0) return -1;
		
		if(merge(data, esize, i, j, k, compare) < 0) return -1;
		
	}
	
	return 0;
}
int main(int argc, char *argv[])
{
	int iarray[10] = {6,7,5,3,7};
	
	printf("%d %d %d %d %d\n", iarray[0], iarray[1], iarray[2], iarray[3], iarray[4]);
	
	/*if(mgsort(iarray, sizeof(int), 0, 4, compare_int) < 0)
		printf("sort errot \n");*/
		
	merge(iarray, sizeof(int),0 ,0, 1, compare_int);
	
	printf("after sort %d %d %d %d %d\n", iarray[0], iarray[1], iarray[2], iarray[3], iarray[4]);
	
	return 0;
}
