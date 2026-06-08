#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

struct node {
    int data;
    struct node* next;
};


struct node* arrayNaarLinkedList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    struct node* head = NULL;
    struct node* current = NULL;

    for (int i = 0; i < n; i++)
    {
        // allocate nieuwe node
        struct node* nieuw = malloc(sizeof(struct node));
        if (nieuw == NULL) {
            printf("Malloc fout!\n");
            exit(1);
        }

        nieuw->data = arr[i];     // kopie van data
        nieuw->next = NULL;

        if (head == NULL) {
            head = nieuw;
            current = nieuw;
        }
        else {
            current->next = nieuw;
            current = nieuw;
        }
    }

    return head;
}


void printList(struct node* head)
{
    struct node* p = head;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
}


struct node* deleteNodeAt(struct node* head, int position)
{
    // Als lijst leeg is
    if (head == NULL)
        return NULL;

    // Als eerste node moet worden verwijderd
    if (position == 0) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }


    struct node* current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    // Als positie buiten de lijst valt
    if (current == NULL || current->next == NULL)
        return head;

    struct node* temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

struct node* deleteFirstNegative(struct node* head)
{

    if (head == NULL)
        return head;

    if (head->data < 0) 
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
	}

	struct node* current = head;

	while (current->next != NULL && current->next->data >= 0) 
    {
        current = current->next;
    }

    if (current-> next == NULL)
		return head;

	struct node* temp = current->next;
	current->next = temp->next;
	free(temp);

    return head;
}

struct node* insertAt(struct node* head, int positie, int waarde)
{
    // nieuwe node maken
    struct node* nieuw = malloc(sizeof(struct node));
    if (nieuw == NULL) {
        printf("Malloc fout!\n");
        exit(1);
    }
    nieuw->data = waarde;
    nieuw->next = NULL;

    if (positie == 0) {
        nieuw->next = head;
        return nieuw;     // nieuwe head
    }

    struct node* current = head;
    for (int i = 0; current != NULL && i < positie - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        free(nieuw);   // want we voegen niet toe
        return head;
    }

    nieuw->next = current->next;
    current->next = nieuw;

    return head;
}

struct node* voegAchteraanToe(struct node* head, int waarde)
{
    // Maak nieuwe node
    struct node* nieuw = malloc(sizeof(struct node));
    if (nieuw == NULL) {
        printf("Malloc fout!\n");
        exit(1);
    }

    nieuw->data = waarde;
    nieuw->next = NULL;

    // Als de lijst leeg is, wordt dit de eerste node
    if (head == NULL) {
        return nieuw;
    }

    // Anders: ga naar de laatste node
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Voeg de nieuwe node achteraan toe
    current->next = nieuw;

    return head;
}

struct node* deleteFirst(struct node* head)
{
    // Als de lijst leeg is, doe niets
    if (head == NULL)
        return NULL;

    // Bewaar oude head
    struct node* temp = head;

    // Nieuwe head wordt de volgende node
    head = head->next;

    // Oude eerste node verwijderen
    free(temp);

    return head;
}

struct node* push(struct node* head, int waarde)
{
    struct node* nieuw = malloc(sizeof(struct node));
    if (nieuw == NULL) {
        printf("Malloc fout!\n");
        exit(1);
    }

    nieuw->data = waarde;
    nieuw->next = head;   // nieuwe node wordt de nieuwe eerste node
    return nieuw;         // nieuwe head
}

int main(void)
{
    int arr[] = { 10, -5, 20, -2, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);

    struct node* head = arrayNaarLinkedList(arr, n);

    printf("Oorspronkelijke linked list:\n");
    printList(head);

    head = deleteNodeAt(head, 2);

    printf("\nLinked list na verwijderen node op positie 2:\n");
    printList(head);

    head = deleteFirstNegative(head);

    printf("\nLinked list na verwijderen eerste negatieve waarde:\n");
    printList(head);

    printf("\nVoeg 99 toe op positie 2:\n");
    head = insertAt(head, 2, 99);
    printList(head);

    head = voegAchteraanToe(head, 99);

    printf("\nLinked list na toevoegen 99 aan het einde:\n");
    printList(head);

    printf("\nLinked list na verwijderen van de eerste node:\n");
    head = deleteFirst(head);
    printList(head);

    printf("\n--- Queue demonstratie ---\n");

    // Start met een lege queue
    struct node* queue = NULL;

    // ENQUEUE 10
    queue = voegAchteraanToe(queue, 10);
    printf("Na enqueue 10: ");
    printList(queue);

    // ENQUEUE 20
    queue = voegAchteraanToe(queue, 20);
    printf("Na enqueue 20: ");
    printList(queue);

    // ENQUEUE 30
    queue = voegAchteraanToe(queue, 30);
    printf("Na enqueue 30: ");
    printList(queue);

    // DEQUEUE (verwacht 10 verdwijnt)
    queue = deleteFirst(queue);
    printf("Na dequeue (10 is weg): ");
    printList(queue);

    // DEQUEUE (verwacht 20 verdwijnt)
    queue = deleteFirst(queue);
    printf("Na dequeue (20 is weg): ");
    printList(queue);

    // ENQUEUE 40
    queue = voegAchteraanToe(queue, 40);
    printf("Na enqueue 40: ");
    printList(queue);

    // DEQUEUE (verwacht 30 verdwijnt)
    queue = deleteFirst(queue);
    printf("Na dequeue (30 is weg): ");
    printList(queue);

    printf("\n--- Stack demonstratie ---\n");

    struct node* stack = NULL;

    // PUSH 10
    stack = push(stack, 10);
    printf("Na push 10: ");
    printList(stack);

    // PUSH 20
    stack = push(stack, 20);
    printf("Na push 20: ");
    printList(stack);

    // PUSH 30
    stack = push(stack, 30);
    printf("Na push 30: ");
    printList(stack);

    // POP (verwacht 30 verdwijnt)
    stack = deleteFirst(stack);
    printf("Na pop (30 is weg): ");
    printList(stack);

    // POP (verwacht 20 verdwijnt)
    stack = deleteFirst(stack);
    printf("Na pop (20 is weg): ");
    printList(stack);

    printf("Bekijk de linked list in het Memory Window.\n");

    return 0;
}