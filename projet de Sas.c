#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
  int numer_unique;
  char name[50];
  char last_name[50];
  char date_birth[50];
  char departement[50];
  float note;
};


int count = 0;
struct student students[100];


void addStudent()
{
  printf("enter the  name: ");
  scanf("%s", &students[count].name);
  // printf("enter the  numero unique: ");
  //  scanf("%s",&students[count].numer_unique);
  printf("enter the last name: ");
  scanf("%s", &students[count].last_name);
  printf("enter the date of birth: ");
  scanf("%s", &students[count].date_birth);
  printf("enter the departement: ");
  scanf("%s", &students[count].departement);
  printf("enter the  note generale: ");
  scanf("%f", &students[count].note);
  printf("the student '%s' is added.\n", students[count].name);
  count++;
  system("pause");
}


void editAstudent()
{

  if (count > 0)
  {
    int i;
    printf("numero unique of a student that u want to modify :");
    scanf("%d", &i);
    if (i > 0 && i <= count)
    {
      printf("%d", i - 1);
      printf("New name : ");
      scanf("%s", students[i - 1].name);
      printf("New last name : ");
      scanf("%s", students[i - 1].last_name);
      printf("New date of birth : ");
      scanf("%s", students[i - 1].date_birth);

      printf("New departement : ");
      scanf("%s", students[i - 1].departement);
      printf("New note : ");
      scanf("%f", &students[i - 1].note);
    }
    else
    {
      printf("invalid number \n");
    }
  }
  else
  {
    printf("none student to edit.\n");
    system("pause");
  }
}



void deletStudent()
{
  int i, index;
  printf("le numero unique qui doit supprimer ");
  scanf("%d", &index);
  for (i = index; i < count - 1; i++)
  {
    students[i] = students[i + 1];
  }
  count--;
  printf(" deleted successfully.\n");
  system("pause");
}


void detailsOfstudent()
{
  for (int i = 0; i < count; i++)
  {

    printf("New id%d\n", i + 1);
    printf("New name %s\n", students[i].name);
    printf("New last name : %s\n", students[i].last_name);
    printf("New date of birth :%s\n", students[i].date_birth);
    printf("New departement :%s\n", students[i].departement);
    printf("New note :%f\n", students[i].note);
    printf("\n-----------------------------------------------\n");
  }

  system("pause");
}


void searchByName()
{
  char name[50];
  printf("Enter the name: ");
  scanf("%s", &name);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(name, students[i].name) == 0)
    {
      printf("-------------- Student --------------\n");
      printf("name : %s\n", students[i].name);
      printf("last_name : %s\n", students[i].last_name);
      printf("date_birth: %s\n", students[i].date_birth);
      printf("departement : %s\n", students[i].departement);
      printf("note :%.2f\n", students[i].note);
    }
  }
  system("pause");
}


void searchByDepartment()
{
  char depar[50];
  printf("Enter the department: ");
  scanf("%s", &depar);
  for (int i = 0; i < count; i++)
  {
    if (strcmp(depar, students[i].departement) == 0)
    {
      printf("-------------- Student --------------\n");
      printf("name : %s\n", students[i].name);
      printf("last_name : %s\n", students[i].last_name);
      printf("date_birth: %s\n", students[i].date_birth);
      printf("departement : %s\n", students[i].departement);
      printf("note :%.2f\n", students[i].note);
    }
  }
  system("pause");
}


void searchStudent()
{

  int choice;
  printf("Search by:\n");
  printf("1. Name\n");
  printf("2. Department\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    searchByName();
    break;
  case 2:
    searchByDepartment();
    break;
  default:
    printf("Invalid choice.\n");
  }
}


void leave()
{
  printf("bye :) ");
}

void totalStudents()
{
  printf("Nombre total d'étudiants inscrits : %d\n", count);
}


void statistiques()
{
  int choice;
  printf("\n--- Statistiques Menu ---\n");
  printf("1. Afficher le nombre total d'étudiants\n");
  printf("2. Afficher le nombre d'étudiants dans chaque département\n");
  printf("3. Afficher les étudiants ayant une moyenne supérieure à un certain seuil\n");
  printf("4. Afficher les 3 étudiants ayant les meilleures notes\n");
  printf("5. Afficher le nombre d'étudiants ayant réussi dans chaque département\n");
  printf("0. Retourner au menu principal\n");

  printf("Entrez votre choix : ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    totalStudents();
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 0:
    leave();
    break;
  default:
    printf("Choix invalide.\n");
  }
}


int main()
{
  int choice;
  do
  {
    system("cls");

    printf("\n--- Menu ---\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Modifier un étudiant\n");
    printf("3. Supprimer un étudiant\n");
    printf("4. Afficher les détails d'un étudiant\n");
    printf("5. Calculer la moyenne générale\n");
    printf("6. Statistiques\n");
    printf("7. Rechercher un étudiant\n");
    printf("8. Trier un étudiant\n");
    printf("0. Quitter\n");

    printf("\n------------------------------\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addStudent();
      break;
    case 2:
      editAstudent();
      break;
    case 3:
      deletStudent();
      break;
    case 4:
      detailsOfstudent();
      break;
    case 5:
      break;
    case 6:
      statistiques();
      break;
    case 7:
      searchStudent();
      break;
    case 8:
      break;
    case 0:
      leave();
      break;
    default:
      printf("Choix invalide.\n");
    }
  } while (choice != 0);

  return 0;
}
