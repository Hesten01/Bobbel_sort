//
//  main.c
//  Øvelse
//
//  Created by noah helweg on 14/10/2025.
//
#include <stdio.h>
#include <stdbool.h>
// bobbel sort training:

// i create two bools that will check if the functions sort the numbers and letter correctly
// this bool checks the numbers
// the bool works by checking if the number after is larger or smaller than the number before: if it is lager for the whole length it returns true, otherwise it returns false.
bool pair_is_in_order_ints(int a[], int length)
{
    if (length <= 1) return true;
    for (int i = 0; i < length - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
// this bool checks the letters
// the bool works by checking if the letter after is larger or smaller than the letter before: if it is lager for the whole length it returns true, otherwise it returns false. it checks via the letters ASCII value
bool pair_is_in_order_chars(char b[], int length_letters)
{
    if (length_letters <= 1) return true;
    for (int i = 0; i < length_letters - 1; i++)
    {
        if (b[i] > b[i + 1])
            return false;
    }
    return true;
}
// this function takes a int array and the lenght of that array and is then abel to sort the numbers in the array though bubbel sort
// it works by having two loops
// the inner loop makes the swaps one number at a time, as the first loop goes though the array. it skips the last number because there is no number to compare the last number too.

void bubble_sort_numbers(int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < (length - 1); j++)
        {
// this is the function that makes the swap, it works by checking if a[j] is larger than a[j+1] and if it is it swaps them.
// visualised : with array a[5,2] : a[j] > a[j +1] = a[5] > a[2]
// then int temp = a[5] and a[j] = a[j + 1] = a[5] = a[2] : then a[j +1] =  int temp: whitch is a[2] = a[5].  the array would then be a[2,5] : the outer for loop makes sure that it does this for every number in the array
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // prints out the array after the sort
    for (int i = 0; i < length; i++)
        printf("a[%d] = %d\n", i, a[i]);
}
// this function takes a char array and the lenght of that array and is then abel to sort the letters in the array though bubbel sort
// it works the excat same way as the number sorting but instead of the letter it uses its ASCII value to sort them, and then prints out that values letter
void bubbel_sort_letters(char b[], int length_letters)
{
    for (int d = 0; d < length_letters; d++)
    {
        for (int j = 0; j < (length_letters - 1); j++)
        {
            if (b[j] > b[j+1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j+1] = temp;
            }
        }
    }
    for (int d = 0; d < length_letters; d++)
        printf("b[%d] = %c\n", d, b[d]);
}

int main(void) {
    int a[] = {8,6,4,3,2,5,3,7,9,1,10}; // the array of numbers
    char b[] = {'z','s','S','a','A'}; // the array of letters
    
    int length = 11;
    int length_letter = 5;
    
    // a menu
    printf("Hello you wil see two arrays sorted though a bubbel sort\n");
    printf("the arrays are chosen before hand, but could be changed and then sorted though the functions\n");
    printf("the first one will sort the numbers \n");
    printf("The second one will sort the letters \n");
    
    // printing out the order of the numbers and letters before the swap to show they have been sorted
    printf("Are the numbers in order before the swap %s\n",
           pair_is_in_order_ints(a, length) ? ": true" : ": false");
    printf("Are the letters in order before the swap %s\n",
           pair_is_in_order_chars(b, length_letter) ? ": true" : ": false");
    
    // running the sorting functions
    bubble_sort_numbers(a,length);
    bubbel_sort_letters(b, length_letter);
    
    // validating if the sorting functions sorted correctly
    printf("Are the numbers in order After the swap %s\n",
           pair_is_in_order_ints(a, length) ? ": true" : ": false");
    printf("Are the letters in order After the swap %s\n",
           pair_is_in_order_chars(b, length_letter) ? ": true" : ": false");
    
    return 0;
}
