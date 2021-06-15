#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct defined datatype
typedef struct item
{
   char itemName[25];		// item name
   size_t quantity;		//
   double price;
}item;

// prototypes 
void printItem(item *shoppingCart,int size);   // prototype for printing saved items
item getItem();			// read items from consule
void *ResizeArray(void  *shoppingCart, int count);	// double the size of the array 

int main()
{
    int option;			// menu option
    int count=0;		// count number of items when it add on the shopping cart
    int size;			// intitial size 
    char buffer[100];		// 
    
     printf("Enter number of items -> ");	// 
     fgets(buffer,100,stdin);			// read initial item size
     sscanf(buffer,"%d",&size);		
     
     item *shoppingCart;			// initialize shoppingCart
     
     shoppingCart =(item*)malloc(size * sizeof(item));   // allocate memory from the heap 
     if (shoppingCart == NULL)		// check to see that the memory was allocated
      {
        printf("Error allocating memory for shopping cart!\n");
	exit(0);
      }
		
  while(1)	
   {
	// menu 
    printf("1. Add an item to ShoppingCart \n");
    printf("2. Print the current list of items \n");
    printf("3. Quit the program \n");

    printf("Enter your choise  -> ");
    scanf("%d",&option);
      
   switch(option)
   {
  
	case 1:					// 
	   if(count==size)			// check if number of item and current size is equal
	    {
		shoppingCart=ResizeArray(shoppingCart,count);	// if true call ResizeArray function
		size=size*2;		// double current size
	    }

	    shoppingCart[count]=getItem();		// call getItem function to add items
            count++;			// count number of items which is added
            break;

       case 2:
           printItem(shoppingCart,count);		// call printItem function 
	   break;
  
       case 3:
	   printf(" Exit from program \n");
	   exit(0);			// exit program

        default:
	   printf("invalid input try again");
	   break; 
  }
// free(shoppingCart);
 }
return 0;
}
// get Item function adds item in shoping cart
item getItem()
{
     item cItem;	// variable declaration type item
 
     getchar();		// reaid of newline 

     printf("Enter item Name  -> ");		// item name
     fgets(cItem.itemName,25,stdin);		// rread item name
  

     printf("Enter quantity  ->");		// quantity 
     scanf("%zu",&cItem.quantity);		// read quantity 


     printf("Enter item price->");		// read price
     scanf("%lf",&cItem.price);			

     return cItem;		// return item values
}
// printItem function prints items in the shopping cart
void printItem(item* shoppingCart,int size)
{
     for(int i=0;i< size;i++)			// use loop get access and all items in the array
     {
         printf("item Name -> %s",shoppingCart[i].itemName);
	 printf("item quantity -> %zu\n",shoppingCart[i].quantity);
         printf("item price -> %lf \n\n",shoppingCart[i].price);
     }
}
// ResizeArray function double the size of the existing ShoppingCart whenever it calls
void *ResizeArray(void *shoppingCart,int size)

{

 
    item *newShoppingCart=(item*) malloc((size + size)*sizeof(item));  // declare new dinamic array 
     if (newShoppingCart == NULL)	//check if number of item and current size is equal

    {
        printf("Error allocating memory for new shopping Cart!\n");
	exit(0);
    }
    memcpy(newShoppingCart,shoppingCart,size*sizeof(item));   // copy the existing shopingcart items in to new array 
    free(shoppingCart);			// free the shoppingCart
    return newShoppingCart;		// return newshopingCart array

}
