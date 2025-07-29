#include "GameData.h"

namespace GameData {
    std::vector<fox::vec2> playerPoints = {
        {  5,  0 },
        { -4, -3 },
        { -2,  0 },
        { -4,  3 },
        {  5,  0 }

    };

    std::vector<fox::vec2> enemyPoints = {
        { -2, -1 },
        { -1, -2 },
        { 1, -2 },
        { 2, -1 },
        { 6, 0 },
        { 2, 1 },
        { 1, 2 },
        { -1, 2 },
        { -2, 1 },
        { -6, 0 },
        { -2, -1 },
    };
}