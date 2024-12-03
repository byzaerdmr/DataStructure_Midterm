#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList{
    char data;
    struct linkedList *next;
}SIMPLE_LIST;

SIMPLE_LIST *first = NULL;
SIMPLE_LIST *last = NULL;   

//insersiton 
int insert( SIMPLE_LIST *p)
{
    if(first != NULL)
    {
        last->next = p;
        p -> next = NULL;
        last = p;
    }
    else
    {
        first = p;
        last = p;
        p -> next = NULL;
    }
    return 0;
}

//traversing
int displayList() {
    SIMPLE_LIST *p;
    p = first;
    while(p == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    while(p != NULL)
    {
        printf("%d %s\n", p->data);
        p = p->next;
    }
    return 0;
}

//searching
SIMPLE_LIST *search(int key)
{
    SIMPLE_LIST *p;
    p = first;
    while(p != NULL)
    {
        if(p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//deletion
SIMPLE_LIST *delete(int key) {
    SIMPLE_LIST *p, *previous;
    p = first;
    previous = NULL;

    // Arama işlemi
    while (p != NULL) {
        if (key == p->data) 
            break;
        
        previous = p;
        p = p->next;
    }

    // Eğer p NULL değilse (eleman bulunduysa)
    if (p != NULL) {
        if (previous == NULL) { 
            // Silinecek eleman listenin başında
            if (first == last) { 
                // Liste sadece bir elemandan oluşuyorsa
                first = NULL;
                last = NULL;
            } else {
                // Liste birden fazla elemandan oluşuyorsa
                first = first->next;
            }
        } else {
            // Silinecek eleman listenin ortasında veya sonunda
            previous->next = p->next;
            if (previous->next == NULL) {
                // Eğer silinen eleman son eleman ise
                last = previous;
            }
        }

        // Bellek temizleme
        free(p);
        return p;
    } else {
        // Eleman bulunamadıysa
        printf("Key not found\n");
        return NULL;
    }
}

int main()
{
    SIMPLE_LIST *p;
    p = (SIMPLE_LIST *)malloc(sizeof(SIMPLE_LIST));
    p->data = 'A';
    insert(p);

    p = (SIMPLE_LIST *)malloc(sizeof(SIMPLE_LIST));
    p->data = 'B';
    insert(p);

    p = (SIMPLE_LIST *)malloc(sizeof(SIMPLE_LIST));
    p->data = 'C';
    insert(p);

    displayList();

    p = search('B');
    if(p != NULL)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }

    p = delete('B');
    if(p != NULL)
    {
        printf("Key deleted\n");
    }
    else
    {
        printf("Key not found\n");
    }

    displayList();

    return 0;
}
