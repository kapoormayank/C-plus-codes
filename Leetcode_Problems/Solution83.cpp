// Leet Code Problem 83: Remove Duplicate from Sorted List
#include<iostream>
using namespace std;

// Node class
class ListNode{
    // Default Access Modifier And Data Memebers
    public:
    int val;
    ListNode* next;
    // Parameterized Constructor
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
};
class Solution83{
    public:
    ListNode* head=nullptr;
    // Method of insert the node element in singly linked list
    void insert(int val){
        ListNode* newNode=new ListNode(val);
        if(head == nullptr){
            head=newNode;
        }else{
            ListNode* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    
    // Method of remove duplicate the node element from singly linked list
    void deleteDuplicates() {
        ListNode* temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->val == temp->next->val){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }
        }
    }
    
    // Method to display the linked list
    void display(){
        if(head == nullptr){
            cout<<"Empty Singly Linked List!!!"<<endl;
        }else{
            ListNode* temp=head;
            while(temp!=nullptr){
                cout<<temp->val<<"-->";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
    }
    
};
// Main function
int main(){
    Solution83 list;
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    cout<<"Enter node elements: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        list.insert(value);
    }
    cout<<"Original Singly Linke List: ";
    list.display();
    list.deleteDuplicates();
    cout<<"After deletion the duplicate node elements from singly linked list: ";
    list.display();
}
