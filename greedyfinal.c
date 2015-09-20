/**
*Yero Rudzinskas
*
*CS-50
*
*greedy.c
*
*Calculates the number of coins (and outputs type) needed for given change
*
*/


#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float cash ; // this float is converted to int values
     // setting up all of the values so accessible 
    
    int quartersowed = 0;
    int quarterremain = 0;
    int dimesowed = 0;
    int dimeremain = 0;
    int nickelsowed = 0;
    int nickelremain = 0;
    int penowed = 0;

// getting the user input2014.fall.pset1.hello
    do  
    {
        printf("How much cash do you owe the customer?\n");
        cash = GetFloat();
    }
// will repeat if input is invalid

while
    (cash < 0); 
// multiplying cash by 100 and rounding it to accomodate errors    

int centsowed = round(cash * 100);

// first case: if less than a nickel is owed
    if (centsowed < 5)
    {
        penowed = (centsowed / 1);
    }

//second case, increasing complexity with each case    
    else if ((centsowed) >= 5 && (centsowed < 10))
    {
        // setting up how many nickels owed and using modulo to get remainder    
        nickelsowed = (centsowed / 5);
        nickelremain = centsowed % (nickelsowed * 5);
        
        // asks if any pennies are owed after the nickel 
        if (nickelremain >= 1)
        {
            penowed = (nickelremain / 1);
        }    
            else 
        {
            
            (penowed = 0);
        }
		    
   		}
// between a dime and a quarter owed   			
else if ((centsowed >= 10) && (centsowed < 25))
    { 
    // asking if any dimes are owed
        dimesowed = (centsowed / 10);
        dimeremain = centsowed % (dimesowed * 10);
        
        if (dimeremain >= 5)
        {
        // asking if any nickels are owed
            nickelsowed = (dimeremain / 5);
            nickelremain = dimeremain % (nickelsowed * 5); 
		
            // asking if pennies are owed
            if (nickelremain >= 1)
            {
                penowed = (nickelremain / 1);
            }
        
        
            else
            {
                penowed = 0;
            }    			
		
		}	
	    
	    else 
        { 
            penowed = (dimeremain / 1);	
        }
}

else
    {
    //this branch covers all values >= 25 cents owed
        quartersowed = (centsowed / 25);
        quarterremain = centsowed % (quartersowed * 25);
	
        if (quarterremain >= 10)
        {
            dimesowed = (quarterremain / 10);
            dimeremain = quarterremain % (dimesowed * 10);
			   
            if (dimeremain >= 5)
            
            {
                nickelsowed = (dimeremain / 5);
                nickelremain = dimeremain % (nickelsowed * 5);

                if (nickelremain >= 1)
                
                {
                    penowed = (nickelremain / 1);
                }
                    else
                {
                    penowed = 0;
                }
			}			
				else
            {
                penowed = (dimeremain / 1);
            }	
				
        }
        else
        {
            if (quarterremain >= 5)
            {
                nickelsowed = (quarterremain / 5);
                nickelremain = quarterremain % (nickelsowed * 5);
					    
                if (nickelremain >= 1)
                {
                    penowed = (nickelremain / 1);
						}
					else
                {
                    penowed = 0;
                }	
			}
                else
            {
                penowed = (quarterremain / 1);
            }					
			}			
}

	// deriving the total coins needed	
    int total = quartersowed + dimesowed + nickelsowed + penowed;
    
    // thought we should include this feature 
    printf ("quarters %d, dimes %d, nickels %d, pennies %d\n", 
    quartersowed, dimesowed, nickelsowed, penowed);
    
    // total coins
    printf ("%d\n", total); 

}