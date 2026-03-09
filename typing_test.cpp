

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>

class TypingTest {
private:
    std::vector<std::string> sentences;
    double startTime;
    
    double getCurrentTime() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count() / 1000.0;
    }
    
public:
    TypingTest() {
        sentences = {
            "The quick brown fox jumps over the lazy dog",
            "Programming in C++ is fun and challenging",
            "Practice makes perfect when learning to type",
            "The early bird catches the worm",
            "Actions speak louder than words",
            "A journey of a thousand miles begins with a single step"
        };
        srand(time(0));
    }
    
    std::string getRandomSentence() {
        return sentences[rand() % sentences.size()];
    }
    
    void runTest() {
        std::string sentence = getRandomSentence();
        std::cout << "\n=== TYPING SPEED TEST ===\n";
        std::cout << "Type this sentence:\n\n";
        std::cout << "\"" << sentence << "\"\n\n";
        std::cout << "Press Enter when ready...";
        std::cin.get();
        
        startTime = getCurrentTime();
        
        std::cout << "\nStart typing: ";
        std::string input;
        std::getline(std::cin, input);
        
        double endTime = getCurrentTime();
        double timeTaken = endTime - startTime;
        
        int correctChars = 0;
        int length = std::min(sentence.length(), input.length());
        
        for(int i = 0; i < length; i++) {
            if(sentence[i] == input[i]) correctChars++;
        }
        
        double accuracy = (correctChars * 100.0) / sentence.length();
        double wpm = (sentence.length() / 5.0) / (timeTaken / 60.0);
        
        std::cout << "\n=== RESULTS ===\n";
        std::cout << "Time: " << timeTaken << " seconds\n";
        std::cout << "Accuracy: " << accuracy << "%\n";
        std::cout << "Speed: " << wpm << " WPM\n";
        std::cout << "Characters correct: " << correctChars << "/" 
                  << sentence.length() << "\n";
        
        if(accuracy > 95 && wpm > 40) {
            std::cout << "Excellent typing skills! 🏆\n";
        } else if(accuracy > 80) {
            std::cout << "Good job! Keep practicing 👍\n";
        } else {
            std::cout << "Keep practicing! You'll get better 📝\n";
        }
    }
};

int main() {
    TypingTest test;
    char choice;
    
    do {
        test.runTest();
        std::cout << "\nTry again? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();
    } while(choice == 'y' || choice == 'Y');
    
    return 0;
}

