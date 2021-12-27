#include <stdio.h>
#include <stdlib.h>

//Написать программу, составляющую по символьному файлу линейный упорядоченный список неповторяющихся слов и вывести его.

typedef struct file_s
{
	char *arr;
	int size;
} file_s;

typedef struct word_s
{
	char *arr;
	int size;
	int capacity;
} word_s;

typedef struct node_t
{
	struct word_s *word;
	struct node_t *prev;
	struct node_t *next;
} node_t;

typedef struct list_t
{
	node_t *head;
	node_t *tail;
	size_t size;
} list_t;

int is_char(int ch)
{
	if (
		(65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
		(128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
		return 1;
	else
		return 0;
}

struct node_t *get_node(list_t *l, int i)
{
	node_t *curr;
	if (i < ((l->size) / 2))
	{
		int count = 0;
		node_t *curr = l->head;
		while (count != i)
		{
			curr = curr->next;
			count++;
		}
		return curr;
	}
	else
	{
		int count = l->size-1;
		node_t *curr = l->tail;
		while (count != i)
		{
			curr = curr->prev;
			count--;
		}
		return curr;
	}
}

size_t file_size(FILE *f)
{

	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	return fsize;
}

file_s *read_file(char *filename)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("Error! opening files");
		exit(1);
	}

	size_t fsize = file_size(f);
	char *s = (char *)malloc(fsize * sizeof(char));
	for (size_t i = 0; i < fsize; i++)
		s[i] = fgetc(f);

	file_s *tstur = (file_s *)malloc(sizeof(file_s));
	;
	tstur->arr = s;
	tstur->size = fsize;
	fclose(f);
	return tstur;
}

void init(list_t *l)
{
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
}

word_s *get(list_t *l, int i)
{
	struct word_s *result;
	if (i < ((l->size) / 2))
	{
		node_t *cur = l->head;
		struct word_s *result = cur->word;
		int count = 0;

		while (count != i)
		{
			cur = cur->next;
			result = cur->word;
			count++;
		}
		return result;
	}
	else
	{
		node_t *cur = l->tail;
		struct word_s *result = cur->word;
		int count = l->size - 1;

		while (count != i)
		{
			cur = cur->prev;
			result = cur->word;
			count--;
		}
		return result;
	}
}

void destroy_node(node_t *node)
{
	free(node->word->arr);
	free(node->word);
	free(node);
}

void destroy(list_t *l)
{
	node_t *cur = l->head;
	node_t *prev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		destroy_node(prev);
	}
	node_t *tail = NULL;
}

struct word_s *gen_word(char *ws, size_t sizews, int capws)
{
	word_s *w_t = (word_s *)malloc(sizeof(word_s));

	w_t->arr = ws;
	w_t->size = sizews;
	w_t->capacity = capws;
	return w_t;
}

void push_back(list_t *l, char *ws, size_t sizews, int capws)
{
	node_t *n, *cur;

	word_s *w_t = gen_word(ws, sizews, capws);
	n = (node_t *)malloc(sizeof(node_t));

	n->word = w_t;
	n->next = NULL;
	if (l->head == NULL)
	{
		n->prev = NULL;
		l->head = n;
	}
	else
	{
		cur = l->head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n;
		n->prev = cur;
	}
	l->tail = n;
	l->size++;
}

void readstr(char *tmp, size_t size, list_t *list)
{
	int len = 0;
	int capacity = 1;
	char *s = (char *)malloc(sizeof(char));
	for (size_t i = 0; i < size; i++)
	{
		if (is_char(tmp[i]) == 1)
		{
			s[(len)++] = tmp[i];
			if (len >= capacity)
			{
				capacity *= 2;
				s = (char *)realloc(s, capacity * sizeof(char));
			}
			if (i + 1 == size)
				goto last_char;
		}
		else
		{
		last_char:
			if (len != 0)
			{
				s[len] = '\0';

				push_back(list, s, len, capacity);
				len = 0;
				capacity = 1;
				s = (char *)malloc(sizeof(char));
			}
		}
	}
}

