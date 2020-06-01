//Sorting of elements of array using insertion sort.
#include<stdio.h>
  int* insertion_sort(int *ptr,int l) //function of insertion sort.
  {
      int i,j;
      for(j=1; j<l;j++)
      {
          int key=ptr[j];
              i=j-1 ;
          while(i>=0 && ptr[i]>key)
          {
              ptr[i+1]=ptr[i];
              i-- ;
          }
          ptr[i+1]=key ;
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
  int *sort_arr=insertion_sort(ptr,n); //calling of insertion sort function
  printf("Elements after sorting are (using insertion sort): \n");
  for(int d=0;d<n;d++)
   {
	   printf("%d  ",sort_arr[d]);
   }

      return 0;
}
