#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

        Node(int x){
            data = x;
            next = NULL;
        }

};

// head->1->2->3->4->/

class LinkedList{
    Node *head;

    public:
        LinkedList(){
            head = NULL;
        }

        void insert(int data){
            Node *temp = new Node(data);
            if(head == NULL){
                head = temp;
            }else{
                Node *p = head;
                while(p->next != NULL)
                    p = p->next;
                p->next = temp;
            }
        }  
        void reverse(){
            Node *p, *q, *r;
            p = head;
            q = NULL;
            r = NULL;

            while(p!=NULL){
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            head = q;
        }

        int addTwoLinkedLists(LinkedList l2){
            reverse();
            l2.reverse();
            
            int num1 = 0;
            int num2 = 0;
            int count=0;

            Node*p  = this->head;
            while(p!=NULL){
                num1 = num1 + p->data*pow(10, count);
                p = p->next;
                count++;
            }
            p = l2.head;
            count=0;
            while(p!=NULL){
                num2 = num2 + p->data*pow(10, count);
                p = p->next;
                count++;
            }
            return num1 + num2;
        }    

        void printLL(){
            Node* p = head;
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
        }  
};


int main(){
    LinkedList l1, l2;

    l1.insert(5);
    l1.insert(4);
    l1.insert(2);

    l2.insert(9);
    l2.insert(3);

    cout<<l1.addTwoLinkedLists(l2);

    
}