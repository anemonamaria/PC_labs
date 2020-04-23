#include <stdio.h>
#include <stdlib.h>

struct multime {
        unsigned char a;
};

void init(struct multime *m)
{
        m->a = 0;
}

void add(struct multime *m, int x)
{
        m->a = m->a | (1 << x);
}

void del(struct multime *m, int x)
{
        m->a = m->a & ~(1 << x);
}

int contains(struct multime *m, int x)
{
        return m->a & (1 << x);
}

void print(struct multime *m)
{
        int i;
        printf("{ ");
        for (i = 0; i < 8; i++)
                if (contains(m, i))
                        printf("%d ", i);
        printf("}\n");
}

int main()
{	int nr;
        struct multime m;
        init(&m);
	scanf("%d", &nr);
	init(&m);
	add(&m, nr);
	add(&m, 3);
	print(&m);
	add(&m, 7);
	print(&m);
	del(&m, nr);
	contains(&m, nr);
	print(&m);
	








 /*       add(&m, 3);
        add(&m, 5);
        add(&m, 2);
        add(&m, 7);
        print(&m);
        del(&m, 2);
        del(&m, 7);
        print(&m); */



        return 0;
}
