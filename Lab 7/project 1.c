#include "stdio.h" 
#define max_combination 100 // max array is 100.
int safety = 2; //takes each integer for points
int td = 6;
int td1 = 7;
int td2 = 8;
int field_goal = 3;

void print_combination(int combination[], int index) { // for each combination, it prints every single way(prints each number seperately, sorry).
    for (int i = 0; i < index; i++) {
        printf("%d ", combination[i]);
    }
    printf("\n");
}

void find_combinations(int score, int combination[], int index, int last_score) {
    if (score == 0) { // my base case of the recursion function
        print_combination(combination, index); // this prints the current combination of the score
        return;
    }
    if (score < 0) return; // if the score becomes negative, it means it isnt valid.

    int scores[] = {safety, field_goal, td, td1, td2}; // contains the possible scores
    int num_scores = sizeof(scores) / sizeof(scores[0]); // determines the number of scores in the array

    for (int i = 0; i < num_scores; i++) {// this goes over each score in the array, taking and 
        if (scores[i] >= last_score) {  // adds the scores in a non-decreasing form. 
            combination[index] = scores[i]; // adds current score to index
            find_combinations(score - scores[i], combination, index + 1, scores[i]); // takes the score, sees if any more can be added, and then adds it to the combination index.
        }
    }
}

int main(){
    int score; // declares variable socre
    printf("Enter a score: ");// asks for score to use
    scanf("%d", &score); // turns it into a usable variable, score.
    if (score <= 1) {
        printf("Program terminated.\n");// if the score is less than 1, nothing will add up to that, so the program is terminated.
        return 1;
    }
    int combination[max_combination];// creates array
    find_combinations(score, combination, 0, 0); // runs array with past_score as 0.
    return 0;
}