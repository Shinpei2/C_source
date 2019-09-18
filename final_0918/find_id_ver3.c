#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<string.h>


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


/* 関数宣言 */
cell* find_id(char *entry_id);
int to_integer(char *str);


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

    /* テスト部 */
    printf("テストを行います\n");
    char test_id[5] = "112";    //テスト用の数字
    cell *target = find_id(test_id);
    
    if (target != NULL){
        printf("構造体が見つかりました。\n");
        printf("id：%s\n", target->cell_entr.id);
        printf("名前：%s\n", target->cell_entr.name);
        printf("性別：%d\n", target->cell_entr.sex);
        printf("部署名：%s\n", target->cell_entr.department);
        printf("自己紹介：%s\n", target->cell_entr.my_intro);

    } else{
        printf("構造体が見つかりませんでした。\n");
    }
}


/* find_id - リスト内のidを検索し、idがあれば戻り値構造体ポインタ、ない場合nullを返す */
cell* find_id(char *entry_id){
    int f = 0;
    int entry_id_num;
    int list_id_num;
    cell *curr_cell = p_list_head;

    entry_id_num = to_integer(entry_id);
    printf("entry_id_num: %d\n", entry_id_num);

    while(1){
        curr_cell = curr_cell->next_cell;
        // 終端まで探索し、見つからない場合はループを抜ける
        if(curr_cell == NULL){
            break;
        }

        list_id_num = to_integer(curr_cell->cell_entr.id);
        printf("list_id_num: %d\n", list_id_num);

        // 数字が一致した場合は、fを1にしてループを抜ける
        if (entry_id_num == list_id_num){
            f = 1;
            break;
        }
    }

    // printf("f:%d\n", f);
    if (f = 1){
        return curr_cell;
    }else{
        return NULL;
    }
}

/* to_integer() - 数字（文字列）を数値に変換する関数 */
int to_integer(char *str){
    int num = 0;
    int len = strlen(str);
    for(int i =0; i < len; i++){
        num = num * 10 + (str[i] - '0') ;
    }
    return num;
}

