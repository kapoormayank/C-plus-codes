// Inserting the node for correct position Algorithm Implementation In C++
#include<iostream>
using namespace std;
// class of Doubly Linked List
class Doublyll {
    // Public Access Modifier
    public:
    // Node class of Doubly Linked List
    class Node{
        // Public Access Modifier
        public:
        // Data Members
        int data;
        Node* next;
        Node* prev;
        // Parameterized Constructor
        Node(int data) {
            this->data=data;
            this->next=nullptr;
            this->prev=nullptr;
        }
    };

    Node* head=nullptr;
    Node* tail=nullptr;
    // Function to insert the nodes into doubly linked list
    void insert(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=newNode;
            tail=newNode;
            return;
        }
        else{ 
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    // Function to sort the linked list
    static Node* sorted(Node* head) {
        if(head == nullptr || head->next == nullptr)
        return head;
        Node* i;
        Node* j;
        for(i = head; i->next != nullptr; i = i->next) {
            for(j = i->next; j != nullptr; j = j->next) {
                if(i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        return head;
    }

    // Function to insert the node at right position
    void insertNode(int data) {
        Node* newNode=new Node(data);
        if(head == nullptr) {
            head=tail=newNode;
            return;
        }
        if(data <= head->data) {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next != nullptr && temp->next->data < data) {
            temp=temp->next;
        }
        // Insert after temp
        newNode->next=temp->next;
        temp->next=newNode;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }else {
            tail=newNode; // Update tail if inserted at end
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    // Function to display yhe doubly linked list
    void display() {
        if(head == nullptr) {
            cout<<"Empty Doubly Linked List!!!!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp != nullptr) {
            cout<<temp->data<<"<-->";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

// Main function
int main() {
    Doublyll* list=new Doublyll();
    int n,values;
    cout<<"Enter number of terms: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++) {
        cin>>values;
        list->insert(values);
    }
    cout<<"Display the Doubly Linked List: ";
    list->display();
    Doublyll::Node* head=list->sorted(list->head);
    cout<<"Display after sorted Doubly Linked List: ";
    list->display();
    cout<<"Enter node for inserting into doubly linked list: ";
    cin>>values;
    list->insertNode(values);
    cout<<"After inserting the doubly linked list: ";
    list->display();
    return 0;
}
