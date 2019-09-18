#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<string.h>


//構造体
/* 社員構造体 */
typedef struct entry {
	char id[6];
    char name[21];
    int sex;
    char department[11];
    char my_intro[101];
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
struct entry entry_1 = { "11111", "arinaga", 1, "IIS-E2", "I am King."};
struct entry entry_2 = { "11112", "kuroiwa", 2, "IIS-E1", "I am Queen."};
struct entry entry_3 = { "11113", "Mita", 1, "IIS-E1", "I am Jack."};


/*関数*/
void print(void);

int main(void){

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
	
    /* テスト */
	print();
}


void print(void){
	struct cell *curr_cell = p_list_head->next_cell;
	// printf("%p\n", curr_cell);
	// printf("%p\n", curr_cell->next_cell);
    while (curr_cell != NULL){
        printf("------------------------------\n");
        printf("社員番号　　　　　　　：%s\n", curr_cell->cell_entr.id);
        printf("名前　　　　　　　　　：%s\n", curr_cell->cell_entr.name);
        printf("性別(男：1 女：2)  　 ：%d\n", curr_cell->cell_entr.sex);
        printf("部署名　　　　　　　　：%s\n", curr_cell->cell_entr.department);
        printf("自己紹介　　　　　　　：%s\n", curr_cell->cell_entr.my_intro);
        // printf("%s %s %d %s %s\n" ,curr_cell->cell_entr.id, curr_cell->cell_entr.name, 
        // 	curr_cell->cell_entr.sex, curr_cell->cell_entr.department, curr_cell->cell_entr.my_intro);
        curr_cell = curr_cell->next_cell;
    }
    printf("------------------------------\n");
}


