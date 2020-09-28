#include <iostream>
using namespace std;

struct Funcionario {
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;
};
Funcionario* init() {
	return NULL;
}
int isEmpty(Funcionario* employee) {
	return (employee == NULL);
}
Funcionario* insert(Funcionario* employee, int i, string nome, double salario) {
	Funcionario* novo = new Funcionario;
	novo->prontuario = i;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = employee;
	return novo;
}
void print(Funcionario* employee){
	double somasalario = 0;
	Funcionario* aux;
	aux = employee;
	while (aux != NULL) {
		cout << "Prontuario: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Salario: " << aux->salario << endl;
		somasalario += aux->salario;
		aux = aux->prox;
		cout << endl;		
	}
	
	cout << "Salario total: " << somasalario << endl;
}
Funcionario* find(Funcionario* employee, int i) {
	Funcionario* aux;
	aux = employee;
	while (aux != NULL && aux->prontuario != i)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		aux = new Funcionario;
		aux->prontuario = -1;
		aux->prox = NULL;
	}
	return aux;
}
Funcionario* remove(Funcionario* employee, int i) {
	Funcionario *ant = NULL;
	Funcionario *aux;
	
	aux = employee;
	
	while (aux != NULL && aux->prontuario != i) {
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL) {
		return employee;
	}
	if (ant == NULL) {
		employee = aux->prox;
	}
	else {
		ant->prox = aux->prox;
	}
	free(aux);
	return employee;
}
void freeList(Funcionario* employee) {
	Funcionario* aux;
	aux = employee;
	
	while(aux != NULL) {
		Funcionario *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}
void exitProgram(int &option) {
		option = 0;
}
int main() {
	Funcionario *funcionario;
	funcionario = init();
	int option;
	int prontuario;
	string nome;
	double salario;		
	while(option != 0) {
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		cout << endl;
		cout << "Opção: ";
		cin >> option;
		system("cls");
		if(option == 1) {
			int verificacao = 0;{
				cout << "Digite o prontuario: ";
				cin >> verificacao;				
				Funcionario* procurado = find(funcionario, verificacao);
				if(procurado->prontuario == verificacao) {
					cout << "Prontuario ja inserido." << endl;
					system("pause");
					system("cls");
					init();
					cout << endl;					
				}
				else{
					prontuario = verificacao;
					cout << "Digite o nome: ";
					cin >> nome;
					cout << "Digite o salario: ";
					cin >> salario;	
				}
			}
		
			funcionario = insert(funcionario, prontuario, nome, salario);	
			prontuario = 0;
			nome = "";
			salario = 0;
			system("cls");
	}
		
		if(option == 2) {
			cout << "Digite o prontuario: ";
			cin >> prontuario;
			funcionario = remove(funcionario, prontuario);
			prontuario = 0;
			system("cls");
		}
		if(option == 3) {
			cout << "Digite o prontuario: ";
			cin >> prontuario;
			cout << endl;
			Funcionario* procurado = find(funcionario, prontuario);
			if (procurado->prontuario > -1) {				
				cout << "  Prontuário: " << procurado->prontuario << endl;
				cout << "  Nome: " << procurado->nome << endl;
				cout << "  Salário: " << procurado->salario << endl;
			
			}
			else if (procurado->prontuario == -1){
				cout << "Não encontrado" << endl;
			}
			prontuario = 0;
			system("pause");
			system("cls");
			init();
		}
		if(option == 4) {
			print(funcionario);
			system("pause");
			system("cls");
			init();
		}
	}
	freeList(funcionario);
	return 0;
}