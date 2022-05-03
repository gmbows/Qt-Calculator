#include "calculator.h"

Calculator::Calculator()
{

}

void Calculator::equals() {
    switch(this->op) {
        case OP_ADD:
            this->displayValue = this->displayValue + this->lastValue;
            break;
        case OP_SUB:
            this->displayValue = this->lastValue - this->displayValue;
            break;
        case OP_DIV:
            if(!this->displayValue) {
                this->clear();
                break;
            }
            this->displayValue = this->lastValue / this->displayValue;
            break;
        case OP_MULT:
            this->displayValue = this->displayValue * this->lastValue;
            break;
    }
    this->update_display();
}

void Calculator::set_op(C_OP _op) {
    this->op = _op;
    this->lastValue = this->displayValue;
    this->displayValue = 0;
}

void Calculator::add_digit(int d) {
    if(!this->display) std::cout << "No display" << std::endl;
    this->displayValue *= 10;
    this->displayValue += d;
    this->update_display();
}

void Calculator::update_display() {
    this->display->display(std::to_string(this->displayValue).c_str());
}

int Calculator::getLastDigit() {
    float f = (this->displayValue/10.0f);
    int last = f - (int)f;
    int lastDigit = last*10;
    return lastDigit;
}

void Calculator::del() {
    this->displayValue -= this->getLastDigit();
    this->displayValue /= 10;
    this->update_display();
}

void Calculator::clear() {
    this->displayValue = 0;
    this->lastValue = 0;
    this->update_display();
}
