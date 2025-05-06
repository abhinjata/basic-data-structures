#include <stdio.h>

typedef struct Stru{

    int rollno;
    char name[50];
    char college[50];
    int score;
}Stu;

void sortStruct(Stu* arr, int n){

    while(1==1){

        int i = 0;
        int swap = 0;

        while(i < n - 1){

            if((arr + i)->score < (arr + i + 1)-> score){

                Stu temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp; 

                swap = 1;

            }
            i++;
        }
        if(swap == 0){

            break;

        }




    }


}

int main(void){

    int n;
    scanf("%d", &n);

    Stu* SDB = malloc(n*sizeof(Stu));

    for(int i = 0; i < n; i++){

        scanf("%d", &(SDB + i) -> rollno);
        scanf("%d", (SDB + i) -> name);
        scanf("%d", (SDB + i)-> college);
        scanf("%d", &(SDB + i) -> score);
    }

    sortStruct(SDB, n);

    for(int i = 0; i < n; i++){

        printf("%d %s %s %d\n", (SDB +  i) -> rollno, (SDB + i) -> name, (SDB + i) -> college, (SDB + i) -> score);

    }

    free(SDB);
    

}