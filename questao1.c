#include <stdio.h>
#include <locale.h>
main () {
	struct ficha_cadastral {
		char nome[40], sexo, endereco[40];
		int idade, rg;
		float salario;
	};
	setlocale (LC_ALL,"");
	struct ficha_cadastral pessoa[3];
	int cont, cont_idade=0;
	float soma=0, percent;
	for (cont=0; cont<3; cont++) {
		printf ("Informe o RG: ");
		scanf ("%d", &pessoa[cont].rg);
		printf ("Informe o nome: ");
		scanf("%s", &pessoa[cont].nome);
		printf ("Informe o sexo: ");
		pessoa[cont].sexo=getche();
		printf ("\nInforme a idade: ");
		scanf ("%d", &pessoa[cont].idade);
		if (pessoa[cont].idade>=18){
			cont_idade++;
		}
		printf ("Informe o endere�o: ");
		scanf ("%s", &pessoa[cont].endereco);
		printf ("Informe o sal�rio: ");
		scanf ("%f", &pessoa[cont].salario);
		soma=soma+pessoa[cont].salario;
	}
	printf ("DADOS CADASTRADOS\n");
	for (cont=0;cont<3;cont++){
		printf ("PESSOA %d\n", cont+1);
		printf ("RG: %d\n", pessoa[cont].rg);
		printf ("NOME: %s\n", pessoa[cont].nome);
		printf ("SEXO: %c\n", pessoa[cont].sexo);
		printf ("IDADE: %d\n", pessoa[cont].idade);
		printf ("ENDERE�O: %s\n", pessoa[cont].endereco);
		printf ("SAL�RIO: %.2f\n", pessoa[cont].salario);
	}
	percent = (cont_idade*100)/3;
	printf ("A m�dia sal�rial �: %.2f\n", soma/3);
	printf ("O percentual de pessoas maiores de idade �: %.2f", percent);
}


