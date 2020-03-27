#include <stdio.h>
#include <stdlib.h>

struct Cred{
  char *user;
  char *pass;
  struct Cred *next;
};



struct Cred* cred(char *newUser, char *newPass, struct Cred *next){
  struct Cred* head = (struct Cred*) malloc(sizeof(struct Cred));
  head->user = newUser;
  head->pass = newPass;
  head->next = &*next;
  return head;

}

//Frees the cred inputted and any cred remaining in the linked list
void cred_Free(struct Cred* credFree){
  if(credFree->next != NULL){
    cred_Free(credFree->next);
  }
  free(credFree);
}

// See the README.txt file for the challenge description.
int main(void) {
  struct Cred* c = cred("caleb", "xyz",
                      cred("hazel", "abc",
                           cred("jody", "123", NULL)));
  printf("%s\n", c->user);
  cred_Free(c->next);
  printf("%s\n", c->user);
  cred_Free(c);
  printf("%s\n", c->user);
}