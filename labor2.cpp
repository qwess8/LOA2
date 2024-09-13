// labor2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>



int _tmain(int argc, _TCHAR* argv[])
{

 setvbuf(stdin, NULL, _IONBF, 0);
 setvbuf(stdout, NULL, _IONBF, 0);

 clock_t start = clock(), end; // объявляем переменные для определения времени выполнения

 int i=0, j=0, r, n;
 int elem_c;
 scanf("%d", &n);
 int** a = (int**) malloc(n * sizeof(int*));
 for(int i = 0; i < n; i++)
 {
	 a[i] = (int*) malloc(n * sizeof(int));
 }

 int** b = (int**) malloc(n * sizeof(int*));
 for(int i = 0; i < n; i++)
 {
	 b[i] = (int*) malloc(n * sizeof(int));
 }

 int** c = (int**) malloc(n * sizeof(int*));
 for(int i = 0; i < n; i++)
 {
	 c[i] = (int*) malloc(n * sizeof(int));
 }


 srand(time(NULL)); // инициализируем параметры генератора случайных чисел
 while(i<n)
 {
  while(j<n)
  {
   a[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
   j++;
  }
  i++;
 }
 srand(time(NULL)); // инициализируем параметры генератора случайных чисел
 i=0; j=0;
 while(i<n)
 {
  while(j<n)
  {
   b[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
   j++;
  }
  i++;
 }

 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   elem_c=0;
   for(r=0;r<n;r++)
   {
    elem_c=elem_c+a[i][r]*b[r][j];
    c[i][j]=elem_c;
   }
  }
 }

float t = (float(clock())-start)/float(CLOCKS_PER_SEC);

printf("%f", t);

getchar();
getchar();

	return 0;
}

