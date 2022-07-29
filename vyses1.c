#include <stdio.h>
#include <stdlib.h>

 struct node{//struct ta x veri bilgisi ve node tanýmlarýz
	int x;
	struct node* next;
};



int main(){
	struct node* root;// node tutacak root tanýmlarýz
	root = (struct node*)malloc(sizeof(struct node));//ilk nodu pointer ile gözsteriz
	root -> x = 10;//ilk eleman
	root -> next = (struct node*)malloc(sizeof(struct node));//ikinci nodu pointer ile gözsteriz
	root -> next -> x = 20;//ikinci eleman
	root -> next -> next  = (struct node*)malloc(sizeof(struct node));//üçüncü nodu pointer ile gözsteriz
	root -> next -> next -> x = 30; //üçüncü eleman eleman
	struct node * iter;//iter tanýmlaýz
	iter = root;//iteri roota atarýz
	printf("%d",iter->x);//ilk iteri yazdýrýrz
	iter = iter -> next;//iteri bir artýrýrýz
	printf("%d",iter->x);//ikinci iteri yazdýrýrz

}
