#include <stdio.h>

typedef char String[1024];      //最大1024文字の文字列型を作る

int main(void)
{
    String MonsterName = "ドラゴン" ;       //String型は””で囲む
    String myname = "神" ;
    printf("敵は%s\n", MonsterName) ;
    printf("私は%s\n", myname) ;
    printf("%sと%sは互いに死闘を繰り広げた" , MonsterName , myname) ;
    return 0 ;
}
        //String内の数は、ひとまず1024で固定する。実際には全角だと250文字程度、初期値以外は代入してはだめ。
