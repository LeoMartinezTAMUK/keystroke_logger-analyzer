# Keystroke Logger+Analyzer

**Authors:** Leo Martinez III - [LinkedIn](https://www.linkedin.com/in/leo-martinez-iii/)

**Contact:** [leo.martinez@students.tamuk.edu](mailto:leo.martinez@students.tamuk.edu)

**Created:** Spring 2024

# Disclaimer

**Warning:** This keystroke logger is designed for educational purposes only. Any use of this software for malicious purposes is strictly prohibited. The developer of this software is not responsible for any misuse or damage caused by its use. By using this software, you agree to use it responsibly and ethically in compliance with all applicable laws and regulations.

---

# Keystroke Logger and Log Analyzer

This project consists of two components: a keystroke logger implemented in C++ and a log analyzer implemented in Java.

## Keystroke Logger (C++)

The keystroke logger captures keyboard input and logs it into a text file. It's designed for educational purposes only.

### Usage

1. Compile the `keystroke_logger.cpp` file using a C++ compiler.
2. Run the compiled executable.
3. Press keys on the keyboard to log the keystrokes.
4. The keystrokes will be recorded in the `log.txt` file in the same directory as the executable.

### Dependencies

- Windows operating system
- C++ compiler (e.g., Visual Studio, MinGW)

## Log Analyzer (Java)

The log analyzer reads the log file generated by the keystroke logger and analyzes it for specific phrases.

### Usage

1. Compile the `keystroke_analyzer.java` file using a Java compiler.
2. Run the compiled Java program.
3. Specify the path to the `log.txt` file generated by the keystroke logger.
4. The log analyzer will search for predefined phrases in the log file and display potential matches along with the corresponding line numbers.

### Dependencies

- Java Development Kit (JDK)

## License

This project is licensed under the [MIT License](LICENSE).

## Note:

- Program was created in VS Code using C++ along with Eclipse for Java.

Here is a brief explanation of the items:
- **src:** folder that contains the source code C++ script (.cpp)/Java scripy (.java)
- **bin:** folder that contains the corresponding compiled files (.exe/.CLASS)
- **data:** folder that contains an example log.txt file generated
- **README.md:** contains most basic information about the project
- **LICENSE:** Contains license information in regards to the Github repository
