//Sorting of elements of array using selection  sort.
#include<stdio.h>
  int* selection_sort(int *ptr,int l) //function of selection sort.
  {
      int i,j,min,temp;
      for(j=0; j<l-1;j++)
      {
          min=j;
          for(i=j+1;i<l;i++)
          {
              if(ptr[i]<ptr[min])
                min=i;
          }
          temp=ptr[j];
          ptr[j]=ptr[min] ;
          ptr[min]=temp ;
      }
      return ptr;
  }

  int main() //call of main function.
  {
    int n;
   printf("Enter the size of array:-");
   scanf("%d",&n);
   int *ptr;
   ptr=(int *)malloc(n*sizeof(int)); //dynamic memory allocation
   if(ptr==NULL)
    printf("Memory not succesfully alloacate \n");
   else
    printf("Memory  succesfully alloacate \n");

   printf("Enter the elements of array \n");
   for(int a=0;a<n;a++)
   {
       scanf("%d",&ptr[a]);
   }
  int *sort_arr=selection_sort(ptr,n); //calling of selection sort function
  printf("Elements after sorting are (using secection sort): \n");
  for(int d=0;d<n;d++)
   {
	   printf("%d  ",sort_arr[d]);
   }

      return 0;
}

