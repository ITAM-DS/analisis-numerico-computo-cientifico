/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare,
 *  Matthew Hausknecht, and the Reinforcement Learning and Artificial Intelligence 
 *  Laboratory
 * Released under the GNU General Public License; see License.txt for details. 
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 *  sharedLibraryInterfaceExample.cpp 
 *
 *  Sample code for running an agent with the shared library interface. 
 **************************************************************************** */

#include <iostream>
#include <ale_interface.hpp>
#include <cstdlib>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <math.h>


#ifdef __USE_SDL
  #include <SDL.h>
#endif

using namespace std;

#define H 200
#define D (80 * 80)
#define ROWS 80
#define COLS 80


std::vector<double> preprocessloop(std::vector<unsigned char> data, int width, int height) {
    int top = 34;
    int bottom = 194;
    //cout << "debuggin "<< endl;
    std::vector<unsigned char> interestingData = std::vector<unsigned char>(data.begin() + top * width, data.begin() + bottom * width);
    //cout << "more "<< endl;
    std::vector<double> frame(80*80);

    int count = 0;
    //cout << "****************************************************************************************************************************************************************"<< endl;
    //cout << "size:  " << interestingData.size() << endl;
    
    for(int i = 0; i < COLS * 2; i++) {
        for(int j = 0; j < ROWS * 2; j++) {
            int value = (int)interestingData[i * ROWS * 2 + j];

            if(i % 2 == 0 && j % 2 == 0) {
                if(value == 87) {
                    frame[i/2 * ROWS + j/2] = 0.0;
                }else {
                    frame[i/2 * ROWS + j/2] = 1.0;
                }
            }
        }
    }
    return frame;
}

std::vector<double> subs(std::vector<double> a, std::vector<double> b) {
    std::vector<double> res(a.size());
    for(int i=0; i < a.size(); i++) {
        res[i] = a[i] - b[i];
    }
    return res;
}

void printScreenToConsole(std::vector<double> frame) {
    for(int i = 0; i < 80; i++) {
        for(int j = 0; j < 80; j++) {
            if (frame[i * 80 + j] > 0.0) {
                std::cout << frame[i * 80 + j];
            } else {
                std::cout << " "; 
            }
            
        }
        std::cout << endl;
    }
}



void printVector(std::vector<int> vec) {
    for(int i=0; i < vec.size(); i++) {
        std::cerr << vec[i] << std::endl;
    }
}
void printVectorDouble(std::vector<double> vec) {
    for(int i=0; i < vec.size(); i++) {
        std::cerr << vec[i] << std::endl;
    }
}


double randUniform() {
    return rand() / (RAND_MAX + 1.);
}
double randNormal(double mean, double stddev) {//Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}

int getAction(double prob) {

    if(randUniform() < prob) {
        return 2;
    } else {
        return 3;
    }
    
}

int getRandomAction() {

    if(randUniform() < 0.5) {
        return 2;
    } else {
        return 3;
    }
    
}

std::vector<double> createRandomNormalMatrix(int width, int height, double normalizationFactor) {
    int size = width * height;
    std::vector<double> rarray(size);
    for(int i = 0; i < size; i++){
        rarray[i] = randNormal(0,1) / normalizationFactor;
    }
    return rarray;
}

std::vector<double> matrixMultiplication(std::vector<double> a, std::vector<double> b, int n, int m, int p) {
    int size = n * p;
    std::vector<double> c(size);
    double sum;
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < p ; j++) {
            sum = 0.0;
            for(int k = 0; k < m ; k++) {
                sum = sum + a[i * m + k] * b[k * p + j];
            }
            c[i * p + j] = sum;
        }
    }
    return c;
}

void relu(std::vector<double> &h) {
    int size = h.size();

    for(int i = 0; i < size; i++) {
        if(h[i] < 0.0) {
            h[i] = 0.0;
        }
    }
}



double sigmoid(double x) {
    //std:cout << "value in sigmoid: " << x << std::endl;
    return 1.0 / (1.0 + exp(-x));
}

