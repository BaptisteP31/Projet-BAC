#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

class ledindicator {
	private:
		int _pin;
    int _delay;
	public:
		ledindicator(int pin, int delay);
    void blink();
    void still();
};

#endif
