#include <stdio.h>
#include <stdlib.h>

int FEBRERO = 1;

char* dias[] = { "lunes",
                 "martes",
                 "miercoles",
                 "jueves",
                 "viernes",
                 "sabado",
                 "domingo" };

char* meses[] = { "Enero",
                  "Febrero",
                  "Marzo",
                  "Abril",
                  "Mayo",
                  "Junio",
                  "Julio",
                  "Agosto",
                  "Septiembre",
                  "Octubre",
                  "Noviembre",
                  "Diciembre" };

int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int enero_1(unsigned int year)
{
    // Algoritmo de Gauss: R(1 + 5R(A-1,4) + 4R(A-1,100) + 6R(A-1, 400), 7)
    return (1 + 5*((year-1) % 4) + 4*((year-1) % 100) + 6*((year-1) % 400)) % 7;
}

int es_bisiesto(unsigned int year)
{
    if (year % 4)
        return 0;
    else if (year % 100)
        return 1;
    else if (year % 400)
        return 0;
    else 
        return 1;
}

void primer_dia_por_mes(unsigned int year, int pdpm[])
{
    int dia = (enero_1(year) + 6) % 7;
    int bisiesto = es_bisiesto(year);
    int dmes;

    for (int mes = 0; mes < 12; mes++)
    {
        pdpm[mes] = dia;

        if (mes == FEBRERO)
            dmes = bisiesto ? 29 : 28;
        else
            dmes = dias_mes[mes];

        dia = (dia + dmes) % 7;
    }
}

void imprimir_calendario(unsigned int year)
{
    int dia = (enero_1(year) + 6) % 7;
    int bisiesto = es_bisiesto(year);
    int dmes;

    for (int mes = 0; mes < 12; mes++)
    {
        printf("%s %u\n", meses[mes], year);
        printf("L\tMa\tMi\tJ\tV\tS\tD\n");
        
        for (int i = 0; i < dia; i++)
            printf("\t");

        if (mes == FEBRERO)
            dmes = bisiesto ? 29 : 28;
        else
            dmes = dias_mes[mes];

        for (int i = 0; i < dmes; i++)
        {
            if (dia == 0 && i > 0)
                printf("\n");

            printf("%d\t", i+1);
            dia = (dia + 1) % 7;
        }

        printf("\n---------------------------------------\n");
    }
}


void print_help(void) {
	printf("Pasar el mes como único argumento\n");
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        print_help();
        return 1;
    }
    
    unsigned int y = atoi(argv[1]);
    imprimir_calendario(y);
    

    return 0;
}


