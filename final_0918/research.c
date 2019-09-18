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


/* 関数宣言 */
void research(void);
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
    research();
}


/* research() - 関数内でidを検索し、検索したidの情報を表示する関数 */
void research(void){
    int i;
    char search_id[10] = {'\0'};

    while(1){
        int f = 0;
        printf("検索するcellの社員番号を入力して下さい：");
        scanf("%s", search_id);
        getchar();
        if (strlen(search_id) > 5){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        for(i=0; i < strlen(search_id); i++){
            if (!isdigit(search_id[i])){
                printf("不正な入力2：数字でない\n");
                f = 1;
            }
            if (f == 1){
                break;
            }   
        }
        if (f == 1){
            continue;
        } else{
            break;
        }
    }

    // printf("%s\n", search_id);
    cell *target = find_id(search_id);

    if (target != NULL){
        printf("cellが見つかりました。\n");
        printf("------------------------------\n");
        printf("社員番号　　　　　　　：%s\n", target->cell_entr.id);
        printf("名前　　　　　　　　　：%s\n", target->cell_entr.name);
        printf("性別(男：1 女：2)  　 ：%d\n", target->cell_entr.sex);
        printf("部署名　　　　　　　　：%s\n", target->cell_entr.department);
        printf("自己紹介　　　　　　　：%s\n", target->cell_entr.my_intro);
        printf("------------------------------\n");

    } else{
        printf("見つかりませんでした。\n");
    }


}


/* find_id - リスト内のidを検索し、idがあれば戻り値構造体ポインタ、ない場合nullを返す */
cell* find_id(char *entry_id){
    int f = 0;
    int entry_id_num;
    int list_id_num;
    cell *curr_cell = p_list_head;

    entry_id_num = to_integer(entry_id);
    // printf("entry_id_num: %d\n", entry_id_num);

    while(1){
        curr_cell = curr_cell->next_cell;
        // 終端まで探索し、見つからない場合はループを抜ける
        if(curr_cell == NULL){
            break;
        }

        list_id_num = to_integer(curr_cell->cell_entr.id);
        // printf("list_id_num: %d\n", list_id_num);

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

