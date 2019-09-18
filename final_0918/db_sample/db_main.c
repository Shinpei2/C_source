/*
*	db_main.c -- Simple DB System main routine.
*
*/
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"db_defs.h"
#include	"externals.h"


main()
{
	int	c;

	init_head();
	print_menu();
	command_prompt();

	while ((c = getchar()) != EOF) {
		switch (c) { 
			case 'a' : 
				input_flush();
				db_make_cell();
				break;

			case 'i' : 
				input_flush();
				db_insert();
				break;

			case 'p' :
				input_flush();
				db_print();
				break;

			case 's' :
				input_flush();
				db_save();
				break;

			case 'l' :
				input_flush();
				db_load();
				break;

			case '/' :
				input_flush();
				db_search();
				break;

			case 'd' :
				input_flush();
				db_delete();
				break;
	
			case 'q' :
				exit(0);

			default :
				print_menu();
				break;
		}
		command_prompt();
	}
}


void
print_menu()
{
	fprintf(stdout, "------------------ Simple DB System sample Menu ---------------- \n");
	fprintf(stdout, "a : Append DB Record.\n");
	fprintf(stdout, "i : Insert DB Record.\n");
	fprintf(stdout, "p : Print DB list.\n");
	fprintf(stdout, "s : Save DB list.\n");
	fprintf(stdout, "l : Load DB list.\n");
	fprintf(stdout, "/ : Search DB Record.\n");
	fprintf(stdout, "d : Delete DB Record.\n");
	fprintf(stdout, "q : Quit this DB system.\n\n");
}


void
command_prompt()
{
	fprintf(stderr, "command >> ");
}
