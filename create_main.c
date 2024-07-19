#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int file_exists(const char *filename) {
    return access(filename, F_OK) != -1;
}

void add_main(const char *filename, const char *main_function) {
    if (file_exists(filename)) {
        FILE *file = fopen(filename, "a");
        if (file == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo: %s. Main não adicionada.\n", filename);
            return;
        }

        fwrite(main_function, sizeof(char), strlen(main_function), file);
        printf("Adicionada main ao arquivo: '%s'.\n", filename);

        fclose(file);
    } else {
        printf("O arquivo '%s' não encontrado.\n", filename);
    }
}

int main() {
    const char *main_ex00 = "\
\n\
#include <stdio.h>\n\
void ft_putchar(char c);\n\
int main(int argc, char **argv)\n\
{\n\
    if (argc > 1) {\n\
    for (int i = 1; i < argc; i++) {\n\
        for (int j = 0; argv[i][j] != '\\0'; j++) {\n\
            ft_putchar(argv[i][j]);\n\
        }\n\
        ft_putchar(' ');\n\
    }\n\
    }\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex01 = "\
\n\
#include <stdio.h>\n\
void ft_print_alphabet(void);\n\
int main()\n\
{\n\
    ft_print_alphabet();\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex02 = "\
\n\
#include <stdio.h>\n\
void ft_print_reverse_alphabet(void);\n\
int main()\n\
{\n\
    ft_print_reverse_alphabet();\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex03 = "\
\n\
#include <stdio.h>\n\
void ft_print_numbers(void);\n\
int main()\n\
{\n\
    ft_print_numbers();\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex04 = "\
\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
void ft_is_negative(int n);\n\
int main(int argc, char **argv)\n\
{\n\
    if (argc > 1) {\n\
     for (int i = 1; i < argc; i++) {\n\
        int value = atoi(argv[i]); \n\
        ft_is_negative(value);\n\
        write(1, \" \", 1);\n\
     }\n\
    }\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex05 = "\
\n\
#include <stdio.h>\n\
void ft_print_comb(void);\n\
int main()\n\
{\n\
    ft_print_comb();\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex06 = "\
\n\
#include <stdio.h>\n\
void ft_print_comb2(void);\n\
int main()\n\
{\n\
    ft_print_comb2();\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex07 = "\
\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
void ft_putnbr(int n);\n\
int main(int argc, char **argv)\n\
{\n\
    if (argc > 1) {\n\
        for (int i = 1; i < argc; i++) {\n\
            int value = atoi(argv[i]); \n\
            ft_putnbr(value);\n\
            write(1, \" \", 1);\n\
        }\n\
    }\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    const char *main_ex08 = "\
\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
void ft_putnbr(int n);\n\
void ft_print_combn(int n);\n\
int main(int argc, char **argv)\n\
{\n\
    if (argc > 1) {\n\
        for (int i = 1; i < argc; i++) {\n\
            int value = atoi(argv[i]); \n\
            ft_putnbr(value);\n\
            ft_print_combn(value);\n\
            write(1, \"\\n\", 1);\n\
        }\n\
    }\n\
    printf(\"\\n\");\n\
    return 0;\n\
}";

    add_main("ex00/ft_putchar.c", main_ex00);
    add_main("ex01/ft_print_alphabet.c", main_ex01);
    add_main("ex02/ft_print_reverse_alphabet.c", main_ex02);
    add_main("ex03/ft_print_numbers.c", main_ex03);
    add_main("ex04/ft_is_negative.c", main_ex04);
    add_main("ex05/ft_print_comb.c", main_ex05);
    add_main("ex06/ft_print_comb2.c", main_ex06);
    add_main("ex07/ft_putnbr.c", main_ex07);
    add_main("ex08/ft_print_combn.c", main_ex08);

    return 0;
}
