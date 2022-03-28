/*
 ============================================================================
 Name        : Sheet_1.c
 Author      : Sohaib Dar
 Version     : version 1.0
 Copyright   : For free
 Description : Revision c codes >> problem Solving
 Date        : 13 / 12 / 2021
 ============================================================================
 */

//================================================================================================//

/**
 * \brief  function to take an array and return the biggest difference between
            2 numbers in the array (the smaller number must come first in the array)
 * \param  (ptr_arr) pointer to the array
 * \param  (size) size of array
 * \return (int) return value
 */
int Find_Max_Differernce(int *ptr_arr, int size)
{
    int i, j;
    int Max_diff = -1;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if((ptr_arr[i] < ptr_arr[j]) && (ptr_arr[j] - ptr_arr[i]) > Max_diff )
                Max_diff = ptr_arr[j] - ptr_arr[i];
        }
    }
    return Max_diff;
}


//================================================================================================//
/**
 * \brief  function to take 2 arrays and return an array by merging them
 * \param  (ptr_arr1) pointer to 1st array
 * \param  (ptr_arr2) pointer to 2nd array
 * \param  (arr_merge) pointer to the 3rd array that receives merge 1st & 2nd array
 * \param  (size1) the size of first array
 * \param  (size2) the size of second array
 * \return (void) None
 */
void Merge_Array(int *ptr_arr1, int *ptr_arr2, int *arr_merge, int size1, int size2)
{
    for(int i=0; i<size1+size2; i++)
        (i<size1)? (arr_merge[i] = ptr_arr1[i]) : (arr_merge[i] = ptr_arr2[i-size1]);
}
//================================================================================================//

/**
 * \brief  function to take 2 arrays and return an array by merging them
 * \param  (ptr_arr1) pointer to 1st array
 * \param  (ptr_arr2) pointer to 2nd array
 * \param  (arr_merge) pointer to the 3rd array that receives merge 1st & 2nd array
 * \param  (size1) the size of first array
 * \param  (size2) the size of second array
 * \return (void) None
 */
void Merge_Array(int *ptr_arr1, int *ptr_arr2, int *arr_merge, int size1, int size2)
{
    int i,k;
    for(i=0; i<size1; i++)
    {
        arr_merge[i] = ptr_arr1[i];
    }
    k=i;
    for(i=0; i<size2; i++)
    {
        arr_merge[k] = ptr_arr2[i];
        k++;
    }
}

//================================================================================================//
/**
 * \brief  function to find the most repeated number in an array of char
           (size of the array is very large )
 * \param  (str) pointer to the char array
 * \param  (ptr_arr) pointer to the int array
 * \return (int) return value
 */
int Max_Repeat_char(char *str, int *ptr_arr)
{
    int i, max;
    int index;
  	for(i=0; str[i] != 0; i++)
    {
        ++ptr_arr[str[i]];
    }

  	index = 0;
  	max   = ptr_arr[0];
  	for(i=0; str[i] != 0; i++)
    {
        if(ptr_arr[str[i]] > max)
        {
            max = ptr_arr[str[i]];
            index = i;
        }
    }
    return index;
}


//================================================================================================//

/**
 * \brief  function to find the most repeated number in an array of num
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Find_Repeat_Num(int *Ptr_arr, int size)
{
    int i, j;
    int count;
    int Repeat_element=0;
    int max_count=0;
    for(i=0; i<size; i++)
    {
        count = 1;
        for(j = i+1; j<size; j++)
        {
            if(Ptr_arr[j] == Ptr_arr[i])
                  count++;
            // If count of current element is more than maxCount, then update maxElement
            if(count > max_count){
                Repeat_element = Ptr_arr[j];
                max_count = count;
                //can return count of repeated num using struct and so on

           }
        }
    }
    return Repeat_element;
}
//================================================================================================//

/**
 * \brief  function to take an string and reverse words
            try it without use external arrays.
 * \param  (str) pointer to the string
 * \param  (len) the length of string
 * \return  NONE
 */
void Reverse_string_words(char *str, int len)
{
    int i, j, start_index, end_index;
    end_index = len - 1;

    for(i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				start_index = 0;
			}
			else
			{
				start_index = i + 1;
			}
			for(j = start_index; j <= end_index; j++)
			{
				printf("%c", str[j]);
			}
			end_index = i - 1;
			printf(" ");
		}
	}
}

//================================================================================================//
/**
 * \brief  function to take an string and return the longest word
 * \param  (str) pointer to the string
 * \param  (length) the length of string
 * \param  (longest) pointer to array of char(longest word of string)
 * \return  NONE
 */
