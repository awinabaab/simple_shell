#include "main.h"


/**
 * _strlen - Checks the length of a string
 *
 * @s: The string array
 *
 * Return: String length
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}



/**
 * _strcat - Concats to strings
 *
 * @dest: Destination
 * @src: Source of string
 *
 * Return: A pointer to string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
	}
	while (*src != '\0')
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';

	return (dest);
}



/**
 * _strcmp - Compares two strings
 *
 * @s1: First string
 * @s2: Second string
 *
 * Return: The integer difference between both strings
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}



/**
 * _strcpy - Copies pointer string
 *
 * @dest: Destination of string
 * @src: Source of string
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (start);
}


/**
 * _strdup - Duplicates a string by allocating memory for a new string
 *
 * @s: A pointer to the string to be duplicated
 *
 * Return: A pointer to the newly allocated string
 */
char *_strdup(const char *s)
{
	size_t len;
	char *dup;

	if (s == NULL)
		return (NULL);

	len = _strlen(s) + 1;
	dup = (char *)malloc(len);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, s);

	return (dup);
}
