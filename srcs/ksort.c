/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:09:18 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/09 13:55:38 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void ksort_1(t_stack *a, t_stack *b, int size)
{
  int chunk_size;
  int chunk_index_initial;
  int i;
  int count;
  t_node *temp;
  
  chunk_size = chunk(size);
  chunk_index_initial = 0;
  while (chunk_index_initial < size)
  {
    i = a->size;
    while (i > 0 && a->size > 0)
    {
      if (a->head->s_index >= chunk_index_initial && a->head->s_index <= chunk_index_initial + chunk_size - 1)
        push(b, a);
      else if (a->size > 1 && a->head->next->s_index >= chunk_index_initial &&
               a->head->next->s_index <= chunk_index_initial + chunk_size - 1)
      {
        swap(a);
        push(b, a);
      }
      else
      {
        count = 0;
        temp = a->head;
        while (temp)
        {
          if (temp->s_index >= chunk_index_initial && temp->s_index <= chunk_index_initial + chunk_size - 1)
            break;
          count++;
          temp = temp->next;
        }
        if (temp)
        {
          if (count <= a->size)
            while (a->head != temp)
              rotate(a);
          else
            while (a->head != temp)
              reverse(a);
          push(b, a);
        }
        else
          rotate(a);
      }
      i--;
    }
    chunk_index_initial = chunk_index_initial + chunk_size;
  }
}


void ksort_2(t_stack *a, t_stack *b, int size)
{
    int target;
    int pos;
    int half;
	
    target = size - 1;
    while (target >= 0)
    {
        pos = find_pos_index_stack(b, target);
        half = b->size;
        if (pos <= half)
        {
            while (b->head->s_index != target)
            {
                if (b->head->next != 0 && b->head->next->s_index == target)
                    swap(b);
                else
                    rotate(b);
            }
        }
        else
            while (b->head->s_index != target)
                reverse(b);
        push(a, b);
        target--;
    }
}

void ksort(t_stack *a, t_stack *b, int size)
{
    index_stack(a, size);
    ksort_1(a, b, size);
    ksort_2(a, b, size);
}
