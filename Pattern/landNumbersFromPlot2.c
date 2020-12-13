#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EARTH '@'
#define WATER '.'

int row, col;
int count=0;

typedef struct {
    size_t width;
    size_t height;
    char *data;
} Map;

void display_map(const Map *map);
void process_map(const Map *src_map, Map *dst_map);

void check_map(const Map *map) {
    size_t size = map->data ? strlen(map->data) : 0;
    if (size != map->width * map->height) {
        fprintf(stderr, "Invalid size: %lu != %lux%lu\n", size, map->width, map->height);
//        exit(1);
    }
}

int main(void) {

    // Declare the map
    Map map = { 20, 10, (char *)
        "...@@@@@@.@..@..@@.."
        "..@@@........@.....@"
        "@@@.@@...@..@......."
        ".@..@@@.@.@@@....@@@"
        "..@@...@@@@.@..@.@@."
        "...@@@.@@....@@@..@@"
        "@@@.@@..@.@@@...@@.@"
        "@@@.@.@@@.@.@.@..@.."
        "@.@@..@@@..@..@..@.."
        "@@@@@.....@....@.@@@"
    };
/*
	row=300;
	for(col=0; col<row; col++)
	{
		printf("%c ", map.data[col]);
        	if(col%20==0)
			printf("\n");
	}
  */  Map new_map = { 0, 0, NULL };

    check_map(&map);
    process_map(&map, &new_map);
    check_map(&new_map);

    // Display the maps
    printf("Raw map:\n");
    display_map(&map);
    printf("\nProcessed map:\n");
    display_map(&new_map);

    // Free what should have been allocated
    if (new_map.data) {
        free(new_map.data);
    }

    return 0;
}

/* Write your own code below */

void display_map(const Map *map) {
    int i, j,
    r = map->height,
    c = map->width;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%c", map->data[(i*c)+j]);
        }
        printf("\n");
    }
}

void changeFunction(char* plot, char c, int i, int j)
{
    plot[(i*col)+j]=c;
    if(j-1>=0 && plot[(i*col)+j-1]=='@')
        changeFunction(plot, c, i, j-1);
    if((j+1)<col && plot[(i*col)+j+1]=='@')
        changeFunction(plot, c, i, j+1);
    if((i+1)<row && plot[((i+1)*col)+j]=='@')
        changeFunction(plot, c, i+1, j);
    if((i-1)>=0 && plot[((i-1)*col)+j]=='@')
        changeFunction(plot, c, i-1, j);
    return;
}

void process_map(const Map *src, Map *dst)
{
    char nc='A';
    int i, j;
    row = src->height;
    col = src->width;
    //printf("%d %d %d %d\n",row, col, row*col, strlen(src->data));
    //allocate memory to new_map
    dst->height = src->height;
    dst->width  = src->width;
    dst->data = (char*)malloc(row*col);
    memcpy(dst->data, src->data, row*col);//strlen(src->data)+1);
    
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(dst->data[(i*col)+j]=='@')
            {
                changeFunction(dst->data, nc, i, j);
                nc++;
            }
        }
	printf("Row %d complete..!!\n", i);
    }
    printf("Total land count = %d\n", nc-65);
}
