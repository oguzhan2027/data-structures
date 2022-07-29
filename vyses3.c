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
void ekle(struct node *r,int x){//ekleme fonksiyonu olu�turuyoruz *r ve x parametreleri yaz�yoruz
	while(r->next!=NULL){//r �n nexti null olucaya kadar �al��acak
		r = r->next;
    }
	r->next= (struct node*)malloc(sizeof(struct node));// r �n nextine node ekliyoruz
	r->next->x=x;//r �n nextine data olarak x i koy
	r=r->next->next = NULL;//r �n nextinin nextine Null koyuyoruz her zaman nul olsun
}



int main(){
	struct node* root;// node tutacak root tan�mlar�z
	root = (struct node*)malloc(sizeof(struct node));//rootun ilk d���m�n� tan�lar�z
	root -> next =NULL;
	root -> x = 500;//ilk d���me 500 de�eri veririz
	struct node * iter;//iter tan�mla�z
	iter = root;//iteri roota atar�z
	int i = 0;// i degerine 0 atar�z
	for(i=0;i<5;i++){
		ekle(root, i*10);//ekle fonksiyonunu �al��t�r�rz her gelen i de�erini 10 ile �arpar�z
		
	}
	bastir(root);//bastir fonksiyonunu �al��t�r root ta olan �eyleri yazd�r�r
	//struct node * iter = root;	
	for(i=0;i<3;i++){//araya eleman eklemek i�i d�ng� yaz�yoruz 3. indekse ekleme yapacag�z
		iter = iter -> next;// istedi�imiz yere gelene kadar iteri nextliyoruz
	}
   struct node * temp = (struct node*)malloc(sizeof(struct node));//yeni bir temp ad�nda node olu�turuyoruz
   temp -> next = iter -> next;// tempin nextini iterin nextine at�yoruz
   iter -> next = temp; //iterin nextini tempin nextine at�yoruz
   temp -> x = 100;//tempe de�er olarak 100 veriyoruz
   bastir(root);//yeni �ekilde yazd�rma i�lemi yap�yoruz

}
