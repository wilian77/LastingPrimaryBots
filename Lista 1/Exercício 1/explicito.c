#include <stdio.h>
#include<math.h>
/* Declaracao de macros com condicoes iniciais e parametros*/
#define X0 		1000    // Numero inicial de atomos
#define T0      0.0
#define ALPHA 	0.2  // taxa de decaimento
#define N		1000	// numero de passos
#define DT		0.01

/*pode-se declarar tambem com constantes*/
// const double X0=1000;

int main(void)
{
	double x,t;
	int n;
  FILE *saida;
	
	t=T0;
	x=X0;
  saida = fopen("euler.dat","w");
	fprintf(saida,"%f %f\n",t,x);

	
	for(n=0; n<N; ++n) // n=n+1 ou n+=1  ou ++n ou n++
	{
		//Passo do algoritmo de Euler explicito
		x = x - ALPHA*DT*x;
		t = (n+1)*DT;
		//printf("%f %f\n",t,x);
		fprintf(saida,"%f %f\n",t,x); //notacao cientifica
	}
	fclose(saida);
	return 0;
} 