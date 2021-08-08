#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct Vector2i
{
    int x;
    int y;
} Vector2i;

Vector2i vector2i_create(int x, int y) {
    Vector2i newVector2i;
    newVector2i.x = x;
    newVector2i.y = y;
    return newVector2i;
}

#endif
