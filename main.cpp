#include <ctime>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void selection(int *ar, int size)
 {
     int i, j, mx, nmx;

     for(i = 0; i < size-1; i++)
       {
         mx=ar[i];
         nmx=i;
         for(j = i+1; j < size; j++)
           {
             if (ar[j]<mx)
                {
                 mx=ar[j];
                 nmx=j;
                 }
           }
          ar[nmx]=ar[i];
          ar[i]=mx;
           }
     }
void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i]]-1]=ar[i];
         cr[ar[i]]-=1;
      }
  }
int main(){
label1:
	int a;
	setlocale(LC_ALL,"Russian");
	time_t start, end;
	srand(time(NULL));
	int N;
	cout << "\nВведите размер массива: ";
	cin >> N;
	int *a1=new int[N];
	int *b1=new int[N];
	int c[101];
	int tend;
	int tstart;
	for(int i=0;i<N;++i){
	a1[i]=rand()%101;
	}
	//tstart=GetTickCount();
	start = clock();
	selection(a1,N);
	//tend=GetTickCount();
	end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя selection сортировки для массива размерности " << N << ":   " << seconds;
	//cout << "\nВремя selection сортировки для массива размерности " << N << ":   " << tend-tstart << " ms";
	for(int i=0;i<N;++i){
	a1[i]=rand()%101;
	}
	start = clock();
	//tstart=GetTickCount();
	radix(a1,b1,c,100,N);
	//tend=GetTickCount();
	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nВремя radix сортировки для массива размерности " << N << ":   " << seconds;
	//cout << "\nВремя radix сортировки для массива размерности " << N << ":   " << tend-tstart << " ms";
	cout << "\nПовторить?\n1) Да\n2)Нет";
	cin >> a;
	if(a==1)
		goto label1;
	system("pause");
return 0;
}