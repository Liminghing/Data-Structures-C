//
//  main.c
//  arrayStack
//
//  Created by 임준형 on 10/19/24.
//

#include <stdio.h>
#define MAXSIZE 20
int stack[MAXSIZE];
int top = -1;
/*------isEmpty------*/
int isEmpty(){
    if(top < 0){
        return 1;
    }else{
        return 0;
    }
}
/*------isFull------*/
int isFull(){
    if(top >= MAXSIZE-1){
        return 1;
    }else{
        return 0;
    }
}
/*------push------*/
void push(int data){
    if(isFull()){
        printf("배열이 가득참\n");
    }
    stack[++top] = data;
    return ;
    
}
int pop(){
    if(isEmpty()){
        return -1;
    }else{
        return stack[top--];
    }
}
int main(int argc, const char * argv[]) {
    

    printf("isEmpty : %d (1:empty, 0: not empty)\n",isEmpty());
    printf("isFull : %d (1:full, 0: not full)\n",isFull());
    push(1);
    push(2);
    push(3);
    push(4);
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    
    

    
    
    return 0;
}
