#include <iostream>
#include <string>

int main(int commandLineArgumentCount, char *commandLineArgument[]) {
  bool HasThreeArguments = (commandLineArgumentCount == 3);
// do we have three arguments including the executable?

  if (HasThreeArguments) {
    std::string execname{commandLineArgument[0]};
    auto firstCharOfSecondArgument {*(commandLineArgument[1])};
    auto namelength{execname.size()};
    auto thirdArgument{std::atoi(commandLineArgument[2])};
    auto sumOfChars{0};
    std::string secondArgument{commandLineArgument[1]};
  
// if it has three arguments, then these variables are created

for (char c : secondArgument) {
  sumOfChars += c;
}
// this loop goes over every character in the second argument, which is the first argument after the executable, and stores it into the sumOfChars variable

std::cout << "Your expected key is:" << thirdArgument << std::endl;
std::cout << "Your checksum is:" << sumOfChars << std::endl;

int calculateKey( int sumOfChars, char firstCharOfSecondArgument, int namelength, int thirdArgument); 
    return ((sumOfChars ^ (firstCharOfSecondArgument * 3)) << (namelength & 0x1f));

// calculation of the key

int key = calculateKey(sumOfChars, firstCharOfSecondArgument, namelength, thirdArgument);
// creates a variable called key in which the calculation is stored



    if (key == thirdArgument) {
      std::cout << "Conditions were met, your key is:" << key << std::endl;
    } else {
      std::cout << "Conditions not met. Key does not match expected key." << std::endl;
    }
  }
else 
    std::cout << "Invalid input. Enter exactly three arguments including the name of the executable." << std::endl;

}
