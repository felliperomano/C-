#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
using namespace std;

#define array 10

int soma = 0;
int *pontsoma = &soma;
	
double media = 0;
double *pontmedia = &media;
	
int maior = 0;
int *pontmaior = &maior;

	
void calcmedia(int p[])
{	
	for(int i=0; i<array; i++)
	{		
		*pontsoma += p[i]; 
	}
	
	*pontmedia = (double)*pontsoma/array;
	cout << "M�dia: " << *pontmedia << endl;	
}

void calcmaior(int p[], int media)
{
	cout << "N�meros acima da m�dia: ";
	for(int i=0; i<array; i++)
		
		{
			if (p[i] > media){
				*pontmaior += 1;
				
				cout << p[i] << " ";
			}	
		}
	cout << "\nQuantidade de n�meros acima da m�dia: " << *pontmaior << endl;
}

int main(){
	
	setlocale(LC_ALL,"");
	int *v;
	
		v = (int*)malloc(sizeof(int)*array);
		
		for(int i=0; i<array; i++)
		{
			cin >> v[i];

		}
		
		 calcmedia(v);
		 calcmaior(v, *pontmedia);
		 	 	
free(v);
return 0;
}