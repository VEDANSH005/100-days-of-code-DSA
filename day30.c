/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *head = NULL;
void insertTerm(int coeff, int exp)
{
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (head == NULL || exp > head->exp) 
    {
        newNode->next = head;
        head = newNode;
    } else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp >= exp)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void display() {
    struct node *temp = head;
    while (temp != NULL) 
    {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    int n, coeff, exp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &coeff, &exp);
        insertTerm(coeff, exp);
    }

    display();

    return 0;
}