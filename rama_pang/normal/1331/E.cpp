#include <bits/stdc++.h>
using namespace std;

vector<string> s = {
"                          # # ###### #                          ",
"                      # ### # # #  # #####                      ",
"                    ### #   #   ## #    #  #                    ",
"                 #### # # #####    #### # ### #                 ",
"                ##      # #     ####    # # # ##                ",
"              #  ## ##### ### ### #  # ##   #  # #              ",
"             ###  #  #      # #   ####  ## ## ## ##             ",
"           ###### ## ## ### ### ###    ##  #  #   ###           ",
"          ############    #     #   # ##  ## ## #  ###          ",
"         #################### #######  ####  ##########         ",
"        ################################################        ",
"       ##################################################       ",
"       ##################################################       ",
"      ####################################################      ",
"     ######################################################     ",
"     ######################################################     ",
"    ########################################################    ",
"   ##########################################################   ",
"     ########################################################   ",
"       ############   #  ##############   # # #############     ",
"  ##     #########  #   ############### #       ########        ",
"  ####     #####   ## #   ############### ## ##  # ##       ##  ",
" #######     #   ###  ###  ########### #  #   ##         ###### ",
" #########     #  #  ## ##   ######### ## #####  #    ######### ",
" ############ ## ###     ###  #######   #  #    ### ########### ",
" #########     #   ### ###   ######## # ##### #   #  # ######## ",
"############ ### #  #  #   #  ######  #  #    ## ###   #########",
"###########   #  # ## ### ### #### # ### ####  ###   # #########",
"########### ###### ####    #  # #    # #  # ####   ### #########",
"###########     #  #  ### ###   # # ## ## #  #   #  #  #########",
"############ ## #### ## ###   # ###     #### # ###### ##########",
"###########   ###  #  #   ### #  ### ####  # ###   #   #########",
"#############     ## ### ## ### ##     #  ## ##  #   # #########",
"############## ## #    # #    # #  # # ## #   ## ## ############",
"############    #### # # # # #### ## #  # ###  ###   ###########",
"############# #  #   ###   ####   #  ##    #  ##   #############",
"################   ###   # ## ## ## ##  # ### #  #  ############",
"##################   # ######     #######   #   ################",
" ################  #    ##### # ###########   #  ############## ",
" ##############################    ############################ ",
" ########################### #  # ############################# ",
" ######################### #   ################################ ",
"  ########################   #   #############################  ",
"  #######  ################### ###############################  ",
"   ####### # ################   ##################### #######   ",
"   #######   #   ###########  # ########### ##### #    ######   ",
"   ####### # # #  # #   ## # ##  # #  # ##   ##     # #######   ",
"    ########   ##     #       ##   ##      # #  ### ########    ",
"     ####### #  #### #### ###  ###    ### ##### # #########     ",
"     ########## #  #  #   # #### ### ## #     #   #########     ",
"      ########    ## ## #    #   # #    ### #   ##########      ",
"       ######### ##   ##### ## # #   # ##   #############       ",
"       #########  ###  # #   ###   # ###  #   ###########       ",
"        #########   ####   ### ## #### #### ############        ",
"         ######### ##    # #      #    # ##############         ",
"          ############ # #### ## ## # ##  ############          ",
"           #############    ####    #    ############           ",
"             #################### #################             ",
"              ####################################              ",
"                ################################                ",
"                 ##############################                 ",
"                    ########################                    ",
"                      ####################                      ",
"                          ############                          "};

int main() {
  int r, c;
  cin >> r >> c;
  if (s[r][c] == '#') {
    cout << "IN\n";
  } else {
    cout << "OUT\n";
  }
}