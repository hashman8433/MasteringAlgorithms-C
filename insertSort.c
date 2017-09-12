#include <stdlib.h>
#include <string.h>

#include <stdio.h>


/* issort*/
int issort(void *data,int size,int esize,int (*compare)(const void *key1,const void *key2))
{

  char *a = data;
  void *key;
  int i,j;
  /*Allocate storage for the key element among the sorted elements*/
  if((key = (char*)malloc(esize))== NULL)
    return -1;

  /*Repeatedly insert a key element among the sorted element.*/
  for(j=1;j<size;j++){
    memcpy(key,&a[j*esize],esize);
    i = j-1;
    /*Determine the position at whitch to insert the key element.*/
    while(i>=0&&compare(&a[i * esize],key) > 0)
      {
	memcpy(&a[(i + 1) * esize],key,esize);
	i--;
      }
    memcpy(&a[(i+1) * esize], &a[i * esize], esize);
  }

  /*Free the storage allocated for sorting. */
  free(key);
  return 0;

  
}

int compare(int *i,int *j)
{
  if(i>j)
    {
      return 1;
    }
  
    else if(i==j)
    {
      return 0;
    }
    else
    {
      return -1;
    }
	
  
}

int main()
{
  printf("Hello World! \n");
  int (*func)(int *i,int *j);
  func = compare;

  int i = 9;
  int j = 90;
  printf("func  return %d\n",func(&i,&j));
  return 0;

}
