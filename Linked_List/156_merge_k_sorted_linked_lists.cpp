#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

class Solution{
    public:
        Node* merge(struct Node* a, struct Node* b){
            
            Node *result=NULL;
            if(a == NULL)
                return b;
            if(b==NULL)
                return a;
            
            if(a->data<=b->data){
                result = a;
                result->next = merge(a->next, b);
            }else{
                result = b;
                result->next = merge(a, b->next);
            }
            return result;
        }
        Node* mergeKLists(struct Node* arr[], int k){
            for(int i=0; i<k-1; i++){
                int j = i+1;
                arr[j] = merge(arr[i], arr[j]);
            }
            return arr[k-1];
        }
};


/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}


int main()
{

    int k;
    cin>>k;
    struct Node *arr[k];
    for(int j=0;j<k;j++)
    {
        int n;
        cin>>n;

        int x;
        cin>>x;
        arr[j]=new Node(x);
        Node *curr = arr[j];
        n--;

        for(int i=0;i<n;i++)
        {
            cin>>x;
            Node *temp = new Node(x);
            curr->next =temp;
            curr=temp;
        }
    }
    Solution obj;
    Node *res = obj.mergeKLists(arr,k);
    printList(res);


	return 0;
}