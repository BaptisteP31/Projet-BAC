#ifndef BUZZERINDICATOR_H
#define BUZZERINDICATOR_H

class buzzerindicator {
	private:
		int _pin;
    int _delay;
	public:
		buzzerindicator(int pin, int delay);
    void error();
    void validated();
};

#endif
