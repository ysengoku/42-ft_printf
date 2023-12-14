#include "includes/ft_printf.h"
#include <stdio.h>

static void	*ft_memset(void *s, int c, size_t n);

int	main()
{
	printf("\n------------- TEST / c -------------\n");
	printf(" (%i)\n", ft_printf("%c", 'a'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%c", 'a'));

	printf("\n------------- TEST / s -------------\n");
	printf(" (%i)\n", ft_printf("%s", "hello"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", "hello"));

	int	size = 10000;
	char *testLongText = malloc(size * sizeof(char));
	ft_memset(testLongText, 'a', size * sizeof(char));
	testLongText[size * sizeof(char) - 1] = '\0';
	printf(" (%i)\n", ft_printf("%s", testLongText));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", testLongText));
	free(testLongText);
	
	printf(" (%i)\n", ft_printf(" NULL %s NULL ", (char *)NULL));
	printf("printf: ");
	printf(" (%i)\n\n", printf(" NULL %s NULL ", (char *)NULL));

	printf("\n------------- TEST / p -------------\n");
	const char	*teststr = "hello";
	printf(" (%i)\n", ft_printf("%p", teststr));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%p", teststr));

	int	*testd = (int *)ft_calloc(2, sizeof(int));
	printf(" (%i)\n", ft_printf("%p", testd));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%p", testd));
	free(testd);

	printf(" (%i)\n", ft_printf(" %p %p ", (void *)0, (void *)0));
	printf("printf: ");
	printf(" (%i)\n\n", printf(" %p %p ", (void *)0, (void *)0));

	printf("\n------------- TEST / d & i------------\n");
	printf(" (%i)\n", ft_printf("%d, %d", -42, -5));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d, %d", -42, -5));	

	printf(" (%i)\n", ft_printf("%i, %i, %i", 0, 7, 101));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%i, %i, %i", 0, 7, 101));

	printf(" (%i)\n", ft_printf("%d, %d", INT_MAX, INT_MIN));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d, %d", INT_MAX, INT_MIN));

	printf(" (%i)\n", ft_printf("%d", 'a'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d", 'a'));

	printf("\n------------- TEST / u -------------\n");
	printf(" (%i)\n", ft_printf("%u", 42));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u", 42));

	printf(" (%i)\n", ft_printf("%u, %u", -123, 0));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u, %u", -123, 0));

	printf(" (%i)\n", ft_printf("%u, %u", INT_MIN, INT_MAX));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u, %u", INT_MIN, INT_MAX));

	printf("\n------------- TEST / x -------------\n");
	printf(" (%i)\n",ft_printf("%x", 1011));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 1011));

	printf(" (%i)\n",ft_printf("%x", 9));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 9));

	printf(" (%i)\n",ft_printf("%x", 0));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 0));

	printf("\n------------- TEST / X -------------\n");
	printf(" (%i)\n",ft_printf("%X, %X", 15, 16));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X, %X", 15, 16));

	printf(" (%i)\n",ft_printf("%X", -27));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X", -27));

	printf(" (%i)\n",ft_printf("%X, %X", INT_MAX, INT_MIN));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X, %X", INT_MAX, INT_MIN));

	printf("\n------------ TEST / %% -------------\n");
	printf(" (%i)\n",ft_printf("%%"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%%"));

	printf("\n------------- TEST / s, d -------------\n");
	printf(" (%i)\n",ft_printf("I'm %s, %d years old.", "Coco", 18));
	printf("printf: ");
	printf(" (%i)\n\n", printf("I'm %s, %d years old.", "Coco", 18));

	printf("\n------------- TEST / empty -------------\n");
	printf(" (%i)\n",ft_printf(""));
	printf("printf: ");
	printf(" (%i)\n\n", printf(""));

	printf("\n------------- TEST / spaces between percent and specifier -------------\n");
	printf(" (%i)\n\n",ft_printf("%   s", "Coucou"));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%   s", "Coucou"));

	printf("\n------------- TEST / invalid specifier -------------\n");
	printf(" (%i)\n\n",ft_printf("%a", "Coucou"));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%a", "Coucou"));

	printf(" (%i)\n\n",ft_printf("%s, %a", "Coucou"));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%s, %a", "Coucou"));

	printf("------------- TEST / without type specifier -------------\n");
	printf(" (%i)\n", ft_printf("hello"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("hello"));

	printf("------------- TEST / empty format -------------\n");
	printf(" (%i)\n", ft_printf(""));
	printf("printf: ");
	printf(" (%i)\n\n", printf(""));

	printf("\n-------- TEST / arg in unexpected type --------\n");
	printf("specifier == i <--> input == char\n");
	printf(" (%i)\n", ft_printf("%i", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%i", 'A'));

	printf("specifier == x <--> input == char\n");
	printf(" (%i)\n", ft_printf("%x", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 'A'));

	printf("specifier == u <--> input == char\n");
	printf(" (%i)\n", ft_printf("%u", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u", 'A'));

	return 0;
}

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
