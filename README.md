#ASSIGNMENT 0: Pointer Sorter
By: Gabriel Gutierrez (gg548)
      Ayush Joshi (aj470)

#Description:
-	The implementation for pointer sorter uses a linked list structure to sort and store alphabetic components that were read in as input.

-	Our pointer sorter reads in input from user and passes each element of argv[] in a for loop. From there the extractComponent() function parses through the passed string to find components that are separated by non-alphabetic characters and passes it to the sortComponent() function where it is placed in a node and sorted into the list.

-	We chose to sort our list by copying the current string to be sorted into a temp string and turn it into lower case (solely for comparisons) and also temporarily store the current node being compared and turn it into lower case then use strcmp() on the lower case strings and if it returns a value < 0, the new node is added to previous to the node currently being pointed to.

-	Once the for loop passing elements from argv to the extractComponent() function ends, another loop runs traverses the list, prints the stored string, and frees all allocated memory while going through and printing the sorted list.

-	Input validation on the program ensures that argc is not less than 2 before running. Other errors being checked for is ensuring malloc does not return a NULL pointer when called.

#Runtime Analysis:

-	Since our program uses a linked list and stores values in a sorted manner, our program runs in linear O(Cn) time, where C is a constant for the number of components extracted to be sorted, since the list is only traversed once each time an element is extracted and sent to be sort.
