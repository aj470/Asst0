#ASSIGNMENT 0: Pointer Sorter
Group 88: Gabriel Gutierrez (gg548) and Ayush Joshi (aj470)

#Description:
-	The implementation for pointer sorter uses a dynamic linked list structure to sort and store alphabetic components that were tokenized from the input.

-	Our pointer sorter reads in input from user and passes each element of argv[] in a for loop. If the argv[] deoesn't have input sting we prints error and exits program. If argv has input string, from there the extractComponent() function parses through the passed string to find components that are separated by non-alphabetic characters and passes it to the sortComponent() function where it is placed in a node and sorted into the linked list.

-	We chose to sort our list by copying the current string to be sorted into a temp string and turn it into lower case (solely for comparisons) and also temporarily store the current node being turned into lower case and then compared using strcmp() on the lower case strings and if comparision returns a value < 0, the new node is added to previous to the node currently being pointed to.

-	Once the for loop passing elements from argv to the extractComponent() function ends, another loop runs traverses the list, prints the stored string, and frees all allocated memory while going through and printing the sorted list.

-	Input validation on the program ensures that argc is not less than 2 before running. Other errors being checked for ensuring malloc does not return a NULL pointer when called. Also checks for '\0' as end of strings.

#Outputs: 

-     Our program outputs components/tokens from the input given in dictionary based lexicographical order as we thought the main purpose of assignment is to sort lexicographically. Our algorithm takes care of differences between Uppercase Alph and Lowercase Alph ASCII values and also does print 1-1 mapped output with input. When same component is in lowercase and upercase, we sort it into the first come first sorted basis. Example: "APPLES are apples", output is APPLES first and then apples. Example: "apples are Apples", output apples first then Apples.
-     Other testcases included in testcases file.


#Runtime Analysis:

-	Since our program uses a linked list and stores values in a sorted manner, our program runs in linear O(Cn) time, where C is a constant for the number of components extracted to be sorted, since the list is only traversed once each time an element is extracted and sent to be sort.
