/*
editor_ver2.c
　: 既存のテキストファイルを開き、文字列をリストに格納後、文字のappend(末尾追加)、insert(挿入)、delete(削除)を行う。
*/

#include <stdio.h>
#include <stdlib.h>

/* 構造体の定義 */
struct cell {
    char buf;
    struct cell *prev;
    struct cell *next;
};

/* グローバル変数 */
// char *file_name = NULL;   //　入力された文字列を格納（本番用）
char file_name[30] = "sample.txt";   //　固定ファイル名（テスト用）


/* 関数のプロトタイプ宣言 */
struct cell* file_load(struct cell *p_list_head, char *filename);
struct cell* append(char c, struct cell *curr_cell);
void display(struct cell *p_list_head);
void rev_display(struct cell *curr_cell);
struct cell* to_append(struct cell *p_list_head ,struct cell *new_cell);
struct cell* to_insert(struct cell *p_list_head);
struct cell* to_delete(struct cell *p_list_head);
void to_write(struct cell *p_list_head, char *filename);
char* str_input (char *s);

/* 残りタスク：　入力したファイル名のfile_load()への受け渡し
　対象行：17, 44~48　※コメントアウトしてる部分 */

/* main関数 */
int main (void){

    int c;
    int op;
    struct cell list_head;
    struct cell *p_list_head = &list_head;
    struct cell *p_list_end;

    /* ファイルの読み込み＆文字列をリストへ格納 */
    // printf("ファイル名を入力して下さい >>> ");
    // file_name = str_input(file_name);
    // printf("ファイル名: %s\n", file_name);
    // printf("アドレス：%p\n", file_name);

    p_list_end = file_load(p_list_head, file_name);
    display(p_list_head);
    // rev_display(p_list_end);


    /* 追加、挿入、削除 */
    while(1){
        int flag = 1;
        printf("文字列に対する操作を選んでください\n");
        printf("1:Append  2:Insert  3:Delete >>> ");
        while((c = getchar()) != '\n'){
            op = c;
        }

        if (op == '1'){
            /* append */
            p_list_end = to_append(p_list_head ,p_list_end->next);
            display(p_list_head);
        }
        else if (op == '2'){
            /* insert */
            p_list_head = to_insert(p_list_head);
            display(p_list_head);
        }
        else if (op == '3'){
            /* delete */
            p_list_head = to_delete(p_list_head);
            display(p_list_head);
        }
        else{
            printf("入力が不正です。\n");
        }

        /* 操作を継続するかどうか尋ねる */
        printf("操作を続けますか?\n");
        printf("継続:1  終了:それ以外 >>> ");
        while((c = getchar()) != '\n'){
            flag = c;
        }
        
        if(flag != '1'){
	    printf("flag:%c　終了します\n", flag);
            break;
        }
    }

    /* ファイルへ書き込み */
    to_write(p_list_head, file_name);    //本番用：str , テスト用：str2

    return 0;
}



/***　関数の定義　***/


/* file_load() : ファイルをロードしてリストに格納する関数 */
struct cell *file_load(struct cell *p_list_head, char *filename){
    int c;

    // printf("filename: %s\n", filename);
    // printf("アドレス：%p\n", filename);
    FILE *infile = fopen(filename, "r");
    if (infile == NULL){
        printf("ファイルが見つかりません!\n");
        exit(2);
    }
    printf("ファイルの文字を1文字ずつリストに格納します。\n");
    struct cell *curr_cell = (struct cell*)p_list_head;
    struct cell *list_end;
    curr_cell->prev = NULL;

    while ((c=fgetc(infile)) != EOF){
        curr_cell = append(c, curr_cell);
        // printf("文字をリストに追加！\n");
    }
    list_end = curr_cell->prev;

    fclose(infile);
    return list_end;
}


/* append() : 文字をリストに格納する関数 */
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


/* display() : リストの先頭から文字を表示する関数 */
void display(struct cell *p_list_head){
    //printf("リストの先頭から順に表示します。\n");
    printf("---------------------------------------\n");
    printf("ファイルの文字列：\n");
    while (p_list_head->next != NULL){
        printf("%c", p_list_head->buf);
        p_list_head = p_list_head->next;
    }
    printf("\n---------------------------------------\n");
}


/* rev_display() : リストの末尾から文字を表示する関数 */
void rev_display(struct cell *curr_cell){
    printf("リストの最後から順に表示します。\n");
    while (curr_cell != NULL){
        printf("%c", curr_cell->buf);
        curr_cell = curr_cell->prev;
    }
    printf("\n");
}


/* to_append() : リストの末尾に文字を追加 */
struct cell* to_append(struct cell *p_list_head ,struct cell *new_cell){
    int a;
    int chr;
    struct cell *curr_cell = p_list_head;
    printf("文字を末尾に追加します。\n");
    display(p_list_head);
    printf("追加する文字を1文字入力して下さい >>> ");
    while((a = getchar()) != '\n'){
            chr = a;
        }
    printf("文字：%c\n", chr);
    new_cell = append(chr ,new_cell);
    return new_cell->prev;
}


