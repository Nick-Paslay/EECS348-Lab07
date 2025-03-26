#include "stdio.h"
#define max_combination 100
int safety = 2;
int td = 6;
int td1 = 7;
int td2 = 8;
int field_goal = 3;

void print_combination(int combination[], int index) {
    for (int i = 0; i < index; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

void find_combinations(int score, int combination[], int index) {
    if (score == 0) {
        print_combination(combination, index);
        return;
    }
    if (score < 0) return;

    int scores[] = {safety, field_goal, td, td1, td2};
    int num_scores = sizeof(scores) / sizeof(scores[0]);

    for (int i = 0; i < num_scores; i++) {
        combination[index] = scores[i];
        find_combinations(score - scores[i], combination, index + 1);
    }
}

int main(){
    int score;
    printf("Enter a score: ");
    scanf("%d", &score);
    if (score <= 1) {
        printf("Program terminated.\n");
        return 1;
    }
    int combination[max_combination];
    find_combinations(score, combination, 0);
    return 0;
}