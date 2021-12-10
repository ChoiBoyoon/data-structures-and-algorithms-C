#include <stdio.h>
#include <stdlib.h>
#include "Score.h"

int CompareScore(const void *_elem1, const void *_elem2){
    Score* elem1 = (Score*)_elem1;
    Score* elem2 = (Score*)_elem2;
    
    if(elem1->score < elem2->score)
        return 1;
    else if(elem1->score > elem2->score)
        return -1;
    else
        return 0;
}

int main(void){
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;
    Score target;
    Score* found = NULL;
    
    //sort DataSet in ascendant order using quick sort
    qsort((void*)DataSet, Length, sizeof (Score), CompareScore);
    
    //find a student whose score is 671.78
    target.number = 0; //initialize
    target.score = 671.78;
    
    found = bsearch((void*)&target, (void*)DataSet, Length, sizeof(Score), CompareScore);
    
    printf("found: %d %f\n", found->number, found->score);
    
    return 0;
}
