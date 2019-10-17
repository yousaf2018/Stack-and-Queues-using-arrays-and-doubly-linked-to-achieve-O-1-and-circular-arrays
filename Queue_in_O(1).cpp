#include <iostream>
#include <fstream>
using namespace std;
class Node
{
private:
int data;
Node *Next;
Node *Previous;
public:
Node(int);
void set_Next(Node*);
Node* get_Next();
void set_Previous(Node*);
Node* get_Previous();
void set_data(int);
int get_data();
};
class Doubly_link_list
{
private:
Node *first;
Node *back;
public:
Doubly_link_list();
Node* get_first();
void set_first(Node*);
void set_front(Node*);
void set_back(Node*);
Node* get_back();
Node* get_front();
void add_node_end_list(int);
void add_node_start_list(int);
void remove_node_from_start();
void remove_node_end_list();
void find_length_of_list();
void display_list();
};
class Queue
{
private:
Doubly_link_list list;
public:
void enqueue(int);
void dequeue();
void display_front();
void display_back();
int find_value_return_index(int);
void reverse_queue();
void display();
int size_of_queue();
};
Node::Node(int data)
{
        this->data=data;
        Next=NULL;
        Previous=NULL;
}
void Node::set_Next(Node* temp)
{
        Next=temp;
}
Node* Node::get_Next()
{
        return Next;
}
void Node::set_Previous(Node* temp)
{
        Previous=temp;
}
Node* Node::get_Previous()
{
        return Previous;
}
void Node::set_data(int data)
{
        this->data=data;
}
int Node::get_data()
{
        return data;
}
Doubly_link_list::Doubly_link_list()
{
        first=NULL;
}
void Doubly_link_list::add_node_end_list(int input)
{
        Node *temp=new Node(input);
        Node *temp2=first;
        Node *temp3;
        if(temp2==NULL)
        {
                first=temp;
        }
        else
        {
                while(temp2->get_Next()!=NULL)
                {
                        temp2=temp2->get_Next();
                }
                temp2->set_Next(temp);
                temp3=temp2->get_Next();
                temp3->set_Previous(temp2);
        }
}
void Doubly_link_list::add_node_start_list(int input)
{
        Node *temp=new Node(input);
        Node *temp2=first;
        if(temp2==NULL)
        {
                first=temp;
        }
        else
        {
                temp->set_Next(temp2);
                temp2->set_Previous(temp);
                first=temp;
        }
}
void Doubly_link_list::remove_node_from_start()
{
        if(first==NULL)
        {
                cout << "List is empty\n";
        }
        else
        {
                if(first->get_Next()==NULL)
                {
                        first=NULL;
                }
                else
                {
                        first=first->get_Next();
                        first->set_Previous(NULL);
                }
        }
}
void Doubly_link_list::remove_node_end_list()
{
        Node *temp;
        temp=first;
        if(first==NULL)
        {
                cout << "List is empty\n";
        }
        else if(first->get_Next()==NULL)
        {
                first=NULL;
        }
        else if(first!=NULL)
        {
                while(temp->get_Next()->get_Next()!=NULL)
                {
                        temp=temp->get_Next();
                }
                temp->set_Next(NULL);
        }
}
void Doubly_link_list::find_length_of_list()
{
        Node *temp=first;
        int counter=0;
        while(temp!=NULL)
        {
                counter++;
                temp=temp->get_Next();
        }
        cout << "Total length of your list " << counter << endl;
}
void Doubly_link_list::display_list()
{
        Node *temp=first;
        if(first==NULL)
        {
                cout << "List is empty\n";
        }
        while(temp!=NULL)
        {
                cout << temp->get_data() << endl;
                temp=temp->get_Next();
        }
/*  while(temp!=NULL)
   {
   cout << temp->get_data() << endl;
   temp=temp->get_Previous();
   }
 */
}
Node* Doubly_link_list::get_first()
{
        return first;
}
void Doubly_link_list::set_first(Node *ptr)
{
        first=ptr;
}
void Doubly_link_list::set_back(Node *ptr)
{
        back=ptr;
}
Node* Doubly_link_list::get_back()
{
        return back;
}
int Queue::find_value_return_index(int input)
{
        int check=0,counter=1;
        Node *temp;
        temp=list.get_first();
        if(temp==NULL)
        {
                return -1;
        }
        else if(temp->get_data()==input)//for first node
        {
                return 0;
        }
        else
        {
                while(temp!=NULL)
                {
                        if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to find last node
                        {
                                return counter;
                                break;
                        }
                        else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)   //for find middle node
                        {
                                return counter;
                                break;
                        }
                        else if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()!=input)//for warn no matach is found
                        {
                                return -1;
                                break;
                        }
                        temp=temp->get_Next();
                        counter++;
                }
        }
}
void Queue::enqueue(int input)
{
        Node *temp=new Node(input);
        Node *ptr;
        Node *temp1=list.get_first();
        Node *temp2=list.get_back();
        if(temp1==NULL)
        {
                list.set_back(temp);
                list.set_first(list.get_back());
        }
        else
        {
                temp2->set_Next(temp);
                ptr=temp2->get_Next();
                ptr->set_Previous(temp2);
                temp2=temp2->get_Next();
                list.set_back(temp2);
        }
}
void Queue::dequeue()
{
        list.remove_node_from_start();
}
void Queue::display()
{
        list.display_list();
}
void Queue::display_front()
{
        if(list.get_first()==NULL)
        {
                cout << "List is empty\n";
        }
        else
        {
                cout << "Front value is -> " << list.get_first()->get_data() << endl;
        }
}
void Queue::display_back()
{
        Node *temp=list.get_first();
        if(temp==NULL)
        {
                cout << "List is empty\n";
        }
        else
        {
                while(temp->get_Next()!=NULL)
                {
                        temp=temp->get_Next();
                }
                cout << "Back value is -> " << temp->get_data() << endl;
        }
}
void Queue::reverse_queue()
{
        Node *temp=list.get_first();
        Node *temp1=NULL;
        if(temp==NULL)
        {
                cout << "List is empty\n";
        }
        else if(temp->get_Next()==NULL)
        {
                cout << "Only Single node exits in your list\n";
        }
        else
        {
                while(temp!=NULL)
                {
                        temp1=temp->get_Previous(); //to save Previous for swap
                        temp->set_Previous(temp->get_Next());//swap Previous to next
                        temp->set_Next(temp1);//swap nest to Previous
                        temp=temp->get_Previous();//move temp over node for to more swaop
                }
                temp=temp1->get_Previous();//temp1 stores last node after finishing loop
                list.set_first(temp);//to become it head of list
        }
}
int Queue::size_of_queue()
{
        int counter=0;
        Node *temp=list.get_first();
        if(temp==NULL)
        {
                cout << "List is empty\n";
                return 0;
        }
        while(temp!=NULL)
        {
                counter++;
                temp=temp->get_Next();
        }
        return counter;
}
int main()
{
        int option;
        cout << "*********************************************************\n";
        cout << "Enter 1 for using Queue in Doubly linked list\n";
        cout << "*********************************************************\n";
        cin >> option;
        if(option==1)
        {
                Queue object;
                int a,input,choice;
                while(true)
                {
                        cout << "*********************************************************\n";
                        cout << "Enter 1 to Enqueue\n";
                        cout << "Enter 2 to Dequeue\n";
                        cout << "Enter 3 to display front\n";
                        cout << "Enter 4 to display back\n";
                        cout << "Enter 5 to display\n";
                        cout << "Enter 6 to find value\n";
                        cout << "Enter 7 to call reverse Queue\n";
                        cout << "Enter 8 to display size of your Queue\n";
                        cout << "**********************************************************\n";
                        cin >> input;
                        if(input==1)
                        {
                                cout << "Enter value for Enqueue\n";
                                cin >> a;
                                object.enqueue(a);
                        }
                        else if(input==2)
                        {
                                object.dequeue();
                        }
                        else if(input==3)
                        {
                                object.display_front();
                        }
                        else if(input==4)
                        {
                                object.display_back();
                        }
                        else if(input==6)
                        {
                                cout << "Enter value to find its index position\n";
                                int check,data;
                                cin >> data;
                                check=object.find_value_return_index(data);
                                if(check!=-1)
                                {
                                        cout << "Value " << data << " is stored at index " << check << endl;
                                }
                                else if(check==-1)
                                {
                                        cout << "No match is found for your input value\n";
                                }
                        }
                        else if(input==5)
                        {
                                object.display();
                        }
                        else if(input==7)
                        {
                                object.reverse_queue();
                        }
                        else if(input==8)
                        {
                                int check;
                                check=object.size_of_queue();
                                if(check!=0)
                                        cout << "Size of Stack " << check << endl;
                        }
                        cout << "Enter 1 for to continue use functions for Queue or 0 to stop\n";
                        cin >> choice;
                        if(choice!=1)
                        {
                                break;
                        }
                }
        }

}
