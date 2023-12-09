#include <iostream>
#include <string>
#include <Windows.h>


class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};


class ConcreteCommand : public Command {
private:
    std::string payload;
    
    class Receiver {
    public:
        void action(const std::string& payload) {
            std::cout << "Receiver ������ �� � ����������: " << payload << std::endl;
        }
    };

    Receiver receiver; 

public:
    ConcreteCommand(const std::string& str) : payload(str) {}

    void execute() override {
        receiver.action(payload);
    }
};


class Invoker {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void executeCommand() {
        command->execute();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Command* command = new ConcreteCommand("�������� �������");
    Invoker invoker;

   
    invoker.setCommand(command);

    
    invoker.executeCommand();

  
    delete command;

    return 0;
}
