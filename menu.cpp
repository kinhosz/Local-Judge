#ifdef __unix__
	bool os_unix = true;
	bool os_windows = false;
#elif defined(__WIN32) || defined(WIN32)
	bool os_unix = false;
	bool os_windows = true;
#endif

#include <bits/stdc++.h>
using namespace std;

void sleep(int s){

	clock_t start_t,end_t;

	start_t = clock();
	end_t = clock();

	while((end_t - start_t)/CLOCKS_PER_SEC < s){
		end_t = clock();
	}
}

string comandLine(string cl){

	if(os_unix){
		if(cl == "CLEAR") return "clear";
		if(cl == "RUN") return "./";
		if(cl == "SLASH") return "\\";
		if(cl == "DEL") return "rm";
		if(cl == "MKDIR") return "mkdir";
		if(cl == "LIST") return "ls";
	}
	else if(os_windows){
		if(cl == "CLEAR") return "cls";
		if(cl == "RUN") return "";
		if(cl == "SLASH") return "/";
		if(cl == "DEL") return "del /f";
		if(cl == "MKDIR") return "mkdir";
		if(cl == "LIST") return "dir";
	}
	else{
		system("echo sistema nao reconhecido");
		exit(0);
	}

	return cl;
}

vector<string> split(string str,char chr){

	vector<string> ret;
	string aux = "";
	for(int i=0;i<str.size();i++){
		if(str[i] == chr){
			ret.push_back(aux);
			aux = "";
		}
		else{
			aux += str[i];
		}
	}

	ret.push_back(aux);

	return ret;
}

vector<string> repl(vector<string> vs){

	for(int i=0;i<vs.size();i++){

		vs[i] = comandLine(vs[i]);
	}

	return vs;
}

string merge(vector<string> vs){

	string ret = "";

	for(int i=0;i<vs.size();i++){
		ret += vs[i];
	}

	return ret;
}

string toStr(int x,int d){

	int dig = 0;
	while(d > 0){
		dig++;
		d/=10;
	}
	string aux = "";

	while(aux.size() < dig){
		aux += char(x%10) + 48;
		x /= 10;
	}

	string ret;
	for(int i=aux.size() -1;i>=0;i--){
		ret += aux[i];
	}

	return ret;
}

void prompt(string cl){

	cl = merge(repl(split(cl,'$')));
	char cmd[cl.size() + 1];

	for(int i=0;i<cl.size();i++) cmd[i] = cl[i];
	cmd[cl.size()] = '\0';
	system(cmd);
}

string menu(){

	prompt("$CLEAR$");
	printf("-------------------------------\n");
	printf("        escolha uma opcao      \n");
	printf("-------------------------------\n\n");
	printf("[0] para sair\n");
	printf("[1] para criar casos testes\n");
	printf("[2] para verificar as solucoes\n");
	printf("-------------------------------\n");
	printf("comando: ");
	string x;
	cin >> x;
	
	return x;
}

void runGenerator(){

	prompt("$CLEAR$");
	printf("-----------------------------------\n");
	printf("Digite a quantidade de casos testes\n");
	printf("-----------------------------------\n\n");
	printf("comando: ");
	int len;
	cin >> len;
	printf("\n");

	prompt("$MKDIR$ tests");
	printf("Gerando casos...\n");
	printf("[");
	for(int j=0;j<len;j++){
		printf(" ");		
	}
	printf("]");
	for(int j=len;j>=0;j--){
		printf("%c",8);
	}

	prompt("g++ generator.cpp -o gen");
	
	
	for(int j=1;j<=len;j++){

		string cmd = "$RUN$gen " + toStr(j,len) + " >tests$SLASH$input" + toStr(j,len) + ".in";
		prompt(cmd);
		// loading bar
		printf("%c%c",127,219);
	}
	printf("%c]\n",127);

	prompt("$DEL$ gen.exe");

	promt("$LIST$ >temp");
}

void runOutputs(){


}

int main(){

	string op = menu();
	while(op != "0"){
		if(op == "1"){
			runGenerator();
			sleep(5);
		}
		else if(op == "2"){
			runSolutions();
			sleep(5);
		}

		op = menu();
	}
}