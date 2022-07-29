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



int main(){
	struct node* root;// node tutacak root tanýmlarýz
	root = (struct node*)malloc(sizeof(struct node));//rootun ilk düðümünü tanýlarýz
	root -> next =NULL;
	root -> x = 500;//ilk düðüme 500 deðeri veririz
	struct node * iter;//iter tanýmlaýz
	iter = root;//iteri roota atarýz
	int i = 0;// i degerine 0 atarýz
	for(i=0;i<5;i++){
		ekle(root, i*10);//ekle fonksiyonunu çalýþtýrýrz her gelen i deðerini 10 ile çarparýz
		
	}
	bastir(root);//bastir fonksiyonunu çalýþtýr root ta olan þeyleri yazdýrýr
	//struct node * iter = root;	
	for(i=0;i<3;i++){//araya eleman eklemek içi döngü yazýyoruz 3. indekse ekleme yapacagýz
		iter = iter -> next;// istediðimiz yere gelene kadar iteri nextliyoruz
	}
   struct node * temp = (struct node*)malloc(sizeof(struct node));//yeni bir temp adýnda node oluþturuyoruz
   temp -> next = iter -> next;// tempin nextini iterin nextine atýyoruz
   iter -> next = temp; //iterin nextini tempin nextine atýyoruz
   temp -> x = 100;//tempe deðer olarak 100 veriyoruz
   bastir(root);//yeni þekilde yazdýrma iþlemi yapýyoruz

}
