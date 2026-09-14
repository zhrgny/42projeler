#include "libft.h"
#include <stdio.h>

void printlst(t_list *head)
{
	while(head != NULL)
	{
		printf("%s\n", (char *)head -> content);
		head = head->next;
	}
}
void del(void *content)
{
	free(content);
}
void printnode(void *content)
{
	printf("%s\n", (char *)content);
	
}
void *f(void *content)
{
	char *c;
	int i;

	c = content;
	i = 0;
	while(c[i])
	{
		c[i] = c[i] + 2;
		i++;
	}
	return((void *)c);
}

int main()
{
	t_list *head;
	t_list *newhead;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	head = NULL;
	node1 = ft_lstnew(ft_strdup("node1"));
	node2 = ft_lstnew(ft_strdup("node2"));
	node3 = ft_lstnew(ft_strdup("node3"));

	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	ft_lstadd_back(&head, node3);
	head = head->next;
	ft_lstdelone(node1, del);
	printlst(head);
	newhead = ft_lstmap(head, f, del);
	printlst(newhead);
	printf("%d\n", ft_lstsize(head));
	printf("%s\n", (char *)ft_lstlast(head)->content);
	ft_lstiter(node1, printnode);
	ft_lstclear(&newhead, del);
	ft_lstclear(&head, del);

	
}
