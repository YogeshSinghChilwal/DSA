#include<stdio.h>
#include<stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter number of terms: ");
    scanf("%d", &p->n);
    p->terms = (struct Term * )malloc(p->n * sizeof(struct Term));

    for(int i = 0; i < p->n; i++)
    {
        printf("Enter Term number %d  ", i + 1);
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    for(int i = 0; i < p.n; i++)
    {
        printf("%dx^%d+", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}

struct Poly * add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    i = j = k = 0;
    struct Poly *sum;
    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    while(i < p1->n && j < p2->n)
    {
        if(p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p2->terms[j].exp > p1->terms[i].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff; 
        }
    }

    for(; i < p1->n; i++) sum->terms[k++] = p1->terms[i];
    for(; j < p2->n; j++) sum->terms[k++] = p2->terms[j];

    sum->n = k;

    return sum; 
}

int main()
{
    struct Poly p1, p2, *sum;

    create(&p1);
    create(&p2);


    printf("First polynomial \n");
    display(p1);

    printf("Second polynomial \n");
    display(p2);

    sum = add(&p1, &p2);

    printf("Sum \n");
    display(*sum);

    return 0;
}