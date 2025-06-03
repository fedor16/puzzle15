#include <iostream>
#include "board.h"

int main() {
    Board game;
    game.shuffle();

    std::cout << "Игра '15'. Введите число плитки для перемещения:\n\n";

    while (!game.isSolved()) {
        game.display();

        std::cout << "\nВведите номер плитки для перемещения: ";
        int tile;
        std::cin >> tile;

        if (!game.moveTile(tile)) {
            std::cout << "Неверный ход. Попробуйте снова.\n";
        }
        std::cout << "\n";
    }

    std::cout << "Поздравляем! Вы решили головоломку.\n";
    return 0;
}
