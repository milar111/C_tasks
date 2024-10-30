#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *members;
    int size;
}Set;

Set* init();
void printSet(Set * set);
void addToSet(Set * set, int value);
int is_empty(Set * set);
int is_subset(Set * set1, Set * set2);

int main(void){
    Set * setA = init();
    addToSet(setA, 2);
    addToSet(setA, 3);
    addToSet(setA, 7);

    printSet(setA);
    is_empty(setA);

    Set* setB = init();
    addToSet(setB, 2);
    addToSet(setB, 1);
    addToSet(setB, 2);
    addToSet(setB, 3);
    addToSet(setB, 4);
    printSet(setB);
    is_empty(setB);

    is_subset(setA, setB);
    if(is_subset(setA, setB) == 0){
        printf("setA is not a subset of setB\n");
    }else{
        printf("setA is a subset of setB\n");
    }


    return 0;
}

Set* init(){
    Set * new_set = malloc(sizeof(Set));
    new_set->size = 0;
    new_set -> members = NULL;
    return new_set;
}

void printSet(Set * set){
    for(int i = 0; i < set -> size; i++){
        printf("%d - ", set-> members[i]);
    }
    printf("\n");
}

void addToSet(Set * set, int value){
    for(int i = 0; i < set->size; i++){
        if(set->members[i] == value) return;
    }
    if (set->size == 0){
        set-> members = malloc(sizeof(int));
        set->members[0] = value;
        set->size = 1;
    }
    else{set->members = realloc(set->members, (set->size + 1) * sizeof(int));
        set->members[set->size] = value;
        set->size++;
    }
}

int is_empty(Set * set){
    if(set->size == 0){
        printf("Set is empty\n");
    }
    else{
        printf("Set is not empty\n");
    }
}

int is_subset(Set * set1, Set * set2){
    for(int i = 0; i < set1->size; i++){
        int isSubset = 0;
        for(int j = 0; j < set2->size; j++){
            if(set1-> members[i] == set2-> members[j]){
                isSubset = 1;
                break;
            }
        }
        if(!isSubset) return 0;
    }
    return 1;
}