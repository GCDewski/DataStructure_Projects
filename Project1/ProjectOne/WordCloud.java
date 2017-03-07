
import java.io.File; 
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Collections;

/**
 * The main class of the WordCloud builder
 * 
 * @Gracie Carver-Dews 
 * @9/3/15
 */
public class WordCloud 
{   
    ArrayList<String> words = new ArrayList<String>();

    /**
     * Constructor for objects of class WordCloud
     */
    public WordCloud()
    {

    }

    //main class so it doesn't have to run through BlueJay directly
    public static void main(String [] args)
    {
        if (args.length < 1)
        {
            System.out.println("Pleaseeeee give filename to read.");
        }
        else
        {
            WordCloud cloud = new WordCloud();
            File fileToRead = new File(args[0]);
            try 
            {
                Scanner in = new Scanner(fileToRead);
                PrintWriter outFile = new PrintWriter("words.txt"); //makes file
                cloud.readIt(in); //builds the original array
                cloud.orderIt(); //orders the array
                HashMap <String, Integer> finalWords = cloud.countRepeats(); //compare repeats and size based on repeats
                cloud.writeIt(outFile, finalWords); //write the file
            }
            catch(IOException e) {
                System.out.println("Something's wrong with the file! "+ e);
            }
        }
    }

    //read and build the word array
    public void readIt(Scanner infile)
    {
        while(infile.hasNext())
        {
            String word = infile.next();
            words.add(word);
        }
    }

    //order the array alphabetically
    public void orderIt()
    {
        Collections.sort(words, String.CASE_INSENSITIVE_ORDER);
    }

    //Build new Array and compare words to see the repeats 
    public HashMap<String,Integer> countRepeats()
    {
        HashMap<String, Integer> hmap = new HashMap<String, Integer>();
        int numberRepeat = 1;

        //go through the whole original array
        for(int i=0; i<words.size()-1; i++)
        {
            String newWord = words.get(i);

            if(newWord.equals(words.get(i+1)))
            {
                numberRepeat++; 
                hmap.put(words.get(i), numberRepeat);
            }
            else
            {
                hmap.put(words.get(i), numberRepeat);
                numberRepeat = 1; 
            }
        }
        return hmap;
    }

    //Write it to a new file
    public void writeIt(PrintWriter outputFile, HashMap <String,Integer> someWords)
    {
        outputFile.println("<html>");
        outputFile.println("<body>");
        for(String word : someWords.keySet())
        {
            int repeat = someWords.get(word).intValue();
            if(word != null)
            {
                outputFile.println("<p style='font-size: " + (repeat+10) + ">" + word + "</p>");
            }
        }
        outputFile.println("<html>");
        outputFile.println("<body>");
        outputFile.close();
    }

}
