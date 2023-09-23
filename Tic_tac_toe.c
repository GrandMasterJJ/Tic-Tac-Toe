#include <stdio.h>
#include <ctype.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on a 1D integer array
void bubbleSort(int arr[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void removeElement(int arr[], int *size, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= *size) {
        // Invalid index, do nothing
        return;
    }

    for (int i = indexToRemove; i < *size - 1; i++) {
        // Shift elements to the left to fill the gap
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease the size of the array
}



// Function to compare two arrays for equality
int compareArrays(int player1_arr[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (player1_arr[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

// Function to check if a 1D array is present in a 2D array
int is1DArrayIn2DArray(int player1_arr[], int size) {
    
    int arr2D[][3] = {{0,2,4},{10,12,14},{20,22,24},{0,10,20},{2,12,22},{4,14,24},{0,12,24},{4,12,20}};
    int numRows = sizeof(arr2D) / sizeof(arr2D[0]);
    int numCols = sizeof(arr2D[0]) / sizeof(arr2D[0][0]);
    for (int i = 0; i < numRows; i++) {
        if (compareArrays(player1_arr, arr2D[i], size)) {
            return 1; // 1D array is found in the 2D array
        }
    }
    return 0; // 1D array is not found in the 2D array
}

int Determine_similar(int player1_arr[], int size, int l)
{

    //int size = sizeof(player1_arr) / sizeof(player1_arr[0]);
    bubbleSort(player1_arr, size);


    int arr2[] = {0,0,0,0};
    for (int k = 0; k < 4; k++)
    {
        arr2[k] = player1_arr[k];
    }

    //int win_array[] = {0,0,0,0};

    //int arr2[8];
    
    //for (int l = 0; l < 4; l++)
    //{
        for (int k = 0; k < 4; k++)
        {
            player1_arr[k] = arr2[k]; // 複製arr2 到 player1_arr
        }

        removeElement(player1_arr, &size, l);
    
        //printf("\n%d \n",size);


        if (is1DArrayIn2DArray(player1_arr, size)) 
        {
            //printf("The 1D array is present in the 2D array.\n");
            //printf("We have a winner!! \n");
            //win_array[l] = 1;
            return 1;
            //break;
           
        } 
        else 
        {
            //printf("The 1D array is not present in the 2D array.\n");
            //win_array[l] = 0;
            return 0;
            
        }
/*
        for (int k = 0; k < 3; k++)
        {
            printf("%d ",player1_arr[k]);
        }
*/
        // =============================================
        for (int k = 0; k < 4; k++)
        {
            player1_arr[k] = arr2[k]; // 複製arr2 到 arr1，因為arr1已經被更改過了
        }

        //printf("\n");
        //size = sizeof(player1_arr) / sizeof(player1_arr[0]);
/*
        for (int k = 0; k < 4; k++)
        {
            printf("%d ",player1_arr[k]);
        }
*/
    //}
    
}
/*
int Determin_invalid_pos(int total_arr[8], int player1_arr[4], int player2_arr[4], int arr1_size, int arr2_size)
{
    for (int k = 0; k < 8; k += 2)
    {
        player1_arr[k/2] = total_arr[k];
        
    }
    //int size = sizeof(player1_arr) / sizeof(player1_arr[0]);
    

    for (int k = 1; k < 8; k += 2)
    {
        player2_arr[(k-1)/2] = total_arr[k];
    }

    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (player1_arr[i] == player2_arr[j])
            {
                //printf("invalid pos");
                return 1;
            }
            else
            {
                continue;
            }
        }
    
    }
    return 0;
}
*/

int Win_or_not(int total_arr[8], int player1_arr[4], int player2_arr[4], int size, int size1_2, int round)
{
    
    int det_arr1_win;
    int det_arr1_2_win;
    for (int l = 0; l < 4; l++)
    {
        for (int k = 0; k < 8; k += 2)
        {
            player1_arr[k/2] = total_arr[k];
        
        }
        //int size = sizeof(player1_arr) / sizeof(player1_arr[0]);

        for (int k = 1; k < 8; k += 2)
        {
            player2_arr[(k-1)/2] = total_arr[k];
        }
        //int size1_2 = sizeof(player2_arr) / sizeof(player2_arr[0]);

        det_arr1_win = Determine_similar(player1_arr, size, l);
        det_arr1_2_win = Determine_similar(player2_arr, size, l);

        if (round < 2)
        {
            return -1;
            continue;
            
        }
        else
        {
            if (det_arr1_win == 1)
            {
                //printf("player 1 wins ");
                return 1;
                break;
            }
            else if (det_arr1_2_win == 1)
            {
                //printf("player 2 wins ");
                return 2;
                break;
            }
            else if (det_arr1_win == 0 && det_arr1_2_win == 0 && round == 3 )
            {
                //printf("It is a tie !");
                return 0;
                break;
            }
            else
            {
                return -1;
                continue;
            }

        }
    }
}


void Scafold(int player_pos[], int index)
{
    
    
    //printf("\n final loc :%d", final_loc);
    //printf("\n Final x coordinate: %d ", x_coordinate);
    //printf("Final y coordinate: %d", y_coordinate);

    

    char scafold[25][8] = {" ","|"," ","|"," ",
                        "=","=","=","=","=",
                        " ","|"," ","|"," ",
                        "=","=","=","=","=",
                        " ","|"," ","|"," ",};
    int total_size = sizeof(scafold)/sizeof(scafold[0]);

    //scafold[final_loc][0] = 'o';
    int final_loc;
    for (int i = 0; i< index+1; i++)
    {
        final_loc = player_pos[i];
        //printf("%d \t",final_loc);
        if (i%2 == 0)
        {
            scafold[final_loc][0] = 'O';
        }
        else
        {
            scafold[final_loc][0] = 'X';
        }
        
    }


    // 用來 print 出棋盤方格和 O X
    for (int i = 0; i < total_size; i++)
    {
        
        if(i % 5 == 0)
        {
            printf("\n");
        }
        printf(scafold[i]);
    }
    


}

int main()
{
    
    
    int x_coordinate;
    int y_coordinate;
    int final_loc;
    
    int player_pos[8] = {-1, -2, -1, -2, -1 ,-2 ,-1 ,-2};
    
    for (int i = 0; i < 8; i++)
    {   
        int index = i;
        int round = i/2; 
        printf("round: %d \n", round+1);
        if (i % 2 == 0)
        {
            printf("\n Player 1's turn (O): ");
        }
        else
        {
            printf("\n Player 2's turn (X): ");
        }


        //int invalid_pos_result;
        //int player1_arr[4];
        //int player2_arr[4];
        //int size;
        //int size1_2;

        //do 
        //{
        printf("\n enter x coordinate: ");
        scanf(" %d", &x_coordinate);
        //printf("%d",x_coordinate);

        printf("\n enter y coordinate: ");
        scanf(" %d", &y_coordinate);
        //printf("%d",y_coordinate);

        final_loc = x_coordinate*10 + y_coordinate*2;
        player_pos[i] = final_loc;
                

        Scafold(player_pos, index);

        int player1_arr[4] = {0,0,0,0};
        int player2_arr[4] = {0,0,0,0};
        int size = sizeof(player1_arr) / sizeof(player1_arr[0]);
        int size1_2 = sizeof(player2_arr) / sizeof(player2_arr[0]);

        //invalid_pos_result = Determin_invalid_pos(player_pos, player1_arr, player2_arr,  size, size1_2);

        //} while (invalid_pos_result == 1);

        

        int Who_wins = Win_or_not(player_pos, player1_arr, player2_arr, size, size1_2, round);
        
        if (Who_wins == 1)
        {
            printf("\nplayer 1 wins! ");
            break;
        }
        else if (Who_wins == 2)
        {
            printf("\nplayer 2 wins! ");
            break;
        }
        else if (Who_wins == 0 && i == 7)
        {   
            printf("\nIt is a tie !");
        }
        else
        {
            continue;
        }
        
   
    }


    return 0;
}

