/* 
+-----------------------------------------------------------------------------------+
| * This file is part of the Projet-BAC (https://github.com/BaptisteP31/Projet-BAC).|
| * Copyright (c) 2022 Paqueriaud Baptiste.                                         |
| *                                                                                 |
| * This program is free software: you can redistribute it and/or modify            |
| * it under the terms of the GNU General Public License as published by            |
| * the Free Software Foundation, version 3.                                        |
| *                                                                                 |
| * This program is distributed in the hope that it will be useful, but             |
| * WITHOUT ANY WARRANTY; without even the implied warranty of                      |
| * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU                |
| * General Public License for more details.                                        |
| *                                                                                 |
| * You should have received a copy of the GNU General Public License               |
| * along with this program. If not, see <http://www.gnu.org/licenses/>.            |
+-----------------------------------------------------------------------------------+
                                                                                     
 */

#ifndef HBRIDGE_H
#define HBRIDGE_H

class hbridge {
    private:
        int _pins[8];
        int _speed;
        int _pinNumb;
    public:
        int _speed;
        hbridge(int pins[], int speed);
        void start();
        void stop();
        void vitessep();
        void vitessem();
        void foward();
        void backward();
        void left();
        void right();
        void step_foward();
        void step_backward();
};

#endif
