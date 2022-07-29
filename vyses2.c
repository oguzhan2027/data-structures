#include <stdio.h>
#include <stdlib.h>

 struct node{//struct ta x veri bilgisi ve node tan�mlar�z
	int x;
	struct node* next;
};
void bastir(struct node *r){//bastir fonksiyonu ile linked liste otomatik olarak art�r�r ve deger ekler
	while (r!=NULL){//r null oluncaya kadar �al��
		printf("%d ",r->x);//yazd�r
		r=r->next;//r yi nexte ata
	}
}



int main(){
	struct node* root;// node tutacak root tan�mlar�z
	root = (struct node*)malloc(sizeof(struct node));//ilk nodu pointer ile g�zsteriz
	root -> x = 10;//ilk eleman
	root -> next = (struct node*)malloc(sizeof(struct node));//ikinci nodu pointer ile g�zsteriz
	root -> next -> x = 20;//ikinci eleman
	root -> next -> next  = (struct node*)malloc(sizeof(struct node));//���nc� nodu pointer ile g�zsteriz
	root -> next -> next -> x = 30; //���nc� eleman eleman
	root -> next -> next ->next = NULL;//en sondaki eleman� null yapar�z
	struct node * iter;//iter tan�mla�z
	iter = root;//iteri roota atar�z
	printf("%d \n",iter->x);//ilk iteri yazd�r�rz
	iter = iter -> next;//iteri bir art�r�r�z
	printf("%d \n",iter->x);//ikinci iteri yazd�r�rz
	iter = root;//iteri tekrar ilk roota atar�z
	int i = 0;// i degerine 0 atar�z
	while(iter->next != NULL){// d�ng�de iterin nexti null oluncaya kadar �al��t�r�rz
		i++;//i yi bir art�r�r�z
		printf("%dinci eleman : %d \n",i,iter->x);//elaman� yazd�r�rz
		iter = iter ->next;//iteribir sonraki node atar�z
	}
	for(i=0;i<5;i++){
		iter->next = (struct node*)malloc(sizeof(struct node));//iter ile node eleman ekleme 
		iter=iter->next;//iteri iterin nestine ata
		iter->x = i*10;//for dong�s�nde gelen eleman� 10 ile �arp�p
		iter->next = NULL; //iterin nextini null yap
	}
	bastir(root);//bastir fonksiyonunu �al��t�r root ta olan �eyleri yazd�r�r
		
   

}
