#include <stdio.h>
#include <stdlib.h>
#include "bles.h"
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
    root = sil(root,50);
    bastir(root);
    root = sil(root,1000);
    bastir(root);
    root = sil(root,4);
    bastir(root);
    root = sil(root,450);
    bastir(root);

}
