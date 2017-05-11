#include "memento.h"

Command *Command::commandList[];
Memento *Command::mementoList[];
int Command::numCommands = 0;
int Command::highWater = 0;

int main()
{
	unsigned int i;
	std::cout << "Integer : ";
	std::cin >> i;
	Number *object = new Number(i);

	Command *commands[3];
	commands[1] = new Command(object, &Number::dubble);
	commands[2] = new Command(object, &Number::half);

	std::cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
	std::cin >> i;

	while(i) {
		if(i == 3)
			Command::undo();
		else if(i == 4)
			Command::redo();
		else
			commands[i]->execute();
		std::cout << "    " << object->getValue() << std::endl;
		std::cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
		std::cin >> i;
	}
	return 0;
}
