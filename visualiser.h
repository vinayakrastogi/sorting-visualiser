#include <iostream>
#include <unistd.h>

class Visualiser {
    public:
        int os_var = 1; // 1-WINDOWS, 2-LINUX
        int height;
        int length;

        std::string symbol {" "};
    
        int check_linux() {
            #ifdef __linux__
            return 2;
            #else
            return 0;
            #endif
        }


        void initialise(int arr[],int size) {
            length = size;
            height = arr[0];
            for (int i = 0 ; i < length ; i++) {
                if (height < arr[i]) {
                    height = arr[i];
                }
            }
            os_var = check_linux();
        }

        void print(int state) {

            if (state == 0) { // space
                std::cout << symbol;
            } else if (state == 1) { // red
                std::cout << "\033[3;41;30m"<< symbol <<"\033[0m";
            } else if (state == 2) { // green
                std::cout << "\033[3;42;30m"<< symbol <<"\033[0m";
            } else if (state == 3) { // white
                std::cout << "\033[3;47;30m"<< symbol <<"\033[0m";                
            } else if (state == 4) { // black
                std::cout << "\033[3;100;30m"<< symbol <<"\033[0m";   
            }
        }

        void visualise(int array[], int comparator = 9999, int current_element = 9999 ) {

            usleep(50000);
            if (os_var == 1) {
                system("cls");
            } else {
                system("clear");
            }
            std::cout << std::endl;
            for (int y = height; y > 0 ; y--) {
                for (int x = 0; x < length; x++) {
                    if ((y - array[x]) > 0) {
                        print(0);
                    } else {
                        if (x == current_element) {
                            print(1);
                        } else if (x == comparator) {
                            print(2);
                        } else if (x % 2 == 0) {
                            print(3);
                        } else {
                            print(4);
                        }
                    }
                }
                std::cout << std::endl;
            }
        };


};
