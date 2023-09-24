#include <stdio.h>
#include <string.h>
#include <time.h>

int choix, i, j, nbr, count = 0, id = 497;

struct deadline
{
    int day;
    int month;
    int year;
};

struct task
{
    int id;
    struct deadline dl;
    char titre[20];
    char description[70];
    char statut[20];
};

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

void sortdl(struct task tasks[], int count)
{
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (tasks[i].dl.year > tasks[j].dl.year ||
                (tasks[i].dl.year == tasks[j].dl.year && tasks[i].dl.month > tasks[j].dl.month) ||
                (tasks[i].dl.year == tasks[j].dl.year && tasks[i].dl.month == tasks[j].dl.month && tasks[i].dl.day > tasks[j].dl.day)) {
                struct task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}
void affdltroisjrs(const struct task tasks[], int count)
{
    time_t currentTime;
    struct tm *currentDate;
    time(&currentTime);
    currentDate = localtime(&currentTime);

    int currentDay = currentDate->tm_mday;
    int currentMonth = currentDate->tm_mon + 1;
    int currentYear = currentDate->tm_year + 1900;

    printf("les taches dont le deadline est dans 3 jours ou moins:\n");
    printf("ID\tTitre\tDescription\tStatut\tDeadline\n");

    for (int i = 0; i < count; i++)
    {
        int daysRemaining = (tasks[i].dl.year - currentYear) * 365 + (tasks[i].dl.month - currentMonth) * 30 + (tasks[i].dl.day - currentDay);

        if (daysRemaining >= 0 && daysRemaining <= 3)
        {
            printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                   tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
        }
    }
}
void modifydes(struct task tasks[], int count)
{
    int byId;
    printf("enter ur id : ");
    scanf("%d", &byId);
    for (i = 0; i < count; i++)
    {
        if(tasks[i].id == byId)
        {
            printf("Enter ur new description : ");
            scanf("%s", tasks[i].description);
            printf("lur description a ete modifiee");
            return;
        }
    }
    printf("task with this id %d not found\n", byId);
}
void modifyst(struct task tasks[], int count)
{
    int byId;
    printf("enter ur id : ");
    scanf("%d", &byId);
    for (i = 0; i < count; i++)
    {
        if(tasks[i].id == byId)
        {
            printf("Enter ur new statut : ");
            scanf("%s", tasks[i].statut);
            printf("ur statut a ete modifiee");
            return;
        }
    }
    printf("task with this id %d not found\n", byId);
}
void modifydl(struct task tasks[], int count)
{
    int byId;
    printf("enter ur id : ");
    scanf("%d", &byId);
    for (i = 0; i < count; i++)
    {
        if(tasks[i].id == byId)
        {
            printf("Enter ur new deadline (jj/mm/aaaa): ");
            scanf("%d/%d/%d", &tasks[i].dl.day, &tasks[i].dl.month, &tasks[i].dl.year);
            printf("ur deadline a ete modifiee");
            return;
        }
    }
    printf("task with this id %d not found\n", byId);
}
void searchid(const struct task tasks[], int count)
{
    int byId;
    int found = 0;

    printf("enter the id of tasks u want to search for: ");
    scanf("%d", &byId);
    for(i = 0; i < count; i++)
    {
        if (tasks[i].id == byId)
        {
            found = 1;
            printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                   tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
        }
    }
     if (found)
        printf("Task with id %d is found.\n", byId);
    else
        printf("task with tis is  %d not found\n", byId);
}
void searchTitre(const struct task tasks[], int count)
{
    char byTitre[26];
    int found = 0;

    printf("enter the title of tasks u want to search for: ");
    scanf("%s", byTitre);
    for(i = 0; i < count; i++)
    {
        if (strcmp(tasks[i].titre, byTitre) == 0)
        {
            found = 1;
            printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                   tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
        }
    }
     if (found)
        printf("Task with titre %s is found.\n", byTitre);
    else
        printf("task with this titre %s is not found\n", byTitre);
}
void statistic(const struct task tasks[], int count)
{
    int nbrTasks = count;
    int nbrCo = 0;
    int nbrInco = 0;
    for (i = 0; i < count; i++)
    {
        if (strcmp(tasks[i].statut, "finalisee") == 0)
        nbrCo++;
        else
        nbrInco++;
    }
        printf("le nombre total des taches est : %d \n", nbrTasks);
        printf("le nombre total des taches completes est : %d \n", nbrCo);
        printf("le nombre total des taches incompletes est : %d \n", nbrInco);
    
}
void statisticdeadline(const struct task tasks[], int count)
{
    time_t currentTime;
    struct tm *currentDate;
    time(&currentTime);
    currentDate = localtime(&currentTime);

    int currentDay = currentDate->tm_mday;
    int currentMonth = currentDate->tm_mon + 1;
    int currentYear = currentDate->tm_year + 1900;

    printf("nombre de jours restants jusqu'au delai de chaque teche :\n");
    printf("ID\tTitre\tjours restant\n");

    for (int i = 0; i < count; i++)
    {
        int jrsrestant = (tasks[i].dl.year - currentYear) * 365 + (tasks[i].dl.month - currentMonth) * 30 + (tasks[i].dl.day - currentDay);

        printf("%d\t%s\t%d\n", tasks[i].id, tasks[i].titre, jrsrestant);
    }
}

int main()
{
    struct task tasks[10];

    while (1)
    {
        printf("==================================================================================\n");
        printf("                                Menu d'application\n");
        printf("==================================================================================\n");
        printf("Cliquez sur 1 pour ajouter une nouvelle tache\n");
        printf("Cliquez sur 2 ajouter plusieurs  taches\n");
        printf("Cliquez sur 3 pour afficher les tache\n");
        printf("Cliquez sur 4 pour affi les Taches triees par ordre alphabetique\n");
        printf("Cliquez sur 5 pour modification\n");
        printf("Cliquez sur 6 to search a task by id: \n");
        printf("Cliquez sur 7 to search a task by titre: \n");
        printf("Cliquez sur 8 pour afficher Statistiques\n");
        printf("Cliquez sur 9 pour quitter\n");
        printf("==================================================================================\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
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
                } else
                {
                    printf("nbr of tasks has been reached\n");
                }
                break;
                
            case 2:
                printf("Ajouter plusieurs taches:\n");
                printf("How many tasks do u want to add : ");
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

                if (count >= 10)
                {
                    printf("nbr of tasks has been reached\n");
                }
                break;

            case 3:
                printf("==================================================================================\n");
                printf("Liste des taches :\n");
                printf("==================================================================================\n");
                printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                printf("==================================================================================\n");
                for (i = 0; i < count; i++) {
                    printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                           tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                }
                printf("==================================================================================\n");
                break;

            case 4:
                 
                    printf("Cliquez sur 1 pour trier par titre\n");
                    printf("Cliquez sur 2 pour trier par deadline\n");
                    printf("Cliquez sur 3 pour trier dont le deadline est dans 3 jours ou moins\n");
                    printf("entre votre choix: ");
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
                       
                        case 2:
                            sortdl(tasks, count);
                            printf("Taches triees par deadline :\n");
                            printf("ID\tTitre\tDescription\tStatut\tDeadline\n");
                            printf("==================================================================================\n");
                            for (i = 0; i < count; i++) {
                                printf("%d\t%s\t%s\t%s\t\t%2d/%2d/%4d\n", tasks[i].id, tasks[i].titre, tasks[i].description, tasks[i].statut,
                                       tasks[i].dl.day, tasks[i].dl.month, tasks[i].dl.year);
                            }
                            printf("==================================================================================\n");
                            break;
                            case 3: affdltroisjrs(tasks, count);
                            break;
                            
                        default:
                        printf("choix invalid");
                            break;
                    }
                
                
                break;
                
                case 5:
            while (1)
             {
                 printf("Cliquez sur 1 pour modifier la description d'une tache\n");
                 printf("Cliquez sur 2 pour modifier le statut d'une tache\n");
                 printf("Cliquez sur 3 pour modifier le deadline d'une tache\n");
                 printf("Cliquez sur 4 pour revenir au menu principal\n");
                 printf("Entre votre choix: ");
                 scanf("%d", &choix);

                switch (choix) {
                      case 1: modifydes(tasks, count);
                break;
            case 2: modifyst(tasks, count);
                break;
            case 3: modifydl(tasks, count);  
                break;
            case 4:
                break;
            default:
                printf("Choix invalide. Reessayez.\n");
                break;
        }

        if (choix == 4)
        {
            
            break;
        }
    }
    break;
            case 6:  searchid(tasks, count);
            break;
            case 7: searchTitre(tasks, count);
            break;
            case 8: statistic(tasks, count);
                    statisticdeadline(tasks, count);
            break;
            case 9:
            return 0;
            
            default:
            printf("Choix invalide. Reessayez.\n");
            break;
        }
    }

    return 0;
}