//to insert numbers at the beginning of a linked list

#include<bits/stdc++.h>
using namespace std;

struct linked_list
{
    int data;
    linked_list* link;
};

linked_list* head;

void insert_node(int x)
{
    
    linked_list* temp = new linked_list;
    cout<< head->data<<endl;
    temp->data = x;
    temp->link = head;
    head = temp;
    cout<<x<<endl;
}

void print_list()
{
    linked_list* temp1 = head;
    while (temp1 != nullptr)
    {
        cout<< temp1->data<< " ";
        temp1 = temp1->link;
    }
    

}
int main()
{
    head = new linked_list;
    cout<< "Enter the first number"<<endl;
    int var;
    cin>>var;
    head->data = var;
    head->link = nullptr;
    cout<<"Linked List contains "<< head->data <<endl;
    cout<<"How many more numbers do you want in the list"<<endl;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>var;
        cout<<"hi";
        insert_node(var);
    }
    print_list();
}