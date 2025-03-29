#include <iostream>
#include <thread>

#include "warpengine/Game.h"
#include "warpengine/Types/Object.h"
#include "warpengine/Components/FilledRectangle.h"
#include "warpengine/Components/Rectangle.h"
#include "warpengine/Components/FilledEllipse.h"
#include "warpengine/Components/Button.h"
#include "warpengine/Components/PlayerMovement.h"
#include "warpengine/Components/BoxCollider.h"

void onClick(Game &game, Object *object)
{
    int randomX = rand() % game.getWindowWidth();
    int randomY = rand() % game.getWindowHeight();
    object->setPosition(Vector2(randomX, randomY));
}

int main()
{
    Game game = Game(960, 540, "Portal 3");
    Object *player = game.addObject(new Object(&game, Vector2(100, 100), Vector2(100, 100), 0, RGB(0, 0, 255)));
    player->addComponent(new FilledRectangle(player));
    player->addComponent(new PlayerMovement(player, 15));
    player->addComponent(new BoxCollider(player));

    Object *circle = game.addObject(new Object(&game, Vector2(450, 450), Vector2(100, 100), 0, RGB(255, 0, 0)));
    circle->addComponent(new FilledEllipse(circle));
    circle->addComponent(new Button(circle, [&game, circle]()
                                    { onClick(game, circle); }));

    Object *square = game.addObject(new Object(&game, Vector2(200, 200), Vector2(100, 100), 0, RGB(0, 255, 0)));
    square->addComponent(new Rectangle(square));
    square->addComponent(new BoxCollider(square, [&game, &square]()
                          { std::cout << "Collided with square" << std::endl; }));

    Object *square2 = game.addObject(new Object(&game, Vector2(400, 700), Vector2(100, 100), 0, RGB(255, 255, 0)));
    square2->addComponent(new Rectangle(square2));
    square2->addComponent(new BoxCollider(square2));

    game.start();

    while (true) {}

    return 0;
}