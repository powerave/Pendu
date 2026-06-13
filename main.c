#include "inc/pendu.h"

int main (void) {
    char *word;
    char c;
    int life = 5;

    word = choose_word();
    if (!word)
        return 1;
    
    if (check_word(word) == 1)
        return 1;

    system("clear");

    char *res;

    res = calloc(strlen(word) + 1, sizeof(char));
    if (!res)
        return (printf("[Error] Calloc failed"), free(word), 1);
    
    init(res, word);

    while (strcmp(word, res) != 0 && life > 0) {
        printf("Choose a letter :");
        scanf(" %1c", &c);
        if (strchr(word, c) == NULL) {
            life--;
            printf("Nop !! You lost a life !!\n Life Points: %d\n", life);
            if (life == 0)
                return(printf("You lost! 0 life left!\nThe word was --------> %s\n:'( try again !!", word), free(word), free(res), 0);
        }
        check_letter(word, res, c);
        printf("----------------> |  %s  | <----------------\n", res);
    }

    printf("You win !! You found the word :D\n");

    free(word);
    free(res);
    return 0;
}
