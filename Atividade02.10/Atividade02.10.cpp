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
	Pilha *pilhaFloatAtend;
	pilhaFloatAtend = init();
	int ultimoValor = 0;
	int valorAtual = 0;
	int status = 0;
	
	cout << "Tamanho da fila: " << count(pilhaFloat) << endl;
	cout << "0. Sair." << endl;
	cout << "1. Gerar senha." << endl;
	cout << "2. Realizar atendimento." << endl;
	cin >> status;
	
	while(status != 0) {
	    if(status == 1)
	    {
	        cout << "Senha Adicionada." << endl;
	        valorAtual = valorAtual + 1;
	        push(pilhaFloat, valorAtual);
	    }
	    if(status == 2)
	    {
	        if(isEmpty(pilhaFloat)){
                cout << "Sem senha para atendimento." << endl;
	        }
	        else{
	            ultimoValor = last(pilhaFloat);
	        push(pilhaFloatAtend, ultimoValor);
	        cout << "Atendimento realizado: ";
	        cout << ultimoValor << endl;
	        pop(pilhaFloat);
	        }
	    }
	    cout << "Tamanho da fila: " << count(pilhaFloat) << endl;
        cout << "0. Sair." << endl;
	    cout << "1. Gerar senha." << endl;
	    cout << "2. Realizar atendimento." << endl;
	    cin >> status;
	    while(status == 0 && count(pilhaFloat) > 0){
	        cout << "Não pode finalizar até acabar a fila." << endl;
	        cout << "0. Sair." << endl;
	        cout << "1. Gerar senha." << endl;
	        cout << "2. Realizar atendimento." << endl;
	        cin >> status;
	    }
    }
    
    cout << "Quantidade de senhas atendidas: " << count(pilhaFloatAtend) << endl;

	freePilha(pilhaFloat);
	freePilha(pilhaFloatAtend);
	return 0;
}