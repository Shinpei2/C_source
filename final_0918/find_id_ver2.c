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
	char next;
	struct entry cell_entr;
    struct cell *next_cell;
} cell;

/* 広域変数宣言 */
struct cell list_head = {0 ,0};
struct cell *p_list_head = &list_head;
FILE *fp;
char *filename;

/* デモデータ */
struct entry entry_1 = { "111", "arinaga", 0, "IIS-E2", "I am King."};
struct entry entry_2 = { "112", "kuroiwa", 1, "IIS-E1", "I am Queen."};
struct entry entry_3 = { "113", "Mita", 1, "IIS-E1", "I am Jack."};


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

    // int c;
    // int op;

    // p_list_end = file_load(p_list_head);
    // display(p_list_head);



//関数
void find_id(){

    while(find_id){
        printf("%d",find_id);
    }


}

//IDを探索する　WHILE文を使ってリストが終わるまで

/*while ((c=getchar()) != '\n'){
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    s = str;
    return s;
}
*/

curr_cell = p_list_head;
    for (int i = 0; i < index-1; i++){
        curr_cell = curr_cell->next;
        if (curr_cell == NULL){
            printf("入力した値が不正です！\n");
            return p_list_head;
        }
    }


//戻り値を構造体ポインタ
if(){

}


//ない場合はNULLで返す


if (*id == NULL){
        printf("ファイルが見つかりません!\n");
        break;
                }



/* str_input() : キーボードから文字列を入力し、そのポインタを返す */

