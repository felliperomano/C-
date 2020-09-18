#include <iostream>
#include <time.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#include <locale.h>
#include <string>

 using namespace std;
 
class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;	
    public:
    	Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
		Data* dia_seguinte()
		{
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			Data *d1 = new Data(this->dia, this->mes, this->ano);
			
			if (d1->ano%4 == 0)
			{
				diasNoMes[1]++;
			}
			
			d1->dia++;
			if (d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			
			return d1;
		}
};

class Contato{
    private:
        string email;
        string nome;
        string dt_nascimento;
        string telefone;

    public: 
    
    
        Contato(string email, string nome, string dt_nascimento, string telefone)
        {
          this->email = email;
          this->nome = nome;
          this->dt_nascimento = dt_nascimento;
          this->telefone = telefone;
        }
        
        Contato()
        {
          this->email, nome, dt_nascimento, telefone = "";
        }
        
        void setEmail(string email){
          this-> email = email;  
        }
        
        void setNome(string nome){
          this-> nome = nome;  
        }

        void setdt_nascimento(string dt_nascimento){
          this-> dt_nascimento = dt_nascimento;  
        }
        
        void setTelefone(string telefone){
          this-> telefone = telefone;  
        }
        
        string getEmail(){
            return this-> email;
        }
        string getNome(){
            return this-> nome;
        }
        
        string getdt_nascimento(){
            return this-> dt_nascimento;
        }
        
        string getTelefone(){
            return this-> telefone;
        }        
        
        string getDados(){
            return "Nome: " + this->nome + "\nEmail: " + this->email + "\nData de Nascimento " + this->dt_nascimento + "\nTelefone: " + this->telefone; 
        }
        
        int getIdade(int day, int month, int year){
  
            time_t mytime;
            mytime = time(NULL);
            struct tm tm = *localtime(&mytime);
            int idade = 0;
            
            if(tm.tm_mon + 1 > month)
            {
             idade = tm.tm_year + 1900 - year;
            }
            else if(tm.tm_mon + 1  == month){
                if(tm.tm_mday >= day){
                    idade = tm.tm_year + 1900 - year;
                }
                else{
                    idade = tm.tm_year + 1900 - year - 1;
                }
            }
            else if (tm.tm_mon + 1 < month){
                idade = tm.tm_year + 1900 - year - 1;
            }
            return idade;
        }
};

int main(int argc, char** argv)
{
	string email[3] = "";
	string nome[3] = "";
	string telefone[3] = "";
    int dia[3];
    int mes[3];
    int ano[3];
    int idade[3];
    int contador = 0;
    int velho = 0;
    int maior = 0;
    double soma = 0;
	double media = 0;
    int maioridade = 18;
    
    for (int i = 0; i < 3; i++) {
    cout << "Contato ";
    cout << i+1 << endl;
    cout << "Digite seu email:";
    cin >> email[i];
    cout << "Digite seu nome:";
    cin >> nome[i];
    cout << "Digite o dia em que voce nasceu:";
    cin >> dia[i];
    cout << "Digite o mes em que voce nasceu:";
    cin >> mes[i];  
    cout << "Digite o ano em que voce nasceu:";
    cin >> ano[i];   
    cout << "Digite o seu telefone:";
    cin >> telefone[i];
    }
    
    //system("cls");
 
    
                
    Data *nascimento = new Data[3];
    Contato *dados = new Contato[3];
    
    for (int i = 0; i < 3; i++) {
    nascimento[i] = Data(dia[i], mes[i], ano[i]);
        
    dados[i] = Contato(""+email[i]+"", ""+nome[i]+"", ""+nascimento[i].getData()+"", ""+telefone[i]+"");
    
    cout << "\n" << dados[i].getDados() << endl; 
    
    cout << "Idade: ";
    idade[i] = dados[i].getIdade(nascimento[i].getDia(), nascimento[i].getMes(), nascimento[i].getAno());
	cout << idade[i] << endl; 
    soma +=idade[i]; 
    }
    media = soma/3;
    cout << "\nMedia de idade dos contatos: " << media << endl;
    cout << "\nContatos com idade maior do que a media: " << endl;
    for (int i = 0; i < 3; i++) {
        
        if(idade[i] > media){
            cout << dados[i].getNome() <<endl;
            contador += 1;
        } 
        
        if ((i == 2) && (contador == 0))
        {
            cout<< "Nenhum" << endl;
        }
        
        if (idade[i] >= maioridade){

            maior+=1;
        }
        
        
        if (idade[i] > velho){
            velho = idade[i];
        }
    }
    

    cout << "\nQuantidade de contatos maiores de idade: " << maior << endl;
    cout << "\nContatos mais velhos: " << endl;
    for (int i = 0; i < 3; i++){
        if (idade[i] == velho){
            cout << dados[i].getNome() <<endl;
            cout << dados[i].getEmail() <<endl;
            cout << dados[i].getTelefone() <<endl;
            cout << "\n";
        }
    }
}