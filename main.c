//
//  main.c
// Given a list of unsorted numbers, find the numbers that have the smallest absolute difference between them.
// If there are multiple pairs, find them all. 
//

#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n);

int main (int argc, const char * argv[])
{

    int n;
    
    scanf("%d", &n);
    
    int *arr;
    arr=(int *) malloc(n*sizeof(int));
    int i, j=0;
    for (i=0; i<n;i++) {
        scanf("%d", &arr[i]);
    }
    sort(&arr[0], n);
    
    int smallestDiff = abs(arr[0]-arr[1]);
    for (i=1; i<n-1;i++) {
       int currentDiff = abs(arr[i]-arr[i-1]);
       if (currentDiff < smallestDiff) {
            smallestDiff = currentDiff;
       }
    }
    
    i=0;
    j=1;
    while (i<n && j<n) {
        if (i != j && abs(arr[i]-arr[j]) == smallestDiff) {
            printf("%d %d ", arr[i], arr[j]);
            i++;
            j++;
        }
        else if (abs(arr[i]-arr[j]) < smallestDiff){
            j++;
        } else {
            i++;
        }
    }
    return 0;
}

void sort(int *arr, int n)
{
    int i = 0;
    int el;
    int j;
    for (i=1;i<n;i++) {
        el = arr[i];
        j = i;
        while (j>0 && arr[j-1]>el) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = el;
    }
}