void list_remove(list_t *l, int index)
{
	node_t *cur = get_node(l, index);
	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	if (index == 0)
		if (l->head->next != NULL)
			l->head = l->head->next;
		else
			l->head = NULL;
	if (index == l->size - 1)
		if (l->tail->prev != NULL)
			l->tail = l->tail->prev;
		else
			l->tail = NULL;
	destroy_node(cur);
	l->size--;
}

int compare_words(char *w1, char *w2, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (w1[i] != w2[i])
			return 0;
	}
	return 1;
}

int find_word(list_t *l, int offset, char *temp, size_t temp_size)
{
	for (size_t i = offset; i < l->size; i++)
	{
		word_s *getted_word = get(l, i);
		if (getted_word->size == temp_size && compare_words(temp, getted_word->arr, temp_size))
			return i;
	}
	return -1;
}

void remove_duplicates(list_t *l)
{
	for (size_t i = 0; i < l->size; i++)
	{
		node_t *curr = get_node(l, i);
		int founded_word;
		while ((founded_word = find_word(l, i + 1, curr->word->arr, curr->word->size)) != -1)
			list_remove(l, founded_word);
	}
}

void print_list(list_t *l)
{
	for (size_t i = 0; i < l->size; i++)
	{
		printf("------------------------\n");
		word_s *temp = get(l, i);
		printf("%lu || %s\n", i, temp->arr);
		printf("------------------------\n\n");
	}
}

void merge_list_t(list_t *l, list_t *l_merge)
{
	int size = l->size;
	node_t *cur = l->head;
	for (size_t i = 0; i < size; i++)
	{
		word_s *tmp_str_word = cur->word;
		char *temp_word_arr = (char *)malloc(tmp_str_word->size * sizeof(char));
		for (size_t i = 0; i <= tmp_str_word->size; i++)
		{
			temp_word_arr[i] = tmp_str_word->arr[i];
		}
		push_back(l_merge, temp_word_arr, tmp_str_word->size, tmp_str_word->capacity);
		cur = cur->next;
	}
}

size_t sizecounter(list_t *l)
{
	size_t totalsize = 0;
	for (size_t i = 0; i < l->size; i++)
	{
		totalsize += get(l, i)->size;
		//printf("%d\n", totalsize);
	}
	return totalsize;

}

int main(int argc, char *argv[])
{
	file_s *filestruct1 = read_file("labs/lab6/lab06.txt");
	file_s *filestruct2 = read_file("labs/lab6/lab061.txt");
	file_s *filestruct3 = read_file("labs/lab6/lab062.txt");

	list_t list1, list2, list3;
	list_t merge1, merge2;
	init(&list1);
	init(&list2);
	init(&list3);
	init(&merge1);
	init(&merge2);

	readstr(filestruct1->arr, filestruct1->size, &list1);
	readstr(filestruct2->arr, filestruct2->size, &list2);
	readstr(filestruct3->arr, filestruct3->size, &list3);
	
	merge_list_t(&list1, &merge1);
	merge_list_t(&list2, &merge1);
	merge_list_t(&list1, &merge2);
	merge_list_t(&list3, &merge2);

	remove_duplicates(&merge1);
	remove_duplicates(&merge2);
	size_t totalsize1 = sizecounter(&merge1);
	size_t totalsize2 = sizecounter(&merge2);
	printf("%d - %d\n", totalsize1, totalsize2);
	if (totalsize1 < totalsize2)
		print_list(&merge1);
	else
		print_list(&merge2);

	destroy(&list1);
	destroy(&list2);
	destroy(&list3);
	destroy(&merge1);
	destroy(&merge2);
	free(filestruct1->arr);
	free(filestruct2->arr);
	free(filestruct3->arr);
	free(filestruct1);
	free(filestruct2);
	free(filestruct3);
	
	return 0;
}