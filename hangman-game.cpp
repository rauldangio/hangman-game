#include <iostream>

using namespace std;

void limpaTela(int op);


int main(){
	int op,tam,chances,acertos,tamdica;
	char palavra[40],letra[1], palavraSecreta[40], dica[20];
	bool acerto;
	
	acerto = false;
	chances = 6;
	tam = 0;
	acertos = 0;
	tamdica = 0;

	while(true){
		cout << "antes de comecar diga: seu sistema e linux[1] ou windows[2]? ";
		cin >> op;
		if(op == 1 || op == 2){
			break;
		}
	}
	limpaTela(op);
	
	cout << "fale para seu amigo fechar o olho e digite a palavra: ";
	cin >> palavra;
	cout << "agora a dica: ";
	cin >> dica;

	for(int i = 0; i < 40; i++){
		if(palavra[i] != '\0'){
			tam++;
			palavraSecreta[i] = '-';
		}else if(dica[i] != '\0'){
			tamdica++;
		}
	}	
	
	
	limpaTela(op);

	while(chances > 0 && acertos < tam){
		cout << "voce acertou " << acertos << " vezes\n";
		cout << "voce tem " << chances << " chances\n";
		cout << "dica: ";
		for(int i = 0; i < tamdica; i++){
				cout << dica[i];
			
		}		
		cout << "\npalavra Secreta: ";
		for(int i = 0; i < tam; i++){
			cout << palavraSecreta[i];
		}
		

		cout << "\ndigita uma letra: ";
		cin >> letra[0];
		
		for(int i = 0; i < tam; i++){
			if(palavra[i] == letra[0]){
				palavraSecreta[i] = palavra[i];
				acertos++;
				acerto = true;
			}
		}

		if(!acerto){
			chances--;
		}

		limpaTela(op);	
	}
	
	limpaTela(op);

	if(acertos == tam){
		cout << "\nPARABENS VC GANHOU!!!\n";
	}else{
		cout << "\nVoce PERDEU!!!!\n";
	}
}

void limpaTela(int op){
	if(op == 1){
		system("clear");
	}else if(op == 2){
		system("cls");
	}
}
