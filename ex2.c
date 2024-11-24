/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int stop=0;
	while (stop==0) {
		int option;
		printf("Choose an option: \n  1. Happy Face \n  2. Balanced Number  \n  3. Generous Number \n  4. Circle Of Joy \n  5. Happy Numbers \n  6. Festival Of Laughter \n  7. Exit\n");
		scanf("%d", &option);
		switch (option) {
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
			case 1: {
				char eyes, nose, mouth ;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				int n;
				printf("Enter face size:\n");
				scanf("%d", &n);
				while (n%2==0 || n<=0 ){
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &n);
				}
				printf("%c", eyes);      //printing first eye
				for (int i = 0; i < n; i++) {
					printf(" ");			//printing n spaces
				}
				printf("%c\n", eyes);      //printing second eye
				for (int j = 0; j < n+2; j++) {
					if (j == n/2+1) {
						printf("%c ", nose);     // printing the nose in the middle
					}
					else {
						printf(" ");      // if it is not in the middle it prints space
					}
				}
				printf("\n%c", 92); // printing \ simbole
				for (int i = 0; i < n; i++) {
					printf("%c", mouth);  // printing the mouth simbole
				}
				printf("/\n"); // printing "/" simbole
				break;
			}
			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
			case 2: {
				int num, numcopy, num_length=0;
				printf("Enter a number:\n");
				scanf("%d", &num); //scanning the number
				while (num<=0) {   //using while loop to ensure opsitive number
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num);
				}
				numcopy = num; //creating a copy of number to find the length
				while (numcopy>0) {
					numcopy = numcopy/10;
					num_length++;  //counting the amount of loops until numcopy is restarting
				}
				int digits[num_length];  //creting an array as big as num's length
				for (int i = num_length-1; i >=0; i--) {
					digits[i] = num%10;  //entering the position of the digit in the right spot inside the array
					num = num/10;
				}
				int sum_r =0,sum_l=0; /*creating sum of the left side of the number
			and of the right side of the number and restarting it*/
				for (int j = 0; j < num_length; j++) {
					if (j<num_length/2) {  //if j is smaller than the middle f the array
						sum_l += digits[j]; // we add the digit to the left sum
					}
					else if(j>num_length/2 || (num_length%2 == 0 && j==num_length/2)) { /*if j is bigger then the middle f the array or
					equals in case it's an even number*/
						sum_r += digits[j]; //we add the digit to the right sum
					}
					else if (j==num_length/2 && num_length%2 != 0) { //if the number is odd we add the middle digit to both, right and left sum's.
						sum_r += digits[j];
						sum_l += digits[j];
					}
				}
				if ( sum_r==sum_l) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			case 3: {
				int num3;
				printf("Enter a number:\n");
				scanf("%d", &num3); //scanning the number
				while (num3<=0) {   //using while loop to ensure opsitive number
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num3);
				}
				int sum_devisors = 0;
				for (int i = 1; i <=num3/2; i++) {
					if (num3%i == 0) {
						sum_devisors+= i ;
					}
				}
				if (sum_devisors > num3) {
					printf("This number is generous!\n");
				}
				else {
					printf("This number does not share.\n");
				}
				break;
			}
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			case 4: {
				int num4;
				printf("Enter a number:\n");
				scanf("%d", &num4); //scanning the number
				while (num4<=0) {   //using while loop to ensure opsitive number
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num4);
				}

				int sum_divisors = 0;
				for (int i = 2; i <= num4/2; i++) {
					if (num4%i == 0 ) {
						sum_divisors++ ;
					}
				}
				int num4Reversed=0;
				while (num4 != 0) {
					num4Reversed = num4Reversed*10 + num4%10;
					num4 = num4/10;
				}
				int sum_divisors_reversed = 0;
				for (int i = 2; i <= num4Reversed / 2; i++) {
					if (num4Reversed % i == 0) {
						sum_divisors_reversed++;
					}
                }
				if (sum_divisors == 0 && sum_divisors_reversed == 0) {
					printf("This number completes the circle of joy!\n");
				} else {
					printf("The circle remains incomplete.\n");
				}
				break;
			}
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5: {
				int num_5;
				printf("Enter a number:\n");
				scanf("%d", &num_5);
				// Input a positive number
				while (num_5<=0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &num_5);
				}
				// Print happy numbers between 1 and num_5
				printf("Between 1 and %d only these numbers bring happiness: ", num_5);
				for (int i = 1; i <= num_5; i++) {
					int num = i;
					int slow = num, fast = num; /*slow stands for the first sum to be calculated and fast stands for the
					rest of the sums being calculated Using a loop to check for happy numbers */
					do {
						// Calculate the sum of squares for `slow` (1 step)
						int sum_slow = 0;
						while (slow > 0) {
							int digit = slow % 10;
							sum_slow += digit * digit;
							slow /= 10;
						}
						slow = sum_slow;

						// Calculate the sum of squares for `fast` (2 steps)
						int sum_fast = 0;
						while (fast > 0) {
							int digit = fast % 10;
							sum_fast += digit * digit;
							fast /= 10;
						}
						fast = sum_fast;
						sum_fast = 0;
						while (fast > 0) {
							int digit = fast % 10;
							sum_fast += digit * digit;
							fast /= 10;
						}
						fast = sum_fast;

					} while (slow != fast); // as long as the none of the fast sums isn't equal to the first sum the loop would keep going

					// If the loop ends and `slow` is 1, the number is happy
					if (slow == 1) {
							printf("%d ", i);
						}
				}
				printf("\n");
				break;
			}
			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 6: {
				int max, smile, cheer;
				printf("Enter a smile and cheer number:\n");
				while (1) {
					// Prompt for input and validate
					if (scanf("\nsmile: %d, cheer: %d", &smile, &cheer) == 2 && smile > 0 && cheer > 0 && smile != cheer) {
						break; // Valid input, exit loop
					}
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					// Clear invalid input
					while (getchar() != '\n');
				}

				printf("Enter maximum number for the festival:\n");
				scanf("%d", &max);
				while (max<=0) {
					printf("Only positive maximum number is allowed, please try again:");
					scanf("%d", &max);
				}
				for (int i = 1; i <= max; i++) {
					if (i%smile == 0 && i%cheer > 0) {
						printf("\nSmile!");
					}
					else if (i%smile > 0 && i%cheer == 0) {
						printf("\nCheer!");
					}
					else if (i%smile == 0 && i%cheer == 0) {
						printf("\nFestival!");
					}
					else {
						printf("\n%d", i);
					}
				}
				printf("\n");
				break;
			}

			case 7: {
				printf("Thank you for your journey through Numeria!");
				stop++ ;
				break;
			}
			default: {
				printf("This option is not available, please try again.");
			}
		}
	}
	return 0;
}
