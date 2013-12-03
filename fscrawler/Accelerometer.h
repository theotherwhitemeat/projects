
class Accelerometer {

    int max_inputs;
    std::deque<int> input_vals;

    public:
        void append_val(int val);
        int get_acceleration();
        int get_recommended_output();
};