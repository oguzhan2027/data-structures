#include <stdio.h>
#include <stdlib.h>

 struct node{//struct ta x veri bilgisi ve node tan�mlar�z
	int x;
	struct node* next;
};



int main(){
	struct node* root;// node tutacak root tan�mlar�z
	root = (struct node*)malloc(sizeof(struct node));//ilk nodu pointer ile g�zsteriz
	root -> x = 10;//ilk eleman
	root -> next = (struct node*)malloc(sizeof(struct node));//ikinci nodu pointer ile g�zsteriz
	root -> next -> x = 20;//ikinci eleman
	root -> next -> next  = (struct node*)malloc(sizeof(struct node));//���nc� nodu pointer ile g�zsteriz
	root -> next -> next -> x = 30; //���nc� eleman eleman
	struct node * iter;//iter tan�mla�z
	iter = root;//iteri roota atar�z
	printf("%d",iter->x);//ilk iteri yazd�r�rz
	iter = iter -> next;//iteri bir art�r�r�z
	printf("%d",iter->x);//ikinci iteri yazd�r�rz

}
