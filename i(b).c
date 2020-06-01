//sorting the elements using merge sort.
#include <stdio.h>
int b[10];
int arr[100];
void merging(int p, int q, int r)//funtion for merging process.
{
   int  i;
  int l1=p,r1=q+1 ;
   for( i = p; l1 <=q && r1<= r; i++)
    {
      if(arr[l1] <= arr[r1])
      {
         b[i] = arr[l1];
         l1++;
      }
      else
      {
         b[i] = arr[r1];
         r1++ ;
     }
   }

   while(l1<= q)
   {
      b[i] = arr[l1];
      i++;
      l1++;
   }

   while(r1<= r)
     {
      b[i] = arr[r1];
      i++;
      r1++;
    }
   for(i = p; i <= r; i++)
      arr[i] = b[i];
}

void merge_sort(int p, int r) // function for merge sort
{

   if(p < r)
  {
         int q=((p+r)/2);
      merge_sort(p, q); //recursive call of merge sort function
      merge_sort(q+1,r);//recursive call of merge sort function
      merging(p,q,r);   //call of merging function
   }
   else
    {
      return;
    }
}

int main() //call of main function.
 {
   int size;
   printf("Enter size of array--");
   scanf("%d",&size);
   printf("Enter elements before sorting\n");
   for(int i = 0; i <= size-1; i++)
    {
      scanf("%d",&arr[i]);
    }
    merge_sort(0,size-1);    //call of merge sort function
    printf("Elements after sorting\n");
   for(int j = 0; j <= size-1; j++)
    printf("%d  ", arr[j]);
    return 0;
}

