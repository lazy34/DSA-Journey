#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value=this->data;
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
void traverse(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    cout << "Node added successfully in the head" << endl;

    // Traversing the node
    traverse(head);
}

void InsertAtTail(Node *&Tail, Node *&head, int data)
{
    Node *newNode = new Node(data);
    Tail->next = newNode;
    Tail = newNode;
    newNode->next = NULL;

    cout << "Node added successfully in the Tail" << endl;

    // Traversing the node
    traverse(head);
}

void InsertAtAnyPosition(int position, Node *&head, Node *&Tail, int data)
{
    // Finding the length of the linked list
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    // Checking user input valid or not
    if (count < position)
    {
        cout << "User input is out of bound" << endl;
    }

    // Insertion Operation
    // There are three possibilities
    // 1.position is 0th
    // 2.Position is (n-1)th
    // 3.Position is middle of that

    Node *newNode = new Node(data);
    Node *pointer = head;

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        cout << "Node added successfully in the head" << endl;

        // Traversing the node
        traverse(head);
    }
    else if (position == count)
    {
        Tail->next = newNode;
        Tail = newNode;
        newNode->next = NULL;

        cout << "Node added successfully in the Tail" << endl;

        // Traversing the node
        traverse(head);
    }
    else{
        int flag=1;
        while(flag<position)
        {
            pointer=pointer->next;
            flag++;
        }
        newNode->next=pointer->next;
        pointer->next=newNode;


        cout<<"Node added successfully at "<<position<<"th position"<<endl;
        // Traversing the node
        traverse(head);

    }

}

void DeleteAtAnyPosition(int position, Node *&head, Node *&tail){

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    // Checking user input valid or not
    if (count <= position || position < 0)
    {
        cout << "User input is out of bound" << endl;
        return;
    }

    // Deletation Operation
    // There are three possibilities
    // 1.position is 0th
    // 2.Position is (n-1)th
    // 3.Position is middle of that

    if (position == 0)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;

        cout<<position<<"th Node is deleted"<<endl;
        traverse(head);
    }
    else
    {
        Node* prev=NULL;
        Node* curr=head;
        count=0; // Resetting count to 0 since we need to start counting from the beginning
        while (count < position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        if (curr == tail) // Update tail if the last node is deleted
            tail = prev;
        curr->next=NULL;
        delete curr;
        cout<<position<<"th Node is deleted"<<endl;
        traverse(head);
    }
}


int main(int argc, char const *argv[])
{
    Node *node1 = new Node(5);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node *head;
    head = node1;
    // creating a tail
    Node *Tail = node1;
    // Insert a node in the tail
    InsertAtTail(Tail, head, 15);
    InsertAtTail(Tail, head, 69);

    // Insert a node in head
    // InsertAtHead(head,1);
    // InsertAtHead(head,2);
    // InsertAtHead(head,3);

    // Insert at any position
    // Position started at 0th position
    InsertAtAnyPosition(2, head, Tail, 52);
    DeleteAtAnyPosition(3,head,Tail);
    cout<<Tail->data<<endl;

    return 0;
}
