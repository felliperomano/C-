#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <locale.h>
using namespace std;

#define LINHA 3
#define COLUNA 3

void exibematrizes(int **x, int **y){
int i;
int j;

cout << "\n\nMatriz 1" << setw(21) << "Matriz 2" << endl;
	for(i=0; i<LINHA; ++i)
		{
		    for(j=0; j<COLUNA; ++j)
		    {
	            cout << x[i][j] << " | ";
			} 
			
			cout << setw(10);
			
		    for(j=0; j<COLUNA; ++j)
		    {
	            cout << y[i][j] << " | ";
			}
			cout << endl; 
		}	
	}

void compara_matrizes(int **x, int **y){
int comparador = 1;	
	for(int i=0; i<LINHA; ++i)
	{
		
	    for(int j=0; j<COLUNA; ++j)
	    {
            if(x[i][j] != y[i][j]){
				comparador = 0;
			}
		} 

	}	
	cout << endl;
	if (comparador == 1){
		cout << "As matrizes são iguais";
	}
	else{
		cout << "As matrizes não são iguais";
	}
}

void popmatrizes(int **x, int **y){
	cout << "Preencha a primeira matriz: " << endl;
	
		for(int i=0; i<LINHA; ++i)
		{
			x[i] = new int[COLUNA];
			for(int j=0; j<COLUNA; ++j)
		    {
		    	cin >> x[i][j];
		    	
		    }
		}

	cout << "Preencha a segunda matriz: " << endl;	
	
		for(int i=0; i<LINHA; ++i)
		{
			y[i] = new int[COLUNA];
			for(int j=0; j<COLUNA; ++j)
		    {
		    	cin >> y[i][j];
		    		
		    }
		}
}

int main()
{
	setlocale(LC_ALL,"");
   	
	int **matriz1;
	int **matriz2;
	
	matriz1 = new int*[LINHA];
	matriz2 = new int*[LINHA];
	
	popmatrizes(matriz1, matriz2);
	exibematrizes(matriz1, matriz2);
	compara_matrizes(matriz1, matriz2);
	
	
delete[] matriz1;	
delete[] matriz2;
return 0;
}