void Find_Long_Word(char *str, char *longest, int length)
{
    int count = 0;
    int max = 0;
    int i,j;
    int index=0;
    // Finding length of longest word and starting index
    for( i = 0 ; i< length ; i++)
    {
        if(str[i] != ' ')
        {
            count++;
        }
        else
        {
            if(count > max)
            {
                max = count;
                index = i-max;
            }
            count = 0;
        }
    }
    // Checking if last word is longest
    if(count>max)
    {
        max = count;
        index = length-max;
    }
    //Using length and index copying longest word
    j=0;
    for(i=index; i< index+max; i++)
    {
        longest[j] = str[i];
        j++;
    }
    // Inserting NULL character to terminate string
    longest[j] = '\0';
     // print number Characters of longest word, its optional
     printf("\nLong of word = %i\n", max);
}

//================================================================================================//

/**
 * \brief  Write c function to take an array and reverse its elements
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return  NONE
 */
void Reverse_Array(int* Ptr_arr, int size)
{
    int i;
    for(i=size-1; i>=0; i--){
        printf("%i\t",Ptr_arr[i]);
    }
}

//================================================================================================//

/**
 * \brief  Write c function to take an array and reverse its elements
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return  NONE
 */
void Reverse_Array(int* Ptr_arr, int size)
{
    int i;
    int arr_temp[size];
    for(i=0; i<size; i++)
        arr_temp[size-1-i] = Ptr_arr[i];
    for(i=0; i<size; i++)
        Ptr_arr[i] = arr_temp[i] ;
}

//================================================================================================//
/**
 * \brief  function to take 2 unsigned char and add them
            and return the result in unsigned char
            (where is the problem and how to solve it).
 * \param  (ch2) the first unsigned char
 * \param  (ch2) the second unsigned char
 * \return (int) return value
 */
int Sum_Char(unsigned char ch1, unsigned char ch2)
{
    return ((ch1-'0') + (ch2-'0'));
}

//================================================================================================//

/**
 * \brief  function to return the minimum number in an array
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Find_MIN(int* Ptr_arr, int size)
{
  static  int min_num = 0;
    // the index of array starts with "1"
   int i=1;
   while(i<size)
   {
      if(Ptr_arr[min_num] > Ptr_arr[i])
      {
          min_num = i;
          Find_MIN(Ptr_arr, size);
      }
      i++;
   }
   return min_num;
}

//================================================================================================//

/**
 * \brief  function to return the maximum number in an array
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Find_MAX(int* Ptr_arr, int size)
{
    static  int max_num = 0;
   //the index of array starts with "1"
    int i=1;
    while(i<size)
    {
        if(Ptr_arr[max_num] < Ptr_arr[i])
        {
            max_num = i;
            Find_MAX(Ptr_arr, size);
        }
        i++;
    }
    return max_num;
}


//================================================================================================//



/**
 * \brief  function to return the maximum and minimum number
           in an array and there index
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \param  (Ptr_min_num) pointer to the minimum number
 * \param  (Ptr_max_num) pointer to the maximum number
 * \return (void) NONE
 */
void Find_MIN_MAX(int* Ptr_arr, int size, int* Ptr_min_num, int* Ptr_max_num)
{
    int index;
    *Ptr_min_num = Ptr_arr[0];
    *Ptr_max_num = Ptr_arr[0];
    for(index=1; index<size; index++)
    {
        if(*Ptr_min_num > Ptr_arr[index])
            *Ptr_min_num = Ptr_arr[index];

        if(*Ptr_max_num < Ptr_arr[index])
            *Ptr_max_num = Ptr_arr[index];
    }
}

//================================================================================================//


typedef struct greaterSmaller{
    int greater;
    int smaller;
}Struct;


Struct Find_MIN_MAX(int* Ptr_arr, int size)
{
    int index = 0;
    Struct S;
    S.smaller = Ptr_arr[0];
    S.greater = Ptr_arr[0];
    for(index=1; index<size; index++)
    {
        if(S.smaller > Ptr_arr[index])
             S.smaller = Ptr_arr[index];
        if(S.greater < Ptr_arr[index])
            S.greater = Ptr_arr[index];
    }
    return S;
}


//================================================================================================//

/**
 * \brief  function to return the maximum and minimum number
           in an array and there index
 * \param  (Ptr_arr) pointer to the array
 * \param  (size) the size of array
 * \return (int) return value
 */