/* to_insert() : リスト内で指定された番号に文字を挿入　引数：リストの先頭ポインタ, ファイル名　戻り値：リストの先頭ポインタ */
struct cell* to_insert(struct cell *p_list_head){
    int a;      // getchar()のキャリア用
    int chr;    //挿入文字の格納用
    int index = 0;
    char *num = NULL;
    struct cell *curr_cell;
    struct cell *prev_cell;

    struct cell *insert_cell;
    if ((insert_cell = (struct cell *) malloc(sizeof(struct cell))) == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}

    /* 挿入する番号および挿入文字を入力 */
    printf("文字を指定位置に挿入します。\n");
    display(p_list_head);
    printf("挿入する番号を入力して下さい >>> ");
    // char str[4];
    // scanf("%s", str);
    // index = atoi(str);
    num = str_input(num);
    int j = 0;
    while (num[j] != '\0'){
        index = index * 10 + num[j] - '0';
        j++;
    }
    /* 挿入する1つ前のセルをcurr_cellに指定 */
    curr_cell = p_list_head;
    for (int i = 0; i < index-1; i++){
        curr_cell = curr_cell->next;
        if (curr_cell == NULL){
            printf("入力した値が不正です！\n");
            return p_list_head;
        }
    }

    printf("挿入する文字を1文字入力して下さい >>> ");
    while((a = getchar()) != '\n'){
            chr = a;
    }
    printf("番号：%d  文字：%c\n", index, chr);


    /* 1個前のセルと1個後ろのセルを連結 */
    // 選択セルが先頭の場合
    if (curr_cell->prev == NULL)
    {
        /* insert_cellの設定:ポインタ→値 */
        insert_cell->prev = NULL;
        insert_cell->next = curr_cell;
        insert_cell->buf = chr;
        /* curr_cellをinsert_cellに接続, insert_cellを先頭セルに指定 */
        curr_cell->prev = insert_cell;
        p_list_head = insert_cell;
    }
    else // それ以外の場合
    {
        prev_cell = curr_cell->prev;
        /* insert_cellの設定:ポインタ→値 */
        insert_cell->prev = prev_cell;
        insert_cell->next = curr_cell;
        insert_cell->buf = chr;
        /* prev_cell, curr_cellをinsert_cellに接続 */
        prev_cell->next = insert_cell;
        curr_cell->prev = insert_cell;
    }

    return p_list_head;
}


/* to_delete() : リスト内の指定された番号の文字を削除　引数：リストの先頭ポインタ, ファイル名　戻り値：リストの先頭ポインタ */
struct cell* to_delete(struct cell *p_list_head){
    struct cell *curr_cell;
    struct cell *new_cell;
    struct cell *prev_cell;

    /* 入力する番号を指定 */
    char *num = NULL;
    int index = 0;
    printf("文字を削除します。\n");
    display(p_list_head);
    printf("削除する番号を入力して下さい >>> ");
    // char str[4];
    // scanf("%s", str);
    // index = atoi(str);
    num = str_input(num);
    int j = 0;
    while (num[j] != '\0'){
        index = index * 10 + num[j] - '0';
        j++;
    }
    printf("番号：%d\n", index);

    /* 削除するセルをcurr_cellに指定 */
    curr_cell = p_list_head;
    for (int i = 0; i < index-1; i++){
        curr_cell = curr_cell->next;
        if (curr_cell == NULL){
            printf("入力した値が不正です！\n");
            return p_list_head;
        }
    }
    //printf("削除する文字 : %c\n", curr_cell->buf);

    /* 1個前のセルと1個後ろのセルを連結 */
    // 選択セルが先頭の場合
    if (curr_cell->prev == NULL){
        new_cell = curr_cell->next;
        new_cell->prev = NULL;
        p_list_head = new_cell;

    // 選択セルが末尾の場合
    } else if (curr_cell->next == NULL){
        prev_cell = curr_cell->prev;
        prev_cell->next = NULL;
    }
    // それ以外の場合
    else{
        prev_cell = curr_cell->prev;
        new_cell = curr_cell->next;

        prev_cell->next = new_cell;
        new_cell->prev = prev_cell;
    }


    /* curr_cellの記憶領域を解放 */
    free(curr_cell);

    return p_list_head;
}


/* to_write() : リストの文字列をファイルに書き込む関数 */
void to_write(struct cell *p_list_head, char *filename){
    FILE *fp = fopen(filename, "w");
    struct cell *curr_cell = p_list_head;
    while (curr_cell->next != NULL){
        fputc(curr_cell->buf, fp);
        curr_cell = curr_cell->next;
    }
    fclose(fp);
}

/* str_input() : キーボードから文字列を入力し、そのポインタを返す */
char* str_input (char *s){
    int c;
    int i = 0;
    char str[100];

    while ((c=getchar()) != '\n'){
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    s = str;
    return s;
}
