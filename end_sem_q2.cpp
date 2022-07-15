#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class CSLinkedList{
	public:
        // include the necessary member functions for solving the above problem
        CSLinkedList()
        {
            Node n1("a"),n2("b"), n3("c"),n4("d");
            head=&n1;
            n1.next=&n2;
            n2.next=&n3;
            n3.next=&n4;
            n4.next=&n1;
            count=5;
        }
        void remove()
        {
            int k=0;
            Node *traverse=head;
            while(k!=count)
            {
                k++;
                traverse=head->next;
            }
        }
        void display()
        {
            Node *trav=head;
            while(trav->next==head)
            {
                cout<<trav->nameOfPerson<<endl;
                trav=trav->next;
            }
        }
    private:
        //nested class
        class Node
        {
        private :
            char *nameOfPerson;
            Node *next;
        public:
            Node(char *name)
            {
                nameOfPerson=new char[strlen(name)+1];
                strcpy(nameOfPerson,name);
                next=NULL;
            }
            friend  class  CSLinkedList;
        };
        Node *head;  // points to the first node of the linked list
        int count;	//  number of nodes in the linked list
};

int main()
{
    CSLinkedList c1();
}