int Find_MIN_MAX(int* Ptr_arr, int* Ptr_min_num, int* Ptr_max_num)
{
    int index;
    int min_num = Ptr_arr[0];
    int max_num = Ptr_arr[0];
    for(index=0; index<sizeof Ptr_arr / sizeof Ptr_arr[0];; index++)
    {
        if(min_num > Ptr_arr[index])
            min_num = Ptr_arr[index];

        if(man_num < Ptr_arr[index])
            max_num = Ptr_arr[index];
    }
    return min_num;
}


//================================================================================================//


/**
 * \brief  function to calculate the factorial of number try in 2 different way.
 * \param  (input_value) int number that determines end_range
 * \return (unsigned) return value
 */
int Recursive_Factorial(int number_user)
{
    if(number_user == 0) return 1;
    return (number_user * Recursive_Factorial(number_user-1));
}
//================================================================================================//

/**
 * \brief  function to calculate the factorial of number try in 2 different way.
 * \param  (input_value) int number that determines end_range
 * \return (int) return value
 */
int Find_Factorial(int number_user)
{
    unsigned int fact = 1;
    unsigned int index_fact;
    if(number_user == 0) return 1;
    for(index_fact= number_user; index_fact>1; index_fact--)
        fact *= index_fact;
    return fact;
}
//================================================================================================//


/**
 * \brief  function to sum numbers from 1 to 100 (without loop).
 * \param  (input_value) unsigned int number that determines end_range
 * \return (unsigned) return value
 */
unsigned Sum_Without_Loop(unsigned int input_value)
{
    //(N(N+1)/2)
    return((input_value * (input_value+1))/2);
}

//================================================================================================//

/**
 * \brief  function to take number of lines and draw pattern with '*'
 * \param  (num_lines) the take number of lines
 * \return (None)
 */
