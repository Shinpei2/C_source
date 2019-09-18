/*
*	db_misc.c -- Simple DB System misc functions.
*
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<string.h>

#include	"db_defs.h"
#include	"externals.h"

#define 	is_number(c)	((c >= '0') && (c <= '9'))

void
input_flush()
{
	while (getchar() != '\n')
		;
}


void
input_rewind(char c)
{
	ungetc(c, stdin);
}


void
input_buf(unsigned char *buf, int size)
{
	int	c;
	register index = 0;

	while ((c = getchar()) != '\n' && (c != EOF)) {
		if (index >= size) 
			break;

		*buf++ = (unsigned char)c;
		index++;
	}
	
	*buf = '\0';
}
		

int	
to_number(char	*buf)
{
	int	result = 0;


	while (*buf != '\0') {
		if (is_number(*buf))
			result = 10 * result + (*buf - '0');
		buf++;
	}
	return(result);
}

	

/* ---------------------------- db_misc.c --------------------- */
