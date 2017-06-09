#include <iostream>

class Number;

class Note {
	private:
	
};

class Memento {
	private:
	friend class Number;
	int state;

	public: 
	Memento(int v) : state(v) {}
};

class Number {
	private :
	int value;

	public :
	Number(int v) : value(v) {}
	void dubble() { value *= 2; }
	void half() { value /= 2; }
	int getValue() const { return value; }
	Memento *createMemento() {
		return new Memento(value);
	}
	void reinstateMemento(Memento* m) {
		value = m->state;
	}
};

class Command {
	typedef void(Number:: *Action)();
	private:
	Number* receiver;
	Action action;
	static Command* commandList[20];
	static Memento* mementoList[20];
	static int numCommands;
	static int highWater;

	public:
	Command(Number* r, Action a) : receiver(r), action(a) {};
	
	virtual void execute() {
		mementoList[numCommands] = receiver->createMemento();
		commandList[numCommands] = this;

		if(numCommands > highWater)
			highWater = numCommands;
		numCommands++;
		(receiver->*action)();
	}

	static void undo() {
		if(numCommands == 0) {
			std::cout << "Vous avez atteint la fin de la liste" << std::endl;
			return;
		}
		commandList[numCommands-1]->receiver->reinstateMemento(mementoList[numCommands - 1]);
		numCommands--;
	}

	static void redo() {
		if( numCommands > highWater ) {
			std::cout << "Vous avez atteint la tête de la liste" << std::endl;
			return;
		}
		(commandList[numCommands]->receiver->*(commandList[numCommands]->action))();
		numCommands++;
	}
};
