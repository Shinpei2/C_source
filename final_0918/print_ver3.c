#include <stdio.h>
#include <stdlib.h>


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


/* 関数のプロトタイプ宣言 */
struct cell* file_load(struct cell *p_list_head);
void print(struct cell *p_list_head);

/*デモデータ */
struct entry entry_1 = { "111", "arinaga", 0, "IIS-E2", "I am King."};
struct entry entry_2 = { "112", "kuroiwa", 1, "IIS-E1", "I am Queen."};
struct entry entry_3 = { "113", "Mita", 1, "IIS-E1", "I am Jack."};


/*関数*/

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
	
	int c;
	int op;
	// struct cell list_head;
	// struct cell *p_list_head = &list_head;
	// struct cell *p_list;
	//p_list_end = file_load(p_list_head);
	print(p_list_head);
}


void print(struct cell *p_list_head){
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


