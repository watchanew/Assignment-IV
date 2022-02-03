// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item_1, item_2; // char entered by user

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter an ID: " );
            scanf( "%d", &item_1 );
            printf( "%s", "Score: " );
            scanf( "%d", &item_2 );
            insert( &startPtr, item_1, item_2 ); // insert item in list
            printList( startPtr );
            printReverse(startPtr);
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &item_1 );

               // if character is found, remove it
               if ( deletes( &startPtr, item_1 ) == item_1) { // remove item
                  printf( "%d deleted.\n", item_1 );
                  printList( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", item_1 );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while

   puts( "End of run." );
} // end main
