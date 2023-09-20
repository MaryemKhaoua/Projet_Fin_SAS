#include <stdio.h>
#include <stdlib.h>

int choix, count = 0, id = 497;

struct task {
    int id;
    struct deadline {
        int day;
        int month;
        int year;
    } dl;
    char titre[20];
    char description[70];
    char statut[70];
};

int main() {
    struct task tasks[10];

    while (1) {
        printf("==================================================================================\n");
        printf("                                Menu d'application\n");
        printf("==================================================================================\n");
        printf("Cliquez sur 1 pour ajouter une nouvelle tâche\n");
        printf("Cliquez sur 2 pour ajouter plusieurs tâches\n");
        printf("Cliquez sur 3 pour afficher la liste de toutes les tâches \n"); 
        printf("==================================================================================\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Ajouter des détails:\n");

                if (count < 10) {
                    tasks[count].id = id;
                    printf("Votre id est %d\n", id);
                    printf("Entrer le titre: ");
                    scanf("%s", tasks[count].titre);
                    printf("Enter une description pour cette tache: ");
                    scanf("%s", tasks[count].description); 
                    printf("Enter votre statut: [1] pour ''to do\n[2] ''doing''\n[3] pour ''done'' :\n ");
                    scanf("%s", tasks[count].statut); 
                    printf("Enter la deadline (jj/mm/aaaa): ");
                    scanf("%2d/%2d/%4d", &tasks[count].dl.day, &tasks[count].dl.month, &tasks[count].dl.year);
                    printf("id = %d\n", tasks[count].id);
                    printf("titre: %s\n", tasks[count].titre);
                    printf("description: %s\n", tasks[count].description);

                    count++;
                    id++;
                } else {
                    printf("Le nombre maximum de tâches a été atteint\n");
                }
                break;

            case 2:
                printf("Ajouter des détails:\n");
                if (count < 10) {
                    tasks[count].id = id;
                    printf("Votre id est %d\n", id);
                    printf("Entrer le titre: ");
                    scanf("%s", tasks[count].titre);
                    printf("Enter une description pour cette tache: ");
                    scanf("%s", tasks[count].description); 
                    printf("Enter votre statut: [1] pour ''to do\n[2] ''doing''\n[3] pour ''done'' :\n ");
                    scanf("%s", tasks[count].statut);
                    printf("Enter la deadline (jj/mm/aaaa): ");
                    scanf("%2d/%2d/%4d", &tasks[count].dl.day, &tasks[count].dl.month, &tasks[count].dl.year);
                    printf("id = %d\n", tasks[count].id);
                    printf("titre: %s\n", tasks[count].titre);
                    printf("description: %s\n", tasks[count].description);
                    count++;
                    id++;
                } else {
                    printf("Le nombre maximum de tâches a été atteint\n");
                }
                break;

            default:
                printf("Choix invalide. Réessayez.\n");
                break;
        }
    }

    return 0;
}