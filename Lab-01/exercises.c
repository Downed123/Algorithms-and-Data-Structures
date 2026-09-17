#include <stdio.h>

typedef struct {
    char name[20];
    char surname[20];
    float height;
    float weight;
    int wins;
    int nMatches;
} Player;

int player_score(Player plr);

int main(){
    Player p1 = {"John", "Doe", 1.7f, 70, 10, 20};

    printf("%d", player_score(p1));
    return 0;
}

int player_score(Player plr){
    return ((float)plr.wins / (float)plr.nMatches) * 100;
}