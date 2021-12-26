public class LinearSearch() {
  /**
  * Searches for int target in int[] array and returns the index it is found at, if not found, then return -1.
  *
  * @return - the index at which the target is found at in the array
  *
  */
  public static int search (int[] array, int target) {
    for (int i = 0; i < array.length; i++) {
      if (array[i] == target) {
        return i;
      }
      return -1;
    }
  }
  
  public static int search () {
    
  }
}
