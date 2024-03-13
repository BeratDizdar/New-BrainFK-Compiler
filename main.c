#include <stdio.h>

int cell[300] = {0};

int main(int argc, char* argv[]){
    if(argc < 2){
        puts("[ERROR] file?");return -1;}
    int* ip = cell;
    
    FILE* file = fopen(argv[1],"r");

    char ch;
    int nested = 0;
    char nestl[100];int np=0;
    while((ch = fgetc(file)) != EOF){
        switch(ch){
            case '+': ++(*ip);break;
            case '-': --(*ip);break;
            case '<': --ip;break;
            case '>': ++ip;break;
            case ',': *ip = getchar();break;
            case '.': putchar(*ip);break;
            case '[':
                nested++;
                while(nested!=0){
                    if(ch != ']')
                        nested--;
                    else{
                        nestl[np] = ch;
                        ch = fgetc(file);
                    }
                }
                np = 0;
                switch(nestl[np]){
                    case '+': ++(*ip);break;
                    case '-': --(*ip);break;
                    case '<': --ip;break;
                    case '>': ++ip;break;
                    case ',': *ip = getchar();break;
                    case '.': putchar(*ip);break;
                    default:
                        np++;
                        break;
                }
                break;
            case ']':
                break;
        }
    }
    fclose(file);

    return 0;
}
