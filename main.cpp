#include "../tasks/tasks.cpp"
void printMenu() {
    std::cout << "+-------------------+----------------+ \n";
    std::cout << "|     Menu          |   Option       | \n";
    std::cout << "+-------------------+----------------+ \n";
    std::cout << "| 1. task_1         |   Press 1      | \n";
    std::cout << "| 2. task_2         |   Press 2      | \n";
    std::cout << "| 3. task_3         |   Press 3      | \n";
    std::cout << "| 4. exit           |   Press 4      | \n";
    std::cout << "+-------------------+----------------+ \n";
}
int main() {
    int n;
    char repeat;
    do{
    printMenu();
    std::cin >> n;
    task_1 program;
    task_2 program_2;
    task_3 program_3;
    switch (n)
    {
    case 1:
    program.run();
        break;
    case 2:
    program_2.run();
    break;
    case 3:
    program_3.run();
    break;
    default:
    return 0;
        break;
    }
    std::cout << "-----------------------------------\n";
    std::cout << "Do u want to repeat?(y/n)";
    std::cin >> repeat;
    std::cout << "-----------------------------------\n";
    }
    while(repeat == 'y' || repeat == 'Y');
    
    return 0;
}