void test(){
    double arr[] = {4.0, 1.5, -2.0, -3.0, 4.0, -5.5};
    double arr2[] = {6.0, 7.0, 8.0};
    std::vector<double> a (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    std::vector<double> b (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
    std::vector<double> mult = matrixMultiplication(a, b, 2, 3, 1);
    



}
double policy_forward(std::vector<double> x, std::vector<double> w1, std::vector<double> w2){
    double prob;
    //std::cerr << " before h.size()" << std::endl;
    std::vector<double> h= matrixMultiplication(w1,x,H,D,1);
    int size = h.size();
    //std::cerr << "h.size(): " << size << std::endl;
    //printVectorDouble(h);
    relu(h);
    //printVectorDouble(h);
    std::vector<double> logp= matrixMultiplication(w2,h,1,H,1);
    //std::cerr << "**********************************" << std::endl;
    //printVectorDouble(logp);
    //std::cerr << "**********************************" << std::endl;
    prob = sigmoid(logp[0]);
    return prob;
}

int randSkip() {
    return (rand() % 3) + 2;
}



int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " rom_file" << std::endl;
        return 1;
    }

    //std::vector<double> H = createRandomNormalMatrix(50,50);
    //printVectorDouble(H);

    //test();

    std::vector<double> w1 = createRandomNormalMatrix(H,D, sqrt(D));
    std::vector<double> w2 = createRandomNormalMatrix(H,1, sqrt(H));

    //printVectorDouble(w2);

    ALEInterface ale;

    // Get & Set the desired settings
    ale.setInt("random_seed", 123);
    //The default is already 0.25, this is just an example
    ale.setFloat("repeat_action_probability", 0.25);

#ifdef __USE_SDL
    ale.setBool("display_screen", false);
    ale.setBool("sound", false);
#endif

    // Load the ROM file. (Also resets the system for new settings to
    // take effect.)
    ale.loadROM(argv[1]);


    //test();

    // Get the vector of legal actions
    ActionVect legal_actions = ale.getMinimalActionSet();

    cout << "Legal Actions: " << legal_actions.size() << endl;


    int width = ale.getScreen().width();
    int height = ale.getScreen().height();



    
    //cout << "width: " << width << endl;
    //cout << "height: " << height << endl;
    std::vector<unsigned char> data;
    std::vector<double> last (80 * 80);
    std::vector<double> current;
    std::vector<double> x;
    int up = 0;
    int down = 0;
    int episode = 0;
    double totalReward = 0;
    double reward;
    while(true) {
        //cout << "Begin while "<< endl;
        
        //cout << "get data "<< endl;
        ale.getScreenGrayscale(data);
        //cout << "proprocess "<< endl;
        
        current = preprocessloop(data, width, height);

        //printScreenToConsole(current);
        //cout << "substract "<< endl;
        x = subs(current,last);
        

        last = current;

        double prob = policy_forward(x, w1, w2);
        //double prob = randUniform();

        //cout << "prob " << prob << endl;


        double act = getAction(prob);

        if(act == 2) {
            up++;
        }else {
            down++;
        }


        Action a = legal_actions[act];

        //cout << "Action " << act << endl;
        int skip = randSkip();

        reward = 0.0;
        for(int i = 0; i < skip; i++) {
            reward += ale.act(a);
        }
        //cout << "Reward " << reward << endl;
        totalReward += reward;
        //cout << "Toal reward " << totalReward << endl;
        if(ale.game_over()) {
            episode++;
            ale.reset_game();
            ale.getScreenGrayscale(data);
            cout << "Episode " << episode << " ended with score: " << totalReward << endl;
            cout << "up: " << up <<endl;
            cout << "down: " << down <<endl;
            totalReward = 0;
            //up=0;
            //down=0;
        }

        if(reward > 0.0 || reward < 0.0) {
            cout << "Episode game finished, reward: " << reward << endl;
        }

    }
    return 0;
}
