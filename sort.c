#include <stdio.h>

void swap (int *a, int *b);
void bubble_sort(int length,int a[]);
void insertion_sort(int length, int a[]);
void selection_sort(int length, int a[]);
void merge_sort(int a[], int l , int r);
void merge (int a[], int l , int r, int m);
void quick_sort(int a[], int low, int high);
int partition(int a[], int low, int high);



void main (void){

     int algo;
     printf ("*** Sort Algorithms***\n");
     printf ("Pick your algorithm : \n 1- Bubble sort \n 2- Insertion sort \n 3- Selection sort \n 4- merge sort \n 5- quick sort \n");
     printf ("alogorithm number : ");
     scanf ("%i", &algo);

     int a[] = {0,7,8,3,6,4};
     int size = sizeof(a)/sizeof(a[0]);

     switch (algo) {

     case 1 : bubble_sort (size,a); break;
     case 2 : insertion_sort (size,a); break;
     case 3 : selection_sort(size,a); break;
     case 4 : merge_sort(a,0,size-1);break;
     case 5 : quick_sort(a,0,size-1);break;
     default : printf ("enter a number between 1 and 5"); break;

     }
     

     for(int i =0; i<size;i++){

     printf ("%i ", a[i]);

    }
     
    printf ("\n");

}

/*swap two ints*/


void swap (int *a, int *b){

   int t;
   t = *b;
   *b = *a ;
   *a = t;


}

/*sort an array of ints using bubble sort algorithm*/

void bubble_sort(int length, int a[]){
 
    // swap a[j] and a[i] if they are not in order

     for(int j = 0 ; j<length-1 ; j++){

          for(int i =0; i<=length-2; i++){
		
              if (a[i] > a [i+1]) 
        	 swap (&a[i], &a[i+1]);
              
          }
   }
}

/* sort an array of ints using insertion sort*/

void insertion_sort(int length, int a[]){

  for (int i = 1; i<= length -1; i++){

    int value = a[i];
    int hole = i;

    while (hole >0 && a[hole-1] > value){

      a[hole] = a[hole-1];
      hole --;

    }

      a[hole] = value;

  }   


}


void selection_sort(int length, int a[]){

     

     for(int i = 0; i<length; i++){

        int minindex=i;

	    for(int j=i ; j<length; j++){

	       if(a[j] <a[minindex] ) minindex = j;
	 
             }
        swap (&a[i],&a[minindex]);


    }
   

}

void merge (int arr[], int l, int r, int m){

      int n1 = m-l+1;
      int n2 = r-m;

      int L[n1];
      int R[n2];

      int i,j,k;

     //copy the left part in L and the right part in R

      for(i=0; i<n1; i++){
          L[i] = arr[l+i];

     } 
     
     for(j=0; j<n1; j++){
          R[j] = arr[m+j+1];

     } 

     i = 0 ; // index for L
     j=0;    //index for R
     k=l;    // index for arr

     //merge the two parts

     while (i<n1 && j<n2){

	if(L[i] <= R[j]){
	   
	      arr[k] = L[i]; i++;
      
	}
	else {

	      arr[k] = R[j]; j++;

	}
       k++;

     }

     //remaining elements in L

    while (i<n1){
         
	arr[k] = L[i]; i++; k++;

     }

    while (j<n2){
         
	arr[k] = R[j]; j++; k++;

     }


}

/*

   l : left r : right m : middle

*/

void merge_sort(int a[], int l , int r){

    
       if (l<r){

	int m = (r+l)/2;

	merge_sort(a,l,m);
	merge_sort(a,m+1,r);

	merge(a,l,r,m);


      }

}

int partition (int a[], int low, int high) {

   int pivot = a [high];
   int i = (low - 1); // index of lmower element

   for (int j = low; j <= high -1; j++ ){

     if (a[j] < pivot ) {
	i++;
	swap (&a[i] , &a[j]);

     }

  }

  swap (&a[i+1] , &a[high]);

  //return the pivot index
  return i+1;

}


void quick_sort(int a[], int low, int high){

   if(low < high) {

       int pivot = partition (a, low, high);

       //the pivot is already in the right place
       // sort the left part using the quick algorithm
       quick_sort (a,low,pivot-1);
       // sort the right part using the quick algorithm
       quick_sort (a,pivot+1, high);



  }
}








