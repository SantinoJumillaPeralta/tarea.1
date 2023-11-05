#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

class Crosshair {
public:
    Crosshair(sf::Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.3f, 0.3f);
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    sf::Sprite getSprite() {
        return sprite;
    }

private:
    sf::Sprite sprite;
};

class Enemy {
public:
    Enemy(sf::Texture& texture) {
        sprite.setTexture(texture);
        sprite.setScale(0.2f, 0.2f);
        sprite.setPosition(rand() % 600, rand() % 400);
    }

    sf::Sprite getSprite() {
        return sprite;
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

private:
    sf::Sprite sprite;
};

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);
    sf::Texture etTexture, crosshairTexture;

    if (!etTexture.loadFromFile("et.png") || !crosshairTexture.loadFromFile("crosshair.png")) {
        return -1;
    }

    Crosshair crosshair(crosshairTexture);
    std::vector<Enemy> enemies;
    int enemiesDefeated = 0;

    while (window.isOpen() && enemiesDefeated < 5) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (auto it = enemies.begin(); it != enemies.end(); ++it) {
                    sf::FloatRect bounds = it->getSprite().getGlobalBounds();

                    if (bounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                        enemies.erase(it);
                        enemiesDefeated++;
                        break;
                    }
                }
            }
        }

        if (enemies.size() < 5 && rand() % 100 < 5) {
            enemies.emplace_back(etTexture);
        }

        window.clear(sf::Color::Black);
        window.draw(crosshair.getSprite());

        for (const auto& enemy : enemies) {
            window.draw(enemy.getSprite());
        }

        window.display();
    }

    return 0;
}
