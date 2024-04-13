/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:25:08 by amejdoub          #+#    #+#             */
/*   Updated: 2023/12/13 20:42:56 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	void	*res;

	newlist = NULL;
	while (lst && f && del)
	{
		res = f(lst->content);
		node = ft_lstnew(res);
		if (node == NULL)
		{
			del(res);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}
// void *map_function(void *content)
// {
//     // Modify the content as needed
//     // For example, convert the content to uppercase
//     char *str = (char *)content;
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//         {
//             str[i] = str[i] - 32;
//         }
//     }
//     return content;
// }
// void del_function(void *content)
// {
//     free(content);
// }

// void print_list(t_list *list)
// {
//     printf("list:\n");
//     while (list != NULL)
//     {
//         printf("%s\n", (char *)list->content);
//         list = list->next;
//     }
// }

// int main()
// {
// 	t_list *node;
//     node = ft_lstnew(ft_strdup("teest"));
//     ft_lstadd_back(&node, ft_lstnew(ft_strdup("hehehehe")));
//     ft_lstadd_front(&node, ft_lstnew(ft_strdup("ali")));
//     print_list(node);
//     printf("%d\n", ft_lstsize(node));
//     printf("%s\n", ft_lstlast(node)->content);
//     // ft_lstclear(&node, &del_function);
//     // printf("after clear:\n");
//     print_list(node);
//     t_list *new_list = ft_lstmap(node, &map_function, &del_function);

//     printf("new list is not null\n");
//     printf("after map:\n");
//     print_list(ft_lstmap(node, &map_function, &del_function));    
//     return 0;
// }