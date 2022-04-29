#ifndef HBRIDGE_H
#define HBRIDGE_H

class hbridge {
	private:
		int _pins[8];
    int _speed;
	public:
		hbridge(int pins[], int speed);
    void start();
    void stop();
    void vitessep();
    void vitessem();
    void foward();
    void backward();
    void left();
    void right();
};

#endif
