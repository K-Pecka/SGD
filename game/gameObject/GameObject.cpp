#include "GameObject.h"

void GameObject::toString() const{
    std::cout<<"Object Info:"<<std::endl;
    std::cout<<"{ x: "<<getX()<<",y: "<<getY()<<",height: "<<getHeight()<<",width: "<<getWidth()<<" }"<<std::endl;
}

void GameObject::render(SDL_Renderer * render) {
    SDL_SetRenderDrawColor(render, rgba.red, rgba.green, rgba.blue, rgba.alfa);
    SDL_Rect rect = {int(x), int(y), int(width), int(height)};
    SDL_RenderFillRect(render, &rect);
}
void GameObject::move(Direction direction,int dx,int dy){
    switch (direction) {
        case Direction::LEFT:
        case Direction::RIGHT:
            setXplus(dx);
            break;
        case Direction::UP:
        case Direction::DOWN:
            setYplus(dy);
            break;
    }
}
