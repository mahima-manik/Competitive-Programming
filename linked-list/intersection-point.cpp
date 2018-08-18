#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int m=1, n=1;
    Node* i = head1;
    Node* j = head2;
    while (i->next != NULL)    {
        i = i->next;
        m += 1;
    }
    while (j->next != NULL)    {
        j = j->next;
        n += 1;
    }
    //cout << m << " " << n << "\n";
    i = head1;
    j = head2;
    if (m > n)  {
        for (int k=0; k<m-n; k++)   {
            i = i->next;
        }
    }
    else if (m < n) {
        for (int k=0; k<n-m; k++)   {
            j = j->next;
        }
    }
    
    while (i->data != j->data && i->next != j->next && i != NULL && j != NULL)    {
        //cout << i->data << " " << j->data << endl;
        i = i->next;
        j = j->next;
    }
    if (i->next == NULL || j->next == NULL)
        return -1;
    else 
        return i->next->data;
}