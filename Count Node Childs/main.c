#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct StackNode
{
    char c;
    struct StackNode* next;
} StackNode;

typedef struct Stack
{
    int size;
    StackNode* top;
} Stack;

Stack* stack_init(void)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

StackNode* create_stack_node(char c)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->c = c;
    node->next = NULL;
    return node;
}

void stack_push(Stack* stack, char c) {
    StackNode* new_node = create_stack_node(c);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

char stack_pop(Stack* stack)
{
    StackNode* temp = stack->top;
    if (temp == NULL)
    {
        return '\0';
    }
    char c = temp->c;
    stack->top = stack->top->next;
    stack->size--;
    free(temp);
    return c;
}

char stack_is_empty(Stack* stack)
{
    return (stack->top == NULL);
}

void stack_free(Stack* stack)
{
    StackNode* current = stack->top;
    while (current != NULL)
    {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

int get_child_counts(char* str, char target)
{
    if (str == NULL) {
        return -1;
    }

    char* c = str;

    while ((*c) != '\0')
    {
        if ((*c) == target)
        {
            char* current = c + 1;
            if ((*current) == '(')
            {
                Stack* stack = stack_init();
                while (true)
                {
                    if ((*current) == ' ' || (*current) == ',')
                    {
                        current++;
                        continue;
                    }
                    if ((*current) == ')')
                    {
                        int counts = 0;
                        while (stack_pop(stack) != '(')
                        {
                            counts++;
                        };
                        if (stack_is_empty(stack)) {
                            stack_free(stack);
                            return counts;
                        }
                        current++;
                        continue;
                    }
                    stack_push(stack, *current);
                    current++;
                }
            } else
            {
                return 0;
            }
        }
        c++;
    }
    return 0;
}

int get_child_counts_by_chatGPT(char* str, char target) {
    char* c = str;

    while (*c != '\0') {
        if (*c == target) {
            char* current = c + 1;
            if (*current == '(') {
                int counts = 0;
                int depth = 1;
                current++;  // Skip '('

                while (*current != '\0' && depth > 0) {
                    if (*current == '(') {
                        depth++;
                    } else if (*current == ')') {
                        depth--;
                    } else if (depth == 1 && *current != ' ' && *current != ',') {
                        counts++;  // Only count direct children
                    }
                    current++;
                }

                return counts;
            } else {
                return 0;
            }
        }
        c++;
    }
    return 0;
}

int main(void) {
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'C') == 3);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'G') == 0);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'H') == 2);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'M') == 1);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'N') == 0);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'I') == 0);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'D') == 1);
    assert(get_child_counts("C(G, H(L, M(N)), I), D(J)))", 'J') == 0);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'A') == 2);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'B') == 2);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'E') == 2);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'C') == 0);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'D') == 0);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'F') == 0);
    assert(get_child_counts("A(B(C, D), E(F, G))", 'G') == 0);
    assert(get_child_counts("X(Y(Z))", 'X') == 1);
    assert(get_child_counts("X(Y(Z))", 'Y') == 1);
    assert(get_child_counts("X(Y(Z))", 'Z') == 0);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'P') == 2);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'Q') == 2);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'R') == 2);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'S') == 0);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'T') == 0);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'U') == 0);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'V') == 1);
    assert(get_child_counts("P(Q(R(S, T), U), V(W))", 'W') == 0);

    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'C') == 3);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'G') == 0);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'H') == 2);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'M') == 1);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'N') == 0);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'I') == 0);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'D') == 1);
    assert(get_child_counts_by_chatGPT("C(G, H(L, M(N)), I), D(J)))", 'J') == 0);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'A') == 2);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'B') == 2);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'E') == 2);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'C') == 0);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'D') == 0);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'F') == 0);
    assert(get_child_counts_by_chatGPT("A(B(C, D), E(F, G))", 'G') == 0);
    assert(get_child_counts_by_chatGPT("X(Y(Z))", 'X') == 1);
    assert(get_child_counts_by_chatGPT("X(Y(Z))", 'Y') == 1);
    assert(get_child_counts_by_chatGPT("X(Y(Z))", 'Z') == 0);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'P') == 2);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'Q') == 2);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'R') == 2);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'S') == 0);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'T') == 0);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'U') == 0);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'V') == 1);
    assert(get_child_counts_by_chatGPT("P(Q(R(S, T), U), V(W))", 'W') == 0);
    printf("All tests passed!\n");
    return 0;
}