#include "monty.h"
/**
 * errors_msg - Prints appropriate error messages based on error codes.
 * @error_code: The error codes and their meanings are detailed below.
 * (2) => The file provided cannot be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => The program is unable to allocate more memory.
 * (5) => The parameter passed to the "push" instruction is not an int.
 * (6) => The stack is empty for "pint".
 * (7) => The stack is empty for "pop".
 * (8) => The stack is too short for the operation.
 */
void errors_msg(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * more_errors - Handles specific errors in the program.
 * @error_code: The error codes and their corresponding messages:
 *               - 6: Stack is empty for 'pint' operation.
 *               - 7: Stack is empty for 'pop' operation.
 *               - 8: Stack is too short for the operation.
 *               - 9: Division by zero.
 */
void more_errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - Handles errors related to string operations.
 * @error_code: The error codes and their corresponding messages:
 *               - 10: The number inside a node is outside ASCII bounds.
 *               - 11: The stack is empty.
 */
void string_errors(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
