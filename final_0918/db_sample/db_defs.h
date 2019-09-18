/*
*	db_defs.h -- Simple Databese System Data Structures.
*
*/
#ifndef	__DB_DEFS_H__
#define	__DB_DEFS_H__


#define	NAME_SIZE	64
#define	MEMO_SIZE	128


struct items {
	unsigned int	id;
	unsigned char	name[NAME_SIZE];
	char	sex;
	unsigned char	memo[MEMO_SIZE];
};


struct db_cell {
	struct items	db_items;
	struct db_cell	*next;
};



#endif

/* ------------------ db_defs.h ------------------------ */
