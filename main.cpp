#include <iostream>
#include <limits>

int main(){
  std::srand(time(NULL));

  while (true){
    std::cout << "<=========================>" << std::endl;

    int offset = std::rand() % 26, u_row{}, u_col{};
    char letter = offset + 97;
    std::cout << "Letter: " << "\e[0;34m" << letter << "\e[0m " << std::endl;

    std::cin >> u_row >> u_col; 
    if (std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }

    if (letter == 'k')
      offset -= 8;
    else if (letter > 'k')
      --offset;

    int a_row = (offset / 5) + 1, a_col = (offset % 5) + 1;
    if (u_row == a_row && u_col == a_col){
      std::cout << "\e[0;32mCorrect!\e[0m Letter " << letter
        << " is " << a_row << ":" << a_col << std::endl;
    }
    else{
      std::cout << "\e[0;31mIncorrect!\e[0m Letter " << letter
        << " is " << a_row << ":" << a_col << std::endl;
    }
  }
}
