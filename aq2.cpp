#include<iostream> 
using namespace std; 
struct Node{ 
int data; 
Node* next; 
}; 
void display(Node* head) { 
Node* temp = head; 
    while (temp != NULL) { 
        cout << temp->data; 
        if (temp->next != NULL) cout << "->"; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
int deleteOccurrences(Node*& head,int key){ 
         int count=0; 
         // Case 1: If key is at head 
    while (head != NULL && head->data == key) { 
        Node* temp = head; 
        head = head->next; 
        delete temp; 
        count++; 
    } 
    Node* current = head; 
    while (current != NULL && current->next != NULL) { 
        if (current->next->data == key) { 
            Node* temp = current->next; 
            current->next = current->next->next; 
            delete temp; 
            count++; 
        } else { 
            current = current->next; 
        } 
    } 
 
    return count; 
} 
int main() { 
    // Manually creating linked list: 1->2->1->2->1->3->1 
    Node* head = new Node{1, NULL}; 
    head->next = new Node{2, NULL}; 
    head->next->next = new Node{1, NULL}; 
    head->next->next->next = new Node{2, NULL}; 
    head->next->next->next->next = new Node{1, NULL}; 
    head->next->next->next->next->next = new Node{3, NULL}; 
    head->next->next->next->next->next->next = new Node{1, NULL}; 
 
    cout << "Original Linked List: "; 
    display(head); 
 
    int key = 1; 
    int count = deleteOccurrences(head, key); 
 
    cout << "Count: " << count << endl; 
    cout << "Updated Linked List: "; 
    display(head); 
 
    return 0; 
}