void Print_Pattern(unsigned int num_lines)
{
     int row ,col;
     for(row = 1; row <= num_lines; row++)
    {
        for(col= 1; col<= row; col++)
        {
 //  print * only on the first line, last column of every line and on the last line
            if(col == 1 || col == row || row == num_lines)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

//================================================================================================//

/**
 * \brief  function to take number of lines and draw pattern with '*'
 * \param  (num_lines) the take number of lines
 * \return (None)
 */
void Print_Pattern(unsigned int num_lines)
{
    int row ,col,space;
    // loop to print upper pyramid
    for(row = 1; row <= num_lines; row++)
    {
        // loop to print leading spaces in each line
        for(space = 0; space <= (num_lines - row); space++)
        {
            printf("   ");
        }

        // loop to print *
        for(col = 1; col <= (row * 2 - 1); col++)
        {
            printf(" * ");
        }

        printf("\n");
    }

    // loop to print lower pyramid
    for(row= num_lines+1; row >= 1; row--)
    {
        // loop to print leading spaces in each line
        for(space = num_lines-row; space >= 0; space--)
        {
            printf("   ");
        }

        // loop to print *
        for(col = row * 2 - 1; col >= 1; col--)
        {
            printf(" * ");
        }

        printf("\n");
    }

}

//================================================================================================//




/**
 * \brief  function to take number of lines and draw pattern with '*'
 * \param  (num_lines) the take number of lines
 * \return (None)
 */
void Print_Pattern(unsigned int num_lines)
{
    int row, col, space;
    for(row=num_lines;row>=1;row--)
  {
    for(space=1;space<=num_lines-row;space++) printf(" ");
    for(col=1;col<=row;col++) printf("* ");

    printf("\n");
  }
}
//================================================================================================//




/**
 * \brief  function to take number of lines and draw pattern with '*'
 * \param  (num_lines) the take number of lines
 * \return (None)
 */
void Print_Pattern(unsigned int num_lines)
{
    int row,col;

    // outer for loop to represent rows
    for(row=1; row<=num_lines; row++)
    {
        // inner for loop to represent columns
        for(col=1; col<=row; col++)
        {
            printf("* ");
        }

        // new line
        printf("\n");
    }
}

//================================================================================================//

/**
 * \brief  Write c function to print the binary representation of a number
 * \param  (number_user) the integer number that user gives
 * \return (None)
 */
void Print_bin(unsigned int number_user)
{
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (number_user & i) ? printf("1") : printf("0");
}



//================================================================================================//




/**
 * \brief  function to count number of ones in the binary
            representation of a number
 * \param  (number_user) the integer number that user gives
 * \return (int) return value
 */
int Count_ONES(unsigned int number_user)
{
    char count = 0 ;
    if(number_user == 0)
        return 0;
    else{
        while(number_user > 0){
            if(number_user & 1)
                count++;
            number_user = number_user >> 1;
        }
    }
    return count;
}


//================================================================================================//


/**
 * \brief  function to check Whether the Number base is 2 or not
 * \param  (number_user) the integer number that user gives
 * \return (bool) return value with true or false
 */
bool isPowerOfTwo(unsigned int number_user)
{
 unsigned int power_Of_Two = 1;

 while (power_Of_Two < number_user && power_Of_Two < 2147483648)
    power_Of_Two *= 2;
 return (number_user == power_Of_Two);
}


/**
 * \brief  function to check Whether the Number base is 2 or not
 * \param  (number_user) the integer number that user gives
 * \return (bool) return value with true or false
 */
bool isPowerOfTwo(unsigned int number_user)
{
    return(number_user != 0 && ((number_user & (~number_user +1)) == number_user));
}



//================================================================================================//

/**
 * \brief   function to check Whether the Number base is 2 or not
 * \param  (number_user) the integer number that user gives
 * \return (bool) return value with true or false
 */
bool isPowerOfTwo(unsigned int number_user)
{
   return (ceil(log2(number_user)) == floor(log2(number_user)));
}

//================================================================================================//

/**
 * \brief   function to check Whether the Number base is 2 or not
 * \param  (number_user) the integer number that user gives
 * \return (bool) return value with true or false
 */
bool isPowerOfTwo(unsigned int number_user)
{
   if(number_user == 0)
      return 0;
   else{
    while(number_user != 1){
         if (n % 2 != 0)
            return 0;
       number_user /= 2;
    }
   }
   return 1;
}

//================================================================================================//

/**
 * \brief  function to reverse digits in number
 * \param  (number_user) the integer number that user gives
 * \return (int) return value with the sum (sum all its digits)
 */
int Reverse_digits(int number_user)
{
    int rem_val=0,reverse_val=0;
    while(number_user != 0)
    {
        rem_val =(number_user % 10);
        reverse_val = (reverse_val *10) + rem_val;
        number_user /= 10;
    }
    return reverse_val;
}


//================================================================================================//


/**
 * \brief  function to take a number and sum all its digits
 * \param  (number_user) the integer number that user gives
 * \return (int) return value with the sum (sum all its digits)
 */
int Get_sum_digits(int number_user)
{
    int rem_val=0,sum=0;
    while(num != 0)
    {
        rem_val =number_user % 10;
        sum += rem_val ;
        number_user /= 10;
    }
    return sum;
}

//================================================================================================//




/**
 * \brief  function to take 2 numbers and print all prime numbers between them.
 * \param  (st_range) the start number user given[left]
 * \param  (En_range) the second number user given[right]
 * \return None
 */
void Check_Prime_Range(int St_range, int En_range)
{
    int i=0;
    int num=0;
    int flag;

    for (num = St_range; num <= En_range; num++)

    {
        flag = 0;
        // for loop to check for the prime numbers.

        for (i = 2; i <= num / 2; i++)

        {
            // check if num is divisible by any number.

            if (num % i == 0)

            {
                flag++;
                break;
            }

        }

        // check for the values of temp and num.
        if (flag == 0 && num != 1)

        {
            printf("%d\t",num);

        }

    }
}

//================================================================================================//

/**
 * \brief  function to check whether a number is prime number or not
            using Recursive
 * \param  (number_user) the integer number check prime or not
 * \param  (half_number_user) the half of number_user(number_user / 2)
 * \return (int) return int value
 */
int Check_Prime(int number_user,int half_number_user){

    if(half_number_user==1){
        return 1;
    }else{
       if(number_user%half_number_user==0)
         return 0;
       else
         Check_Prime(number_user,half_number_user-1);
    }
}


//================================================================================================//

/**
 * \brief  function to check whether a number is prime number or not
 * \param  (number_user) the integer number check prime or not
 * \return (unsigned) return unsigned value
 */
unsigned char Chech_Prime(unsigned int number_user)
{
    unsigned int index = 2;

    while (index <= number_user/2)   //(index <= number_user -1)
    {
        if (number_user % index == 0){
            return 0;
        }
        else{
        index++;
        }
    }
    return 1;
}


//================================================================================================//

/**
 * \brief  function to take an integer number and calculate its square root
 * \param  (number_user) the integer number that calculate its square root
 * \return (unsigned) return unsigned value
 */
unsigned square_root(unsigned number_user)
{
    unsigned root = 1;
    unsigned i = 0;

    while (1)
    {
        ++i;
        root = ((number_user / root) + root) / 2;
        if (i == number_user + 1)
        {
            break;
        }
    }
    return root;
}


//================================================================================================//
