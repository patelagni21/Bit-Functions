#include <stdio.h>

int main(int argc, char *argv[])
{
   	char input_command[6];
   	int x, n, v;		    // reading these from the file
   	int	tx;

   	FILE* in_file = fopen(argv[1], "r");		// read only
    //FILE* in_file  = fopen("BIT_func_input_file.dat", "r");	// for debug only

    if (fscanf(in_file, "%d", &x ) == 1 ) {     //read line 1

        while (!feof(in_file))                  //rest rest
        {
           fscanf(in_file, "%s %d %d\n", input_command, &n, &v);

           tx = 1 << n;					//shifting to move that bit to nth position
           switch(input_command[0])     //checking 1st char of the command
           {
                case 'g':
                        printf("%d\n", (x & tx)&&1);
                        break;
                case 'c':
                    x = x ^ tx;
                    printf("%d\n", x);
                    break;
                case 's':
                    if (!v) {
                        tx = ~tx;
                        x = x & tx;
                    } else {
                        x = x | tx;			//'or' with 1 to set it directly
                    }
                    printf("%d\n",x);
                    break;
                default:
                    //printf("Wrong command. This message should not appear though.\n");
                    break;
            }
        }
   }
   fclose(in_file);
   return 0;
}