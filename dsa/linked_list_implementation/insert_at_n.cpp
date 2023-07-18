//to insert numbers at the nth position in  a linked list

#include<bits/stdc++.h>
using namespace std;

struct linked_list
{
    int data;
    linked_list* link;
};

linked_list* head;

void insert_node(int x, int n)
{
    linked_list* temp = new linked_list;
    temp->data = x;
    temp->link = NULL;

    if (n==1)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        linked_list* temp1 = head;
        for (int i=0; i<n-2; i++)
        {
            temp1 = temp1->link;
        }
        temp->link = temp1->link;
        temp1->link = temp;
    }
    
    
}

void delete_node(int no)
{
    linked_list* temp = head;
    if (no==1)
    {
        head = temp->link;
        free(temp);
    }
    else
    {
        for (int i = 0; i < no-2; i++)
        {
            temp = temp->link;
        }
        linked_list* temp1 = temp->link;
        temp->link = temp1->link;
        free(temp1);
    }
}

void reverse_list()
{
    linked_list *curr, *prev, *next;
    curr = head;
    prev = NULL;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    
}


void print_list(int size = 100)
{
    linked_list* temp1 = head;
    if (size = 100)
    {
        while (temp1 != NULL)
        {
            cout<< temp1->data << " ";
            temp1 = temp1->link;    
        }
        
    }



    else
    {
        for (int i=0; i<size; i++)
        {
            cout<< temp1->data <<" ";
            temp1 = temp1->link;
        }
    }
    cout<<endl;

}

void recursion_print(linked_list* in)
{
    if (in == NULL)
    {
        return;
    }
    cout<< in->data<<" ";
    recursion_print(in->link);
}

void reverse_print(linked_list* in)
{
    if (in == NULL)
    {
        return;
    }
    reverse_print(in->link);
    cout<< in->data<<" ";
    
}


void reverse_rec_list(linked_list* in)
{
    if (in->link == NULL)
    {
        head = in;
        return;
    }
    reverse_rec_list(in->link);
    linked_list* p = in->link;
    p->link = in;
    in->link = NULL;
    
    
}


int main()
{
    head = NULL;
    insert_node(2, 1);
    insert_node(3, 2);
    insert_node(4, 3);
    insert_node(5, 2);
    print_list();
    delete_node(4);
    print_list();
    reverse_list();
    print_list();
    recursion_print(head);
    cout<<endl;
    reverse_print(head);
    cout<<endl;
    reverse_rec_list(head);
    print_list();
}