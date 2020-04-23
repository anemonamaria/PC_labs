#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strtolower(char *s)
{
        int i, n;
        for (i = 0, n = strlen(s); i < n; i++)
                s[i] = tolower(s[i]);
}

int main(int argc, char *argv[])
{
        FILE *f = fopen(argv[argc - 2], "r");
        char buffer[1000];
        int o_i = 0, o_n = 0, o_c = 0;
        int nr = 0, i, ct = 0;
        for (i = 1; i < argc - 2; i++) { // parcurgem lista de optiuni
                switch (argv[i][1]) {
                        case 'i' : o_i = 1; break;
                        case 'n' : o_n = 1; break;
                        case 'c' : o_c = 1; break;
                }
        }
        if (o_i)
                strtolower(argv[argc - 1]);
        while (fgets(buffer, 1000, f) != NULL) {
                nr++;
                if (o_i)
                        strtolower(buffer);
                if (strstr(buffer, argv[argc - 1])) {
                        ct++;
                        if (o_n)
                                printf("%d : ", nr);
                        printf("%s", buffer);
                }
        }
        if (o_c)
                printf("NR TOTAL DE LINII %d\n", ct);
        fclose(f);
        return 0;
}
