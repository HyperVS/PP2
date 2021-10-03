#include "NotationConverter.hpp"

// Takes a string of postfix notation and returns a std::string in infix notation
std::string NotationConverter::postfixToInfix(std::string inStr){

    // Validate input is postfix
    if(!isalpha(inStr[0])) throw inStr;

    for(unsigned int i=0; i<inStr.size(); ++i){
        
        // Remove all white spaces
        if(inStr[i] != ' '){ 

            // Store operators in the temporary operators deque
            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') operators.insertBack(inStr[i]);

            // Store operands in the temporary operands deque
            else operands.insertBack(inStr[i]);
        }
    }

    // Validate postfix is correct
    if(operators.size() != operands.size()-1) throw inStr;
    
    deque.insertBack('(');
    int count = operators.size();
    
    // Insert parenthesis depending on operator count
    for(int i=1; i<count-1; ++i) deque.insertBack('(');

    // Retrieve operands and operators from the temporary deques and insert them into the main deque
    while(!operands.isEmpty()){
        deque.insertBack(operands.front());
        operands.removeFront();

        // Remaining operators if any get put into the main deque
        if(!operators.isEmpty()){
            
            // Insert from the back of the operators deque if there are 2 operators left
            if(operators.size() == 2){
                deque.insertBack(')');
                deque.insertBack(operators.back());
                operators.removeBack();
                deque.insertBack('(');
            }
            else{
                deque.insertBack(operators.front());
                operators.removeFront();
            }
        }
    }

    deque.insertBack(')');

    // Insert remaining parenthesis needed to make the infix notation correct
    for(int i=1; i<count-1; ++i) deque.insertBack(')');

    // Return elements in the main deque as a single string
    return toString();
}

// Takes a string of postfix notation and returns a string in prefix notation
std::string NotationConverter::postfixToPrefix(std::string inStr){
    return infixToPrefix(postfixToInfix(inStr));
}

// Takes a string of infix notation and returns a string in postfix notation
std::string NotationConverter::infixToPostfix(std::string inStr){

    // Validate input is infix
    if(inStr[0] != '(') throw inStr;
    
    for(unsigned int i=0; i<inStr.size(); ++i){
        
        // Remove parenthesis from the infix notation
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){

                // Store operators in the temporary deque
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                    operators.insertBack(inStr[i]);
                }
                
                // Store operands in the main deque
                else if(inStr[i] != '(') deque.insertBack(inStr[i]);
            }
            i++;
        }

        int count = operators.size();
        for(int i = 0; i < count; i++){
    
            // Insert from the back of the operators deque if there are 2 operators left
            if(operators.size() == 2){
                deque.insertBack(operators.back());
                operators.removeBack();
            }
            else{
                deque.insertBack(operators.front());
                operators.removeFront();
            }
        }
    }

    // Return elements in the main deque as a single string
    return toString();
}

// Takes a string of infix notation and returns a std::string in prefix notation
std::string NotationConverter::infixToPrefix(std::string inStr){

    // Validate input is infix
    if(inStr[0] != '(') throw inStr;

    for(unsigned int i=0; i<inStr.size(); ++i){

        // Remove parenthesis from the infix notation
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){

                    // Insert the operator to the front of the main deque if it is next to parenthesis
                    if(inStr[i-2] == ')'){
                        deque.insertFront(inStr[i]);
                    }

                    // Else insert to the back of the main deque
                    else deque.insertBack(inStr[i]);
                }

                // Insert the operands into the temporary operands deque
                else if(inStr[i] != '(') operands.insertBack(inStr[i]);
            }
            i++;
        }

        // Insert operands from the operands deque into the main deque
        int count = operands.size();
        for(int i=0; i<count; ++i){
            deque.insertBack(operands.front());
            operands.removeFront();
        }
    }

    // Return elements in the main deque as a single string
    return toString();
}

// Takes a string of prefix notation and returns a string in infix notation
std::string NotationConverter::prefixToInfix(std::string inStr){

    // Vaidate input is prefix
    if(inStr[0] != '+' && inStr[0] != '-' && inStr[0] != '*' && inStr[0] != '/') throw inStr;

    // Determine if parenthesis are needed and store count to make sure there is an even amount
    bool needParenthesis = false;
    int parCount= 0;

    for(unsigned int i=0; i<inStr.size(); ++i){
        if(inStr[i] != ' '){

            // Insert operators into operators deque
            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                operators.insertBack(inStr[i]);
                deque.insertBack('(');
                parCount++;
                needParenthesis = false; // No operand found yet
            }

            else{

                // Insert operands into main deque
                deque.insertBack(inStr[i]);

                // Insert a parenthesis after an operator in between two operands is inserted
                if(needParenthesis == true){
                    deque.insertBack(')');
                    parCount--; // Decrement count each time a closing parenthesis is inserted to keep at 0
                }

                // Insert the operator from the operands deque into the main deque
                if(operators.isEmpty() == false){
                    deque.insertBack(operators.back());
                    operators.removeBack();
                    needParenthesis = true; // Parenthesis is now needed in the next iteration of the loop
                }
            }
        }
    }

    // Check if there are a correct amount of opening and closing parenthesis and fix as needed
    if(parCount != 0){
        while(parCount != 0){
            deque.insertBack(')');
            parCount--;
        }
    }

    // Return elements in the main deque as a single string
    return toString();
}

// Takes a string of prefix notation and returns a string in postfix notation
std::string NotationConverter::prefixToPostfix(std::string inStr){
    return infixToPostfix(prefixToInfix(inStr));
}

// Converts elements in the deque into a single string to be returned
std::string NotationConverter::toString(){
    std::string outStr;

    // Checks if the deque is empty
    if(deque.isEmpty()) return outStr;

    int size = deque.size();

    // Fix formatting as instructed
    for(unsigned int i=0; i<size; ++i){
        if(deque.front() == ')') outStr.pop_back();
        outStr += deque.front();
        if(deque.front() != '(') outStr += ' ';
        deque.removeFront();
    }

    // Remove extra space
    outStr.pop_back();

    // Return the string
    return outStr;
}