#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

<<<<<<< HEAD
<<<<<<< HEAD
	va_start(arg, *format);
=======
	va_start(arg, format);
>>>>>>> 991053e4b53cfc1a583aaff6158c5202f23061b2
	string = format;

	cont = loop_format(arg, string);

	va_end(arg);
	return (cont);
}
/**
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characteres printed
 */
int loop_format(va_list arg, const char *string)
{
	int i = 0, flag = 0, cont_fm = 0, cont = 0, check_per = 0;
=======
	va_start(list, format);
>>>>>>> 526b88c6db2fdc4030640648c31ac111d299dede

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/** write(1, &format[i], 1); **/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
