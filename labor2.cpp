// labor2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void shell(int *items, int count)
{

  int i, j, gap, k;
  int x, a[5];

  a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

  for(k=0; k < 5; k++) {
    gap = a[k];
    for(i=gap; i < count; ++i) {
      x = items[i];
      for(j=i-gap; (x < items[j]) && (j >= 0); j=j-gap)
        items[j+gap] = items[j];
      items[j+gap] = x;
    }
  }
}

void qs(int *items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;



  i = left; j = right;

  /* выбор компаранда */
  x = items[(left+right)/2];
  
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;

    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
}

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 50000;
	int arr[50000];
	float time;

	setlocale(LC_ALL, "Rus");
	printf("Набор случайных чисел\n");
	for(int i = 0;i<n;i++){//случайные числа
		arr[i] = rand()%10;
	}
	clock_t start = clock();
	shell(arr, n);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("shell: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = rand()%10;
	}
	start = clock();
	qs(arr, 0, n-1);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qs: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = rand()%10;
	}
	start = clock();
	qsort(arr, n,sizeof(int),compare);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qsort: %f\n", time);

	printf("\nНабор возрастающиx чисел\n");
	for(int i = 0;i<n;i++){//возрастающий набор
		arr[i] = i;
	}
	start = clock();
	shell(arr, n);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("shell: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = i;
	}
	start = clock();
	qs(arr, 0, n-1);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qs: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = i;
	}
	start = clock();
	qsort(arr, n,sizeof(int),compare);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qsort: %f\n", time);

	printf("\nНабор убывающиx чисел\n");
	for(int i = 0;i<n;i++){//убывающий набор
		arr[i] = n - i;
	}
	start = clock();
	shell(arr, n);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("shell: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = n - i;
	}
	start = clock();
	qs(arr, 0, n-1);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qs: %f\n", time);


	for(int i = 0;i<n;i++){
		arr[i] = n - i;
	}
	start = clock();
	qsort(arr, n,sizeof(int),compare);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qsort: %f\n", time);

	printf("\nЛевая половина массива возрастает, а правая убывает\n");
	for(int i = 0;i<n;i++){//левая половина возрастает, а правая убывает
		if(i<n/2){
			arr[i] = i;
		}
		else arr[i] = n - i;
	}
	start = clock();
	shell(arr, n);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("shell: %f\n", time);

	
	printf("qs: Недостаточно памяти\n");

	for(int i = 0;i<n;i++){
		if(i<n/2){
			arr[i] = i;
		}
		else arr[i] = n - i;
	}
	start = clock();
	qsort(arr, n,sizeof(int),compare);
	time = (float(clock())-start)/float(CLOCKS_PER_SEC);
	printf("qsort: %f\n", time);

	getchar();
	return 0;
}

