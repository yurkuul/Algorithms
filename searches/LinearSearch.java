import java.util.ArrayList;
import java.util.*;

/**
 * A class for using the linear search algorithm. By inputting either an array
 * or ArrayList and a target, the method will return the index at which target
 * is found if it exists. Otherwise it will return -1 if not found.
 * 
 * @author LZ-FSDev
 * @since 17.0.1
 * @version 0.0.2
 */
public class LinearSearch() {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] numbers = new int[];
        int index = 0;
        while (true) {
            System.out.println("Please enter numbers into the array. Enter -1
                                 to quit: ");
            int number = input.nextInt();
            if (number == -1) {
                break;
            } else {
                numbers[index] = number;
                index++;
            }
        }
        System.out.println("What number do you want to search for?");
        int search = input.nextInt();
        int foundNumber = search(numbers, search);
        if (foundNumber != 1) {
            System.out.println(search + " is found at index: " + foundNumber);
        } else {
            System.out.println("Your number does not exist in the array");
        }
    }

    /**
     * Searches for int target in int[] array and returns the index it is found
     * at, if not found, then return -1.
     *
     * @param array the array used for searching for target.
     * @return int the index at which the target is found at in the array, or
     * -1 if not found.
     * @since 0.0.1
     */
    public static int search(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
        if (array[i] == target) {
            return i;
        }
        }
        return -1;
    }
    
    /**
     * Searches for int target in an int ArrayList and returns the index it is
     * found at, if not found, then return -1.
     *
     * @param arrayList the ArrayList used for searching for target.
     * @return int the index at which the target is found at in the array, or 
     * -1 if not found.
     * @since 0.0.1
     */
    public static int search(ArrayList <Integer> arrayList, int target) {
        for (int i = 0; i < arrayList.size(); i++) {
        if (arrayList.get(i) == target) {
            return i;
        }
        }
        return -1;
    }
}
