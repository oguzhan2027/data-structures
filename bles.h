#ifndef bles
#define bles
 struct node{//struct ta x veri bilgisi ve node tan�mlar�z
	int x;
	struct node* next;
};
void bastir(struct node *r);
void ekle(struct node *r,int x);
struct node * ekleSirali(struct node *r,int x);
struct node * sil(struct node *r,int x);

#endif
