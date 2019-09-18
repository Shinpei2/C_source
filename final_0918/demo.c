#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define INITIALIZER NULL;

/* 構造体 */

//構造体
/* 社員構造体 */
typedef struct entry {
	char id[5];
    char name[20];
    int sex;
    char department[10];
    char my_intro[100];
} entry;

/* リスト構造体の定義 */
typedef struct cell {
	struct entry cell_entr;
    struct cell *next_cell;
} cell;


/* 広域変数宣言 */
struct cell list_head = {0 ,0};
struct cell *p_list_head = &list_head;
FILE *fp;
char filename[100];


/*デモデータ */
struct entry entry_1 = { "111", "arinaga", 0, "IIS-E2", "I am King."};
struct entry entry_2 = { "112", "kuroiwa", 1, "IIS-E1", "I am Queen."};
struct entry entry_3 = { "113", "Mita", 1, "IIS-E1", "I am Jack."};


/* 関数 */
void save(){

}

int main (void){
    /* main関数内デモ 
    list_head -> cell_1 -> cell_2 -> cell_3　
    ※cell_3のnext_cellはNULL
    ※list_headの中身　→{0, cell_1}
    */
   /* 以下のコードはmain関数内に記述してください */
    struct cell *cell_1 = NULL;
    struct cell *cell_2 = NULL;
    struct cell *cell_3 = NULL;

    cell_1 = (cell*)malloc(sizeof(cell));
    cell_1->cell_entr = entry_1;
	p_list_head->next_cell = cell_1;

	cell_2 = (cell*)malloc(sizeof(cell));
    cell_2->cell_entr = entry_2;
    cell_1->next_cell = cell_2;

	cell_3 = (cell*)malloc(sizeof(cell));
    cell_3->cell_entr = entry_3;
    cell_2->next_cell = cell_3;

    cell_3->next_cell = NULL;
    /*main関数内デモ終端*/

}