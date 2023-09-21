#include <stdio.h>
#include <string.h>

int choix, i, j, nbr, count = 0, id = 497;

struct deadline {
    int day;
    int month;
    int year;
};

struct task {
    int id;
    struct deadline dl;
    char titre[20];
    char description[70];
    char statut[20]; 
};
  void sortst(struct task tasks[], int count)
{
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(tasks[i].statut, tasks[j].statut) > 0)
            {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}
  void sortdes(struct task tasks[], int count)
{
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(tasks[i].description, tasks[j].description) > 0)
            {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

    void sort(struct task tasks[], int count)
{
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (strcmp(tasks[i].titre, tasks[j].titre) > 0)
            {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}
int main() {
    struct task tasks[10];

    while (1) {
        printf("==================================================================================\n");
        printf("                                Menu d'application\n");
        printf("==================================================================================\n");
        printf("Cliquez sur 1 pour ajouter une nouvelle tache\n");
        printf("Cliquez sur 2 ajouter plusieurs  taches\n");
        printf("Cliquez sur 3 pour afficher les tache\n");
        printf("Cliquez sur 4 pour affi les Taches triees par ordre alphabetique\n");
        printf("Cliquez sur 5 pour quitter\n");
        printf("==================================================================================\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Ajouter une tache:\n");
                if (count < 10) {
                    tasks[count].id = id;
                    printf("Votre id est %d\n", id);
                    printf("Entrer le titre: ");
                    scanf("%d", 0);
                    scanf("%[^\n]", tasks[count].titre);
                    printf("Enter une description pour cette tache: ");
                    scanf("%d", 0);
                    scanf("%[^\n]", tasks[count].description);
                    printf("enter ur statut : a realiser, en cours de realisation,  finalisee: ");
                    scanf("%d", 0);
                    scanf("%[^\n]", tasks[count].statut);
                    printf("Enter deadline (jj/mm/aaaa): ");
                    scanf("%d/%d/%d", &tasks[count].dl.day, &tasks[count].dl.month, &tasks[count].dl.year);
                    count++;
                    id++;
                } else {
                    printf("nbr of tasks has been reached\n");
                }
                break;
                case 2:
    printf("Ajouter plusieurs taches:\n");
    
    
    printf("How many tasks do u want to add");
    scanf("%d", &nbr);

    for (i = 0; i < nbr && count < 10; i++) {
        tasks[count].id = id;
        printf("Votre id est %d\n", id);
        printf("Enter le titre: ");
        scanf("%d", 0);
        scanf("%[^\n]", tasks[count].titre);
        printf("Enter une description pour cette tache: ");
        scanf("%d", 0);
        scanf("%[^\n]", tasks[count].description);
       printf("enter ur statut : a realiser, en cours de realisation,  finalisee: ");
       scanf("%d", 0);
        scanf("%[^\n]", tasks[count].statut);
        printf("Entre deadline (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &tasks[count].dl.day, &tasks[count].dl.month, &tasks[count].dl.year);
        count++;
        id++;
    }

    if (count >= 10) {
        printf("nbr of tasks has been reached\n");
    }
    break;

            case 3:
                        printf("==================================================================================\n");
                        printf("Liste des taches :\n");
                        printf("==================================================================================\n");
                        printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                        printf("==================================================================================\n");
                        for (i = 0; i < count; i++)
                        {
                            printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                            tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                        }
                        printf("==================================================================================\n");
                break;

            case 4: while(1)
            {
                    printf("Cliquez sur 1 pour trier par titre\n");
                    printf("Cliquez sur 2 pour trier par description\n");
                    printf("Cliquez sur 3 pour trier par statut\n");
                    printf("entre votre choix");
                    scanf("%d", &choix);
                    switch (choix)
                    {
                    case 1:
                    sort(tasks, count);
                    printf("Taches triees par titre :\n");
                    printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                    printf("==================================================================================\n");
                    for (i = 0; i < count; i++) {
                    printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                            tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                }
                printf("==================================================================================\n");
                        break;
                    case 2: sortdes(tasks, count);
                     printf("Taches triees par description :\n");
                    printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                    printf("==================================================================================\n");
                    for (i = 0; i < count; i++) {
                    printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                            tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                }
                printf("==================================================================================\n");
                break;
                case 3: sortst(tasks, count);
                printf("Taches triees par status :\n");
                    printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                    printf("==================================================================================\n");
                    for (i = 0; i < count; i++) {
                    printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                            tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                }
                printf("==================================================================================\n");
                break;
                    default:
                        break;
                    }
            }
                    
                break;
                return 0;

            default:
                printf("Choix invalide. Reessayez.\n");
                break;
        }
    }

    return 0;
}