#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4

typedef struct Persoana
{
    char* nume;
    char* prenume;
} Persoana;

void serializeaza (Persoana v[],  int nrPersoane, char* fileName)
{
    int i, dim;
    char string[1024];
    FILE *f = fopen(fileName, "wb");
    for(i=0;i< nrPersoane; i++)
    {
        dim = strlen(v[i].prenume);
        fwrite(&dim, 1, sizeof(dim), f);
        strcpy(string, v[i].prenume);
        fwrite(string, 1, dim, f);

        dim = strlen(v[i].nume);
        fwrite(&dim, 1, sizeof(dim), f);
        strcpy(string, v[i].nume);
        fwrite(string, 1, dim, f);
    }
    fclose(f);
}

void deserializeaza(Persoana w[], int nrPersoane, char *fileName)
{
    int i, dim;
    char str[1024];
    FILE *f= fopen(fileName, "rb");
    for(i=0;i<nrPersoane;i++)
    {
        fread(&dim, 1, sizeof(dim), f);
        fread(str, 1, dim, f);
        str[dim] = 0;
        w[i].prenume = strdup(str);
        fread(&dim, 1, sizeof(dim), f);
        fread(str, 1, dim, f);
        w[i].nume = strdup(str);
    }
    fclose(f);
}

int main()
{
    Persoana v[N], w[N];
    char* prenume[N]= {"Eric", "kyle", "Stan", "KEnny"};
    char* nume[N]={"Cartman", "Broflovski", "Marsh", "McCormick"};
    int i;
    for(i=0;i<N;i++)
    {
        v[i].nume = nume[i];
        v[i].prenume = prenume[i];
    }

    serializeaza(v, N, "persoane.bin");
    deserializeaza(w,N,"persoane.bin");
    for(i=0;i<N;i++)
    {
        printf("%s %s\n", w[i].prenume, w[i].nume);
    }
    return 0;
}