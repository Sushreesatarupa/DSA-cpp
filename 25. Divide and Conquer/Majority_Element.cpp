public class Solution {
    public int majorityElement(int[] num) {
        int major = num[0], count = 1;
        for (int i = 1; i < num.length; i++) {
            if (count == 0) {
                count++;
                major = num[i];
            } else if (major == num[i]) {
                count++;
            } else {
                count--;
            }
        }
        return major;
    }

    public static void main(String[] args) {
        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Example input array
        int[] nums = {3, 2, 3};

        // Call the majorityElement method and print the result
        System.out.println("Majority Element: " + solution.majorityElement(nums)); // Output: 3
    }
}
