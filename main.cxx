#include <iostream>
#include <string>

// Define the calculateKey function here
int calculateKey(int sumOfChars, char firstCharOfSecondArgument, int namelength, [[maybe_unused]] int thirdArgument) {
    return ((sumOfChars ^ (firstCharOfSecondArgument * 3)) << (namelength & 0x1f));
}


int main(int commandLineArgumentCount, char *commandLineArgument[]) {
    bool HasThreeArguments = (commandLineArgumentCount == 3);

    if (HasThreeArguments) {
        std::string execname{ commandLineArgument[0] };
        auto firstCharOfSecondArgument{ *(commandLineArgument[1]) };
        auto namelength{ execname.size() };
        auto thirdArgument{ std::atoi(commandLineArgument[2]) };
        auto sumOfChars{ 0 };
        std::string secondArgument{ commandLineArgument[1] };

        for (char c : secondArgument) {
            sumOfChars += c;
        }

        std::cout << "Your expected key is:" << thirdArgument << std::endl;
        std::cout << "Your checksum is:" << sumOfChars << std::endl;

        // Calculate the key using the calculateKey function
        int key = calculateKey(sumOfChars, firstCharOfSecondArgument, namelength, thirdArgument);

        if (key == thirdArgument) {
            std::cout << "Conditions were met, your key is:" << key << std::endl;
        }
        else {
            std::cout << "Conditions not met. Key does not match expected key." << std::endl;
        }
    }
    else
        std::cout << "Invalid input. Enter exactly three arguments including the name of the executable." << std::endl;

    return 0; // Return 0 to indicate successful execution
}
