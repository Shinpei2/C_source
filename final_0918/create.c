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


/* 関数 */
int create();
void print(struct cell *p_list_head);
int to_integer(char *str);
cell* find_id(char *entry_id);

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

    create();
    print(p_list_head);

}

int create(){
    int i;                          // for文用のint型変数
    int check = 0;                      //文字列入力チェック用
    int cr_id_num = 0;              // 作成した社員情報のidをint型で保持するための変数
    int list_id_num = 0;            //　リスト内の社員情報のidをint型で保持するための変数
    char cr_id[10] = {'\0'};        //入力情報の一時格納用変数。入力自体は2倍の大きさまで受付OKにする。
    char cr_name[40] = {'\0'};
    char cr_sex[3] = {'\0'};
    char cr_department[20] = {'\0'};
    char cr_my_intro[200] = {'\0'};
    entry cr_entry = {"", "", 0, "", ""};       //作成する社員情報。空白で初期化
    cell *target = NULL;                        // idの重複を調べるためのcellポインタ


    /***** 入力処理部　※以下、未完　(1)NULLチェック *****/
    while(1){
        check = 0;
        printf("idを入力：");
        scanf("%s", cr_id);
        getchar();
        if (strlen(cr_id) != 5){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        for(i=0; i < strlen(cr_id); i++){
            if (!isdigit(cr_id[i])){
                printf("不正な入力2：数字でない\n");
                check = 1;
                break;
            }
        }
        if (check == 1){
            continue;
        }
        target = find_id(cr_id);
        if (target != NULL){
            printf("同じ社員番号が存在しています。\n");
            continue;
        }
        for(i = 0; i < strlen(cr_id); i++){
            cr_entry.id[i] = cr_id[i];
        } 
        if (strlen(cr_id) != 5){
            cr_entry.id[i+1] = '\0';
        }
        break;
    }

    while(1){
        printf("名前を入力：");
        scanf("%s", cr_name);
        getchar();
        if (strlen(cr_name) > 20){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        for(i = 0; i < strlen(cr_name); i++){
            cr_entry.name[i] = cr_name[i];
        }
        if (strlen(cr_name) != 20){
            cr_entry.name[i+1] = '\0';
        }
        break;
    }

    while(1){
        printf("性別を入力(1:男 2:女)：");
        scanf("%s", cr_sex);
        getchar();
        if (strlen(cr_sex) > 1){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        if (cr_sex[0] == '1' || cr_sex[0] == '2'){
            cr_entry.sex = cr_sex[0] - '0';
        } else{
            printf("不正な入力2：1か2以外の入力\n");
            continue;
        }
        break;
    }

    while(1){
        printf("部署名を入力：");
        scanf("%s", cr_department);
        getchar();
        if (strlen(cr_department) > 10){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        for(i = 0; i < strlen(cr_department); i++){
            cr_entry.department[i] = cr_department[i];
        }
        if (strlen(cr_department) != 10){
            cr_entry.department[i+1] = '\0';
        }
        break;
    }

    while(1){
        printf("自己紹介を入力(空白なし)：");
        scanf("%s", cr_my_intro);
        getchar();
        if (strlen(cr_my_intro) > 100){
            printf("不正な入力1：文字列の長さ\n");
            continue;
        }
        for(i = 0; i < strlen(cr_my_intro); i++){
            cr_entry.my_intro[i] = cr_my_intro[i];
        }
        if (strlen(cr_my_intro) != 100){
            cr_entry.my_intro[i+1] = '\0';
        }
        break;
    }

    // printf("id：%s\n", cr_entry.id);
    // printf("名前：%s\n", cr_entry.name);
    // printf("性別：%d\n", cr_entry.sex);
    // printf("部署名：%s\n", cr_entry.department);
    // printf("自己紹介：%s\n", cr_entry.my_intro);


    /***** リストへの格納 *****/
    cell *create_cell = NULL;
    cell *curr_cell = p_list_head;
    cell *prev_cell = NULL;
    create_cell = (cell*)malloc(sizeof(cell));

    create_cell->cell_entr = cr_entry;
    cr_id_num = to_integer(create_cell->cell_entr.id);
    // printf("cr_id_num: %d\n", cr_id_num);

    /* リスト探索＆格納 */
    while(1){
        /* リストが空の場合 */
        if (p_list_head->next_cell == NULL){
            curr_cell->next_cell = create_cell;
            create_cell->next_cell = NULL;
            // printf("1\n");
            break;
        }

        /* リストの中に社員情報が存在する場合 */
        prev_cell = curr_cell;
        curr_cell = curr_cell->next_cell;

        // リストの末尾まで到達した場合、末尾にcreate_cellを追加
        if (curr_cell == NULL){
            prev_cell->next_cell = create_cell;
            // printf("2\n");
            break;
        }

        // 作成した社員情報のid < curr_cellのidであれば、作成したものをcurr_cellの手前に挿入
        list_id_num = to_integer(curr_cell->cell_entr.id);  //curr_cellのidをint型に変換
        if (cr_id_num < list_id_num){
            create_cell->next_cell = curr_cell;
            prev_cell->next_cell = create_cell;
            //printf("3\n");
            break;
        }
    }
    
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

/* to_integer() - 数字（文字列）を数値に変換する関数 */
int to_integer(char *str){
    int num = 0;
    int len = strlen(str);
    for(int i =0; i < len; i++){
        num = num * 10 + (str[i] - '0') ;
    }
    return num;
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
