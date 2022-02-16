#include <stdio.h>
#include <stdlib.h>

void print_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("wcat: cannot open file\n");
        exit(1);
    }
    // how big should this be?
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }
}
// wcat is a utility which reads a file(s) (argument(s) to the program) and outputs
// it's contents to the stdout
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        exit(0);
    }

    for (int i = 1; i < argc; i++)
    {
        print_file(argv[i]);
    }

    return 0;
}
