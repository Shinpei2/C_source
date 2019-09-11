#include <stdio.h>
#include <stdlib.h>

struct cell {
    char buf;
    struct cell *prev;
    struct cell *next;
};

struct cell* append(char c, struct cell *curr_cell);
void display(struct cell *p_list_head);
void rev_display(struct cell *curr_cell);

int main (void){
    int c;
    printf("実行！\n");
    struct cell list_head;
    struct cell *curr_cell = (struct cell*)&list_head;
    struct cell *list_end;
    curr_cell->prev = NULL;


    printf("文字を入力!\n");
    while ((c=getchar()) != EOF){
        if (c == '\n'){
            printf("改行\n");
            break;
        }
        curr_cell = append(c, curr_cell);
        // printf("文字をリストに追加！\n");
    }
    list_end = curr_cell->prev;
    display(&list_head);
    rev_display(list_end);
}


struct cell* append(char c, struct cell *curr_cell){
    struct cell *new_cell;
	/* 記憶領域の確保 */
	if ((new_cell = (struct cell *) malloc(sizeof(struct cell))) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}

	curr_cell->buf = c;
	curr_cell->next = new_cell;
	new_cell->next = NULL;
	new_cell->prev = curr_cell;
	curr_cell = new_cell;
	return curr_cell;
}


void display(struct cell *p_list_head){
    printf("リストの先頭から順に表示します。\n");
    while (p_list_head->next != NULL){
        printf("%c", p_list_head->buf);
        p_list_head = p_list_head->next;
    }
    printf("\n");
}
void rev_display(struct cell *curr_cell){
    printf("リストの最後から順に表示します。\n");
    while (curr_cell != NULL){
        printf("%c", curr_cell->buf);
        curr_cell = curr_cell->prev;
    }
    printf("\n");
}