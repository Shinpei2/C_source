/*
    list2.c : 自己参照型構造体(name, age, emp_id)のリストを作成する
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 構造体の定義 cell_defs.h */
struct cell {
    char name[15];
    int age;
    int emp_id;
    struct cell *prev;
    struct cell *next;
};


/* 関数のプロトタイプ宣言 : externals.h */
struct cell* append(char *name,int age, int emp_id, struct cell *curr_cell);
void display(struct cell *p_list_head);
void rev_display(struct cell *curr_cell);
char* str_input (char *s);
int int_input (void);


/* main関数 ; cell_main.c */
int main (void){
    struct cell list_head;
    struct cell *curr_cell = (struct cell*)&list_head;
    curr_cell->prev = NULL;

    char *name = NULL;
    int age = 0;
    int emp_id = 0;


    printf("データを入力します。\n");
    int count = 0;
    while(1){

        printf("%d人目の入力を開始します。\n", count+1);
        printf("名前を入力:");
        name = str_input(name);
        printf("年齢を入力:");
        age = int_input();
        // printf("関数外のname1: %s\n", name);
        printf("社員番号を入力:");
        emp_id = int_input();
        // printf("関数外のname2: %s\n", name);

        curr_cell = append(name, age, emp_id, curr_cell);
        printf("%d人目の入力を終了しました。\n", count+1);
        printf("続けますか？\n 続ける:1  終了：それ以外 \n>>> ");


        int flag = int_input();
        if (flag == 1){
            count++;
            continue;
        } else{
            printf("入力を終了します。\n");
            break;
        }
    };

    display(&list_head);
    rev_display(curr_cell);
}



/*　関数の定義：cell_funcs.c　*/
struct cell* append(char *name,int age, int emp_id, struct cell *curr_cell){
    struct cell *new_cell;
	/* 記憶領域の確保 */
	if ((new_cell = (struct cell *) malloc(sizeof(struct cell))) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}

	strcpy(curr_cell->name, name);
	curr_cell->age = age;
	curr_cell->emp_id = emp_id;

	curr_cell->next = new_cell;
	new_cell->next = NULL;
	new_cell->prev = curr_cell;
	curr_cell = new_cell;
	return curr_cell;
}


void display(struct cell *p_list_head){
    printf("リストの先頭から順に表示します。\n");
    printf("-----------------------------------\n");
    while (p_list_head->next != NULL){
        printf("name : %s\n", p_list_head->name);
        printf("age : %d\n", p_list_head->age);
        printf("emp_id : %d\n", p_list_head->emp_id);
        printf("-----------------------------------\n");
        p_list_head = p_list_head->next;
    }
    printf("\n");
}

void rev_display(struct cell *curr_cell){
    printf("リストの最後から順に表示します。\n");
    printf("-----------------------------------\n");
    if (curr_cell->next == NULL){
        curr_cell = curr_cell->prev;
    }
    while (curr_cell != NULL){
        printf("name : %s\n", curr_cell->name);
        printf("age : %d\n", curr_cell->age);
        printf("emp_id : %d\n", curr_cell->emp_id);
        printf("-----------------------------------\n");
        curr_cell = curr_cell->prev;
    }
    printf("\n");
}


char* str_input (char *s){
    int c;
    int i = 0;
    char str[100];
    while ((c=getchar()) != EOF){
        if (c == '\n'){
            break;
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    s = str;
    return s;
}

int int_input (void){
    int c;
    char str[50];
    int count = 0;
    while ((c=getchar()) != EOF){
        if (c == '\n'){
            break;
        }
        str[count] = c;
        count++;
    }
    str[count] = '\0';

    int num = 0;
    int len = strlen(str);
    for(int i =0; i < len; i++){
        num = num * 10 + (str[i] - '0') ;
    }
    return num;
}