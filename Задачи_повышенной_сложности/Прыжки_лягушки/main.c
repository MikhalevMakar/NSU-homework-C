#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct TTable {
    int* StonesArr;
    int* LenJumpArr;
    int* PosArr;
}TTable;

int* CreateStonesArr(int count) {
    int* stones = malloc(count * sizeof(int));
    assert(stones != NULL);
    
    for (int i = 0; i < count; ++i) {
        assert(scanf("%d", &stones[i]) == 1);
    }

    return stones;
}

int* CreateLenJumpArr(int count) {
    int* lenJump = calloc(count, sizeof(int));
    assert(lenJump != NULL);
    return lenJump;
}

int CreatePosArr(int count) {
    int* posArr = calloc(count, sizeof(int));
    assert(posArr != NULL);
    return posArr;
}

TTable* CreateTabelValue(countStones) {
    TTable* table = malloc(sizeof(TTable));
    assert(table != NULL);

    table->StonesArr = CreateStonesArr(countStones);
    table->LenJumpArr = CreateLenJumpArr(countStones);
    table->PosArr = CreatePosArr(countStones);
    
    return table;
}

bool IsTrueJump(int count, int pos, int len, TTable* table) {
    for (int i = 0; i < count; ++i) {
        if (table->StonesArr[i] == len && table->LenJumpArr[i] != len && table->PosArr[i] != pos) {
            table->LenJumpArr[i] = len;
            table->PosArr[i] = pos;
            return true;
        }
    }

    return false;
}

bool JumpToFinish(int len, int pos, int count, TTable* table) {
    if (pos >= table->StonesArr[count - 1]) {
        return true;
    }

    bool fx = IsTrueJump(count, pos + len, len, table) && JumpToFinish(len, pos + len, count, table);
    bool fy = IsTrueJump(count, pos + len + 1, len + 1, table) && JumpToFinish(len + 1, pos + len + 1, count, table);
    bool fz = IsTrueJump(count, pos + len - 1, len - 1, table) && JumpToFinish(len - 1, pos + len - 1, count, table);
    bool bx = IsTrueJump(count, pos - len, len, table) && JumpToFinish(len, pos - len, count, table);
    bool by = IsTrueJump(count, pos - len - 1, len + 1, table) && JumpToFinish(len + 1, pos - len - 1, count, table);
    bool bz = IsTrueJump(count, pos - len + 1, len - 1, table) && JumpToFinish(len - 1, pos - len + 1, count, table);

    return fx || fy || fz || bx || by || bz;
}

int main() {
    int countStones = 0;
    assert(scanf("%d", &countStones));
    
    TTable* tableMoving = CreateTabelValue(countStones);

    printf("%d", JumpToFinish(1, 0, countStones, tableMoving));

    return 0;
}
