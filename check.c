#include<stdio.h>


int global_1;
int global_2;
const int global_3=5;


int test(int para)
{
        int f=0,s=0, diff,i;
        int l_var;
        f=f|(int)(&para);
        s=s|(int)(&l_var);
        diff=f-s;
        printf("This is one useless function \n");
L1:     for(i=1;i<100;i++)
                i=i+1;
        printf("para=%x\nL_var=%x\n",&para,&l_var);
        printf("Diff=%d\n", diff);
return 0;
}




int another(int parameter)
{
        int f=0,s=0, diff,i;
        int another_var;
        printf("%x byte system\n",sizeof(int));
        f=f|(int)(&parameter);
        s=s|(int)(&another_var);
        diff=f-s;
        printf("This is Another useless function \n");
L2:     for(i=1;i<100;i++)
                i=i<<1;
        printf("parameter=%x\nanother_var=%x\n",&parameter,&another_var);
        printf("Diff=%d\n", diff);
return 0;
}




int main()
{
        int local_1;
        int local_2;
        static int local_3;
        test(local_1);
        another(local_2);
        printf("global_1=%x\nglobal_2=%x\nglobal_3=%x\n",&global_1,&global_2,&global_3);
        printf("local_1=%x\n",&local_1);
        printf("local_2=%x\n",&local_2);
        printf("Local_3=%x\t",&local_3);
        return 0;
}