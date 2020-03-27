Video Link: https://youtu.be/sdT3dm3T-yU

BST:
struct BST: is the structure of the node we use for each word, has a word value, freq, left and right pointers. Standard node for a BST tree

-newTree:
	takes a word as a parameter and makes it the root of the BST. 

-addWord:
	takes a word as a parameter and if its not in the BST it creates a new word and adds it to the proper place in the tre

-printTree:
	takes in the root of the BST and prints the entire tree

-nodePrint:
	takes in root of the BST and prints out the word from the tree using write()

-isAlpha:
	takes in the word and determines if its alphabetical value to another word

-outNewLine:
	takes a word and adds a \n to the input

-sortByFrequency:
	sorts the BST by frequency

Main:

-main:
	takes in the parameters and runs as the driver

(Main is what is used to colate the header files and the driver function)

Parser:

-fileTokenizer:
	takes n the fd and root Node and parses the file. This returns the root node to a filled BST sorted by freq
-addEOS:
	takes in the buffer string and adds the '\0' to the end of the file


