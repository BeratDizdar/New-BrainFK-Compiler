#include <stdio.h>
#define write_t(x) case x :tape[index]=ch;break

int cell[30000] = {0};
int* ip = cell;
char tape[300];
int tape_end;

char write_tape(){
    FILE* file = fopen("main.bf","r");
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
            write_t('[');
            write_t(']');
        }index++;
    }fclose(file);
    tape_end = index;

    printf("TAPE :: ");
    for(index = 0; index < tape_end; index++)
        printf("%c",tape[index]);
}

void execute_tape(){
    int index = 0;
    int nested = 0;
    printf("\nOUTPUT :: ");

    while(index < tape_end){
        switch(tape[index]){
            case '+': ++(*ip);break;
            case '-': --(*ip);break;
            case '<': --ip;break;
            case '>': ++ip;break;
            case ',': *ip=getchar();break;
            case '.':
                putchar(*ip);
                break;
            case '[':
                if (*ip == 0) {
                    int temp_nested = 1;
                    while (temp_nested != 0) {
                        index++;
                        if (tape[index] == '[') {
                            temp_nested++;
                        } else if (tape[index] == ']') {
                            temp_nested--;
                        }
                    }
                }
                break;
            case ']':
                if (*ip != 0) {
                    int temp_nested = 1;
                    while (temp_nested != 0) {
                        index--;
                        if (tape[index] == '[') {
                            temp_nested--;
                        } else if (tape[index] == ']') {
                            temp_nested++;
                        }
                    }
                }
                break;
        }
        index++;
    }
}

int main(int argc, char* argv[]){
    //if(argc < 2){
        //puts("[ERROR] file?");return -1;}

    write_tape();
    execute_tape();

    return 0;
}
