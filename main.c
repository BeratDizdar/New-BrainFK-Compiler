#include <stdio.h>
#define write_t(x) case x :tape[index]=ch;break

void execute_tape(char* bf_code){
    int nested = 0;
    char command;
    char cell[30000] = {0};
    char* cp = cell;
    
    printf("\nOUTPUT :: ");

    while(command = *bf_code++)
        switch(command){
        case '+': (*cp)++;break;
        case '-': (*cp)--;break;
        case '<': cp--;break;
        case '>': cp++;break;
        case ',': *cp=getchar();break;
        case '.': putchar(*cp);break;
        case '#': (*cp)+=48;break;
        case '!': (*cp)+=10;break;
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
    printf("\n");
}

char tape[30000];

char* file_to_string(){
    FILE* file = fopen("main.bf","r");
    int tape_end;
    int index = 0;
    char ch;
    while((ch = fgetc(file)) != EOF){
        switch(ch){
            write_t('+');
            write_t('-');
            write_t('<');
            write_t('>');
            write_t(',');
            write_t('.');
            write_t('#');
            write_t('!');
            write_t('[');
            write_t(']');
        }index++;
    }fclose(file);
    tape_end = index;

    printf("TAPE :: ");
    for(index = 0; index < tape_end; index++)
        printf("%c",tape[index]);
    return tape;
}

int main(int argc, char* argv[]){
    //if(argc < 2){
        //puts("[ERROR] file?");return -1;}

    char* bf_code = file_to_string();
    execute_tape(bf_code);

    return 0;
}
