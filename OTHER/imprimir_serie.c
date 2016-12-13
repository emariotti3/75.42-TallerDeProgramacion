#include <stdio.h>
#include <stdlib.h>

#define INICIAL 1
#define CANT_TERMINOS 3
#define POS_CANTIDAD 1

void calcular_nuevos_terminos(int *v_sumandos, int tam){
	int suma = 0;
	for (int i = 0; i < tam; i++){
		suma += v_sumandos[i];
		if ((i+1) < tam){
			v_sumandos[i] = v_sumandos[i + 1];
		}else{
			v_sumandos[i] = suma;
		}
	}
}

void calcular_serie(int n_terminos){
	int sumandos[CANT_TERMINOS];
	int terminos_calculados = 0;
	while (terminos_calculados < n_terminos){
		if (terminos_calculados < CANT_TERMINOS){
			sumandos[terminos_calculados] = INICIAL;
			printf("%d", INICIAL);
		}else{
			calcular_nuevos_terminos(sumandos, CANT_TERMINOS);
			printf("%d", sumandos[CANT_TERMINOS-1]);
		}
		terminos_calculados++;
	}
}

int main(int argc, char *argv[]){
	char *cant = argv[POS_CANTIDAD];
	int cantidad = atoi(cant);
	calcular_serie(cantidad);
	return 0;
}
