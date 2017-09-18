#include <stdlib.h>
#include <string.h>

static int ctsort(int *data, int size, int k)
{
	int *counts, *temp;
	int i, j;
	
	if( (counts = (int *)malloc(k * sizeof(int))) == NULL) return -1;
	
	if( (temp = (int *)malloc(size * sizeof(int))) == NULL) return -1;
	
	/* Initialize the counts */
	for(i = 0; i < size; i++)
		counts[i] = 0;
	
	/* Count the occurrences of each element */
 	for(j = 0; j < size; j++)
	{
		counts[data[j]]++;
	}
	
	for(i = 1; i < k; i++)
	{
		counts[i] = counts[i] + counts[i - 1];
	}
	
	for(j = size - 1; j>= 0; j--)
	{
		temp[counts[data[j]] - 1] = data[j];
		counts[data[j]] = counts[data[j]] - 1;
	}
	
	memcpy(data, temp, size * sizeof(int));
	
	free(counts);
	free(temp);
	
	return 0;
}

int main()
{
	int ctarray[10] = {2,2,5,6,5,7,2,6,5,4};
 	printf("%d %d %d %d %d %d %d %d %d\n", ctarray[0], ctarray[1], 
	 ctarray[2], ctarray[3], ctarray[4], ctarray[5], ctarray[6], ctarray[7],
	 ctarray[8], ctarray[9]);
	
	if(ctsort(ctarray, 9, 10 ) != 0) return -1;
	
	printf("%d %d %d %d %d %d %d %d %d\n", ctarray[0], ctarray[1], 
	 ctarray[2], ctarray[3], ctarray[4], ctarray[5], ctarray[6], ctarray[7],
	 ctarray[8], ctarray[9]);
	return 0;
	
}
