#include <stdio.h>
#include <stdlib.h>


void execute_tape(char* bf_code){
    int nested = 0;
    char command;
    char cell[30000] = {0};
    char* cp = cell;
    int temp;
    printf("\nOUTPUT :: ");

    while(command = *bf_code++){
        switch(command){
        case '+': ++(*cp);break;
        case '-': --(*cp);break;
        case '<': --cp;break;
        case '>': ++cp;break;
        case ',': *cp=getchar();break;
        case '.': putchar(*cp);break;   /*chr out*/
        case '#': printf("%d",*cp);break;   /*dec out*/
        case 'x': printf("%x",*cp);break;  /*hex out*/
        case '!': putchar('\n');break;
        case '[':
            if (!*cp) {
                for (nested=1; nested; bf_code++)
                    if (*bf_code == '[')
                        nested++;
                    else if (*bf_code == ']')
                        nested--;
            }
            break;
        case ']':
            if (*cp) {
                bf_code -= 2;
                for (nested=1; nested; bf_code--)
                    if(*bf_code == ']')
                        nested++;
                    else if (*bf_code == '[')
                        nested--;
                bf_code++;
            }
            break;
        }
        if(*cp==256)
            *cp=0;
        else if (*cp==-1)
            *cp=255;
    }
    printf("\n");
}

char tape[30000];

char* file_to_string() {
    FILE* file = fopen("main.bf", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int index = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            tape[index++] = ch;
        }
    }
    tape[index] = '\0';
    fclose(file);

    printf("TAPE :: %s\n", tape);
    return tape;
}

int main(int argc, char* argv[]){
    //if(argc < 2){
        //puts("[ERROR] file?");return -1;}

    char* bf_code = file_to_string();
    execute_tape(bf_code);

    return 0;
}
