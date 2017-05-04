package name;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class NameScoreJava {
    public static void main(String[] args) throws IOException {

        BufferedReader abc = new BufferedReader(new FileReader("names.txt"));
        List < String > data = new ArrayList < String > ();
        Scanner input = new Scanner(System.in);

        String s, name, inputName;
        int nameTotal = 0, total = 0;

        //reads file into array list
        while ((s = abc.readLine()) != null) {
            data.add(s);
        }
        Collections.sort(data); //sorts array alphabetically

        //assigns name score
        for (int i = 0; i < data.size(); i++) {
            name = data.get(i);

            for (int j = 0; j < name.length(); j++) {

                if (name.charAt(j) - 64 > 0 && name.charAt(j) - 64 < 27)
                    nameTotal = nameTotal + (name.charAt(j) - 64);
            }
            nameTotal = nameTotal * (i + 1);
            total = total + nameTotal;
            nameTotal = 0;
        }

        System.out.println("The total Name Score is " + total + "\n");

        //gives option to add another name into the array, sort it, and find a new name score
        System.out.print("What name would you like to search for? \nEnter Name: ");
        inputName = input.next();

        if (data.contains(inputName)) {
            System.out.print(inputName + " is already in the list!\n");
        } else {
            System.out.println(inputName + " is not in the list!");
            data.add(inputName);
            Collections.sort(data);

            nameTotal = 0;
            total = 0;

            for (int i = 0; i < data.size(); i++) {
                name = data.get(i);

                for (int j = 0; j < name.length(); j++) {

                    if (name.charAt(j) - 64 > 0 && name.charAt(j) - 64 < 27)
                        nameTotal = nameTotal + (name.charAt(j) - 64);
                }
                if (name == inputName) {
                    System.out.println(inputName + " was added to the list in position " + (i + 1));
                    System.out.println("The individual name value for " + inputName + " is " + nameTotal);
                    System.out.println("The name score for " + inputName + " is " + nameTotal * (i + 1));
                }

                nameTotal = nameTotal * (i + 1);
                total = total + nameTotal;
                nameTotal = 0;
            }
            System.out.println("the new total name score after adding " + inputName + " is " + total);
        }
    }
}
