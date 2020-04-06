#include <stdio.h>
/*
typedef struct {
	int num;
	char name[100];
	int cost;
} ProductInfo ;
*/

 struct ProductInfo {
	int num;
	char name[100];
	int cost;
} ;
 int sell(struct ProductInfo *ptr) {
	 printf("struct ProductInfo  function \n");
	 return ptr->cost -= 100;
 }

 int sell1(struct ProductInfo *prd) {
	 printf("sell1 func address %d \n", *prd);
	 return (*prd).cost -10;
 }

 void productSweap(struct ProductInfo *prd1 , struct ProductInfo *prd2) {
	 struct ProductInfo tmp = *prd1;
	 *prd1 = *prd2;
	 *prd2 = tmp;
 }

int main() {

	struct ProductInfo product = { 434312 , "力林 茄扼豪" , 4000 };
	struct ProductInfo product1 = { 2 , "力林 茄扼豪" , 7000 };
	printf("sell1 func %d \n", sell1(&product));
	struct ProductInfo *ptr_product = &product;

	productSweap(&product, &product1);

	printf("%d \n", product.num);
	printf("%s \n", product.name);
	printf("%d \n", product.cost);

	printf("%d \n", sizeof(product));
	printf("%d \n", &product);
	printf("%d \n", ptr_product);
	printf("%d \n", ptr_product->cost);
	printf("%d \n", (*ptr_product).cost);
	printf("%d \n", sell(ptr_product));
	printf("%d \n", (*ptr_product).cost);
}