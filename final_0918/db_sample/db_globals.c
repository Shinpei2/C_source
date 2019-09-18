/*
*	db_globals.c -- Simple DBSystem global datas.
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>

#include	"db_defs.h"
#include	"externals.h"

struct db_cell	db_head;
struct db_cell	*db_current = (struct db_cell *)&db_head;


void
init_head()
{
	struct db_cell	*index_cell;
	struct db_cell	*temp_cell;


	
	db_current = (struct db_cell *)&db_head;
	index_cell = db_current->next;
	while (index_cell != NULL) {
		temp_cell = index_cell->next;
		index_cell->next = NULL;
		free(index_cell);
		index_cell = temp_cell;
	}
	db_current->next = NULL;
}


/* ---------------- db_globals.c ----------------- */

