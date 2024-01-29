#include <iostream>
#include <limits>

int main(){
  std::srand(time(NULL));

  while (true){
    std::cout << "<=========================>" << std::endl;

    int letter = std::rand() % 26, u_row{}, u_col{}, a_row{}, a_col{};
    std::cout << "Letter: " << "\e[0;34m" << char(letter + 97) << "\e[0m " << std::endl;

    std::cin >> u_row >> u_col; 
    if (std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }

    if (letter + 97 == 'k')
      a_row = 1, a_col = 3;
    else if (letter + 97 < 'k')
      a_row = (letter / 5) + 1, a_col = (letter % 5) + 1;
    else
      a_row = ((letter - 1) / 5) + 1, a_col = ((letter - 1) % 5) + 1;

    if (u_row == a_row && u_col == a_col){
      std::cout << "\e[0;32mCorrect!\e[0m Letter " << char(letter + 97)
        << " is " << a_row << ":" << a_col << std::endl;
    }
    else{
      std::cout << "\e[0;31mIncorrect!\e[0m Letter " << char(letter + 97)
        << " is " << a_row << ":" << a_col << std::endl;
    }
  }
}
