#include <iostream>
#include <math.h>
using namespace std;

//1ST CLASS
class AdjMatrix
{
    public:
        AdjMatrix();
        AdjMatrix(int nodes_strength,int entries);
        ~AdjMatrix();
        void set_weight(int in_vertex,int out_vertex);//,float indi_weight);
        friend istream & operator>>(istream & in,AdjMatrix & mat)
        {

            int i,in_node,out_node,node_count=0;
            float ind_weight;
            cout<<"ENTER THE NODES AND THEIR CORRESPONDING WEIGHTS!"<<endl;
            cout<<"THE NODES CAN RANGE FROM  0 TO "<<mat.nodes-1<<"."<<endl;
            cout<<endl;
            for(i=0; i<mat.entries ; i++)
            {
                node_count++;
                cout<<"ENTRY #"<<node_count<<endl;
                cout<<"Enter the starting node : ";
                cin>>in_node;
                cout<<"Enter the ending node : ";
                cin>>out_node;
                /*cout<<"Enter the weight : ";
                cin>>ind_weight;*/
                cout<<endl;
                mat.set_weight(in_node,out_node);
            }
        }
        friend ostream & operator <<(ostream & out,AdjMatrix & mat)
        {

            int i,no_of_nodes=mat.nodes;
            int matrix_order=no_of_nodes*no_of_nodes;
            cout<<"The graph is as follows : "<<endl;
            for(i=0 ; i<matrix_order ; i++)
            {
                cout<<" "<<mat.weight[i];
                if ((i+1)%mat.nodes==0)
                    cout<<endl;
            }
        }
    private:
        int nodes;
        int entries;
        float *weight;
}; 

AdjMatrix::AdjMatrix()
{
    nodes=2;
    entries=2;
    int i,matrix_order=nodes*nodes;
    weight=(float *)malloc(sizeof(float)*nodes*nodes);
    for(i=0 ; i<matrix_order ; i++)
    {
        weight[i]=0;
    }
}

AdjMatrix::AdjMatrix(int nodes_strength,int ent)
{
    int i,matrix_order=nodes_strength*nodes_strength;
    entries=ent;
    nodes=nodes_strength;
    weight=(float *)malloc(sizeof(float)*matrix_order);
    for(i=0 ; i<matrix_order ; i++)
    {
        weight[i]=0;
    }
}

AdjMatrix::~AdjMatrix()
{
    free(weight);
}

void AdjMatrix::set_weight(int in_vertex,int out_vertex)
{
    if (in_vertex!=out_vertex && in_vertex<nodes && out_vertex<nodes)
    {
        weight[(in_vertex*nodes)+out_vertex]=1;
    }
}

int main()
{
    AdjMatrix a1(3,4);   //first parameter gives no of nodes in the graph
                         //second parameter gives no of edges in the graph   
    cin>>a1;
    cout<<a1<<endl;
    return 0;
}