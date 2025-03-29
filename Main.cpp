#include <iostream>
#include <thread>

#include "warpengine/WarpEngine.h"

void onClick(Game &game, Object *object)
{
    int randomX = rand() % game.getWindowWidth();
    int randomY = rand() % game.getWindowHeight();
    object->setPosition(Vector2(randomX, randomY));
}

int main()
{
    Game game = Game(960, 540, "Portal 3");
    Object *player = game.addObject(Vector2(100, 100), Vector2(100, 100), 0, RGB(0, 0, 255));
    player->addComponent<FilledRectangle>();
    player->addComponent<PlayerMovement>(15);
    player->addComponent<BoxCollider>();

    Object *circle = game.addObject(Vector2(450, 450), Vector2(100, 100), 0, RGB(255, 0, 0));
    circle->addComponent<FilledEllipse>();
    circle->addComponent<Button>(std::function<void()>([&game, circle]() {
        onClick(game, circle);
    }));
    

    Object *square = game.addObject(Vector2(200, 200), Vector2(100, 100), 0, RGB(0, 255, 0));
    square->addComponent<Rectangle>();
    square->addComponent<BoxCollider>(std::function<void()>([&game, &square]()
                                      { std::cout << "Collided with square" << std::endl; }));

    Object *square2 = game.addObject(Vector2(400, 700), Vector2(100, 100), 0, RGB(255, 255, 0));
    square2->addComponent<Rectangle>();
    square2->addComponent<BoxCollider>();

    game.start();

    while (true)
    {
    }

    return 0;
}