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


#ifdef __USE_SDL
  #include <SDL.h>
#endif

using namespace std;

void ClearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

std::vector<int> preprocess(std::vector<unsigned char> data, int width, int height) {
    int top = 34;
    int bottom = 194;
    std::vector<unsigned char> interestingData = std::vector<unsigned char>(data.begin () + top * width, data.begin () + bottom * width);
    std::vector<int> frame (80 * 80);

    int count = 0;
    std::vector<unsigned char>::iterator it = interestingData.begin();
    while(it != interestingData.end()) {

        count++;
        if(*it == 87){
            //std::cout << ' ';
            frame[count] = 0;
        }else{
            if(*it == 147){
                //std::cout << '1';
                frame[count] = 1;
            }
            else{
                if(*it == 148){
                    //std::cout << '2';
                    frame[count] = 1;
                } else {
                    if(*it == 236) {
                        //std::cout << '3';
                        frame[count] = 1;
                    }
                    
                }
            }
        }
        
        if(count%80 == 0) {
            it+=160;
        }
        it+=2;
    }
    return frame;
}

std::vector<int> subs(std::vector<int> a, std::vector<int> b) {
    std::vector<int> res(a.size());
    for(int i=0; i < a.size(); i++) {
        res[i] = a[i] - b[i];
    }
    return res;
}


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " rom_file" << std::endl;
        return 1;
    }

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

    // Get the vector of legal actions
    ActionVect legal_actions = ale.getMinimalActionSet();

    cout << "Legal Actions: " << legal_actions.size() << endl;


    int width = ale.getScreen().width();
    int height = ale.getScreen().height();


    cout << "width: " << width << endl;
    cout << "height: " << height << endl;

    std::vector<unsigned char> data;
    std::vector<int> last (80 * 80);
    std::vector<int> current;
    std::vector<int> frame;

    // Play 10 episodes
    for (int episode=0; episode<1; episode++) {
        float totalReward = 0;
        while (!ale.game_over()) {
            Action a = legal_actions[rand() % legal_actions.size()];
            // Apply the action and get the resulting reward
            float reward = ale.act(a);
            totalReward += reward;


            ale.getScreenGrayscale(data);



            current = preprocess(data, width, height);
            
            frame = subs(current,last);
            
            for(int i = 0; i < 80; i++) {
                for(int j = 0; j < 80; j++) {
                    std::cout << frame[i * 80 + j];
                }
                std::cout << endl;
            }
            last = current;
        }
        
        cout << "Episode " << episode << " ended with score: " << totalReward << endl;
        ale.reset_game();
    }

    return 0;
}
