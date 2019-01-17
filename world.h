#ifndef WORLD_H
#define WORLD_H
#define WSize 100

class world
{
public:
    world() {
        for (int i = 0; i<WSize; i++) {
            for (int j = 0; j<WSize; j++) {
                life[i][j] = false;
            }
        }
    }
    world(const world &other) {
        for (int i = 0; i<WSize; i++) {
            for (int j = 0; j<WSize; j++) {
                life[i][j] = other.life[i][j];
            }
        }
    }
    ~world() {

    }
    world operator=(const world&other) {
        if (this == &other)
            return *this;
        for (int i = 0; i<WSize; i++) {
            for (int j = 0; j<WSize; j++) {
                life[i][j] = other.life[i][j];
            }
        }
    }
    bool& operator()(int row, int column) {
        if (row < 0) {
            row = WSize + row;
        }
        if (column < 0) {
            column = WSize + column;
        }
        if (row > WSize - 1) {
            row = row - WSize;
        }
        if (column > WSize - 1) {
            column = column - WSize;
        }
        return life[row][column];
    }

private:
    bool life[WSize][WSize];
};

#endif // WORLD_H
