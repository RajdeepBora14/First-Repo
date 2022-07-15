#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define dt int

class collection
{
    private:
        dt * arr;
        int p,r;
    public:
        collection(int n);
        collection();
        int partition();
        void sort();
        void show();
};
collection::collection(int n)
{
    int i;
    r=n;
    p=0;
    arr=(dt *)malloc(r*sizeof(dt));
    if (arr==NULL)
            return;
    else
        printf("Enter the elements : \n");
        for(i=0 ; i<r ; i++)
                scanf("%d",&arr[i]);
}
collection::collection()
{
    int i;
    p=0;
    printf("Enter the number of elements you want to enter : \n");
    scanf("%d",&r);
    arr=(dt *)malloc(r*sizeof(dt));
    if (arr==NULL)
            return;
    else
        printf("Enter the elements : \n");
        for(i=0 ; i<r ; i++)
                scanf("%d",&arr[i]);
}
int collection::partition()
{
  int x=arr[r];
  int i =p-1;
  int j,temp1,temp2;
  for(j=p ; j<=r-1 ; j++)
  {
    temp1=arr[j];
    if(arr[j]<=x)
    {
      i++;
      arr[j]=arr[i];
      arr[i]=temp1;
    }
    temp2=arr[i+1];
  }
  arr[i+1]=arr[r];
  arr[r]=temp2;
  return (i+1);
}
void collection::sort()
{
  if(p<r)
  {
    int q=partition();
    p=p;
    r=q-1;
    sort();
    r=r;
    p=q+1;
    sort();
  }
}
void collection::show()
{
    int i;
    for(i=0 ; i<r ; i++)
            printf("%d  ",arr[i]);
}
int main()
{
    collection c1(12);
    c1.sort();
    c1.show();
    return 0;
}