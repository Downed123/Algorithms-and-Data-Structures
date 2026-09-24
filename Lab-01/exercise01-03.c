#include <stdio.h>

#define MAX_SIZE 9

typedef struct
{
    char name[20];
    char surname[20];
    float height;
    float weight;
    int wins;
    int nMatches;
} Player;

// exercise 01
int player_score(Player plr);

// exercise 02
int add_player(Player arr[], Player plr, int *count);
void print_players(Player arr[], int count);
int remove_player(Player arr[], int index, int *count);
Player get_highest_score_player(Player arr[], int count);

// exercise 03
void sort_by_score(Player arr[], int count);

int main()
{
    Player arr[MAX_SIZE];
    int count = 0;

    Player players[10] = {
        {"Alice", "Smith", 1.72f, 65.5f, 15, 20},
        {"Bob", "Johnson", 1.85f, 80.0f, 8, 12},
        {"Charlie", "Williams", 1.68f, 62.0f, 22, 30},
        {"Diana", "Brown", 1.75f, 68.0f, 11, 15},
        {"Ethan", "Jones", 1.90f, 88.2f, 5, 10},
        {"Fiona", "Garcia", 1.65f, 58.0f, 18, 22},
        {"George", "Miller", 1.80f, 75.4f, 12, 18},
        {"Hannah", "Davis", 1.70f, 61.0f, 20, 25},
        {"Ian", "Rodriguez", 1.82f, 79.1f, 9, 14},
        {"Julia", "Martinez", 1.69f, 60.5f, 14, 19}
    };

    // Insert all 10 players using add_player
    for (int i = 0; i < 10; i++) {
        if (add_player(arr, players[i], &count) == 0) {
            printf("Failed to add %s %s (array full)\n", players[i].name, players[i].surname);
        }
    }

    print_players(arr, count);

    sort_by_score(arr, count);

    printf("\n");
    print_players(arr, count);

    // printf("%d\n", remove_player(arr, 1, &count));

    // print_players(arr, count);

    printf("\n%s\n", get_highest_score_player(arr, count).name);
    return 0;
}

int player_score(Player plr)
{
    if (plr.nMatches == 0)
        return 0;
    return ((float)plr.wins / (float)plr.nMatches) * 100;
}
// O(1)
int add_player(Player arr[], Player plr, int *count)
{
    if (*count >= MAX_SIZE)
    {
        return 0;
    }

    arr[*count] = plr;
    (*count)++;

    return 1;
}
// O(n)
void print_players(Player arr[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Surname: %s, Height: %f, Weight: %f, Wins: %d, nMatches: %d\n",
               arr[i].name, arr[i].surname, arr[i].height, arr[i].weight, arr[i].wins, arr[i].nMatches);
    }
}
//O(n)
int remove_player(Player arr[], int index, int *count)
{
    if (index < 0 || index >= *count)
        return 0;

    for (int i = index; i < *count; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*count)--;

    return 1;
}
// O(n)
Player get_highest_score_player(Player arr[], int count)
{
    Player max_plr = arr[0];

    for (int i = 0; i < count; i++)
    {
        if (player_score(max_plr) < player_score(arr[i]))
        {
            max_plr = arr[i];
        }
    }

    return max_plr;
}

void swap(Player *a, Player *b){
    Player temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_score(Player arr[], int count){
    bool swapped;

    for (int i = 0; i < count-1; i++)
    {
        swapped = false;
        for (int j = 0; j < count-i-1; j++)
        {
            if(player_score(arr[j]) > player_score(arr[j+1])){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}