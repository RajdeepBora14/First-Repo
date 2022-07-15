#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define dt int

class point
{
    private:
        dt *coordinates;
        dt *group;
        dt count=0;
    public:
        point(dt first,dt second,dt third);
        point(dt *rhs);
        point();
        ~point();
        void group_ins();
        void group_del();
        void heapsort(int n);
        void display(); 
};
point::point(dt first,dt second,dt third)
{
    coordinates=(dt *)malloc(3*sizeof(dt));
    coordinates[0]=first;
    coordinates[1]=second;
    coordinates[2]=third;
}

point::point()
{
    coordinates=(dt *)malloc(3*sizeof(dt));
    coordinates[0]=0;
    coordinates[1]=0;
    coordinates[2]=0;
}

point::point(dt *rhs)
{
    int j;
    coordinates=(dt *)malloc(3*sizeof(dt));
    for (j=0 ; j<3 ; j++)
                coordinates[j]=rhs[j];
}

point::~point()
{
	free(coordinates);	
}

void point::heapsort(int n)
{
	int i,temp,temp1,temp2;
	for (i=1 ; i<3; i++)
	{
		if (coordinates[i]>coordinates[(i-1)/2])
		{
			int j=i;
			while (coordinates[j]>coordinates[(j-1)/2])
			{
                temp1=coordinates[j];
                coordinates[j]=coordinates[(j-1)/2];
                coordinates[(j-1)/2]=temp;
				j=(j-1)/2;
			}
		}
	}
	for (int i=3-1 ; i>0 ; i--)
	{
        temp1=coordinates[0];
        coordinates[0]=coordinates[i];
        coordinates[i]=temp1;
		int j=0,index;
		do
		{
			index=(2*j+1);
			if (coordinates[index]<coordinates[index+1] && index<(i-1))
				index++;
			if (coordinates[j]<coordinates[index] && index<i)
                temp2=coordinates[j];
                coordinates[j]=coordinates[index];
                coordinates[index]=temp2;
			j=index;
		} while (index<i);
    }
}

void point::group_ins()
{
}

void point::group_del()
{
}

void point::display()
{
    int i;
    for(i=0 ; i<2 ; i++)
    {
        printf("%d ",coordinates[i]);
    }
    printf("%d     ",coordinates[2]);
}

int main()
{
    point p1(23,45,12);
    point p2(76,4,90);
    p1.display();
    p2.display();
}