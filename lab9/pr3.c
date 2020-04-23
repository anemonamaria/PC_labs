#include<stdio.h>
#include<time.h>


char* timestr(struct tm t, char* time){
	

        sprintf(time, "%02d:%02d:%02d\n", t.tm_hour, t.tm_min, t.tm_sec);
        printf("%02d:%02d:%02d\n", t.tm_hour, t.tm_min, t.tm_sec);
        return time;
}

int main()
{
        time_t t1;
        struct tm *t2;
        char buffer[100];
        time(&t1);
        t2 = localtime(&t1);
        printf("%s", timestr(*t2, buffer));
        return 0;
}
