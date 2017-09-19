#include <stdlib.h>
#include <string.h>

int rxsort(int *data, int size, int p, int k)
{
	int *counts, *temp;
	int index, pval, i, j, n;
	
	if( (counts = (int *)malloc(size * sizeof(int)) ) == NULL ) return -1;
	
	if( (temp = (int *)malloc(size * sizeof(int)) ) == NULL) return -1;
	
	

	for(n = 0; n < p; n++)
	{
		for(i = 0; i < k; i++)
			counts[i] = 0;
		
		pval = n * k;	
		
		if(pval == 0) pval = 1;
		
		for(j = 0; j < size; j++){
			
			index = (int)(data[j] / pval) % k;
			printf("pval = %d  ", pval);
			printf("index = %d ", index);
			counts[index] += 1;
			printf("counts index  %d\n" ,counts[index]);
		}
		printf(" \n");
		
		for(j = 1; j < k; j++){
			counts[j] += counts[j - 1];
			
		}
		
		
		for(j = size - 1; j >= 0; j--){
			index = (int)(data[j] / pval) % k;
			temp[ counts[index] - 1] = data[j];
			counts[index] -= 1;
		}
		printf("temp %d %d %d %d %d %d %d %d %d\n", temp[0], temp[1], 
	 		temp[2], temp[3], temp[4], temp[5], temp[6], temp[7],
	 		temp[8]);
		memcpy(data, temp, size * sizeof(int));
		
	}
	
	free(counts);
	free(temp);
	
	return 0;
}

int main()
{
	int rxarray[10] = {2,52,51,62,45,97,211,62,5,4};
 	printf("%d %d %d %d %d %d %d %d %d\n", rxarray[0], rxarray[1], 
	 rxarray[2], rxarray[3], rxarray[4], rxarray[5], rxarray[6], rxarray[7],
	 rxarray[8], rxarray[9]);
	
	if( rxsort(rxarray, 9, 8, 10) != 0) return -1;
	
	printf("%d %d %d %d %d %d %d %d %d\n", rxarray[0], rxarray[1], 
	 rxarray[2], rxarray[3], rxarray[4], rxarray[5], rxarray[6], rxarray[7],
	 rxarray[8], rxarray[9]);
	
	return 0;
	
}
