#include <deque>
#include <iostream>

class Accelerometer {

    int recommended_output;
    int max_inputs;
    std::deque<int> input_vals;

    public:
        void append_val(int val);
        int get_acceleration();
        int get_recommended_output();
};

Accelerometer::append_val(int val) {
    // pop values off the back if we've reached
    //  the maximum number of values we want to inspect
    if (input_vals.size() >= max_inputs) {
        input_vals.popback();
    }
    input_vals.push_front(val);
}


Accelerometer::get_acceleration() {
    // Measure the rate of change between the 
    //  first half of the input_vals and the last
    //  half

    int first_count = 0;
    int last_count = 0;
    for (int i = 0; i < input_vals.size(); i++) {
        if (i < input_vals.size()) {
            first_count += input_vals[i];
        }
        else{
            last_count += input_vals[i];
        }
    }

}


int main() {
    return 0;
}