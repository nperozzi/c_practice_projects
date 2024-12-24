#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

void read_point(struct point *ptr);
void print_polygon(struct point *ptr, int *ptr_num_vertices);

int main(void)
{
    struct point *polygon;

    int num_vertices;
    printf("How many vertices does your polygon have? ");
    scanf("%d", &num_vertices);
    polygon = (struct point *) malloc(sizeof(struct point) * num_vertices);

    for (int i = 0; i < num_vertices; i++){
        printf("Enter vertice number %d: ", i);
        printf("\n");
        read_point(&polygon[i]);
    }

    print_polygon(polygon, &num_vertices);
    free(polygon);
    return 0;
}

void read_point(struct point *ptr){
    printf("Enter x coord: ");
    scanf("%d", &ptr->x);
    printf("Enter y coord: ");
    scanf("%d", &ptr->y);
}

void print_point(struct point *ptr){
    printf("(%d, %d)\n", ptr->x, ptr->y);
}

void print_polygon(struct point *ptr, int *ptr_num_vertices){
    for(int i = 0; i < *ptr_num_vertices; i++){
        print_point(ptr+i);
    }
}
