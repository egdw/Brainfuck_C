#include "header.h"
#include "stack.h"
// print String  
void printString(char *s){
    printf("%s",s);
}

void printInt(int d){
    printf("%d",d);
}

void printIntNewLine(int d){
    printf("%d\n",d);
}

// print 
void print(char s){
    printf("%c",s);
}

// line feed 
void printNewLine(char s){
    printf("%c\n",s);
}

// parse the input content
void parse(char *inputText){
    Stack *stack = stack_init(200);
    // define space to store data
    int *datas = (int *) malloc(sizeof(int) * 2000);
    // pointer
    int plt = 0;
    int indexOfInputText = 0;
    int while_flag = 0;
    int while_run = 0;
    while(*(inputText+indexOfInputText)!='\0'){
        if(while_flag && *(inputText+indexOfInputText)!=']'){
            indexOfInputText = indexOfInputText + 1;
            continue;
        }
        switch (*(inputText+indexOfInputText))
        {
            case '>':
                plt = plt + 1;
                break;
            case '<':
                plt = plt - 1;
                break;
            case '+':
                datas[plt] = datas[plt] + 1;
                break;
            case '-':
                datas[plt] = datas[plt] - 1;
                break;
            case '.':
                print(datas[plt]);
                break;
            case ';': //to add \n
                printNewLine(datas[plt]);
                break;
            case ',':
                datas[plt] = getchar() - 48;
                break;
            case '[':
                if(datas[plt] == 0){
                    //Indicates that the current loop has ended
                    //Jump to the next]
                    //[[+++++++;+++++++;----+++++;]]
                    //There need a stack here
                    if(stack_size(*stack)>=1){
                        pop(*stack);
                    }
                    while_flag = 1;
                    continue;
                }else{
                    if(while_run == 0){
                        push(*stack,indexOfInputText);
                        while_run = 1;
                    }
                }
                break;
            case ']':
                //If the pointer to the cell does not have a value of 0, jump forward to the next instruction of the corresponding [instruction]
                if(datas[plt] !=0){
                    int pre = top(*stack);
                    //Jump back in position.
                    indexOfInputText = pre;
                    continue;
                }
                while_flag = 0;
                while_run = 0;
                break;
            default:
                break;
        }
        indexOfInputText = indexOfInputText + 1;
    }
    free(stack);
    free(datas);
}

int main(){
    //* 
    //++++>++++++++++++++++++++++++++++++++++++++[<+>-]<;

    //helloworld
    //++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.<.;
    
    char* inputs = (char *)malloc(sizeof(char) * 2000);
    // get input text from user
    gets(inputs);

    //start to parse
    parse(inputs);

    free(inputs);
    // printString(inputs);
    return 0;
}
