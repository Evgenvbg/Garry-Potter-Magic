#include "Game.h"
#include "Fire.h"

Game::Game()
{
    win = new RenderWindow(VideoMode(800, 800), "GPotter");
}

void Game::start()
{
    

    Texture tex;
    tex.loadFromFile("gallery_10492_49_5214.png");//Potter

    Texture ball;
    ball.loadFromFile("Fireball-PNG-HD-Quality.png");  //Fireball


    Sprite fireball;
    fireball.setOrigin(0, 0);
    fireball.rotate(120.f);
    fireball.setScale(Vector2f(0.1, 0.1));
    
    fireball.setTexture(ball);
    fireball.setPosition(Vector2f(400, 700));
    

    Sprite sprite;
    sprite.setScale(4, 3);
    sprite.setPosition(Vector2f(300, 100));
    sprite.setTexture(tex);
    sprite.setTextureRect(IntRect(0, 0, 32, 48));
    Color color(Color(43, 133, 133, -300));

    float animationState = 0;
    float animSpeed = 5;

    Clock clc;

    int dir = 0;

    while (win->isOpen())
    {
        sf::Event event;
        while (win->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win->close();
        }


        if (Keyboard::isKeyPressed(Keyboard::D)) {
            sprite.move(0.03, 0);
            dir = 2;
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            sprite.move(-0.03, 0);
            dir = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            sprite.move(0, -0.02);
            dir = 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            sprite.move(0, 0.02);
            dir = 0;
        }
        //создаем фаербол
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            Fire* f = new Fire(300, 200, Vector2f(0.01, 0));
            fire.push_back(f);

        }

        

       

        auto elapsed = clc.restart().asSeconds();

        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S));


        animationState += animSpeed * elapsed;
        if (animationState >= 4) {
            animationState -= 4;
        }
        sprite.setTextureRect(IntRect(floor(animationState) * 32, dir * 48, 32, 48));


        win->clear(color);
        win->draw(sprite);

        win->draw(fireball);
        
        

        win->display();
    }

    for (auto fb : fire) {
        fb->update();
    }

}

Game::~Game()
{
    delete win;
}
