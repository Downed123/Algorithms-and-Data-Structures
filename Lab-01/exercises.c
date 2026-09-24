#include <stdio.h>

#define MAX_SIZE 2

typedef struct {
    char name[20];
    char surname[20];
    float height;
    float weight;   
    int wins;
    int nMatches;
} Player;

int player_score(Player plr);
int add_player(Player arr[], Player plr, int* count);
void print_players(Player arr[], int* count);
void remove_player(Player arr[], int index);

int main(){
    Player p1 = {"John", "Doe", 1.7f, 70, 10, 20};
    Player p2 = {"Jane", "Doe", 1.7f, 70, 10, 20};
    Player p3 = {"Joe", "Doe", 1.7f, 70, 10, 20};

    int count = 0;

    printf("%d\n", player_score(p1));

    Player arr[MAX_SIZE];
    printf("%d\n", add_player(arr, p1, &count));
    printf("%d\n", add_player(arr, p2, &count));
    printf("%d\n", add_player(arr, p3, &count));

    print_players(arr, &count);
    return 0;
}

int player_score(Player plr){
    if(plr.nMatches == 0) return 0;
    return ((float)plr.wins / (float)plr.nMatches) * 100;
}

int add_player(Player arr[], Player plr, int* count){
    if(*count >= MAX_SIZE){
        return 0;
    }

    arr[*count] = plr;
    (*count)++;

    return 1;
}

void print_players(Player arr[], int* count){
    for (int i = 0; i < *count; i++)
    {
        printf("Name: %s, Surname: %s, Height: %f, Weight: %f, Wins: %d, nMatches: %d\n", 
            arr[i].name, arr[i].surname, arr[i].height, arr[i].weight, arr[i].wins, arr[i].nMatches);
    }
}