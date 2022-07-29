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
	root = (struct node*)malloc(sizeof(struct node));//rootun ilk düðümünü tanýlarýz
	root -> x = 500;//ilk düðüme 500 deðeri veririz
	struct node * iter;//iter tanýmlaýz
	iter = root;//iteri roota atarýz
	int i = 0;// i degerine 0 atarýz
	for(i=0;i<5;i++){
		iter->next = (struct node*)malloc(sizeof(struct node));//iter ile node eleman ekleme 
		iter=iter->next;//iteri iterin nestine ata
		iter->x = i*10;//for dongüsünde gelen elemaný 10 ile çarpýp
		iter->next = NULL; //iterin nextini null yap
	}
	bastir(root);//bastir fonksiyonunu çalýþtýr root ta olan þeyleri yazdýrýr
		
   

}
