#include <stdio.h>
#include <stdlib.h>

 struct node{//struct ta x veri bilgisi ve node tanýmlarýz
	int x;
	struct node* next;
};
void bastir(struct node *r){//bastir fonksiyonu ile linked liste otomatik olarak artýrýr ve deger ekler
	while (r!=NULL){//r null oluncaya kadar çalýþ
		printf("%d ",r->x);//yazdýr
		r=r->next;//r yi nexte ata
	}
}



int main(){
	struct node* root;// node tutacak root tanýmlarýz
	root = (struct node*)malloc(sizeof(struct node));//ilk nodu pointer ile gözsteriz
	root -> x = 10;//ilk eleman
	root -> next = (struct node*)malloc(sizeof(struct node));//ikinci nodu pointer ile gözsteriz
	root -> next -> x = 20;//ikinci eleman
	root -> next -> next  = (struct node*)malloc(sizeof(struct node));//üçüncü nodu pointer ile gözsteriz
	root -> next -> next -> x = 30; //üçüncü eleman eleman
	root -> next -> next ->next = NULL;//en sondaki elemaný null yaparýz
	struct node * iter;//iter tanýmlaýz
	iter = root;//iteri roota atarýz
	printf("%d \n",iter->x);//ilk iteri yazdýrýrz
	iter = iter -> next;//iteri bir artýrýrýz
	printf("%d \n",iter->x);//ikinci iteri yazdýrýrz
	iter = root;//iteri tekrar ilk roota atarýz
	int i = 0;// i degerine 0 atarýz
	while(iter->next != NULL){// döngüde iterin nexti null oluncaya kadar çalýþtýrýrz
		i++;//i yi bir artýrýrýz
		printf("%dinci eleman : %d \n",i,iter->x);//elamaný yazdýrýrz
		iter = iter ->next;//iteribir sonraki node atarýz
	}
	for(i=0;i<5;i++){
		iter->next = (struct node*)malloc(sizeof(struct node));//iter ile node eleman ekleme 
		iter=iter->next;//iteri iterin nestine ata
		iter->x = i*10;//for dongüsünde gelen elemaný 10 ile çarpýp
		iter->next = NULL; //iterin nextini null yap
	}
	bastir(root);//bastir fonksiyonunu çalýþtýr root ta olan þeyleri yazdýrýr
		
   

}
