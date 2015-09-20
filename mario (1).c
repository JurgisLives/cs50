#include <stdio.h>
#include <cs50.h>

int main(void)

/**
 * Create a half pyramid with a user-determined height!
 *
 */

{
	// prompt user for pyramid height. Pyramids with < 3 rows don't make great pyramids and are therefore excluded.
	int height = 0;
	do
	{
		printf("Please enter a number between 3-23.\n");
		height = GetInt();
	}
	while (height < 3 || height > 23);
	
	printf("height: %d\n", height);
	
	// create mario pyramid
	
	for (int row = 0; row < height; row++)
	{
	    // left half of pyramid 
	    for (int num_space = 0; num_space < (height - row - 1); num_space++)
	    {
            char space = ' ';
	        printf("%c", space);
	    }
	    
	    for (int num_hash = 0; num_hash < (row + 2); num_hash++)
	    {
            char hash = '#';
	        printf("%c", hash);
	    }
	    
	    // print gap between halves
	    printf("         ");
	    
	    // right half of pyramid. Spaces are not needed.
	    for (int num_hash = 0; num_hash < (row + 2); num_hash++)
	    {
            char hash = '#';
	        printf("%c", hash);
	    }
	    
	    printf("\n");
	}
}
