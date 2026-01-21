/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:16:41 by amartel           #+#    #+#             */
/*   Updated: 2026/01/21 14:31:20 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/**
 * @file libft.h
 */
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "atoi.h"
# include "is.h"
# include "lst.h"

/**
 * @brief calculate the length of a string
 * @param s A non-NULL, null-terminated string
 * @warning NULL string will result in a segemantion fault
 * @return The length of the string
 */
size_t		ft_strlen(const char *s);
/**
 * @brief fill memory with a constant byte
 * @param s Pointer to the memory area to fill
 * @param c The character to fill the memory
 * @param n Number of bytes to be set to the value
 * @return A pointer to the memory area s
 */
void		*ft_memset(void *s, int c, size_t n);
/**
 * @brief zero a byte string
 * 
 * It writes zeros ('\0') to that area
 * 
 * @param s Pointer to the memory
 * @param n Number of bytes to set to zero
 */
void		ft_bzero(void *s, size_t n);
/**
 * @brief copy memory area
 * @warning this function must overlap, use ft_memmove if they do
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy in the dest memory area
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief compare memory areas
 * @param s1 Pointer to the frist source in memory area
 * @param s2 Pointer to the seconde source in memory area
 * @param n Number of bytes to compare
 * @return An interger  less than, equal to, or greater than 
 * zero if the first n bytes of s1 is found to be less than, 
 * matching, or greater than s2
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief copy memory area
 * @details Unlike ft_memcpy, this function handles overlaping memory areas
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Nomber of bytes to copy in the dest memory area
 */
void		*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief copies a string to a specific size
 * @param dest Pointer to the destination buffer
 * @param src Pointer to the source buffer
 * @param size The full size of dest buffer
 * @return The length of the string, it tries to create the length of src
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
/**
 * @brief appends string src to the end of dest
 * @param dest Pointer to the destination buffer
 * @param src Pointer to the source buffer
 * @param size The full size of dest buffer
 * @return The length of the string, it tries to create initail length of dest
 * + length of src
 */
size_t		ft_strlcat(char *dest, const char *src, size_t size);
/**
 * @brief transform lowercase to uppercase
 * @details if the param c is already in uppercase the function return c
 * @param c The character
 * @return The transform character
 */
int			ft_toupper(int c);
/**
 * @brief transform uppercase to lowercase
 * @details if the param c is already in lowercase the function return c
 * @param c The charater
 * @return The transform character
 */
int			ft_tolower(int c);
/**
 * @brief locate the frist occurence of character in string
 * @param s The string to be searched
 * @param c The charaters to be located
 * @return A pointer to the located charater, or NULL if the charater
 * is not found
 */
char		*ft_strchr(const char *s, int c);
/**
 * @brief locate the last occurence of character in string
 * @param s The string to be searched
 * @param c The charaters to be located
 * @return A pointer to the located charater, or NULL if the charater
 * is not found
 */
char		*ft_strrchr(const char *s, int c);
/**
 * @brief  compare a string
 * @param s1 The frist string
 * @param s2 The seconde string
 * @return A pointer to the matching byte, or NULL if the character
 * is not found
 */
int			ft_strcmp(const char *s1, const char *s2);
/**
 * @brief compare a string with n characters
 * @param s1 The frist string
 * @param s2 The seconde string
 * @param n Number of charaters to compare
 * @return An interger  less than, equal to, or greater than 
 * zero if the first n bytes of s1 is found to be less than, 
 * matching, or greater than s2
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief scan memory for a character
 * @param s The pointer of the memory area to be scanned
 * @param c The charater to be search
 * @param n Number of bytes to scan
 * @return A pointer to the matching byte, or NULL if the character
 * is not found
 */
void		*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief locate a substring in a string
 * @param big The pointer to the string
 * @param little The pointer to the substring
 * @param n Number of characters to search
 * @return A pointer to the start of the located substring,
 * if little is empty big is returned,
 * if no match found NULL is returned
 */
char		*ft_strnstr(const char *big, const char *little, size_t n);
/**
 * @brief duplicate a string
 * @param s1 The string to duplicate
 * @return A pointer to the newly allocated string,
 * or NULL if memory allocation failed
 */
char		*ft_strdup(const char *s1);
/**
 * @brief duplicate a string with n characters
 * @param s1 The string to duplicate
 * @param n Number of charaters to copy
 * @return A pointer to the newly allocated string,
 * or NULL if memory allocation failed
 */
char		*ft_strndup(const char *s1, size_t n);
/**
 * @brief allocate dynamic memory set to '\0'
 * @param nmemb Number of elements to allocate
 * @param size Size in bytes of element `sizeof(type)`
 */
void		*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief create a substring form the string 's'
 * @param s The original string
 * @param start The start index of the substring
 * @param len The maximum length of the substring
 * @return The substring, or NULL if the allocation fails
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief concatenation of two string
 * @param s1 The frist string
 * @param s2 The second string
 * @return The concatenation string of s1 and s2,
 * or if s1 is NULL but s2 is not, then it revises s2 and vice versa,
 * but if both are NULL, then it returns NULL
 * and NULL if memory allocation fails
 */
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief copy of 's1' with characters specified in 'set'
 * removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed
 * @param set The reference set of charaters to trim
 * @return The trimmed string, or NULL if the allocation fails
 */
char		*ft_strtrim(char const *s1, char const *set);
/**
 * @brief returns an array of strings obtained by splitting 's'
 * using 'c' as a delimiter
 * @param s The string to be split
 * @param c The delimiter charater
 * @return The array of new strings, or NULL if the allocation fails
 */
char		**ft_split(char const *s, char c);
/**
 * @brief convert an interger to string
 * @param n The interger to convert
 * @return The string representing interge, or NULL if the allocation fails
 */
char		*ft_itoa(int n);
/**
 * @brief applies 'f' function to each charaters form 's' to create a new
 * string resulting form successive application of 'f'
 * @param s The string on which to iterate
 * @param f The function to apply to each charater
 * @return The string create form the successive application of 'f' 
 * function, or NULL if the allocation fails
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief applies 'f' function to each characters of the string 's'
 * @param s The string on wich iterate
 * @param f The funtion to apply to each charater
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * @brief Output the charater 'c' to the given file descriptor
 * @param c The character to output
 * @param fd The file descriptor on which to write
 */
void		ft_putchar_fd(char c, int fd);
/**
 * @brief Output the interger 'n' to the given file descriptor
 * @param n The interger to output
 * @param fd The file descriptor on which to write
 */
void		ft_putnbr_fd(int n, int fd);
/**
 * @brief Output the string 's' to the given file descriptor
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void		ft_putstr_fd(char *s, int fd);
/**
 * @brief Output the string 's' with new line to the given file descriptor
 * @param s The string to output
 * @param fd The file decriptor on wich to write
 */
void		ft_putendl_fd(char *s, int fd);
/**
 * @brief Read a line form filedescriptor
 * @details For force free put negative fd in param
 * @param fd The file descriptor to read form
 * @return The read line (with the new line if present),
 * or NULL if there is nothing to read or an error occurred
 */
char		*get_next_line(int fd);

#endif
