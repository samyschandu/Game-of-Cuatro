#include <iostream>   // for cin and cout
#include <iomanip>    // for setw()
#include <cctype>     // for toupper()
using namespace std;  // so that we don't need to preface every cin and cout with std::

// Global variables to represent the 16 board pieces and C++ strings representing
// the pieces that have not yet been played.  Since these are global they don't
// need to be passed as parameters to functions, and are shared over the entire program.
// Normally global variables will not be allowed.
char p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16;//characters used in my board display
string upperRowPiecesToPlay = "OO/CC  II/ZZ";//upperstring pieces 
string lowerRowPiecesToPlay = "oo/cc  ii/zz";//lower string pieces

//-------------------------------------------------------------------------------------
void displayInstructions()//displaying instructions
{
    cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
         << "of four pieces that are alike.  Players take turns making moves.    \n"
         << "On each move your OPPONENT chooses the piece, then YOU get to       \n"
         << "place it on the board.  If you create a set of four alike when      \n"
         << "you place your piece, then you win!       \n"
         << "\n"
         << "A set of four alike can be completed by using four all upper (or all\n"
         << "lower) case characters, four all vowels (or all consonants), or four\n"
         << "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
         << "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
         << "lower). Groups of four can be created in a row, column, diagonal, or\n"
         << "corner quadrant.\n"
         << "\n"
         << "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}// end displayInstructions()


void boardDisplay(){//displaying the board 
   cout<<endl
       <<" ---------"<<"       Square # " <<endl
       <<"|"<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<"|"<<"     1  2  3  4 " <<endl
      <<"|"<<" "<<p5<<" "<<p6<<" "<<p7<<" "<<p8<<" "<<"|"<<"     5  6  7  8 "<<endl
       <<"|"<<" "<<p9<<" "<<p10<<" "<<p11<<" "<<p12<<" "<<"|"<<"     9 10 11 12 "<<endl
       <<"|"<<" "<<p13<<" "<<p14<<" "<<p15<<" "<<p16<<" "<<"|"<<"     13 14 15 16 "<<endl
       <<" ---------"<<endl
       <<"Pieces:     Curved Straight"<<endl   
       <<"Upper:"<<upperRowPiecesToPlay <<endl
       <<"Lower:"<<lowerRowPiecesToPlay<<endl
       <<"             Vowel/Consonant"<<endl; 
} //end of the function      


void makeMove(int positionOfPiece,char pieceToMove ){//giving parameters to my function
  //makeMove function starts 	
		switch (positionOfPiece) {//used switch case for convenience as there are 16 cases
			case 1: p1 = pieceToMove; break;
			case 2: p2 = pieceToMove; break;
			case 3: p3 = pieceToMove; break;
			case 4: p4 = pieceToMove; break;
			case 5: p5 = pieceToMove; break;
			case 6: p6 = pieceToMove; break;
			case 7: p7 = pieceToMove; break;
			case 8: p8 = pieceToMove; break;
			case 9: p9 = pieceToMove; break;
			case 10: p10 = pieceToMove; break;
			case 11: p11 = pieceToMove; break;
			case 12: p12 = pieceToMove; break;
			case 13: p13 = pieceToMove; break;
			case 14: p14 = pieceToMove; break;
			case 15: p15 = pieceToMove; break;
			case 16: p16 = pieceToMove; break;
		}

}//function ends

bool changeString(char pieceToMove){//function to replace the character in the strings given with a space
   int someInteger;//some integer which i defied in this function
   
   
   if(isupper(pieceToMove)){
   
   someInteger = upperRowPiecesToPlay.find(pieceToMove);//to find the pieceToMove in the string upperRowPiecesToPlay
   
   
      if(someInteger != -1) {  //using of if-else statements
         upperRowPiecesToPlay[someInteger]=' ';
         return true;
      }
      
      else {
           cout <<"*** Sorry, that is an invalid piece.  Please retry." << endl;
           return false;
         }//if the charater is not in the string
   }
   
   else{
      someInteger = lowerRowPiecesToPlay.find(pieceToMove);//to find the pieceToMove in the string lowerRowPiecesToPlay
      
         // When character found in string
         if(someInteger != -1) {
            lowerRowPiecesToPlay[someInteger]=' ';
            return true;
         }
         
         else {
           cout <<"*** Sorry, that is an invalid piece.  Please retry." << endl;
           return false;
         }// if the character is not in the string
            
   }
   
}//end of the function
      
      
bool vowelCheck(char pieceToMove){//boolean function so that it can return true or false
   //checking for the vowels 
   if (pieceToMove == 'O' ||  pieceToMove == 'o' || pieceToMove=='I' || pieceToMove=='i'){
      
       return true;  //using if-else statement
   
   }
   return false; 
} //end of the function 
   

bool consonantCheck(char pieceToMove){//check for the consonants
   
   if (pieceToMove == 'Z' ||  pieceToMove == 'z' || pieceToMove=='C' || pieceToMove=='c'){
      
      return true; //using of conditional statements
   } 
   
    return false;
}//end of the function   


bool straightlineCheck(char pieceToMove){//check for the straighline characters
   if (pieceToMove == 'Z' ||  pieceToMove == 'z' || pieceToMove=='I' || pieceToMove=='i'){//using the conditional statements
      return true;
   }
   return false;
}//end of this function   


bool curveCheck(char pieceToMove){//check for the curve character functions
   if (pieceToMove == 'c' ||  pieceToMove == 'C' || pieceToMove=='O' || pieceToMove=='o'){
      return true;
   }
   return false;
}//end of the function
       
//function for the matching pieces     
bool matchingPieces(char c1, char c2, char c3, char c4){//any 4 characters as parameters
   if (vowelCheck(c1) && vowelCheck(c2) &&vowelCheck(c3)&&vowelCheck(c4)){ //checking if all four of the characters are vowels
      
      return true;
   }
   
   if (consonantCheck(c1)&& consonantCheck(c2) &&consonantCheck(c3)&&consonantCheck(c4)){//checking if all four of the characters are consonants
      
      return true;
   }
   
   if (straightlineCheck(c1)&& straightlineCheck(c2) &&straightlineCheck(c3)&&straightlineCheck(c4)){//checking if all four of the characters are straightline 
       
      return true;
   }
   
   if (curveCheck(c1)&& curveCheck(c2) &&curveCheck(c3)&&curveCheck(c4)){//checking if all four of the characters are curved characters
      
      return true;  
   }
   if(isupper(c1)&& isupper(c2) && isupper(c3) && isupper(c4)){//checking if all four of the characters are upper case characters
      
      return true;
   }
   if(islower(c1)&& islower(c2) && islower(c3) && islower(c4)){////checking if all four of the characters are lower case characters
      
      return true;
      
   }
   else {
      return false;
   }//using of the return statements to use in my game loop
}//end of the function   
   

 bool checkWin(){//checking all the possible combinations for winning in my game 
    if(matchingPieces(p1,p2,p3,p4)||matchingPieces(p5,p6,p7,p8)||matchingPieces(p9,p10,p11,p12)||matchingPieces(p13,p14,p15,p16)||matchingPieces(p1,p6,p11,p16)||matchingPieces(p4,p7,p10,p13)||matchingPieces(p1,p5,p9,p13)||matchingPieces(p2,p6,p10,p14)||matchingPieces(p3,p7,p11,p15)||matchingPieces(p4,p8,p12,p16)||matchingPieces(p1,p2,p5,p6)||matchingPieces(p3,p4,p7,p8)||matchingPieces(p9,p10,p13,p14)||matchingPieces(p11,p12,p15,p16)){
       
       return true;
       
    }
    return false;
 }//end of the function
   
   
 bool stopGame(){//to stop the game when the board is full
    if (p1!='.' && p2!='.' && p3!='.' && p4!='.' && p5!='.' && p6!='.' && p7!='.' && p8!='.' && p9!='.' && p10!='.' && p11!='.' && p12!='.' && p13!='.' && p14!='.' && p15!='.' && p16!='.'){
     //if the board would be full, that means no character would reresent a '.'  
       return true;
    }
    return false;
    
 } //end of the function      
 
       
//-------------------------------------------------------------------------------------
int main(char pieceToMove,int positionOfPiece){//my main function which has the game loop
INSTRUCTOR
| 02/15 AT 3:41 PM
int main() can only be int main() or int main(int argc, char *argv[]), no way for char, int to work

   
   
   p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16='.';
    // Declare and initialize variables
    
    int moveNumber = 1;
    
    displayInstructions();//before the start of the loop displaying the instructions and the empty board
    boardDisplay();
    
    
      while(true){//my main game loop 
            cout<<moveNumber<<'.';//moveNumber is the serial number 
            
            if( moveNumber%2==1) { //condition of when do the players enter piece and  destination
               cout<<"Player 1 enter piece, and Player 2 enter destination:";
            }
            else{
                 cout<<"Player 2 enter piece, and Player 1 enter destination:";
            }
    
            cin>>pieceToMove;//pieceToMove is the character which the player has to enter
            if (pieceToMove=='X' || pieceToMove=='x'){//the condition for exiting the program
               cout<<"Exiting program..."<<endl;
                exit(0);//exit the program
            } 
            
            cin>>positionOfPiece;//the position in my board
            
            if (positionOfPiece <= 0 || positionOfPiece >= 17) {//my condition for the position of the piece to be between 0 and 16 inclusive
               
               cout<<"*** Sorry, that destination is invalid.  Please retry.";//message to be displayed
               boardDisplay();
               continue; //or else continue the game 
            }
            
            if(changeString(pieceToMove)==false) {//the condition where the user gives a character input which does not exists in my string
               boardDisplay();//update the board
               continue;
            }
            
            makeMove( positionOfPiece, pieceToMove );//for making the move
            
            boardDisplay(); //displaying the updated board
            
            if (checkWin()){ // the condition to check each time for a win condition
               if( moveNumber%2==1) {//the condistion for which player would be the winner
               cout<<"*** Player 2 you won!";//nested if statements
               break;
               }
               else{
                  cout<<"*** Player 1 you won!";
                  break;
               }
            
            }
            if(stopGame()){//checking if the board is full to exit the game 
               exit(0);
               
            }
            
            moveNumber++; // if there is no winner or the game is not stopped, this will print the next turn .  
               
      }//end of the game loop      
            
    return 0;
} // end main()
//end of the program            
            
            
