#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define dt float

class n_tuple{
    public:
        n_tuple(int x); //constructor 1
        n_tuple(); //constructor 2
        n_tuple(int n , dt array2 []); //constructor 3

        //member functions
        int lexicography_compare(n_tuple array2);
        void add(n_tuple array2);
        void subtract(n_tuple array2);
        void show();
    private:
        dt *array;
        int size;
};
n_tuple::n_tuple(int x)
{
            int i;
            size=x;
            array=(dt *)malloc(size*sizeof(dt)); 
            if (array==NULL)
            {
                return;
            }
            else
            {
                for(i=0 ; i<size ; i++)
                {
                    array[i]=rand();
                }
            } 
}
n_tuple::n_tuple()
{
    int i;
    size=1;
    array=(dt *)malloc(size*sizeof(dt));
    if(array==NULL)
    {
        return;
    }
    else
    {
        for(i=0 ; i<size ; i++)
        {
            array[i]=rand();
        }        
    }
    for(i=0 ; i<size ; i++)
    {
        array[i]=rand();
    }
}
n_tuple::n_tuple(int n,dt array2 [])
{   
    int i;
    size=n;
    array=(dt *)malloc(size*sizeof(dt)); 
    if (array==NULL)
    {
         return;
    }
    else
    {
        for(i=0 ; i<size ; i++)
        {
            array[i]=array2[i];
        }
    }  
}
int n_tuple::lexicography_compare(n_tuple array2)
{
    int count=0;
    if (size==array2.size)
    {
       while(count!=size)
       {
           if (array[count] < array2.array[count])
           {
               return 2;
           }
           if (array[count] > array2.array[count])
           {
               return 1;
           }
           else{
               count++;
           }
       }
       return 0;     
    }
    else
    {
        return -1;
    }
}
void n_tuple::show()
{
    int i;
    printf("The %d-tuple is as follows : (",size);
    if (size==1)
    {
        printf("%f)\n",array[0]);
    }
    else
    {
        for(i=0 ; i<size-1 ; i++)
        {
            printf("%f,",array[i]);
        }
        printf("%f)\n",array[size-1]);
    }
}
void n_tuple::add(n_tuple array2)
{
    if (size==array2.size)
    {
        int i;
        for(i=0;i<size;i++)
        {
            array[i]+=array2.array[i];
        }
        printf("SUM : (");
        for(i=0 ; i<size-1 ; i++)
        {
            printf("%f,",array[i]);
        }
        printf("%f)\n",array[size-1]);
        }
    else
    {
        printf("THE LENGTHS OF THE ARRAYS ARE DIFFERENT, HENCE CAN'T BE ADDED.\n");
    }
}
void n_tuple::subtract(n_tuple array2)
{
    if (size==array2.size)
    {
        int i;
        for(i=0;i<size;i++)
        {
            array[i]-=array2.array[i];
        }
        printf("DIFFERENCE : (");
        for(i=0 ; i<size-1 ; i++)
        {
            printf("%f,",array[i]);
        }
        printf("%f)\n",array[size-1]);
    }
    else
    {
        printf("THE LENGTHS OF THE ARRAYS ARE DIFFERENT, HENCE CAN'T BE SUBTRACTED.\n");
    }
}

int main()
{
    n_tuple n0(5);
    n0.show();
    n_tuple n1(3);
    n1.show();
    n_tuple n2(3);
    n2.show();

    int a=n1.lexicography_compare(n2);
    if (a==-1)
        printf("LENGTHS OF BOTH THE ARRAYS ARE DIFFERENT. HENCE CAN'T BE COMPARED.\n");
    if (a==0)
        printf("n1 IS EQUAL TO n2.\n");
    if (a==1)
        printf("n1 IS GREATER THAN n2.\n");
    if (a==2)
        printf("n2 IS GREATER THAN n1.\n");

    int b=n0.lexicography_compare(n1);
    if (b==-1)
        printf("LENGTHS OF BOTH THE ARRAYS ARE DIFFERENT. HENCE CAN'T BE COMPARED.\n");
    if (b==0)
        printf("n0 IS EQUAL TO n1.\n");
    if (b==1)
        printf("n0 IS GREATER THAN n1.\n");
    if (b==2)
        printf("n1 IS GREATER THAN n0.\n");

    n0.add(n1);
    n1.add(n2);

    n0.subtract(n1);
    n1.subtract(n2);
    printf("\n");

    printf("LET US CONSTRUCT ANOTHER TUPLE NOW...\n");
    int i,size;
    dt *array2;
    printf("Give a size for the array : \n");
    scanf("%d",&size);
    array2=(dt *)malloc(size*sizeof(dt));
    for(i=0 ; i<size ; i++)
    {
        array2[i]=rand();
    }   
    n_tuple n3(size,array2);
    n3.show();

    return 0;
}