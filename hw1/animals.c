#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_utils.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

NODE *root = NULL;
int MAXLENGTH = 200;
char in[201]; //string

// Returns true if user types "yes" or "y" (upper or lower case)
// and returns false if user types "no" or "n". Keeps
// prompting otherwise.

BOOL yes_response()
{

  //Fill in the code 
  //Hint: You might consider using the C library function strcasecmp()
  BOOL ans = FALSE;
  fgets(in,MAXLENGTH,stdin);
  in[strcspn(in,"\n")]='\0';  


  if(!strcasecmp(in,"yes")||!strcasecmp(in,"y")){  //
      return ans = TRUE;
  }else if(!strcasecmp(in,"no")||!strcasecmp(in,"n")){
      return ans = FALSE;
  }else{
    printf("Invalid input. Try again.\n");
    yes_response();
  }
  return ans;
}



// This procedure creates a new NODE and copies
// the contents of string s into the 
// question_or_animal field.  It also initializes
// the left and right fields to NULL.
// It should return a pointer to the new node

NODE *new_node(char *s)
{
  //Fill in the code
    NODE *n = (NODE *)malloc(sizeof(NODE));
    strcpy(n->question_or_animal, s);
    n->left = NULL;
    n->right = NULL;
    return n;
}

// This is the procedure that performs the guessing.
// If the animal is not correctly guessed, it prompts
// the user for the name of the animal and inserts a
// new node for that animal into the tree.

void guess_animal()
{
  // If the root is NULL, then there are no animals in 
  // the tree. Prompt the player for the name of an 
  // animal, create a node for that animal, and make
  // that node the root of the tree.

  //FILL IN CODE HERE
  if(root == NULL){
      printf("%s","Name an animal > \n");
      fgets(in,MAXLENGTH,stdin);
      in[strcspn(in,"\n")]='\0'; 
      NODE *aNode = new_node(in);
      root= aNode;
  }
    /*
      Otherwise (i.e. if the root is not NULL)
      Then descend down the tree. At each node encountered:

      If the left and right fields of the node are not NULL, i.e. the node
      is an interior node and must contain a question, then:
      - print the question_or_answer field, which will be a yes/no question.
      - read the response from the user
      - If the response is yes, follow the left field to the next node. Otherwise,
        follow the right field.
    */

  //FILL IN CODE HERE
  else if(root != NULL&&(root->left != NULL && root->right != NULL)){
      while(root->left != NULL&&root->right != NULL){
        printf("%s >> ",root->question_or_animal);
        if(yes_response()){ //if yes
            root = root->left;
        }else{//if no
            root = root->right;
        }
      }
  }

  /*
      Otherwise, if the left and right fields are NULL (i.e. the node is a leaf), 
      then the question_or_animal field contains an animal. Print the
      the question_or_animal field as the guess and prompt the user
      if the guess was correct. If the guess was correct, then 
      return. Otherwise, do the following:
           - prompt the user for the name of the new animal she was thinking of
           - prompt the user for a yes or no question distinguishing the new animal from the guessed animal
	   - ask the user what the answer for the new animal would be (yes or no)
           - create a new node with the new animal in the question_or_animal field
	   - create another new node that has the guessed animal in the question_or_animal field
           - make the two new nodes the children of the current node, where the animal for which the
             answer to the question is "yes" is the left child and the other animal is the right child.
           - overwrite the question_or_animal field of the current node with the new question.

      Note that the tree is a stricly binary tree, i.e. left and right fields of each node are either both NULL or 
      both valid pointers to child nodes (in other words, each node is a leaf or has exactly two children).
    */

  //FILL IN CODE HERE
  if(root!=NULL&&(root->left == NULL && root->right == NULL)){
    //
      printf("Is it %s?(yes/no) >\n",root->question_or_animal);
      if(yes_response()){
          return;
      }else{
        printf("What is the animal you are thinking about? > \n" );
        fgets(in,MAXLENGTH,stdin);
        in[strcspn(in,"\n")]='\0'; 
        char *animal=malloc(sizeof(in));
        strcpy(animal,in);

        printf("What is a short yes/no question that distinguishes %s and %s?\n", animal, root->question_or_animal);
        fgets(in,MAXLENGTH,stdin);
        in[strcspn(in,"\n")]='\0';
        char *question=malloc(sizeof(in));
        strcpy(question,in);

        printf("What is the yes/no answer for %s? > \n", animal);
        fgets(in,MAXLENGTH,stdin);
        in[strcspn(in,"\n")]='\0';
        char *answer=malloc(sizeof(in));
        strcpy(answer,in);

        NODE *new_animal = new_node(animal);
        NODE *guessed_animal = new_node(question);
        root->left = new_animal;
        root->right = guessed_animal;
        strcpy(root->question_or_animal,question);

      }
    
  }
}



//This code is complete. Just add comments where indicated.

int main()
{ int i;
  BOOL done = FALSE;

  //insert comment here
  //Open file "data.dat" in read mode and assign to FILE pointer
  //If filepath is incorrect, print file not found message, then quit the program
  FILE *datafile = fopen("data.dat", "r"); 

  if (datafile == NULL) {
    printf("data.dat not found\n");
    exit(1);
  }

  //insert comment here
  //Create or Override a backup file
  FILE *backupfile = fopen("data.dat.bak", "w");

  //insert comment here
  //assign the root of the tree containing info from datafile to "root"
  root = read_tree(datafile);

  //call write_tree() to write the initial tree to the
  //backup file (i.e. to backup the tree data)
  write_tree(root,backupfile);

  //close both files (for now)
  fclose(backupfile);
  fclose(datafile);

  printf("Welcome to the animal guessing game (like 20 questions).\n");
  do { 
    printf("\nThink of an animal...\n");
    guess_animal();  //insert comment here
    //game content, Q&A
    printf("\nDo you want to play again? (yes/no) >");
  } while (yes_response());  //insert comment here
  //as long as the player want to play again, the program restarts


  //now open the "data.dat" file for writing
  datafile = fopen("data.dat", "w");

  //insert comment
  //Write to the tree using user-given info
  write_tree(root, datafile);

  //close the data.dat file
  fclose(datafile);

}

