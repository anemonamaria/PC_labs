#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        FILE *cod, *in, *out;
        char c[128]; // pentru fiecare caracter ii vom retine codul
        char chi, cho, buffer[1000];
        int i, n;

        cod = fopen(argv[1], "r");
        in = fopen(argv[2], "r");
        out = fopen(argv[3], "w");

        for (i = 0; i < 128; i++)
                c[i] = i; // daca nu exista codificare, caracterul ramane la fel
        while (fgets(buffer, 1000, cod) != NULL) {
                if (sscanf(buffer, "%c %c", &chi, &cho)==2)
                        c[chi] = cho;
        }

        while (fgets(buffer, 1000, in) != NULL) {
                for (i = 0, n = strlen(buffer); i < n; i++)
                        fprintf(out, "%c", c[buffer[i]]);
        }

        fclose(cod);
        fclose(in);
        fclose(out);
        return 0;
}

