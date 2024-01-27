import javax.swing.*;

public class test {
    public static void main(String args[]) throws Exception {
        // Declare variables.
        final int NUM_ITEMS = 5; // Named constant
        // Initialized array of add-ins.
        String addIns[] = {"Cream", "Cinnamon", "Chocolate", "Amaretto", "Whiskey"}; 
        // Initialized array of add-in prices.
        double addInPrices[] = {.89, .25, .59, 1.50, 1.75};
        boolean foundIt = false; 
        int x;            // Loop control variable.
        double orderTotal = 2.00; // All orders start with a 2.00 charge

        while (!foundIt) {
            // Write the rest of the program here.
            // Get user input.
            String addIn = JOptionPane.showInputDialog("Enter coffee add-in or XXX to quit: ");
            for(int it=0; it < NUM_ITEMS; it++) {
                if(addIns[it].equals(addIn)) {
                    foundIt = true;
                    System.out.println("\nName of the add-in: "+addIn);
                    System.out.println("Price: $"+String.format("%.2f",addInPrices[it]));
                    // adding amount into total cost
                    orderTotal=orderTotal+addInPrices[it];
                    break;
                }
            }

            //See if it is found 
            if(!foundIt)
                System.out.println("Sorry, but we do not carry that product.");

            if(addIn.equalsIgnoreCase("XXX"))
                break;

            foundIt = false;
        }

        System.out.println("\nTotal order cost: $"+String.format("%.2f",orderTotal));
    } // End of main() method.

} // End of JumpinJive class.
