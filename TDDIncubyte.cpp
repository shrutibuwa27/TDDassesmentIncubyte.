#include <iostream>
using namespace std;

class Spacecraft {
private:
    int x, y, z;
    char direction;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection) {
        x = initialX;
        y = initialY;
        z = initialZ;
        direction = initialDirection;
    }

    void move(char command) {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            default:
                break;
        }
    }

    void turn(char command) {
        switch (command) {
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            case 'u':
                turnUp();
                break;
            case 'd':
                turnDown();
                break;
            default:
                break;
        }
    }

    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
            default:
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
            default:
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
            default:
                break;
        }
    }

    void turnRight() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
            default:
                break;
        }
    }

    void turnUp() {
        if (direction == 'N' || direction == 'S') {
            direction = 'U';
        }
    }

    void turnDown() {
        if (direction == 'N' || direction == 'S') {
            direction = 'D';
        }
    }

    void printCoordinates() {
        cout << "Current Coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    int startX = 0, startY = 0, startZ = 0;
    char startDirection = 'N';

    Spacecraft chandrayaan(startX, startY, startZ, startDirection);

    char commands[] = {'f', 'r', 'f', 'b', 'u', 'l'};
    int numCommands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < numCommands; i++) {
        char command = commands[i];

        if (command == 'f' || command == 'b') {
            chandrayaan.move(command);
        } else {
            chandrayaan.turn(command);
        }
    }

    chandrayaan.printCoordinates();

    return 0;
}