// NumberGuesser Class Declaration File
#ifndef NUMBERGUESSER_HPP
#define NUMBERGUESSER_HPP

//class declaration
class NumberGuesser
{
    private:
        int lower_bound,
            upper_bound,
            initial_lower,
            initial_upper,
                   middle;
    public:
    //default constructor
    NumberGuesser();
    //parameter constructor
    NumberGuesser(int, int);
    //destructor
    ~NumberGuesser();
    void higher();
    void lower();
    int getCurrentGuess();
    void reset();
};

#endif