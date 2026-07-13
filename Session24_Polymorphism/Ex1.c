    #include <stdio.h>

    // Define a generic "shape" structure
    struct Shape {
        void (*draw)(void*); // Function pointer for drawing
        // Other common attributes
    };

    // Define specific shape structures
    struct Circle {
        struct Shape base; // Embed the base shape
        int radius;
    };

    struct Square {
        struct Shape base; // Embed the base shape
        int side;
    };

    // Specific drawing functions
    void draw_circle(void* self) {
        struct Circle* circle = (struct Circle*)self;
        printf("Drawing a circle with radius %d\n", circle->radius);
    }

    void draw_square(void* self) {
        struct Square* square = (struct Square*)self;
        printf("Drawing a square with side %d\n", square->side);
    }

    int main() {
        struct Circle my_circle = {{draw_circle}, 5};
        struct Square my_square = {{draw_square}, 10};

        // Treat both as generic shapes
        struct Shape* shapes[] = {(struct Shape*)&my_circle, (struct Shape*)&my_square};

        for (int i = 0; i < 2; i++) {
            shapes[i]->draw(shapes[i]); // Polymorphic call
        }

        return 0;
    }