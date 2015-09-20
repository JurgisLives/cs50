#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float cash; //this float is converted to int values
    int centsowed = 0; //setting up all of the values so that they are accessible 
    int quartersowed = 0;
    int quarterremain = 0;
    int dimesowed = 0;
    int dimeremain = 0;
    int nickelsowed = 0;
    int nickelremain = 0;
    int penowed = 0;
    
    
    do  //getting the user input
    {
        printf("How much cash do you owe the customer?\n");
        cash = GetFloat();
    }
        while
            (cash < 0); 
            centsowed = (cash * 100);
        
if (centsowed >= 25)
	{
		quartersowed = (centsowed / 25);
        quarterremain = centsowed % (quartersowed * 25);
            
            if (quarterremain >= 10)
            {
                dimesowed = (quarterremain / 10);
                dimeremain = quarterremain % (dimesowed * 10);
            
			}
				if (dimeremain < 10 && dimeremain >= 5)
				{
					nickelsowed = (dimeremain / 5);
					nickelremain = dimeremain % (nickelsowed * 5);
				}
					if (nickelremain >= 1 && nickelremain < 5)
					{
						penowed = (nickelremain / 1);
					}	
					
					
				
			if (quarterremain >= 5 && quarterremain < 10)
			{
				nickelsowed = (quarterremain / 5);
				nickelremain = quarterremain & (nickelsowed * 5);
			}
				if (nickelremain >= 1 && nickelremain < 5)
				{
					penowed = (nickelremain / 1);
				}
					
    }    

	
 if (centsowed >=10 && centsowed < 25)//elseif??
                
    {
		dimesowed = (centsowed / 10);
		dimeremain = centsowed % (dimesowed * 5);
	}
		if (dimeremain >= 5)
		{
			nickelsowed = (dimeremain / 5);
			nickelremain = dimeremain % (nickelsowed * 5);
		}	
								
			if (nickelremain >= 1 && nickelremain < 5)
			{
				penowed = (nickelremain / 1);
			}				
							
						   
        if (dimeremain < 5)
		{
			penowed = (quarterremain / 1);
		}	

                
    
   
                    
    if (centsowed >= 5 && centsowed <= 10)
        {
        nickelsowed = (centsowed / 5);
        nickelremain = centsowed % (nickelsowed * 5);
        } 
			if (nickelremain >= 1 && nickelremain < 5)
			{
				penowed = (nickelremain / 1);
			}				
						
				
	if (centsowed >= 0 && centsowed < 5)
	{
		penowed = (centsowed / 1);
	}		
                    
    printf("quarters %d, dimes %d, nickels %d, pennies %d\n", quartersowed, dimesowed, nickelsowed, penowed);
}