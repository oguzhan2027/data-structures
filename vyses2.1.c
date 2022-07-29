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
	root = (struct node*)malloc(sizeof(struct node));//rootun ilk d���m�n� tan�lar�z
	root -> x = 500;//ilk d���me 500 de�eri veririz
	struct node * iter;//iter tan�mla�z
	iter = root;//iteri roota atar�z
	int i = 0;// i degerine 0 atar�z
	for(i=0;i<5;i++){
		iter->next = (struct node*)malloc(sizeof(struct node));//iter ile node eleman ekleme 
		iter=iter->next;//iteri iterin nestine ata
		iter->x = i*10;//for dong�s�nde gelen eleman� 10 ile �arp�p
		iter->next = NULL; //iterin nextini null yap
	}
	bastir(root);//bastir fonksiyonunu �al��t�r root ta olan �eyleri yazd�r�r
		
   

}
