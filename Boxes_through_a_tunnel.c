#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41


#define MAX_HEIGHT 41

// Define the box structure
struct box {
    int length;
    int width;
    int height;
};

typedef struct box box;

// Return the volume of the box
int get_volume(box b) {
    return b.length * b.width * b.height;
}

// Return 1 if height < MAX_HEIGHT, else 0
int is_lower_than_max_height(box b) {
    return b.height < MAX_HEIGHT;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i]))
			printf("%d\n", get_volume(boxes[i]));
	}
	return 0;
}
