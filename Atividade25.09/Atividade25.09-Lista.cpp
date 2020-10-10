#include <iostream>
using  namespace std;

struct No {
	int dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void push(Pilha *p, int v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

int pop(Pilha *p) {
	int ret;
	No *no = p->topo;
	ret = no->dado;
	p->topo = no->prox;
	free(no);
	return ret;
}

void print(Pilha *p) {
	No *no;
	no = p->topo;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------------------" << endl;
}

int last(Pilha *p) {
  int ret;
	No *no;
	no = p->topo;
		ret = no->dado;
    return ret;
}

int count(Pilha *p) {
	int qtde = 0;
	No *no;
	no = p->topo;
	while(no != NULL) {
        qtde++;   
		no = no->prox;
	}
	return qtde;
}

void freePilha(Pilha *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
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
	Pilha *pilhaFloatRev;
	pilhaFloatRev = init();
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
	cout << "Valores Normais: " << endl;	
	print(pilhaFloat);
	cout << "Valores Pares: " << endl;
	print(pilhaFloatPar);
	cout << "Valores Impares: " << endl;	
	print(pilhaFloatImp);
	contagem = 0;
	if(last(pilhaFloatPar) > last(pilhaFloatImp)){
	    while(contagem < 15) {
	        if(!isEmpty(pilhaFloatPar)){
	            push(pilhaFloatRev,last(pilhaFloatPar));
	            pop(pilhaFloatPar);
	        }
	        if(!isEmpty(pilhaFloatImp)){
	            push(pilhaFloatRev,last(pilhaFloatImp));
	            pop(pilhaFloatImp);
	        }
	        contagem++;
	    }
	    
	}
	else{
	    while(contagem < 15) {
	        
            if(!isEmpty(pilhaFloatImp)){
	            push(pilhaFloatRev,last(pilhaFloatImp));
	            pop(pilhaFloatImp);
	        }
	        if(!isEmpty(pilhaFloatPar)){
	            push(pilhaFloatRev,last(pilhaFloatPar));
	            pop(pilhaFloatPar);
	        }
	        contagem++;
	    }
	    
	}
	cout << "Valores Reversos: " << endl;	
	print(pilhaFloatRev);
	freePilha(pilhaFloatPar);
	freePilha(pilhaFloatImp);
	
	return 0;
}