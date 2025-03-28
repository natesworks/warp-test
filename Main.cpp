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

void onClick(Game& game, Object& object)
{
    int randomX = rand() % game.getWindowWidth();
    int randomY = rand() % game.getWindowHeight();
    object.setPosition(Vector2(randomX, randomY));
}

int main()
{
    Game game = Game(960, 540, "Portal 3");
    game.addObject(Object(&game, Vector2(0, 0), Vector2(100, 100), 25, RGB(0, 0, 255)));
    Object* player = game.getObject(0);
    FilledRectangle rectangle(player);
    player->addComponent(std::move(rectangle));
    PlayerMovement playerMovement(player, 15);
    player->addComponent(std::move(playerMovement));
    BoxCollider collider(player, false);
    player->addComponent(std::move(collider));
    //Rectangle hitbox(object);
    //object->addComponent(std::move(hitbox));

    game.addObject(Object(&game, Vector2(450, 450), Vector2(100, 100), 25, RGB(255, 0, 0)));
    Object* object2 = game.getObject(1);
    FilledEllipse ellipse(object2);
    object2->addComponent(std::move(ellipse));
    Button button2(object2, [&game, &object2]() { onClick(game, *object2); });
    object2->addComponent(std::move(button2));
    Rectangle hitbox2(object2);
    object2->addComponent(std::move(hitbox2));

    game.start();

    while (true) {}

    return 0;
}