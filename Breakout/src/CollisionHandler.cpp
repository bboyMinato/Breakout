#include "../include/CollisionHandler.h"

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    bool x_overlaps = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_overlaps = (a.y < b.y + b.h) && (a.y + a.h > b.y);

    return (x_overlaps && y_overlaps);
}

bool CollisionHandler::CheckCollision(Entity* a, Entity* b)
{
    bool x_overlaps = (a->_box.x < b->_box.x + b->_box.w) && (a->_box.x + a->_box.w > b->_box.x);
    bool y_overlaps = (a->_box.y < b->_box.y + b->_box.h) && (a->_box.y + a->_box.h > b->_box.y);

    return (x_overlaps && y_overlaps);
}
