/*
*	db_funcs.c -- Simple DBSystem functions.
*
*/
#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<string.h>

#include	"db_defs.h"
#include	"externals.h"


int
db_make_items(struct items   *temp_item)
{
	char	input[NAME_SIZE];


	fprintf(stdout, "Please input ID : ");
	input_buf((unsigned char *)input, NAME_SIZE);
	temp_item->id = to_number(input);

	fprintf(stdout, "\nPlease input name : ");
	input_buf((unsigned char *)temp_item->name, NAME_SIZE);

	fprintf(stdout, "\nPlease input sex : male = m, female -> f : ");
	temp_item->sex = getchar();
	input_flush();
	strcpy((char *)temp_item->memo, "Not Avaiable");

}



int
db_make_cell()
{
	struct items	temp_item;


	db_make_items(&temp_item);
	db_append(&temp_item);

}


void
print_items(struct db_cell	*db_target)
{

		fprintf(stderr, "ID : %d \n", db_target->db_items.id);
		fprintf(stderr, "Name : %s \n", db_target->db_items.name);
		fprintf(stderr, "sex : %c \n", db_target->db_items.sex);
		fprintf(stderr, "Memo : %s \n\n", db_target->db_items.memo);
}


void
db_print()
{
	struct db_cell	*index_cell = (struct db_cell *)db_head.next;

	while (index_cell != NULL) {
		fprintf(stderr, "ID : %d \n", index_cell->db_items.id);
		fprintf(stderr, "Name : %s \n", index_cell->db_items.name);
		fprintf(stderr, "sex : %c \n", index_cell->db_items.sex);
		fprintf(stderr, "Memo : %s \n\n", index_cell->db_items.memo);
		index_cell = index_cell->next;
	}
}


int
db_append(struct items	*item_ptr)
{
	struct db_cell	*new_cell;

	 
	if ((new_cell = (struct db_cell *)malloc(sizeof(struct db_cell))) == (struct db_cell *)0) {
		fprintf(stderr, "memory is out of range. program abort\n");
		exit(-1);
	} 
	memcpy((char *)&new_cell->db_items, (char *)item_ptr, sizeof(struct items));

	db_current->next = (struct db_cell *)new_cell;
	new_cell->next = NULL;
	db_current = new_cell;
}


int
db_insert()
{
	struct items	in_item;
	struct db_cell	*new_cell;
	struct db_cell	*index_cell = (struct db_cell *)db_head.next;
	struct db_cell	*prev_cell = (struct db_cell *)&db_head;


	db_make_items(&in_item);
	while (index_cell != NULL) {
		if (index_cell->db_items.id < in_item.id) {
			prev_cell = index_cell;	
			index_cell = index_cell->next;	
		}
		else {
			if ((new_cell = (struct db_cell *)malloc(sizeof(struct db_cell))) == (struct db_cell *)0) {
				fprintf(stderr, "memory is out of range. program abort\n");
				exit(-4);
			}
			memcpy((char *)&new_cell->db_items, (char *)&in_item, sizeof(struct items));
			prev_cell->next = new_cell;
			new_cell->next = index_cell;
			break;
		}
	} 
	if (index_cell == NULL) 
		db_append(&in_item);

}


db_save()
{
	struct db_cell	*index_cell = (struct db_cell *)db_head.next;
	char	save_file[NAME_SIZE];
	FILE	*fd;



	fprintf(stderr, "Please input save file name : ");
	input_buf(save_file, NAME_SIZE);
	if ((fd = fopen(save_file, "w")) == (FILE *)0) {
		fprintf(stderr, "Cannot open save file %s\n", save_file);
		exit(-1);
	}

	while (index_cell != NULL) {
		fwrite((char *)&index_cell->db_items, sizeof(struct items), 1, fd);
		index_cell = index_cell->next;
	}

	fclose(fd);
}


db_load()
{
	char	load_file[NAME_SIZE];
	FILE	*fd;
	struct items	temp_item;
	int	len = 0;


	fprintf(stderr, "Please input load file name : ");
	input_buf(load_file, NAME_SIZE);
	if ((fd = fopen(load_file, "r")) == (FILE *)0) { fprintf(stderr, "Cannot open load file %s\n", load_file);
		exit(-1);
	}

	init_head();
	while (fread((char *)&temp_item, sizeof(struct items), 1, fd) != 0) {
		db_append((struct items *)&temp_item);
	}
	
	fclose(fd);
}
	
		

db_delete()
{
	char	input[NAME_SIZE];
	unsigned int	key;
	struct db_cell	*db_target;
	struct db_cell	*db_prev;


	fprintf(stderr, "Please input ID : ");
	input_buf(input, NAME_SIZE);

	if (db_key_match(to_number(input), &db_target, &db_prev)) {
		db_prev->next = db_target->next;
		db_target->next = NULL;
		free(db_target);
	}
	else
		fprintf(stderr, "ID : %s is not avaiable.\n", input);
	

}


db_search()
{
	char	input[NAME_SIZE];
	unsigned int	key;
	struct db_cell	*db_target; 
	struct db_cell	*db_prev; 


	fprintf(stderr, "Please input ID : ");
	input_buf(input, NAME_SIZE);

	if (db_key_match(to_number(input), &db_target, &db_prev))	
		print_items(db_target);
	else
		fprintf(stderr, "ID : %s is not avaiable.\n", input);
	

}


int
db_key_match(unsigned int key, struct db_cell *(*db_target), struct db_cell *(*db_prev))
{

	struct db_cell	*index_cell = (struct db_cell *)db_head.next;
	struct db_cell	*prev_cell	= (struct db_cell *)&db_head;


	while (index_cell != NULL) {
		if (index_cell->db_items.id == key) {
			*db_target = index_cell;
			return(1);
		}		
		prev_cell = index_cell;
		*db_prev = prev_cell;
		index_cell = index_cell->next;
	}
	return(0);
}


	
/* ----------------------- db_funcs.c ------------------------- */
