//Sorting of elements of array using quick sort.
#include<stdio.h>
int arr[20];

void swap(int *a,int *b) //function for swaping the number
{
    int temp=*b;
	*b=*a;
	*a=temp;
}

int partition(int low,int high)//function for partition
{
   int pivot=arr[low];
   int i=low;
   int j=high;
    while(i<j)
    {
          do{
              i++;
            }while(arr[i]<=pivot);

          do{
              j--;
            }while(arr[j]>pivot);

            if(i<j)
             swap(&arr[i],&arr[j]) ;
     }

     swap(&arr[low],&arr[j]);
     return j;
}

void quick_sort(int low,int high)//function of quick sort
{
   if(low<high)
   {
      int j=partition(low,high);//call of partition function
      quick_sort(low,j);        //recursive call  of quick sort function
      quick_sort(j+1,high);     //recursive call  of quick sort function
   }
}

int main()   //call of main function
{
   int size;
   printf("Enter size of array--");
   scanf("%d",&size);
   printf("Enter elements before sorting\n");
   for(int i = 0; i <= size-1; i++)
    {
      scanf("%d",&arr[i]);
    }
    quick_sort(0,size-1);        //call of quick sort function
    printf("Elements after sorting\n");
   for(int j = 0; j <= size-1; j++)
    printf("%d  ", arr[j]);
    return 0;
}


