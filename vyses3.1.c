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
void ekle(struct node *r,int x){//ekleme fonksiyonu oluþturuyoruz *r ve x parametreleri yazýyoruz
	while(r->next!=NULL){//r ýn nexti null olucaya kadar çalýþacak
		r = r->next;
    }
	r->next= (struct node*)malloc(sizeof(struct node));// r ýn nextine node ekliyoruz
	r->next->x=x;//r ýn nextine data olarak x i koy
	r=r->next->next = NULL;//r ýn nextinin nextine Null koyuyoruz her zaman nul olsun
}

struct node * ekleSirali(struct node *r,int x){//sirali ekleme fonksiyonu oluþturuyoruz *r ve x parametreleri yazýyoruz
	if(r==NULL){//r ýn null olup olmadýðý kontrolü yapýlyýor
		r = (struct node*)malloc(sizeof(struct node));//r null sa yeni bir node oluþturuluyor
		r->next = NULL;//r ýn nextini null olarak atýyoruz
		r -> x = x; //r ýn deðerini veriyoruz
		return r;
	}
	if(r->x>x){//rootun x deðeri yeni eklemeye çalýþtýðým deðerden küçükse kutunun baþýna eklemeli root deðiþiyor
				struct node * temp = (struct node*)malloc(sizeof(struct node));// temp oluturup yeni noda atýyoruz
				temp -> x = x;//tempin deðerini x olarak atýyoruz
				temp -> next = r;// tempin nexti root oldu
				return temp;
			}
	struct node * iter =r;
	while(iter->next!=NULL && iter->next->x< x){	//listenin sonuna gelmediyse ve baktýðým eleman eklemeye çalýþtýðým deðerden kuçukse bir sonraki deðere gitmeli
			iter = iter->next;
    }
    	
    struct node * temp = (struct node*)malloc(sizeof(struct node));//yeni bir temp adýnda node oluþturuyoruz
	temp ->next = iter->next;
	iter->next = temp;
	temp -> x = x;
	return r;
}


int main(){
	int i;
	struct node* root;// node tutacak root tanýmlarýz
	root = NULL;//rootu nulla atarýz
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
    bastir(root);//yeni þekilde yazdýrma iþlemi yapýyoruz

}
