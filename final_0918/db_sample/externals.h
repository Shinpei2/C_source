/*
*	externals.h -- Simple DBSystem Global Functions & Datas.
*
*/

#ifndef	__EXTERNALS_H__
#define	__EXTERNALS_H__

#include	"db_defs.h"

/*
*	in db_globals.c
*/
extern struct db_cell	db_head;	
extern struct db_cell	*db_current;
extern void	init_head();


/*
*	in db_misc.c
*/
extern void	input_flush();
extern void	input_rewind(char c);
extern void	input_buf(unsigned char *buf, int size);
extern int	to_number(char *buf);

/*
*	in db_funcs.c
*/
extern int	db_make_items(struct items  *items_ptr);
extern int	db_make_cell(); 
extern int	db_append(struct items  *item_ptr);
extern int	db_insert();
extern void	db_print();
extern int	db_load();
extern int	db_save();	
extern void	print_items(struct db_cell *target);
extern int	db_key_match(unsigned int key, struct db_cell *(*target), struct db_cell *(*prev));

/*
*	in db_main.c
*/
extern void	command_prompt();
extern void	print_menu();

#endif

/* ------------------------ externals.h --------------------- */
