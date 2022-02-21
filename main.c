#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TOTAL 10

int main(void) {

int sexo, sn;
	int qtdS = 0, qtdN = 0, qtdS_F = 0, qtdS_M = 0, qtdN_F = 0, qtdN_M=0;
	float psF, psM, pnM, pnF;// percentuais de sim e não masculino e feminino.

	//usamos essa função para conseguir exibir acentos
	setlocale(LC_ALL, "Portuguese");
	for (int i = 0; i < TOTAL; i++) {

		printf("Cliente %i, Qual seu sexo ? (1 - Masculino | 2 - Feminino) - ", i);
		scanf("%i", &sexo);

		while ((sexo < 1) || (sexo > 2))
		{
			printf("Você digitou uma entrada inválida! Tente novamente. \n");
			printf("Cliente %i, Qual seu sexo ? (1 - Masculino | 2 - Feminino) - ", i);
			scanf("%i", &sexo);
		}

		printf("Cliente %i, Gostou do nosso produto ? (1 - Sim | 2 - Não) - ", i);
		scanf("%i", &sn);

		while ((sn < 1) || (sn > 2))
		{
			printf("Você digitou uma entrada inválida! Tente novamente. \n");
			printf("Cliente %i, Gostou do nosso produto ? (1 - Sim | 2 - Não) - ", i);
			scanf("%i", &sn);
		}

		//vamos contar quantos gostaram ou não.
		if (sn == 1) {
			qtdS++;
			if (sexo == 1) {
				qtdS_M++;
			}
			else if (sexo == 2) {
				qtdS_F++;
			}

		}
		else if (sn == 2) {
			qtdN++;
			if (sexo == 1) {
				qtdN_M++;
			}
			else if (sexo == 2) {
				qtdN_F++;
			}
		}
	}
	psF = (float)qtdS_F / TOTAL; // porcentagem de sim feminino
	psM = (float)qtdS_M / TOTAL; // porcentagem de sim masculino
	pnM = (float)qtdN_M / TOTAL; // porcentagem de não masculino
	pnF = (float)qtdN_F / TOTAL; // porcentagem de não feminino

	printf("Total de pessoas que responderam sim: %i\n", qtdS);
	printf("Total de pessoas que responderam não: %i\n", qtdN);

	printf("Total de femininos que responderam sim: %i\n", qtdS_F);
	printf("Total de masculinos que responderam sim: %i\n", qtdS_M);

	printf("Percentual de femininos que responderam sim: %.0f%%\n", psF*100);
	printf("Percentual de masculinos que responderam sim: %.0f%%\n", psM*100);

	printf("Percentual de femininos que responderam não: %.0f%%\n", pnF*100);
	printf("Percentual de masculinos que responderam não: %.0f%%\n", pnM*100);
	//repetimos o %% para exibir o simbolo no console e multiplicamos o resultado da equação por 100 para exibir o valor mais bonito para o usuário mostrando a porcentagem.
	
	return 0;
}