// Leet Code Problem 328: Odd Even Linked List
#include<iostream>
using namespace std;

class ListNode{
    // Default Access Modifier And Data Memebers
    public:
    int data;
    ListNode* next;
    // Parameterized Constructor
    public:
    ListNode(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class Solution328{
    public:
    ListNode* head=nullptr;
    // Method to insert the elements in linked list
    void insert(int data){
        ListNode* newNode = new ListNode(data);
        if(head == nullptr){
            head = newNode;
        }else{
            ListNode* temp=head;
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    // Method to arrange elements of linked list from the odd-even order
    void oddEvenList() {
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next;
        while(even != nullptr && even->next != nullptr){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
    }

    // Method to display the linked list data
    void display(){
        if(head == nullptr){
            cout<<"Empty Linke List!!!"<<endl;
        }else{
            ListNode* temp=head;
            while(temp != nullptr){
                cout<<temp->data<<"-->";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
    }
};

// Main function 
int main(){
    Solution328 list;
    cout<<"Enter number of terms: ";
    int n,value;
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>value;
        list.insert(value);
    }
    cout<<"Original Linked List: ";
    list.display();
    list.oddEvenList();
    cout<<"After arrangement of elements by odd-even order : ";
    list.display();
    return 0;
}