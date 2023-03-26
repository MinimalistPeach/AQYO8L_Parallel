#include <stdio.h>
#include <stdlib.h>
#include "inputhandler.h"
#include "rng.h"

#define MAX_N 1000

void prefix_sum(int *a, int n)
{
    if (n <= 1) {
        return;
    }
    
    int i;
    int *b = malloc(n / 2 * sizeof(int));
    int *c = malloc(n / 2 * sizeof(int));
    for (i = 0; i < n / 2; i++) {
        b[i] = a[2 * i] + a[2 * i + 1];
        c[i] = b[i];
    }
    prefix_sum(b, n / 2);
    prefix_sum(c, n / 2);
    for (i = 0; i < n; i++) {
        if (i == 0) {
            a[i] = c[0];
        } else if (i % 2 == 1) {
            a[i] = c[i / 2];
        } else {
            a[i] = b[i / 2 - 1] + c[i / 2];
        }
    }
    free(b);
    free(c);
}

void generate_graph(int *a, int n, FILE *fp)
{
    fprintf(fp, "digraph {\n");
    fprintf(fp, "  node [shape=circle]\n");
    int i, j;
    int node_id = 0;
    for (i = 0; i < n; i++) {
        fprintf(fp, "  %d [label=\"%d\"]\n", node_id, a[i]);
        node_id++;
        for (j = i + 1; j < n; j++) {
            if ((i % 2 == 0 && j == i + 1) || (i % 2 == 1 && j == i + 2)) {
                fprintf(fp, "  %d -> %d [label=\"interval %d-%d\"]\n", i, node_id, i, j);
                break;
            }
        }
        if (i % 2 == 0 && i > 0) {
            fprintf(fp, "  %d -> %d [label=\"interval %d-%d\"]\n", i / 2 - 1, node_id, 0, i);
        }
    }
    fprintf(fp, "}\n");
}

int main()
{
    int n[1];
    printf("Adja meg a bemeneti adatok meretet: ");
    getIntegerInput(n, 1, 1, MAX_N);
    int a[MAX_N];
    int i;
    for (i = 0; i < n[0]; i++) {
        a[i] = rand() % 100;
    }
    prefix_sum(a, n[0]);
    FILE *fp = fopen("./outputs/graph.dot", "w");
    if (fp == NULL) {
        printf("Fajl nem hozhato letre!\n");
        return 1;
    }
    generate_graph(a, n[0], fp);
    fclose(fp);
    printf("A graf ki lett mentve a graph.dot nevu fajlba!\n");
    return 0;
}
