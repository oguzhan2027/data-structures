
#include<bits/stdc++.h> 
using namespace std; 
  

struct Node //struct tanýmlýyoruz
{ 
    int data; 
    struct Node *next; 
}; 
  
//neew node tanýmlýyoruz dairesel kuyruk için
Node *newNode(int data) 
{ 
   Node *temp = new Node; 
   temp->next = temp; 
   temp->data = data; 
} 
  

   //kalan tek kiþiyi bulacak fonksiyon her m den sonra n düðümdünden oluþan
void getJosephusPosition(int m, int n) 
{ 
    //n boyutlu dairesel linked list oluþturma 
    Node *head = newNode(1); 
    Node *prev = head; 
    for (int i = 2; i <= n; i++) 
    { 
        prev->next = newNode(i); 
        prev = prev->next; 
    } 
    prev->next = head;  
  
   //likned liste son node kalana kadar
    Node *ptr1 = head, *ptr2 = head; 
    while (ptr1->next != ptr1) 
    { 
        //m. nodu bulma
        int count = 1; 
        while (count != m) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->next; 
            count++; 
        } 
  
        //m. nodu silme
        ptr1 = ptr2->next; 
    } 
  
    printf ("son kalan askerin "
            "sirasi %d", ptr1->data); 
} 
  
//main program
int main() 
{ 
    int n = 5, m = 3; 
    getJosephusPosition(m, n); 
    return 0; 
} 
