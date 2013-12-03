#include <deque>
#include <iostream>

class Accelerometer {

    int recommended_output;
    size_t max_inputs;
    std::deque<int> input_vals;

    public:
        void append_val(int val);
        int get_acceleration();
        int get_recommended_output();
};

void Accelerometer::append_val(int val) {
    // pop values off the back if we've reached
    //  the maximum number of values we want to inspect
    if (input_vals.size() >= max_inputs) {
        input_vals.pop_back();
    }
    input_vals.push_front(val);
}


int Accelerometer::get_acceleration() {
    // Measure the rate of change between the 
    //  first half of the input_vals and the last
    //  half

    int first_count = 0;
    int last_count = 0;
    for (size_t i = 0; i < input_vals.size(); i++) {
        if (i < input_vals.size()) {
            first_count += input_vals[i];
        }
        else{
            last_count += input_vals[i];
        }
    }

    return 0;

}


int main() {
    return 0;
}