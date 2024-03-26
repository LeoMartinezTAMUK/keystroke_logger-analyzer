// Keystroke Log Analyzer 
// Designed to work directly with the output of keystroke_logger.cpp/exe from the same GitHub Repository
// Created by: Leo Martinez III in Spring 2024

// ** FOR EDUCATIONAL USE ONLY **

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class keystroke_analyzer {
    public static void main(String[] args) {
        String path = "EnterPathHere\\data\\log.txt";

        String filename = path; // specify the path to your log.txt file (MODIFY AS NEEDED)
        StringBuilder currentPhrase = new StringBuilder();

        // define phrases to check for and their corresponding messages
        HashMap<String, String> phrases = new HashMap<>();
        phrases.put("password", "Potential password found starting from line ");
        phrases.put("malware", "Potential malware found starting from line ");
        phrases.put("root", "Potential root access found starting from line ");
        phrases.put("admin", "Potential admin access found starting from line ");
        phrases.put("kernel", "Potential kernel access found starting from line ");
        phrases.put("ssn", "Potential social security number access found starting from line ");
        phrases.put("sudo", "Potential super user access found starting from line ");
        phrases.put("denied", "Potential denied access found starting from line ");
        phrases.put("settings", "Potential settings access found starting from line ");
        // more phrases can be added as needed for specific use cases

        int lineNumber = 1; // initialized

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
            	if (line.length() <= 11) {
            		lineNumber++; // line number still needs to be incremented
            		continue; // skip processing lines with length less than or equal to 11 (most likely blank or irrelevant)
            	}
                char keyLogged = line.charAt(12); // column 13 corresponds to index 12 (zero-indexed)
                currentPhrase.append(Character.toLowerCase(keyLogged)); // convert to lowercase to support case insensitivity

                // search for specific phrases
                for (String phrase : phrases.keySet()) {
                    if (currentPhrase.toString().contains(phrase)) {
                        int startLine = lineNumber - phrase.length() + 1;
                        System.out.println(phrases.get(phrase) + startLine);
                        currentPhrase.setLength(0); // clear the current phrase
                        break; // exit the loop after the first match is found
                    }
                }

                lineNumber++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
