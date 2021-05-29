#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

char check[37] = {0};
int check2[] = {0x6a, 0x61, 0x76, 0x61, 0x69, 0x73, 0x6c, 0x61, 0x66, 0x6c, 0x65, 0x6d, 0x6d, 0x65, 0x64, 
0x65, 0x66, 0x61, 0x69, 0x72, 0x65, 0x75, 0x6e, 0x76, 0x72, 0x61, 0x69, 0x70, 0x72, 0x6f, 0x67, 0x72, 0x61, 0x6d, 0x6d, 0x65};

int main(int argc, char* argv[])
{
    
    for(int i = 0; i < 36; i++)
    {
        *(check+i) = *(check2+i);
    }
    *(check+36)='\0';

    int bool = 1;
    while(bool)
    {
        char* user = malloc(100);
        char* pwd = malloc(100);
        printf("===== Password Annexe =====");
        printf("User: ");
        scanf("%s", user);
        if(!user)
        {
            printf("An error has occured");
            return 1;
        }
        scanf("%s", pwd);
        if(!pwd)
        {
            printf("An error has occured");
            return 1;
        }

        if(strlen(pwd) == 36 && strcmp(check, pwd) == 0)
        {
            printf("An error hasn't occured");
            bool = 0;
        }
        else
        {
            printf("Password and user association does not work");
        }
        free(pwd);
        free(user);
    }

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);

    return 0;
}


//Useless code for made decompilation harder
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}