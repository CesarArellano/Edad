#include <stdio.h>
#include <time.h>

void Edad(int d, int m, int a,int d2, int m2, int a2);

int main (void)
{
	int Dia, Mes, Anio;
	int DiaActual, MesActual, AnioActual;
	char Timestamp[200];
	time_t rawtime;
  	struct tm *timeinfo;

	printf("Ingresa tu dia de nacimiento\n");
	scanf(" %d", &Dia);
	printf("Ingrese mes de nacimiento\n");
	scanf(" %d", &Mes);
	printf("Ingrese año de nacimiento\n");
	scanf(" %d", &Anio);
	
  	time(&rawtime);
  	timeinfo = localtime(&rawtime);
  	strftime(Timestamp,200, "%Y,%m,%d", timeinfo);
  	sscanf(Timestamp,"%d,%d,%d",&AnioActual,&MesActual,&DiaActual);

  	printf("Nacimiento, Dia: %d, Mes: %d, Anio: %d\n",Dia,Mes,Anio);
  	printf("Hoy, Dia: %d, Mes: %d, Anio: %d\n",DiaActual,MesActual,AnioActual);

  	Edad(Dia,Mes,Anio,DiaActual,MesActual,AnioActual);
}
void Edad(int d, int m, int a,int d2, int m2, int a2)
{
	int NoDias1, NoDias2,Diferencia, Edad;
	NoDias1 = (a*365)+(m*30)+d;
	NoDias2 = (a2*365)+(m2*30)+d2;
	Diferencia = NoDias2-NoDias1;
	Edad = Diferencia / 365;
	if(Edad <= 0){
		Edad  = (Diferencia/30);
		printf("Usted tiene: %d mes(es)\n", Edad);
	}
	else {
		printf("Usted tiene: %d año(s)\n", Edad);
	}
}