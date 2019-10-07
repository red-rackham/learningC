/* Let's have some crazy fun with pointers!
 * author: crazy rackham (the red)
 * date: 08.04.2019
 */


#include <stdio.h>

int double_that_p(int *i);
int double_that_v(int i);
int main() {
	int v = 16;
	int *p = &v;
	printf("--------pointer p points to variable v---------\n");
	printf("value of variable v:\t\t%d\n", v);
	printf("value of pointer p:\t\t%d\n", *p);
	printf("address where p points to:\t%p\n", p);
	printf("address of v:\t\t\t%p\n", &v);
	printf("address of pointer p:\t\t%p\n", &p);

	printf("--------pointer p points to array 'arr'---------\n");
//	int arr[10] = {0,1,2,3,4,5,6,7,,9};
	char arr[10] = {'a','a','a','a','a','a','a','a','a','a'};

	int *pntarr = &arr;
	printf("%p\n", &arr);
	printf("%p\n", pntarr);
	for(int i = 0; i<10; i++)
		printf("%p\n", &arr[i]);


	printf("-------- pass pointers to other functions ---------\n");

	int a = 5;
	int* ap = &a;

	printf("value of variabe a is set to:%d\n",a);
	printf("address of variabe a is:%p\n", &a);
	printf("pointer ap points to value: %d\n", *ap);
	printf("address of pointer ap : %p\n", &ap);
/*
	p_handler(a, a);
	printf("%d\n", a);
	p_handler(ap, ap);
	printf("%d\n", a);
	p_handler(&a, &a);
	printf("%d\n", a);
	p_handler(&ap, &ap);
	printf("%d\n", a);
*/
	double_that_p(&a);
	printf("%d\n", a);

	double_that_p(ap);
	printf("%d\n", a);

	double_that_v(ap);
	printf("%d\n", a);

	
	printf("--------- more fun ---------\n");

	int k = 10;
	int *l = &k;


	printf("before\n");
	printf("%d\n", k);
	printf("%d\n", l);
	printf("%d\n", *l);
	
	pass_ptr(l);
	printf("after\n");
	printf("%d\n", k);
	printf("%d\n", *l);

	printf("--------- more fun ---------\n");
	
	


}

int pass_ptr(int *i) {

	int *m = i;
//	m = i;
	*m = *m *2;

	printf("in function\n");
	printf("%d\n", *m );
	printf("%d\n", *i);
}

int double_that_v(int i){
	i = i * 2;
	printf("%d\n", i);
}

int double_that_p(int *i) {
	printf("in function before operation: value of passed pointer:%d\n", *i);
	printf("in function before operation: address of passed pointer:%p\n", &i);
	*i = *i * 2;
	printf("in function after operation: value of passed pointer:%d\n", *i);
	printf("in function after operation: address of passed pointer:%p\n", &i);
}


int p_handler(int *i, int j) {
	printf("%d\t%d\n", *i++, j++);
	
}
