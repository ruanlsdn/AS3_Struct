#include <stdio.h>
#include <locale.h>
#include <ctype.h>
main () {
	setlocale (LC_ALL,"");
	struct ficha_cadastral {
		int codigo, aulas;
		char sexo;
	};
	int i, cont_m=0, cont_f=0;
	float desconto[3], salario[3], soma_masc=0, soma_fem=0;
	struct ficha_cadastral prof[3];
	for (i=0; i<3; i++) {
		printf ("Informe o código: ");
		scanf ("%d", &prof[i].codigo);
		printf ("Informe o sexo: ");
		prof[i].sexo = getche();
		prof[i].sexo = tolower (prof[i].sexo);
		do {
			if (prof[i].sexo!='m'&&prof[i].sexo!='f') {
				printf ("\nSEXO INVÁLIDO!\n");
				printf ("Informe o sexo: ");
				prof[i].sexo = getche();
				prof[i].sexo = tolower (prof[i].sexo);
			}
		} while (prof[i].sexo!='m'&&prof[i].sexo!='f');
		printf ("\nInforme o número de horas/aula: ");
		scanf ("%d", &prof[i].aulas);
		salario[i]=prof[i].aulas*12.50;
		if (prof[i].sexo=='m') {
			soma_masc=soma_masc+salario[i];
			cont_m++;
		} else {
			soma_fem=soma_fem+salario[i];
			cont_f++;
		}
		if (prof[i].sexo=='m'&&prof[i].aulas>70) {
			desconto[i]=(salario[i]*8)/100;
		} else if (prof[i].sexo=='m'&&prof[i].aulas<=70) {
			desconto[i]=(salario[i]*10)/100;
		} else if (prof[i].sexo=='f'&&prof[i].aulas>70) {
			desconto[i]=(salario[i]*5)/100;
		} else if (prof[i].sexo=='f'&&prof[i].aulas<=70) {
			desconto[i]=(salario[i]*7)/100;
		}
	}
	printf ("DADOS CADASTRADOS\n");
	for (i=0; i<3; i++) {
		printf ("PESSOA %d\n", i+1);
		printf ("CÓDIGO: %d\n", prof[i].codigo);
		printf ("SALÁRIO BRUTO: %.2f\n", salario[i]);
		printf ("SALÁRIO LÍQUIDO: %.2f\n", salario[i]-desconto[i]);
	}
	printf ("A média aritmética dos salários brutos dos professores do sexo masculino: %.2f\n", soma_masc/cont_m);
	printf ("A média aritmética dos salários brutos dos professores do sexo feminino: %.2f", soma_fem/cont_f);

}
