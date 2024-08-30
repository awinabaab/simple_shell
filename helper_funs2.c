#include "main.h"



/**
 * _isdigit - Checks through digits
 *
 * @c: An character as parameter
 *
 * Return: 1 if it's a digit, else returns 0
 */
int _isdigit(unsigned char c)
{
	if (c >= 48 && c < 58)
	{
		return (1);
	}

	return (0);
}



/**
 * _atoi - Converts a string to an integer
 *
 * @s: String pointer
 *
 * Return: Integer if string contains number or 0 if not
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int digit_found = 0;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s == '+')
		{
			continue;
		}
		else if (*s >= '0' && *s <= '9')
		{
			digit_found = 1;
			if (result > (INT_MAX - (*s - '0')) / 10)
			{
				return ((sign == 1) ? INT_MAX : INT_MIN);
			}
			result = result * 10 + (*s - '0');
		}
		else if	(digit_found)
		{
			break;
		}
		s++;
	}
	return (result * sign);
}



/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
