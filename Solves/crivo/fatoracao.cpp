/*Vê o maior primo que divide o numero e fatora com ele. Vai 
dividindo pelo primo elevado ao numero de vezes que ele apareceu.
Quando esse numero não for mais divisor, pega o maior divisor
primo do numero atual*/

int f(int i, int e, int d) {//i = fator primo atual, e = expoente atual, n = numero sendo montado
	if(i == fat[i].second) cout << d << endl;
	f(i+1, 1, d);
	if(e < fat[i].second) f(i , e+1, d*fat[i].first);
}

int main(int argc, char const *argv[]){
	
	for (int i = 1; i <= n; i++){
			for(int j = i; j <= n; j+=i){
				solve[j]=i;
			}
		}

	for(int i = 2; i*i<= n; i++){
		int cont = 0;
		while(n%i==0){
			cont++;
			n/=i;
		}
		if(int){
			fat[i].push_back({i, cont});
		}
	}	

	f(0, 0, 1);

	return 0;
}
