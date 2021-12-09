#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//elem1>elem2 이면 1, elem1==elem2 이면 0, elem1<elem2 이면 -1
int CompareScore(const void *_elem1, const void *_elem2){
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;
    
    if(*elem1 > *elem2)
        return 1;
    else if (*elem1 < *elem2)
        return -1;
    else
        return 0;
}

int main(void){
    int DataSet[] = {6,4,2,3,1,5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    
    qsort((void*)DataSet, Length, sizeof(int), CompareScore);
    
    for(i=0; i<Length; i++){
        printf("%d", DataSet[i]);
    }
    
    printf("\n");
    
    return 0;
}
