package Algorithms;
import java.util.*;

/**
 * Write a recursive function that finds the minimum value in an ArrayList.
 * 
 * <ul>
 *  <li> findMinimum([1, 3, 5, 7, 9]) -> 1
 * </ul>
 * 
 * @author LZ-FSDev
 * @see 10.1.8 Recursive Minimum on CodeHS Recursion Unit 10
 * @since 17.0.1
 * @version 0.0.1
 */
public class RecursiveMin {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        while (true) {
             System.out.println("Please enter numbers. Enter -1 to quit: ");
             int number = input.nextInt();
             if (number == -1) {
                 break;
             }
             else {
                 numbers.add(number);
             }
        }
        int minimum = findMinimum(numbers);
        System.out.println("Minimum: " + minimum);
    }
    
    /**
     * Recursively finds the minimum in an ArrayList of integers the user inputs.
     * 
     * @param numbers An ArrayList of integers the user inputted.
     * @return The smallest value in 'numbers'.
     * @since 0.0.1
     */
    public static int findMinimum(ArrayList<Integer> numbers) {
        if (numbers.size() == 1) {
            return numbers.get(0);
        }
        if (numbers.get(numbers.size()-1) > numbers.get(numbers.size()-2)) {
            numbers.remove(numbers.size()-1);
            return findMinimum(numbers);
        } else {
            numbers.remove(numbers.size()-2);
            return findMinimum(numbers);
        }
    }
}
