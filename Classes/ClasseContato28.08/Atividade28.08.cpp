#include <iostream>
#include <time.h>
#include <locale.h>

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
            return this-> dt_nascimento;
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
	setlocale(LC_ALL, "Portuguese");
    string email, nome, telefone = "";
    int dia, mes, ano = 0;	
    
    cout << "Digite seu email:";
    cin >> email;
    cout << "Digite seu nome:";
    cin >> nome;
    cout << "Digite o dia em que você nasceu:";
    cin >> dia;
    cout << "Digite o mes em que você nasceu:";
    cin >> mes;  
    cout << "Digite o ano em que você nasceu:";
    cin >> ano;   
    cout << "Digite o seu telefone:";
    cin >> telefone;
    
    system("cls");
    
    Data *nascimento = new Data(dia, mes, ano);
         
    Contato *dados = new Contato(""+email+"", ""+nome+"", ""+nascimento->getData()+"", ""+telefone+"");
    cout << dados->getDados() << endl; 
    cout << "Idade: ";
    cout << dados->getIdade(nascimento->getDia(), nascimento->getMes(), nascimento->getAno()) << endl; 
	 
	return 0;
}