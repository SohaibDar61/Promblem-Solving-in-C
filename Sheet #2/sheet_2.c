/*
 ============================================================================
 Name        : Sheet_2.c
 Author       : Sohaib Dar
 Version      : version 1.0
 Copyright   : For free
 Description : Revision c codes >> problem Solving
 Date           : 13 / 1 / 2021
 ============================================================================
 */

//================================================================================================//



/**
 * \brief  function to know if the system is big endian or little.
 */
int TestByteOrder(short int word)
{
        char *b = (char *)&word;
        return (b[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

int main(void)
{
        short int word = 0x1000;
        int r = TestByteOrder(word);
        printf("%s\n", r == LITTLE_ENDIAN ? "Little Endian" : "Big Endian");
        return r;
}

//====================================================================//
/**
 * \brief  function to know if the system is big endian or little.
 */
union check_endian
{
    unsigned int value;
    char r;
};
union check_endian endian;

int main(void)
{
    endian.value = 0x1;

    if (endian.r == 1)
        printf("Your system is Little Endian\n");
    else
        printf("Your system is Big Endian\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////

/**
 * \brief  function to swap the two bytes of a short int
 * \param  (data) the short int number
 * \return (int) return value
 */
int swap_two_bytes(short int data)
{
   return( data = ((data << 8) & 0xff00) | ((data >> 8) & 0x00ff));
}

//====================================================================//

/**
 * \brief  function that removes the repeated number of an input
           sorted array and return a new size OR return a new array
 * \param  (arr) the pointer to array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Remove_Repeated_Number (int *arr, int size)
{

    if (size == 0 || size == 1)
        return size;

    int i, new_size = 0;


    for (i = 0; i < size - 1; i++)
    {
        if ( arr[i] != arr[i+1])
        {
            arr[new_size] = arr[i];
            new_size++;
        }

    }
    arr[new_size] = arr[size -1];
    new_size++;
    return new_size;
}


//====================================================================//

/**
 * \brief  function that removes the repeated number
           of an input sorted array and return a new size OR return a new array
 * \param  (arr) the pointer to array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Remove_Repeated_Number(int *arr, int size)
{
    if(size == 0 || size == 1)
        return size;

    int i,j,k;
     for(i=0; i<size; i++)
    {
        for(j = i+1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
        //  delete the current position of the duplicate element
                for(k = j; k <size; k++)
                {
                    arr[k] = arr[k+1];
                }

        // if the position of the elements is changes, don't increase the index j
                j--;
        // decrease the size of array after removing duplicate element
                size--;
            }
        }
    }
    return size;
}

//====================================================================//

/**
 * \brief  function that removes the repeated number
           of an input sorted array and return a new size/return a new array
 * \param  (arr) the pointer to array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Remove_Repeated_Number(int *arr, int size)
{
    // Return, if array is empty or contains a single element

    if (size==0 || size==1)
        return size;

    int temp[size];
    int new_size = 0;

    for (int i=0; i<size-1; i++)
    {

   //If current element is not equal to next element
           //then store that current element
        if (arr[i] != arr[i+1]){
            temp[new_size] = arr[i];
            new_size++;
        }
    }
    //Store the last element as whether
    //it is unique or repeated, it hasn't stored previously
    temp[new_size] = arr[size-1];
    new_size++;

    for(int i=0; i<new_size; i++)
    {
        arr[i] = temp[i];
    }
    return new_size;
}

//====================================================================//


/**
 * \brief  function that take two numbers and return array
           contain all numbers between the two given numbers
 * \param  (number1) the first int number
 * \param  (number2) the second int number
 * \return (int*) return value( pointer to array)
 */
int* array_between_TwoNumbers(int number1, int number2)
{
    int i, j=0;
    static int arr[]={0};
    for(i = number1+1; i<number2; i++)
    {
        *(arr+j)= i;
        j++;
    }
    return arr;
}

//====================================================================//


/**
 * \brief  function to remove all characters in a string except alphabets
 * \param  (string) pointer to the given string
 * \return (void) None
 */
void Remove_Character(char* string)
{
    int i, j;
    for(i = 0; string[i] != '\0'; i++)
    {
        while (!( (string[i] >= 'a' && string[i] <= 'z') ||
                 (string[i] >= 'A' && string[i] <= 'Z') || string[i] == '0') )
        {
            for(j = i; string[j] != '\0'; j++)
            {
                string[j] = string[j+1];
            }
            string[j] = '\0';
        }
    }
}


//====================================================================//

/**
 * \brief  function which given a string and check if any character is repeated.
 * \param  (Start) the int number of starting number
 * \param  (diff_common) the int number of Common difference
 * \param  (n_term) the int number of Nth term to be find
 * \return (int) return value.
 */
int Get_nth_term(int Start, int diff_common, int n_term)
{
   // using formula to find the t(n) = a(1) + (n-1)*d
   return (Start + ((n_term - 1) * diff_common));
}

//====================================================================//


/**
 * \brief  function which given a string and check if any character is repeated.
 * \param  (string) pointer to the string given.
 * \return (char) return value.
 */
char Find_Repeat(char* string)
{
    int p = -1;
    int i,k;

    // initialized counts of occurrences of elements as zero
    int hash[MAX_CHAR] = { 0 };
    // initialized positions
    int pos[MAX_CHAR];

    for (i = 0; i < strlen(string); i++)
    {
        k = (int)string[i];
        if (hash[k] == 0) {
            hash[k]++;
            pos[k] = i;
        }
       else if (hash[k] == 1)
            hash[k]++;
    }

    for (i = 0; i < MAX_CHAR; i++)
    {
        if (hash[i] == 2) {
            if (p == -1)
                p = pos[i];
            else if (p > pos[i])
                p = pos[i];
        }
    }
    return p;
}


/**
  Time complexity : O(N)
    We loop through
    the string and hash the characters using ASCII codes.
    Store 1 if found and store 2 if found again.
     Also, store the position of the letter first found in.

     We run a loop
     on the hash array and now we find the minimum position of any character repeated.
*/


//====================================================================//




/**
 * \brief  function which given a string and check if any character is repeated.
 * \param  (string) pointer to the string given.
 * \return (char) return value.
 */
char Check_repeated_character(char *string)
{
    int rep_ch=-1;
    for(int i=0; i<strlen(string); i++)
    {
        for(int j=i+1; j<strlen(string); j++)
        {
            if(string[i] == string[j])
            {
                rep_ch = string[i];
                break;
            }
        }
        if(rep_ch != -1) break;
    }
    return rep_ch;
}


/**
 O(N^2) complexity:
     is to loop through the string for >>> each character
                        and search for >>> the same in the rest
                        of the string.
                 This would need two loops and thus not optimal.
*/



//====================================================================//



/**
 * \brief  Function that converts the any letter from lowercase to uppercase.
 * \param  (string_Lower) pointer to the string given(lowercase)
 * \param  (string_Upper) pointer to the string given(Uppercase
 * \return (void) None
 */
void  Lower_TO_Upper_string(char *string_Lower, char *string_Upper)
{
   int i=0;
    while(string_Lower[i])
    {
        string_Upper[i] = string_Lower[i]-32;
        i++;
    }
}


//====================================================================//

/**
 * \brief  Function that converts the any letter from lowercase to uppercase.
 * \param  (string_user) pointer to the string given
 * \return (void) None
 */
void  Lower_TO_Upper_string(char *string_user)
{
    int j;
    char ch;
    while (string_user[j])
    {
        ch = string_user[j];
        putchar(toupper(ch));
        j++;
    }
}

//====================================================================//

/**
 * \brief  function to check if the input is an even number or an odd number.
 * \param  (number_user) the int number of user
 * \return (char) return value
 */
char Check_Even_Odd(int number_user)
{
    return  (number_user % 2 == 0) ? 0 : 1;
}

