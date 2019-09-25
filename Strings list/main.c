#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200



typedef struct Node Node;
typedef struct List List;
struct Node {
	char* string;
	struct Node* next;
};

struct List {
	struct Node *first;
}List_;

List* create_list(void) {
	List* List_ = (List*)malloc(sizeof(List));
	if(List_ != NULL)
		List_->first = NULL;
	return List_;
}

Node* new_elem(void) {
	Node *elem = (Node*)malloc(sizeof(Node));
	if (elem != NULL) {
		elem->next = NULL;
	}
	return elem;
}

void insert_elem(List* list, char* str) {
	if (list == NULL || str == NULL)
		return;

	if (list->first == NULL)
	{
		Node* elem = new_elem();

		if (elem != NULL) {
			list->first = elem;
			elem->string = malloc(sizeof(char)*(strlen(str)+1));

			if (elem->string != NULL) {
				strcpy(elem->string, str);
				elem->next = NULL;
			}
			else
				return;
		}
		else
			return;
	}
	else {
		Node * current = list->first;
		while (current->next != NULL) 
			current = current->next;
				
		current->next = new_elem();

		if (current->next != NULL)
		{
			current->next->string = malloc(sizeof(char)*(strlen(str) + 1));

			if (current->next->string != NULL) {
				strcpy(current->next->string, str);
				current->next->next = NULL;
			}
			else 
				return;
			
			
			
		}
		else 
			return; //can't allocate
	}
}


void printlist(List* list) {
	if (list) {
		Node* current = list->first;

		while (current != NULL) {
			printf("%s", current->string);
			current = current->next;
		}
	}
	
}

void freelist(List* list)
{
	if (list != NULL) {
		Node* current = list->first;
	
		while (current != NULL) {
			if(current->string != NULL) 
				free(current->string);
			Node* temp = current;
			current = current->next;
			free(temp);
		}
	}
}

char* get_string(const char* buf, size_t size, FILE* file) {

	if (buf == NULL || file == NULL)
		return NULL;

	const char* ptr = fgets(buf, size, stdin);

	if (ptr != NULL) {
		size_t size = strlen(ptr);
		while (ptr[strlen(ptr)-1] != '\n') { //means that didn't finish reading
			
		}
		
	}

	return ptr;
}



int main(void)
{
	List* List_ = create_list();
	if (List_ != NULL) {
		const char buf[MAX_SIZE];

		while (1) {

			char* string = get_string(&buf, MAX_SIZE, stdin);

			if (string == NULL) {
				perror("Malloc: couldn't allocate memory");
				return -1;
			}

			size_t str_len = strlen(string);
			if (string[0] != '.') {
				insert_elem(List_, string);
			}
			else
				break;

		}
		printlist(List_);
		freelist(List_);
	}
	return 0;
}
