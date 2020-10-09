 #include <iostream>
using  namespace std;

#define MAX 50

struct Pilha {
	int qtde;
	int nos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return p->qtde;
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->nos[p->qtde] = v;
		p->qtde++;
	}
	return podeEmpilhar;
}

int pop(Pilha *p) {
	int ret;
	int podeDesempilhar = (p->qtde > 0);
	if (podeDesempilhar) {
		ret = p->nos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void print(Pilha *p) {
	for(int i = p->qtde-1; i >= 0; --i) {
		cout << p->nos[i] << endl;
	} 
	cout << "------------------" << endl;
}

int last(Pilha *p) {
    int ret;
	int i = p->qtde-1;
		ret = p->nos[i];

	return ret;
}

void freePilha(Pilha *p)
{
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	Pilha *pilhaFloatPar;
	pilhaFloatPar = init();
	Pilha *pilhaFloatImp;
	pilhaFloatImp = init();
	int ultimoValor = 0;
	int valorAtual = 0;
	int contagem = 0;
	while(contagem < 30) {
	    if(contagem == 0)
	    {
	        cout << "Digite um valor: ";
	        cin >> valorAtual;
	        push(pilhaFloat, valorAtual);
	    }
	    else
	    {
	        cout << "Digite um valor: ";
	        cin >> valorAtual;
	        ultimoValor = last(pilhaFloat);
	        while(valorAtual < ultimoValor)
	        {
	            if(valorAtual < ultimoValor)
	            {
	                cout << "O valor tem que ser maior que o anterior." << endl;
	            }
	            cout << "Digite um valor: ";
	            cin >> valorAtual;
	        }
	        push(pilhaFloat, valorAtual);
	    }
	    if((valorAtual % 2) == 0 )
	    {
	        push(pilhaFloatPar, valorAtual);
	    }
	    if((valorAtual % 2) != 0 )
	    {
	        push(pilhaFloatImp, valorAtual);
	    }

        contagem++;
    }
	
	cout << "------------------------" << endl;
	cout << "Valores Pares: " << endl;
	print(pilhaFloatPar);
	cout << "Valores Impares: " << endl;	
	print(pilhaFloatImp);
	
	freePilha(pilhaFloatPar);
	freePilha(pilhaFloatImp);
	
	return 0;
}
