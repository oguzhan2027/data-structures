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

struct node * ekleSirali(struct node *r,int x){//sirali ekleme fonksiyonu olu�turuyoruz *r ve x parametreleri yaz�yoruz
	if(r==NULL){//r �n null olup olmad��� kontrol� yap�ly�or
		r = (struct node*)malloc(sizeof(struct node));//r null sa yeni bir node olu�turuluyor
		r->next = NULL;//r �n nextini null olarak at�yoruz
		r -> x = x; //r �n de�erini veriyoruz
		return r;
	}
	if(r->x>x){//rootun x de�eri yeni eklemeye �al��t���m de�erden k���kse kutunun ba��na eklemeli root de�i�iyor
				struct node * temp = (struct node*)malloc(sizeof(struct node));// temp oluturup yeni noda at�yoruz
				temp -> x = x;//tempin de�erini x olarak at�yoruz
				temp -> next = r;// tempin nexti root oldu
				return temp;
			}
	struct node * iter =r;
	while(iter->next!=NULL && iter->next->x< x){	//listenin sonuna gelmediyse ve bakt���m eleman eklemeye �al��t���m de�erden ku�ukse bir sonraki de�ere gitmeli
			iter = iter->next;
    }
    	
    struct node * temp = (struct node*)malloc(sizeof(struct node));//yeni bir temp ad�nda node olu�turuyoruz
	temp ->next = iter->next;
	iter->next = temp;
	temp -> x = x;
	return r;
}


int main(){
	int i;
	struct node* root;// node tutacak root tan�mlar�z
	root = NULL;//rootu nulla atar�z
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
    bastir(root);//yeni �ekilde yazd�rma i�lemi yap�yoruz

}
