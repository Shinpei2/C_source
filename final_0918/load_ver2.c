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
    //struct entry *next_cell;
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
char *p_filename = filename;


/*デモデータ */
struct entry entry_1 = { "11111", "arinaga", 1, "IIS-E2", "I am King."};
struct entry entry_2 = { "11112", "kuroiwa", 2, "IIS-E1", "I am Queen."};
struct entry entry_3 = { "11113", "Mita", 1, "IIS-E1", "I am Jack."};


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



    //file_load(p_filename);


//void file_load(char *p_filename){
    //FILE *pf;
    //char ch;
    //p_filename = "sample.txt";

    //pf = fopen(p_filename,"rb");

    //if(pf == NULL){
        //printf("該当するファイルはありません\n");
        //exit(EXIT_FAILURE);
    //}
    //while((ch = fgetc(pf)) != EOF){
        //mainlist = addlist(mainlist,ch);
        //printf("%c",ch);

    


    //}
    //fclose(pf);
    //return 0;

    //put_list(mainlist);
}

/* file_load() : ファイルをロードしてリストに格納する関数 */
//struct cell *file_load(struct cell *p_list_head){
    //int c;


struct cell *file_load(){
    int c;
    FILE *infile = fopen(p_filename, "rb");
    if (infile == NULL){
        printf("強制終了!\n");
        exit(2);
    }
    printf("ファイルの文字を1文字ずつリストに格納します。");
    struct cell *curr_cell = (struct cell*)p_list_head;
    struct cell *list_end;
    //curr_cell->prev = NULL;
 
    while ((c=fgetc(infile)) != EOF){
        curr_cell = append(c, curr_cell);
        // printf("文字をリストに追加！\n");
    }
    //list_end = curr_cell->prev;
 
    fclose(infile);
    //return list_end;
}


struct entry* append(char c, struct entry *curr_cell){
    struct entry *new_cell;
    /* 記憶領域の確保 */
    if ((new_cell = (struct entry *) malloc(sizeof(struct entry))) == NULL) {
        printf("malloc error\n");
        exit(EXIT_FAILURE);
    }
 
    curr_entry->id = id;
    curr_entry->name = name;
    curr_entry->sex = sex;
    curr_entry->department = department;
    curr_entry->my_intro = my_intro;
    curr_entry->next = new_cell;
    new_entry->next = NULL;
    //new_cell->prev = curr_cell;
    curr_cell = new_cell;
    return curr_cell;
}
