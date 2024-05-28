#include <stdio.h>
#include <stdlib.h>
 
int cmp(const void *a, const void *b) // conditie pt sortare descrescatoare
{
    return (*(int *)b - *(int *)a);
}
 
int main()
{
    FILE *fin, *fout;
    fin = fopen("date.in", "r");
    fout = fopen("date.out", "w");
 
    int n = 0;
    int *v = malloc(n * sizeof(int)); // vectorul de pagini
    int *gramada = malloc(n * sizeof(int)); // vectorul de apartenenta la gramezi(1, 2 sau 3)
 
    fscanf(fin, "%d", &n);
    for(int i = 0; i < n; i++)
        fscanf(fin, "%d", &v[i]); // citim vectorul
 
    qsort(v, n, sizeof(int), cmp); // sortam descrescator vectorul pentru a aplica metoda greedy
 
    int gr[3] = {0, 0, 0};
    for(int i = 0; i < n; i++)
    {
        int min = 0; // alegem grupa cu nr de pagini minim
        if(gr[1] < gr[min])
            min = 1;
        if(gr[2] < gr[min])
            min = 2;
 
        gr[min] += v[i];
        gramada[i] = min + 1; // notam in ce gramada apartine cartea cu indexul i
    }
 
    // afisare
 
    fprintf(fout, "Gramada 1:");
    for(int i = 0; i < n; i++)
        if(gramada[i] == 1)
            fprintf(fout, "%d ", v[i]);
    fprintf(fout, "=> Suma: %d\n", gr[0]);
 
    fprintf(fout, "Gramada 2:");
    for(int i = 0; i < n; i++)
        if(gramada[i] == 2)
            fprintf(fout, "%d ", v[i]);
    fprintf(fout, "=> Suma: %d\n", gr[1]);
 
    fprintf(fout, "Gramada 3:");
    for(int i = 0; i < n; i++)
        if(gramada[i] == 3)
            fprintf(fout, "%d ", v[i]);
    fprintf(fout, "=> Suma: %d\n", gr[2]);
 
    // eliberam memoria
    free(v);
    free(gramada);   
 
    return 0;
}