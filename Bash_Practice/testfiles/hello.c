#include <stdio.h>

unsigned char main()
{
        int a,b,c;

        fscanf(stdin, "%d", &a);
        fscanf(stdin, "%d", &b);
        fscanf(stdin, "%d", &c);
        fprintf(stdout, "Hi World: %d\n", a);
        fprintf(stderr, "Hi Error: %d\n", b);
        fprintf(stderr, "Hi Error: %d\n", c);
        return(a);
}
