#include <stdio.h>

main()
{
    /*long nc;*/

    /*nc = 0;*/
    /*while(getchar() != EOF) {*/
        /*nc = nc + 1;*/
    /*}*/

    /*for (nc = 0; getchar() != EOF; ++nc) {*/
        /*;*/
    /*}*/

    /*int nl, c;*/

    /*nl = 0;*/
    /*while ((c = getchar()) != EOF) {*/
        /*if (c=='\n'){*/
            /*nl = nl + 1;*/
        /*}*/
    /*}*/

    int c, ns, nt, nl;
    nl = ns = nt = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        else if (c == '\t') {
            ++nt;
        }
        else if (c == ' ') {
            ++ns;
        }
    }
    printf("line\n%d\n", nl);
    printf("tab\n%d\n", nt);
    printf("space\n%d\n", ns);
}
