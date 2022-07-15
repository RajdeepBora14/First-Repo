#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define dt int

class collection{
    private:
        dt * array;
        int size;
    public:
        collection(int n);
        collection();
        void show();
        void sort();
};
collection::collection(int n){
    int i;
    size=n;
    array=(dt *)malloc(size*sizeof(dt));
    if (array==NULL)
            return;
    else
        printf("Enter the elements : \n");
        for(i=0 ; i<size ; i++)
                scanf("%d",&array[i]);
}
collection::collection(){
    int i;
    printf("Enter the number of elements you want to enter : \n");
    scanf("%d",&size);
    array=(dt *)malloc(size*sizeof(dt));
    if (array==NULL)
            return;
    else
        printf("Enter the elements : \n");
        for(i=0 ; i<size ; i++)
                scanf("%d",&array[i]);
}
void collection::sort(){
    int i,j;
    dt temp;
    for(i=1 ; i<size ; i++){
            temp=array[i];
            for(j=i-1 ; j>-1 && temp<array[j] ; j--){
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    for(i=0 ; i<size ; i++)
            printf("%d  ",array[i]);
}
void collection::show(){
    int i;
    for(i=0 ; i<size ; i++)
            printf("%d  ",array[i]);
}
int main(){
    collection c1(5);
    c1.sort();
    return 0;
}