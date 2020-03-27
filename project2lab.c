#include <stdlib.h>
#include <stdio.h>

int main(void){
	struct Item *item();
	char *item_name();
	char *item_description();
	struct Item *item_next();
	struct Item *item_take();
	
	struct Item *knife = item("Knife", "A Knife...", item("Butter", "Tasty", NULL));
	printf("%s\n", item_name(item_next(knife)));
	
}

struct Item{
	char *name;
	char *description;
	struct Item *next;
};


struct Item *item(char* name, char* description, struct Item* next){
	struct Item *itemPtr = (struct Item *) malloc(sizeof(struct Item));
	(*itemPtr).name = name;
	(*itemPtr).description = description;
	(*itemPtr).next = next;
	return itemPtr;
}

char* item_name(struct Item *item){
	return (*item).name;
}

char* item_description(struct Item *item){
	return (*item).description;
}

struct Item* item_next(struct Item *item){
	return (*item).next;
}

struct Item* item_take(char *name){
	
}