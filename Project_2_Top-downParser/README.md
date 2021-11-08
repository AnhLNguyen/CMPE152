# CMPE152 Team 12

PROJECT 2: Top-down Parser

Compiler Design: Top-down Parser in Java
By Anh Nguyen, Timothy Vu, Gia Ly, and An Nguyen

**Instructions on how to run it on VsCode**

First, you need to install either VsCode on your machine if you haven't done so. After installation, we recommend you use the **Coding Pack for Java**, which is the bundle of VS Code, the Java Development Kit (JDK), and a collection of suggestion extensions by Microsoft. The Coding Pack can be downloaded on the following URL: https://code.visualstudio.com/docs/languages/java

Make sure you check your Java version and Javac version before compile the program.

Depending on whether you use command line or an IDE, follow one of the below two instructions to get the sample compiled and run:

1.  If you use command line in VS Code
    To compile in command line, navigate to your main.Main file then compile with the following commands:

         // To navigate the path to your main
         cd path/path/....../path //enter your directory
         // To compile the program
         javac symbols/*.java
         javac inter/*.java
         javac lexer/*.java
         javac parser/*.java
         javac main/Main.java

    To run this program in command line:

         method 1: java main.Main
            // Input your text in one line
            // For example:
            //    {int r; int dd; int a; int d;r = a; dd = d;while( dd <= r ) dd = 2*dd;}

         method 2: java main.Main < test_file
            // Since test_file has two test inputs,
            // please remove one
            // and test one at a time.

**Refer to below methods if you want to use IntelliJ application**

/_ A sample passer that generate a syntax tree _/

First, you need to install JDK on your machine if you haven't
done so. After installation, you may need to update your
environment variables (e.g., JAVA_HOME and PATH) so that
you can invoke javac from command line. If you use an IDE,
configure your IDE so that it can find your Java installation
and use its libraries.

Depending on whether you use command line or an IDE, follow
one of the below two instructions to get the sample compiled
and run:

1. If you use command line
   To compile in command line, enter the src directory and run

javac symbols/_.java
javac inter/_.java
javac lexer/_.java
javac parser/_.java
javac main/Main.java

To run the lexer in command line:

java main.Main < test_file

2. If you use IntelliJ Idea IDE
   In the IntelliJ IDE, create a project and import the code. Then use
   the below steps to build and run:
   (1) Under "Run"->"Edit Configurations", put main.Main as main class.
   Specify your test file in "Redirect input from".
   (2) Click "Run"->"Run Main"

**Features that modified based on the sample code**

1. Token definitions (ID, FOR, and INCDECEXPR)
2. Type checking
3. Self-increment and decrement expression
4. For loop
