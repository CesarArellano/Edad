#include <stdio.h>
#include <time.h>

typedef struct def_Nodo
{
	int Dia, Mes, Anio, Edad;
}Date;

int CalcEdad(Date Fecha, int *flag);

int main (void)
{
	Date Fecha; 
	int flag=0;
	printf("Ingresa tu dia de nacimiento\n");
	scanf(" %d", &Fecha.Dia);
	printf("Ingrese mes de nacimiento\n");
	scanf(" %d", &Fecha.Mes);
	printf("Ingrese año de nacimiento\n");
	scanf(" %d", &Fecha.Anio);
  	Fecha.Edad = CalcEdad(Fecha,&flag);
  	if(flag == 0)
 	 	printf("Usted tiene: %d año(s)\n", Fecha.Edad);
  	else
  		printf("Usted tiene: %d mes(es)\n", Fecha.Edad);
}

int CalcEdad(Date Fecha, int *flag)
{
	int NoDias1, NoDias2,Diferencia;
	char Timestamp[200];
	Date Fecha2;
	time_t rawtime;
  	struct tm *timeinfo;
	time(&rawtime);
  	timeinfo = localtime(&rawtime);
  	strftime(Timestamp,200, "%Y,%m,%d", timeinfo);
  	sscanf(Timestamp,"%d,%d,%d",&Fecha2.Anio,&Fecha2.Mes,&Fecha2.Dia);

	NoDias1 = (Fecha.Anio*365)+(Fecha.Mes*30)+Fecha.Dia;
	NoDias2 = (Fecha2.Anio*365)+(Fecha2.Mes*30)+Fecha2.Dia;
	Diferencia = NoDias2-NoDias1;
	Fecha2.Edad = Diferencia / 365;
	
	if(Fecha2.Edad <= 0){
		Fecha2.Edad  = (Diferencia/30);
		*flag = 1;
		return Fecha2.Edad;
	}
	else 
		return Fecha2.Edad;
}