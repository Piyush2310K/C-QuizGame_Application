
#include <stdio.h>
#include <ctype.h>

struct Question {
    const char *question;
    const char *options[4];
    char answer;
};

// Function to display instructions
void showInstructions() {
    printf("\n=================================\n");
    printf("          INSTRUCTIONS\n");
    printf("=================================\n");

    printf("1. This quiz contains 7 questions.\n");
    printf("2. Each question has 4 options.\n");
    printf("3. Choose your answer from A, B, C or D.\n");
    printf("4. Each correct answer gives you 1 point.\n");
    printf("5. There is no negative marking.\n");
    printf("6. Your final score will be displayed at the end.\n");

    printf("=================================\n");
}

// Function to start the quiz
void startQuiz() {
    struct Question questions[7] = {
        {
            "What will be the output of the following code? int a = 5; printf(\"%d\", ++a);",
            {"A. 5", "B. 6",
             "C. 4", "D. Compilation Error"},
            'B'
        },
        {
            "Which storage class allows a local variable to retain its value between function calls?",
            {"A. auto", "B. register",
             "C. static", "D. extern"},
            'C'
        },
        {
            "What does a pointer store in C?",
            {"A. Value of another variable",
             "B. Address of a variable",
             "C. Data type of a variable",
             "D. Size of a variable"},
            'B'
        },
        {
            "Which function is used to dynamically allocate memory in C?",
            {"A. malloc()", "B. printf()",
             "C. scanf()", "D. strlen()"},
            'A'
        },
        {
            "What is the output of sizeof(char) in C?",
            {"A. 2 bytes", "B. 4 bytes",
             "C. 8 bytes", "D. 1 byte"},
            'D'
        },
        {
            "Which operator is used to access a structure member through a pointer?",
            {"A. .", "B. ->",
             "C. &", "D. *"},
            'B'
        },
        {
            "What is the main purpose of a base condition in a recursive function?",
            {"A. To repeat the function forever",
             "B. To stop recursion",
             "C. To allocate memory",
             "D. To declare variables"},
            'B'
        }
    };

    int score = 0;
    char answer;

    printf("\n=================================\n");
    printf("          QUIZ STARTED!\n");
    printf("=================================\n");

    for (int i = 0; i < 7; i++) {
        printf("\nQuestion %d: %s\n", i + 1,
               questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        answer = toupper((unsigned char)answer);

        if (answer == questions[i].answer) {
            printf("Correct Answer!\n");
            score++;
        } else {
            printf("Wrong Answer!\n");
            printf("Correct answer: %c\n",
                   questions[i].answer);
        }
    }

    // Display final result
    printf("\n=================================\n");
    printf("          QUIZ RESULT\n");
    printf("=================================\n");

    printf("Total Questions : 7\n");
    printf("Correct Answers : %d\n", score);
    printf("Wrong Answers   : %d\n", 7 - score);
    printf("Your Score      : %d/7\n", score);
    printf("Percentage      : %.2f%%\n",
           (score / 7.0) * 100);

    if (score == 7) {
        printf("Performance     : Excellent!\n");
    } else if (score >= 4) {
        printf("Performance     : Good Job!\n");
    } else {
        printf("Performance     : Keep Practicing!\n");
    }

    printf("=================================\n");
    printf("\nTHANK YOU FOR PLAYING QUIZ MASTER!\n");
    printf("HAVE A GREAT DAY!\n");
}

// Main function
int main() {
    int choice;

    printf("\n=================================\n");
    printf("          QUIZ MASTER\n");
    printf("=================================\n");
    printf("1. Start Quiz\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("---------------------------------\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("\nInvalid input! Please run the program again.\n");
        return 0;
    }

    switch (choice) {
        case 1:
            startQuiz();
            break;

        case 2:
            showInstructions();

            printf("\nPress Enter to return to the main menu...");
            getchar(); // Clear previous Enter
            getchar(); // Wait for Enter

            return main();

        case 3:
            printf("\nThank you for visiting Quiz Master!\n");
            break;

        default:
            printf("\nInvalid choice! Please run the program again.\n");
    }

    return 0;
}
