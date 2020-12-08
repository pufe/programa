#include <stdio.h>
#include <stdlib.h>

int main()
{
  int semestre, disciplinas, cont, cont2, cont3, carga_horaria, horas_cumpridas, qtd_notas;
  int aprovN = 0, reproN = 0, qtdis = 0, reproF = 0, reproA = 0;
  double notastotal, medianotas, notas, frequencia;
  double ida = 0;
  double soma_notas_aprova = 0;

  printf("Quantos semestres: ");
  scanf("%i", &semestre);


  for(cont = 1; cont <= semestre; cont++)
    {
      int SaprovN = 0, SreproN = 0, SreproF = 0, SreproA = 0;
      double Sida = 0;
      double Ssoma_notas_aprova = 0;
      printf("Semestre %i\n", cont);
      printf("Quantas disciplinas: ");
      scanf("%i", &disciplinas);
      qtdis += disciplinas;
      for(cont2 = 1; cont2 <= disciplinas; cont2++)
	{
	  printf("Disciplinas: %i\n", cont2);
	  printf("\nCarga horaria: ");
	  scanf("%i", &carga_horaria);
	  printf("\nHoras cumpridas: ");
	  scanf("%i", &horas_cumpridas);
	  if(horas_cumpridas > carga_horaria)
	    {
	      return 0;
	    }
	  printf("\nQuantidades de notas: ");
	  scanf("%i", &qtd_notas);

	  for(cont3 = 1; cont3 <= qtd_notas ; cont3++)
	    {
	      printf("Notas: \n");
	      scanf("%lf", &notas);
	      if(notas < 0 || notas > 10)
		{
		  return 0;
		}
	      notastotal = notastotal + notas;
	      if(cont3 == qtd_notas)
		{

		  medianotas = notastotal / qtd_notas;
		  printf("sua media das disciplinas: %.2lf\n", medianotas);
		  notastotal = 0;


		  frequencia = horas_cumpridas * 100 / carga_horaria;
		  if(medianotas > 7 && frequencia > 75){
		    printf("\n-Aprovado!\n\n");
		    aprovN++;
		    SaprovN++;
		    Sida += medianotas * carga_horaria;
		    Ssoma_notas_aprova += medianotas;
		  }

		  else if(medianotas > 7 && frequencia < 75){
		    printf("\n-Reprovado por frequencia!\n\n");
		    reproF++;
		    SreproF++;
		    Sida -= (7.0 - medianotas) * carga_horaria;
		  }
		  else if(medianotas < 7 && frequencia > 75){
		    printf("\n-Reprovado por nota!\n\n");
		    reproN++;
		    SreproN++;
		    Sida -= (7.0 - medianotas) * carga_horaria;
		  }

		  else if(medianotas <7 && frequencia <75){
		    printf("\n-Reprovado!\n\n!");
		    reproA++;
		    SreproA++;
		    Sida -= (7.0 - medianotas) * carga_horaria;

		  }

		}

	    }

	}
      printf("=========Relatorio do Semestre=============\n");
      printf("Aprovadas:%i \n Reprovadas:%i \n Reprovadas por nota: %i\n Reprovas por Frequecia: %i\n Aprovadas em %.2lf%% das disciplinas do semestre\n", SaprovN, SreproN+SreproF, SreproN, SreproF, SaprovN * 100.0 / (double)disciplinas);
      printf("IDA: %.2lf\n", Sida);
      if (SaprovN > 0)
	printf("MGA: %.2lf\n", Ssoma_notas_aprova / SaprovN);
      else
	printf("MGA indefinido\n");
      ida += Sida;
      soma_notas_aprova += Ssoma_notas_aprova;
    }
  printf("=========Relatorio Final=============\n");
  printf("Quantidade de disciplinas:%i \n", qtdis);
  printf("Aprovadas:%i \n Reprovadas:%i \n Reprovadas por nota: %i\n Reprovas por Frequecia: %i\n", aprovN, reproN+reproF, reproN, reproF);
  printf("IDA: %.2lf\n", ida);
  if (aprovN > 0)
    printf("MGA: %.2lf\n", soma_notas_aprova / aprovN);
  else
    printf("MGA indefinido\n");

  return 0;
}
