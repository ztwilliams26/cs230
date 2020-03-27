#include <stdlib.h>
#include <stdio.h>

struct Item{
	char *name;
	char *description;
	struct Item *next;
};

struct Room{
  char *description;
  struct Item *items;
  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west; 
  struct Room *up;
  struct Room *down;
};

int main(void){
  struct Item *item(char*, char*, struct Item*);
	char *item_name(struct Item*);
	char *item_description(struct Item*);
	struct Item *item_next(struct Item*);
	struct Item *item_take();
  struct Room *room(char*, struct Item*, struct Room*, struct Room*, struct Room*, struct Room*, struct Room*, struct Room*);
  void room_exit_north(struct Room*, struct Room*);
	

  struct Item* items = item("a bronze key", "a dull bronze key", item("rope", "a leather-bound rope", NULL));

  struct Item *items2 = item("Knife", "A Knife...", item("Butter", "Tasty", NULL));

  struct Room *current = room("A large empty room with a glow at the end of the hall...", items, NULL, NULL, NULL, NULL, NULL, NULL);

  struct Room *other = room("The final room...", items2, NULL, NULL, NULL, NULL, NULL, NULL);
  
  room_exit_north(current,other);
  
	
	
}




struct Item *item(char* name, char* description, struct Item* next){
	struct Item *itemPtr = (struct Item *) malloc(sizeof(struct Item));
	(*itemPtr).name = name;
	(*itemPtr).description = description;
	(*itemPtr).next = next;
	return itemPtr;
}

char *item_name(struct Item *item){
	if(item==NULL)return NULL;
  return (*item).name;
}

char *item_description(struct Item *item){
	if(item==NULL)return NULL;
  return (*item).description;
}

struct Item *item_next(struct Item *item){
	if(item==NULL)return NULL;
  return (*item).next;
}

struct Item *item_take(char *name, struct Item *root){
	int strcmp();
  struct Item *prevItem = NULL;
	struct Item *curItem = root;
  struct Item *nextItem = item_next(curItem);
	while(curItem!=NULL){
		if(strcmp(name, item_name(curItem))){
			if(nextItem==NULL){
				if(prevItem==NULL){
          struct Item **rootPtr = &root;
          rootPtr=NULL;
          return curItem;
        }
        (*prevItem).next = NULL;
        return curItem;
			}
      else if(prevItem != NULL){
        (*prevItem).next = nextItem;
        (*curItem).next = NULL;
        return curItem;
      }
      else{
        struct Item **rootPtr = &root;
        rootPtr=NULL;
        return curItem;
      }

		}
		prevItem = curItem;
		curItem = item_next(curItem);
    nextItem = item_next(curItem);
	}
	return NULL;
}

struct Room *room(char *description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down){

  struct Room *rmPtr = (struct Room *) malloc(sizeof(struct Room));
  (*rmPtr).description = description;
  (*rmPtr).items = items;
  (*rmPtr).north = north;
  (*rmPtr).south = south;
  (*rmPtr).east = east;
  (*rmPtr).west = west;
  (*rmPtr).up = up;
  (*rmPtr).down = down;
  return rmPtr;
}

void room_exit_north(struct Room *current, struct Room *other){
  if(current == NULL || other == NULL){
    return;
  }
  current->north = other;  
}